#include <stdio.h>
#include <stdlib.h>

#include "quizz_data.h"

int main() {
  struct quizz *q = get_quiz(1);
  printf("%d. %s:\n%d. %s\n\n%c) %s %d\n", q->quizzNumber, q->quizzName,
         q->question[0].questionNumber, q->question[0].questionText,
         q->question[0].answerOptions[0].optionLetter,
         q->question[0].answerOptions[0].optionText,
         q->question[0].answerOptions[0].isAnswerRight);
  fill_data_with_quizz(q);
  free(q);
  return 0;
}
