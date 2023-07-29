#include "enemyMovement.h"
#include <stdbool.h>

extern int dungeonSizeX;
extern int dungeonSizeY;
extern int posX;
extern int posY;
extern char dungeon[20][40];

int monsterLocX[];
int monsterLocY[];
int monsterAmount = 0;
int startY;
int endY;

void scanMonster () {
    int i, j;
    for (i=0; i<dungeonSizeY; i++) {
        for (j=0; j<dungeonSizeX; j++) {
            if (dungeon[i][j] == 'S') {
                monsterLocX[monsterAmount] = j;
                monsterLocY[monsterAmount] = i;
                monsterAmount++;
            }
        }
    }
}

bool wallCheckY (int start, int end, int x) {
    int i;
    for (i=start; i<end; i++) {
        if (dungeon[i][x] == '#') {
            return true;

        } else {
            return false;
        }
    }
}


void startEndY (int posY, int monsterLocY) {
    if (posY < monsterLocY) {
        startY = posY;
        endY = monsterLocY;
    }
    if (posY > monsterLocY) {
        startY = monsterLocY;
        endY = posY;
    }
}


bool lineOfSight (int index) {
    if (posX == monsterLocX[index]) {
        return true;
    }
    else {
        return false;
    }
}

//movemonster
//check if Monster on the same y Axis as Player
//check if no Wall between Player and Monster
//move Monster 1 closer to player


//Hit check
// if playerPos == MonsterPos hp--
// Gaahwffaad<//for (I=0; i<99; i++) {amonsterAmount++;
//monstlOcY[]}
