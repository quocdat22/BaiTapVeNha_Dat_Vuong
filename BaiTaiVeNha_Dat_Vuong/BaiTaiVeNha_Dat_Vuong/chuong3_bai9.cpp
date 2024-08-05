#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000
#define ASCII_SIZE 256

void countCharacterFrequency(const char* str) {
    int count[ASCII_SIZE] = { 0 };
    int i;

    // Đếm số lần xuất hiện của mỗi ký tự
    for (i = 0; str[i]; i++) {
        count[(unsigned char)str[i]]++;
    }

    // In số lần xuất hiện của mỗi ký tự
    printf("Số lần xuất hiện của các ký tự:\n");
    for (i = 0; i < ASCII_SIZE; i++) {
        if (count[i] > 0) {
            printf("Ký tự '%c': %d lần\n", i, count[i]);
        }
    }
}

void chuong3_bai9() {
    char str[MAX_LEN];

    // Nhập chuỗi từ người dùng
    printf("Nhập chuỗi: ");
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0'; // Loại bỏ ký tự newline

    // Đếm và liệt kê số lần xuất hiện của mỗi ký tự
    countCharacterFrequency(str);

    return;
}