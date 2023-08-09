/***************
| Ap.02, Ej.04 |
***************/
#include <stdio.h>
#include <stdlib.h>

void borrpant();

int main()
{
  /* versión 4: impresión del código ASCII > */
  /* del carácter tecleado por el usuario */
  /* con posibilidad de repetir el proceso */

  char carEjemp, repetir;

  repetir = 'S';

  while (repetir == 'S' || repetir == 's')
  {
    borrpant();
    printf("\nCarácter del que se desea conocer el código ASCII > ");
    scanf("\n%c", &carEjemp);
    printf("\nEl código ASCII de %c es %d", carEjemp, carEjemp);
    repetir = 'x';
    while (repetir != 'S' && repetir != 's' && repetir != 'N' && repetir != 'n')
    {
      printf("\nDesea repetir el proceso (S/N) > ");
      scanf("\n%c", &repetir);
    }
  }

  borrpant();
  return 0;
}

void borrpant()
{ /* borra la pantalla */
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}