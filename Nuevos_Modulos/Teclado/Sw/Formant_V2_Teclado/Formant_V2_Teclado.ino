
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


ARDUINO_MIDI c_MIDI;




// ------------------------------------------------------------
//
// setup()
//
//
// ------------------------------------------------------------

void setup()
{
   pinMode(IDE_HW_PIN_D0,OUTPUT);
   pinMode(IDE_HW_PIN_D1,OUTPUT);
   pinMode(IDE_HW_PIN_D2,OUTPUT);
   pinMode(IDE_HW_PIN_D3,OUTPUT);
   pinMode(IDE_HW_PIN_D4,OUTPUT);
   pinMode(IDE_HW_PIN_D5,OUTPUT);
   
   pinMode(IDE_HW_PIN_GATE,OUTPUT);
   

}



// ------------------------------------------------------------
//
// void loop()
//
// ------------------------------------------------------------

void loop()
{
  int resultado;
  
  
  resultado = c_MIDI.get_msg_MIDI();

  if ( resultado==MIDI_RET_OK ) 
     { // ------------------------------------------------------------
       //
       // ------------------------------------------------------------
       if ( c_MIDI.get_Channel()==1 )
          { // -------------------------------------------------------
            //
            // -------------------------------------------------------
            
            
            
          }
     }




}





// ------------------------------------------------------------
//
// void readMIDI(byte* channel ,byte* type, byte* data1, byte* data2)
//
// ------------------------------------------------------------
    byte type;
byte channel;
byte data1;
byte data2;

 void readMIDI(byte* channel ,byte* type, byte* data1, byte* data2)
   {

     


    int aux;

    while (Serial.available()>0){

    aux=Serial.read();

    if ((aux >= B10000000)&&(aux <= B11101111)){

    // Si es byte STATUS legal:

    *channel=(aux&B00001111)+1; //canales entre 1 y 16

    *type=(aux&B11110000);

    // Esperamos porque si aún no han llegado los datos,

    // los Serial.read() devolverán -1:

    while (Serial.available() < 2){

    }

    *data1 = Serial.read();

    *data2 = Serial.read();

    break; // Sale porque ha leído un mensaje MIDI correcto

    }

    }

    }

