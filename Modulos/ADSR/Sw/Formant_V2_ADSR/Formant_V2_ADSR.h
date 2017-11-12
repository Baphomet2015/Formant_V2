
// ---------------------------------------------------------
//
// Proyecto:       Formant_V2
// Version:        1.0
// Fichero:        Formant_V2_ADSR.h
// Autor:   
// Hardware:       Arduino Nano V3.0
// Fecha:          Noviembre 2017
//
// Funcionalidad:  Fichero principal ( main ) de la aplicaciÃ³n
//                 de control del generador de ADSR.
//
// Notas:          REVISADO --        
//
// ---------------------------------------------------------

#ifndef FORMANT_V2_ADSR
#define FORMANT_V2_ADSR


// ---------------------------------------------------------
//                        ATENCION:
// DESCOMENTAR este define para compilar trazas de depuracion
// que se envian por el pueerto serie
// ---------------------------------------------------------

#define DEBUG_MIDI  1


// ---------------------------------------------------------
//
// Defines de la aplicacion
//
// ---------------------------------------------------------

#define IDE_HW_PIN_GATE          12   // Pin para recibir la seÃ±al de disparo (GATE)

#define IDE_HW_PIN_ADSR_1_A       2   // Pin para generar la parte ATTACK  en el ADSR 1 DIGITAL
#define IDE_HW_PIN_ADSR_1_AF     A0   // Pin para detectar final de la parte ATTACK en el ADSR 1 
#define IDE_HW_PIN_ADSR_1_D       3   // Pin para generar la parte DECAY   en el ADSR 1 DIGITAL
#define IDE_HW_PIN_ADSR_1_S      A1   // Pin para generar la parte SUSTAIN en el ADSR 1 ANALOG
#define IDE_HW_PIN_ADSR_1_R       4   // Pin para generar la parte RELEASE en el ADSR 1 DIGITAL

#define IDE_HW_PIN_ADSR_2_A       5   // Pin para generar la parte ATTACK  en el ADSR 1 DIGITAL
#define IDE_HW_PIN_ADSR_2_AF     A2   // Pin para detectar final de la parte ATTACK en el ADSR 2 
#define IDE_HW_PIN_ADSR_2_D       6   // Pin para generar la parte DECAY   en el ADSR 1 DIGITAL
#define IDE_HW_PIN_ADSR_2_S      A3   // Pin para generar la parte SUSTAIN en el ADSR 1 ANALOG
#define IDE_HW_PIN_ADSR_2_R       7   // Pin para generar la parte RELEASE en el ADSR 1 DIGITAL

#define IDE_GATE_ON               1    // SeÃ±al GATE activa, se esta pulsando una tecla
#define IDE_GATE_OFF              0    // SeÃ±al GATE inactiva, NO se esta pulsando una tecla

#define IDE_ADSR_OK               0    // Indica estado OK, no se esta generando nada
#define IDE_ADSR_A                1    // Indica que se esta generando la parte ATTACK  en la envolvente de salida
#define IDE_ADSR_D                2    // Indica que se esta generando la parte DECAY   en la envolvente de salida
#define IDE_ADSR_S                3    // Indica que se esta generando la parte SUSTAIN en la envolvente de salida
#define IDE_ADSR_R                4    // Indica que se esta generando la parte RELEASE en la envolvente de salida
#define IDE_ADSR_RESET            5    // Indica resetear el modulo ADSR

#define IDE_ADSR_FIN_ATTACK     815    // Valor  para detectar el fin del ciclo de ATTACK en una envolvente






#endif




