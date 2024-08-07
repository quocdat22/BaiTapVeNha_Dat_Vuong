#include <stdio.h>
#include <limits.h>

int isPerfectNumber(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

//in mat tran
void printMatrix(int a[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main() {
    int m = 4;
    int n = 5; // Số hàng và số cột của ma trận
    int a[100][100] = {
        {28, 6, 3, 7, 1},
        {6, 15, 2, 4, 3},
        {4, 8, 496, 10, 12},
        {2, 18, 22, 3, 6}
    };

    // Bài 1: Liệt kê các cột có tổng nhỏ nhất trong ma trận
    int minSum = INT_MAX;
    int sum[5];
    for (int j = 0; j < n; j++) {
        sum[j] = 0;
        for (int i = 0; i < m; i++) {
            sum[j] += a[i][j];
        }
        if (sum[j] < minSum) {
            minSum = sum[j];
        }
    }

    printf("Bai 1: Cac cot co tong nho nhat:\n");
    printMatrix(a, m, n);
    for (int j = 0; j < n; j++) {
        if (sum[j] == minSum) {
            printf("Cot %d\n", j);
        }
    }

    // Bài 2: Liệt kê các dòng có nhiều số hoàn thiện nhất trong ma trận
    printMatrix(a, m, n);
    int maxPerfect = 0;
    int countPerfect[4];
    for (int i = 0; i < m; i++) {
        countPerfect[i] = 0;
        for (int j = 0; j < n; j++) {
            if (isPerfectNumber(a[i][j])) {
                countPerfect[i]++;
            }
        }
        if (countPerfect[i] > maxPerfect) {
            maxPerfect = countPerfect[i];
        }
    }

    printf("\nBai 2: Cac dong co nhieu so hoan thien nhat:\n");
    printMatrix(a, m, n);
    for (int i = 0; i < m; i++) {
        if (countPerfect[i] == maxPerfect) {
            printf("Dong %d\n", i);
        }
    }

    // Bài 3: Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
    printf("\nBai 3: Cac dong chua toan gia tri chan:\n");
    printMatrix(a, m, n);
    for (int i = 0; i < m; i++) {
        int allEven = 1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                allEven = 0;
                break;
            }
        }
        if (allEven) {
            printf("Dong %d\n", i);
        }
    }

    // Bài 4: Tìm giá trị xuất hiện nhiều nhất trong ma trận
    int maxCount = 0, maxValue;
    int count[4 * 5];
    int values[4 * 5];
    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int value = a[i][j];
            int found = 0;
            for (int l = 0; l < k; l++) {
                if (values[l] == value) {
                    count[l]++;
                    found = 1;
                    if (count[l] > maxCount) {
                        maxCount = count[l];
                        maxValue = value;
                    }
                    break;
                }
            }
            if (!found) {
                values[k] = value;
                count[k] = 1;
                if (count[k] > maxCount) {
                    maxCount = count[k];
                    maxValue = value;
                }
                k++;
            }
        }
    }
    printMatrix(a, m, n);
    printf("\nBai 4: Gia tri xuat hien nhieu nhat trong ma tran la: %d\n", maxValue);

    // Bài 5: Tìm số nguyên tố nhỏ nhất trong ma trận
    int minPrime = INT_MAX;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(a[i][j]) && a[i][j] < minPrime) {
                minPrime = a[i][j];
            }
        }
    }
    printMatrix(a, m, n);
    if (minPrime == INT_MAX) {
        printf("\nBai 5: Khong co so nguyen to trong ma tran.\n");
    }
    else {
        printf("\nBai 5: So nguyen to nho nhat trong ma tran la: %d\n", minPrime);
    }

    // Bài 6: Tìm phần tử lớn (nhỏ) nhất trong dòng thứ k
    printMatrix(a, m, n);
    int k_row = 2; // Dòng thứ k
    int maxInRow = INT_MIN;
    int minInRow = INT_MAX;
    for (int j = 0; j < n; j++) {
        if (a[k_row][j] > maxInRow) {
            maxInRow = a[k_row][j];
        }
        if (a[k_row][j] < minInRow) {
            minInRow = a[k_row][j];
        }
    }

    printf("\nBai 6: Phan tu lon nhat trong dong thu %d la: %d\n", k_row, maxInRow);
    printf("Phan tu nho nhat trong dong thu %d la: %d\n", k_row, minInRow);

    // Bài 7: Tìm phần tử lớn (nhỏ) nhất trong cột thứ k

    int k_col = 1; // Cột thứ k
    int maxInCol = INT_MIN;
    int minInCol = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (a[i][k_col] > maxInCol) {
            maxInCol = a[i][k_col];
        }
        if (a[i][k_col] < minInCol) {
            minInCol = a[i][k_col];
        }
    }
    printMatrix(a, m, n);
    printf("\nBai 7: Phan tu lon nhat trong cot thu %d la: %d\n", k_col, maxInCol);
    
    printf("Phan tu nho nhat trong cot thu %d la: %d\n", k_col, minInCol);
    printMatrix(a, m, n);
    return 0;
}
