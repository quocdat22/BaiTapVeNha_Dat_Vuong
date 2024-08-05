#include"BaiTap.h"
#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include"functions.h"



//Viết hàm đổi những kí tự đầu tiên của mỗi từ thành chữ in hoa và những từ không phải đầu câu sang chữ thường
void chuong3_bai4() {
	char str[] = "hoang   le   quoc   dat";
	removeExtraSpaces(str);
	printf("Chuoi ban dau: \"%s\"\n", str);
	int n = strlen(str);
	int i;
	// Biến để theo dõi nếu ký tự trước đó là khoảng trắng
	int spaceFound = 1;
	for (i = 0; i < n; i++) {
		if (isspace(str[i])) {
			spaceFound = 1;
		}
		else {
			if (spaceFound) {
				str[i] = toupper(str[i]);
			}
			else {
				str[i] = tolower(str[i]);
			}
			spaceFound = 0;
		}
	}
	printf("Chuoi sau khi chuan hoa: \"%s\"\n", str);
	
	return;
}