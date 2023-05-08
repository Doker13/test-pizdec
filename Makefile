all: main

main: main.o quizz_data.o quizz_create.o
	gcc -Wall -o main main.o quizz_data.o quizz_create.o
main.o: main.c
	gcc -Wall -c -o main.o main.c
quizz_data.o: quizz_data.c
	gcc -Wall -c -o quizz_data.o quizz_data.c
quizz_create.o: quizz_create.c
	gcc -Wall -c -o quizz_create.o quizz_create.c

clean: 
	rm *.o
