/***************
| Ap.06, Ej.08 |
***************/
#include <stdio.h>
#include <stdlib.h>

int main()
{ /* leer el fichero de notas */
  FILE *puntFich;
  char escritur;
  puntFich = fopen("notas.txt", "r");
  if (puntFich == NULL)
  {
    printf("Error de apertura de fichero");
    exit(0);
  }
  while (escritur != EOF)
  {
    escritur = getc(puntFich);
    printf("%c", escritur);
  }
  fclose(puntFich);

  return 0;
}