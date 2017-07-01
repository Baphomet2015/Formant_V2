
// ---------------------------------------------------------
//
// Proyecto:       Formant_V2
// Version:        1.0
// Fichero:        Formant_V2_Teclado.ino
// Autor:   
// Hardware:       Arduino Nano V3.0
// Fecha:          Junio 2017
//
// Funcionalidad:  Fichero cabecera ( include ) principal de
//                 definiciones  de la aplicación de control 
//                 del teclado.
//
// Notas:          REVISADO --        
//
// ---------------------------------------------------------

#include <Arduino.h>
#include <stdlib.h>
#include "Formant_V2_MIDI.h"
#include "Formant_Teclado.h"




// ------------------------------------------------------------
//
//
//
//
// ------------------------------------------------------------


ARDUINO_MIDI c_MIDI;         // Variable para manejar los datos MIDI
byte         canalID;        // Canal MIDI asignado al Formant V2
byte         modoF;          // Modo de funcionamniento: TEST/Normal



// ------------------------------------------------------------
//
// setup()
//
//
// ------------------------------------------------------------

void setup()
{
   pinMode(IDE_HW_PIN_CLOCK,OUTPUT);
   pinMode(IDE_HW_PIN_DATA ,OUTPUT);
   pinMode(IDE_HW_PIN_LATCH,OUTPUT);
   
   pinMode(IDE_HW_PIN_LED_TECLA_ON,OUTPUT);
   
   pinMode(IDE_HW_PIN_GATE,OUTPUT);
   
   pinMode(IDE_HW_CANAL_ID_0,INPUT);
   pinMode(IDE_HW_CANAL_ID_1,INPUT);
   pinMode(IDE_HW_CANAL_ID_2,INPUT);
   pinMode(IDE_HW_CANAL_ID_3,INPUT);
   
   pinMode(IDE_HW_PIN_TEST,INPUT);
     
   c_MIDI.begin();                          // Imprescindible llamar antes de usar c_MIDI
   set_CodigoTecla(0);
   set_GATE(LOW);
   set_LedTeclaOn(LOW);
   get_CanalID();
    
   modoF = digitalRead(IDE_HW_PIN_TEST);
   if ( modoF==LOW )  
      { // ------------------------------------------------------------
        // Entrar en modo TEST
        // ------------------------------------------------------------
        modoTest(); 
      }
     
}



// ------------------------------------------------------------
//
// void loop()
//
// ------------------------------------------------------------

void loop()
{
  int resultado;
  int flgNoteOn;
  
  
  resultado = c_MIDI.get_msg_MIDI(false);

  if ( resultado==MIDI_RET_OK ) 
     { // ------------------------------------------------------------
       //
       // ------------------------------------------------------------
   
       if ( c_MIDI.get_Channel()==canalID )
          { // -------------------------------------------------------
            // Es un mensaje para este receptor
            // -------------------------------------------------------
            switch( c_MIDI.get_Type() )
                  { // -----------------------------------------------
                    //
                    // -----------------------------------------------
                                          
                    case ( MIDI_MSG_C_NOTE_ON ):
                         { // -----------------------------------------------
                           //
                           //             PULSAR TECLA
                           //
                           // -----------------------------------------------
                           if ( c_MIDI.get_Data_02()==0 )
                              { // -----------------------------------------------
                                // Un mensaje MIDI_MSG_C_NOTE_ON con velocidad=0
                                // es equivalente al mensaje MIDI_MSG_C_NOTE_OFF
                                // -----------------------------------------------
                                set_CodigoTecla(0);
                                set_GATE(LOW);
                                set_LedTeclaOn(LOW);
                              }
                           else
                              { // -----------------------------------------------
                                // Los codigos MIDI que identifican las teclas van
                                // del 0 ... 127 0   --> Do mas grave
                                //               127 --> Teclas mas aguda 
                                //
                                // En el circuito de  interfaz el Formant V2 , las 
                                // teclas se  numeran del 1 ...50  porque  son las 
                                // teclas que existen (4 OCTAVAS).
                                //
                                // IMPORTANTE:
                                // El  codigo  0  se utiliza  en  el interfaz  del
                                // Formant V2 para dejar de pulsar cualquier tecla
                                // ,por lo que las teclas empiezan en el 1 y hasta
                                // el 50 debido a esto se debe sumar 1  al  codigo
                                // de tecla recibido en un mensaje MIDI.
                                // -----------------------------------------------
                                set_CodigoTecla(c_MIDI.get_Data_01()+1); 
                                set_GATE(HIGH); 
                                set_LedTeclaOn(HIGH);
                              }
                           break; 
                         }

                    case ( MIDI_MSG_C_NOTE_OFF ):
                         { // -----------------------------------------------
                           //            DEJAR DE PULSAR TECLA
                           // -----------------------------------------------
                           set_CodigoTecla(0);
                           set_GATE(LOW);
                           set_LedTeclaOn(LOW);
                           break; 
                         }
                         
                    case ( MIDI_MSG_S_RESET ):
                         { // -----------------------------------------------
                           //            RESET DE SISTEMA
                           // -----------------------------------------------
                           set_CodigoTecla(0);
                           set_GATE(LOW);
                           set_LedTeclaOn(LOW);
                           break; 
                         }    
                  }
          }
    
     }
 
}


