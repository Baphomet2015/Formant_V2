
// ---------------------------------------------------------
//
// Proyecto:       Formant_V2
// Version:        1.0
// Fichero:        Formant_V2_ADSR.h
// Autor:   
// Hardware:       Arduino Nano V3.0
// Fecha:          Noviembre 2017
//
// Funcionalidad:  Fichero principal ( main ) de la aplicación
//                 de control del generador de ADSR.
//
// Notas:          REVISADO --        
//
// ---------------------------------------------------------

#ifndef FORMANT_V2_ADSR
#define FORMANT_V2_ADSR


// ---------------------------------------------------------
//                        ATENCIÓN:
// DESCOMENTAR este define para compilar trazas de depuracion
// que se envian por el pueerto serie
// ---------------------------------------------------------

//#define DEBUG_MIDI  1


// ---------------------------------------------------------
//
// Defines de la aplicacion
//
// ---------------------------------------------------------

#define IDE_HW_PIN_GATE           0   // Pin para recibir la señal de disparo (GATE)

#define IDE_HW_PIN_ADSR_1_A       0   // Pin para generar la parte ATTACK  en el ADSR 1 DIGITAL
#define IDE_HW_PIN_ADSR_1_AF      0   // Pin para detectar final de la parte ATTACK en el ADSR 1 
#define IDE_HW_PIN_ADSR_1_D       0   // Pin para generar la parte DECAY   en el ADSR 1 DIGITAL
#define IDE_HW_PIN_ADSR_1_S       0   // Pin para generar la parte SUSTAIN en el ADSR 1 ANALOG
#define IDE_HW_PIN_ADSR_1_R       0   // Pin para generar la parte RELEASE en el ADSR 1 DIGITAL

#define IDE_HW_PIN_ADSR_2_A       0   // Pin para generar la parte ATTACK  en el ADSR 1 DIGITAL
#define IDE_HW_PIN_ADSR_2_AF      0   // Pin para detectar final de la parte ATTACK en el ADSR 2 
#define IDE_HW_PIN_ADSR_2_D       0   // Pin para generar la parte DECAY   en el ADSR 1 DIGITAL
#define IDE_HW_PIN_ADSR_2_S       0   // Pin para generar la parte SUSTAIN en el ADSR 1 ANALOG
#define IDE_HW_PIN_ADSR_2_R       0   // Pin para generar la parte RELEASE en el ADSR 1 DIGITAL


#define IDE_ADSR_1                1    // Identifica el modulo ADSR 1
#define IDE_ADSR_2                2    // Identifica el modulo ADSR 2

#define IDE_GATE_ON               1    // Señal GATE activa, se esta pulsando una tecla
#define IDE_GATE_OFF              0    // Señal GATE inactiva, NO se esta pulsando una tecla

#define IDE_ADSR_OK               0    // Indica estado OK, no se esta generando nada
#define IDE_ADSR_A                1    // Indica que se esta generando la parte ATTACK  en la envolvente de salida
#define IDE_ADSR_D                2    // Indica que se esta generando la parte DECAY   en la envolvente de salida
#define IDE_ADSR_S                3    // Indica que se esta generando la parte SUSTAIN en la envolvente de salida
#define IDE_ADSR_R                4    // Indica que se esta generando la parte RELEASE en la envolvente de salida
#define IDE_ADSR_RESET            5    // Indica resetear el modulo ADSR

#define IDE_ADSR_FIN_ATTACK     800    // Valor  para detectar el fin del ciclo de ATTACK en una envolvente






#endif



