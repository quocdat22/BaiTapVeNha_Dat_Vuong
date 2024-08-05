#include<stdio.h>
#include"Baitap.h"
#include<string>

void splitName(const char* fullName, char* lastName, char* firstName) {
    // Tìm vị trí của ký tự trắng cuối cùng
    const char* lastSpace = strrchr(fullName, ' ');

    // Nếu không tìm thấy ký tự trắng, toàn bộ chuỗi là tên
    if (lastSpace == NULL) {
        strcpy(firstName, fullName);
        lastName[0] = '\0'; // Không có họ lót
    }
    else {
        // Sao chép họ lót từ đầu đến ký tự trắng cuối cùng
        strncpy(lastName, fullName, lastSpace - fullName);
        lastName[lastSpace - fullName] = '\0';

        // Sao chép tên từ ký tự trắng cuối cùng đến hết chuỗi
        strcpy(firstName, lastSpace + 1);
    }
}

void chuong3_bai6() {

    const char* fullName = "Hoang Le Quoc Dat";
    char lastName[100];
    char firstName[100];

    printf("Họ tên: %s\n", fullName);

    splitName(fullName, lastName, firstName);

    printf("Họ lót: %s\n", lastName);
    printf("Tên: %s\n", firstName);

	return;
}