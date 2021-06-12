#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int MAXLEN = 200;

int main(){
    int user_option = -1;
    int pick_cat = -1;
    int pick_q = -1;
    int edit_option = -1;
    char input[100];
    int i, j;

    //default game
    char * category[5];
    category[0] = malloc(20);
    category[1] = malloc(20);
    category[2] = malloc(20);
    category[3] = malloc(20);
    category[4] = malloc(20);
    strcpy(category[0], "Bible Trivia");
    strcpy(category[1], "Simple Math");
    strcpy(category[2], "Prof Trivia");
    strcpy(category[3], "Capitals");
    strcpy(category[4], "HGU Campus");

    char * q_buffer[5][5] = {
        {"Name the 4 Gospels.", "What was Jesus' first miracle?", "How many brothers did Joseph have?", "Who is the mother of John the Baptist?", "Who is the oldest man to have ever lived?"},
        {"0 + 0 = ?", "12 + 77 = ", "194 - 39 = ?", "57 * 3 = ", "812 * 46 = ?"},
        {"Name a Carmichael Professor.", "What is PG short for?", "Where is Professor Cawood from?", "What is the name of PG's wife?", "What are the names of Professor Bailey's children?"},
        {"What is the capital of the USA?", "What is the capital of China?", "What is the capital of Germany?", "What is the capital of Vietnam?", "What is the capital of Egypt?"},
        {"Which building has God's University written on it?", "What is the name of the chapel building?", "What is the name of the newest building?", "What does HIS stand for?", "What is the name of the building behind ANH?"}
    };
    char * questions[5][5];
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            questions[i][j] = malloc(MAXLEN);
            strcpy(questions[i][j], q_buffer[i][j]);
        }
    };

    char * a_buffer[5][5] = {
        {"Matthew, Mark, Luke, John", "Turning water into wine", "11", "Elizabeth", "Methuselah"},
        {"0", "89", "155", "171", "37352"},
        {"Grace Kim, Keturah Haferkamp, Bryan Alkema, John Shin, Amber Montouri, Craig Smith, John Bailey, John Choi, Mark Buzby, Christenson Low, Anthony Cawood, or Megan Cawood", "Pastor Greg", "South Africa", "Tara", "Tim and Esther"},
        {"Washington, DC", "Beijing", "Berlin", "Hanoi", "Cairo"},
        {"Hyundong Hall", "Hyoam Chapel", "Papyrus Basket Hall", "Handong International School", "The Ark building"}
    };
    char * answers[5][5];
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            answers[i][j] = malloc(MAXLEN);
            strcpy(answers[i][j], a_buffer[i][j]);
        }
    };

    int check[5][5] = {{0}};
    
    do{
        printMenu();
        scanf(" %d", &user_option);

        switch(user_option){
            case 0:
                endGame(category, questions, answers);
                break;

            //play game
            case 1:
                do{
                    printBoard(category, check);
                    pick_cat = askCat();
                    if(pick_cat == -1){
                        endGame(category, questions, answers);
                    }
                    pick_q = askQ();
                    if(check[pick_q][pick_cat] != -1){
                        printf("\n %s - %d: %s\n", category[pick_cat], (pick_q+1)*100, questions[pick_cat][pick_q]);
                        check[pick_q][pick_cat] = -1;
                        printOptions();
			scanf(" %d", &user_option);
                        do{
                            if(user_option == 0){
                                endGame(category, questions, answers);
                            }
                            else if (user_option == 1){
                                printf("The answer is: %s\n\n", answers[pick_cat][pick_q]);
                            }
                            else{
                                printf("Invalid input. Please enter again: ");
                                printOptions();
                            }
                        }while(user_option != 0 && user_option != 1);
                    }
                    else{
                        printf("\nThis question was already played before. Please pick a new question.\n\n");
                    }
                }while(user_option != 0);
                break;

            //edit game    
            case 2:
                do{
                    printBoard(category, check);
                    editBoard();
                    scanf(" %d", &edit_option);
                    switch(edit_option){
                        case 0:
                            endGame(category, questions, answers);
                            break;
                        case 1:
                            pick_cat = askCat();
                            if(pick_cat == -1){
                                exit(0);
                            }
                            printf("Enter new category: ");
                            scanf(" %[^\n]%*c", input);
                            strcpy(category[pick_cat], input);
                            printf("Category changed. New Category: %d %s\n", pick_cat+1, category[pick_cat]);
                            break;
                        case 2:
                            pick_cat = askCat();
                            if(pick_cat == -1){
                                endGame(category, questions, answers);
                            }
                            pick_q = askQ();
                            printf("Enter the new question: ");
                            scanf(" %[^\n]%*c", input);
                            strcpy(questions[pick_cat][pick_q], input);
                            printf("Enter its answer: ");
                            scanf(" %[^\n]%*c", input);
                            strcpy(answers[pick_cat][pick_q], input);
                            printf("Question changed.\n \tNew question: %s - %d -> %s\n \tIts answer: %s\n", category[pick_cat], (pick_q+1)*100, questions[pick_cat][pick_q], answers[pick_cat][pick_q]);
                            break;
                        case 3:
                            user_option = -1;
                            edit_option = 0;
                            break;
                    }
                }while(edit_option != 0);
                break;
        }
    }while(user_option != 0);
    
    return 0;
}
