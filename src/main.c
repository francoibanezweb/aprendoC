#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>

#ifndef DT_REG
#define DT_REG 8
#endif

#ifndef DT_DIR
#define DT_DIR 4
#endif

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int compareStrings(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

int countFilesInDir(const char *dirname)
{
    int count = 0;
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dirname);
    if (dir != NULL)
    {
        while ((entry = readdir(dir)) != NULL)
        {
            if (entry->d_type == DT_REG)
            {
                count++;
            }
        }
        closedir(dir);
    }
    return count;
}

void listExercises(const char *dirname, char *exercises[])
{
    int count = 0;
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dirname);
    if (dir != NULL)
    {
        while ((entry = readdir(dir)) != NULL)
        {
            char path[256];
            snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

            struct stat file_stat;
            if (stat(path, &file_stat) == 0 && S_ISREG(file_stat.st_mode))
            {
                // Exclude certain files from the list
                if (strcmp(entry->d_name, "CMakeLists.txt") != 0 &&
                    strcmp(entry->d_name, "cmake_install.cmake") != 0 &&
                    strcmp(entry->d_name, "Makefile") != 0)
                {
                    // Extract the exercise number from the filename
                    int exercise_number;
                    if (sscanf(entry->d_name, "ej_%*d_%d",
                               &exercise_number) == 1)
                    {
                        exercises[count] = strdup(entry->d_name);
                        count++;
                    }
                }
            }
        }
        closedir(dir);

        // Sort the exercise names
        qsort(exercises, count, sizeof(char *), compareStrings);
    }
}

int main()
{
    const char *src_dir = "./src"; // Modify this path to your src directory
    DIR *dir;
    struct dirent *entry;

    dir = opendir(src_dir);
    if (dir == NULL)
    {
        printf("Error opening the source directory.\n");
        return 1;
    }

    int total_chapters = 0;
    char *chapter_names[100]; // Adjust the array size as per your requirements

    int total_exercises = 0;
    char *exercise_names[100] = {NULL}; // Adjust the array size as per your
                                        // requirements

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 &&
            strcmp(entry->d_name, "..") != 0)
        {
            chapter_names[total_chapters] = strdup(entry->d_name);
            total_chapters++;
        }
    }

    qsort(chapter_names, total_chapters, sizeof(char *), compareStrings);

    closedir(dir);

    while (1)
    {
        clearScreen();
        printf("== MENU ==\n");

        for (int i = 0; i < total_chapters; i++)
        {
            printf("%d. Seleccionar Tema %s\n", i + 1, chapter_names[i]);
        }

        printf("Q. Salir\n");
        printf("Elija una opción de capítulo: ");

        int chapter_option;
        char choice;

        if (scanf(" %c", &choice) == 1) // Read a character input
        {
            if (choice == '0')
            {
                break;
            }
            else if (choice == 'q' || choice == 'Q') // Handle 'Q' or 'q'
            {
                break;
            }
            else if (isdigit(choice))
            {
                // Convert the character input to an integer
                chapter_option = choice - '0';
                // ... (rest of the code)
                char chapter_dir[100];
                snprintf(chapter_dir, sizeof(chapter_dir), "%s/%s", src_dir,
                         chapter_names[chapter_option - 1]);

                for (int i = 0; i < 100; i++)
                {
                    exercise_names[i] = NULL;
                }

                total_exercises = countFilesInDir(chapter_dir);
                listExercises(chapter_dir, exercise_names);

                int option;

                printf("Inside Inner Loop\n");

                while (1)
                {
                    clearScreen();
                    printf("== MENU ==\n");

                    for (int i = 0; i < total_exercises; i++)
                    {
                        if (exercise_names[i] != NULL)
                        {
                            printf("%d. Ejecutar %s\n", i + 1,
                                   exercise_names[i]);
                        }
                    }

                    printf("Q. Volver al Menú de Capítulos\n");

                    printf("Elija una opción: ");
                    char option;
                    scanf(" %c", &option);
                    while (getchar() != '\n')
                        ; // Clear input buffer

                    if (option == 'Q' || option == 'q')
                    {
                        break;
                    }
                    else if (isdigit(option))
                    {
                        int exercise_option = option - '0';
                        if (exercise_option >= 1 &&
                            exercise_option <= total_exercises)
                        {
                            // ... (rest of the code for exercise execution)
                            char *exercise_name = exercise_names[exercise_option - 1];
                            char exercise_path[200];
                            snprintf(exercise_path, sizeof(exercise_path),
                                     "%s/%s/%s", src_dir,
                                     chapter_names[chapter_option - 1],
                                     exercise_name);

                            printf("\n");

                            int result = system(exercise_path);

                            printf("\nEnter para continuar...\n");
                            while (getchar() != '\n')
                                ; // Wait for the user to press Enter
                        }
                        else
                        {
                            printf("Opción no válida. Intente de nuevo.\n");
                        }
                    }
                    else
                    {
                        printf("Opción no válida. Intente de nuevo.\n");
                    }
                }
            }
            else
            {
                printf("Opción no válida. Intente de nuevo.\n");
            }
        }
        else
        {
            printf("Opción no válida. Intente de nuevo.\n");
        }
    }

    // Free allocated memory for chapter_names and exercise_names
    for (int i = 0; i < total_chapters; i++)
    {
        free(chapter_names[i]);
    }

    return 0;
}
