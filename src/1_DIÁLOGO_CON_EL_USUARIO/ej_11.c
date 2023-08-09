/***************
| Ap.01, Ej.11 |
***************/
#include <stdio.h>
int main(){

  char carEjemp;           /* Utilización de scanf y printf */
  printf("¿Qué desea carácter que aparezca en pantalla? ");
  scanf("%c", &carEjemp);
  printf("\nEl carácter que ha tecleado es el %c. \n", carEjemp);
  return 0;
}