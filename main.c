#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Card.h"


void printTable(struct Card* head);
//struct Card* shuffleDeck();
int arrayGenerator();


int main() {
    struct Card* head;
    struct Card* newCard;
    struct Card* prevCard;

    char cmd1;
    char cmd2;

    printf("Command: ");
    scanf("%c%c", &cmd1, &cmd2);

    FILE * file;
    char line[5];
    if (cmd1 == 'L' && cmd2 == 'D'){
        file = fopen("..\\UnshuffledDeck.txt", "rt");
        int cur_line = 1; //sat til 1 pga head der bliver lavet uden for loop
        if (file == NULL){
            printf("File not found, loading default deck\n\n");
            head = generateDeck();
        }
        else {

            printf("File found\n\n");
            head = (struct Card *) malloc(sizeof(struct Card));
            head->shown = true;
            head->next = NULL;
            head->previous = NULL;
            prevCard = head;
            fgets(line, 4, file);
            //sscanf(line, "%c%c\n", head->value, head->suit);
            head->value = line[0];
            head->suit = line[1];

            while (fgets(line, 4, file) != NULL){
                newCard = (struct Card *) malloc(sizeof(struct Card));
                newCard->previous = prevCard;
                prevCard->next = newCard;
                newCard->next = NULL;
                newCard->shown = true;
                newCard->value = line[0];
                newCard->suit = line[1];
                prevCard = newCard;
                cur_line++;
            }
        }

        printTable(head);
    }

    return 0;
}


void printTable(struct Card* head){

    struct Card* newCard = head;

    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");

    int rowNumber = 0;
    int lineNumber = 0;
    for (int i = 0; i < 52; i++){
        rowNumber++;
        if (!newCard->shown) printf("[]\t");
        else printf("%c%c\t", newCard->value, newCard->suit);

        if (rowNumber == 7){
            lineNumber++;
            if (lineNumber % 2 == 1) printf("\t\t[]\tF%d", (lineNumber/2)+1);

            printf("\n");
            rowNumber = 0;
        }
        newCard = newCard->next;
    }
    printf("\n\n\n");
}