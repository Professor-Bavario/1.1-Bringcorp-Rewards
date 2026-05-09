#include <stdio.h>
#include "main.h"

// TODO: Adjust modifiers and values
unsigned int score = -1;
char username[1];

// For the tester - do not touch!
size_t usernameSize = sizeof(username);

void calcUsername () {
    // TODO: Prompt the user to enter their username,
    // store it and calculate points!

}

void calcBirthday () {
    // TODO: Prompt the user to enter their birthday
    // and calculate points!

}

void calcDonations () {
    // TODO: Prompt the user to enter their total donation money
    // and calculate points!

}

void calcMembership () {
    // TODO: Ask the user about their membership status
    // and how long they have been a member for
    // and calculate points!

}

#ifndef TESTER
int main () {
    printf("Welcome to Bringcorp Rewards!\nHere at Bringcorp's Content Ethics Board, viewer satisfaction is our #1 priority.\nAnd we want to offer this Rewards program as a thanks!\nTake a minute to enter your personal information.\nFor any inquiry, please reach out to contentethicsboard@gmail.com.\n\n");
    calcUsername();
    calcBirthday();
    calcDonations();
    calcMembership();
    // TODO: Print the score and tell the user about the perks they can get
    return 0;
}
#endif