#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Card.h"


void PrintDeckAsTable(struct Card* head);
void showAllCards(struct Card* head);
struct CardArray* setupGame(struct Card* head);
void printCard(struct Card* card);
void printTable(struct Card* head1, struct Card* head2, struct Card* head3, struct Card* head4, struct Card* head5,
                struct Card* head6, struct Card* head7);
void saveDeck(struct Card* head);
void moveCards(struct Card* fromColumn, char cardValue, char cardSuit, struct Card* toColumn);
struct Card* getColumnAsHead(char in, struct CardArray* cardArray);

//struct Card* shuffleDeck();
int arrayGenerator();

int main() {
    srand(time(NULL));// seeder vores pseudo number generator
    rand(); // kalder rand for at fixe et problem med første kort der var det samme i nogle minutter.
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

        file = fopen("..\\UnshuffledDeck.txt", "rt"); // TODO: Prompt der spørger om filnavn
        if (file == NULL){
            printf("File not found, loading default deck\n\n");
            head = generateDeck();
        }
        else { // load decket fra en .txt fil

            printf("File found, loading deck...\n\n");
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

    struct Card* currentDeck = head;
    bool started = false;
    struct CardArray* cardArr;
    while (true){
        // dumpCmd is a bugfix. We don't know why, but the first char is a \n only half of the time.
        char dumpCmd;
        printf("Command: ");
        scanf("%c%c%c", &cmd1, &cmd2, &dumpCmd);
        if (cmd1 == '\n'){
            cmd1 = cmd2;
            cmd2 = dumpCmd;
        }

        // quit the program
        if (cmd1 == 'Q' && cmd2 == 'Q'){
            printf("Quitting program...\n");
            break;
        }

        // print the whole deck with all cards face-up
        else if (cmd1 == 'S' && cmd2 == 'W'){
            showAllCards(currentDeck);
            PrintDeckAsTable(currentDeck);
        }

        // shuffle all cards in interleaved manner
        else if (cmd1 == 'S' && cmd2 == 'I'){
            printf("Command not implemented\n");
        }

        // Shuffle all cards in a random manner
        else if (cmd1 == 'S' && cmd2 == 'R'){
            currentDeck = shuffleDeck();
            PrintDeckAsTable(currentDeck);
        }

        // Save game to speficied file from parameter
        else if (cmd1 == 'S' && cmd2 == 'D'){
            saveDeck(head);
            //printf("Command not implemented\n");
        }

        // Play the game using current deck
        else if (cmd1 == 'P' && cmd2 == '\n'){
            printf("Setting up game...\n\n");
            cardArr = setupGame(currentDeck);
            started = true;
        }
        else printf("Command not recognized\n");

        while (started){
            /*
             * TODO: GAME MOVES
             * format: <from> -> <to>
             * From example: If we have 4 of hearts in C6, and we want to move this card, we type:
             * C6:4H
             *
             * If we only type column, it will select the bottom card. Example: C6
             *
             * If we need to move something from foundation, we can only move the top card, so we type:
             * F1, F2, F3 or F4
             *
             * To example: If we want to move to a column, we type column name. Example:
             * C2
             *
             * If we want to move to foundation, we type the foundation name. Example:
             * F2
             *
             * A command will therefore have the input:
             * C7->F4
             * to move the bottom card of C7 to foundation F4
             *
             * If we want to move more cards, we can type:
             * C7:4C->C4
             * to move 4 of clubs and everything below to column C4
             *
             * ---------------------------------------------------------------------------------------------------------
             * TODO IMPORTANT: VALIDITY CHECK
             * ---------------------------------------------------------------------------------------------------------
             * If the move is illegal, a message should be printed: ERROR
             * If the move is valid, a message should be printed: OK
             *
             */

            char input[20];
            printf("Input: ");
            scanf("%s", input);
            printf("\n");
            if (input[0] == '\n'){
                int i = 1;
                while (input[i] != '\0') {
                    input[i-1] = input[i];
                    i++;
                }
            }
            if (input[0] == 'Q'){
                printf("Returning to startup phase...\n");
                currentDeck = shuffleDeck();
                started = false;
            }
            else {
                if (input[0] == 'C'){
                    switch (input[1]){
                        case ('1'): {
                            moveCards(cardArr->head1, input[4], input[5],
                                      getColumnAsHead(input[8], cardArr));
                            break;
                        }
                        case ('2'): {
                            moveCards(cardArr->head2, input[4], input[5],
                                      getColumnAsHead(input[8], cardArr));
                            break;
                        }
                        case ('3'): {
                            moveCards(cardArr->head3, input[4], input[5],
                                      getColumnAsHead(input[8], cardArr));
                            break;
                        }
                        case ('4'): {
                            moveCards(cardArr->head4, input[4], input[5],
                                      getColumnAsHead(input[8], cardArr));
                            break;
                        }
                        case ('5'): {
                            moveCards(cardArr->head5, input[4], input[5],
                                      getColumnAsHead(input[8], cardArr));
                            break;
                        }
                        case ('6'): {
                            moveCards(cardArr->head6, input[4], input[5],
                                      getColumnAsHead(input[8], cardArr));
                            break;
                        }
                        case ('7'): {
                            moveCards(cardArr->head7, input[4], input[5],
                                      getColumnAsHead(input[8], cardArr));
                            break;

                        }
                    }
                }
            }
        }
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

        printCard(newCard);

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

struct CardArray* setupGame(struct Card* origHead){
    struct Card* origNewCard = origHead;

    struct Card* row1head = origNewCard;
    origNewCard = origNewCard->next;
    row1head->next = NULL;
    row1head->previous = NULL;
    row1head->shown = true;
    struct Card* row1newCard;
    struct Card* row1prevCard = row1head;


    struct Card* row2head = origNewCard;
    origNewCard = origNewCard->next;
    row2head->next = NULL;
    row2head->previous = NULL;
    row2head->shown = false;
    struct Card* row2newCard;
    struct Card* row2prevCard = row2head;


    struct Card* row3head = origNewCard;
    origNewCard = origNewCard->next;
    row3head->next = NULL;
    row3head->previous = NULL;
    row3head->shown = false;
    struct Card* row3newCard;
    struct Card* row3prevCard = row3head;

    struct Card* row4head = origNewCard;
    origNewCard = origNewCard->next;
    row4head->next = NULL;
    row4head->previous = NULL;
    row4head->shown = false;
    struct Card* row4newCard;
    struct Card* row4prevCard = row4head;

    struct Card* row5head = origNewCard;
    origNewCard = origNewCard->next;
    row5head->next = NULL;
    row5head->previous = NULL;
    row5head->shown = false;
    struct Card* row5newCard;
    struct Card* row5prevCard = row5head;

    struct Card* row6head = origNewCard;
    origNewCard = origNewCard->next;
    row6head->next = NULL;
    row6head->previous = NULL;
    row6head->shown = false;
    struct Card* row6newCard;
    struct Card* row6prevCard = row6head;

    struct Card* row7head = origNewCard;
    origNewCard = origNewCard->next;
    row7head->next = NULL;
    row7head->previous = NULL;
    row7head->shown = false;
    struct Card* row7newCard;
    struct Card* row7prevCard = row7head;

    //Creating F1-F4 lists
    /* struct Card* F1head = origNewCard;
    origNewCard = origNewCard->next;

    F1head->next = NULL;
    F1head->previous = NULL;
    F1head->shown = false;
    struct Card* F1newCard;
    struct Card* F1prevCard = F1head;

    struct Card* F2head = origNewCard;
    origNewCard = origNewCard->next;

    F2head->next = NULL;
    F2head->previous = NULL;
    F2head->shown = false;
    struct Card* F2newCard;
    struct Card* F2prevCard = F2head;

    struct Card* F3head = origNewCard;
    origNewCard = origNewCard->next;

    F3head->next = NULL;
    F3head->previous = NULL;
    F3head->shown = false;
    struct Card* F3newCard;
    struct Card* F3prevCard = F3head;

    struct Card* F4head = origNewCard;
    origNewCard = origNewCard->next;

    F4head->next = NULL;
    F4head->previous = NULL;
    F4head->shown = false;
    struct Card* F4newCard;
    struct Card* F4prevCard = F4head; */




    int row2counter = 0;
    int row3counter = 0;
    int row4counter = 0;
    int row5counter = 0;
    int row6counter = 0;
    int row7counter = 0;
    for (int i = 0; i < 45; i++) {
        if (row2counter <5) {
            row2newCard = origNewCard;
            origNewCard = origNewCard->next;
            row2newCard->previous = row2prevCard;
            row2prevCard->next = row2newCard;
            row2newCard->next = NULL;
            row2newCard->shown = true;
            row2prevCard = row2newCard;
            row2counter++;
            i++;
        }
        if (row3counter < 6) {
            row3newCard = origNewCard;
            origNewCard = origNewCard->next;
            row3newCard->previous = row3prevCard;
            row3prevCard->next = row3newCard;
            row3newCard->next = NULL;
            if (row3counter < 1){
                row3newCard->shown = false;
            } else row3newCard->shown = true;
            row3prevCard = row3newCard;
            row3counter++;
            i++;
        }
        if (row4counter < 7) {
            row4newCard = origNewCard;
            origNewCard = origNewCard->next;
            row4newCard->previous = row4prevCard;
            row4prevCard->next = row4newCard;
            row4newCard->next = NULL;
            if (row4counter < 2){
                row4newCard->shown = false;
            } else row4newCard->shown = true;
            row4prevCard = row4newCard;
            row4counter++;
            i++;
        }
        if (row5counter < 8) {
            row5newCard = origNewCard;
            origNewCard = origNewCard->next;
            row5newCard->previous = row5prevCard;
            row5prevCard->next = row5newCard;
            row5newCard->next = NULL;
            if (row5counter < 3){
                row5newCard->shown = false;
            } else row5newCard->shown = true;
            row5prevCard = row5newCard;
            row5counter++;
            i++;
        }
        if (row6counter < 9) {
            row6newCard = origNewCard;
            origNewCard = origNewCard->next;
            row6newCard->previous = row6prevCard;
            row6prevCard->next = row6newCard;
            row6newCard->next = NULL;
            if (row6counter < 4){
                row6newCard->shown = false;
            } else row6newCard->shown = true;
            row6prevCard = row6newCard;
            row6counter++;
            i++;
        }
        row7newCard = origNewCard;
        origNewCard = origNewCard->next;
        row7newCard->previous = row7prevCard;
        row7prevCard->next = row7newCard;
        row7newCard->next = NULL;
        if (row7counter < 5){
            row7newCard->shown = false;
        } else row7newCard->shown = true;
        row7counter++;
        row7prevCard = row7newCard;

    }
    printTable(row1head, row2head, row3head, row4head, row5head, row6head, row7head);
    struct CardArray* arr;
    arr = (struct CardArray*)malloc(sizeof(struct CardArray));
    arr->head1 = row1head;
    arr->head2 = row2head;
    arr->head3 = row3head;
    arr->head4 = row4head;
    arr->head5 = row5head;
    arr->head6 = row6head;
    arr->head7 = row7head;
    /*arr->f11head = F1head;
    arr->f22head = F2head;
    arr->f33head = F3head;
    arr->f44head = F4head;*/


    return arr;
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

    while (row1 != NULL || row2 != NULL || row3 != NULL || row4 != NULL || row5 != NULL || row6 != NULL || row7 != NULL){
       if (row1 != NULL){
           printCard(row1);
           row1 = row1->next;
       } else printf("\t");

        if (row2 != NULL){
            printCard(row2);
            row2 = row2->next;
        } else printf("\t");

        if (row3 != NULL){
            printCard(row3);
            row3 = row3->next;
        } else printf("\t");

        if (row4 != NULL){
            printCard(row4);
            row4 = row4->next;
        } else printf("\t");

        if (row5 != NULL){
            printCard(row5);
            row5 = row5->next;
        } else printf("\t");

        if (row6 != NULL) {
            printCard(row6);
            row6 = row6->next;
        } else printf("\t");

        if (row7 != NULL) {
            printCard(row7);
            row7 = row7->next;
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

void saveDeck(struct Card* head){
    char deck[4*52];
    FILE* file;
    file = fopen("..\\Cards.txt", "w");
    if (file == NULL){
        printf("Error opening file.\n");
    }

    for (int i = 0; i < 52; i++){
        //deck[i]=head;
        printf("%c%c\n", head->value, head->suit);
        fprintf(file,"%c%c\n", head->value, head->suit);
        head = head->next;
    }

    fclose(file);
}

void moveCards(struct Card* fromColumn, char cardValue, char cardSuit, struct Card* toColumn){
    struct Card* fromColumnNewCard = fromColumn;
    struct Card* toColumnNewCard = toColumn;

    while (cardValue != fromColumnNewCard->value || cardSuit != fromColumnNewCard->suit) {

        fromColumnNewCard = fromColumnNewCard->next;
        if (fromColumnNewCard == NULL){
            printf("Error\n");
            return;
        }
    }

    while (toColumnNewCard->next != NULL){
        toColumnNewCard = toColumnNewCard->next;
    }
    fromColumnNewCard->previous->next = NULL;
    toColumnNewCard->next = fromColumnNewCard;
    fromColumnNewCard->previous = toColumnNewCard;


}

struct Card* getColumnAsHead(char in, struct CardArray* cardArray){

    // ASCII values 49-55 er 1-7
    int rowNr = (int) in;
    rowNr = rowNr-48; // trækker ascii værdi fra
    switch (rowNr){
        case(1): return cardArray->head1;
        case(2): return cardArray->head2;
        case(3): return cardArray->head3;
        case(4): return cardArray->head4;
        case(5): return cardArray->head5;
        case(6): return cardArray->head6;
        case(7): return cardArray->head7;
        default: printf("Error\n"); return 0;
    }
}