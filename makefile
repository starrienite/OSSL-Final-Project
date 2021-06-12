run: functions.o main.o
	gcc -g  -o run functions.o main.o -lm
functions.o: functions.c
	gcc -g -c -o functions.o functions.c
main.o:
	gcc -g -c -o main.o main.c
