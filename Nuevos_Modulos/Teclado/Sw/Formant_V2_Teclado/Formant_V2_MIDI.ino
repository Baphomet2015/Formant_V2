
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
  msg_MIDI.type    = 0;
  msg_MIDI.channel = 0;
  msg_MIDI.data_01 = 0;
  msg_MIDI.data_02 = 0;  
  
  Serial.begin(MIDI_VEL_TRX);
  
}



// ------------------------------------------------------------
//
// int ARDUINO_MIDI::get_msg_MIDI(void)
//
// Retorna:
// . MIDI_RET_OK  Se ha recibido un mensaje MIDI
// . MIDI_RET_NO  NO se ha recibido ningun mensaje
// . MIDI_RET_ER  Se ha recibido un mensaje MIDI pero erroneo
//
// ------------------------------------------------------------

int ARDUINO_MIDI::get_msg_MIDI(void)
{
  int  resultado;
  byte b0;
  byte b1;
  byte b2;
  byte nCar;
  
  resultado = MIDI_RET_NO;
  nCar      = 0;
  
  while ( Serial.available()>0 && (nCar<=3) )
        { // ------------------------------------------------------------
          //
          // ------------------------------------------------------------
          switch ( nCar )
                 {
                   case ( 0 ):
                        { b0 = Serial.read();
                          nCar++;
                          break;
                        }
          
                   case ( 1 ):
                        { b1 = Serial.read();
                          nCar++;
                          break;
                        }
                        
                   case ( 2 ):
                        { b2 = Serial.read();
                          nCar++;
                          break;
                        }
                 }
        }
             
  if ( nCar==3 )
     { // ------------------------------------------------------------
       //
       // ------------------------------------------------------------
       if ( (b0>= B10000000) && (b0<= B11101111) )
          {
             msg_MIDI.channel = (b0 & B00001111) + 1;
             msg_MIDI.type    = (b0 & B11110000);
             msg_MIDI.data_01 = b1;
             msg_MIDI.data_02 = b2;
             resultado = MIDI_RET_OK;
          }     
       else  
          {
             resultado = MIDI_RET_ER;
          }
       delayMicroseconds(IDE_PAUSA_CAR_RX); 
     }  

  return( resultado); 
}





