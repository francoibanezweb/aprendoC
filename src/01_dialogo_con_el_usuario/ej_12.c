/***************
| Ap.01, Ej.12 |
***************/
#include <stdio.h>
int main(){                /* impresión del código ASCII del */
                           /* carácter tecleado por el usuario*/
  char carEjemp;           
  printf("\nCarácter del que desea conocer el código ASCII > ");
  scanf("%c", &carEjemp);
  printf("\nEl código ASCII de %c es %d\n",carEjemp,carEjemp);
  return 0;
}