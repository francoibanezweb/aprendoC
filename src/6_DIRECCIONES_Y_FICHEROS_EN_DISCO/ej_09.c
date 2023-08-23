/***************
| Ap.06, Ej.09 |
***************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

int main()
{
  setlocale(LC_ALL, "en_US.UTF-8");

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
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\tINTRODUCCIÓN DE PALABRAS DE VOCABULARIO");
    printf("\n\t\t-------------------------------------");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("Escriba la palabra en español > ");
    fgets(Espanol, sizeof(Espanol), stdin);
    Espanol[strcspn(Espanol, "\n")] = '\0';

    printf("\nEscriba la palabra en alemán > ");
    fgets(Aleman, sizeof(Aleman), stdin);
    Aleman[strcspn(Aleman, "\n")] = '\0';

    while (1 == 1)
    {
      printf("\nEscriba el tipo de elemento gramatical que le\n");
      printf("corresponde (N=nombre, V=verbo, O=otros) > ");
      fgets(elemento, sizeof(elemento), stdin);
      elemento[strcspn(elemento, "\n")] = '\0';
      if (elemento[0] == 'N' || elemento[0] == 'V' || elemento[0] == 'O')
      {
        break;
      }
      else
      {
        putchar(7);
      }
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
      ;

    printf("\n¿Desea archivar en disco estos datos? (S/N) > ");
    int confirmaChar = getchar();
    while (getchar() != '\n')
      ;
    if (toupper(confirmaChar) == 'S')
    {
      contador = 0;
      while (contador < 16 && Espanol[contador] != '\0')
      {
        putc(Espanol[contador], puntFich);
        contador = contador + 1;
      }
      contador = 0;
      while (contador < 16 && Aleman[contador] != '\0')
      {
        putc(Aleman[contador], puntFich);
        contador = contador + 1;
      }
      putc(elemento[0], puntFich);
    }
    printf("\n¿Desea introducir otra palabra? (S/N) > ");
    fgets(repetir, sizeof(repetir), stdin);
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    if (toupper(repetir[0]) != 'S' && (repetir[1] == '\n' ||
                                       repetir[1] == '\0'))
    {
      break;
    }
  }
  
  fclose(puntFich);
  return 0;
}
