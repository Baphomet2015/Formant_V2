
// ---------------------------------------------------------
//
// Proyecto:       Formant_V2
// Version:        1.0
// Fichero:        Ver_Analogico.ino
//
//                 Version para Hardware de interfaz analogico
//                 de teclado ( array de resistencias original
//                 del formant)
// Autor:   
// Hardware:       Arduino Nano V3.0
// Fecha:          Junio 2017
//
// Funcionalidad:  Fichero principal ( main ) de la aplicación
//                 de control del interfaz MIDI de teclado.
//
// Notas:          REVISADO --        
//
// ---------------------------------------------------------

#include <Arduino.h>
#include <EEPROM.h>
#include <stdlib.h>
#include "Formant_V2_MIDI.h"
#include "Formant_Teclado.h"




// ------------------------------------------------------------
//
//
//
//
// ------------------------------------------------------------


ARDUINO_MIDI c_MIDI;                               // Variable para manejar los datos MIDI
byte         canalID;                              // Canal MIDI asignado al Formant V2
byte         modoF;                                // Modo de funcionamniento: TEST/Normal

                                                   // ------------------------------------------------------------
byte         tab_TeclasEstado[IDE_MAX_TECLA_ID+1]; // Tabla con el estado de cada  tecla , esta  tabla  se utiliza 
                                                   // para controlar el estado de cada tecla (pulsada o sin pulsar)
                                                   // Cada posicion en esta  tabla  almacena el estado de la tecla
                                                   // correspondiente, por ejemplo el estado de la  tecla MIDI con
                                                   // el codigo 27 se almacena en tab_TeclasEstado[27] etc
                                                   // Estados posibles:
                                                   // . IDE_TECLA_ESTADO_OFF, Tecla SIN pulsar
                                                   // . IDE_TECLA_ESTADO_ON,  Tecla pulsada
                                                   //
                                                   // Los codigos MIDI de las teclas reconocidas se  fijan con los 
                                                   // defines:
                                                   //  #define IDE_MIN_TECLA_ID codigo MIDI de la tecla mas baja
                                                   //  #define IDE_MAX_TECLA_ID codigo MIDI de la tecla mas alta
                                                   // Se dimensiona  1  mas  porque  el valor de tecla mas alto es  
                                                   // IDE_MAX_TECLA_ID incluido
                                                   // ------------------------------------------------------------

byte volumenManualGeneral;                         // valor del potenciometro que fija el volumen general del Formant, en modo manual



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
          
   analogWrite(IDE_HW_PIN_VOLCOM_DATA ,0);
   analogWrite(IDE_HW_PIN_VOLCOM_RESET,0);
   analogWrite(IDE_HW_PIN_VOLCOM_CLOCK,0);

   volumenManualGeneral = 0;
     
   set_CodigoTecla(1);
   set_GATE(LOW);
   set_LedTeclaOn(LOW);
   get_CanalID();

   c_MIDI.begin(canalID);      // IMPORTANTE: Imprescindible llamar antes de usar la clase MIDI
                               //             . Programa el puerto serie con la velocidad MIDI
                               //             . Inicilaliza la clase
                               //             . La  clase  DEBE  recibir  el  canalID  asignado al 
                               //               interfaz por eso se llama DESPUES de get_canalID()        

      
   iniTabTeclasEstado();

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

  // ------------------------------------------------------------
  //
  // Mantiene activas funciones que no tienen que ver con el MIDI
  //
  // . getPotenciomentroManual_COM()
  //   Potenciometro  de  control  manual del volumen general del 
  //   Formant V2
  // .
  // .
  // .
  // .
  // 
  // ------------------------------------------------------------
  getPotenciomentroManual_COM();
    
    
    
  // ------------------------------------------------------------
  //
  // Implementacion del manejador de mensajes MIDI
  //
  // ------------------------------------------------------------
   
  if ( (c_MIDI.get_msg_MIDI(false)==MIDI_RET_OK) && (c_MIDI.get_Channel()==canalID) )  
     { // ------------------------------------------------------------
       // Se ha recibido informacion y va dirigida a este receptor
       // ------------------------------------------------------------
       switch( c_MIDI.get_Type() )
             { // -----------------------------------------------
               //
               //             EJECUTA EL MENSAJE
               //
               // -----------------------------------------------

               case ( MIDI_MSG_C_NOTE_ON ):
                    { // -----------------------------------------------
                      //                 PULSAR TECLA
                      // -----------------------------------------------
                      msg_MIDI_Tecla_ON();
                      break; 
                    }

               case ( MIDI_MSG_C_NOTE_OFF ):
                    { // -----------------------------------------------
                      //            DEJAR DE PULSAR TECLA
                      // -----------------------------------------------
                      msg_MIDI_Tecla_OFF();
                      break; 
                    }
                         
               case ( MIDI_MSG_S_RESET ):
                    { // -----------------------------------------------
                      //            RESET DE SISTEMA
                      // -----------------------------------------------
                      msg_MIDI_Reset();
                      break; 
                    }    
                        
               case ( MIDI_MSG_C_CTRL_CHG ):
                    { // -----------------------------------------------
                      //            CAMBIO DE CONTROL
                      // -----------------------------------------------
                      switch( c_MIDI.get_Data_01() )
                            {
                              case( MIDI_MSG_C_TECLAS_OFF ):
                                  { // -----------------------------------------------
                                    // OFF de todas las Teclas
                                    // -----------------------------------------------
                                    msg_MIDI_Ctrl_TeclasOFF();
                                    break;
                                  }
                              case( MIDI_MSG_C_VOLUMEN ):
                                  { // -----------------------------------------------
                                    // Volumen general del Formant  (Modulo COM)
                                    // -----------------------------------------------
                                     msg_MIDI_Ctrl_Volumen();
                                     break;
                                  }
                            }
                      break; 
                    }    
             }
     }
 
}



