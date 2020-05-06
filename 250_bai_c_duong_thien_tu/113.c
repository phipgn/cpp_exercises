#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* s = (char*) calloc(100, sizeof(char));
    printf("Nhap chuoi nhi phan: ");
    scanf("%s", s);
    
    s = (char*) realloc(s, (strlen(s) + 1) * sizeof(char));
    
    int head, len;
    int maxlen, maxhead;
    int i = 0;
    maxlen = maxhead = 0;
    
    do {
        for (len = 0, head = i; s[i] && s[i] == '0'; i++)
            len++;
        if (len > maxlen) {
            maxlen = len;
            maxhead = head;
        }
        i++;
    } while (s[i] != '\0');
    
    printf("Chuoi 0 dai nhat co %d ky tu", maxlen);
    printf("\nBat dau tai s[%d]", maxhead);

    return 0;
}
