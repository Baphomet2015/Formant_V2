
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
  int resultado;


  resultado = MIDI_RET_NO;
 
  
  
  
  
  
  return( resultado); 
}







