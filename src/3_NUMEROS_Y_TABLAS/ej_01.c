/***************
| Ap.03, Ej.01 |
***************/
#include <stdio.h>

int main(){               /* introducir salarios semanales */
                          /* programa escrito de la forma fácil */
  float salSem[52];
  int contador, numDeSem;

  printf("\n¿Cuántos salarios semanales desea introducir? ");
  scanf("%d", &numDeSem);
  contador = 0;
  while(contador < numDeSem && contador < 52)
  {
    printf("\nIntroduzca el salario de la semana %d > ", contador + 1);
    scanf("%f", &salSem[contador]);
    contador = contador + 1;
  }
 
  return 0;
}