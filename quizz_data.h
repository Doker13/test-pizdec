#pragma once

struct answerOptions {
  char optionLetter;
  char optionText[100];
  int isAnswerRight;
};
typedef struct answerOptions answerOptions;

struct question {
  int questionNumber;
  char questionText[100];
  answerOptions answerOptions[10];
};
typedef struct question question;

struct quizz {
  int quizzNumber;
  char quizzName[100];
  question question[100];
};

int amount_of_quizzes();
struct quizz *get_quiz(int qNumber);
int fill_data_with_quizz(struct quizz *q);
