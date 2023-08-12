/***************
| Ap.05, Ej.09 |
***************/
/* Programa de preguntas español-alemán */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXPALAB 10

struct vocabul
{ /* estructura en la que se almacenan los datos con los que  */
  /* formar las preguntas */
  char Espanol[16];
  char Aleman[16];
  char elemento;
  int bandErr;
} esAle[MAXPALAB];

void pregunta(char idiom1[], char idiom2[], char elem);
void iniciali();
void clearBuffer();

int bandRepe;

int main() /* menú principal */
{

  char opc[2];
  char idiomPre[8], idiomRes[8], queElem;

  iniciali();
  bandRepe = 0;
  while (1 == 1) /* presentación en pantalla del menú  */
  {
    printf("\n\t\tPreguntas de Vocabulario\n\n");
    printf("\n\n\t\t1 - Español a Alemán, nombres");
    printf("\n\n\t\t2 - Español a Alemán, verbos");
    printf("\n\n\t\t3 - Español a Alemán, otros");
    printf("\n\n\t\t4 - Español a Alemán, todo");
    printf("\n\n\t\t5 - Alemán a Español, nombres");
    printf("\n\n\t\t6 - Alemán a Español, verbos");
    printf("\n\n\t\t7 - Alemán a Español, otros");
    printf("\n\n\t\t8 - Alemán a Español, todo");

    if (bandRepe == 1)
    {
      printf("\n\n\t\t9 - Repetir errores de la última prueba");
    }
    printf("\n\n\t\t0 - Salir del programa");
    if (bandRepe != 1)
    {
      printf("\n\n");
    }
    printf("\n\n\t\t\t¿Qué opción desea? > ");

    fgets(opc, sizeof(opc), stdin); /* obtención de la opción que desea el  */
    opc[strcspn(opc, "\n")] = '\0'; /* usuario y asignación de los valores */
    clearBuffer();                  /* correspondientes a las variables */

    if (opc[0] == '1' || opc[0] == '2' || opc[0] == '3' || opc[0] == '4')
    {
      strcpy(idiomPre, "Espanol");
      strcpy(idiomRes, "Aleman");
    }
    if (opc[0] == '5' || opc[0] == '6' || opc[0] == '7' || opc[0] == '8')
    {
      strcpy(idiomPre, "Aleman");
      strcpy(idiomRes, "Espanol");
    }
    if (opc[0] == '1' || opc[0] == '5')
    {
      queElem = 'N';
    }
    else if (opc[0] == '2' || opc[0] == '6')
    {
      queElem = 'V';
    }
    else if (opc[0] == '3' || opc[0] == '7')
    {
      queElem = 'O';
    }
    else if (opc[0] == '4' || opc[0] == '8')
    {
      queElem = 'T';
    }
    else if (opc[0] == '9' && bandRepe == 1)
    {
      queElem = 'R';
    }
    else if (opc[0] == '0')
    {
      break;
    }
    else
    {
      putchar(7);
      continue;
    }
    pregunta(idiomPre, idiomRes, queElem);
  }

  return 0;
}

void clearBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }
}

void iniciali()
{ /* creación de una lista de palabras españolas y alemanas */
  /*  Versión 1 */
  int contador;

  contador = 0;

  while (contador < MAXPALAB)
  {
    esAle[contador].bandErr = 0;
    contador = contador + 1;
  }
  strcpy(esAle[0].Espanol, "HABLAR");
  strcpy(esAle[0].Aleman, "SPRECHEN");
  esAle[0].elemento = 'V';
  strcpy(esAle[1].Espanol, "VENDER");
  strcpy(esAle[1].Aleman, "VERKAUFEN");
  esAle[1].elemento = 'V';
  strcpy(esAle[2].Espanol, "IR");
  strcpy(esAle[2].Aleman, "GEHEN");
  esAle[2].elemento = 'V';
  strcpy(esAle[3].Espanol, "EL LIBRO");
  strcpy(esAle[3].Aleman, "DAS BUCH");
  esAle[3].elemento = 'N';
  strcpy(esAle[4].Espanol, "LA PLUMA");
  strcpy(esAle[4].Aleman, "DIE FEDER");
  esAle[4].elemento = 'N';
  strcpy(esAle[5].Espanol, "LA MUCHACHA");
  strcpy(esAle[5].Aleman, "DAS MADCHEN");
  esAle[5].elemento = 'N';
  strcpy(esAle[6].Espanol, "EN");
  strcpy(esAle[6].Aleman, "IN");
  esAle[6].elemento = 'O';
  strcpy(esAle[7].Espanol, "SOBRE");
  strcpy(esAle[7].Aleman, "AUF");
  esAle[7].elemento = 'O';
  strcpy(esAle[8].Espanol, "DURANTE");
  strcpy(esAle[8].Aleman, "WAHREND");
  esAle[8].elemento = 'O';
  strcpy(esAle[9].Espanol, "ANTES");
  strcpy(esAle[9].Aleman, "VORHER");
  esAle[9].elemento = 'O';
}

