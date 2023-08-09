/***************
| Ap.02, Ej.05 |
***************/
#include <stdio.h>
#include <stdlib.h>

void borrpant();
void codcar();
void carcod();

int main()
{ /* menú del programa de conversión ASCII */
  char menuOpc;

  borrpant();
  printf("MENU - PROGRAMA CONVERSIÓN ASCII");
  printf("\n-------------------------------");
  printf("\n\n\n1 - Carácter ASCII correspondiente a un código");
  printf("\n\n2 - Código ASCII correspondiente a un carácter");
  printf("\n\n3 - Abandonar el programa");

  menuOpc = ' ';

  while (menuOpc != '1' && menuOpc != '2' && menuOpc != '3')
  {
    printf("\n\n\n¿QUÉ OPCIÓN ESCOGE? > ");
    scanf("\n%c", &menuOpc);
  }

  if (menuOpc == '1')
  {
    codcar();
  }

  if (menuOpc == '2')
  {
    carcod();
  }

  borrpant();
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
{ /* borra la pantalla */
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}