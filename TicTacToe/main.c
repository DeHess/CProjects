#include <stdio.h>
#include <stdlib.h>
#ifdef __BORLANDC__ && __MSDOS__
    #include <conio.h>
#elif __WIN32 || _MSC_VER
    #define clrscr() system ("cls")
#endif // __BORLANDC__


    // DEKLARATION:
char spielfeld[3][3] = {
{'#','#','#'},
{'#','#','#'},
{'#','#','#'}
};
int zug = 0;
char marker = 'x';
int markiertesFeld = 0;

void paint () {
    printf("Spielfeld:\n");
    int i;
    for(i=0; i<3; i++) {
        int j;
        for(j=0; j<3; j++) {
            printf("%c ", spielfeld[i][j]);
        }
        printf("\n");
    }
}

void scan () {
    printf("Welches Feld soll markiert werden?\n");
    scanf("%d", &markiertesFeld);
    if (markiertesFeld > 9) {
            zug--;
    }
}

void feldMarkierer () {
        switch (markiertesFeld) {
            case 1:
                if (spielfeld[0][0] == '#') {
                    spielfeld[0][0] = marker;
                    break;
                } else {
                    zug--;
                    break;
                }
            case 2:
                if (spielfeld[0][1] == '#') {
                    spielfeld[0][1] = marker;
                    break;
                } else {
                    zug--;
                    break;
                }
            case 3:
                 if (spielfeld[0][2] == '#') {
                    spielfeld[0][2] = marker;
                    break;
                } else {
                    zug--;
                    break;
                }
            case 4:
                if (spielfeld[1][0] == '#') {
                    spielfeld[1][0] = marker;
                    break;
                } else {
                    zug--;
                    break;
                }
            case 5:
                if (spielfeld[1][1] == '#') {
                    spielfeld[1][1] = marker;
                    break;
                } else {
                    zug--;
                    break;
                }
            case 6:
                if (spielfeld[1][2] == '#') {
                    spielfeld[1][2] = marker;
                    break;
                } else {
                    zug--;
                    break;
                }
            case 7:
                if (spielfeld[2][0] == '#') {
                    spielfeld[2][0] = marker;
                    break;
                } else {
                    zug--;
                    break;
                }
            case 8:
                if (spielfeld[2][1] == '#') {
                    spielfeld[2][1] = marker;
                    break;
                } else {
                    zug--;
                    break;
                }
            case 9:
                if (spielfeld[2][2] == '#') {
                    spielfeld[2][2] = marker;
                    break;
                } else {
                    zug--;
                    break;
                }
            default:
                break;
        }
    }

void setMarker () {
    if (zug%2 == 0) {
    marker = 'x';
    printf("Spieler 1 ist am Zug\n");
    } else {
    marker = 'o';
    printf("Spieler 2 ist am Zug\n");
    }
}

void ticTacToe () {
    paint();
    while (1) {
    setMarker ();
    scan();
    feldMarkierer();
    system("cls");
    paint();
    zug++;
    }
}


int main()
{
    ticTacToe();
    return 0;
}

