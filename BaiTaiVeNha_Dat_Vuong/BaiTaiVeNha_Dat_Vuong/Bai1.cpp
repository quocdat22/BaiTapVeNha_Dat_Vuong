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

int soSanhPhanSo(PhanSo a, PhanSo b) {
    int value1 = a.tu * b.mau;
    int value2 = b.tu * a.mau;

    if (value1 > value2) {
        return 1;
    }
    else if (value1 < value2) {
        return -1;
    }
    else {
        return 0;
    }
}

// Hàm tìm phân số lớn nhất
PhanSo timPhanSoLonNhat(PhanSo ds[], int n) {
    PhanSo max = ds[0];
    for (int i = 1; i < n; i++) {
        if (soSanhPhanSo(ds[i], max) > 0) {
            max = ds[i];
        }
    }
    return max;
}

// Hàm tìm phân số nhỏ nhất
PhanSo timPhanSoNhoNhat(PhanSo ds[], int n) {
    PhanSo min = ds[0];
    for (int i = 1; i < n; i++) {
        if (soSanhPhanSo(ds[i], min) < 0) {
            min = ds[i];
        }
    }
    return min;
}

//Tính tổng các phân số có trong danh sách.
PhanSo tongPhanSo(PhanSo ds[], int n) {
	PhanSo sum = ds[0];
	for (int i = 1; i < n; i++) {
		sum.tu = sum.tu * ds[i].mau + ds[i].tu * sum.mau;
		sum.mau = sum.mau * ds[i].mau;
	}
	return sum;
}

//Tính tích các phân số có trong danh sách.
PhanSo tichPhanSo(PhanSo ds[], int n) {
	PhanSo tich = ds[0];
	for (int i = 1; i < n; i++) {
		tich.tu = tich.tu * ds[i].tu;
		tich.mau = tich.mau * ds[i].mau;
	}
	return tich;
}

//Xuất ra nghịch đảo giá trị các phân số trong mảng
void nghichDaoPhanSo(PhanSo ds[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Nghịch đảo phân số thứ %d: %d/%d\n", i + 1, ds[i].mau, ds[i].tu);
	}
}

//sap xep tang dan theo thuat toan INTERCHANGE SORT

void interchangeSortTang(PhanSo ds[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (soSanhPhanSo(ds[i], ds[j]) > 0) {
				PhanSo temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
}
//sap xep giam dan theo thuat toan INTERCHANGE SORT
void interchangeSortGiam(PhanSo ds[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (soSanhPhanSo(ds[i], ds[j]) < 0) {
				PhanSo temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
}

//sap xep giam dan theo thuat toan Selection Sort
void selectionSortGiam(PhanSo ds[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int max = i;
		for (int j = i + 1; j < n; j++) {
			if (soSanhPhanSo(ds[j], ds[max]) > 0) {
				max = j;
			}
		}
		if (max != i) {
			PhanSo temp = ds[i];
			ds[i] = ds[max];
			ds[max] = temp;
		}
	}
}

//sap xep tang dan theo thuat toan Selection Sort
void selectionSortTang(PhanSo ds[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (soSanhPhanSo(ds[j], ds[min]) < 0) {
				min = j;
			}
		}
		if (min != i) {
			PhanSo temp = ds[i];
			ds[i] = ds[min];
			ds[min] = temp;
		}
	}
}

//sap xep tang dan theo thuat toan quick sort

void quickSortTang(PhanSo ds[], int n) {
	int i = 0;
	int j = n - 1;
	PhanSo pivot = ds[n / 2];
	while (i <= j) {
		while (soSanhPhanSo(ds[i], pivot) < 0) {
			i++;
		}
		while (soSanhPhanSo(ds[j], pivot) > 0) {
			j--;
		}
		if (i <= j) {
			PhanSo temp = ds[i];
			ds[i] = ds[j];
			ds[j] = temp;
			i++;
			j--;
		}
	}
	if (0 < j) {
		quickSortTang(ds, j + 1);
	}
	if (i < n) {
		quickSortTang(ds + i, n - i);
	}
}

//sap xep giam dan theo thuat toan quick sort
void quickSortGiam(PhanSo ds[], int n) {
	int i = 0;
	int j = n - 1;
	PhanSo pivot = ds[n / 2];
	while (i <= j) {
		while (soSanhPhanSo(ds[i], pivot) > 0) {
			i++;
		}
		while (soSanhPhanSo(ds[j], pivot) < 0) {
			j--;
		}
		if (i <= j) {
			PhanSo temp = ds[i];
			ds[i] = ds[j];
			ds[j] = temp;
			i++;
			j--;
		}
	}
	if (0 < j) {
		quickSortGiam(ds, j + 1);
	}
	if (i < n) {
		quickSortGiam(ds + i, n - i);
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

    //// Tìm phân số lớn nhất
    //PhanSo max = timPhanSoLonNhat(ds, n);
    //printf("\nPhân số lớn nhất: %d/%d\n", max.tu, max.mau);

    //// Tìm phân số nhỏ nhất
    //PhanSo min = timPhanSoNhoNhat(ds, n);
    //printf("\nPhân số nhỏ nhất: %d/%d\n", min.tu, min.mau);

    //// Tính tổng các phân số
    //PhanSo sum = tongPhanSo(ds, n);
    //printf("\nTổng các phân số: %d/%d\n", sum.tu, sum.mau);

    //// Tính tích các phân số
    //PhanSo tich = tichPhanSo(ds, n);
    //printf("\nTích các phân số: %d/%d\n", tich.tu, tich.mau);

    // Xuất ra nghịch đảo giá trị các phân số trong mảng
    //nghichDaoPhanSo(ds, n);

    ////sap xep tang dan theo thuat toan INTERCHANGE SORT
    //interchangeSortTang(ds, n);
    //printf("\nDanh sách các phân số sau khi sắp xếp tăng dần:\n");
    //inDanhSachPhanSo(ds, n);

    ////sap xep giam dan theo thuat toan INTERCHANGE SORT
    //interchangeSortGiam(ds, n);
    //printf("\nDanh sách các phân số sau khi sắp xếp giảm dần:\n");
    //inDanhSachPhanSo(ds, n);

    ////sap xep giam dan theo thuat toan Selection Sort
    //selectionSortGiam(ds, n);
    //printf("\nDanh sách các phân số sau khi sắp xếp giảm dần:\n");
    //inDanhSachPhanSo(ds, n);

    ////sap xep tang dan theo thuat toan Selection Sort
    //selectionSortTang(ds, n);
    //printf("\nDanh sách các phân số sau khi sắp xếp tăng dần:\n");
    //inDanhSachPhanSo(ds, n);

	//sap xep tang dan theo thuat toan quick sort
	quickSortTang(ds, n);
	printf("\nDanh sách các phân số sau khi sắp xếp tăng dần:\n");
	inDanhSachPhanSo(ds, n);

	//sap xep giam dan theo thuat toan quick sort
	quickSortGiam(ds, n);
	printf("\nDanh sách các phân số sau khi sắp xếp giảm dần:\n");
	inDanhSachPhanSo(ds, n);



    return;
}