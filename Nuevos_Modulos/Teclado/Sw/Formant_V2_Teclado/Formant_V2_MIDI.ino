
// ---------------------------------------------------------
//
// Proyecto:       Formant_V2
// Version:        1.0
// Fichero:        Formant_V2_MIDI.ino
// Autor:
// Fecha:          Junio 2017
//
// Funcionalidad:  Fichero cabecera ( include ) principal de
//                 definiciones MIDI
//
// Notas:          REVISADO --        
//
// ---------------------------------------------------------

#include "Formant_V2_MIDI.h"


// ------------------------------------------------------------
//
//
//
//
// ------------------------------------------------------------

ARDUINO_MIDI::ARDUINO_MIDI()
{
  begin();
}



// ------------------------------------------------------------
//
// void ARDUINO_MIDI::begin(void)
//
//
// ------------------------------------------------------------

void ARDUINO_MIDI::begin(void)
{
  iniDatos();
  Serial.begin(MIDI_VEL_TRX);
}



// ------------------------------------------------------------
//
// void ARDUINO_MIDI::iniDatos(void)
//
//
// ------------------------------------------------------------

void ARDUINO_MIDI::iniDatos(void)
{
  msg_MIDI.type    = 0;
  msg_MIDI.channel = 0;
  msg_MIDI.data_01 = 0;
  msg_MIDI.data_02 = 0;  
  numBytesDatos    = 2;
}




// ------------------------------------------------------------
//
// int ARDUINO_MIDI::get_msg_MIDI(byte modo)
//
// Retorna:
// . MIDI_RET_OK  Se ha recibido un mensaje MIDI
// . MIDI_RET_NO  NO se ha recibido ningun mensaje
// . MIDI_RET_ER  Se ha recibido un mensaje MIDI pero erroneo
//
// ------------------------------------------------------------

int ARDUINO_MIDI::get_msg_MIDI(byte modo)
{
  int  resultado;
  byte nCar;
  byte aux;
  
  
  resultado = MIDI_RET_NO;
  nCar      = 0;
  
  while ( Serial.available()>0 )
        { 
          resultado = MIDI_RET_ER;
          aux       = Serial.read();
          
          if ( modo==true )
             {
               Serial.print  ("BYTE RECIBIDO (DEC): ");   
               Serial.println(aux,DEC);  
             }
          
          if ( aux>=B10000000 )
             { // ------------------------------------------------------------
               // El bit mas significativo es 1, luego es el byte de ESTADO
               // ------------------------------------------------------------              
               if ( aux<0xF0 )
                  { // ------------------------------------------------------------
                    // A) NO es un mensaje de sistema
                    // ------------------------------------------------------------  
                    msg_MIDI.type    = (aux & B11110000);
                    msg_MIDI.channel = (aux & B00001111) + 1;
                    if ( (msg_MIDI.type==MIDI_MSG_C_CHANNEL_AFTER) || (msg_MIDI.type==MIDI_MSG_C_PROG_CHG) )  
                       { // ------------------------------------------------------------  
                         // Estos mensajes solo tienen 1 dato 
                         // ------------------------------------------------------------  
                         numBytesDatos = 1;
                       }
                    else
                       { // ------------------------------------------------------------  
                         // Resto de mensajes tienen 2 datos 
                         // ------------------------------------------------------------  
                         numBytesDatos = 2;
                       }
                  }
               else
                  { // ------------------------------------------------------------
                    // B) SI es un mensaje de sistema
                    // ------------------------------------------------------------ 
                    msg_MIDI.type    = aux;
                    msg_MIDI.channel = 0;
                    numBytesDatos    = 1;
                  }   
             }    
          else
             { // ------------------------------------------------------------
               // Running Status o datos de Mensaje
               // ------------------------------------------------------------
               if ( msg_MIDI.type!=0 )
                  {
                    if ( numBytesDatos!=0 ) 
                       {
                         if      ( nCar==0 ) { msg_MIDI.data_01 = aux; }
                         else if ( nCar==1 ) { msg_MIDI.data_02 = aux; }
                         nCar++;
                       }
                   
                   if ( numBytesDatos==nCar )
                      {
                        resultado = MIDI_RET_OK;
                        break;
                      }
                  }
             }
          delayMicroseconds(IDE_PAUSA_CAR_RX);          
       }  

  return( resultado); 
}





