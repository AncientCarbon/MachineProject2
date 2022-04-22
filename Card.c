//
// Created by Anton on 4/21/2022.
//

#include "Card.h"
#include <stdlib.h>

struct Card* generateDeck(){
    struct Card* newCard;
    struct Card* head;
    struct Card* prevCard;
    //------------------------------------------------------------------------------------------------------------------
    // Suit 1 = Clubs (C)
    // Suit 2 = Diamonds (D)
    // Suit 3 = Hearts (H)
    // Suit 4 = Spades (S)
    //------------------------------------------------------------------------------------------------------------------

    int index = 0;
    int value = 1;
    char suit = 'C';
    int suitNr = 0;

    head = (struct Card*)malloc(sizeof(struct Card));
    head->index = index;
    head->suit = suit;
    head->value = value;
    head->shown = 0;
    head->previous = NULL;
    head->next = NULL;
    prevCard = head;



    for (int i = 0; i < 51; i++) {
        index++;
        value++;
        if (value > 13) {
            value = 1;
            suitNr++;
            switch (suitNr){
                case(1): suit = 'D'; break;
                case(2): suit = 'H'; break;
                case(3): suit = 'S'; break;
                default: break;
            }
        }
        newCard = (struct Card *) malloc(sizeof(struct Card));
        newCard->shown = false;
        newCard->index = index;
        newCard->previous = prevCard;
        newCard->next = NULL;
        prevCard->next = newCard;
        prevCard = newCard;
        newCard->suit = suit;
        newCard->value = value;
    }
    return head;
}

void flipCard(struct Card* newCard, bool in){
    newCard->shown = in;
}

void loadFile(){

}