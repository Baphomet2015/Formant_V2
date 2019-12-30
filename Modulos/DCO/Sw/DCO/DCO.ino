
// ---------------------------------------------------------
//
// Proyecto:       Formant_V2
// Version:        1.0
// Fichero:        DCO.ino
// Autor:   
// Hardware:       Arduino Nano V3.0
// Fecha:          Diciembre 2019
//
// Funcionalidad:  
//                 
//
// Notas:          
//
// ---------------------------------------------------------

#include <Arduino.h>
#include <stdlib.h>
#include <SPI.h>
#include <MD_AD9833.h>



// ------------------------------------------------------------
//
//
//
//
// ------------------------------------------------------------


#define IDE_HW_PIN_LOAD_AUTO  3         // Pin para cargar datos en el buffer de memoria
#define IDE_HW_PIN_LOAD_CLK   2         // Generacion de reloj en modo load
#define IDE_HW_PIN_LOAD_RESET 4         // Reset contador de direcciones del buffer 6116 en modo load
#define IDE_HW_PIN_LOAD_WR    5         // Escritura en memoria en modo load
                                 
#define IDE_HW_PIN_SER        6         // Datos serie para cargar los HC595
#define IDE_HW_PIN_LATCH_GEN  8         // Señal para almacenar datos (latch) en los HC595 que cargan datos en la ram de generacion de onda (6116) 
#define IDE_HW_PIN_CLK        7         // Reloj para cargar los HC595 
#define IDE_HW_PIN_LATCH_LED  12        // Señal para almacenar datos (latch) en el HC595 que controla los leds de forma de onda

#define IDE_HW_POT_COARSE     A0        // Entrada del potenciometro de COARSE  
#define IDE_HW_POT_FINE       A1        // Entrada del potenciometro de FINE
#define IDE_HW_INPUT_KEYS     A2        // Lectura de pulsadores de seleccion de onda

#define IDE_HW_PIN_HC245      9         // Control del HC245
                                        // 0: A --> B
                                        // 1: B Alta Impedancia

#define IDE_HW_SPI_FSYNC      10        // SPI Load pin number (FSYNC in AD9833 usage)
#define IDE_HW_SPI_DATA       11        // SPI Data pin number
#define IDE_HW_SPI_CLK        13        // SPI Clock pin number


#define IDE_MODO_LOAD         0         // Modo Load, cargar datos en el buffer HW formado por los 6116
#define IDE_MODO_AUTO         1         // Modo de generacion de onda definida

#define IDE_DELAY_RESET_ADDR  1000      // Duracion en ms del pulso para resetear el contador de direcciones 4040
#define IDE_MAX_HW_BUFFER     2048      // Tamaño en Kbytes de la memoria utilizada para definir la onda ( Dos chips 6116 2Kx8 )
#define IDE_MAX_HW_DAC        1024      // Valor maximo de una muestra enviada al DAC ( DAC 10 Bits, 0 ... 1023)

#define IDE_FREQ_DEFECTO       901088L  // Frecuencia a cargar por defecto en el AD9833, genera la nota LA de 440Hz
#define IDE_FREQ_FINE           20480L  // Frecuencia a sumar a la nota generada, utilizando el potenciomentro de FINE (+10Hz), sobre la nota generada
#define IDE_FREQ_MAX_AD9833  12500000L  // Frecuencia maxima que puede generar el AD9833 ( 12.5MHz)


#define IDE_MAXV_POTENCIOMETROS 0x03FC  // Valor maximo leido desde los potenciomentros de COARSE y FINE
                                        // 1020, para eliminar los bits de menor peso y eliminar ruido

// ------------------------------------------------------------
//
// ------------------------------------------------------------

