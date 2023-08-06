/***************
| Ap.01, Ej.09 |
***************/
#include <stdio.h>
int main(){
                          /* Utilización de scanf y printf */
  int numEjemp;
  printf("¿Qué desea que aparezca en pantalla? ");
  scanf("%d", &numEjemp);
  printf("\nEl número que ha tecleado es el %d. \n", numEjemp);
  return 0;
}