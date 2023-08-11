/***************
| Ap.05, Ej.06 |
***************/
/* program ejemplo, diálogo con el usuario, versión mejorada */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char nombre[21];
  int contador;
  printf("\n¿Cómo se llama? > ");

  if (fgets(nombre, sizeof(nombre), stdin) != NULL)
  {
    nombre[strlen(nombre) - 1] = '\0'; 
    /* Elimina el salto de línea capturado por fgets */ 

    nombre[0] = toupper(nombre[0]);
    contador = 1;

    while (nombre[contador] != '\0')
    {
      if (nombre[contador - 1] == ' ')
      {
        nombre[contador] = toupper(nombre[contador]);
      }
      else
      {
        nombre[contador] = tolower(nombre[contador]);
      }
      contador = contador + 1;
    }

    printf("\nHola, %s. \n", nombre);
  }

  return 0;
}
