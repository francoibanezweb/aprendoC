/***************
| Ap.06, Ej.13 |
***************/
/* Spanish - German flashcard program */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXWORDS 100

const char FOREIGN[] = "German";

struct flshcard
{
  char Spanish[16];
  char FOREIGN[16]; /* struct to hold flashcard data */
  char spchPart;
  int errorFlg;
} spGe[MAXWORDS];

int retstFlg;

void initlze();
int testword(char lang1[], char lang2[], char pos);
void clearBuffer();

int main()
{
  char ch[2];
  char toAsk[8], toAnswer[8], whchWrds;

  initlze();
  retstFlg = 0;

  while (1 == 1)
  {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\t\tLanguage Flashcards\n\n");
    printf("\n\n\t\t1 - English to FOREIGN, nouns");
    printf("\n\n\t\t2 - English to FOREIGN, verbs");
    printf("\n\n\t\t3 - English to FOREIGN, others");
    printf("\n\n\t\t4 - English to FOREIGN, all");
    printf("\n\n\t\t5 - FOREIGN to English, nouns");
    printf("\n\n\t\t6 - FOREIGN to English, verbs");
    printf("\n\n\t\t7 - FOREIGN to English, others");
    printf("\n\n\t\t8 - FOREIGN to English, all");

    if (retstFlg == 1)
    {
      printf("\n\n\t\t9 - Errors from last test");
    }

    printf("\n\n\t\t0 - Quit");

    if (retstFlg != 1)
    {
      printf("\n\n");
    }

    printf("\n\n\t\t\tWhat is your choice > ");

    fgets(ch, sizeof(ch), stdin);
    ch[strcspn(ch, "\n")] = '\0';
    clearBuffer(); /* get user's choice and set parameters accordingly */

    if (ch[0] == '1' || ch[0] == '2' || ch[0] == '3' || ch[0] == '4')
    {
      strcpy(toAsk, "English");
      strcpy(toAnswer, "FOREIGN");
    }
    if (ch[0] == '5' || ch[0] == '6' || ch[0] == '7' || ch[0] == '8')
    {
      strcpy(toAsk, "FOREIGN");
      strcpy(toAnswer, "English");
    }
    if (ch[0] == '1' || ch[0] == '5')
    {
      whchWrds = 'N';
    }
    else if (ch[0] == '2' || ch[0] == '6')
    {
      whchWrds = 'V';
    }
    else if (ch[0] == '3' || ch[0] == '7')
    {
      whchWrds = 'O';
    }
    else if (ch[0] == '4' || ch[0] == '8')
    {
      whchWrds = 'A';
    }
    else if (ch[0] == '9' && retstFlg == 1)
    {
      whchWrds = 'R';
    }
    else if (ch[0] == '0')
    {
      break;
    }
    else
    {
      putchar(7);
      continue;
    }
    testword(toAsk, toAnswer, whchWrds);
  }
  return 0;
}

void initlze()
{
  FILE *filePtr;

  if ((filePtr = fopen("/home/franco/programacion/aprendoC/build/wordlist.txt",
                       "r")) == NULL)
  {
    printf("ERROR: The wordlist file cannot be opened\n");
    exit(1);
  }

  int entrCntr = 0;
  char line[64];

  while (fgets(line, sizeof(line), filePtr) != NULL)
  {
    char Spanish[16];
    char German[16];
    char spchPart;

    if (sscanf(line, "%s %s %c", Spanish, German, &spchPart) == 3)
    {
      strcpy(spGe[entrCntr].Spanish, Spanish);
      strcpy(spGe[entrCntr].FOREIGN, German);
      spGe[entrCntr].spchPart = spchPart;

      // printf("Debug: Spanish: %s, German: %s, Part of Speech: %c\n",
      //        Spanish, German, spchPart);

      entrCntr++;

      if (entrCntr >= MAXWORDS)
      {
        printf("WARNING: Reached the maximum number of words.\n");
        break;
      }
    }
    else
    {
      printf("WARNING: Invalid line format in the wordlist file: %s\n", line);
    }
  }

  fclose(filePtr);
}

