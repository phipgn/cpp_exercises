#include <stdio.h>

int main()
{
    int x, y;
    for (x = 1; x < 20; x++) {
        if (3*x % 4) continue;
        if ((y = 25 - 1.75*x) < 0) continue;
        printf("(%d, %d, %d)\n", x, y, 6*x + 3*y);
    }
    return 0;
}
