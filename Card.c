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
    char value = 'A';
    char suit = 'C';
    int suitNr = 0;

    head = (struct Card*)malloc(sizeof(struct Card));
    head->index = index;
    head->suit = suit;
    head->value = value;
    head->shown = true;
    head->previous = NULL;
    head->next = NULL;
    prevCard = head;



    for (int i = 0; i < 51; i++) {
        index++;

        if (index % 13 == 0) {
            suitNr++;
            switch (suitNr){
                case(1): suit = 'D'; break;
                case(2): suit = 'H'; break;
                case(3): suit = 'S'; break;
                default: break;
            }
        }

        newCard = (struct Card *) malloc(sizeof(struct Card));
        newCard->shown = true;
        newCard->index = index;
        newCard->previous = prevCard;
        newCard->next = NULL;
        prevCard->next = newCard;
        prevCard = newCard;
        newCard->suit = suit;

        // value switch
        switch (index % 13){
            case (0): newCard->value = 'A'; break;
            case 1 ... 8: newCard->value = index%13 + 49; break; // ASCII værdier 50-57 giver digits 2-9.
            case (9): newCard->value = 'T'; break;
            case (10): newCard->value = 'J'; break;
            case (11): newCard->value = 'Q'; break;
            case (12): newCard->value = 'K'; break;
            default: newCard->value = '0';
        }

    }
    return head;
}

void flipCard(struct Card* newCard){
    if (newCard->shown) newCard->shown = false;
    else newCard->shown = true;
}

void setCardShown(struct Card* newCard, bool shown){
    newCard->shown = shown;
}


/*struct Card* shuffleDeck(){
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

    //------------------------------------------------------------------------------------------------------------------
    // Source: https://benpfaff.org/writings/clc/shuffle.html
    // Shuffles an array from 1-52
    //------------------------------------------------------------------------------------------------------------------
    size_t i;
    for (i = 0; i < n-1; i++){
        size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }

    return head;
}*/