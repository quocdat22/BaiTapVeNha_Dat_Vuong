#include <stdio.h>
#include <stdlib.h> 

void nhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu a[%d]: ", i);
        scanf_s("%d", &a[i]);
    }
}

void xuatMang(int a[], int n) {
    printf("Mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int timMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int timMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int demChan(int a[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            dem++;
        }
    }
    return dem;
}

int demLe(int a[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            dem++;
        }
    }
    return dem;
}

int timKiemTuyenTinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;  
}

int timKiemNhiPhan(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;  
}
int demSoLanXuatHien(int a[], int n, int x) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            dem++;
        }
    }
    return dem;
}

void sapXepMang(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, x;
    printf("Nhap so phan tu cua mang: ");
    scanf_s("%d", &n);

    int* a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1; 
    }

    nhapMang(a, n);

    xuatMang(a, n);

    printf("Gia tri lon nhat: %d\n", timMax(a, n));
    printf("Gia tri nho nhat: %d\n", timMin(a, n));
    printf("So phan tu chan: %d\n", demChan(a, n));
    printf("So phan tu le: %d\n", demLe(a, n));
    printf("Nhap phan tu x de tim kiem: ");
    scanf_s("%d", &x);
    int viTri = timKiemTuyenTinh(a, n, x);
    if (viTri != -1) {
        printf("Phan tu %d duoc tim thay tai vi tri %d (tim kiem tuyen tinh)\n", x, viTri);
    }
    else {
        printf("Phan tu %d khong duoc tim thay (tim kiem tuyen tinh)\n", x);
    }

    sapXepMang(a, n);
    viTri = timKiemNhiPhan(a, n, x);
    if (viTri != -1) {
        printf("Phan tu %d duoc tim thay tai vi tri %d (tim kiem nhi phan)\n", x, viTri);
    }
    else {
        printf("Phan tu %d khong duoc tim thay (tim kiem nhi phan)\n", x);
    }

    printf("So lan xuat hien cua phan tu %d: %d\n", x, demSoLanXuatHien(a, n, x));
    free(a);

    return 0;
}

