#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Card.h"


void PrintDeckAsTable(struct Card* head);
void showAllCards(struct Card* head);
void setupGame(struct Card* head);
void printCard(struct Card* card);
void printTable(struct Card* head1, struct Card* head2, struct Card* head3, struct Card* head4, struct Card* head5,
                struct Card* head6, struct Card* head7);

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
        if (file == NULL){
            printf("File not found, loading default deck\n\n");
            head = generateDeck();
        }
        else {

            printf("File found\n\n");
            head = (struct Card *) malloc(sizeof(struct Card));
            head->shown = false;
            head->next = NULL;
            head->previous = NULL;
            prevCard = head;
            fgets(line, 4, file);

            // line er et char array som fgets læser information ind i.
            // Derfor kaldes line[0] og line[1]
            head->value = line[0];
            head->suit = line[1];

            while (fgets(line, 4, file) != NULL){
                newCard = (struct Card *) malloc(sizeof(struct Card));
                newCard->previous = prevCard;
                prevCard->next = newCard;
                newCard->next = NULL;
                newCard->shown = false;
                newCard->value = line[0];
                newCard->suit = line[1];
                prevCard = newCard;
            }
        }
    }

    while (true){
        char dumpCmd;
        printf("Command: ");
        scanf("%c%c%c", &cmd1, &cmd2, &dumpCmd);
        if (cmd1 == '\n'){
            cmd1 = cmd2;
            cmd2 = dumpCmd;
        }
        if (cmd1 == 'Q' && cmd2 == 'Q'){
            printf("Quitting program...\n");
            break;
        }
        else if (cmd1 == 'S' && cmd2 == 'W'){
            showAllCards(head);
            PrintDeckAsTable(head);
            printf("");
        }
        else if (cmd1 == 'S' && cmd2 == 'I'){
            printf("Command not implemented\n");
        }
        else if (cmd1 == 'S' && cmd2 == 'R'){
            printf("Command not implemented\n");
        }
        else if (cmd1 == 'S' && cmd2 == 'D'){
            printf("Command not implemented\n");
        }
        else if (cmd1 == 'P' && cmd2 == '\n'){
            printf("Setting up game...\n\n");
            setupGame(head);

        }
        else if (cmd1 == 'Q' && cmd2 == '\n'){
            printf("Command not implemented\n");
        }
        else printf("Command not recognized\n");
    }

    return 0;
}


void PrintDeckAsTable(struct Card* head){

    struct Card* newCard = head;

    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");

    int rowNumber = 0;
    int lineNumber = 0;
    for (int i = 0; i < 52; i++){
        rowNumber++;
        if (!newCard->shown) printf("[]\t");
        else printCard(newCard);

        if (rowNumber == 7){
            lineNumber++;
            if (lineNumber % 2 == 1 && lineNumber <= 8) printf("\t\t[]\tF%d", (lineNumber/2)+1);

            printf("\n");
            rowNumber = 0;
        }
        newCard = newCard->next;
    }
    printf("\n\n\n");
}

void showAllCards(struct Card* head){
    struct Card* newCard = head;
    for (int i = 0; i < 52; i++){
        newCard->shown = true;
        newCard = newCard->next;
    }
}

