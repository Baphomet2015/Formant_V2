
// ---------------------------------------------------------
//
// Proyecto:       Formant_V2
// Version:        1.0
// Fichero:        Formant_V2_ADSR.ino
// Autor:   
// Hardware:       Arduino Nano V3.0
// Fecha:          Noviembre 2017
//
// Funcionalidad:  Fichero principal ( main ) de la aplicación
//                 de control del generador de ADSR.
//
// Notas:          REVISADO --        
//
// ---------------------------------------------------------

#include <Arduino.h>
#include <stdlib.h>
#include "Formant_V2_ADSR.h"





// ------------------------------------------------------------
//
//
//
//
// ------------------------------------------------------------


byte flg_estado_ADSR_1;    // Estado del modulo ADSR 1
                           // Valores:
                           // . IDE_ADSR_OK
                           // . IDE_ADSR_A
                           // . IDE_ADSR_D                                                     
                           // . IDE_ADSR_S
                           // . IDE_ADSR_R
                           // . IDE_ADSR_RESET                           

byte flg_estado_ADSR_2;    // Estado del modulo ADSR 2
                           // Valores:
                           // . IDE_ADSR_OK
                           // . IDE_ADSR_A
                           // . IDE_ADSR_D                                                     
                           // . IDE_ADSR_S
                           // . IDE_ADSR_R
                           // . IDE_ADSR_RESET                           

byte flg_GATE;             // Estado de la señal GATE
                           // Valores:
                           // . IDE_GATE_ON , señal GATE activa, se esta pulsando una tecla
                           // . IDE_GATE_OFF, señal GATE inactiva, NO se esta pulsando una tecla



// ------------------------------------------------------------
//
// setup()
//
//
// ------------------------------------------------------------

void setup()
{
   pinMode(IDE_HW_PIN_GATE,INPUT);

   pinMode(IDE_HW_PIN_ADSR_1_A,OUTPUT); // Control del ATTACK , en ADSR 1
   pinMode(IDE_HW_PIN_ADSR_1_D,OUTPUT); // Control del DECAY  , en ADSR 1
   pinMode(IDE_HW_PIN_ADSR_1_S,INPUT);  // Control del SUSTAIN, en ADSR 1  
   pinMode(IDE_HW_PIN_ADSR_1_R,OUTPUT); // Control del RELEASE, en ADSR 1

   pinMode(IDE_HW_PIN_ADSR_2_A,OUTPUT); // Control del ATTACK , en ADSR 2
   pinMode(IDE_HW_PIN_ADSR_2_D,OUTPUT); // Control del DECAY  , en ADSR 2
   pinMode(IDE_HW_PIN_ADSR_2_S,INPUT);  // Control del SUSTAIN, en ADSR 2  
   pinMode(IDE_HW_PIN_ADSR_2_R,OUTPUT); // Control del RELEASE, en ADSR 2


   flg_estado_ADSR_1 = IDE_ADSR_RESET;
   flg_estado_ADSR_2 = IDE_ADSR_RESET;
   flg_GATE          = IDE_GATE_OFF;
  

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
  genera_ADSR(IDE_ADSR_1);
  genera_ADSR(IDE_ADSR_2);

  if ( digitalRead(IDE_HW_PIN_GATE)==HIGH )
     { // ------------------------------------------------------------
       // Señal GATE activa
       // ------------------------------------------------------------
       flg_GATE = IDE_GATE_ON;

       if ( flg_estado_ADSR_1==IDE_ADSR_OK )
          { // ------------------------------------------------------------
            // Inicia el ciclo de generacion de la envolvente en ADSR 1
            // ------------------------------------------------------------
            flg_estado_ADSR_1 = IDE_ADSR_A;
          }
          
       if ( flg_estado_ADSR_2==IDE_ADSR_OK )
          { // ------------------------------------------------------------
            // Inicia el ciclo de generacion de la envolvente en ADSR 2
            // ------------------------------------------------------------
            flg_estado_ADSR_2 = IDE_ADSR_A;
          }
     }
  else
     { 
       if ( flg_GATE==IDE_GATE_ON )
          { // ------------------------------------------------------------
            // La señal GATE se estaba recibiendo y se deja de recibir, 
            // es decir estaba pulsando una tecla y deja de hacerlo
            // ------------------------------------------------------------
            flg_GATE          = IDE_GATE_OFF;
            flg_estado_ADSR_1 = IDE_ADSR_RESET;
            flg_estado_ADSR_2 = IDE_ADSR_RESET;
          }
     }  

}



