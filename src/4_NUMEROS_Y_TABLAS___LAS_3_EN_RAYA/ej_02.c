/****************
| Ap.04, Ej.02A |
****************/
/* (DEBE COMPILARSE JUNTO CON LOS EJEMPLOS 2B, 2C, 2D, 2E, 2F) */

/* TRES EN RAYA: VERSION TONTA */

#include <stdio.h>

char casilla[3][3]; /* tabla utilizada como tablero */

int compVict(char letra);
void iniciali();
void presPant();
void leeJugOp();
void mueve();

int main()
{
  char repetir;
  int contaJug, bandVict;

  while (1 == 1) /* repetir mientras el oponenete quiera seguir jugando */
  {
    iniciali(); /* limpiar las casillas de tablero */

    casilla[1][1] = 'X'; /* pone una 'X' en la casilla central */
    presPant();          /* presenta en pantalla el tablero */
    leeJugOp();          /* lee un movimiento válido */
    mueve();             /* hace cualquier movimiento */
    contaJug = 3;        /* tres movimiento efectuados */

    while (1 == 1) /* repetir hasta el final del juego */
    {
      presPant();
      leeJugOp();
      contaJug = contaJug + 1;
      bandVict = compVict('O');
      if (bandVict == 1) /* comprobar si ha ganado el oponente */
      {
        presPant();
        printf("¡Enohorabuena, ha ganado!.\n");
        break;
      }
      else /* en caso contrario hacer cualquier */
      {
        mueve();
        bandVict = compVict('X');
        if (bandVict == 1) /* comprobar si hemos ganado */
        {                  /* si es así, fin de partida */
          presPant();
          printf("He ganado.\n");
          break;
        }
      }
      contaJug = contaJug + 1;
      if (contaJug == 9) /* si se han hecho 9 jugadas sin victoria, */
      {                  /* fin de partida: TABLAS */
        presPant();
        printf("Tablas. Ha sido buena partida.\n");
        break;
      }
      else /* en caso contrario repetir nuevamente el bucle */
      {
        continue;
      }
    } /* fin de la partida */

    printf("\n¿Desea jugar de nuevo (S/N)? ");
    scanf("\n%c", &repetir);
    if (repetir == 'S' || repetir == 's')
    {           /* si el jugador desea jugar de nuevo, volver al  */
      continue; /* principio del bucle */
    }
    else
    { /* en caso contrario salir del programa */
      break;
    }
  }

  return 0;
}

/****************
| Ap.04, Ej.02B |
****************/
/* (DEBE AÑADIRSE AL EJEMPLO 2A) */

int compVict(char letra)
{
  int c;

  c = 0;

  while (c < 3)
  {
    if (casilla[c][0] == letra && casilla[c][1] == letra &&
        casilla[c][2] == letra)
    {
      return 1;
    }
    else
    {
      c = c + 1; /* comprobar todas las líneas */
    }
  }
  c = 0;
  while (c < 3)
  {
    if (casilla[0][c] == letra && casilla[1][c] == letra &&
        casilla[2][c] == letra)
    {
      return 1;
    }
    else
    {
      c = c + 1; /* comprobar todas las columnas */
    }
  }
  if (casilla[0][0] == letra && casilla[1][1] == letra &&
      casilla[2][2] == letra)
  {
    return 1; /* comprobar las diagonales */
  }
  if (casilla[0][2] == letra && casilla[1][1] == letra &&
      casilla[2][0] == letra)
  {
    return 1; /* devolver un 1 si hay tres */
  }           /* casillas consecutivas con la misma letra: hay ganador */
  return 0;   /* En caso contrario devolver 0 */
}

/****************
| Ap.04, Ej.02C |
****************/
/* (DEBE AÑADIRSE AL EJEMPLO 2A) */

void iniciali()
{ /* limpiar todas las casillas del tablero */
  int contaLin, contaCol;

  contaLin = 0;
  while (contaLin < 3)
  {
    contaCol = 0;
    while (contaCol < 3)
    {
      casilla[contaLin][contaCol] = ' ';
      contaCol = contaCol + 1;
    }
    contaLin = contaLin + 1;
  }
}

/****************
| Ap.04, Ej.02D |
****************/
/* (DEBE AÑADIRSE AL EJEMPLO 2A) */

void presPant() /* presentar en pantalla el tablero */
{
  printf("\n\n\n\n\n\n\n");
  printf("\t\t\t\t  C O L U M N A\n\n\n");
  printf("\t\t\t\t   1   2   3\n");
  printf("\n\t\t\tL     1    %c | %c | %c", casilla[0][0], casilla[0][1],
         casilla[0][2]);
  printf("\n\t\t\tI         -----------");
  printf("\n\t\t\tN     2    %c | %c | %c", casilla[1][0], casilla[1][1],
         casilla[1][2]);
  printf("\n\t\t\tE         -----------");
  printf("\n\t\t\tA     3    %c | %c | %c\n\n\n\n\n\n", casilla[2][0],
         casilla[2][1], casilla[2][2]);
}

/****************
| Ap.04, Ej.02E |
****************/
/* (DEBE AÑADIRSE AL EJEMPLO 2A) */

void leeJugOp()
{ /* obtención de un movimiento válido */
  int numLin, numCol;

  while (1 == 1) /* leer el movimiento del oponente */
  {
    printf("\n¿En qué línea desea situar la 'O'?");
    printf("\nIntroduzca un número del 1 al 3 > ");
    scanf("%d", &numLin);
    printf("\n¿En qué columna desea situar la 'O'?");
    printf("\nIntroduzca un número del 1 al 3 > ");
    scanf("%d", &numCol);

    numLin = numLin - 1;
    numCol = numCol - 1;

    if (numLin < 0 || numLin > 2 || numCol < 0 || numCol > 2 ||
        casilla[numLin][numCol] != ' ')
    {
      printf("%c", 7); /* si el movimiento no es válido emitir un pitido,  */
      presPant();      /* presentar de nuevo la pantalla y volver a obtener */
      continue;        /* otro movimiento */
    }
    else
    { /* Si es válido, colocar una O en esa casilla */
      casilla[numLin][numCol] = 'O';
      break;
    }
  }
}

/****************
| Ap.04, Ej.02F |
****************/
/* (DEBE AÑADIRSE AL EJEMPLO 2A) */

void mueve()
{
  if (casilla[0][0] == ' ')
  {
    casilla[0][0] = 'X';
  }
  else if (casilla[0][2] == ' ')
  {
    casilla[0][2] = 'X';
  }
  else if (casilla[2][0] == ' ')
  {
    casilla[2][0] = 'X';
  }
  else if (casilla[2][2] == ' ')
  {
    casilla[2][2] = 'X';
  }
  else if (casilla[0][1] == ' ')
  {
    casilla[0][1] = 'X';
  }
  else if (casilla[1][0] == ' ')
  {
    casilla[1][0] = 'X';
  }
  else if (casilla[1][2] == ' ')
  {
    casilla[1][2] = 'X';
  }
  else if (casilla[2][1] == ' ')
  {
    casilla[2][1] = 'X';
  }
}
