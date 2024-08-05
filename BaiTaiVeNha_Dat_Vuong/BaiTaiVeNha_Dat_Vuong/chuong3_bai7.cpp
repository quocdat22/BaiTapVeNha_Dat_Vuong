#include<stdio.h>
#include "BaiTap.h"
#include<string.h>

#define MAX_LEN 100

void insertWord(char* original, const char* word, int position) {
    int origLen = strlen(original);
    int wordLen = strlen(word);

    // Kiểm tra vị trí hợp lệ
    if (position < 0 || position > origLen) {
        printf("Vị trí không hợp lệ.\n");
        return;
    }

    // Nếu chuỗi gốc không có đủ chỗ, cần thêm đủ chỗ cho chuỗi kết quả
    if (origLen + wordLen + 1 > MAX_LEN) {
        printf("Không đủ không gian để chèn từ.\n");
        return;
    }

    // Di chuyển phần chuỗi sau vị trí chèn để tạo không gian cho từ mới
    memmove(original + position + wordLen, original + position, origLen - position + 1);

    // Chèn từ vào chuỗi
    memcpy(original + position, word, wordLen);
}

void chuong3_bai7() {
    char original[MAX_LEN];
    char word[MAX_LEN];
    int position;

    // Nhập chuỗi gốc từ người dùng
    printf("Nhập chuỗi gốc: ");
    fgets(original, MAX_LEN, stdin);
    original[strcspn(original, "\n")] = '\0'; // Loại bỏ ký tự newline

    // Nhập từ cần chèn
    printf("Nhập từ cần chèn: ");
    fgets(word, MAX_LEN, stdin);
    word[strcspn(word, "\n")] = '\0'; // Loại bỏ ký tự newline

    // Nhập vị trí cần chèn
    printf("Nhập vị trí cần chèn: ");
    scanf("%d", &position);

    // Chèn từ vào chuỗi gốc
    insertWord(original, word, position);

    // In ra kết quả
    printf("Chuỗi sau khi chèn từ: %s\n", original);

    return;

}