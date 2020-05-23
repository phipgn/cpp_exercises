#include <stdio.h>

int main() {
    int h1, m1, s1;
    int h2, m2, s2;
    
    printf("Nhap gio, phut, giay [1]: ");
    scanf("%d%d%d", &h1, &m1, &s1);
    printf("Nhap gio, phut, giay [2]: ");
    scanf("%d%d%d", &h2, &m2, &s2);
    
    int t1 = h1 * 3600 + m1 * 60 + s1;
    int t2 = h2 * 3600 + m2 * 60 + s2;
    int t = t1 > t2 ? t1 - t2 : t2 - t1;
    
    printf("Hieu thoi gian: %d gio %d phut %d giay", t / 3600, (t % 3600) / 60, (t % 3600) % 60);

    return 0;
}
