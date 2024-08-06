#include <stdio.h>
#include <stdlib.h>  


void nhapMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu arr[%d]: ", i);
        scanf_s("%d", &arr[i]);
    }
}

void xuatMang(int arr[], int n) {
    printf("Mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sapXepTangDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf_s("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho cho mang\n");
        return 1; 
    }


    nhapMang(arr, n);
    printf("Mang truoc khi sap xep:\n");
    xuatMang(arr, n);
    sapXepTangDan(arr, n);
    printf("Mang sau khi sap xep tang dan:\n");
    xuatMang(arr, n);
    free(arr);

    return 0;
}

