#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>

#define EXERCISE_CHAPTER 1
#define EXERCISE_NUM 1

#define LINE_END "\x1b[0m\n"
#define COLOR_RED "\x1b[31m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_GREEN "\x1b[32m"
#define CHECK "\xE2\x9C\x93"
#define CROSS "\xE2\x9C\x96"

#ifdef VS
    #define NEWLINE "\n"
#else
    #define NEWLINE "\n"
#endif

typedef bool(*bool_func)();

#define IS_UNSIGNED(x) (((typeof(x)) -1) > 0)

#include "main.h"

// Capture printf calls

bool capturePrintf = true;
char printFormatBuf[5000];
int test_printf (const char *format, ...) {
    va_list printfList;
    va_start(printfList, format);
    if (capturePrintf) {
        snprintf(printFormatBuf, 5000, "%s", format);
    }
    va_end(printfList);
    return 0;
}

// Capture scanf calls

va_list scanfList;
void(*scanf_runTest)(const char *, va_list);
int test_scanf (const char *format, ...) {
    va_start(scanfList, format);
    scanf_runTest(format, scanfList);
    return 0;
}

// Tests section

bool hasFailed = false;

void dummyFunc (const char *format, va_list args) {
    
}

bool isExistScore () {
    if (score != 0) {
        fprintf(stdout, COLOR_RED CROSS " Your score does not have the default value of 0." LINE_END);
        return false;
    }
    return true;
    /*if (!IS_UNSIGNED(score)) {
        fprintf(stdout, COLOR_RED CROSS " Your score can become negative." LINE_END);
        return false;
    }*/
}

bool isExistUsername () {
    if (usernameSize < 256) {
        fprintf(stdout, COLOR_RED CROSS " You do not allocate enough space for username." LINE_END);
        return false;
    }
    return true;
}

bool isUsernameCorrectPrint () {
    capturePrintf = true;
    calcUsername();
    if (strcmp(printFormatBuf, "Please enter your username (max 255 characters):\n")) {
        fprintf(stdout, COLOR_RED CROSS " Incorrect print statement." LINE_END);
        return false;
    }
    return true;
}

void isUsernameReadCorrect_part2 (const char *format, va_list args) {
    if (strcmp(format, "%255s")) {
        fprintf(stdout, COLOR_RED CROSS " Incorrect scanf format string." LINE_END);
        hasFailed = true;
    } else {
        snprintf(va_arg(args, char *), usernameSize, "%s", "Bavario");
        va_end(args);
    }
}

bool isUsernameReadCorrect_part1 () {
    scanf_runTest = isUsernameReadCorrect_part2;
    calcUsername();
    if (!hasFailed && score != 7) {
        fprintf(stdout, COLOR_RED CROSS " Score is incorrect (expected 7, got %u)." LINE_END, score);
        return false;
    }
    return !hasFailed;
}

void isLongUsernameReadCorrect_part2 (const char *format, va_list args) {
    if (strcmp(format, "%255s")) {
        fprintf(stdout, COLOR_RED CROSS " Incorrect scanf format string." LINE_END);
        hasFailed = true;
    } else {
        snprintf(va_arg(args, char *), usernameSize, "BringlesCanToadsbottomTheFourthOfBringcordThisIsAVeryLongUserNameOnOPurposeToTestTheBufferSizeWeHaveALongWayToGoSoIfYouAreSomehowSomewayReadingThisThenHelloHowIsYourDayAreYouDoingGoodYesThisIsStillGoingIAmGettingTiredOfTypingButAlmostThereAstronotterLikesStickerStar");
        va_end(args);
    }
}

bool isLongUsernameReadCorrect_part1 () {
    scanf_runTest = isLongUsernameReadCorrect_part2;
    calcUsername();
    if (!hasFailed && score != 255) {
        fprintf(stdout, COLOR_RED CROSS " Score is incorrect (expected 255, got %u)." LINE_END, score);
        return false;
    }
    return !hasFailed;
}

void isBirthdayReadCorrect_part2 (const char *format, va_list args) {
    if (strcmp(format, "%d/%d/%d") && strcmp(format, "%u/%u/%u")) {
        fprintf(stdout, COLOR_RED CROSS " Incorrect scanf format string." LINE_END);
        hasFailed = true;
    } else {
        *va_arg(args, int *) = 2006;
        *va_arg(args, int *) = 9;
        *va_arg(args, int *) = 14;
        va_end(args);
    }
}

bool isBirthdayReadCorrect_part1 () {
    capturePrintf = true;
    scanf_runTest = isBirthdayReadCorrect_part2;
    calcBirthday();
    if (strcmp(printFormatBuf, "Please enter your birthday (YYYY/MM/DD):\n")) {
        fprintf(stdout, COLOR_RED CROSS " Incorrect print statement." LINE_END);
        return false;
    }
    if (!hasFailed && score != 1014) {
        fprintf(stdout, COLOR_RED CROSS " Score is incorrect (expected 1014, got %u)." LINE_END, score);
        return false;
    }
    return !hasFailed;
}

