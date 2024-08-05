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

//so luong sinh vien dat va khong
void demSinhVienDatVaKhongDat(SinhVien ds[], int n, int* soSinhVienDat, int* soSinhVienKhongDat) {
	*soSinhVienDat = 0;
	*soSinhVienKhongDat = 0;

	for (int i = 0; i < n; i++) {
		if (tinhDiemTongKet(&ds[i]) >= 5.0) {
			(*soSinhVienDat)++;
		}
		else {
			(*soSinhVienKhongDat)++;
		}
	}
}

float quyDoiDiemHe4(float diemHe10) {
	if (diemHe10 >= 9.0) return 4.0;
	if (diemHe10 >= 8.0) return 3.5;
	if (diemHe10 >= 7.0) return 3.0;
	if (diemHe10 >= 6.0) return 2.5;
	if (diemHe10 >= 5.0) return 2.0;
	if (diemHe10 >= 4.0) return 1.5;
	if (diemHe10 >= 3.0) return 1.0;
	return 0.0;
}

void xuatSinhVienVaDiemHe4(SinhVien* sv) {
	float diemTongKet = tinhDiemTongKet(sv);
	printf("Số thứ tự: %d\n", sv->stt);
	printf("Mã số sinh viên: %s\n", sv->maSV);
	printf("Họ tên sinh viên: %s\n", sv->hoTen);
	printf("Điểm tiểu luận: %.2f\n", sv->diemTieuLuan);
	printf("Điểm thi kết thúc môn: %.2f\n", sv->diemThiKetThuc);
	printf("Điểm tổng kết: %.2f\n", diemTongKet);
	printf("Điểm quy đổi hệ 4: %.2f\n", quyDoiDiemHe4(diemTongKet));
}
void xuatDanhSachSinhVienVaDiemHe4(SinhVien ds[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Thông tin sinh viên thứ %d:\n", i + 1);
		xuatSinhVienVaDiemHe4(&ds[i]);
	}
}
//sap xep diem tong ket tang dan
void sapXepTangDanTheoDiemTongKet(SinhVien ds[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (tinhDiemTongKet(&ds[j]) < tinhDiemTongKet(&ds[min_idx])) {
				min_idx = j;
			}
		}
		if (min_idx != i) {
			SinhVien temp = ds[i];
			ds[i] = ds[min_idx];
			ds[min_idx] = temp;
		}
	}
}

void sapXepGiamDanTheoDiemTongKet(SinhVien ds[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int max_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (tinhDiemTongKet(&ds[j]) > tinhDiemTongKet(&ds[max_idx])) {
				max_idx = j;
			}
		}
		if (max_idx != i) {
			SinhVien temp = ds[i];
			ds[i] = ds[max_idx];
			ds[max_idx] = temp;
		}
	}
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


	//// Xuất danh sách sinh viên kèm theo điểm tổng kết
	//printf("\nDanh sách sinh viên có sẵn và điểm tổng kết:\n");
	//xuatDanhSachSinhVienVaDiemTongKet(ds, n);


	//// Tìm và in sinh viên có điểm tổng kết cao nhất
	//SinhVien* svMax = timSinhVienDiemTongKetCaoNhat(ds, n);
	//if (svMax != NULL) {
	//	printf("\nSinh viên có điểm tổng kết cao nhất:\n");
	//	xuatSinhVienVaDiemTongKet(svMax);
	//}

	//// Tìm và in sinh viên có điểm tổng kết thấp nhất
	//SinhVien* svMin = timSinhVienDiemTongKetThapNhat(ds, n);
	//if (svMin != NULL) {
	//	printf("\nSinh viên có điểm tổng kết thấp nhất:\n");
	//	xuatSinhVienVaDiemTongKet(svMin);
	//}


	//// Đếm số lượng sinh viên đạt và không đạt
	//int soSinhVienDat, soSinhVienKhongDat;
	//demSinhVienDatVaKhongDat(ds, n, &soSinhVienDat, &soSinhVienKhongDat);

	//printf("\nSố lượng sinh viên đạt: %d\n", soSinhVienDat);
	//printf("Số lượng sinh viên không đạt: %d\n", soSinhVienKhongDat);


	/*printf("\nDanh sách sinh viên có sẵn và điểm tổng kết:\n");
	xuatDanhSachSinhVienVaDiemHe4(ds, n);*/

	// Sắp xếp tăng dần theo điểm tổng kết
	sapXepTangDanTheoDiemTongKet(ds, n);
	printf("\nDanh sách sinh viên sau khi sắp xếp tăng dần theo điểm tổng kết:\n");
	xuatDanhSachSinhVienVaDiemHe4(ds, n);

	// Sắp xếp giảm dần theo điểm tổng kết
	sapXepGiamDanTheoDiemTongKet(ds, n);
	printf("\nDanh sách sinh viên sau khi sắp xếp giảm dần theo điểm tổng kết:\n");
	xuatDanhSachSinhVienVaDiemHe4(ds, n);


	return;
}