// ------------------------------------------------------------
//
// void genera_ADSR(adsr_ID)
// Genera la envolvente ADSR en el modulo indicado, esta funcion 
// se debe llamar continuamente MIENTRAS se recibe la señal  de
// GATE, que equivale a tecla pulsada
//
// ------------------------------------------------------------

void genera_ADSR(byte adsr_ID)
{
  byte adsr_A;
  byte adsr_AF;
  byte adsr_D;
  byte adsr_S;
  byte adsr_R;
   
  
  switch( adsr_ID )
        {
          case (IDE_ADSR_1):
               { // -------------------------------------------
                 // ADSR 1, utilizar sus pines asociados
                 // -------------------------------------------
                 adsr_A  = IDE_HW_PIN_ADSR_1_A;
                 adsr_AF = IDE_HW_PIN_ADSR_1_AF;
                 adsr_D  = IDE_HW_PIN_ADSR_1_D;
                 adsr_S  = IDE_HW_PIN_ADSR_1_S;
                 adsr_R  = IDE_HW_PIN_ADSR_1_R;
                 switch ( flg_estado_ADSR_1 )
                        {
                          case ( IDE_ADSR_RESET ):
                               { // ---------------------------------------------
                                 // Reinicia el ADSR 1 y reseta la variable global
                                 // que indica que se debe hacer
                                 // ---------------------------------------------
                                 ini_ADSR(IDE_ADSR_1);
                                 flg_estado_ADSR_1 = IDE_ADSR_OK;
                                 break;
                               }
                          case ( IDE_ADSR_A ):
                               { // ---------------------------------------------
                                 // Generar parte ATTACK en ADSR 1
                                 // ---------------------------------------------
                                 genera_ATTACK(adsr_ID,adsr_A,adsr_AF,adsr_D,adsr_S,adsr_R);
                                 break;
                               }
                          case ( IDE_ADSR_D ):
                               { // ---------------------------------------------
                                 // Generar parte DECAY en ADSR 1
                                 // ---------------------------------------------
                                 genera_DECAY(adsr_ID,adsr_A,adsr_AF,adsr_D,adsr_S,adsr_R);
                                 break;
                               }
                          case ( IDE_ADSR_S ):
                               { // ---------------------------------------------
                                 // Generar parte SUSTAIN en ADSR 1
                                 // ---------------------------------------------
                                 genera_SUSTAIN(adsr_ID,adsr_A,adsr_AF,adsr_D,adsr_S,adsr_R);
                                 break;
                               }
                          case ( IDE_ADSR_R ):
                               { // ---------------------------------------------
                                 // Generar parte RELEASE en ADSR 1
                                 // ---------------------------------------------
                                 genera_RELEASE(adsr_ID,adsr_A,adsr_AF,adsr_D,adsr_S,adsr_R);
                                 break;
                               }
                        }
                 break;
               } 
               
          case (IDE_ADSR_2):
               { // -------------------------------------------
                 // ADSR 2, utilizar sus pines asociados
                 // -------------------------------------------
                 adsr_A  = IDE_HW_PIN_ADSR_2_A;
                 adsr_AF = IDE_HW_PIN_ADSR_2_AF;                 
                 adsr_D  = IDE_HW_PIN_ADSR_2_D;
                 adsr_S  = IDE_HW_PIN_ADSR_2_S;
                 adsr_R  = IDE_HW_PIN_ADSR_2_R;
                 switch ( flg_estado_ADSR_2 )
                        {
                          case ( IDE_ADSR_RESET ):
                               { // ---------------------------------------------
                                 // Reinicia el ADSR 2 y reseta la variable global
                                 // que indica que se debe hacer
                                 // ---------------------------------------------
                                 ini_ADSR(IDE_ADSR_2);
                                 flg_estado_ADSR_2 = IDE_ADSR_OK;
                                 break;
                               }
                          case ( IDE_ADSR_A ):
                               { // ---------------------------------------------
                                 // Generar parte ATTACK en ADSR 1
                                 // ---------------------------------------------
                                 genera_ATTACK(adsr_ID,adsr_A,adsr_AF,adsr_D,adsr_S,adsr_R);
                                 break;
                               }
                          case ( IDE_ADSR_D ):
                               { // ---------------------------------------------
                                 // Generar parte DECAY en ADSR 1
                                 // ---------------------------------------------
                                 genera_DECAY(adsr_ID,adsr_A,adsr_AF,adsr_D,adsr_S,adsr_R);
                                 break;
                               }
                          case ( IDE_ADSR_S ):
                               { // ---------------------------------------------
                                 // Generar parte SUSTAIN en ADSR 1
                                 // ---------------------------------------------
                                 genera_SUSTAIN(adsr_ID,adsr_A,adsr_AF,adsr_D,adsr_S,adsr_R);
                                 break;
                               }
                          case ( IDE_ADSR_R ):
                               { // ---------------------------------------------
                                 // Generar parte RELEASE en ADSR 1
                                 // ---------------------------------------------
                                 genera_RELEASE(adsr_ID,adsr_A,adsr_AF,adsr_D,adsr_S,adsr_R);
                                 break;
                               }
                        }
                 break;
               } 
        }

}



