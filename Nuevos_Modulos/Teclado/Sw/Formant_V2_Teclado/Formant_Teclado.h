
// ---------------------------------------------------------
//
// Proyecto:       Formant_V2
// Version:        1.0
// Fichero:        Formant_V2_Teclado.h
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

#ifndef FORMANT_V2_TECLADO
#define FORMANT_V2_TECLADO


// ---------------------------------------------------------
//
// DESCOMENTAR este define para compilar trazas de depuracion
//
// ---------------------------------------------------------

#define IDE_HW_PIN_CLOCK          5   // Pin para generar el codigo de control ( CLOCK )
#define IDE_HW_PIN_DATA           4   // Pin para generar el codigo de control ( DATA  )
#define IDE_HW_PIN_LATCH          6   // Pin para generar el codigo de control ( LATCH )

#define IDE_HW_PIN_GATE           2   // Pin para generar la señal GATE

#define IDE_HW_PIN_LED_TECLA_ON   3   // Pin para indicar "tecla pulsada"

#define IDE_HW_CANAL_ID_0         7   // Pines para asignar el canal por el que se reciben los mensajes
#define IDE_HW_CANAL_ID_1         8
#define IDE_HW_CANAL_ID_2         9
#define IDE_HW_CANAL_ID_3        10

#define IDE_HW_PIN_TEST          11   // Pulsador para entrar en el modo TEST



#define IDE_STR_VERSION          "Formant V2 Controlador MIDI V1.0, modo TEST"
#define IDE_STR_MSG_01           "Esperando mensajes MIDI..."
#define IDE_STR_MSG_02           "Mensaje ERROR..."
#define IDE_STR_MSG_03           "Canal MIDI asignado: "
#define IDE_STR_MSG_04           "La senal GATE y el LED de Tecla Pulsada se estan generando automaticamente..."



#define IDE_PAUSA_TEST          1000 // Pausa en modo TEST, 1 segundo

#endif



