
// ---------------------------------------------------------
//
// Proyecto:       Formant_V2
// Version:        1.0
// Fichero:        Formant_V2_COM.ino
// Autor:   
// Hardware:       Arduino Nano V3.0
// Fecha:          Junio 2017
//
// Funcionalidad:  Fichero con funciones relacionadas con el
//                 control del modulo COM
//
// Notas:          REVISADO --        
//
// ---------------------------------------------------------

#include <Arduino.h>
#include <stdlib.h>






// ------------------------------------------------------------
//
// void getPotenciomentroManual_COM(void)
//
// Lee el potenciometro que  permite ajustar  "manualmente"  el 
// volumen  general  del  Formant  V2  y  lo  actualiza  en  el
// potenciometro  digital  que  es el que controla realmente el
// volumen en el modulo COM
//
// ------------------------------------------------------------

void getPotenciomentroManual_COM(void)
{
  int  val;
  byte volumen;

  val     = analogRead(IDE_HW_VOL_COM_POT);
  volumen = (byte)map(val,0,1023,0,127);
  
  if ( volumen!=volumenManualGeneral )
     { // ---------------------------------------------------------
       // Actualiza el volumen
       // ---------------------------------------------------------
       volumenManualGeneral = volumen;
       setPotenciomentro_COM(volumen);
     }

}




// ------------------------------------------------------------
//
// void setPotenciomentro_COM(byte volumen)
//
// Ajusta el volumen general del  Formant  V2  actualizando  el 
// potenciometro digital de volumen del modulo COM.
//
// Esta funcion se puede llamar desde 2 sitios:
// A) Cada vez que se mueve el potenciometro de volumen "manual"
// B) Si se recibe un mensaje MIDI de control de volumen global
// 
// ------------------------------------------------------------

void setPotenciomentro_COM(byte volumen)
{
  byte val;
  
  // -----------------------------------------------
  //
  //         Valor a cargar en el DS1801
  //
  // El DS1801 contiene 2 potenciomentros digitales
  // de 64 pasos, con funcion "MUTE" incorporada.
  // Bit D0 ... D5 posicion del cursor del potenciomentro
  // Bit D6 Mute 0 Desactivado, 1 Activado
  // Bit D7 No utilizado
  //
  // Mapear e  valor  recibido desde el mensaje MIDI
  // al  rango 0...63 conlleva que el bit D6 (Mute)
  // se pone a 0  y  el D7  como  es  indiferente se
  // envia tambien a 0.
  // Se debe enviar el mismo valor 2 VECES (shiftOut) 
  // porque el DS1801 son  2  potenciomentros  y  en
  // este caso DEBEN tener el  mismo  valor , porque
  // sustituyen al  potenciomento  DOBLE  del modulo
  // COM del Formant  original (ver esquema original
  // del  modulo COM el Formant).
  // -----------------------------------------------
  val = (byte)map(volumen,0,127,0,63);
  
  #ifdef DEBUG_MIDI 
  Serial.print  ("Volumen: " );
  Serial.print  (volumen,DEC);
  Serial.print  (" -> " );
  Serial.println(val,DEC );
  #endif
  
  analogWrite(IDE_HW_PIN_VOLCOM_CLOCK,0);                // Señal de reloj a nivel bajo
  analogWrite(IDE_HW_PIN_VOLCOM_RESET,255);              // Señal de reloj a nivel alto
  delayMicroseconds(5);
  
  shiftOut(IDE_HW_PIN_VOLCOM_DATA,IDE_HW_PIN_VOLCOM_CLOCK, LSBFIRST, val); // Potenciometro 1
  shiftOut(IDE_HW_PIN_VOLCOM_DATA,IDE_HW_PIN_VOLCOM_CLOCK, LSBFIRST, val); // Potenciometro 0

  analogWrite(IDE_HW_PIN_VOLCOM_RESET,0);                // Señal de reloj a nivel bajo al salir debe quedar asi
  
}










