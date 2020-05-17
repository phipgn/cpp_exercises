#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int y) {
    return (!(y % 4) && y % 100) || !(y % 400);
}

int getDow(int q, int m, int y) {
    if (m == 1) { m = 13; y--; }
    if (m == 2) { m = 14; y--; }
    int k = y % 100;
    int j = y / 100;
    int h = q + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 - 2 * j;
    h = h % 7;
    return h == 0 ? 6 : h - 1;
}

int getRows(int dow, int top) {
    return dow + top > 35 ? 6 : 5;
}

int** initCal(int dow, int top) {
    int rows = getRows(dow, top);
    int cols = 7;
    int** cal = (int**) calloc(rows, sizeof(int*));
    for (int r = 0; r < rows; r++)
        cal[r] = (int*) calloc(cols, sizeof(int));
    
    int day = 1;
    for (int i = 0; i < rows; i++) {
        int* d = cal[i];
        if (i == 0) {
            for (int j = 0; j < dow; j++) d++;
            for (int j = dow; j < cols; j++) *(d++) = day++;
        } else { 
            for (int j = 0; j < cols; j++) {
                *(d++) = day++;
                if (day > top) break;
            }
        }
        if (day > top) break;
    }
    return cal;        
}

int main()
{
    char months[12][10] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };
    char daysow[7][4] = {"S", "M", "T", "W", "T", "F", "S"};
    
    int y;
    printf("Input year: ");
    scanf("%d", &y);
    
    putchar('\n');
    
    for (int m = 1; m <= 12; m++, printf("\n")) {
        printf("%s\n", months[m - 1]);
        
        int top;
        switch(m) {
            case 2: top = isLeapYear(y) ? 29 : 28; break;
            case 4: case 6: case 9: case 11: top = 30; break;
            default: top = 31; break;
        }
        
        int dow = getDow(1, m, y);
        int rows = getRows(dow, top), cols = 7;
        int** cal = initCal(dow, top);
        for (int j = 0; j < cols; j++, putchar('\n')) {
            printf("%s ", daysow[j]);
            for (int i = 0; i < rows; i++)
                cal[i][j] == 0 ? printf("%3s", " ") : printf("%3d", cal[i][j]);
        }
        free(cal);
    }
    
    return 0;
}
