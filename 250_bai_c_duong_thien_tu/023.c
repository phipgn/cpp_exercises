#include <stdio.h>

int isPerfectNumber(int n) {
    int sum = 0;
    for (int i = 1; i <= n/2; i++)
        if (n % i == 0)
            sum += i;
    return sum == n ? 1 : 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    for (int i = 2; i < n; i++)
        if (isPerfectNumber(i))
            printf("%d ", i);

    return 0;
}
