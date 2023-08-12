/***************
| Ap.05, Ej.07 |
***************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void contras();

int main()
{ /* programa ejemplo uso de contraseña */

  contras();

  printf("\nContraseña correcta, puede utilizar el programa");

  return 0;
}

void contras() /* leer y verificar una contraseña */
{
  int contaLet, contaInt;
  char contras[12];

  contaInt = 0;  /* bucle para dar al usuario tres intentos para hallar la  */
  while (1 == 1) /* contraseña */
  {
    printf("¿Cuál es la contraseña? > ");
    scanf("%s", contras);  /* pone en mayúsculas la entrada del usuario */

    contaLet = 0;
    while (contras[contaLet] != '\0')
    {
      contras[contaLet] = toupper(contras[contaLet]);
      contaLet = contaLet + 1;
    }
    if (strcmp(contras, "ABRACADABRA") == 0)
    {
      break; /* si la contraseña es correcta pasar al programa principal */
    }
    else
    {
      contaInt = contaInt + 1;
      if(contaInt == 3)
      {             /* si se han producido 3 errores al introducir la  */
        exit(0);     /* contreseña, impedir el acceso al programa */
      }
    }
  }
}
