#include <stdio.h>
#include "BaiTap.h"

#define MAX_SIZE 100

struct PhanSo {
	int tu;
	int mau;
};

// Hàm nhập một phân số
void nhapPhanSo(PhanSo* ps) {
    printf("Nhập tử số: ");
    scanf("%d", &ps->tu);
    printf("Nhập mẫu số: ");
    scanf("%d", &ps->mau);
}

// Hàm nhập danh sách các phân số
void nhapDanhSachPhanSo(PhanSo ds[], int* n) {
    printf("Nhập số lượng phân số (n <= %d): ", MAX_SIZE);
    scanf("%d", n);

    if (*n > MAX_SIZE || *n <= 0) {
        printf("Số lượng phân số không hợp lệ.\n");
        return;
    }

    for (int i = 0; i < *n; i++) {
        printf("Nhập phân số thứ %d:\n", i + 1);
        nhapPhanSo(&ds[i]);
    }
}

// Hàm in danh sách các phân số
void inDanhSachPhanSo(PhanSo ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Phân số thứ %d: %d/%d\n", i + 1, ds[i].tu, ds[i].mau);
    }
}

void chuong2_8_1() {
    PhanSo ds[MAX_SIZE];
    int n;

    // Nhập danh sách các phân số
    nhapDanhSachPhanSo(ds, &n);

    // In danh sách các phân số
    printf("\nDanh sách các phân số đã nhập:\n");
    inDanhSachPhanSo(ds, n);

    return;
}