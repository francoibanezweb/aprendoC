/***************
| Ap.02, Ej.01 |
***************/
#include <stdio.h>

int main()
{ /* Impresión del código ASCII del */
  /* carácter tecleado por el usuario */
  /* con posibilidad de repetir el proceso */

  char carEjemp, repetir;
  repetir = 'R';
  while (repetir == 'R')
  {
    printf("\nCarácter del que desea conocer el código ASCII > ");
    scanf("\n%c", &carEjemp);
    printf("El código ASCII de %c es %d", carEjemp, carEjemp);

    printf("\n\nPulse la tecla R para repetir el proceso,");
    printf("\nu otra tecla cualquiera para abandonar el programa ");
    scanf("\n%c", &repetir);
  }

  return 0;
}