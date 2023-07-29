#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#ifdef __BORLANDC__ && __MSDOS__
    #include <conio.h>
#elif __WIN32 || _MSC_VER
    #define clrscr() system ("cls")
#endif // __BORLANDC__


char solutionWord[100];
char displayWord[100];
int allowedMistakes = 6;


void printTitle () {



printf(" _    _   \n");
printf("| |  | |  \n");
printf("| |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __      \n");
printf("|  __  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\     \n");
printf("| |  | | (_| | | | | (_| | | | | | | (_| | | | |    \n");
printf("|_|  |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|    \n");
printf("                     __/ |                          \n");
printf("                    |___/                           \n");


    printf("\n \n            Press Space to continue\n \n");

    char pressSpace;
    do {
        pressSpace = getch();
    } while (pressSpace != ' ');

}

void scanSolutionWord() {
    printf("Type in solution: ");
    scanf("%s", solutionWord);
}

int lenSolutionWord() {
    int solutionLength;
    solutionLength = strlen(solutionWord);
    return solutionLength;
}

void generateDisplayWord (int solutionLength) {
    int i;
    for (i=0; i<solutionLength; i++) {
        displayWord[i] = '_';
    }
    displayWord[solutionLength] = '\0';
}

char scannedLetter () {
    printf("what letter do you wish to try?\n");
    char scannedLetter;
    scannedLetter = getch();
    return scannedLetter;
}

bool replaceLetter (char scannedLetter, int solutionLength) {
    bool match = false;
    int i;
    for (i=0; i<solutionLength; i++) {
        if (scannedLetter == solutionWord[i]) {
            displayWord[i] = scannedLetter;
            match = true;
        }
    }
    if (match == true) {
        printf("You found the letter %s!", &scannedLetter);
    }
    if (match == false) {
        allowedMistakes--;
        printf("The letter %s does not exists in the word!", &scannedLetter);
    }
    return match;
}

bool defeatCondition () {
    bool lose = false;
    if (allowedMistakes == 0) {
        lose = true;

    }
    return lose;
}

bool victoryCondition () {
    bool win = false;
    if( strcmp(displayWord, solutionWord) == 0)
    {
        win = true;

    }
    return win;
}

void paintGallows () {
    switch (allowedMistakes) {
        case 6:
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("___|___ \n\n");
            break;

        case 5:
            printf("\n");
            printf("   | \n");
            printf("   | \n");
            printf("   | \n");
            printf("   | \n");
            printf("   | \n");
            printf("   | \n");
            printf("___|___ \n\n");
            break;

        case 4:
            printf("   _________\n");
            printf("   | \n");
            printf("   | \n");
            printf("   | \n");
            printf("   | \n");
            printf("   | \n");
            printf("   | \n");
            printf("___|___ \n\n");
            break;

        case 3:
            printf("   _________\n");
            printf("   |/ \n");
            printf("   | \n");
            printf("   | \n");
            printf("   | \n");
            printf("   | \n");
            printf("   | \n");
            printf("___|___ \n\n");
            break;

        case 2:
            printf("   _________\n");
            printf("   |/      |    \n");
            printf("   |            \n");
            printf("   |            \n");
            printf("   |            \n");
            printf("   |            \n");
            printf("   |            \n");
            printf("___|___ \n\n");
            break;

        case 1:
            printf("   _________\n");
            printf("   |/      |   \n");
            printf("   |      (_)  \n");
            printf("   |      \\|/  \n");
            printf("   |            \n");
            printf("   |            \n");
            printf("   |            \n");
            printf("___|___ \n\n");
            break;

        case 0:
            printf("   _________\n");
            printf("   |/      |\n");
            printf("   |      (_)\n");
            printf("   |      \\|/\n");
            printf("   |       |\n");
            printf("   |      / \\ \n");
            printf("   | \n");
            printf("___|___ \n\n");
            break;

        default:
            break;
    }

}

void endScreen (bool defeatCondition) {
    if (defeatCondition == true) {
        printf("   _________\n");
        printf("   |/      |\n");
        printf("   |      (_)\n");
        printf("   |      \\|/\n");
        printf("   |       |\n");
        printf("   |      / \\ \n");
        printf("   | \n");
        printf("___|___ \n\n");
    } else {
        printf(" __      ___      _                   \n");
        printf(" \\ \\    / (_)    | |                  \n");
        printf("  \\ \\  / / _  ___| |_ ___  _ __ _   _ \n");
        printf("   \\ \\/ / | |/ __| __/ _ \\| '__| | | |\n");
        printf("    \\  /  | | (__| || (_) | |  | |_| |\n");
        printf("     \\/   |_|\\___|\\__\\___/|_|   \\__, |\n");
        printf("                                 __/ |\n");
        printf("                                |___/ \n");
    }
}




void printUsedChars(char scannedLetter, int solutionLength, bool match) {
    char usedVariables[solutionLength];
    int counter = 0;


}

int main()
{
    printTitle();
    system("cls");
    scanSolutionWord();
    generateDisplayWord(lenSolutionWord());
    system("cls");



    while (!victoryCondition() && !defeatCondition()) {
    paintGallows();
    printf("Word: %s \n", &displayWord);
    printf("mistakes left:%d \n", allowedMistakes);
    //printUsedChars(scannedLetter(), lenSolutionWord(), replaceLetter());
    replaceLetter(scannedLetter(), lenSolutionWord());

    Sleep(2000);
    system("cls");





    }
    endScreen(defeatCondition());
    Sleep(10000);

    return 0;
}
