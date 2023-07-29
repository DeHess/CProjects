#include "dungeonPainter.h"

extern int dungeonSizeX;
extern int dungeonSizeY;
extern char dungeon[20][40];


void blankDungeon() {
    int i, j;
    for (i=0; i<dungeonSizeY; i++) {
        for (j=0; j<dungeonSizeX; j++) {
            dungeon[i][j] = '#';
        }
    }
}

void paintDungeon () {
    int i, j;
    for (i=0; i<dungeonSizeY; i++) {
        for (j=0; j<dungeonSizeX; j++) {
            switch (dungeon[i][j]) {
                case '#': // Wall
                    printf("█");
                    break;

                case ' ': //empty space
                    printf(" ");
                    break;

                case 'P': // Player
                    printf("ʘ");
                    break;

                case 'G': //Gate
                    printf("▓");
                    break;

                case 'L': //Lever to open Gate
                    printf("L");
                    break;

                case 'C': //Chest
                    printf("ϖ");
                    break;

                case 'S': //Snake Monster
                    printf("Ѯ");
                    break;

                case 'c': //room corner
                    printf(" ");
                    break;

                case 's': //room side
                    printf("s");
                    break;

                case 'E': //Exit
                    printf("E");
                    break;

                case 'R': //Exit
                    printf("ѳ");
                    break;
            }
        }
        printf("\n");
    }
}
