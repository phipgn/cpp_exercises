#include <stdio.h>

int main()
{
    int hours;
    scanf("%d", &hours);
    
    int w = hours / 168;
    int d = (hours % 168) / 24;
    int h = (hours % 168) % 24;
    
    printf("weeks=%d, days=%d, hours=%d", w, d, h);

    return 0;
}
