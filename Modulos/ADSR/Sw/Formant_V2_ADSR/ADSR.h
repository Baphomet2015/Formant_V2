
// ---------------------------------------------------------
//
// Proyecto:       Formant_V2
// Version:        1.0
// Fichero:        ADSR.h
// Autor:   
// Hardware:       Arduino Nano V3.0
// Fecha:          Noviembre 2017
//
// Funcionalidad:  Definicion de la clase ADSR
//
// Notas:          REVISADO --        
//
// ---------------------------------------------------------

#ifndef ADSR_CLASS
#define ADSR_CLASS


// ---------------------------------------------------------
//
//
//
// ---------------------------------------------------------

#define IDE_ADSR_OK               0    // Indica estado OK, no se esta generando nada
#define IDE_ADSR_A                1    // Indica que se esta generando la parte ATTACK  en la envolvente de salida
#define IDE_ADSR_D                2    // Indica que se esta generando la parte DECAY   en la envolvente de salida
#define IDE_ADSR_S                3    // Indica que se esta generando la parte SUSTAIN en la envolvente de salida
#define IDE_ADSR_R                4    // Indica que se esta generando la parte RELEASE en la envolvente de salida

#define IDE_ADSR_FIN_ATTACK     950    // Valor  para detectar el fin del ciclo de ATTACK en una envolvente
#define IDE_AD_FIN_DECAY         50    // Valor  para detectar el fin del ciclo de DECAY  en el modo AD

#define IDE_MODO_ADSR            LOW   // Seleccionado modo ADSR, coincide con el nivel leido en el pin de entrada correspondiente   
#define IDE_MODO_AD              HIGH  // Seleccionado modo AD,   coincide con el nivel leido en el pin de entrada correspondiente


// ---------------------------------------------------------
// Clase de manejo de ADSR
// ANTES de uilizar la clase se DEBE llamara a la funcion
// begin()
// ---------------------------------------------------------

class ARDUINO_ADSR
{
 
 public: 
   
   ARDUINO_ADSR() {}

   void begin       (byte p_adsr_A,byte p_adsr_D,byte p_adsr_S,byte p_adsr_R,byte p_adsr_OUT,byte p_modo);
   void generar     (byte estado_GATE);
   void inicializar (void);
   
   
 private:

   byte flg_Sustain;         // Periodo SUSTAIN habilitado/No habilitado 
   byte flg_Estado;          // Estado del modulo ADSR 
                             // Valores:
                             // . IDE_ADSR_OK
                             // . IDE_ADSR_A
                             // . IDE_ADSR_D                                                     
                             // . IDE_ADSR_S
                             // . IDE_ADSR_R
  byte flg_GATE;
  
  byte flg_Inicio;           // True Se ha iniciado la generacion de ADSR, False NO se ha iniciado
  
  int  vOut;                 // Tension medida en la Salida del ADSR 
  int  vSustain;             // Tension medida en el potenciometro de SUSTAIN
  byte modo;                 // Modo de funcionamiento
  
  byte adsr_A;               // Pin para generar la parte ATTACK  
  byte adsr_D;               // Pin para generar la parte DECAY   
  byte adsr_S;               // Pin para generar la parte SUSTAIN 
  byte adsr_R;               // Pin para generar la parte RELEASE 
  byte adsr_OUT;             // Pin para leer la tension de salida del ADSR
  byte adsr_modo;            // Pin para leer el modo de funcionanmiento IDE_MODO_AD , IDE_MODO_ADSR
  
  byte get_Modo(void);
  
  void gen_Envolvente(void);
  
  void genera_ATTACK  (void);
  void genera_DECAY   (void);
  void genera_SUSTAIN (void);
  void genera_RELEASE (void);
  
};



#endif




