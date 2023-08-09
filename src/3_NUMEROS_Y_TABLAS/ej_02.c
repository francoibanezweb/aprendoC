/***************
| Ap.03, Ej.02 |
***************/
#include <stdio.h>

int main(){               /* introducir salarios semanales */
                          /* programa escrito en la forma */
                          /* fácil de entender */
  float salSem[52];
  int contador, numDeSem, semNumer;

  printf("\n¿Cuántos salarios semanales desea introducir? ");
  scanf("%d", &numDeSem);

  contador = 0;
  semNumer = 1;
  while(contador < numDeSem && contador < 52)
  {
    printf("\nIntroduzca el salario de la semana %d > ", semNumer);
    scanf("%f", &salSem[contador]);
    contador = contador + 1;
    semNumer = semNumer + 1;
  }
  return 0;
}