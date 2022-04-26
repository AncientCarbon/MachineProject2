//
// Created by Anton on 4/21/2022.
//
#include <stdbool.h>
#ifndef MACHINEPROJECT2_CARD_H
#define MACHINEPROJECT2_CARD_H
struct Card* generateDeck();
void flipCard(struct Card*);
void setCardShown(struct Card*, bool);

struct Card{
    int index;
    bool shown;
    char value;
    char suit;
    struct Card* next;
    struct Card* previous;
};

#endif //MACHINEPROJECT2_CARD_H