// ------------------------------------------------------------
//
// void set_CodigoTecla(byte tecla)
//
//
// ------------------------------------------------------------

void set_CodigoTecla(byte tecla)
{
  digitalWrite(IDE_HW_PIN_LATCH,LOW);
  shiftOut(IDE_HW_PIN_DATA, IDE_HW_PIN_CLOCK, MSBFIRST, tecla);
  digitalWrite(IDE_HW_PIN_LATCH,HIGH);
}
  
  

// ------------------------------------------------------------
//
// void set_GATE(byte modo)
// Activa/Desactiva la señal GATE
//
//. modo --> LOW
//. modo --> HIGH
//
// ------------------------------------------------------------

void set_GATE(byte modo)
{
  digitalWrite(IDE_HW_PIN_GATE,modo);  
}




// ------------------------------------------------------------
//
// void set_LedTeclaOn(byte modo)
// Activa/Desactiva el led de tecla pulsada
//
//. modo --> LOW
//. modo --> HIGH
//
// ------------------------------------------------------------

void set_LedTeclaOn(byte modo)
{
  digitalWrite(IDE_HW_PIN_LED_TECLA_ON,modo);  
}



// ------------------------------------------------------------
//
// void get_CanalID(void)
//
// ------------------------------------------------------------

void get_CanalID(void)
{
   canalID = 0;
   if ( digitalRead(IDE_HW_CANAL_ID_3)==HIGH ) { canalID += 8; }
   if ( digitalRead(IDE_HW_CANAL_ID_2)==HIGH ) { canalID += 4; }
   if ( digitalRead(IDE_HW_CANAL_ID_1)==HIGH ) { canalID += 2; }
   if ( digitalRead(IDE_HW_CANAL_ID_0)==HIGH ) { canalID += 1; }
}




// ------------------------------------------------------------
//
// void modoTest(void)
//
// ------------------------------------------------------------

void modoTest(void)
{
  int               resultado;  
  byte              modo;
  unsigned long int m;
  unsigned long int t;
   

  
  Serial.println(IDE_STR_VERSION);
  Serial.print(IDE_STR_MSG_03);
  Serial.println(canalID,DEC);
  Serial.println(IDE_STR_MSG_04);
  Serial.println(IDE_STR_MSG_01);

  m = millis();
  
  while( 1 )
       {
         resultado = c_MIDI.get_msg_MIDI(true);

         if ( resultado==MIDI_RET_OK ) 
            { // ------------------------------------------------------------
              // Decodifica el mensaje y muestra lo recibido
              // ------------------------------------------------------------
              Serial.println();
              Serial.print  ("TIPO:" );
              Serial.println(c_MIDI.get_Type()   ,HEX);
              Serial.print  ("CANAL:" );
              Serial.println(c_MIDI.get_Channel(),HEX);
              Serial.print  ("DATA0:" );
              Serial.println(c_MIDI.get_Data_01(),HEX);
              Serial.print  ("DATA1:" );
              Serial.println(c_MIDI.get_Data_02(),HEX);
           }
        else
            { // ------------------------------------------------------------
              // ERROR
              // ------------------------------------------------------------
              if ( resultado==MIDI_RET_ER )
                 {
                   Serial.println(IDE_STR_MSG_02);
                 }
           }

         t = millis();
         if ( (t-m)>=IDE_PAUSA_TEST )
            {
              m = t;
              
              if ( modo==HIGH ) { modo = LOW;  }
              else              { modo = HIGH; }
              set_GATE(modo);
              set_LedTeclaOn(modo);
            }
      }
  
}



// ------------------------------------------------------------
//
// void pausa(void)
//
// ------------------------------------------------------------

void pausa(void)
{
  unsigned long int m;
   
  m = millis();
  
  while( 1 )
       {
         if ( (millis()-m)>=1000 )
            {
              break;
           }   
      }
}