bool isDonationCorrectPrint () {
    capturePrintf = true;
    calcDonations();
    if (strcmp(printFormatBuf, "Please enter the total money you donated to Bringle in USD:\n")) {
        fprintf(stdout, COLOR_RED CROSS " Incorrect print statement." LINE_END);
        return false;
    }
    return true;
}

void isDonationReadCorrect_part2 (const char *format, va_list args) {
    if (strcmp(format, "%f")) {
        fprintf(stdout, COLOR_RED CROSS " Incorrect scanf format string." LINE_END);
        hasFailed = true;
    } else {
        *va_arg(args, float *) = 15.5f;
        va_end(args);
    }
}

bool isDonationReadCorrect_part1 () {
    scanf_runTest = isDonationReadCorrect_part2;
    calcDonations();
    if (!hasFailed && score != 16) {
        fprintf(stdout, COLOR_RED CROSS " Score is incorrect (expected 16, got %u)." LINE_END, score);
        return false;
    }
    return !hasFailed;
}

void isBigDonationReadCorrect_part2 (const char *format, va_list args) {
    if (strcmp(format, "%f")) {
        fprintf(stdout, COLOR_RED CROSS " Incorrect scanf format string." LINE_END);
        hasFailed = true;
    } else {
        *va_arg(args, float *) = 100.5f;
        va_end(args);
    }
}

bool isBigDonationReadCorrect_part1 () {
    scanf_runTest = isBigDonationReadCorrect_part2;
    calcDonations();
    if (!hasFailed && score != 100) {
        fprintf(stdout, COLOR_RED CROSS " Score is incorrect (expected 100, got %u)." LINE_END, score);
        return false;
    }
    return !hasFailed;
}

void isMembershipCorrectPrint_part2 (const char *format, va_list args) {
    if (strcmp(printFormatBuf, "Are you a Bringle Crisp (C) or Bringle Stack (S) member or neither (N)?\n")) {
        fprintf(stdout, COLOR_RED CROSS " Incorrect first print statement." LINE_END);
        hasFailed = true;
    }
    *va_arg(args, char *) = 'C';
    va_end(args);
    scanf_runTest = dummyFunc;
}

bool isMembershipCorrectPrint_part1 () {
    capturePrintf = true;
    scanf_runTest = isMembershipCorrectPrint_part2;
    calcMembership();
    if (strcmp(printFormatBuf, "How many months have you been a member?\n")) {
        fprintf(stdout, COLOR_RED CROSS " Incorrect second print statement." LINE_END);
        return false;
    }
    return true;
}

void isCrispMemberReadCorrect_part3 (const char *format, va_list args) {
    if (strcmp(format, "%d") && strcmp(format, "%u")) {
        fprintf(stdout, COLOR_RED CROSS " Incorrect scanf format string." LINE_END);
        hasFailed = true;
    } else {
        *va_arg(args, int *) = 3;
        va_end(args);
    }
}

void isCrispMemberReadCorrect_part2 (const char *format, va_list args) {
    if (strcmp(format, " %c")) {
        fprintf(stdout, COLOR_RED CROSS " Incorrect scanf format string." LINE_END);
        hasFailed = true;
    } else {
        *va_arg(args, char *) = 'C';
        scanf_runTest = isCrispMemberReadCorrect_part3;
        va_end(args);
    }
}

bool isCrispMemberReadCorrect_part1 () {
    scanf_runTest = isCrispMemberReadCorrect_part2;
    calcMembership();
    if (!hasFailed && score != 1500) {
        fprintf(stdout, COLOR_RED CROSS " Score is incorrect (expected 1500, got %u)." LINE_END, score);
        return false;
    }
    return !hasFailed;
}

void isStackMemberReadCorrect_part3 (const char *format, va_list args) {
    if (strcmp(format, "%d") && strcmp(format, "%u")) {
        fprintf(stdout, COLOR_RED CROSS " Incorrect scanf format string." LINE_END);
        hasFailed = true;
    } else {
        *va_arg(args, int *) = 5;
        va_end(args);
    }
}

void isStackMemberReadCorrect_part2 (const char *format, va_list args) {
    if (strcmp(format, " %c")) {
        fprintf(stdout, COLOR_RED CROSS " Incorrect scanf format string." LINE_END);
        hasFailed = true;
    } else {
        *va_arg(args, char *) = 'S';
        scanf_runTest = isStackMemberReadCorrect_part3;
        va_end(args);
    }
}

