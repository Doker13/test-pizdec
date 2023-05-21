#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib/quizz_create.h>
#include <lib/quizz_data.h>
#include <lib/quizz_run.h>

int main() {
  struct user *usr = get_user_data("Pasha", 12);
  printf("%s %d %d%%\n", usr->username, usr->quizzNum, usr->passPercentage);
  
  fill_data_with_user_data(usr);
  free(usr);
  return 0;
}
