#pragma once

#include <lib/quizz_create.h>
#include <lib/quizz_data.h>
#include <lib/quizz_run.h>

int amount_of_quizzes();
struct quizz* get_quiz(int qNumber);
int fill_data_with_quizz(struct quizz* q);
struct user* get_user_data(char *userName, int quizzNum);
int fill_data_with_user_data(struct user *user);
