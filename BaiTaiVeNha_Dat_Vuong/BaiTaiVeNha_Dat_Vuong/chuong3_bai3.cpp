#include"BaiTap.h"
#include<stdio.h>
#include<string.h>
#include <ctype.h>

//Nhập vào một chuỗi, xóa những khoảng trắng thừa trong chuỗi.
void removeExtraSpaces(char* str) {
    int n = strlen(str);
    int i, j = 0;

    // Biến để theo dõi nếu khoảng trắng trước đó là không
    int spaceFound = 0;

    for (i = 0; i < n; i++) {
        // Nếu ký tự hiện tại không phải là khoảng trắng
        if (!isspace(str[i])) {
            // Nếu trước đó đã gặp khoảng trắng và bây giờ là ký tự không phải khoảng trắng
            // thì thêm một khoảng trắng vào kết quả
            if (spaceFound) {
                str[j++] = ' ';
                spaceFound = 0;
            }
            str[j++] = str[i];
        }
        else {
            // Nếu ký tự hiện tại là khoảng trắng, đánh dấu đã gặp khoảng trắng
            spaceFound = 1;
        }
    }

    // Xóa khoảng trắng cuối cùng nếu có
    if (j > 0 && str[j - 1] == ' ') {
        j--;
    }

    // Kết thúc chuỗi kết quả
    str[j] = '\0';
}

void chuong3_bai3() {
    char str[] = "    Hoang   Le     Quoc Dat.      ";
    printf("Chuoi binh thuong: \"%s\"\n", str);
    removeExtraSpaces(str);
    printf("Chuoi sau khi xoa khoang trang: \"%s\"\n", str);
	
	return;
}