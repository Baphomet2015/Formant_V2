
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

#define IDE_HW_PIN_CLOCK          0   // Pin para generar el codigo de control ( CLOCK )
#define IDE_HW_PIN_DATA           1   // Pin para generar el codigo de control ( DATA  )
#define IDE_HW_PIN_LATCH          2   // Pin para generar el codigo de control ( LATCH )

#define IDE_HW_PIN_GATE           6   // Pin para generar la señal GATE

#define IDE_HW_PIN_LED_TECLA_ON   7   // Pin para indicar "tecla pulsada"

#define IE_HW_CANAL_00            0
#define IE_HW_CANAL_01            0
#define IE_HW_CANAL_02            0
#define IE_HW_CANAL_03            0








#endif



