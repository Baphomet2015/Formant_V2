
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

#define APP_MODO_DEBUG     1   // MODO DEBUG: Descomentar este define
                               // MODO REAL:  Comentar este define

#define IDE_HW_PIN_D0      0   // Pines para generar el codigo de control 
#define IDE_HW_PIN_D1      1   // del multiplexor, el que selecciona la tecla pulsada
#define IDE_HW_PIN_D2      2
#define IDE_HW_PIN_D3      3
#define IDE_HW_PIN_D4      4
#define IDE_HW_PIN_D5      5

#define IDE_HW_PIN_GATE    6    // Pin para generar la señal GATE

#define IDE_CANAL_ASIGNADO 1    // Canal por el que se comunica el MIDI














#endif



