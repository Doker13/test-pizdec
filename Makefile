all: main

main: main.o quizz_data.o
	gcc -Wall -o main main.o quizz_data.o
main.o: main.c
	gcc -Wall -c -o main.o main.c
quizz_data.o: quizz_data.c
	gcc -Wall -c -o quizz_data.o quizz_data.c

clean: 
	rm *.o
