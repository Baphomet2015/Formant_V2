
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

#define APP_MODO_DEBUG            1   // MODO DEBUG: Descomentar este define
                                      // MODO REAL:  Comentar este define

#define IDE_HW_PIN_CLOCK          5   // Pin para generar el codigo de control ( CLOCK )
#define IDE_HW_PIN_DATA           4   // Pin para generar el codigo de control ( DATA  )
#define IDE_HW_PIN_LATCH          6   // Pin para generar el codigo de control ( LATCH )

#define IDE_HW_PIN_GATE           2   // Pin para generar la señal GATE

#define IDE_HW_PIN_LED_TECLA_ON   3   // Pin para indicar "tecla pulsada"

#define IDE_HW_CANAL_ID_0         7   // Pines para asignar el canal por el que se reciben los mensajes
#define IDE_HW_CANAL_ID_1         8
#define IDE_HW_CANAL_ID_2         9
#define IDE_HW_CANAL_ID_3        10





#endif