int testword(char lang1[], char lang2[], char pos) /* test user */
{                                                  /* using parameters set */
  int wrdCntr, ltrCntr;                            /* in main() */
  char answer[16];
  char yorn[2];
  int retestFlg;

  wrdCntr = 0;
  if (pos != 'R') /* if not a retest, make error flags 0 so they so they */
  {               /* can record new errors */
    while (wrdCntr < MAXWORDS)
    {
      spGe[wrdCntr].errorFlg = 0;
      wrdCntr = wrdCntr + 1;
    }
  }
  wrdCntr = 0;
  while (wrdCntr < MAXWORDS)
  {
    if (pos != 'A' && pos != 'R' && pos != spGe[wrdCntr].spchPart)
    {
      wrdCntr = wrdCntr + 1;
      continue;
    }
    if (pos == 'R' && spGe[wrdCntr].errorFlg != 1)
    {
      wrdCntr = wrdCntr + 1;
      continue;
    }
    printf("\n\n\n\n\n\n\n");
    printf("\t\t   Translation from %s to %s", lang1, lang2);
    printf("\n\n\t\t\t    test of ");
    if (pos == 'N')
    { /* display screen */
      printf("nouns");
    }
    else if (pos == 'V')
    {
      printf("verbs");
    }
    else if (pos == 'O')
    {
      printf("other words");
    }
    else if (pos == 'A')
    {
      printf("all words");
    }
    if (lang1[0] == 'F')
    {
      printf("\n\n\n\n\n\n\n\n\n");
      printf("\t\t\t\t%s", spGe[wrdCntr].FOREIGN);
      printf("\n\n\n\n\n\n\n\n");
      printf(" What is the English translation > ");

      fgets(answer, sizeof(answer), stdin);
      answer[strcspn(answer, "\n")] = '\0';
      clearBuffer(); /* get user's answer and capitalize it */

      ltrCntr = 0;
      while (answer[ltrCntr] != '\0')
      {
        answer[ltrCntr] = toupper(answer[ltrCntr]);
        ltrCntr = ltrCntr + 1;
      }

      if (strcmp(answer, spGe[wrdCntr].Spanish) == 0)
      {
        printf("\n\nCongratulations. That is right.");
        printf("\nDo your want to try another (Y/N) > ");
        fgets(yorn, sizeof(yorn), stdin);
        yorn[strcspn(yorn, "\n")] = '\0';
        clearBuffer();

        if (toupper(yorn[0]) == 'N')
        {
          exit(0);
        }
      }
      else /* message for right or wrong answer */
      {
        spGe[wrdCntr].errorFlg = 1;
        retstFlg = 1;
        printf("\n\tThe correct answer is %s.", spGe[wrdCntr].Spanish);
        printf("\nDo you want to try another (Y/N) > ");
        fgets(yorn, sizeof(yorn), stdin);
        yorn[strcspn(yorn, "\n")] = '\0';
        clearBuffer();

        if (toupper(yorn[0]) == 'N')
        {
          exit(0);
        }
      }
      wrdCntr = wrdCntr + 1;
    }
    else /* English-FOREIGN */
    {
      printf("\n\n\n\n\n\n\n\n\n");
      printf("\t\t\t\t%s", spGe[wrdCntr].Spanish);
      printf("\n\n\n\n\n\n\n\n");
      printf("What is the FOREIGN translation > ");
      fgets(answer, sizeof(answer), stdin);
      answer[strcspn(answer, "\n")] = '\0';
      clearBuffer(); /* get user's answer and capitalize it */

      ltrCntr = 0;
      while (answer[ltrCntr] != '\0')
      {
        answer[ltrCntr] = toupper(answer[ltrCntr]);
        ltrCntr = ltrCntr + 1;
      }

      if (strcmp(answer, spGe[wrdCntr].FOREIGN) == 0)
      {
        printf("\n\nCongratulations. That is right.");
        printf("\nDo you want to try another (Y/N) > ");
        fgets(yorn, sizeof(yorn), stdin);
        yorn[strcspn(yorn, "\n")] = '\0';
        clearBuffer();

        if (toupper(yorn[0]) == 'N')
        {
          exit(0);
        }
      } /* message for right or wrong answer */
      else
      {
        spGe[wrdCntr].errorFlg = 1;
        retstFlg = 1;
        printf("\n\nNo, the correct answer is %s. ", spGe[wrdCntr].FOREIGN);
        printf("Do you want to try another (Y/N) ");
        fgets(yorn, sizeof(yorn), stdin);
        yorn[strcspn(yorn, "\n")] = '\0';
        clearBuffer();

        if (toupper(yorn[0]) == 'N')
        {
          exit(0);
        }
      }
      wrdCntr = wrdCntr + 1;
    }
  }
}

void clearBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }
}


