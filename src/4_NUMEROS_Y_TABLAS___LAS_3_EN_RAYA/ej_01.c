/***************
| Ap.04, Ej.01 |
***************/
#include <stdio.h>

int sumInt(int x,int y);

int main(){
  /* programa ejemplo de transferencia de parámetros */

  int numero1, numero2, total;
  numero1 = 5;
  numero2 = 3;
  total = sumInt(numero1, numero2);
  printf("%d más %d igual a %d", numero1, numero2, total);

  return 0;
}

int sumInt(int x,int y)
{ /* sumar dos números enteros */
return x + y;
}