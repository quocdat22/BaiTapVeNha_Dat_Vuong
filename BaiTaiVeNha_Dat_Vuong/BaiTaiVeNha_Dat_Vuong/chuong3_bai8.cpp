#include <stdio.h>
#include <string.h>
#include "BaiTap.h"

#define MAX_LEN 1000

void removeWord(char* original, const char* word) {
    char* pos, temp[MAX_LEN];
    int wordLen = strlen(word);

    // Tìm vị trí của từ cần xóa
    while ((pos = strstr(original, word)) != NULL) {
        // Sao chép phần trước từ cần xóa vào biến tạm
        strncpy(temp, original, pos - original);
        temp[pos - original] = '\0';

        // Sao chép phần sau từ cần xóa vào biến tạm
        strcat(temp, pos + wordLen);

        // Sao chép lại chuỗi gốc
        strcpy(original, temp);
    }
}


void chuong3_bai8() {
    char original[MAX_LEN];
    char word[MAX_LEN];

    // Nhập chuỗi gốc từ người dùng
    printf("Nhập chuỗi gốc: ");
    fgets(original, MAX_LEN, stdin);
    original[strcspn(original, "\n")] = '\0'; // Loại bỏ ký tự newline

    // Nhập từ cần xóa
    printf("Nhập từ cần xóa: ");
    fgets(word, MAX_LEN, stdin);
    word[strcspn(word, "\n")] = '\0'; // Loại bỏ ký tự newline

    // Xóa từ khỏi chuỗi gốc
    removeWord(original, word);

    // In ra kết quả
    printf("Chuỗi sau khi xóa từ: %s\n", original);

    return;
}