// ------------------------------------------------------------
//
// void msg_MIDI_Tecla_ON(void)
// Implementa el mensaje de tecla pulsada ( tecla ON )
//
// ------------------------------------------------------------

void msg_MIDI_Tecla_ON(void)
{
  int  resultado;
  byte teclaID;
                      
                      
  teclaID = c_MIDI.get_Data_01(); // Recupera el codigo de la tecla pulsada
  
  #ifdef DEBUG_MIDI 
  Serial.println();
  Serial.print  ("Tecla: ");
  Serial.println(teclaID,DEC);
  #endif
  
  if ( (teclaID>=IDE_MIN_TECLA_ID) && (teclaID<=IDE_MAX_TECLA_ID) )
     { // -------------------------------------------------
       // Procesa la tecla pulsada porque es un codigo MIDI
       // de tecla dentro del rango utilizable
       // -------------------------------------------------
       if ( c_MIDI.get_Data_02()==0 )
          { // -----------------------------------------------
            // Comprueba el parametro 2 del mensaje.
            // Un mensaje MIDI_MSG_C_NOTE_ON con velocidad=0
            // es equivalente al mensaje MIDI_MSG_C_NOTE_OFF
            // -----------------------------------------------
            tab_TeclasEstado[teclaID] = IDE_TECLA_ESTADO_OFF;     
            activarTeclaPulsada();    
          }
       else
          { // -----------------------------------------------
            // Los codigos MIDI que identifican las teclas van
            // del 0 ... 127 0   --> Do mas grave
            //               127 --> Teclas mas aguda 
            //
            // En el circuito de  interfaz el Formant V2 , las 
            // teclas se  numeran del 1 ...49  porque  son las 
            // teclas que maneja el HW (4 OCTAVAS).
            //
            // IMPORTANTE:
            // El codigo valor 0 se utiliza EN EL INTERFAZ del
            // Formant V2 para dejar de pulsar cualquier tecla
            // (queda seleccionada la entrada 0 del multiplexor
            // que esta unida a GND), por  lo que  las  teclas
            // empiezan en el 1 y hasta el 49 debido a esto se
            // debe sumar 1 al codigo de  tecla recibido en un
            // mensaje MIDI.
            // -----------------------------------------------
            tab_TeclasEstado[teclaID] = IDE_TECLA_ESTADO_ON;
            activarTeclaPulsada();                                    
          }
     }                        
 }




// ------------------------------------------------------------
//
// void msg_MIDI_Tecla_OFF(void)
// Implementa el mensaje de tecla no pulsada ( tecla OFF )
//
// ------------------------------------------------------------

void msg_MIDI_Tecla_OFF(void)
{
  int  resultado;
  byte teclaID;                         
               
  teclaID = c_MIDI.get_Data_01(); // Recupera el codigo de la tecla pulsada

  #ifdef DEBUG_MIDI 
  Serial.println();
  Serial.print  ("Tecla: ");
  Serial.println(teclaID,DEC);
  #endif
                           
  if ( (teclaID>=IDE_MIN_TECLA_ID) && (teclaID<=IDE_MAX_TECLA_ID) )
     { // -------------------------------------------------
       // Procesa la tecla pulsada porque es un codigo MIDI
       // de tecla dentro del rango utilizable
       // -------------------------------------------------
       tab_TeclasEstado[teclaID] = IDE_TECLA_ESTADO_OFF;     
       activarTeclaPulsada();    
     }
}




// ------------------------------------------------------------
//
// void msg_MIDI_Reset(void)
// Implementa el mensaje de SISTEMA de reset
//
// ------------------------------------------------------------

