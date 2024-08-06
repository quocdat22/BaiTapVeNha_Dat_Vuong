#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void interchangeSortIntAsc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}
void interchangeSortIntDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            int temp = arr[i];
            arr[i] = arr[maxIdx];
            arr[maxIdx] = temp;
        }
    }
}
void interchangeSortFloatAsc(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            float temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

void interchangeSortFloatDesc(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            float temp = arr[i];
            arr[i] = arr[maxIdx];
            arr[maxIdx] = temp;
        }
    }
}
void interchangeSortCharAsc(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            char temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}
void interchangeSortCharDesc(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            char temp = arr[i];
            arr[i] = arr[maxIdx];
            arr[maxIdx] = temp;
        }
    }
}
void interchangeSortStringAsc(char* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[minIdx]) < 0) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            char* temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

void interchangeSortStringDesc(char* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[maxIdx]) > 0) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            char* temp = arr[i];
            arr[i] = arr[maxIdx];
            arr[maxIdx] = temp;
        }
    }
}

int main() {
    int n, choice;
    printf("Nhap so phan tu cua mang so nguyen: ");
    scanf_s("%d", &n);
    int* intArr = (int*)malloc(n * sizeof(int));
    if (intArr == NULL) {
        perror("Failed to allocate memory for intArr");
        return EXIT_FAILURE;
    }
    printf("Nhap cac phan tu cua mang so nguyen:\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &intArr[i]);
    }

    printf("Chon thao tac:\n1. Sap xep tang dan\n2. Sap xep giam dan\n");
    scanf_s("%d", &choice);
    if (choice == 1) {
        interchangeSortIntAsc(intArr, n);
        printf("Mang so nguyen sau khi sap xep tang dan:\n");
    }
    else if (choice == 2) {
        interchangeSortIntDesc(intArr, n);
        printf("Mang so nguyen sau khi sap xep giam dan:\n");
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", intArr[i]);
    }
    printf("\n");
    free(intArr);
    printf("Nhap so phan tu cua mang so thuc: ");
    scanf_s("%d", &n);
    float* floatArr = (float*)malloc(n * sizeof(float));
    if (floatArr == NULL) {
        perror("Failed to allocate memory for floatArr");
        return EXIT_FAILURE;
    }
    printf("Nhap cac phan tu cua mang so thuc:\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%f", &floatArr[i]);
    }

    printf("Chon thao tac:\n1. Sap xep tang dan\n2. Sap xep giam dan\n");
    scanf_s("%d", &choice);
    if (choice == 1) {
        interchangeSortFloatAsc(floatArr, n);
        printf("Mang so thuc sau khi sap xep tang dan:\n");
    }
    else if (choice == 2) {
        interchangeSortFloatDesc(floatArr, n);
        printf("Mang so thuc sau khi sap xep giam dan:\n");
    }
    for (int i = 0; i < n; i++) {
        printf("%f ", floatArr[i]);
    }
    printf("\n");
    free(floatArr);
    printf("Nhap so phan tu cua mang ky tu: ");
    scanf_s("%d", &n);
    char* charArr = (char*)malloc(n * sizeof(char));
    if (charArr == NULL) {
        perror("Failed to allocate memory for charArr");
        return EXIT_FAILURE;
    }
    printf("Nhap cac phan tu cua mang ky tu:\n");
    for (int i = 0; i < n; i++) {
        scanf_s(" %c", &charArr[i]);
    }

    printf("Chon thao tac:\n1. Sap xep tang dan\n2. Sap xep giam dan\n");
    scanf_s("%d", &choice);
    if (choice == 1) {
        interchangeSortCharAsc(charArr, n);
        printf("Mang ky tu sau khi sap xep tang dan:\n");
    }
    else if (choice == 2) {
        interchangeSortCharDesc(charArr, n);
        printf("Mang ky tu sau khi sap xep giam dan:\n");
    }
    for (int i = 0; i < n; i++) {
        printf("%c ", charArr[i]);
    }
    printf("\n");
    free(charArr);
    printf("Nhap so phan tu cua mang chuoi ky tu: ");
    scanf_s("%d", &n);
    char** stringArr = (char**)malloc(n * sizeof(char*));
    if (stringArr == NULL) {
        perror("Failed to allocate memory for stringArr");
        return EXIT_FAILURE;
    }
    printf("Nhap cac chuoi ky tu:\n");
    for (int i = 0; i < n; i++) {
        stringArr[i] = (char*)malloc(100 * sizeof(char));
        if (stringArr[i] == NULL) {
            perror("Failed to allocate memory for stringArr[i]");
            return EXIT_FAILURE;
        }
        scanf_s("%s", stringArr[i], 100);
    }

    printf("Chon thao tac:\n1. Sap xep tang dan\n2. Sap xep giam dan\n");
    scanf_s("%d", &choice);
    if (choice == 1) {
        interchangeSortStringAsc(stringArr, n);
        printf("Mang chuoi ky tu sau khi sap xep tang dan:\n");
    }
    else if (choice == 2) {
        interchangeSortStringDesc(stringArr, n);
        printf("Mang chuoi ky tu sau khi sap xep giam dan:\n");
    }
    for (int i = 0; i < n; i++) {
        printf("%s ", stringArr[i]);
        free(stringArr[i]);
    }
    free(stringArr);
    printf("\n");

    return 0;
}
