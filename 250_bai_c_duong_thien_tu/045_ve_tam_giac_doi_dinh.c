#include <stdio.h>

int main()
{
    int n;
    printf("n=");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++, putchar('\n'))
        for (int j = 0; j < n; j++)
            (j > i && j < n - 1 - i) || (j > n - 1 - i && j < i) ? printf("  ") : printf("%d ", j + 1);

    return 0;
}
