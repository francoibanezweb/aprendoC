/****************
| Ap.05, Ej.02 |
****************/
#include <stdio.h>
#include <string.h>

int main(){  /* programa ejemplo, operaciones con una cadena */
  char nombre[16];

  strcpy(nombre,"Amadeo");

  printf("La segunda letra de %s es %c", nombre, nombre[1]);

  return 0;
}
