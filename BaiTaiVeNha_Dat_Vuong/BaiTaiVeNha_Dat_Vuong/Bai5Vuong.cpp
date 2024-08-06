#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}
bool isAllPrime(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (!isPrime(arr[i])) return false;
    }
    return true;
}
bool isSymmetric(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - 1 - i]) return false;
    }
    return true;
}
bool isAscending(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

bool isDescending(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) return false;
    }
    return true;
}

bool isUnsorted(int arr[], int n) {
    return !(isAscending(arr, n) || isDescending(arr, n));
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf_s("%d", &n);

    int* a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        perror("Failed to allocate memory for array");
        return EXIT_FAILURE;
    }
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &a[i]);
    }
    if (isAllPrime(a, n)) {
        printf("Mang chua toan bo so nguyen to.\n");
    }
    else {
        printf("Mang khong chua toan bo so nguyen to.\n");
    }

    if (isSymmetric(a, n)) {
        printf("Mang la doi xung.\n");
    }
    else {
        printf("Mang khong la doi xung.\n");
    }

    if (isAscending(a, n)) {
        printf("Mang la day tang dan.\n");
    }
    else if (isDescending(a, n)) {
        printf("Mang la day giam dan.\n");
    }
    else {
        printf("Mang khong tang dan khong giam dan.\n");
    }
    free(a);

    return 0;
}
