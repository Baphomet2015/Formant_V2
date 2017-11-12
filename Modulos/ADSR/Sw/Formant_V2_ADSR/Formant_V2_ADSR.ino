
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
#include "Formant_V2_ADSR.h"





// ------------------------------------------------------------
//
//
//
//
// ------------------------------------------------------------


byte flg_estado_ADSR;      // Estado del modulo ADSR 
                           // Valores:
                           // . IDE_ADSR_OK
                           // . IDE_ADSR_A
                           // . IDE_ADSR_D                                                     
                           // . IDE_ADSR_S
                           // . IDE_ADSR_R
                           // . IDE_ADSR_RESET                           

byte flg_GATE;             // Estado de la senal GATE
                           // Valores:
                           // . IDE_GATE_ON , senal GATE activa, se esta pulsando una tecla
                           // . IDE_GATE_OFF, senal GATE inactiva, NO se esta pulsando una tecla

int vOut_adsr;             // Tension medida en la Salida del ADSR 
int vSustain_adsr;         // Tension medida en el potenciometro de SUSTAIN
int flg_Sustain;           // Periodo SUSTAIN habilitado/No habilitado

unsigned long int t;       // Para hacer medidas de pruebas





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

   flg_estado_ADSR = IDE_ADSR_RESET;
   flg_GATE        = IDE_GATE_OFF;
   flg_Sustain     = false;
   t               = 0L;
   
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
  genera_ADSR();

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
       t = 0L;
     }
}



// ------------------------------------------------------------
//
// void genera_ADSR(void)
// Genera la envolvente ADSR en el modulo indicado, esta funcion 
// se debe llamar continuamente MIENTRAS se recibe la seÃ±al  de
// GATE, que equivale a tecla pulsada
//
// ------------------------------------------------------------

void genera_ADSR(void)
{
  byte adsr_A;
  byte adsr_AF;
  byte adsr_D;
  byte adsr_S;
  byte adsr_R;
   
  
  // -------------------------------------------
  // Utilizar sus pines asociados
  // -------------------------------------------
  adsr_A  = IDE_HW_PIN_ADSR_1_A;
  adsr_AF = IDE_HW_PIN_ADSR_1_AF;
  adsr_D  = IDE_HW_PIN_ADSR_1_D;
  adsr_S  = IDE_HW_PIN_ADSR_1_S;
  adsr_R  = IDE_HW_PIN_ADSR_1_R;
           
              
  vOut_adsr     = analogRead(adsr_AF);
  vSustain_adsr = analogRead(adsr_S);
                 
  switch ( flg_estado_ADSR )
         {
           case ( IDE_ADSR_RESET ):
                { // ---------------------------------------------
                  // Reinicia el ADSR 1 y reseta la variable global
                  // que indica que se debe hacer
                  // ---------------------------------------------
                  ini_ADSR();
                  flg_estado_ADSR = IDE_ADSR_OK;
                  break;
                }
      
           case ( IDE_ADSR_OK ):
                { // ---------------------------------------------
                  // 
                  // 
                  // ---------------------------------------------
                  if ( flg_GATE==IDE_GATE_ON )
                     {
                       ini_ADSR();
                       flg_estado_ADSR = IDE_ADSR_A;
                     }
                  break;
                }
                
           case ( IDE_ADSR_A ):
                { // ---------------------------------------------
                  // Generar parte ATTACK
                  // ---------------------------------------------
                  genera_ATTACK(adsr_A,adsr_AF,adsr_D,adsr_S,adsr_R);
                  break;
                }
              
           case ( IDE_ADSR_D ):
                { // ---------------------------------------------
                  // Generar parte DECAY
                  // ---------------------------------------------
                  genera_DECAY(adsr_A,adsr_AF,adsr_D,adsr_S,adsr_R);
                  break;
                }

           case ( IDE_ADSR_S ):
                { // ---------------------------------------------
                  // Generar parte SUSTAIN
                  // ---------------------------------------------
                  genera_SUSTAIN(adsr_A,adsr_AF,adsr_D,adsr_S,adsr_R);
                  break;
                }
        
           case ( IDE_ADSR_R ):
                { // ---------------------------------------------
                  // Generar parte RELEASE
                  // ---------------------------------------------
                  genera_RELEASE(adsr_A,adsr_AF,adsr_D,adsr_S,adsr_R);
                  break;
                }
        }

}



// ------------------------------------------------------------
//
// void ini_ADSR(void)
// Inicializa el modulo ADSR
//
// ------------------------------------------------------------

