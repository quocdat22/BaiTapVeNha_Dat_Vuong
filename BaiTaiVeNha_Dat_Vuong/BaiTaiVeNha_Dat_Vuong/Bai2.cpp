#include "BaiTap.h"
#include <stdio.h>
#include <string.h>

#define MAX_SV 100

struct SinhVien {
	int stt;
	char maSV[10];
	char hoTen[50];
	float diemTieuLuan;
	float diemThiKetThuc;
};

//nhap
void nhapSinhVien(SinhVien* sv) {
	printf("Nhập số thứ tự: ");
	scanf("%d", &sv->stt);
	printf("Nhập mã số sinh viên: ");
	scanf("%s", sv->maSV);
	printf("Nhập họ tên sinh viên: ");
	getchar(); // Xóa ký tự newline còn lại từ buffer
	fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
	sv->hoTen[strcspn(sv->hoTen, "\n")] = '\0'; // Loại bỏ ký tự newline
	printf("Nhập điểm tiểu luận: ");
	scanf("%f", &sv->diemTieuLuan);
	printf("Nhập điểm thi kết thúc môn: ");
	scanf("%f", &sv->diemThiKetThuc);
}

void nhapDanhSachSinhVien(SinhVien ds[], int* n) {
	printf("Nhập số lượng sinh viên (n <= %d): ", MAX_SV);
	scanf("%d", n);

	if (*n > MAX_SV || *n <= 0) {
		printf("Số lượng sinh viên không hợp lệ.\n");
		return;
	}

	for (int i = 0; i < *n; i++) {
		printf("Nhập thông tin sinh viên thứ %d:\n", i + 1);
		nhapSinhVien(&ds[i]);
	}
}

//xuat
void xuatSinhVien(const SinhVien* sv) {
	printf("Số thứ tự: %d\n", sv->stt);
	printf("Mã số sinh viên: %s\n", sv->maSV);
	printf("Họ tên sinh viên: %s\n", sv->hoTen);
	printf("Điểm tiểu luận: %.2f\n", sv->diemTieuLuan);
	printf("Điểm thi kết thúc môn: %.2f\n", sv->diemThiKetThuc);
}
void xuatDanhSachSinhVien(const SinhVien ds[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Thông tin sinh viên thứ %d:\n", i + 1);
		xuatSinhVien(&ds[i]);
	}
}



void chuong2_slide9_bai2() {
	SinhVien ds[MAX_SV];
	int n;

	// Nhập danh sách sinh viên
	nhapDanhSachSinhVien(ds, &n);

	// Xuất danh sách sinh viên
	printf("\nDanh sách sinh viên đã nhập:\n");
	xuatDanhSachSinhVien(ds, n);

}