// ------------------------------------------------------------
//
// void ini_ADSR(byte adsr_ID)
// Inicializa el modulo ADSR indicado
//
// ------------------------------------------------------------

void ini_ADSR(byte adsr_ID)
{
  switch( adsr_ID )
        {
          case (IDE_ADSR_1):
               { // -------------------------------------------
                 // Inicializar el ADSR 1
                 // -------------------------------------------
                 digitalWrite(IDE_HW_PIN_ADSR_1_A,LOW); // Inicializa control del ATTACK , en ADSR 1
                 digitalWrite(IDE_HW_PIN_ADSR_1_D,LOW); // Inicializa control del DECAY  , en ADSR 1
                 digitalWrite(IDE_HW_PIN_ADSR_1_R,LOW); // Inicializa control del RELEASE, en ADSR 1
                 break;
               } 
               
          case (IDE_ADSR_2):
               { // -------------------------------------------
                 // Inicializar el ADSR 2
                 // -------------------------------------------
                 digitalWrite(IDE_HW_PIN_ADSR_2_A,LOW); // Inicializa control del ATTACK , en ADSR 2
                 digitalWrite(IDE_HW_PIN_ADSR_2_D,LOW); // Inicializa control del DECAY  , en ADSR 2
                 digitalWrite(IDE_HW_PIN_ADSR_2_R,LOW); // Inicializa control del RELEASE, en ADSR 2
                 break;
               } 
        }
}



// ------------------------------------------------------------
//
// void genera_ATTACK( byte adsr_ID ,
//                     byte adsr_A  ,
//                     byte adsr_AF ,
//                     byte adsr_D  ,
//                     byte adsr_S  ,
//                     byte adsr_R  ,
//                   )
//
// ------------------------------------------------------------

void genera_ATTACK(byte adsr_ID,byte adsr_A,byte adsr_AF,byte adsr_D,byte adsr_S,byte adsr_R)
{
  if ( digitalRead(adsr_AF)>=IDE_ADSR_FIN_ATTACK )
     {
       digitalWrite(adsr_A,LOW);              
       digitalWrite(adsr_D,HIGH);              
       if ( adsr_ID==IDE_ADSR_1 ) { flg_estado_ADSR_1 = IDE_ADSR_D; }
       else                       { flg_estado_ADSR_2 = IDE_ADSR_D; } 
     }
  else   
     {
       digitalWrite(adsr_A,HIGH);       
     }
   
}



// ------------------------------------------------------------
//
// void genera_DECAY( byte adsr_ID ,
//                    byte adsr_A  ,
//                    byte adsr_AF , 
//                    byte adsr_D  ,
//                    byte adsr_S  ,
//                    byte adsr_R  ,
//                  )
//
// ------------------------------------------------------------

void genera_DECAY(byte adsr_ID,byte adsr_A,byte adsr_AF,byte adsr_D,byte adsr_S,byte adsr_R)
{
  
  
  
  
  
}



// ------------------------------------------------------------
//
// void genera_SUSTAIN( byte adsr_A  ,
//                      byte adsr_AF ,
//                      byte adsr_D  ,
//                      byte adsr_S  ,
//                      byte adsr_R  ,
//                    )
//
// ------------------------------------------------------------

void genera_SUSTAIN(byte adsr_ID,byte adsr_A,byte adsr_AF,byte adsr_D,byte adsr_S,byte adsr_R)
{
  
  
  
  
  
}



// ------------------------------------------------------------
//
// void genera_RELEASE( byte adsr_A  ,
//                      byte adsr_AF ,
//                      byte adsr_D  ,
//                      byte adsr_S  ,
//                      byte adsr_R  ,
//                    )
//
// ------------------------------------------------------------

void genera_RELEASE(byte adsr_ID,byte adsr_A,byte adsr_AF,byte adsr_D,byte adsr_S,byte adsr_R)
{
  
  
  
  
  
}




