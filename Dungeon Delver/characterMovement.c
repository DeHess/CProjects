#include "charMovement.h"
#include <stdbool.h>

extern int dungeonSizeX;
extern int dungeonSizeY;
extern int posX;
extern int posY;
extern char dungeon[20][40];
extern char savedChar;
extern char savedSwordChar;
extern bool exittt;
extern int gold;
extern int hp;
extern int hpmax;


void keyInput () {
    char input=getch();
    switch (input) {
        case 'w':
            dungeon[posY][posX] = savedChar;
            if (dungeon[posY-1][posX] == '#' || dungeon[posY-1][posX] == 'G') {break;}
            interaction(posY-1, posX);
            posY--;
            break;
        case 'a':
            dungeon[posY][posX] = savedChar;
            if (dungeon[posY][posX-1] == '#' || dungeon[posY][posX-1] == 'G') {break;}
            interaction (posY, posX-1);
            posX--;
            break;
        case 's':
            dungeon[posY][posX] = savedChar;
            if (dungeon[posY+1][posX] == '#' || dungeon[posY+1][posX] == 'G') {break;}
            interaction(posY+1, posX);
            posY++;
            break;
        case 'd':
            dungeon[posY][posX] = savedChar;
            if (dungeon[posY][posX+1] == '#' || dungeon[posY][posX+1] == 'G') {break;}
            interaction(posY, posX+1);
            posX++;
            break;


        default:
            break;
    }
}

void interaction (int y, int x) {
    if (dungeon[y][x] == 'L') {removeGate();}
    if (dungeon[y][x] == 'C') {openChest();}
    if (dungeon[y][x] == 'S') {fightMonster();}
    if (dungeon[y][x] == 'E') {exittt = true;}
    if (dungeon[y][x] == 'R') {drinkPotion();}
    savedChar = dungeon[y][x];
    if (savedChar == 'S' || savedChar == 'C' || savedChar == 'E' || savedChar == 'R') {savedChar = ' ';}
}

void firstCharPlacement() {
    int i, j;
    bool k = false;
    for (i=0; i<dungeonSizeY; i++) {
        for (j=0; j<dungeonSizeX; j++) {
            if (dungeon[i][j] == ' ' && !k){
                posX = j+1;
                posY = i+1;
                k = true;
            }
        }
    }
}


void removeChar () {
    dungeon[posY][posX] = ' ';
}

void placeChar () {
    dungeon[posY][posX] = 'P';
}

int trackCharX () {
    int i, j;
    for (i=0; i<dungeonSizeY; i++) {
        for (j=0; j<dungeonSizeX; j++) {
            if (dungeon[i][j] == 'P') {
                return j;
            }
        }
    }
}

int trackCharY () {
    int i, j;
    for (i=0; i<dungeonSizeY; i++) {
        for (j=0; j<dungeonSizeX; j++) {
            if (dungeon[i][j] == 'P') {
                return i;
            }
        }
    }
}


void fightMonster () {
    gold = gold + rand()%50;
    hp = hp - rand()%50;
}

void openChest() {
    gold = gold + rand()%50;
}

void removeGate() {
    int i, j;
    for (i=0; i<dungeonSizeY; i++) {
        for (j=0; j<dungeonSizeX; j++) {
            if (dungeon[i][j] == 'G') {
                dungeon[i][j] = ' ';
            }
        }
    }
}

void drinkPotion() {
    hp = hp+rand()%30;
    if (hp > hpmax) {
        hp = hpmax;
    }
}
