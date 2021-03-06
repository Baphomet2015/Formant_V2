
// ---------------------------------------------------------
//
// Proyecto:       Formant_V2
// Version:        1.0
// Fichero:        ADSR.ino
// Autor:   
// Hardware:       Arduino Nano V3.0
// Fecha:          Noviembre 2017
//
// Funcionalidad:  Implementacion de los miembros de la clase
//                 ADSR
//
// Notas:          REVISADO --        
//
// ---------------------------------------------------------

#include <Arduino.h>
#include <stdlib.h>
#include "ADSR.h"





// ------------------------------------------------------------
//
// void ARDUINO_ADSR::begin( byte p_adsr_A    ,
//                           byte p_adsr_D    ,
//                           byte p_adsr_S    ,
//                           byte p_adsr_R    ,
//                           byte p_adsr_OUT  ,
//                           byte p_modo
//                         )
// Genera la envolvente ADSR en el modulo indicado, esta funcion 
// se debe llamar continuamente MIENTRAS se recibe la seÃ±al  de
// GATE, que equivale a tecla pulsada
//
// ------------------------------------------------------------

void ARDUINO_ADSR::begin(byte p_adsr_A,byte p_adsr_D,byte p_adsr_S,byte p_adsr_R,byte p_adsr_OUT,byte p_modo)
{
  adsr_A    = p_adsr_A;
  adsr_D    = p_adsr_D;
  adsr_S    = p_adsr_S;
  adsr_R    = p_adsr_R;
  adsr_OUT  = p_adsr_OUT;
  adsr_modo = p_modo;
  
  pinMode(adsr_A   ,OUTPUT); // Control del ATTACK
  pinMode(adsr_D   ,OUTPUT); // Control del DECAY 
  pinMode(adsr_S   ,INPUT);  // Control del SUSTAIN (pin analogico)
  pinMode(adsr_R   ,OUTPUT); // Control del RELEASE
  pinMode(adsr_OUT ,INPUT);  // Para medir la tension de salida del ADSR (pin analogico)
  pinMode(adsr_modo,INPUT);  // Para leer el modo de funcionamiento seleccionado
  
  modo       = get_Modo();
  inicializar();
  flg_Estado = IDE_ADSR_OK;
    
  #ifdef DEBUG_ADSR  
  if ( modo==HIGH ) { Serial.println("MODO AD");   }
  else              { Serial.println("MODO ADSR"); }
  #endif
  
}



// ------------------------------------------------------------
//
// void ARDUINO_ADSR::inicializar(void)
// Inicializa el modulo ADSR
//
// ------------------------------------------------------------

void ARDUINO_ADSR::inicializar(void)
{
  digitalWrite(adsr_A,LOW); // Inicializa control del ATTACK 
  digitalWrite(adsr_D,LOW); // Inicializa control del DECAY  
  digitalWrite(adsr_R,LOW); // Inicializa control del RELEASE
  vOut        = 0;
  vSustain    = 0;
  flg_Sustain = false;
  flg_Inicio  = false;

  #ifdef DEBUG_ADSR
  Serial.println("ADSR Inicializado...");
  #endif
}



// ------------------------------------------------------------
//
// void ARDUINO_ADSR::generar(byte estado_GATE)
//
// ------------------------------------------------------------

void ARDUINO_ADSR::generar(byte estado_GATE)
{
  byte m;

  m = get_Modo();
  if ( modo!=m )
     { // ----------------------------------------------
       // Ha cambiado el modo de funcionamiento
       // ----------------------------------------------
       modo = m;
       inicializar();
       flg_Estado = IDE_ADSR_OK;
       
       #ifdef DEBUG_ADSR
       if ( modo==HIGH ) { Serial.println("MODO AD");   }
       else              { Serial.println("MODO ADSR"); }
       #endif
     }
  
  if ( (flg_Inicio==false)  )    
     { // ----------------------------------------------
       // Se dispara la generacion de envolvente
       // ----------------------------------------------
       flg_Inicio = true;
     }

  if ( flg_Inicio==true) 
     { // ----------------------------------------------
       // Generar envolvente
       // ----------------------------------------------
       vOut     = analogRead(adsr_OUT);
       vSustain = analogRead(adsr_S);
       flg_GATE = estado_GATE;
       
       gen_Envolvente(); 
     }
  
}



// ------------------------------------------------------------
//
// void ARDUINO_ADSR::gen_Envolvente(void)
//
// ------------------------------------------------------------

