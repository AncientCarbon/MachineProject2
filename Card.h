//
// Created by Anton on 4/21/2022.
//
#include <stdbool.h>
#ifndef MACHINEPROJECT2_CARD_H
#define MACHINEPROJECT2_CARD_H
struct Card* generateDeck();
void flipCard(struct Card*);
void setCardShown(struct Card*, bool);
char getValue(int);
char getSuit(int);
struct Card* shuffleDeck();

struct Card{
    int index;
    bool shown;
    char value;
    char suit;
    struct Card* next;
    struct Card* previous;
};

struct CardArray{
    struct Card* head1;
    struct Card* head2;
    struct Card* head3;
    struct Card* head4;
    struct Card* head5;
    struct Card* head6;
    struct Card* head7;
    struct Card* f11head;
    struct Card* f22head;
    struct Card* f33head;
    struct Card* f44head;
};

#endif //MACHINEPROJECT2_CARD_H
