#include <stdio.h>

int main() {
    int k;
    printf("Nhap so kW tieu thu: ");
    scanf("%d", &k);
    
    int sum = 0;
    for (int i = 1; i <= k; i++) {
        if (i <= 100) sum += 500;
        else if (i > 100 && i <= 250) sum += 800;
        else if (i > 250 && i <= 350) sum += 1000;
        else sum += 1500;
    }
    printf("Chi phi: %d", sum);

    return 0;
}
