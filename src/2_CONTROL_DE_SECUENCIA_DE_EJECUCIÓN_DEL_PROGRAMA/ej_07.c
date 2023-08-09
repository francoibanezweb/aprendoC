/***************
| Ap.02, Ej.06 |
***************/
#include <stdio.h>    /* Se puede utilizar en lugar del módulo codcar() del */
#include <stdlib.h>   /* ej. 6 */

void borrpant();

int main()
{
  int numEjemp;
  char repetir;

  repetir = 'S';
  while (repetir == 'S' || repetir == 's')
  {
    borrpant();
    printf("\nCódigo ASCII del que que desea conocer el carácter > ");
    scanf("\n%d", &numEjemp);
    if (numEjemp < 33 || numEjemp > 254)
    {
      printf("\nEl código debe ser mayor de 33 y menor de 254");
    }
    else
    {
      printf("\nEl carácter ASCII de %d es %c", numEjemp, numEjemp);
    }
    repetir = 'x';
    while (repetir != 'S' && repetir != 's' && repetir != 'N' && repetir != 'n')
    {
      printf("\nDesea repetir el proceso (S/N) > ");
      scanf("\n%c", &repetir);
    }
  }

  return 0;
}

void borrpant()
{                       /* borra la pantalla */
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}