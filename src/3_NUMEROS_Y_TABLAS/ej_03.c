/***************
| Ap.03, Ej.03 |
***************/
#include <stdio.h>

int main()
{ /* introducir salarios semanales */
  /* y calcular el salario anual */
  float salSem[52];
  int contador, numDeSem, semNumer;
  float salAnual;

  printf("\n¿Cuántos salarios semanales desea introducir? ");
  scanf("%d", &numDeSem);

  contador = 0;
  semNumer = 1;
  while (contador < numDeSem && contador < 52)
  {
    printf("\nIntroduzca el salario de la semana %d > ", semNumer);
    scanf("%f", &salSem[contador]);
    contador = contador + 1;
    semNumer = semNumer + 1;
  }
  salAnual = 0; /* sumar todos los salarios semanales */
  contador = 0;
  while (contador < numDeSem && contador < 52)
  {
    salAnual = salAnual + salSem[contador];
    contador = contador + 1;
  }
  printf("\n\nEl salario total anual es %f", salAnual);
  return 0;
}