uint32_t tablaNotas[92] =  {      0L ,     0L ,     0L ,    0L   ,      0L , 44698L  , 47358L  , 50174L , 53164L , 56318L , 59676L ,  63219L,
                              66967L ,  70960L, 75179L , 79643L  ,  84375L , 89392L  , 94716L  ,100348L ,106309L ,112636L ,238664L , 252866L,
                             268000L , 283835L,300715L , 318572L , 337538L ,357608L  ,379000L  ,401392L ,425272L ,450544L ,477328L , 505732L,
                             536000L , 567670L,601430L , 637144L , 675076L ,715216L  ,758000L  ,802784L ,850544L ,901088L ,954656L ,1011464L,
                            1072000L ,1135340L,1202860L,1274288L ,1350152L ,1430432L ,1516000L ,1605568L,1701088L,1802176L,1909312L,2022928L,
                            2144000L ,2270680L,2405720L,2548576L ,2700304L ,2860864L ,3031000L ,3211136L,3402176L,3604352L,3818624L,4045856L,
                            4288000L ,4541360L,4811440L,5097152L ,5400608L ,5721728L ,6062000L ,6422272L,6804352L,7201000L,7637248L,8095000L,
                            8576000L ,9085000L,9626000L,10199000L,10806000L,11448000L,12129000L,1250000L
                           };
                         
uint32_t frq_Nota;     // Frecuencia cargada en el AD9833 para generar la nota recibida (algun valor de tablaNotas) 
uint32_t frq_Coarse;   // Frecuencia que se suma/resta a frq_Nota para crear el efecto de COARSE
uint32_t frq_Fine;     // Frecuencia que se suma/resta a frq_Nota para crear el efecto de FINE

int      vPotCoarse;        // Asociada a la lectura del potenciometro de COARSE
int      vPotFine;          // Asociada a la lectura del potenciometro de FINE
byte     vInterfaz;         // Valor cargado en el HC595 que controla los leds y permite leer los pulsadores  

// ------------------------------------------------------------
//
// ------------------------------------------------------------

MD_AD9833 AD_9833(IDE_HW_SPI_FSYNC); 



// ------------------------------------------------------------
//
// setup()
//
//
// ------------------------------------------------------------

void setup()
{
   pinMode(IDE_HW_PIN_LOAD_AUTO ,OUTPUT);
   pinMode(IDE_HW_PIN_LOAD_CLK  ,OUTPUT);
   pinMode(IDE_HW_PIN_LOAD_RESET,OUTPUT);
   pinMode(IDE_HW_PIN_LOAD_WR   ,OUTPUT);

   pinMode(IDE_HW_PIN_HC245     ,OUTPUT);

   pinMode(IDE_HW_PIN_SER       ,OUTPUT);
   pinMode(IDE_HW_PIN_LATCH_GEN ,OUTPUT);
   pinMode(IDE_HW_PIN_LATCH_LED ,OUTPUT);
   pinMode(IDE_HW_PIN_CLK       ,OUTPUT);

   pinMode(IDE_HW_SPI_FSYNC     ,OUTPUT);
   pinMode(IDE_HW_SPI_DATA      ,OUTPUT);
   pinMode(IDE_HW_SPI_CLK       ,OUTPUT);

   Serial.begin(9600);
   iniAD9833();

   vPotCoarse = 0;
   vPotFine   = 0;  
   vInterfaz  = 0B10000000;

   iniGenerador();
   setInterfaz();
   genOndaSinusoidal(); 
   setModoAutoLoad(IDE_MODO_AUTO); 
   
}



// ------------------------------------------------------------
//
// void loop()
//
// ------------------------------------------------------------
  
void loop()
{
  get_Coarse();            // Lee potenciometro COARSE
  get_Fine();              // Lee potenciomentro FINE
  get_Tecla_MIDI();        // Lee codigo de las teclas MIDI pulsadas, que envía el interfaz  de teclado 
//get_Pulsadores();        // Lee los pulsadores de seleccion de forma de onda 

}



// ------------------------------------------------------------
//
// void get_Coarse(void)
// 
// 
// ------------------------------------------------------------

