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
        printf("6. Ejecutar 01_06\n");
        printf("7. Ejecutar 01_07\n");
        printf("8. Ejecutar 01_08\n");
        printf("9. Ejecutar 01_09\n");
        printf("10. Ejecutar 01_10\n");
        printf("11. Ejecutar 01_11\n");
        printf("12. Ejecutar 01_12\n");
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
            case 6:
                system("./src/01_dialogo_con_el_usuario/ej_06");
                break;
            case 7:
                system("./src/01_dialogo_con_el_usuario/ej_07");
                break;
            case 8:
                system("./src/01_dialogo_con_el_usuario/ej_08");
                break;
            case 9:
                system("./src/01_dialogo_con_el_usuario/ej_09");
                break;
            case 10:
                system("./src/01_dialogo_con_el_usuario/ej_10");
                break;
            case 11:
                system("./src/01_dialogo_con_el_usuario/ej_11");
                break;
            case 12:
                system("./src/01_dialogo_con_el_usuario/ej_12");
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
