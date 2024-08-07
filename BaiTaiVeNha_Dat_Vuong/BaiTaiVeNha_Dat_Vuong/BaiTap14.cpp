#include <stdio.h>

// Bài 1: Tính tổng các phần tử nằm trên đường chéo chính
int sumMainDiagonal(int a[100][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i][i];
    }
    return sum;
}

// Bài 2: Tính tổng các phần tử nằm trên đường chéo phụ
int sumSecondaryDiagonal(int a[100][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i][n - i - 1];
    }
    return sum;
}

// Bài 3: Tính tổng các phần tử nằm phía trên đường chéo chính
int sumAboveMainDiagonal(int a[100][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}

// Bài 4: Tính tổng các phần tử nằm phía trên đường chéo phụ
int sumAboveSecondaryDiagonal(int a[100][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}

int main() {
    int n = 4;
    int a[100][100] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // Bài 1: Tính tổng các phần tử nằm trên đường chéo chính
    int sumMain = sumMainDiagonal(a, n);
    printf("Bai 1: Tong cac phan tu tren duong cheo chinh la: %d\n", sumMain);

    // Bài 2: Tính tổng các phần tử nằm trên đường chéo phụ
    int sumSecondary = sumSecondaryDiagonal(a, n);
    printf("Bai 2: Tong cac phan tu tren duong cheo phu la: %d\n", sumSecondary);

    // Bài 3: Tính tổng các phần tử nằm phía trên đường chéo chính
    int sumAboveMain = sumAboveMainDiagonal(a, n);
    printf("Bai 3: Tong cac phan tu nam phia tren duong cheo chinh la: %d\n", sumAboveMain);

    // Bài 4: Tính tổng các phần tử nằm phía trên đường chéo phụ
    int sumAboveSecondary = sumAboveSecondaryDiagonal(a, n);
    printf("Bai 4: Tong cac phan tu nam phia tren duong cheo phu la: %d\n", sumAboveSecondary);

    return 0;
}
