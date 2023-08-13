/***************
| Ap.06, Ej.01 |
***************/
#include <stdio.h>

/* programa ejemplo de utilización de punteros */
int main(){
  int varEjem;  
  int *pVarEjem;

  varEjem = 10;
  printf("\nLa variable ejemplo vale %d", varEjem);
  pVarEjem = &varEjem;
  *pVarEjem = 2;
  printf("\nAhora la variable ejemplo vale %d.",varEjem);

  return 0;
}