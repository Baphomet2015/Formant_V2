
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
   
   pinMode(IE_HW_CANAL_00,INPUT);
   pinMode(IE_HW_CANAL_01,INPUT); 
   pinMode(IE_HW_CANAL_02,INPUT);
   pinMode(IE_HW_CANAL_03,INPUT);
   
   set_CodigoTecla(0);
   set_GATE(LOW);
   set_LedTeclaOn(LOW);
   get_CanalID();
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
  
  
  flgNoteOn = false;
  resultado = c_MIDI.get_msg_MIDI();

  if ( resultado==MIDI_RET_OK ) 
     { // ------------------------------------------------------------
       //
       // ------------------------------------------------------------
       
       #ifdef APP_MODO_DEBUG
       Serial.print  ("TIPO:" );
       Serial.println(c_MIDI.get_Type()   ,DEC);
       Serial.print  ("CANAL:" );
       Serial.println(c_MIDI.get_Channel(),DEC);
       Serial.print  ("DATA0:" );
       Serial.println(c_MIDI.get_Data_01(),DEC);
       Serial.print  ("DATA1:" );
       Serial.println(c_MIDI.get_Data_02(),DEC);
       #endif
    
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
                           //             PULSAR la tecla
                           //
                           // Los codigos MIDI que identifican las teclas van
                           // del 0 ... 127 0   --> Do mas grave
                           //               127 --> Teclas mas aguda 
                           //
                           // En el circuito de  interfaz el Formant V2 , las 
                           // teclas se  numeran del 1 ...50  porque  son las 
                           // teclas que existen (4 OCTAVAS).
                           //
                           // IMPORTANTE:
                           // El  codigo  0  se  utiliza  en  el interfaz  del
                           // Formant V2 para dejar de pulsar  cualquier tecla
                           // , por lo que las teclas empiezan en el 1 y hasta
                           // el 50 debido a esto se debe sumar 1 al codigo de
                           // tecla recibido en un mensaje MIDI
                           // -----------------------------------------------
                           if ( flgNoteOn==false )
                              {
                                flgNoteOn = true;
                                set_CodigoTecla(c_MIDI.get_Data_01()+1);
                                set_GATE(HIGH);
                                set_LedTeclaOn(HIGH);
                              }
                           break; 
                         }

                    case ( MIDI_MSG_C_NOTE_OFF ):
                         { // -----------------------------------------------
                           //            DEJAR de pulsar tecla
                           // -----------------------------------------------
                           flgNoteOn = false;
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
  shiftOut(IDE_HW_PIN_DATA, IDE_HW_PIN_CLOCK, LSBFIRST, tecla);
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
  
  canalID = 1;  
  
}

