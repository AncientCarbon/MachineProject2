#include <stdio.h>
#include <stdlib.h>

void generateDeck();
void printDeck();
struct Card{
    int shown;
    int value;
    int suit;
    struct Card* next;
    struct Card* previous;

};
struct Card* newCard;
struct Card* head;
struct Card* tail;
struct Card* prevCard;

int main() {
    // allocate 3 nodes in the heap
    generateDeck();
    printDeck();


    return 0;
}

void generateDeck(){

    //------------------------------------------------------------------------------------------------------------------
    // Suit 1 = Clubs (C)
    // Suit 2 = Diamonds (D)
    // Suit 3 = Hearts (H)
    // Suit 4 = Spades (S)
    //------------------------------------------------------------------------------------------------------------------

    int value = 1;
    int suit = 1;

    head = (struct Card*)malloc(sizeof(struct Card));
    head->suit = suit;
    head->value = value;
    head->previous = NULL;
    head->next = NULL;



    for (int i = 0; i < 51; i++) {
        value++;
        if (value > 13) {
            value = 1;
            suit++;
        }
        newCard = (struct Card *) malloc(sizeof(struct Card));

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
