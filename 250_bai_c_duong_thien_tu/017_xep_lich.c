#include <stdio.h>

int isLeapYear(int y) {
    return (!(y % 4) && y % 100) || !(y % 400);
}

int getDow(int q, int m, int y) {
    if (m == 1) { m = 13; y--; }
    if (m == 2) { m = 14; y--; }
    int k = y % 100;
    int j = y / 100;
    int h = q + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j;
    h = h % 7;
    return h == 0 ? 6 : h - 1;
}

int getTop(int month, int year) {
    int top;
    switch(month) {
        case 4: case 6: case 9: case 11: top = 30; break;
        case 2: top = isLeapYear(year) ? 29 : 28; break;
        default: top = 31; break;
    }
    return top;
}

int getFirstPerson(int month, int year) {
    int index = -1;
    for  (int m = 1; m < month; m++) {
        int dow = getDow(1, m, year);
        int top = getTop(m, year);
        for (int i = 0; i < top; i++) {
            if ((i + dow) % 7 != 0) index++;
            if (index == 5) index = 0;
        }
    }
    index++;
    return index == 5 ? 0 : index;
}

int main() {
    char days[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    char student[5][2] = {"A", "B", "C", "D", "E"};
    int year, month, cols = 7;
    scanf("%d%d", &year, &month);
    
    int dow = getDow(1, month, year);
    int top = getTop(month, year);
    
    for (int i = 0; i < cols; i++)
        printf("%7s", days[i]);
    printf("\n");
    for (int i = 0; i < dow; i++) printf("%7s", " ");
    int index = getFirstPerson(month, year);
    for (int i = 0; i < top; i++) {
        (i + dow) % 7 == 0 ? printf("%3d [ ]", i + 1) : printf("%3d [%s]", i + 1, student[index++]);
        if (index == 5) index = 0;
        if ((i + dow + 1) % cols == 0) printf("\n");
    }

    return 0;
}
