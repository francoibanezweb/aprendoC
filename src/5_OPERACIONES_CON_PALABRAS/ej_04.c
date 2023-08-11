/***************
| Ap.05, Ej.04 |
***************/
#include <stdio.h>
#include <string.h>

int main(){   /* programa ejemplo, dialogo con el usuario */
  char nombre[21];

  printf("\n¿Cómo se llama? > ");
  scanf("%s",nombre);
  printf("\nHola, %s. \n",nombre);

  return 0;
}
