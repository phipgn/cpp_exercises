#include <stdio.h>

int main()
{
    int n;
    printf("n=");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++, putchar('\n'))
        for (int j = 0; j <= n - 1 + i; j++)
            j < (n - 1 - i) ? printf("  ") : printf("* ");
    
    for (int i = 0; i < n; i++, putchar('\n'))
        for (int j = 0; j <= n - 1 + i; j++)
            j == (n - 1 - i) || (j == n - 1 + i) || (i == n - 1) ? printf("* ") : printf("  ");

    return 0;
}
