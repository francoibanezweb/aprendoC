/****************
| Ap.05, Ej.01 |
****************/
#include <stdio.h>
#include <string.h>

int main(){  /* programa ejemplo, iniciliazación de una cadena */
  char nombre[16];

  strcpy(nombre,"Amadeo");

  printf("%c%c%c",nombre[3], nombre[4], nombre[5]);

  return 0;
}
