/***************
| Ap.06, Ej.04 |
***************/
#include <stdio.h>

void impresion(int tabla[]);

int main(){  /* impresión de una tabla, método de alto nivel */
  int contador, tablaEje[9];
  contador = 0;
  while(contador < 9) /* asignación de valores a todos los elementos */
  {                   /* de la tabla */
    tablaEje[contador] = contador + 1;
    contador = contador + 1;
  }
  impresion(tablaEje);
  return 0;
}

void impresion(int tabla[])
{
    int contador;

    contador = 0;
    while(contador < 9)
    {
      printf("\nEl elemento %d es igual a %d.", contador, tabla[contador]);
      contador = contador + 1;
    }
}