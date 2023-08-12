/***************
| Ap.05, Ej.08 |
***************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() /* programa ejemplo de diálogo con el usuario, versión inmejorable */
{
  char nombre[21];
  char buffer[80];
  int contador;

  printf("\n¿Cómo se llama? > ");
  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = '\0';

  if (strlen(buffer) > 20)
  {
    printf("Lo siento, su nombre es demasiado largo.");
  }
  else
  {
    strcpy(nombre, buffer);
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
    printf("\nHola, %s.\n", nombre);
  }

  return 0;
}
