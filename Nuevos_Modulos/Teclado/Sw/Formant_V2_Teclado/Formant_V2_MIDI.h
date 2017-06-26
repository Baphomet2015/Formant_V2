
// ---------------------------------------------------------
//
// Proyecto:       Formant_V2
// Version:        1.0
// Fichero:        Formant_V2_MIDI.h
// Autor:   
// Fecha:          Junio 2017
//
// Funcionalidad:  Fichero cabecera ( include ) principal de
//                 definiciones MIDI
//
// Notas:          REVISADO --        
//
// ---------------------------------------------------------

#ifndef FORMANT_V2_MIDI
#define FORMANT_V2_MIDI

                                             
// ---------------------------------------------------------
//
// Definiciones  relacionadas   con   la  identificacion  de
// comandos MIDI
//
// ---------------------------------------------------------


// ---------------------------------------------------------
// TIPOS de mensajes de CANAL
// ---------------------------------------------------------

#define MIDI_MSG_C_NOTE_OFF         0x80  
#define MIDI_MSG_C_NOTE_ON          0x90  
#define MIDI_MSG_C_POLY_AFTER       0xA0
#define MIDI_MSG_C_CTRL_CHG         0xB0
#define MIDI_MSG_C_PROG_CHG         0xC0
#define MIDI_MSG_C_CHANNEL_AFTER    0xD0
#define MIDI_MSG_C_PITCH_WHEEL      0xE0

// ---------------------------------------------------------
// TIPOS de mensajes de SISTEMA
// ---------------------------------------------------------

#define MIDI_MSG_S_SYS_EXCLUSIVE    0xF0
#define MIDI_MSG_S_FIN_SISEX        0xF7

#define MIDI_MSG_S_SONG_POSITION    0xF2
#define MIDI_MSG_S_SONG_SELECT      0xF3
#define MIDI_MSG_S_TUNE_REQUEST     0xF6

#define MIDI_MSG_S_QUARTER_FRAME    0xF1

#define MIDI_MSG_S_TIMING_CLOCK     0xF8
#define MIDI_MSG_S_START            0xFA
#define MIDI_MSG_S_CONTINUE         0xFB
#define MIDI_MSG_S_STOP             0xFC
#define MIDI_MSG_S_ACTIVE_SENSING   0xFD
#define MIDI_MSG_S_RESET            0xFF

#define MIDI_VEL_TRX                31250  // Velocidad para comunicar con MIDI

#define MIDI_RET_OK                 1
#define MIDI_RET_NO                 2
#define MIDI_RET_ER                 3

#define IDE_PAUSA_CAR_RX            1000  // Pausa en microsegundos para lectura de caracteres en recepcion

// ---------------------------------------------------------
// Estructura para manejar mensajes MIDI
// ---------------------------------------------------------

struct t_msg_MIDI
{
  byte type;
  byte channel;
  byte data_01;
  byte data_02;

};

typedef struct t_msg_MIDI TYPE_MSG_MIDI;


// ---------------------------------------------------------
// Clase de manejo de MIDI
// ---------------------------------------------------------

class ARDUINO_MIDI
{
 
 public: 
   
   ARDUINO_MIDI();
   
   int  get_msg_MIDI (void);
   byte get_Channel  (void)      { return(msg_MIDI.channel); }
   byte get_Type     (void)      { return(msg_MIDI.type);    }
   byte get_Data_01  (void)      { return(msg_MIDI.data_01); }
   byte get_Data_02  (void)      { return(msg_MIDI.data_02); } 
   
   
 private:
  
   TYPE_MSG_MIDI msg_MIDI;





 
};





#endif



