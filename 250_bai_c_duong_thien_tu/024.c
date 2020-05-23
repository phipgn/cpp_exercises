#include <stdio.h>

double pow(x, y) {
    double t = 1;
    for (int i = 0; i < y; i++) t *= x;
    return t;
}

int main()
{
    unsigned long n, t;
    unsigned count = 0, sum = 0;
    scanf("%ld", &n);
    
    t = n;
    do {
        sum += t % 10;
        count++;
    } while (t /= 10);
    
    printf("%ld co %d chu so\n", n, count);
    printf("Chu so cuoi cung la: %d\n", n % 10);
    printf("Chu so dau tien la: %d\n", n / (int) pow(10, count - 1));
    printf("Tong cac chu so la: %d\n", sum);
    printf("So dao nguoc la: ");
    
    do printf("%d", n % 10); while (n /= 10);
    
    return 0;
}