bool isStackMemberReadCorrect_part1 () {
    scanf_runTest = isStackMemberReadCorrect_part2;
    calcMembership();
    if (!hasFailed && score != 5000) {
        fprintf(stdout, COLOR_RED CROSS " Score is incorrect (expected 5000, got %u)." LINE_END, score);
        return false;
    }
    return !hasFailed;
}

void isNothingMemberReadCorrect_failed (const char *format, va_list args) {
    fprintf(stdout, COLOR_RED CROSS " Second scanf after 'N' was entered." LINE_END);
    hasFailed = true;
}

void isNothingMemberReadCorrect_part2 (const char *format, va_list args) {
    if (strcmp(format, " %c")) {
        fprintf(stdout, COLOR_RED CROSS " Incorrect scanf format string." LINE_END);
        hasFailed = true;
    } else {
        *va_arg(args, char *) = 'N';
        scanf_runTest = isNothingMemberReadCorrect_failed;
        va_end(args);
    }
}

bool isNothingMemberReadCorrect_part1 () {
    scanf_runTest = isNothingMemberReadCorrect_part2;
    calcMembership();
    if (!hasFailed && score != 0) {
        fprintf(stdout, COLOR_RED CROSS " Score is incorrect (expected 0, got %u)." LINE_END, score);
        return false;
    }
    return !hasFailed;
}

void isInvalidMemberReadCorrect_failed (const char *format, va_list args) {
    fprintf(stdout, COLOR_RED CROSS " Second scanf after invalid input was entered." LINE_END);
    hasFailed = true;
}

void isInvalidMemberReadCorrect_part2 (const char *format, va_list args) {
    if (strcmp(format, " %c")) {
        fprintf(stdout, COLOR_RED CROSS " Incorrect scanf format string." LINE_END);
        hasFailed = true;
    } else {
        *va_arg(args, char *) = '3';
        scanf_runTest = isInvalidMemberReadCorrect_failed;
        va_end(args);
    }
}

bool isInvalidMemberReadCorrect_part1 () {
    scanf_runTest = isInvalidMemberReadCorrect_part2;
    calcMembership();
    if (!hasFailed && score != 0) {
        fprintf(stdout, COLOR_RED CROSS " Score is incorrect (expected 0, got %u)." LINE_END, score);
        return false;
    }
    return !hasFailed;
}

// Running section

typedef struct {
    const char *name;
    bool_func func;
    bool stopIfFail;
} Test;

Test tests[] = {
    {"Score Type Check", isExistScore, false},
    {"Username Type Check", isExistUsername, true},
    {"Username Print Message", isUsernameCorrectPrint, false},
    {"Username Score Check", isUsernameReadCorrect_part1, false},
    {"Long Username Score Check", isLongUsernameReadCorrect_part1, false},
    {"Birthday Score Check", isBirthdayReadCorrect_part1, false},
    {"Donation Print Message", isDonationCorrectPrint, false},
    {"Donation Score Check", isDonationReadCorrect_part1, false},
    {"Large Donation Score Check", isBigDonationReadCorrect_part1, false},
    {"Membership Print Message", isMembershipCorrectPrint_part1, false},
    {"Bringle Crisp Membership Score Check", isCrispMemberReadCorrect_part1, false},
    {"Bringle Stack Membership Score Check", isStackMemberReadCorrect_part1, false},
    {"No Membership Score Check", isNothingMemberReadCorrect_part1, false},
    {"Invalid Input for Membership Check", isInvalidMemberReadCorrect_part1, false}
};

int main () {
    fprintf(stdout, "Testing your implementation of exercise %d.%d...\n\n", EXERCISE_CHAPTER, EXERCISE_NUM);
    unsigned int totalTests = sizeof(tests) / sizeof(Test);
    unsigned int successfulTests = 0;
    for (int i = 0; i < totalTests; i++) {
        Test curTest = tests[i];
        fprintf(stdout, "Running test %d: %s\n", i, curTest.name);
        if (curTest.func()) {
            successfulTests++;
            fprintf(stdout, COLOR_GREEN CHECK " Success!" LINE_END);
        } else if (curTest.stopIfFail) {
            fprintf(stdout, COLOR_RED "Aborted." LINE_END "\n");
            break;
        }
        score = 0;
        capturePrintf = false;
        hasFailed = false;
        scanf_runTest = dummyFunc;
        fprintf(stdout, "\n");
    }
    float success = successfulTests * 100.0f / totalTests;
    if (success < 40.0f) 
        fprintf(stdout, COLOR_RED);
    else if (success < 80.0f) 
        fprintf(stdout, COLOR_YELLOW);
    else 
        fprintf(stdout, COLOR_GREEN);
    fprintf(stdout, "\n%.1f%% success [%d/%d tests succeeded]" LINE_END, success, successfulTests, totalTests);
    fprintf(stdout, "[Press Enter to quit.]");
    getchar();
    return 0;
}