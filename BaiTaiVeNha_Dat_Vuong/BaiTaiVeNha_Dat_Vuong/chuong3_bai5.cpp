#include"BaiTap.h"
#include<stdio.h>
#include <string.h>

// Hàm kiểm tra chuỗi có chứa ít nhất 2 từ
int isValidName(const char* name) {
    int wordCount = 0;
    int inWord = 0;

    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == ' ') {
            if (inWord) {
                inWord = 0;
            }
        }
        else {
            if (!inWord) {
                wordCount++;
                inWord = 1;
            }
        }
    }

    return wordCount >= 2;
}


// Hàm in tên của người
void printFirstName(const char* fullName) {
    if (!isValidName(fullName)) {
        printf("Lỗi: Họ tên không hợp lệ. Họ tên yêu cầu phải có ít nhất 2 từ.\n");
        return;
    }

    // Tìm và in tên
    char nameCopy[256];
    strncpy_s(nameCopy, fullName, sizeof(nameCopy));
    nameCopy[sizeof(nameCopy) - 1] = '\0'; // Đảm bảo chuỗi kết thúc bằng '\0'

    char* token = strtok(nameCopy, " ");
    char* lastToken = NULL;

    while (token != NULL) {
        lastToken = token;
        token = strtok(NULL, " ");
    }

    if (lastToken != NULL) {
        printf("Tên: %s\n", lastToken);
    }
}

void chuong3_bai5() {
    char fullName[256];

    printf("Nhập họ tên: ");
    fgets(fullName, sizeof(fullName), stdin);

    // Loại bỏ ký tự newline nếu có
    size_t len = strlen(fullName);
    if (len > 0 && fullName[len - 1] == '\n') {
        fullName[len - 1] = '\0';
    }


    printFirstName(fullName);



	return;
}