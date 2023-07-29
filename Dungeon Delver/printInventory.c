#include "printInventory.h"
extern int dungeonSizeX;
extern int gold;
extern int hp;

void printInventory () {
    int i;
    for (i=0; i<dungeonSizeX; i++) {
        printf("=");
    }
    printf("\n");
    printf("Gold: %d \n", gold);
    printf("Hp: %d \n", hp);
}
