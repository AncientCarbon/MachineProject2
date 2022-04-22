#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Card.h"


void printTable();
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
    if (cmd1 == 'L' && cmd2 == 'D'){
        file = fopen("C:\\Users\\bruger\\CLionProjects\\MachineProject2\\UnshuffledDeck.txt", "rt");
        rewind(file);
        if (file == NULL){
            printf("File not found");
        }
        else printf("File found");

        head = (struct Card *) malloc(sizeof(struct Card));
        fscanf(file, "%c%c", head->value, head->suit);
        head->shown = true;
        head->next = NULL;
        head->previous = NULL;
        prevCard = head;
        for (int i = 0; i < 51; i++){
            newCard = (struct Card *) malloc(sizeof(struct Card));
            newCard->previous = prevCard;
            prevCard->next = newCard;
            newCard->next = NULL;
            newCard->shown = true;
            fscanf(file, "%c%c", newCard->value, newCard->suit);
            prevCard = newCard;
        }

        newCard = head;
        for (int i = 0; i < 52; i++){
            printf("%c%c", newCard->value, newCard->suit);
            newCard = newCard->next;
        }
    }


    /*struct Card* head = generateDeck();
    //struct Card* sHead = shuffleDeck();

    struct Card* newCard = head;

    for (int i = 0; i < 52; i++){
        flipCard(newCard, true);
        newCard = newCard->next;
    }

    printTable(head);
    */

    return 0;
}


void printDeck(struct Card* head){
    struct Card* newCard = head;
    for (int i = 0; i < 52; i++){
        switch (newCard->suit){
            case(1): printf("%d of Clubs\n", newCard->value); break;
            case(2): printf("%d of Diamonds\n", newCard->value); break;
            case(3): printf("%d of Hearts\n", newCard->value); break;
            case(4): printf("%d of Spades\n", newCard->value); break;
        }
        newCard = newCard->next;
    }
}



void printTable(struct Card* head){

    struct Card* newCard = head;

    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");

    int rowNumber = 0;
    int lineNumber = 0;
    for (int i = 0; i < 52; i++){
        rowNumber++;
        if (!newCard->shown) printf("[]\t");
        else switch(newCard->value){
            case(1): printf("A%c\t", newCard->suit); break;
            case(10): printf("T%c\t", newCard->suit); break;
            case(11): printf("J%c\t", newCard->suit); break;
            case(12): printf("Q%c\t", newCard->suit); break;
            case(13): printf("K%c\t", newCard->suit); break;
            default: printf("%d%c\t", newCard->value, newCard->suit); break;
        }

        /*else switch (newCard->suit){
            case(1): {
                switch (newCard->value){
                    case(1): printf("AC\t"); break;
                    case(11): printf("JC\t"); break;
                    case(12): printf("QC\t"); break;
                    case(13): printf("KC\t"); break;
                    default: printf("%dC\t", newCard->value); break;
                }
                break;
            }
            case(2): {
                switch (newCard->value){
                    case(1): printf("AD\t"); break;
                    case(11): printf("JD\t"); break;
                    case(12): printf("QD\t"); break;
                    case(13): printf("KD\t"); break;
                    default: printf("%dD\t", newCard->value); break;
                }
                break;
            }
            case(3): {
                switch (newCard->value){
                    case(1): printf("AH\t"); break;
                    case(11): printf("JH\t"); break;
                    case(12): printf("QH\t"); break;
                    case(13): printf("KH\t"); break;
                    default: printf("%dH\t", newCard->value); break;
                }
                break;
            }
            case(4): {
                switch (newCard->value){
                    case(1): printf("AS\t"); break;
                    case(11): printf("JS\t"); break;
                    case(12): printf("QS\t"); break;
                    case(13): printf("KS\t"); break;
                    default: printf("%dS\t", newCard->value); break;
                }
                break;
            }
        }*/
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

/* struct Card* shuffleDeck(){
    struct Card* newCard;
    struct Card* head;
    struct Card* prevCard;

    int array[52];
    for (int i = 0; i < 52; i++){
        array[i] = i+1;
    }

    int index = 0;
    int value = array[0] % 14;


    head = (struct Card*)malloc(sizeof(struct Card));
    head->index = index;
    head->suit = suit;
    head->value = value;
    head->shown = 0;
    head->previous = NULL;
    head->next = NULL;

    int n = 52;

    // Source: https://benpfaff.org/writings/clc/shuffle.html
    size_t i;
    for (i = 0; i < n-1; i++){
        size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }

    for (int i = 0; i < 51; i++)

    return head;
}
*/