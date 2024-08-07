//#include <stdio.h>
//
//// Hàm hoán đổi hai phần tử
//void swap(int* a, int* b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//// Hàm sắp xếp một hàng tăng dần
//void sortRowAscending(int arr[], int size) {
//    for (int i = 0; i < size - 1; i++) {
//        for (int j = i + 1; j < size; j++) {
//            if (arr[i] > arr[j]) {
//                swap(&arr[i], &arr[j]);
//            }
//        }
//    }
//}
//
//// Hàm sắp xếp một hàng giảm dần
//void sortRowDescending(int arr[], int size) {
//    for (int i = 0; i < size - 1; i++) {
//        for (int j = i + 1; j < size; j++) {
//            if (arr[i] < arr[j]) {
//                swap(&arr[i], &arr[j]);
//            }
//        }
//    }
//}
//
//// Bài 1: Sắp xếp các dòng chẵn tăng, dòng lẻ giảm
//void sortRows(int a[100][100], int n, int m) {
//    for (int i = 0; i < n; i++) {
//        if (i % 2 == 0) {
//            sortRowAscending(a[i], m);
//        }
//        else {
//            sortRowDescending(a[i], m);
//        }
//    }
//}
//
//// Hàm sắp xếp một cột tăng dần
//void sortColumnAscending(int a[100][100], int n, int col) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (a[i][col] > a[j][col]) {
//                swap(&a[i][col], &a[j][col]);
//            }
//        }
//    }
//}
//
//// Hàm sắp xếp một cột giảm dần
//void sortColumnDescending(int a[100][100], int n, int col) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (a[i][col] < a[j][col]) {
//                swap(&a[i][col], &a[j][col]);
//            }
//        }
//    }
//}
//
//// Bài 2: Sắp xếp các cột chẵn tăng, cột lẻ giảm
//void sortColumns(int a[100][100], int n, int m) {
//    for (int j = 0; j < m; j++) {
//        if (j % 2 == 0) {
//            sortColumnAscending(a, n, j);
//        }
//        else {
//            sortColumnDescending(a, n, j);
//        }
//    }
//}
//
//// Hàm sắp xếp ma trận tăng dần/giảm dần theo zic-zac
//void sortMatrixZigzag(int a[100][100], int n, int m, int ascending) {
//    int temp[4 * 5];
//    int k = 0;
//
//    // Copy tất cả các phần tử vào mảng tạm thời
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            temp[k++] = a[i][j];
//        }
//    }
//
//    // Sắp xếp mảng tạm thời
//    for (int i = 0; i < k - 1; i++) {
//        for (int j = i + 1; j < k; j++) {
//            if (ascending ? temp[i] > temp[j] : temp[i] < temp[j]) {
//                swap(&temp[i], &temp[j]);
//            }
//        }
//    }
//
//    // Copy lại vào ma trận theo thứ tự zic-zac
//    k = 0;
//    for (int i = 0; i < n; i++) {
//        if (i % 2 == 0) {
//            for (int j = 0; j < m; j++) {
//                a[i][j] = temp[k++];
//            }
//        }
//        else {
//            for (int j = m - 1; j >= 0; j--) {
//                a[i][j] = temp[k++];
//            }
//        }
//    }
//}
//
//// Hàm in ma trận
//void printMatrix(int a[100][100], int n, int m) {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            printf("%d\t", a[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//int main() {
//    int n = 4, m = 5; // Số hàng và số cột của ma trận
//    int a[100][100] = {
//        {28, 6, 3, 7, 1},
//        {6, 15, 2, 4, 3},
//        {4, 8, 496, 10, 12},
//        {2, 18, 22, 3, 6}
//    };
//
//    printf("Ma tran ban dau:\n");
//    printMatrix(a, n, m);
//
//    // Bài 1: Sắp xếp các phần tử trong ma trận sao cho dòng chẵn tăng dòng lẻ giảm
//    sortRows(a, n, m);
//    printf("\nBai 1: Ma tran sau khi sap xep cac dong chan tang, dong le giam:\n");
//    printMatrix(a, n, m);
//
//    // Bài 2: Sắp xếp các phần tử trong ma trận sao cho cột chẵn tăng cột lẻ giảm
//    sortColumns(a, n, m);
//    printf("\nBai 2: Ma tran sau khi sap xep cac cot chan tang, cot le giam:\n");
//    printMatrix(a, n, m);
//
//    // Bài 3: Sắp xếp ma trận tăng dần theo zic-zac
//    sortMatrixZigzag(a, n, m, 1);
//    printf("\nBai 3: Ma tran sau khi sap xep tang dan theo zic-zac:\n");
//    printMatrix(a, n, m);
//
//    return 0;
//}
