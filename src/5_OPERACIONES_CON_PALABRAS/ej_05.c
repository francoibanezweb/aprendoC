/***************
| Ap.05, Ej.05 |
***************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{ /* program ejemplo, diálogo con el usuario, versión mejorada */
  char nombre[21];
  int contador;
  printf("\n¿Cómo se llama? > ");
  scanf("%s", nombre);
  nombre[0] = toupper(nombre[0]);
  contador = 1;
  while (nombre[contador] != '\0')
  {
    nombre[contador] = tolower(nombre[contador]);
    contador = contador + 1;
  }
  printf("\nHola, %s. \n", nombre);

  return 0;
}
