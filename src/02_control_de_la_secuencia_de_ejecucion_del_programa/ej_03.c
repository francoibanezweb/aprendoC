/***************
| Ap.02, Ej.03 |
***************/
#include <stdio.h>

int main()
{
  /* versión 3: impresión del código ASCII */
  /* del carácter tecleado por el usuario */
  /* con posibilidad de repetir el proceso */

  char carEjemp, repetir;
  repetir = 'S';
  while (repetir == 'S' || repetir == 's')
  {
    printf("\nCarácter del que desea conocer el código ASCII > ");
    scanf("\n%c", &carEjemp);
    printf("El código ASCII de %c es %d", carEjemp, carEjemp);
    repetir = 'x';
    while (repetir != 'S' && repetir != 's' && repetir != 'N' && repetir != 'n')
    {
      printf("\nDesea repetir el proceso (S/N) > ");
      scanf("\n%c", &repetir);
    }
  }

  return 0;
}