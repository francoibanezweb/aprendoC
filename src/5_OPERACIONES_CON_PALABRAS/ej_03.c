/***************
| Ap.05, Ej.03 |
***************/
#include <stdio.h>
#include <string.h>

int main()
{ /* programa ejemplo, uso de un contador en operaciones */
  /* con una cadena */
  char nombre[16];
  int contador;

  contador = 0;

  strcpy(nombre, "Amadeo");

  while(nombre[contador] != '\0')
  {
    printf("\nLa letra %d de %s es %c.", contador + 1, nombre, nombre[contador]);
    contador = contador + 1;
  }

  return 0;
}
