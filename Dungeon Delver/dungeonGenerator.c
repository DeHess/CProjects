#include "dungeonGenerator.h"
#include <stdbool.h>

extern int roomAmount;
extern int bigRoomAmount;
extern int dungeonSizeX;
extern int dungeonSizeY;
extern int randomHallwaysAmount;
extern int posX;
extern int posY;
extern char dungeon[20][40];


void generateHallways() {
    int posSpacesX[roomAmount+bigRoomAmount];
    int posSpacesY[roomAmount+bigRoomAmount];
    int i, j, a;
    int roomNumber = 0;
    for (i=0; i<dungeonSizeY; i++) {
        for (j=0; j<dungeonSizeX; j++) {
            if (dungeon[i][j] == 'j' || dungeon[i][j] == 'q') {
                 posSpacesX[roomNumber] = j;
                 posSpacesY[roomNumber] = i;
                 roomNumber++;
            }
        }
    } // roomNumber-1 hallways generieren
    for (a=0; a<roomNumber-1; a++) {
        int xDif = posSpacesX[a+1] - posSpacesX[a];
        int yDif = posSpacesY[a+1] - posSpacesY[a];
        int q, w, t;
        if (xDif > 0) {
            for (q=1; q<=xDif; q++) {
            dungeon[posSpacesY[a]][posSpacesX[a]+q] = 'e';
            }
        }
        if (xDif < 0) {
            for (w=-1; w>=xDif; w--) {
            dungeon[posSpacesY[a]][posSpacesX[a]+w] = 'e';
            }
        }
        for (t=1; t<yDif; t++) {
            dungeon[posSpacesY[a]+t][posSpacesX[a+1]] = 'e';
        }
    }
}

void generateChests() {
    int i, j;
    for (i=0; i<dungeonSizeY; i++) {
        for (j=0; j<dungeonSizeX; j++) {
            if (dungeon[i][j] == 't' && (rand()%51)<2) {
                dungeon[i][j] = 'C';
            }
        }
    }
}


void generateRandomHallways () {
    int posSpacesX[roomAmount+bigRoomAmount];
    int posSpacesY[roomAmount+bigRoomAmount];
    int i, j, a;
    int roomNumber = 0;
    for (i=0; i<dungeonSizeY; i++) {
        for (j=0; j<dungeonSizeX; j++) {
            if (dungeon[i][j] == 'j' || dungeon[i][j] == 'q') {
                 posSpacesX[roomNumber] = j;
                 posSpacesY[roomNumber] = i;
                 roomNumber++;
            }
        }
    } //randomHallwaysAmount hallways generieren
    for (a=0; a<randomHallwaysAmount; a++) {


    }


}

void generateRoomPlacement () {
    int i;
    for (i=0; i<roomAmount; i++) {
        dungeon[rand()%(dungeonSizeY-1)%4*5+2][rand()%(dungeonSizeX-1)%8*5+2] = 'j';
    }
}

void regenerateWalls () {
    int i, j;
    for (i=0; i<dungeonSizeY; i++) {
        for (j=0; j<dungeonSizeX; j++) {
            if (i == 0 || i == dungeonSizeY-1 || j == 0 || j == dungeonSizeX-1) {
                dungeon[i][j] = '#';
            }
        }
    }
}

void generateRooms () {
    int i, j, l, p;
    for (i=0; i<dungeonSizeY; i++) {
        for (j=0; j<dungeonSizeX; j++) {
            if (dungeon[i][j] == 'j') {
                dungeon[i-1][j-1] = 't';
                dungeon[i-1][j]  = 's';
                dungeon[i-1][j+1] = 't';
                dungeon[i][j-1]  = 's';
                dungeon[i][j+1] = 's';
                dungeon[i+1][j-1] = 't';
                dungeon[i+1][j]  = 's';
                dungeon[i+1][j+1] = 't';
            }
        }
    }
}


