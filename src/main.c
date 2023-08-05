#include <stdio.h>
#include <stdlib.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    int option;

    while (1) {
        clearScreen();
        printf("== MENU ==\n");
        printf("1. Ejecutar 01_01\n");
        printf("2. Ejecutar 01_02\n");
        printf("3. Ejecutar 01_03\n");
        printf("4. Ejecutar 01_04\n");
        printf("5. Ejecutar 01_05\n");
        printf("0. Salir\n");

        printf("Elija una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                system("./src/01_dialogo_con_el_usuario/ej_01");
                break;
            case 2:
                system("./src/01_dialogo_con_el_usuario/ej_02");
                break;
            case 3:
                system("./src/01_dialogo_con_el_usuario/ej_03");
                break;
            case 4:
                system("./src/01_dialogo_con_el_usuario/ej_04");
                break;
            case 5:
                system("./src/01_dialogo_con_el_usuario/ej_05");
                break;
            case 0:
                return 0;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }

        printf("\nPresione Enter para continuar...\n");
        getchar();
        getchar(); // Esperar a que el usuario presione Enter
    }

    return 0;
}
