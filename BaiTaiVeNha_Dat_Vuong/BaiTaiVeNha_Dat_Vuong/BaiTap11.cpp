//#include <stdio.h>
//#include <math.h>
//#include <stdbool.h>
//
//bool laSoHoanThien(int n);
//bool laSoNguyenTo(int n);
//int chuSoDauTien(int n);
//void nhapMaTran(int a[][100], int m, int n);
//void xuatMaTran(int a[][100], int m, int n);
//int tinhTongChuSoDauLe(int a[][100], int m, int n);
//void lietKeSoHoanThien(int a[][100], int m, int n);
//int tinhTongLonHonTriTuyetDoiSau(int a[][100], int m, int n);
//int tinhTongDongK(int a[][100], int m, int n, int k);
//int tinhTongBien(int a[][100], int m, int n);
//int demTanSuatX(int a[][100], int m, int n, int x);
//void demCacLoaiPhanTu(int a[][100], int m, int n, int* chan, int* le, int* am, int* duong, int* nguyento);
//
//bool laSoHoanThien(int n) {
//    if (n <= 1) return false;
//    int tong = 1;
//    for (int i = 2; i <= n / 2; i++) {
//        if (n % i == 0) tong += i;
//    }
//    return tong == n;
//}
//
//bool laSoNguyenTo(int n) {
//    if (n <= 1) return false;
//    for (int i = 2; i <= sqrt(n); i++) {
//        if (n % i == 0) return false;
//    }
//    return true;
//}
//
//int chuSoDauTien(int n) {
//    n = abs(n);
//    while (n >= 10) {
//        n /= 10;
//    }
//    return n;
//}
//
//void nhapMaTran(int a[][100], int m, int n) {
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            printf("Nhap a[%d][%d]: ", i, j);
//            scanf("%d", &a[i][j]);
//        }
//    }
//}
//
//void xuatMaTran(int a[][100], int m, int n) {
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            printf("%d ", a[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//int tinhTongChuSoDauLe(int a[][100], int m, int n) {
//    int tong = 0;
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            if (chuSoDauTien(a[i][j]) % 2 != 0) {
//                tong += a[i][j];
//            }
//        }
//    }
//    return tong;
//}
//
//void lietKeSoHoanThien(int a[][100], int m, int n) {
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            if (laSoHoanThien(a[i][j])) {
//                printf("%d ", a[i][j]);
//            }
//        }
//    }
//    printf("\n");
//}
//
//int tinhTongLonHonTriTuyetDoiSau(int a[][100], int m, int n) {
//    int tong = 0;
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n - 1; j++) {
//            if (a[i][j] > abs(a[i][j + 1])) {
//                tong += a[i][j];
//            }
//        }
//    }
//    return tong;
//}
//
//int tinhTongDongK(int a[][100], int m, int n, int k) {
//    int tong = 0;
//    for (int j = 0; j < n; j++) {
//        tong += a[k][j];
//    }
//    return tong;
//}
//
//int tinhTongBien(int a[][100], int m, int n) {
//    int tong = 0;
//    for (int j = 0; j < n; j++) {
//        tong += a[0][j] + a[m - 1][j];
//    }
//    for (int i = 1; i < m - 1; i++) {
//        tong += a[i][0] + a[i][n - 1];
//    }
//    return tong;
//}
//
//int demTanSuatX(int a[][100], int m, int n, int x) {
//    int dem = 0;
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            if (a[i][j] == x) {
//                dem++;
//            }
//        }
//    }
//    return dem;
//}
//
//void demCacLoaiPhanTu(int a[][100], int m, int n, int* chan, int* le, int* am, int* duong, int* nguyento) {
//    *chan = *le = *am = *duong = *nguyento = 0;
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            if (a[i][j] % 2 == 0) (*chan)++;
//            else (*le)++;
//            if (a[i][j] < 0) (*am)++;
//            else if (a[i][j] > 0) (*duong)++;
//            if (laSoNguyenTo(a[i][j])) (*nguyento)++;
//        }
//    }
//}
//
//
//int main() {
//    int a[100][100], m = 4, n = 5;
//    int chan, le, am, duong, nguyento;
//
//    // Khởi tạo ma trận mẫu
//    int maTranMau[4][5] = {
//        {15, 24, -35, 16, 7},
//        {6, 28, 9, 10, 12},
//        {20, -11, 19, 18, 21},
//        {25, 14, 17, 13, -22}
//    };
//
//    // Sao chép ma trận mẫu vào ma trận chính
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            a[i][j] = maTranMau[i][j];
//        }
//    }
//
//    printf("Ma tran:\n");
//    xuatMaTran(a, m, n);
//
//    printf("\nTong cac phan tu co chu so dau la chu so le: %d\n", tinhTongChuSoDauLe(a, m, n));
//
//    printf("Ma tran:\n");
//    xuatMaTran(a, m, n);
//    printf("\nCac so hoan thien trong ma tran: ");
//    lietKeSoHoanThien(a, m, n);
//
//    printf("Ma tran:\n");
//    xuatMaTran(a, m, n);
//    printf("\nTong cac phan tu lon hon tri tuyet doi cua phan tu lien sau: %d\n", tinhTongLonHonTriTuyetDoiSau(a, m, n));
//
//    printf("Ma tran:\n");
//    xuatMaTran(a, m, n);
//    int k = 2; // Ví dụ tính tổng dòng k = 2
//    printf("\nTong gia tri tren dong %d cua ma tran: %d\n", k, tinhTongDongK(a, m, n, k));
//
//    printf("Ma tran:\n");
//    xuatMaTran(a, m, n);
//    printf("\nTong cac gia tri nam tren bien cua ma tran: %d\n", tinhTongBien(a, m, n));
//
//    printf("Ma tran:\n");
//    xuatMaTran(a, m, n);
//    int x = 19; // Ví dụ tìm giá trị x = 19
//    printf("\nTan suat xuat hien cua gia tri %d trong ma tran: %d\n", x, demTanSuatX(a, m, n, x));
//
//    printf("Ma tran:\n");
//    xuatMaTran(a, m, n);
//    demCacLoaiPhanTu(a, m, n, &chan, &le, &am, &duong, &nguyento);
//    printf("\nSo luong phan tu chan: %d\n", chan);
//    printf("So luong phan tu le: %d\n", le);
//    printf("So luong phan tu am: %d\n", am);
//    printf("So luong phan tu duong: %d\n", duong);
//    printf("So luong phan tu la so nguyen to: %d\n", nguyento);
//
//    return 0;
//}
