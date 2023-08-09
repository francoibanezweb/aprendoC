/***************
| Ap.03, Ej.08 |
***************/
/* PROGRAMA DE PROBLEMAS ARITMÉTICOS */
#include <stdio.h>

int numero[10]; /* tabla de números utilizados en todos los módulos */

void iniciali();
void probsuma();
void probrest();
void probmult();
void probdivi();

int main()
{
  char menOpc;
  iniciali(); /* inicializar tabla de números */
  while (1 == 1)
  {
    printf("\n\n\n\t\tPROBLEMAS MATEMÁTICOS");
    printf("\n\n\n\n\n");
    printf("\t\t1 - Problema de suma\n\n");
    printf("\t\t2 - Problema de resta\n\n");
    printf("\t\t3 - Problema de multiplicación\n\n");
    printf("\t\t4 - Problema de división\n\n");
    printf("\t\t5 - Abandonar el programa\n\n");
    printf("\n\n\n\n\n\n\t\tQUE OPCION ESCOGE > ");
    scanf("\n%c", &menOpc);

    if (menOpc == '1')
    {
      probsuma();
    }
    if (menOpc == '2')
    {
      probrest();
    }
    if (menOpc == '3')
    {
      probmult();
    }
    if (menOpc == '4')
    {
      probdivi();
    }
    if (menOpc == '5')
    {
      break;
    }
    else
    {
      printf("%c", 7);
    }
  }

  return 0;
}

void iniciali()
{
  numero[0] = 3;
  numero[1] = 5;
  numero[2] = 0;
  numero[3] = 9;
  numero[4] = 6;
  numero[5] = 1;
  numero[6] = 7;
  numero[7] = 8;
  numero[8] = 4;
  numero[9] = 2;
}

void probsuma() /* problemas de suma */
{
  int contadA, contadB, diferen, respuest;
  char repetir;

  contadA = 0;
  diferen = 1;
  contadB = contadA + diferen;

  while (1 == 1)
  {
    printf("\n\n\n\n\n\n");
    printf("\t\t\tPROBLEMAS DE SUMA");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t%d + %d = ", numero[contadA], numero[contadB]);
    scanf("%d", &respuest);
    if (respuest == numero[contadA] + numero[contadB])
    {
      printf("\n¡CORRECTO!");
    }
    else
    {
      printf("\nError\n");
      printf("La respuesta es %d", numero[contadA] + numero[contadB]);
    }
    printf("\nDesea repetir el proceso (S/N) > ");
    scanf("\n%c", &repetir);
    if (repetir != 'S' && repetir != 's')
    {
      break;
    }
    else
    {
      contadA = contadA + 2;
      if (contadA > 9)
      {
        contadA = contadA - 10;
        diferen = diferen + 1;
      }
      if (diferen > 9)
      {
        diferen = 2;
      }
      contadB = contadA + diferen;
      if (contadB > 9)
      {
        contadB = contadB - 10;
      }
    }
  }
}

void probrest() /* problemas de resta */
{
  int contadA, contadB, diferen, respuest;
  char repetir;

  contadA = 2;
  diferen = 3;
  contadB = contadA + diferen;

  while (1 == 1)
  {
    if (numero[contadA] < numero[contadB])
    {
      repetir = 'S';
    }
    else
    {
      printf("\n\n\n\n\n\n");
      printf("\t\tPROBLEMAS DE RESTA");
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("\t%d - %d = ", numero[contadA], numero[contadB]);
      scanf("%d", &respuest);
      if (respuest == numero[contadA] - numero[contadB])
      {
        printf("\n¡CORRECTO!");
      }
      else
      {
        printf("\nError\n");
        printf("La respuesta es %d", numero[contadA] - numero[contadB]);
      }
      printf("\nDesea repetir el proceso (S/N) > ");
      scanf("\n%c", &repetir);
    }
    if (repetir != 'S' && repetir != 's')
    {
      break;
    }
    else
    {
      contadA = contadA + 2;
      if (contadA > 9)
      {
        contadA = contadA - 10;
        diferen = diferen + 1;
      }
      if (diferen > 9)
      {
        diferen = 2;
      }
      contadB = contadA + diferen;
      if (contadB > 9)
      {
        contadB = contadB - 10;
      }
    }
  }
}

void probmult() /* problemas de multiplicación */
{
  int contadA, contadB, diferen, respuest;
  char repetir;

  contadA = 4;
  diferen = 5;
  contadB = contadA + diferen;

  while (1 == 1)
  {
    printf("\n\n\n\n\n\n");
    printf("\t\t\tPROBLEMAS DE MULTIPLICACION");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t%d x %d = ", numero[contadA], numero[contadB]);
    scanf("%d", &respuest);
    if (respuest == numero[contadA] * numero[contadB])
    {
      printf("\n¡CORRECTO!");
    }
    else
    {
      printf("\nError\n");
      printf("La respuesta es %d", numero[contadA] * numero[contadB]);
    }
    printf("\nDesea repetir el proceso (S/N) > ");
    scanf("\n%c", &repetir);

    if (repetir != 'S' && repetir != 's')
    {
      break;
    }
    else
    {
      contadA = contadA + 2;
      if (contadA > 9)
      {
        contadA = contadA - 10;
        diferen = diferen + 1;
      }
      if (diferen > 9)
      {
        diferen = 2;
        contadB = contadA + diferen;
        if (contadB > 9)
        {
          contadB = contadB - 10;
        }
      }
    }
  }
}

void probdivi() /* problemas de división */
{
  int contadA, contadB, diferen, respuest, resto;
  char repetir;

  contadA = 3;
  diferen = 4;
  contadB = contadA + diferen;

  while (1 == 1)
  {
    if (numero[contadA] < numero[contadB] || numero[contadB] == 0)
    {
      repetir = 'S';
    }
    else
    {
      printf("\n\n\n\n\n\n");
      printf("\t\t\tPROBLEMAS DE DIVISION");
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("\t%d / %d = ", numero[contadA], numero[contadB]);
      printf("\nCuál es la respuesta > ");
      scanf("%d", &respuest);
      printf("\nCuál es el resto > ");
      scanf("%d", &resto);
      if (respuest == numero[contadA] / numero[contadB] &&
          resto == numero[contadA] % numero[contadB])
      {
        printf("\n¡CORRECTO!");
      }
      else
      {
        printf("\nError\n");
        printf("La respuesta es %d, el resto es %d",
               numero[contadA] / numero[contadB],
               numero[contadA % numero[contadB]]);
      }
      printf("\nDesea repetir el proceso (S/N) > ");
      scanf("\n%c", &repetir);
    }
    if (repetir != 'S' && repetir != 's')
    {
      break;
    }
    else
    {
      contadA = contadA + 2;
      if (contadA > 9)
      {
        contadA = contadA - 10;
        diferen = diferen + 1;
      }
      if (diferen > 9)
      {
        diferen = 2;
      }
      contadB = contadA + diferen;
      if (contadB > 9)
      {
        contadB = contadB - 10;
      }
    }
  }
}
