/***************
| Ap.03, Ej.07 |
***************/
#include <stdio.h>
#include <stdlib.h>

void borrpant();

int main(){
  /* introducir salarios semanales escrito con la función borrpant() */
  float salSem[52];
  int contador, numDeSem;

  printf("\n¿Cuántos salarios semanales desea introducir? ");
  scanf("%d", &numDeSem);
  
  contador = 0;
  while(contador < numDeSem && contador < 52)
  {
    printf("\nIntroduzca el salario de la semana %d > ",contador + 1);
    scanf("%f",&salSem[contador]);
    contador = contador + 1;
    borrpant();
  }

  return 0;
}

void borrpant()
{                       /* borra la pantalla */
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}