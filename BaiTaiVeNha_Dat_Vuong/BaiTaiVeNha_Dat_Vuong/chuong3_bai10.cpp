#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000
#define ASCII_SIZE 256

char findMostFrequentCharacter(const char* str) {
    int count[ASCII_SIZE] = { 0 };
    int i;
    int maxCount = 0;
    char mostFrequentChar = '\0';

    // Đếm số lần xuất hiện của mỗi ký tự
    for (i = 0; str[i]; i++) {
        count[(unsigned char)str[i]]++;
    }

    // Tìm ký tự xuất hiện nhiều nhất
    for (i = 0; i < ASCII_SIZE; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            mostFrequentChar = i;
        }
    }

    return mostFrequentChar;
}

void chuong3_bai10() {
    char str[MAX_LEN];

    // Nhập chuỗi từ người dùng
    printf("Nhập chuỗi: ");
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0'; // Loại bỏ ký tự newline

    // Tìm ký tự xuất hiện nhiều nhất
    char mostFrequentChar = findMostFrequentCharacter(str);

    // In kết quả
    if (mostFrequentChar != '\0') {
        printf("Ký tự xuất hiện nhiều nhất là '%c'\n", mostFrequentChar);
    }
    else {
        printf("Chuỗi rỗng.\n");
    }

    return;
}