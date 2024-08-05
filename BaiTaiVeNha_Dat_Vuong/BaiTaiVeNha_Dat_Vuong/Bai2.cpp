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
void xuatSinhVien(SinhVien* sv) {
	printf("Số thứ tự: %d\n", sv->stt);
	printf("Mã số sinh viên: %s\n", sv->maSV);
	printf("Họ tên sinh viên: %s\n", sv->hoTen);
	printf("Điểm tiểu luận: %.2f\n", sv->diemTieuLuan);
	printf("Điểm thi kết thúc môn: %.2f\n", sv->diemThiKetThuc);
}
void xuatDanhSachSinhVien(SinhVien ds[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Thông tin sinh viên thứ %d:\n", i + 1);
		xuatSinhVien(&ds[i]);
	}
}

float tinhDiemTongKet(SinhVien* sv) {
	return 0.3 * sv->diemTieuLuan + 0.7 * sv->diemThiKetThuc;
}

void xuatSinhVienVaDiemTongKet(SinhVien* sv) {
	printf("Số thứ tự: %d\n", sv->stt);
	printf("Mã số sinh viên: %s\n", sv->maSV);
	printf("Họ tên sinh viên: %s\n", sv->hoTen);
	printf("Điểm tiểu luận: %.2f\n", sv->diemTieuLuan);
	printf("Điểm thi kết thúc môn: %.2f\n", sv->diemThiKetThuc);
	printf("Điểm tổng kết: %.2f\n", tinhDiemTongKet(sv));
}	
void xuatDanhSachSinhVienVaDiemTongKet(SinhVien ds[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Thông tin sinh viên thứ %d:\n", i + 1);
		xuatSinhVienVaDiemTongKet(&ds[i]);
	}
}

//diem tong ket cao nhat
SinhVien* timSinhVienDiemTongKetCaoNhat(SinhVien ds[], int n) {
	if (n == 0) return NULL;

	SinhVien* max = &ds[0];
	for (int i = 1; i < n; i++) {
		if (tinhDiemTongKet(&ds[i]) > tinhDiemTongKet(max)) {
			max = &ds[i];
		}
	}
	return max;
}
//thap nhat
SinhVien* timSinhVienDiemTongKetThapNhat(SinhVien ds[], int n) {
	if (n == 0) return NULL;

	SinhVien* min = &ds[0];
	for (int i = 1; i < n; i++) {
		if (tinhDiemTongKet(&ds[i]) < tinhDiemTongKet(min)) {
			min = &ds[i];
		}
	}
	return min;
}

void chuong2_slide9_bai2() {
	
	int n;

	// Nhập danh sách sinh viên
	//nhapDanhSachSinhVien(ds, &n);

	SinhVien ds[MAX_SV] = {
		{1, "SV001", "Nguyen Van A", 8.5, 7.5},
		{2, "SV002", "Tran Thi B", 9.0, 8.0},
		{3, "SV003", "Le Van C", 7.0, 6.5}
	};
	n = 3;

	// Xuất danh sách sinh viên
	/*printf("\nDanh sách sinh viên đã nhập:\n");
	xuatDanhSachSinhVien(ds, n);*/


	// Xuất danh sách sinh viên kèm theo điểm tổng kết
	printf("\nDanh sách sinh viên có sẵn và điểm tổng kết:\n");
	xuatDanhSachSinhVienVaDiemTongKet(ds, n);


	// Tìm và in sinh viên có điểm tổng kết cao nhất
	SinhVien* svMax = timSinhVienDiemTongKetCaoNhat(ds, n);
	if (svMax != NULL) {
		printf("\nSinh viên có điểm tổng kết cao nhất:\n");
		xuatSinhVienVaDiemTongKet(svMax);
	}

	// Tìm và in sinh viên có điểm tổng kết thấp nhất
	SinhVien* svMin = timSinhVienDiemTongKetThapNhat(ds, n);
	if (svMin != NULL) {
		printf("\nSinh viên có điểm tổng kết thấp nhất:\n");
		xuatSinhVienVaDiemTongKet(svMin);
	}
}
