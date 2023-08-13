/***************
| Ap.06, Ej.02 |
***************/
#include <stdio.h>
/* programa ejemplo: forma errónea de modificar valores de parámetros */
int incsum(int x, int y);
int main(){
  int numero1, numero2, total;

  numero1 = 5;
  numero2 = 3;

  total = incsum(numero1, numero2);
  printf("\n%d más %d igual a %d.",numero1, numero2,total);

  return 0;
}

int incsum(int x, int y)
{
  x = x + 1;
  y = y + 1;
  return x + y;
}