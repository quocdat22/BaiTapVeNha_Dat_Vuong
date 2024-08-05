#include"BaiTap.h"
#include<stdio.h>

int countSpaces(const char* str) {
    int count = 0;
    while (*str) {
        if (*str == ' ') {
            count++;
        }
        str++;
    }
    return count;
}

void chuong3_bai2() {

    const char* testStr = "Hoang Le Quoc Dat";
    int numSpaces = countSpaces(testStr);
    printf("So luong khoang trang: %d\n", numSpaces);
    

	return;
}