void msg_MIDI_Reset(void)
{
  iniTabTeclasEstado();
  activarTeclaPulsada();
}




// ------------------------------------------------------------
//
// void msg_MIDI_Ctrl_TeclasOFF(void)
// Implementa el mensaje de Control de cambio --> OFF de todas
// las teclas
//
// ------------------------------------------------------------

void msg_MIDI_Ctrl_TeclasOFF(void)
{
  iniTabTeclasEstado();
  activarTeclaPulsada();
}



// ------------------------------------------------------------
//
// void msg_MIDI_Ctrl_Volumen(void)
// Implementa el mensaje de Control de cambio --> Volumen
// general
//
// ------------------------------------------------------------

void msg_MIDI_Ctrl_Volumen(void)
{
  setPotenciomentro_COM(c_MIDI.get_Data_02());
}



// ------------------------------------------------------------
//
// void tecla_OFF(void)
//
//
// ------------------------------------------------------------

void tecla_OFF(void)
{
  // set_CodigoTecla(0);
  set_GATE(LOW);
  set_LedTeclaOn(LOW);
}



// ------------------------------------------------------------
//
// void tecla_ON(teclaID)
//
//
// ------------------------------------------------------------

void tecla_ON(byte teclaID)
{
  set_CodigoTecla(teclaID);
  set_GATE(HIGH);
  set_LedTeclaOn(HIGH);
}




// ------------------------------------------------------------
//
// void activarTeclaPulsada(void)
// Coloca en el decodificador  del  multiplexor  de  teclas, el 
// codigo de la tecla mas baja  que  este  pulsada  y si no hay
// ninguna tecla  pulsada  deja  seleccionado el 0 que es el NO
// pulsar nada.
// 
// ------------------------------------------------------------

void activarTeclaPulsada(void)
{
  int idx;  
  byte teclaID;
  byte teclaPulsada;
  
  
  teclaID      = 0;
  teclaPulsada = false;
  
  #ifdef DEBUG_MIDI 
  Serial.println();
  #endif 
  
  for ( idx=IDE_MAX_TECLA_ID;idx>=0;idx-- )
      { // -------------------------------------------------
        // Recorre la tabla de MAYOR A MENOR para determinar 
        // la tecla mas baja que esta pulsada
        // -------------------------------------------------
      
        #ifdef DEBUG_MIDI 
        Serial.print(tab_TeclasEstado[idx]);
        #endif 

        if ( tab_TeclasEstado[idx]==IDE_TECLA_ESTADO_ON )
           {
             teclaID      = idx;
             teclaPulsada = true;
           }
      }  
        
  if ( teclaPulsada==false )
     { // NO pulsar nada
       tecla_OFF();
     }
  else
     { // Deja pulsada la tecla mas baja
       tecla_ON(teclaID+1);   
     }

  #ifdef DEBUG_MIDI 
  Serial.println();
  Serial.print  ("Tecla pulsada: ");
  Serial.println(teclaID,DEC);
  #endif
 
}




// ------------------------------------------------------------
//
// void set_CodigoTecla(byte tecla)
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
  Serial.print  (IDE_STR_MSG_03);
  Serial.println(canalID);
  Serial.println(IDE_STR_MSG_04);
  Serial.println(IDE_STR_MSG_01);
  Serial.println();
  Serial.println();

  m = millis();
  
  while( 1 )
       {
         resultado = c_MIDI.get_msg_MIDI(true);

         if ( resultado==MIDI_RET_OK ) 
            { // ------------------------------------------------------------
              // Decodifica el mensaje y muestra lo recibido
              // ------------------------------------------------------------
              Serial.println();
                            
              Serial.print("MENSAJE: " );
              Serial.print(c_MIDI.get_Type(),HEX);
              Serial.println("H ");       
              
              Serial.print("CANAL:   " );
              Serial.print(c_MIDI.get_Channel(),DEC);
              Serial.println("");            
              
              Serial.print("DATA0:   " );
              Serial.print(c_MIDI.get_Data_01(),DEC);
              Serial.println("");          
              
              Serial.print("DATA1:   " );
              Serial.print(c_MIDI.get_Data_02(),DEC);
              Serial.println();
              Serial.println();
              
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
         if ( (millis()-m)>=1000L )
            {
              break;
           }   
      }
}





// ------------------------------------------------------------
//
// void iniTabTeclasEstado(void)
// Inicializa la tabla con el estado de las teclas, todas a OFF
//
// ------------------------------------------------------------

void iniTabTeclasEstado(void)
{
  byte idx;
  
  for ( idx=0;idx<=IDE_MAX_TECLA_ID;idx++ )
      {
        tab_TeclasEstado[idx] = IDE_TECLA_ESTADO_OFF;
      }
}





