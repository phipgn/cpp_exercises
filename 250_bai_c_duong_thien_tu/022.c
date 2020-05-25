#include <stdio.h>

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    
    int count = 0, sum = 1;
    for (int i = 2; i <= n/2; i++)
        if (n % i == 0) {
            count++;
            sum += i;
        }
    sum += n;
    printf("Co %d uoc so, tong la: %d", count + 2, sum);

    return 0;
}