void setupGame(struct Card* origHead){
    struct Card* origNewCard = origHead;

    struct Card* row1head = origNewCard;
    origNewCard = origNewCard->next;
    row1head->next = NULL;
    row1head->previous = NULL;
    struct Card* row1newCard;
    struct Card* row1prevCard = row1head;



    struct Card* row2head = origNewCard;
    origNewCard = origNewCard->next;
    row2head->next = NULL;
    row2head->previous = NULL;
    struct Card* row2newCard;
    struct Card* row2prevCard = row2head;


    struct Card* row3head = origNewCard;
    origNewCard = origNewCard->next;
    row3head->next = NULL;
    row3head->previous = NULL;
    struct Card* row3newCard;
    struct Card* row3prevCard = row3head;

    struct Card* row4head = origNewCard;
    origNewCard = origNewCard->next;
    row4head->next = NULL;
    row4head->previous = NULL;
    struct Card* row4newCard;
    struct Card* row4prevCard = row4head;

    struct Card* row5head = origNewCard;
    origNewCard = origNewCard->next;
    row5head->next = NULL;
    row5head->previous = NULL;
    struct Card* row5newCard;
    struct Card* row5prevCard = row5head;

    struct Card* row6head = origNewCard;
    origNewCard = origNewCard->next;
    row6head->next = NULL;
    row6head->previous = NULL;
    struct Card* row6newCard;
    struct Card* row6prevCard = row6head;

    struct Card* row7head = origNewCard;
    origNewCard = origNewCard->next;
    row7head->next = NULL;
    row7head->previous = NULL;
    struct Card* row7newCard;
    struct Card* row7prevCard = row7head;


    int row2counter = 0;
    int row3counter = 0;
    int row4counter = 0;
    int row5counter = 0;
    int row6counter = 0;
    for (int i = 0; i < 45; i++) {
        if (row2counter <6) {
            row2newCard = origNewCard;
            origNewCard = origNewCard->next;
            row2newCard->previous = row2prevCard;
            row2prevCard->next = row2newCard;
            row2newCard->next = NULL;
            row2prevCard = row2newCard;
            row2counter++;
            i++;
        }
        if (row3counter < 7) {
            row3newCard = origNewCard;
            origNewCard = origNewCard->next;
            row3newCard->previous = row3prevCard;
            row3prevCard->next = row3newCard;
            row3newCard->next = NULL;
            row3prevCard = row3newCard;
            row3counter++;
            i++;
        }
        if (row4counter < 8) {
            row4newCard = origNewCard;
            origNewCard = origNewCard->next;
            row4newCard->previous = row4prevCard;
            row4prevCard->next = row4newCard;
            row4newCard->next = NULL;
            row4prevCard = row4newCard;
            row4counter++;
            i++;
        }
        if (row5counter < 9) {
            row5newCard = origNewCard;
            origNewCard = origNewCard->next;
            row5newCard->previous = row5prevCard;
            row5prevCard->next = row5newCard;
            row5newCard->next = NULL;
            row5prevCard = row5newCard;
            row5counter++;
            i++;
        }
        if (row6counter < 10) {
            row6newCard = origNewCard;
            origNewCard = origNewCard->next;
            row6newCard->previous = row6prevCard;
            row6prevCard->next = row6newCard;
            row6newCard->next = NULL;
            row6prevCard = row6newCard;
            row6counter++;
            i++;
        }
        row7newCard = origNewCard;
        origNewCard = origNewCard->next;
        row7newCard->previous = row7prevCard;
        row7prevCard->next = row7newCard;
        row7newCard->next = NULL;
        row7prevCard = row7newCard;

    }
    printTable(row1head, row2head, row3head, row4head, row5head, row6head, row7head);

}

void printTable(struct Card* head1, struct Card* head2, struct Card* head3, struct Card* head4, struct Card* head5,
        struct Card* head6, struct Card* head7){
    struct Card* row1 = head1;
    struct Card* row2 = head2;
    struct Card* row3 = head3;
    struct Card* row4 = head4;
    struct Card* row5 = head5;
    struct Card* row6 = head6;
    struct Card* row7 = head7;

    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");

    int lineCounter = 1;
    for (int i = 0; i < 52; i++){
        if (row1 != NULL){
            printCard(row1);
            row1 = row1->next;
            i++;
        } else printf("\t");
        if (row2 != NULL){
            printCard(row2);
            row2 = row2->next;
            i++;
        } else printf("\t");
        if (row3 != NULL){
            printCard(row3);
            row3 = row3->next;
            i++;
        } else printf("\t");
        if (row4 != NULL){
            printCard(row4);
            row4 = row4->next;
            i++;
        } else printf("\t");
        if (row5 != NULL){
            printCard(row5);
            row5 = row5->next;
            i++;
        } else printf("\t");
        if (row6 != NULL) {
            printCard(row6);
            row6 = row6->next;
            i++;
        } else printf("\t");
        if (row7 != NULL) {
            printCard(row7);
            row7 = row7->next;
            i++;
        } else printf("\t");
        if (lineCounter % 2 == 1 && (lineCounter/2) < 4) printf("\t\t[] F%d", (lineCounter/2)+1);
        printf("\n");
        lineCounter++;
    }

}
void printCard(struct Card* card){
    if (!card->shown){
        printf("[]\t");
    }
    else printf("%c%c\t", card->value, card->suit);
}