
// ---------------------------------------------------------
//
// Proyecto:       Formant_V2
// Version:        1.0
// Fichero:        Formant_V2_ADSR.ino
// Autor:   
// Hardware:       Arduino Nano V3.0
// Fecha:          Noviembre 2017
//
// Funcionalidad:  Fichero principal ( main ) de la aplicaciÃ³n
//                 de control del generador de ADSR.
//
// Notas:          REVISADO --        
//
// ---------------------------------------------------------

#include <Arduino.h>
#include <stdlib.h>
#include "ADSR.h"
#include "Formant_V2_ADSR.h"





// ------------------------------------------------------------
//
//
//
//
// ------------------------------------------------------------

ARDUINO_ADSR adsr_1;
ARDUINO_ADSR adsr_2;

byte flg_GATE;



// ------------------------------------------------------------
//
// setup()
//
//
// ------------------------------------------------------------

void setup()
{
   pinMode(IDE_HW_PIN_GATE,INPUT);

   adsr_1.begin( IDE_HW_PIN_ADSR_1_A  ,
                 IDE_HW_PIN_ADSR_1_D  ,
                 IDE_HW_PIN_ADSR_1_S  ,
                 IDE_HW_PIN_ADSR_1_R  , 
                 IDE_HW_PIN_ADSR_1_OUT
                );

   adsr_2.begin( IDE_HW_PIN_ADSR_2_A  ,
                 IDE_HW_PIN_ADSR_2_D  ,
                 IDE_HW_PIN_ADSR_2_S  ,
                 IDE_HW_PIN_ADSR_2_R  , 
                 IDE_HW_PIN_ADSR_2_OUT
                );
   
   Serial.begin(9600);
     
}





// ------------------------------------------------------------
//
// void loop()
//
// ------------------------------------------------------------

void loop()
{

  // ------------------------------------------------------------
  // .
  // .
  // .
  // ------------------------------------------------------------
  getGATE();
  
  // ------------------------------------------------------------
  // .
  // .
  // .
  // ------------------------------------------------------------
  adsr_1.generar(flg_GATE);
  adsr_2.generar(flg_GATE);

}




// ------------------------------------------------------------
//
// Lee la senal de GATE y actualiza el flag global
//
// ------------------------------------------------------------

void getGATE(void)
{
  if ( digitalRead(IDE_HW_PIN_GATE)==HIGH )
     { // ------------------------------------------------------------
       // Senal GATE activa
       // ------------------------------------------------------------
       flg_GATE = IDE_GATE_ON;
     }
  else
     { // ------------------------------------------------------------
       // Senal GATE inactiva
       // ------------------------------------------------------------
       flg_GATE = IDE_GATE_OFF;
     }
}




