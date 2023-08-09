/***************
| Ap.03, Ej.06 |
***************/
#include <stdio.h>

int main()
{
  /* ejemplo de división de enteros */
  /* y obtención del resto */
  int dividend, divisor, respuest, resto;
  dividend = 10;
  divisor = 3;
  respuest = dividend / divisor;
  resto = dividend % divisor;
  printf("\n%d / %d = %d R %d", dividend, divisor, respuest, resto);
  return 0;
}