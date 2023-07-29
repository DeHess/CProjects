#include <stdio.h>
#include <stdlib.h>

int seed = 53;



int main()
{


    while (1) {
        seed = (seed + 977) % 199;
        printf("%d\n", seed%50);
        sleep(1);
    }

    return 0;
}
