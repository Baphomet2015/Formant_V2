// ---------------------------------------------------------
//
// Proyecto:       Formant_V2
// Version:        1.0
// Fichero:        DCO_ondas.ino
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






// ------------------------------------------------------------
//
// void genOndaExponencial(void)
// 
// ------------------------------------------------------------

void genOndaExponencial(void)
{
  float        exponente = 0.0;
  unsigned int d;
  int          muestras;

     
  for(muestras=0;muestras<IDE_MAX_HW_BUFFER;muestras++)
     {
       d = (unsigned int)pow(2,exponente);
       exponente += 0.0052;
       cargarDatoBuffer(d);
       cargarDatoMemoria();            
       clkContadorADDR();            
     }
}


// ------------------------------------------------------------
//
// void genOndaSinusoidal(void)
// 
// ------------------------------------------------------------

void genOndaSinusoidal(void)
{
  float        amplitud = 0.0;
  float        angulo   = 0.0;
  unsigned int d;
  int          muestras;
     
  for(muestras=0;muestras<IDE_MAX_HW_BUFFER;muestras++)
     {
       amplitud = ((IDE_MAX_HW_DAC/2)-1) * sin(angulo) + ((IDE_MAX_HW_DAC/2)-1);
       angulo   = angulo + ((2*PI)/IDE_MAX_HW_BUFFER);
       if ( angulo>=(2*PI))
          {
            angulo = 0;
          }
       d = (unsigned int)amplitud;
      
       cargarDatoBuffer(d);
       cargarDatoMemoria();            
       clkContadorADDR();            
     }
}


// ------------------------------------------------------------
//
// void genSenoSemiCicloPositivo(void)
// 
// ------------------------------------------------------------

void genOndaSenoSemiCicloPositivo(void)
{
  float        amplitud = 0.0;
  float        angulo   = 0.0;
  unsigned int d;
  int          muestras;
     
  for(muestras=0;muestras<IDE_MAX_HW_BUFFER;muestras++)
     {
       amplitud = (IDE_MAX_HW_DAC-1) * (-1*sin(angulo)) + (IDE_MAX_HW_DAC-1);
       angulo   = angulo + (PI/IDE_MAX_HW_BUFFER);
       d        = (unsigned int)amplitud; 
      
       cargarDatoBuffer(d);
       cargarDatoMemoria();            
       clkContadorADDR();            
     }
}



// ------------------------------------------------------------
//
// void genCosenoSemiCicloPositivo(void)
// 
// ------------------------------------------------------------

void genOndaCosenoSemiCicloPositivo(void)
{
  float        amplitud = 0.0;
  float        angulo   = 0.0;
  unsigned int d;
  int          muestras;
     
  for(muestras=0;muestras<IDE_MAX_HW_BUFFER;muestras++)
     {
       amplitud = (IDE_MAX_HW_DAC/2) * cos(angulo) + (IDE_MAX_HW_DAC/2);
       angulo   = angulo + (PI/IDE_MAX_HW_BUFFER);
       d        = (unsigned int)amplitud; 
       if ( d>(IDE_MAX_HW_DAC-1) )
          {
            d = IDE_MAX_HW_DAC -1;
          } 
       cargarDatoBuffer(d);
       cargarDatoMemoria();            
       clkContadorADDR();            
     }
}



// ------------------------------------------------------------
//
// void genOndaTriangular(void)
// 
// ------------------------------------------------------------

void genOndaTriangular(void)
{
  unsigned int muestras;
  
  
  muestras = 0;
  while(true)
       {  
         cargarDatoBuffer(muestras);
         cargarDatoMemoria();            
         clkContadorADDR();          
         if ( muestras>(IDE_MAX_HW_DAC-1) ) { break;      }
         else                               { muestras++; }
       }

  muestras = (IDE_MAX_HW_DAC-1);
  while(true)
       {
        cargarDatoBuffer(muestras);
        cargarDatoMemoria();            
        clkContadorADDR();      
        if ( muestras==0 ) { break;      }
        else               { muestras--; }
      }

}



// ------------------------------------------------------------
//
// void genOndaPulso(void)
// 
// ------------------------------------------------------------

void genOndaPulso(void)
{
  unsigned int muestras;
     
  for(muestras=0;muestras<(IDE_MAX_HW_BUFFER/2)-1;muestras++)
     {
       cargarDatoBuffer(0);
       cargarDatoMemoria();            
       clkContadorADDR();            
     }

  for(muestras=IDE_MAX_HW_DAC-1;muestras>0;muestras--)
     {
       cargarDatoBuffer(muestras);
       cargarDatoMemoria();            
       clkContadorADDR();            
     }

}


// ------------------------------------------------------------
//
// void genOndaDienteSierra(void)
// 
// ------------------------------------------------------------

void genOndaDienteSierra(void)
{
  unsigned int muestras;
     
  for(muestras=(IDE_MAX_HW_BUFFER/2)-1;muestras>0;muestras--)
     {
       cargarDatoBuffer(muestras);
       cargarDatoMemoria();            
       clkContadorADDR();            
       cargarDatoBuffer(muestras);
       cargarDatoMemoria();            
       clkContadorADDR();            
     }
}



// ------------------------------------------------------------
//
// void genOndaCuadrada(void)
// 
// ------------------------------------------------------------

void genOndaCuadrada(void)
{
  unsigned int muestras;
     
  for(muestras=0;muestras<(IDE_MAX_HW_BUFFER/2)-1;muestras++)
     {
       cargarDatoBuffer(IDE_MAX_HW_DAC-1);
       cargarDatoMemoria();            
       clkContadorADDR();            
     }
     
  for(muestras=0;muestras<(IDE_MAX_HW_BUFFER/2)-1;muestras++)
     {
       cargarDatoBuffer(0);
       cargarDatoMemoria();            
       clkContadorADDR();            
     }

}
