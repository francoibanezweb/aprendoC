/***************
| Ap.06, Ej.07 |
***************/
#include <stdio.h>
#include <stdlib.h>

int main()
{ /* añadir los datos introducidos por el usuario a un fichero  */
  /* de texto en disco */
  FILE *puntFich;
  char datosUsu;

  puntFich = fopen("notas.txt", "a");

  if (puntFich == NULL)
  {
    printf("Error de apertura de fichero");
    exit(0);
  }
  printf("\nIntroduzca el texto que desee añadir al fichero > ");

  while (datosUsu != '\n')
  {
    scanf("%c", &datosUsu);
    putc(datosUsu, puntFich);
  }
  fclose(puntFich);

  return 0;
}