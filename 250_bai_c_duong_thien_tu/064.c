/*
Bài 64: Viết chương trình thực hiện những yêu cầu sau:
a. Tạo mảng một chiều n phần tử nguyên có giá trị nhập vào từ bàn phím.
b. Hãy đếm số các phần tử có trị là lũy thừa của 2 có trong mảng.
c. Nhập x nguyên, xóa các phần tử trong mảng có trị trùng với x.

Một số là lũy thừa của 2 nếu số đó có bit 1 duy nhất là bit MSB (Most Significant Bit). Ví dụ: 
2^8 = 256 = 1 0000 0000

Nhap n [1, 99]: 10
Nhap 10 phan tu:
2 -5 4 7 9 -8 32 16 11 4
Co 5 so la luy thua cua 2
Nhap x: 4
2 -5 7 9 -8 32 16 11
*/
#include <stdio.h>
#include <stdlib.h>

int is_power_of_2(int x) {
    return x && !(x & (x-1));
}

int main() {
    int n, count = 0, x;
    printf("Input n [1, 99]: ");
    scanf("%d", &n);
    
    printf("Input 10 elements:\n");
    int* a = (int*) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    for (int i = 0; i < n; i++)
        if (is_power_of_2(a[i])) count++;
    printf("%d numbers are power of 2", count);
    
    printf("\nInput x: ");
    scanf("%d", &x);
    
    for (int i = 0; i < n; i++)
        if (a[i] == x) {
            for (int j = i; j < n - 1; j++)
                a[j] = a[j + 1];
            n--;
        }
    
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    
    return 0;
}