void ARDUINO_ADSR::gen_Envolvente(void)
{

  #ifdef DEBUG_ADSR
  switch ( flg_Estado )
         {
        // case ( IDE_ADSR_OK ): { Serial.println("OK");      break; }
           case ( IDE_ADSR_A  ): { Serial.println("ATTACK");  break; }
           case ( IDE_ADSR_D  ): { Serial.println("DECAY");   break; }
           case ( IDE_ADSR_S  ): { Serial.println("SUSTAIN"); break; }
           case ( IDE_ADSR_R  ): { Serial.println("RELEASE"); break; }
        }
  #endif
  
  switch ( flg_Estado )
         {
           case ( IDE_ADSR_OK ):
                { // ---------------------------------------------
                  // 
                  // 
                  // ---------------------------------------------
                  if ( flg_GATE==IDE_GATE_ON )
                     {
                       inicializar();
                       flg_Estado = IDE_ADSR_A;
                     }
                  break;
                }
                
           case ( IDE_ADSR_A ):
                { // ---------------------------------------------
                  // Generar parte ATTACK
                  // ---------------------------------------------
                  genera_ATTACK();
                  break;
                }
              
           case ( IDE_ADSR_D ):
                { // ---------------------------------------------
                  // Generar parte DECAY
                  // ---------------------------------------------
                  genera_DECAY();
                  break;
                }

           case ( IDE_ADSR_S ):
                { // ---------------------------------------------
                  // Generar parte SUSTAIN
                  // ---------------------------------------------
                  genera_SUSTAIN();
                  break;
                }
        
           case ( IDE_ADSR_R ):
                { // ---------------------------------------------
                  // Generar parte RELEASE
                  // ---------------------------------------------
                  genera_RELEASE();
                  break;
                }
        }
}



// ------------------------------------------------------------
//
// byte ARDUINO_ADSR::get_Modo(void)
//
// ------------------------------------------------------------

byte ARDUINO_ADSR::get_Modo(void)
{
  byte mAux;
  
  mAux = digitalRead(adsr_modo);
      
  return(mAux);
}



// ------------------------------------------------------------
//
// void ARDUINO_ADSR::genera_ATTACK(void)
//
// ------------------------------------------------------------

void ARDUINO_ADSR::genera_ATTACK(void)
{
  byte flg_Fin_ATTACK;

  
  flg_Fin_ATTACK = true;

  if ( (flg_GATE==IDE_GATE_ON) || (modo==HIGH) )
     { // ---------------------------------------------
       // Se mantiene  la   tecla  pulsada  durante  el 
       // periodo de ATTACK, o bien esta en modo AD
       // ---------------------------------------------
      
       if ( vOut>=vSustain )
          {
            flg_Sustain = true;          
          }
             
       if ( vOut>=IDE_ADSR_FIN_ATTACK )
          { // ------------------------------------------------------------
            // Alcanzado el nivel de ATTACK
            // Finaliza el ATTACK y activa DECAY
            // ------------------------------------------------------------
            #ifdef DEBUG_ADSR
            Serial.println("OUT: ");
            Serial.print(vOut);
            Serial.print(" SUSTAIN: ");
            Serial.println(vSustain);
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
       flg_Estado = IDE_ADSR_D;
     }
   
}



// ------------------------------------------------------------
//
// void ARDUINO_ADSR::genera_DECAY(void)
//
// ------------------------------------------------------------

void ARDUINO_ADSR::genera_DECAY(void)
{

  if ( (flg_GATE==IDE_GATE_ON) || (modo==HIGH) )
     { // ---------------------------------------------
       // Se mantiene la tecla pulsada durante el 
       // periodo de DECAY
       // ---------------------------------------------
       
       if ( modo==LOW ) 
          { // ---------------------------------------------
            // Control de finalizacion de DECAY en modo ADSR
            // ---------------------------------------------
            if ( (flg_Sustain==true) && (vOut<=vSustain) )
               { // ------------------------------------------------------------
                 // Alcanzado el nivel de SUSTAIN
                 // Finaliza el DECAY y activa el SUSTAIN
                 // ------------------------------------------------------------
                 digitalWrite(adsr_D,LOW);
                 flg_Estado = IDE_ADSR_S;
               }
         }
      else
          { // ---------------------------------------------
            // Control de finalizacion de DECAY en modo AD
            // ---------------------------------------------
           if ( vOut<=IDE_AD_FIN_DECAY )
              {
                digitalWrite(adsr_D,LOW);
                flg_Estado = IDE_ADSR_OK;
              }
         
         }
    }
  else
     { // ---------------------------------------------
       // Deja de pulsar tecla  durante el  periodo  de
       // DECAY, en modo ADSR, reinicia el ADSR dejando
       // el  estado  en  IDE_ADSR_OK,  listo  para  el
       // proximo disparo
       // ---------------------------------------------
       flg_Estado = IDE_ADSR_OK;
     }
  
}



// ------------------------------------------------------------
//
// void ARDUINO_ADSR::genera_SUSTAIN(void)
//
// ------------------------------------------------------------

void ARDUINO_ADSR::genera_SUSTAIN(void)
{
  
  if ( flg_GATE==IDE_GATE_OFF )
     { // ---------------------------------------------
       // Se deja de recibir la senal GATE despues del 
       // periodo de SUSTAIN
       // ---------------------------------------------
       digitalWrite(adsr_R,HIGH);
       flg_Estado = IDE_ADSR_OK;   
     }
  
}



// ------------------------------------------------------------
//
// void ARDUINO_ADSR::genera_RELEASE(void)
//
// ------------------------------------------------------------

void ARDUINO_ADSR::genera_RELEASE(void)
{
  
  
  
  
  
}





