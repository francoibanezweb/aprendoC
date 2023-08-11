/****************
| Ap.04, Ej.03 |
****************/

/* TRES EN RAYA: VERSION INTELIGENTE */

#include <stdio.h>

char casilla[3][3]; /* tabla utilizada como tablero */

int compVict(char letra);
void iniciali();
void presPant();
void leeJugOp();
void mueve();
int posiVict(char xuo);

int main()
{
  char repetir;
  int contaCol, contaLin;
  int contaJug;

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
      if (compVict('O') == 1) /* comprobar victoria del oponente */
      {
        presPant();
        printf("¡Enohorabuena, ha ganado!.\n");
        break;
      }
      else
      { /* si puede ganar, de por terminada la partida */

        if (posiVict('X') == 1)
        {
          presPant();
          printf("He ganado.\n");
          break;
        }
        else /* si puede ganar el oponente, impedirlo */
        {
          if (posiVict('O') == 0) /* en caso contrario, hacer cualquier */
          {                       /* movimiento */
            mueve();
          }
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

int posiVict(char xuo)
{
  int contaLin, contaCol;
  contaLin = 0;

  while (contaLin < 3)
  {
    contaCol = 0;
    while (contaCol < 3)
    {
      if (casilla[contaLin][contaCol] == ' ')
      {
        casilla[contaLin][contaCol] = xuo;
        if (compVict(xuo) == 0)
        {
          casilla[contaLin][contaCol] = ' ';
        }
        else
        {
          if (xuo == 'O')
          {
            casilla[contaLin][contaCol] = 'X';
          }
          return 1;
        }
      }
      contaCol = contaCol + 1;
    }
    contaLin = contaLin + 1;
  }
  return 0;
}

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
