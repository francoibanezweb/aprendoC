/***************
| Ap.06, Ej.11 |
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
  /* leer lista de palabras método de bajo nivel */

  FILE *puntFich;

  char letra;
  char *actual;
  int contaLet = 0;
  int contaPru = 0;

  if ((puntFich = fopen("listpala.txt", "x")) == NULL)
  {
    printf("Error de Disco: no puede abrirse ");
    printf("fichero de palabras");
    exit(0);
  }

  actual = &(palabra[0].Espanol[0]);

  while (letra != EOF)
  {
    letra = getc(puntFich);
    *actual = letra;
    actual = actual + 1;
    contaLet = contaLet + 1;

    if (contaLet / 33 > MAXPALAB)
    {
      printf("\nERROR: lista de palabras, demasiado larga.");
      printf("\n\tEl programa sólo utilizará, %d palabras.", MAXPALAB);
      printf("\n\tSi desea utilizar todas las palabras");
      printf("\n\tpreviamente el programa.");
      break;
    }
  }

  fclose(puntFich);
  while (contaPru < (contaLet / 33))
  {
    printf("\n\n%s", palabra[contaPru].Espanol);
    printf("\n%s", palabra[contaPru].Aleman);
    printf("\n%c", palabra[contaPru].elemento);
    contaPru = contaPru + 1;
  }

  return 0;
}