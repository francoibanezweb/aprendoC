/***************
| Ap.03, Ej.09 |
***************/
#include <stdio.h>

int numDeSem;

float salTot[52][5];

void totSS();
void exmDat();

int main()
{
  /* introducir salarios, impuestos, S.S. */
  /* y contribuciones sociales semanales */

  int contador;

      printf("\n¿Cuántos salarios semanales desea introducir? ");
  scanf("%d", &numDeSem);

  contador = 0;
  while (contador < numDeSem && contador < 52)
  {
    printf("\nIntroduzca el salario de la semana %d > ", contador + 1);
    scanf("%f", &salTot[contador][0]);

    printf("\nIntroduzca los impuestos deducidos en la semana %d > ",
           contador + 1);
    scanf("%f", &salTot[contador][3]);

    salTot[contador][3] = salTot[contador][0] -
                          salTot[contador][1] -
                          salTot[contador][2];

    printf("\nIntroduzca la contribución social de la semana %d > ",
           contador + 1);
    scanf("%f",&salTot[contador][4]);

    contador = contador + 1;
  }

  totSS();

  exmDat();

  return 0;
}

/***************
| Ap.03, Ej.10 |
***************/
/* módulo a utilizar en el programa APARTADO 3, EJEMPLO 9 */
/* debe añadirse el comando totSS(); antes de la llave de cierre */
/* final (}), e incluirse esta función después de la misma */

void totSS()
{
  int contador;
  float suma;

  contador = 0;
  suma = 0;
  while (contador < numDeSem && contador < 52)
  {
    suma = suma + salTot[contador][2];
    contador = contador + 1;
  }
  printf("\n\nDeducciones totales en Seg. Social > %f\n\n", suma);

}

/***************
| Ap.03, Ej.11 |
***************/
/* módulo a utilizar en el programa AP. 03, Ej. 09 */
/* debe añadirse el comando exmDat(); antes de la llave de cierre */
/* final (}), e incluirse esta función después de la misma */

void exmDat(){
  int semana;

  printf("\n¿Qué semana desea examinar? > ");
  scanf("%d",&semana);
  if(semana < 1 || semana > 52 || semana > numDeSem)
  {
    printf("%c",7);
  }
  else
  {
    semana = semana - 1;
    printf("\nSalario Bruto: %f", salTot[semana][0]);
    printf("\nImpuestos: %f",salTot[semana][1]);
    printf("\nSeguridad Social: %f", salTot[semana][4]);
    printf("\nSalario Neto: %f", salTot[semana][4]);
    printf("\nContribución Social: %f", salTot[semana][5]);
  }
}