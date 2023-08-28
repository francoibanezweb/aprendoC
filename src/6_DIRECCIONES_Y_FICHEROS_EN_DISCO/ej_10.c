/***************
| Ap.06, Ej.10 |
***************/
#include <stdio.h>
#include <stdlib.h>

#define MAXPALAB 100

struct LisPalEA
{
  char Espanol[16];
  char Aleman[16];
  char elemento;
} palabra[MAXPALAB];

int main()
{

  FILE *puntFich;
  char letra;
  int contaPal, contLetA, contLetE, contaPos, contaPru;

  if ((puntFich = fopen("listpala.txt", "r")) == NULL)
  {
    printf("Error de Disco: no puede abrirse fichero de palabras");
    exit(0);
  }
  contaPal = 0;
  contLetA = 0;
  contLetE = 0;
  contaPos = 0;

  while (letra != EOF)
  {
    letra = getc(puntFich);
    if (contLetE < 16)
    {
      palabra[contaPal].Espanol[contLetE] = letra;
      contLetE = contLetE + 1;
    }
    else if (contLetE < 16)
    {
      palabra[contaPal].Aleman[contLetA] = letra;
      contLetA = contLetA + 1;
    }
    else if (contaPos < 1)
    {
      palabra[contaPal].elemento = letra;
      contaPos = contaPos + 1;
    }
    if (contLetE == 16 && contLetA == 16 && contaPos == 1)
    {
      contaPal = contaPal + 1;
      contLetE = 0;
      contLetA = 0;
      contaPos = 0;
      if (contaPal > MAXPALAB)
      {
        printf("\nERROR: lista de palabras, demasiado larga.");
        printf("\n\tEl programa sólo utilizará, %d palabras.", MAXPALAB);
        printf("\n\tSi desea utilizar todas, las palabras");
        printf("\n\tmodificar previamente, el programa.");
        break;
      }
    }
  }
  fclose(puntFich);
  contaPru = 0;
  while (contaPru < contaPal)
  {
    printf("\n\n%s", palabra[contaPru].Espanol);
    printf("\n%s", palabra[contaPru].Aleman);
    printf("\n%c", palabra[contaPru].elemento);
    contaPru = contaPru + 1;
  }

  return 0;
}