void get_Coarse(void)
{
  int   vPot;
  float vAux;

  
  vPot = analogRead(IDE_HW_POT_COARSE) & IDE_MAXV_POTENCIOMETROS;

  if ( vPot!=vPotCoarse )
     {
       vAux       = IDE_FREQ_MAX_AD9833 - frq_Nota;
       vPotCoarse = vPot;  
       frq_Coarse = (uint32_t) map2(vPotCoarse,0,IDE_MAXV_POTENCIOMETROS,0,vAux);
       setFrqAD9833();
     }
}



// ------------------------------------------------------------
//
// void get_Fine(void)
// 
// 
// ------------------------------------------------------------

void get_Fine(void)
{
  int vPot;
  
    
  vPot = analogRead(IDE_HW_POT_FINE) & IDE_MAXV_POTENCIOMETROS;
  
  if ( vPot!=vPotFine )
     {
       vPotFine = vPot; 
       frq_Fine = (uint32_t)map2(vPotFine,0,IDE_MAXV_POTENCIOMETROS,0,IDE_FREQ_FINE);
       setFrqAD9833(); 
     }
}



// ------------------------------------------------------------
//
// void get_Tecla_MIDI(void)
// 
// 
// ------------------------------------------------------------

void get_Tecla_MIDI(void)
{

  if ( Serial.available() )
     {
       //   frq_Nota = Serial.parseFloat();
       //   AD_9833.setFrequency(MD_AD9833::CHAN_0, frq_Nota); 
       //   Serial.print(frq_Nota,DEC);
       //   Serial.println(" OK");
     }
}



// ------------------------------------------------------------
//
// void get_Pulsadores(void)
// 
// 
// ------------------------------------------------------------

void get_Pulsadores(void)
{
  int v;
  
  
  v = analogRead(IDE_HW_INPUT_KEYS);
  v = map(v,0,1023,0,1);
  Serial.println(v);
  
}



// ------------------------------------------------------------
// void setInterfaz(void)
// Carga el valor de vInterfaz en el HC595 que controla los led
// y  el  direccionamiento  del  4051  con  el  que se leen los
// pulsadores 
// ------------------------------------------------------------

void setInterfaz(void)
{
  shiftOut(IDE_HW_PIN_SER, IDE_HW_PIN_CLK, MSBFIRST,vInterfaz); // Carga el dato
  digitalWrite(IDE_HW_PIN_LATCH_LED,HIGH);                      // pulso de Latch
  digitalWrite(IDE_HW_PIN_LATCH_LED,LOW);  
}



// ------------------------------------------------------------
//
// void iniGenerador()
// Instrucciones en ese orden
// 
// ------------------------------------------------------------

void iniGenerador(void)
{
  
  setModoAutoLoad(IDE_MODO_LOAD);
  
  digitalWrite(IDE_HW_PIN_LOAD_CLK,HIGH);
  digitalWrite(IDE_HW_PIN_LOAD_WR ,HIGH);
  
  resetContadorADDR();  
  
}



// ------------------------------------------------------------
//
// setModoAutoLoad(byte modo)
// modo: IDE_MODO_LOAD Cargar datos en el buffer 6116
//       IDE_MODO_AUTO Generacion de onda 
// ------------------------------------------------------------

void setModoAutoLoad(byte modo)
{
  if ( modo==IDE_MODO_LOAD )
     { digitalWrite(IDE_HW_PIN_LOAD_AUTO ,HIGH);
       digitalWrite(IDE_HW_PIN_HC245     ,HIGH);
     }
  else
     { digitalWrite(IDE_HW_PIN_LOAD_AUTO ,LOW);
       digitalWrite(IDE_HW_PIN_HC245     ,LOW);
     }
}



// ------------------------------------------------------------
//
// resetContadorADDR(void)  
// Resetea el contador de direcciones (4040) que direcciona el
// buffer de memoria formado por los 6116
// PREVIAMENTE tiene que estar seleccionado el modo IDE_MODO_LOAD
// sino no se resetea el 4040
// ------------------------------------------------------------

