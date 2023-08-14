/***************
| Ap.06, Ej.06 |
***************/
#include <stdio.h>

int main(){ /* escribir los datos introducidos por el usuario en un fichero  */
  FILE *puntFich; /* de texto en disco */
  char datosUsu;

  puntFich = fopen("notas.txt", "w");
  printf("\nIntroduzca el texto que desee archivar > ");
  while(datosUsu != '\n')
  {
    scanf("%c",&datosUsu);
    putc(datosUsu,puntFich);
  }
  fclose(puntFich);

  return 0;
}