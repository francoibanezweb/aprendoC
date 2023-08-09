/***************
| Ap.02, Ej.06 |
***************/
#include <stdio.h>
#include <stdlib.h>

void borrpant();
void codcar();
void carcod();

int main()
{ /* menú del programa de conversión ASCII */
  char menuOpc;

  menuOpc = 'x';
  while (menuOpc != '3')
  {
    borrpant();
    printf("\n\t\t\tMENU - PROGRAMA CONVERSION ASCII");
    printf("\n\n\n\n\n\n\n\n\t\t");
    printf("1 - Carácter ASCII correspondiente a un número");
    printf("\n\n\n");
    printf("\t\t2 - Código ASCII correspondiente a un carácter");
    printf("\n\n\n\t\t3 - Abandonar el programa");
    printf("\n\n\n\n\n\n\n\n\t\t¿QUÉ OPCIÓN ESCOGE? > ");
    scanf("\n%c", &menuOpc);
    if (menuOpc == '1')
    {
      codcar();
    }
    else if (menuOpc == '2')
    {
      carcod();
    }
    else if (menuOpc == '3')
    {
      borrpant();
    }
    else
    {
      printf("%c", 7);
      // printf("\a\n");
    }
    borrpant();
  }

  return 0;
}

void carcod() /* impresión del código ASCII que  */
{             /* corresponde a un carácter dado */
  char carEjemp, repetir;
  repetir = 'S';
  while (repetir == 'S' || repetir == 's')
  {
    borrpant();

    printf("\nCarácter del que desea conocer el código ASCII > ");
    scanf("\n%c", &carEjemp);
    printf("\nEl código ASCII de %c es %d", carEjemp, carEjemp);
    repetir = 'x';
    while (repetir != 'S' && repetir != 's' && repetir != 'n' && repetir != 'N')
    {
      printf("\n¿Desea repetir el proceso? (S/N) > ");
      scanf("\n%c", &repetir);
    }
  }
}

void codcar() /* impresión del carácter que */
{             /* corresponde a un código ASCII dado */
  int numEjemp;
  char repetir;

  repetir = 'S';

  while (repetir == 'S' || repetir == 's')
  {
    borrpant();
    printf("\nCódigo ASCII del que desea conocer el carácter > ");
    scanf("\n%d", &numEjemp);
    printf("\nEl carácter ASCII de %d es %c", numEjemp, numEjemp);
    repetir = 'x';
    while (repetir != 'S' && repetir != 's' && repetir != 'N' && repetir != 'n')
    {
      printf("\nDesea repetir el proceso (S/N) > ");
      scanf("\n%c", &repetir);
    }
  }
}

void borrpant()
{                       /* borra la pantalla */
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}