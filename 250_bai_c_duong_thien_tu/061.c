/*
61: Viết chương trình thực hiện những yêu cầu sau:
a. Tạo ngẫu nhiên mảng một chiều n phần tử nguyên có giá trị chứa trong đoạn
[-100, 100] và xuất mảng.
b. Tính tổng các số nguyên dương có trong mảng.
c. Xóa phần tử có chỉ số p (p nhập từ bàn phím) trong mảng.

Nhap n [1, 99]: 10 
69 -41 48 22 -34 100 -14 70 66 -29
Tong cac so nguyen duong = 375
Nhap p [0, 9]: 4
69 -41 48 22 100 -14 70 66 -29
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_array(int* a, int n) {
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main() {
    int n;
    printf("Input n [1, 99]: ");
    scanf("%d", &n);
    
    int* a = (int*) calloc(n, sizeof(int));
    
    srand(time(0));
    for (int i = 0; i < n; i++) 
        *(a + i) = rand() % 201 - 100;
    print_array(a, n);
    
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > 0) sum += a[i];
    
    printf("\nSum of positive integers: %d", sum);
    
    int p;
    printf("\nInput p [0, 9]: ");
    scanf("%d", &p);
    
    for (int i = p; i < n - 1; i++)
        a[i] = a[i + 1];
    print_array(a, --n);
    
    return 0;
}