void ini_ADSR(void)
{
  digitalWrite(IDE_HW_PIN_ADSR_1_A,LOW); // Inicializa control del ATTACK 
  digitalWrite(IDE_HW_PIN_ADSR_1_D,LOW); // Inicializa control del DECAY  
  digitalWrite(IDE_HW_PIN_ADSR_1_R,LOW); // Inicializa control del RELEASE
  vOut_adsr     = 0;
  vSustain_adsr = 0;
  flg_Sustain   = false;
}



// ------------------------------------------------------------
//
// void genera_ATTACK( byte adsr_A  ,
//                     byte adsr_AF ,
//                     byte adsr_D  ,
//                     byte adsr_S  ,
//                     byte adsr_R  ,
//                   )
//
// ------------------------------------------------------------

void genera_ATTACK(byte adsr_A,byte adsr_AF,byte adsr_D,byte adsr_S,byte adsr_R)
{
  byte flg_Fin_ATTACK;

  
  flg_Fin_ATTACK = true;

  if ( flg_GATE==IDE_GATE_ON )
     { // ---------------------------------------------
       // Se mantiene la tecla pulsada durante el 
       // periodo de ATTACK
       // ---------------------------------------------
      
       if ( vOut_adsr>=vSustain_adsr )
          {
            flg_Sustain = true;   
          }
             
       if ( vOut_adsr>=IDE_ADSR_FIN_ATTACK )
          { // ------------------------------------------------------------
            // Alcanzado el nivel de ATTACK
            // Finaliza el ATTACK y activa DECAY
            // ------------------------------------------------------------
            #ifdef DEBUG_MIDI
            Serial.print("ATTACK: ");
            Serial.print(millis()-t,DEC);
            Serial.println("ms");
            #endif
      
          }
       else   
          {
            digitalWrite(adsr_A,HIGH);       
            flg_Fin_ATTACK = false;
          }
     }     
  
  if ( flg_Fin_ATTACK==true )
     { // ------------------------------------------------------------
       // Fin del periodo de ATTACK       
       // Activa el periodo DECAY
       // ------------------------------------------------------------
       digitalWrite(adsr_A,LOW);              
       digitalWrite(adsr_D,HIGH);              
       flg_estado_ADSR = IDE_ADSR_D;
     }
   
}



// ------------------------------------------------------------
//
// void genera_DECAY( byte adsr_A  ,
//                    byte adsr_AF , 
//                    byte adsr_D  ,
//                    byte adsr_S  ,
//                    byte adsr_R  ,
//                  )
//
// ------------------------------------------------------------

void genera_DECAY(byte adsr_A,byte adsr_AF,byte adsr_D,byte adsr_S,byte adsr_R)
{
  if ( flg_GATE==IDE_GATE_ON )
     { // ---------------------------------------------
       // Se mantiene la tecla pulsada durante el 
       // periodo de DECAY
       // ---------------------------------------------
   
       if ( (flg_Sustain==true) && (vOut_adsr<=vSustain_adsr) )
          { // ------------------------------------------------------------
            // Alcanzado el nivel de SUSTAIN
            // Finaliza el DECAY y activa el SUSTAIN
            // ------------------------------------------------------------
            #ifdef DEBUG_MIDI
            Serial.print("DECAY: ");
            Serial.print(millis()-t,DEC);
            Serial.println("ms");
            #endif
       
            digitalWrite(adsr_D,LOW);
            flg_estado_ADSR = IDE_ADSR_S;
         }

     }
  else
     { // ---------------------------------------------
       // Deja de pulsar tecla  durante el  periodo  de
       // DECAY, reinicia el  ADSR dejando el estado en
       // IDE_ADSR_OK, listo para el proximo disparo
       // ---------------------------------------------
       flg_estado_ADSR = IDE_ADSR_OK;
     }
  
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

void genera_SUSTAIN(byte adsr_A,byte adsr_AF,byte adsr_D,byte adsr_S,byte adsr_R)
{
  if ( flg_GATE==IDE_GATE_OFF )
     { // ---------------------------------------------
       // Se deja de recibir la senal GATE despues del 
       // periodo de SUSTAIN
       // ---------------------------------------------
       digitalWrite(adsr_R,HIGH);
       flg_estado_ADSR = IDE_ADSR_OK;   
     }
  
  
  
  
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

void genera_RELEASE(byte adsr_A,byte adsr_AF,byte adsr_D,byte adsr_S,byte adsr_R)
{
  
  
  
  
  
}





