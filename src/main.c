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

    while (1) /* Chapter Menu Loop */
    {
        clearScreen();
        printf("\n\t\t\t== APRENDO_C 2023 @francoibanezweb ==\n\n");

        for (int i = 0; i < total_chapters; i++)
        {
            printf("\n\n\t\t%d. %s", i + 1, chapter_names[i] + 2);
        }

        printf("\n\n\n\t\t0. SALIR");
        printf("\n\n\t\tELIJA UN TEMA > ");

        int chapter_option;
        int chapter_choice;
        scanf(" %d", &chapter_choice);

        if (chapter_choice == 0)
        {
            break; // Exit the chapter menu
        }
        else if (chapter_choice >= 1 && chapter_choice <= total_chapters)
        {
            chapter_option = chapter_choice - 1;
            char chapter_dir[100];
            snprintf(chapter_dir, sizeof(chapter_dir), "%s/%s", src_dir,
                     chapter_names[chapter_option]);

            for (int i = 0; i < 100; i++)
            {
                exercise_names[i] = NULL;
            }

            total_exercises = countFilesInDir(chapter_dir);
            listExercises(chapter_dir, exercise_names);

            int exercise_choice;

            while (1) /* Exercise Menu Loop */
            {
                clearScreen();
                printf("\n\t\t\t== APRENDO_C 2023 @francoibanezweb ==\n");

                for (int i = 0; i < total_exercises; i++)
                {
                    if (exercise_names[i] != NULL)
                    {
                        printf("\n\t\t%d. Ejecutar %s\n", i + 1,
                               exercise_names[i] + 9);
                    }
                }

                printf("\n\n\t\t0. VOLVER ATRÁS\n");

                printf("\n\n\t\tElija un programa > ");

                scanf(" %d", &exercise_choice);
                while (getchar() != '\n')
                    ; /* Clear input buffer */

                if (exercise_choice == 0)
                {
                    break; // Exit the exercise menu
                }
                else if (exercise_choice >= 1 &&
                         exercise_choice <= total_exercises)
                {
                    char *exercise_name = exercise_names[exercise_choice - 1];
                    char exercise_path[200];
                    snprintf(exercise_path, sizeof(exercise_path),
                             "%s/%s/%s", src_dir,
                             chapter_names[chapter_option],
                             exercise_name);

                    printf("\n");

                    int result = system(exercise_path);

                    printf("\nEnter para continuar...\n");
                    while (getchar() != '\n')
                        ; /* Wait for the user to press Enter */
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

    /* Free allocated memory for chapter_names and exercise_names */
    for (int i = 0; i < total_chapters; i++)
    {
        free(chapter_names[i]);
    }

    return 0;
}
