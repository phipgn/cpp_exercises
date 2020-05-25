#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    
    int gcd = a, lcm = a;
    while (a % gcd || b % gcd) gcd--;
    while (lcm % a || lcm % b) lcm++;
    
    printf("USCLN(a, b): %d\n", gcd);
    printf("BSCNN(a, b): %d\n", lcm);

    return 0;
}
