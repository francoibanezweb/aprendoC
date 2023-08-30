/***************
| Ap.06, Ej.12 |
***************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void clearBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }
}

int main()
{ /* introducir palabras de vocabulario en un fichero en disco, */
  /* para su uso en el programa de preguntas de vocabulario alemán */
  /* VERSIÓN FINAL */
  FILE *puntFich;

  char Espanol[16];
  char Aleman[16];
  char elemento[2];

  char repetir[2], confirma[2];
  int contador;

  puntFich = fopen("listpala.txt", "a");
  if (puntFich == NULL)
  {
    printf("Error de Disco: no puede abrirse");
    printf("fichero de palabras");
    exit(0);
  }

  while (1 == 1)
  {
    strcpy(Espanol, "      "); /* borrrar los restos que puedan  */
    strcpy(Aleman, "      ");  /* haber en memoria */

    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\tINTRODUCCIÓN DE PALABRAS DE VOCABULARIO");
    printf("\n\t\t------------------------------------");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Escriba la palabra en español > ");
    fgets(Espanol, sizeof(Espanol), stdin);
    Espanol[strcspn(Espanol, "\n")] = '\0';
    clearBuffer();

    printf("\nEscriba la palabra en alemán > ");
    fgets(Aleman, sizeof(Aleman), stdin);
    Aleman[strcspn(Aleman, "\n")] = '\0';
    clearBuffer();

    while (1 == 1)
    {
      printf("\nEscriba el tipo de elemento gramatical que le\n"),
      printf("corresponda(N=nombre, V=verbo, O=otros) > ");
      fgets(elemento, sizeof(elemento), stdin);
      elemento[0] = toupper(elemento[0]);
      if (elemento[0] == 'N' || elemento[0] == 'V' || elemento[0] == 'O')
      {
        break;
      }
      else
      {
        putchar(7);
      }
    }
    clearBuffer();

    printf("\n¿Desea archivar en disco estos datos? (S/N) > ");
    fgets(confirma, sizeof(confirma), stdin);
    if (toupper(confirma[0]) == 'S')
    {
      contador = 0;
      while (contador < 16)
      {
        putc(Espanol[contador], puntFich);
        contador = contador + 1;
      }
      contador = 0;
      while (contador < 16)
      {
        putc(Aleman[contador], puntFich);
        contador = contador + 1;
      }
      putc(elemento[0], puntFich);
    }
    clearBuffer();

    printf("\n¿Desea introducir otra palabra? (S/N) > ");
    fgets(repetir, sizeof(repetir), stdin);
    if (toupper(repetir[0]) != 'S')
    {
      break;
    }
    clearBuffer();
  }
  fclose(puntFich);
  return 0;
}