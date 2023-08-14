/***************
| Ap.06, Ej.05 |
***************/
#include <stdio.h>

void impresion(int (*tabla)[9]);

int main()
{ /* impresión de una tabla, método de alto nivel */
  int contador, tablaEje[9];
  contador = 0;
  while (contador < 9) /* asignación de valores a todos los elementos */
  {                    /* de la tabla */
    tablaEje[contador] = contador + 1;
    contador = contador + 1;
  }
  impresion(&tablaEje);
  return 0;
}

void impresion(int (*tabla)[9])
{
  int contador;

  contador = 0;
  while (contador < 9)
  {
    printf("\n El elemento %d es igual a %d.", contador, (*tabla)[contador]);
    contador = contador + 1;
  }
}