void resetContadorADDR(void)
{
  digitalWrite(IDE_HW_PIN_LOAD_RESET ,HIGH);
  delayMicroseconds(IDE_DELAY_RESET_ADDR);
  digitalWrite(IDE_HW_PIN_LOAD_RESET ,LOW);
}



// ------------------------------------------------------------
//
// clkContadorADDR(void)
// Genera un pulso de reloj en el contador de direcciones 4040
// para que avance uno la direccion
// PREVIAMENTE tiene que estar seleccionado el modo IDE_MODO_LOAD
// sino no se resetea el 4040
// ------------------------------------------------------------

void clkContadorADDR(void)
{
  digitalWrite(IDE_HW_PIN_LOAD_CLK,LOW);
  digitalWrite(IDE_HW_PIN_LOAD_CLK,HIGH);
}



// ------------------------------------------------------------
//
// cargarDatoMemoria(void)
// Genera el pulso de escritura en las memorias 6116 que almacena 
// el valor que tenga en ese momento el registro formado por los
// HC595.
// Lo almacena el la direccion de memoria apuntada en las salidas
// del 4040
// ------------------------------------------------------------

void cargarDatoMemoria(void)
{
  digitalWrite(IDE_HW_PIN_LOAD_WR ,LOW);
  digitalWrite(IDE_HW_PIN_LOAD_WR ,HIGH);
}



// ------------------------------------------------------------
//
// void cargarDatoBuffer(unsigned int data)
// Carga el valor que recibe en el registro formado por los dos
// HC595
// ------------------------------------------------------------

void cargarDatoBuffer(unsigned int data)
{
  byte pH;
  byte pL;
  
  pH = (data >> 8 & 0x00FF) | 0B00000100;
  pL = data      & 0x00FF;
  shiftOut(IDE_HW_PIN_SER, IDE_HW_PIN_CLK, MSBFIRST,pH ); // Parte Alta
  shiftOut(IDE_HW_PIN_SER, IDE_HW_PIN_CLK, MSBFIRST,pL);  // Parte Baja
  digitalWrite(IDE_HW_PIN_LATCH_GEN,HIGH);                     // pulso de Latch
  digitalWrite(IDE_HW_PIN_LATCH_GEN,LOW);  
  
}



// ------------------------------------------------------------
//
// void iniAD9833(void)
// 
// ------------------------------------------------------------

void iniAD9833(void)
{
 
  frq_Nota   = IDE_FREQ_DEFECTO; 
  frq_Coarse = 0L;
  frq_Fine   = 0L;
  
  AD_9833.begin();
  AD_9833.setMode(MD_AD9833::MODE_SQUARE1);
  setFrqAD9833();
}



// ------------------------------------------------------------
//
// void setFrqAD9833(void)
// 
// ------------------------------------------------------------

void setFrqAD9833(void)
{
  uint32_t frecuencia;
  
  frecuencia = frq_Nota + frq_Coarse + frq_Fine;

  if ( frecuencia<=IDE_FREQ_MAX_AD9833 )
     { // ---------------------------------------------------
       // Frecuencia valida
       // ---------------------------------------------------
       AD_9833.setFrequency      (MD_AD9833::CHAN_0, frecuencia);
       AD_9833.setActiveFrequency(MD_AD9833::CHAN_0);
     }
}



// ------------------------------------------------------------
//
// float map2( float x       , 
//             float in_min  ,
//             float in_max  ,
//             float out_min ,
//             float out_max
//           )
// Version de la funcion map de Arduino pero con floats
// ------------------------------------------------------------

float map2(float x, float in_min, float in_max, float out_min, float out_max)
{
  float a;
  float b;
  
  a = (x - in_min) * (out_max - out_min);
  b = (in_max - in_min) + out_min;
  
  return (float)a/b;
}


