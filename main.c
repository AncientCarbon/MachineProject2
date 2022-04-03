#include <stdio.h>
#include <stdlib.h>


void generateDeck();
void printTable();
void flipCard();

struct Card{
    int index;
    int shown;
    int value;
    int suit;
    struct Card* next;
    struct Card* previous;

};
struct Card* newCard;
struct Card* head;
struct Card* prevCard;

int main() {
    generateDeck();

    newCard = head->next->next->next->next;
    flipCard(1);

    printTable();

    return 0;
}

void generateDeck(){

    //------------------------------------------------------------------------------------------------------------------
    // Suit 1 = Clubs (C)
    // Suit 2 = Diamonds (D)
    // Suit 3 = Hearts (H)
    // Suit 4 = Spades (S)
    //------------------------------------------------------------------------------------------------------------------

    int index = 0;
    int value = 1;
    int suit = 1;

    head = (struct Card*)malloc(sizeof(struct Card));
    head->index = index;
    head->suit = suit;
    head->value = value;
    head->shown = 0;
    head->previous = NULL;
    head->next = NULL;



    for (int i = 0; i < 51; i++) {
        index++;
        value++;
        if (value > 13) {
            value = 1;
            suit++;
        }
        newCard = (struct Card *) malloc(sizeof(struct Card));
        newCard->shown = 0;
        newCard->index = index;
        if (suit == 1 && value == 2) {
            newCard->previous = head;
            newCard->next = NULL;
            head->next = newCard;
            prevCard = newCard;
        } else {
            newCard->previous = prevCard;
            newCard->next = NULL;
            prevCard->next = newCard;
            prevCard = newCard;
        }
        newCard->suit = suit;
        newCard->value = value;
    }


}

void printDeck(){
    newCard = head;
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

void flipCard(int in){
    newCard->shown = in;
}

void printTable(){
    newCard = head;
    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");
    int rowNumber = 0;
    int lineNumber = 0;
    for (int i = 0; i < 52; i++){
        rowNumber++;
        if (newCard->shown == 0) printf("[]\t");
        else switch (newCard->suit){
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
        }
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
