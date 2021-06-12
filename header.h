#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu();
void printBoard(char** catArray, int check[][5]);
int askCat();
int askQ();
void printOptions();
void editBoard();
void endGame(char** catArray, char* qArray[5][5], char* aArray[5][5]);
