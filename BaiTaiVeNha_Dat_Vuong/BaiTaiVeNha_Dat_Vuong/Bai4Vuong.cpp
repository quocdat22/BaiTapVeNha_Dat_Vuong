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

bool areAllDigitsOdd(int num) {
   while (num > 0) {
       int digit = num % 10;
       if (digit % 2 == 0) return false;
       num /= 10;
   }
   return true;
}

int findLastMaxPosition(int arr[], int n) {
   int max = arr[0];
   int lastPos = 0;
   for (int i = 0; i < n; i++) {
       if (arr[i] >= max) {
           max = arr[i];
           lastPos = i;
       }
   }
   return lastPos;
}

bool isAllEven(int arr[], int n) {
   for (int i = 0; i < n; i++) {
       if (arr[i] % 2 != 0) return false;
   }
   return true;
}

bool isAlternatingEvenOdd(int arr[], int n) {
   if (n < 2) return true; 
   bool expectingEven = arr[0] % 2 == 0;
   for (int i = 1; i < n; i++) {
       if ((arr[i] % 2 == 0) != expectingEven) return false;
       expectingEven = !expectingEven;
   }
   return true;
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

   int primeCount = 0;
   for (int i = 0; i < n; i++) {
       if (isPrime(a[i])) {
           primeCount++;
       }
   }
   printf("So phan tu la so nguyen to: %d\n", primeCount);

   printf("Cac phan tu co tung chu so la so le:\n");
   for (int i = 0; i < n; i++) {
       if (areAllDigitsOdd(a[i])) {
           printf("%d ", a[i]);
       }
   }
   printf("\n");
   int lastMaxPos = findLastMaxPosition(a, n);
   printf("Vi tri cuoi cung cua so lon nhat: %d\n", lastMaxPos);
   if (isAllEven(a, n)) {
       printf("Mang toan so chan.\n");
   }
   else {
       printf("Mang khong toan so chan.\n");
   }
   if (isAlternatingEvenOdd(a, n)) {
       printf("Mang la day so chan-le xen ke.\n");
   }
   else {
       printf("Mang khong phai day so chan-le xen ke.\n");
   }
   free(a);

   return 0;
}
