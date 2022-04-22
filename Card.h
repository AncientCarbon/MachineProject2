//
// Created by Anton on 4/21/2022.
//
#include <stdbool.h>
#ifndef MACHINEPROJECT2_CARD_H
#define MACHINEPROJECT2_CARD_H
struct Card* generateDeck();
void flipCard(struct Card*, bool);
enum suit;

struct Card{
    int index;
    bool shown;
    int value;
    char suit;
    struct Card* next;
    struct Card* previous;
};

#endif //MACHINEPROJECT2_CARD_H