void replacePlaceholders() {
    int q,p;
    for (q=0; q<dungeonSizeY; q++) {
        for (p=0; p<dungeonSizeX; p++) {
            if (dungeon[q][p] == 'e'|| dungeon[q][p]== 't' || dungeon[q][p]== 'j' || dungeon[q][p]== 'q' || dungeon[q][p]== 'u' || dungeon[q][p]== 's') {
                dungeon[q][p] = ' ';
            }
       }
    }
}

void generateBigRoomPlacement () {
    int i;
    for (i=0; i<bigRoomAmount; i++) {
        dungeon[rand()%(dungeonSizeY-2)%4*5+2][rand()%(dungeonSizeX-3)+3] = 'q';
    }
}

void generateBigRooms () {
    int i, j;
    for (i=0; i<dungeonSizeY; i++) {
        for (j=0; j<dungeonSizeX; j++) {
            if (dungeon[i][j] == 'q') {

                dungeon[i-2][j-3] = 'u';
                dungeon[i-1][j-3] = 'u';
                dungeon[i][j-3] = 'u';
                dungeon[i+1][j-3] = 'u';
                dungeon[i+2][j-3] = 'u';

                dungeon[i-2][j-2] = 'u';
                dungeon[i-1][j-2] = '#';
                dungeon[i][j-2] = 'u';
                dungeon[i+1][j-2] = '#';
                dungeon[i+2][j-2] = 'u';

                dungeon[i-2][j-1] = 'u';
                dungeon[i-1][j-1] = 'u';
                dungeon[i][j-1] = 'u';
                dungeon[i+1][j-1] = 'u';
                dungeon[i+2][j-1] = 'u';

                dungeon[i-2][j] = 'u';
                dungeon[i-1][j] = 'u';
                dungeon[i+1][j] = 'u';
                dungeon[i+2][j] = 'u';

                dungeon[i-2][j+1] = 'u';
                dungeon[i-1][j+1] = 'u';
                dungeon[i][j+1] = 'u';
                dungeon[i+1][j+1] = 'u';
                dungeon[i+2][j+1] = 'u';

                dungeon[i-2][j+2] = 'u';
                dungeon[i-1][j+2] = '#';
                dungeon[i][j+2] = 'u';
                dungeon[i+1][j+2] = '#';
                dungeon[i+2][j+2] = 'u';

                dungeon[i-2][j+3] = 'u';
                dungeon[i-1][j+3] = 'u';
                dungeon[i][j+3] = 'u';
                dungeon[i+1][j+3] = 'u';
                dungeon[i+2][j+3] = 'u';
            }
        }
    }
}

void generateExit() {
    int i, j;
    bool k = false;
    while (!k) {
        for (i=0; i<dungeonSizeY; i++) {
            for (j=0; j<dungeonSizeX; j++) {
                if (dungeon[i][j] == 's' && (rand()%51)<2 && k==false) {
                    dungeon[i][j] = 'E';
                    k = true;
                }
            }
        }
    }
}

void generateMonsters() {
    int i, j;
    for (i=0; i<dungeonSizeY; i++) {
        for (j=0; j<dungeonSizeX; j++) {
            if (dungeon[i][j] == 'u'  && (rand()%51)<2) {
                dungeon[i][j] = 'S';
            }
        }
    }

}

void generatePotions() {
        int i, j;
    for (i=0; i<dungeonSizeY; i++) {
        for (j=0; j<dungeonSizeX; j++) {
            if (dungeon[i][j] == 'u'  && (rand()%51)<2) {
                dungeon[i][j] = 'R';
            }
        }
    }
}

void dungeonGenerator () {
    generateRoomPlacement();
    generateBigRoomPlacement();
    generateRooms();
    generateBigRooms();
    generateHallways();
    generateChests();
    generateExit();
    generateMonsters();
    generatePotions();
    replacePlaceholders();
    regenerateWalls();
}
