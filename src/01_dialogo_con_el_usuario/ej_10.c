/***************
| Ap.01, Ej.10 |
***************/
#include <stdio.h>
int main(){

  float numEjemp;           /* Utilización de scanf y printf */
  printf("¿Qué desea que aparezca en pantalla? ");
  scanf("%f", &numEjemp);
  printf("\nEl número que ha tecleado es el %f. \n", numEjemp);
  return 0;
}