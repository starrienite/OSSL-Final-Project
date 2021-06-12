#include "header.h"

void printMenu(){
	printf("Please choose an option.\n");
	printf("\t1 Play Game\n");
	printf("\t2 Edit Game\n");
	printf("\t0 Exit Program\n");
	printf("\nEnter option: ");
}

void printBoard(char** catArray, int check[][5]){
	int i,j;

	printf("\n");
	for(i = 0; i < 5; i++){
		printf("%d %s\t", i+1, catArray[i]);
	}
	printf("\n");

	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			if(check[i][j] == 0){
				printf("%d\t\t", (i+1)*100);
			}
			else{
				printf("X\t\t");
			}
		}
		printf("\n");
	}
}

int askCat(){
	int out = -1;

	do{
		printf("Pick a Category or enter 0 to exit the game. (Enter number only.): ");
		scanf(" %d", &out);
		if(out < 0 || out > 5){
			printf("Invalid input. Please choose again.\n");
		}
	}while(out < 0 || out > 5);

	return out-1;
}

int askQ(){
	int out = -1;

	do{
		printf("Pick a Question. (Enter point-value number only): ");
		scanf(" %d", &out);
		if((out < 100 || out > 500) && (out % 100 != 0)){
			printf("Invalid input. Please choose again. \n");
		}
	}while((out < 100 || out > 500) && (out % 100 != 0));

	return (out/100)-1;
}

void printOptions(){
	printf("\nPress 1 to see the answer, or 0 to exit game: ");
}

void editBoard(){
    printf("\nPlease choose an editing option.\n");
    printf("\t1 Change a category\n");
    printf("\t2 Change a question\n");
    printf("\t3 Return to main menu");
    printf("\t0 Exit Program\n");
    printf("\nEnter option: ");
}

void endGame(char** catArray, char* qArray[5][5], char* aArray[5][5]){
    int i, j;

    for(i = 0; i < 5; i++){
        free(catArray[i]);
        for(j = 0; j < 5; j++){
            free(qArray[i][j]);
            free(aArray[i][j]);
        }
    }

    exit(0);
}
