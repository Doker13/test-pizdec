#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib/quizz_create.h>
#include <lib/quizz_data.h>
#include <lib/quizz_run.h>

int amount_of_quizzes() {
  char *file = "data/quizz_data.csv";
  FILE *fp = fopen(file, "r");
  if (!fp) {
    return -1;
  }
  int qNumber;
  int qMaxNumber = 0;
  char endSeeker;
  while (fscanf(fp, "%d,", &qNumber) == 1) {
    if (qNumber > qMaxNumber) {
      qMaxNumber = qNumber;
    }
    while (1) {
      fscanf(fp, "%c", &endSeeker);
      if (endSeeker == '\n') {
        break;
      }
    }
  }
  fclose(fp);
  return qMaxNumber;
}

struct quizz *get_quiz(int qNumber) {
  char *file = "data/quizz_data.csv";
  FILE *fp = fopen(file, "r");
  if (!fp) {
    return NULL;
  }
  struct quizz *q;
  q = malloc(sizeof(*q));

  q->quizzNumber = qNumber;

  qNumber -= 1;
  int number;
  while (fscanf(fp, "%d ,", &number) != 0) {
    if (number == q->quizzNumber) {
      char name[100];
      fscanf(fp, "%s ,%d ,", name, &number);
      if (!q->quizzName[0]) {
        for (int i = 0; name[i] != '\0'; i++) {
          q->quizzName[i] = name[i];
        }
      }
      q->question[qNumber].questionNumber = number;
      char letter;
      fscanf(fp, "%s ,%c ,", q->question[qNumber].questionText, &letter);
      if (letter >= 65 && letter <= 75) {
        q->question[qNumber].answerOptions[letter - 65].optionLetter = letter;
        fscanf(fp, "%s ,%d",
               q->question[qNumber].answerOptions[letter - 65].optionText,
               &q->question[qNumber].answerOptions[letter - 65].isAnswerRight);
      } else {
        return NULL;
      }
    } else {
      char endSeeker;
      while (1) {
        fscanf(fp, "%c", &endSeeker);
        if (endSeeker == '\n') {
          break;
        }
      }
    }
  }
  fclose(fp);
  return q;
}

int fill_data_with_quizz(struct quizz *q) {
  char *file = "data/quizz_data.csv";
  FILE *fp = fopen(file, "a");
  if (!fp) {
    return -1;
  }
  for (int i = 1; strlen(q->question[i].questionText); i++) {
    for (int j = 1; strlen(q->question[i].answerOptions[j].optionText); j++) {
      fprintf(fp, "%d ,%s ,%d ,%s ,%c ,%s ,%d\n", q->quizzNumber, q->quizzName,
              q->question[i].questionNumber, q->question[i].questionText,
              q->question[i].answerOptions[j].optionLetter,
              q->question[i].answerOptions[j].optionText,
              q->question[i].answerOptions[j].isAnswerRight);
    }
  }
  fclose(fp);
  return 0;
}

struct user *get_user_data(char *userName, int quizzNum) {
  char *file = "data/user_data.csv";
  FILE *fp = fopen(file, "r");
  if (!fp) {
    return NULL;
  }
  char name[100];
  int percent;
  int number;
  struct user *user = malloc(sizeof(*user));
  while (fscanf(fp, "%s ,%d ,%d", name, &number, &percent) != 0) {
    if (strcmp(name, userName) == 0 && number == quizzNum) {
      strcpy(user->username, name);
      user->quizzNum = number;
      user->passPercentage = percent;
      return user;
    }
  }
  free(user);
  return NULL;
}

int fill_data_with_user_data(struct user *user) {
  char *file = "data/user_data.csv";
  FILE *fp = fopen(file, "a");
  if (!fp) {
    return -1;
  }
  fprintf(fp, "%s ,%d ,%d\n", user->username, user->quizzNum, user->passPercentage);
  return 0;
}