void pregunta(char idiom1[], char idiom2[], char elem)
{ /* preguntas al usuario utilizando */
  /* parámetros a los que se les han asignado */
  /* valores en main() */
  int contaPal, contaLet;
  char respuest[16];
  char siono[2];

  bandRepe = 0;

  contaPal = 0;
  if (elem != 'R')
  {                                /* si no se van a repetir las preguntas */
    while (contaPal < MAXPALAB)    /* erróneas, poner a 0 las banderas  */
    {                              /* de error para poder anotar los  */
      esAle[contaPal].bandErr = 0; /* nuevos errores */
      contaPal = contaPal + 1;
    }
  }
  contaPal = 0;
  while (contaPal < MAXPALAB)
  {
    if (elem != 'T' && elem != 'R' && elem != esAle[contaPal].elemento)
    {
      contaPal = contaPal + 1;
      continue;
    }
    if (elem == 'R' && esAle[contaPal].bandErr != 1)
    {
      contaPal = contaPal + 1;
      continue;
    }
    printf("\n\n\n\n\n\n\n");
    printf("\t\t Traducción de %s a %s", idiom1, idiom2);
    printf("\n\n\t\t\tpreguntas de ");
    if (elem == 'N')
    { /* presentación en pantalla */
      printf("nombres");
    }
    else if (elem == 'V')
    {
      printf("verbos");
    }
    else if (elem == 'O')
    {
      printf("otros elementos gramaticales");
    }
    else if (elem == 'T')
    {
      printf("todo tipo de elementos gramaticales");
    }

    if (idiom1[0] == 'A')
    {
      printf("\n\n\n\n\n\n\n\n\n");
      printf("\t\t\t\t%s", esAle[contaPal].Aleman);
      printf("\n\n\n\n\n\n\n\n");
      printf("¿Cuál es la traducción al Español? > ");

      fgets(respuest, sizeof(respuest), stdin); /* estas 2 líneas son una  */
      respuest[strcspn(respuest, "\n")] = '\0'; /* alternativa a gets() */

      clearBuffer();

      contaLet = 0;
      while (respuest[contaLet] != '\0')
      {
        respuest[contaLet] = toupper(respuest[contaLet]);
        contaLet = contaLet + 1;
      }
      if (strcmp(respuest, esAle[contaPal].Espanol) == 0)
      {
        printf("\n\nFelicitaciones. Respuesta correcta.");
        printf("\n¿Desea intentarlo de nuevo? (S/N) > ");

        fgets(siono, sizeof(siono), stdin);
        siono[strcspn(siono, "\n")] = '\0';

        clearBuffer();

        if (toupper(siono[0]) == 'N')
        {
          return;
        }
      }
      else /* mensaje para respuesta correcta o errónea */
      {
        esAle[contaPal].bandErr = 1;
        bandRepe = 1;
        printf("\n\nLa respuesta correcta es %s.", esAle[contaPal].Espanol);
        printf("\n\n¿Desea intentarlo de nuevo? (S/N) > ");

        fgets(siono, sizeof(siono), stdin);
        siono[strcspn(siono, "\n")] = '\0';

        clearBuffer();

        if (toupper(siono[0]) == 'N')
        {
          return;
        }
      }
      contaPal = contaPal + 1;
    }
    else
    {
      printf("\n\n\n\n\n\n\n\n\n");
      printf("\t\t\t\t%s", esAle[contaPal].Espanol);
      printf("\n\n\n\n\n\n\n\n");
      printf("¿Cuál es la traducción al Alemán? > ");

      fgets(respuest, sizeof(respuest), stdin);
      respuest[strcspn(respuest, "\n")] = '\0';

      clearBuffer();

      contaLet = 0;
      while (respuest[contaLet] != '\0')
      {
        respuest[contaLet] = toupper(respuest[contaLet]);
        contaLet = contaLet + 1;
      }
      if (strcmp(respuest, esAle[contaPal].Aleman) == 0)
      {
        printf("\n\nFelicitaciones. Respuesta correcta.");
        printf("\n¿Desea intentarlo de nuevo? (S/N) > ");

        fgets(siono, sizeof(siono), stdin);
        siono[strcspn(siono, "\n")] = '\0';

        clearBuffer();

        if (toupper(siono[0]) == 'N')
        {
          return;
        }
        else
        {
          esAle[contaPal].bandErr = 1;
          bandRepe = 1;
          printf("\n\nLa respuesta correcta es %s.", esAle[contaPal].Aleman);
          printf("\n¿Desea intentarlo de nuevo? (S/N) > ");

          fgets(siono, sizeof(siono), stdin);
          siono[strcspn(siono, "\n")] = '\0';

          clearBuffer();

          if (toupper(siono[0]) == 'N')
          {
            return;
          }
        }
        contaPal = contaPal + 1;
      }
    }
  }
}
