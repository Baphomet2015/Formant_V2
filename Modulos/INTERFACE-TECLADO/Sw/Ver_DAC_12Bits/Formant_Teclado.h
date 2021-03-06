
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
//                 del interfaz MIDI de teclado.
//
// Notas:          REVISADO --        
//
// ---------------------------------------------------------

#ifndef FORMANT_V2_TECLADO
#define FORMANT_V2_TECLADO


// ---------------------------------------------------------
//                        ATENCIÓN:
// DESCOMENTAR este define para compilar trazas de depuracion
// que se envian por el pueerto serie
// ---------------------------------------------------------

#define DEBUG_MIDI  1


// ---------------------------------------------------------
//
// Defines de la aplicacion
//
// ---------------------------------------------------------

#define IDE_HW_PIN_CLOCK          5   // Pin para generar el codigo de control del teclado ( CLOCK )
#define IDE_HW_PIN_DATA           4   // Pin para generar el codigo de control del teclado ( DATA  )
#define IDE_HW_PIN_LATCH_L        6   // Pin para generar el codigo de control del teclado ( LATCH ), parte L
#define IDE_HW_PIN_LATCH_H       12   // Pin para generar el codigo de control del teclado ( LATCH ), parte H

#define IDE_HW_PIN_GATE           2   // Pin para generar la señal GATE

#define IDE_HW_PIN_LED_TECLA_ON   3   // Pin para indicar "tecla pulsada"

#define IDE_HW_CANAL_ID_0         7   // Pines para asignar mediante switches el
#define IDE_HW_CANAL_ID_1         8   // canal por el que se reciben los mensajes
#define IDE_HW_CANAL_ID_2         9
#define IDE_HW_CANAL_ID_3        10

#define IDE_HW_PIN_TEST          11   // Pulsador para entrar en el modo TEST

#define IDE_HW_VOL_COM_POT       A0   // Pin para leer el potenciometro de volumen del modulo COM,en
                                      // modo manual

#define IDE_HW_PIN_VOLCOM_DATA   A1   // Pines para controlar el potenciometro digital de volumen del 
#define IDE_HW_PIN_VOLCOM_RESET  A2   // modulo COM, no quedan digitales libres asi que se usan estos...
#define IDE_HW_PIN_VOLCOM_CLOCK  A3

#define IDE_STR_VERSION          "Formant V2 Controlador MIDI V1.0, modo TEST"
#define IDE_STR_MSG_01           "Esperando mensajes MIDI..."
#define IDE_STR_MSG_02           "Mensaje ERROR..."
#define IDE_STR_MSG_03           "Canal MIDI asignado: "
#define IDE_STR_MSG_04           "La senal GATE y el LED de Tecla Pulsada se estan generando automaticamente..."

#define IDE_PAUSA_TEST           500  // Pausa en modo TEST, 500 milisegundos para generar las señales de 
                                      // GATE y LED de tecla pulsada
#define IDE_PAUSA_GATE          1000  // Pausa utilizada en la generacion de la señal GATE (1ms), ver funciones tecla_ON y tecla_OFF
                                      
#define IDE_MIN_TECLA_ID         0    // Codigo MIDI de la tecla mas baja que se reconoce
#define IDE_MAX_TECLA_ID         48   // Codigo MIDI de la tecla mas alta que se reconoce
                                      // IMPORTANTE:
                                      // El codigo MIDI de la tecla MAS ALTA que se puede manejar se utiliza tambien
                                      // para dimensionar la tabla de estado de las teclas (variable global tab_TeclasEstado)
                                      // NO CAMBIAR este valor !!! corresponde a 4 octavas, que es el rango mas alto que
                                      // se puede obtener utilizando un conversor D/A de 12 Bits como el utilizado
                                      
#define IDE_TECLA_ESTADO_ON      1    // Indica que la tecla correspondiente esta pulsada (ON)
#define IDE_TECLA_ESTADO_OFF     0    // Indica que la tecla correspondiente esta sin pulsar (OFF)




#endif



