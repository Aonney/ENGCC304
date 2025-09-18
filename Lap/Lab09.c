#include <stdio.h>
#include <math.h>

// ฟังก์ชันตรวจสอบจำนวนเฉพาะ
int isPrime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    
    printf("ใส่จำนวนครั้ง :");
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("ขออภัย !! โปรดใส่ข้อมูลเป็นตัวเลขเท่านั้น\n");
        // ล้าง buffer input
        while (getchar() != '\n');
        printf("ใส่จำนวนครั้ง :");
    }
    
    int arr[n];
    
    // รับค่าจากผู้ใช้ พร้อมตรวจสอบว่าเป็นตัวเลข
    for (int i = 0; i < n; i++) {
        printf("ใส่ตัวเลข[%d] :", i);
        
        while (scanf("%d", &arr[i]) != 1) {
            printf("ขออภัย ! ! โปรดใส่ข้อมูลเป็นตัวเลขเท่านั้น\n");
            // ล้าง buffer input
            while (getchar() != '\n');
            printf("ใส่ตัวเลข[%d] :\n", i);
        }
    }
    
    // แสดงผล index
    printf("\nIndex: ");
    for (int i = 0; i < n; i++) {
        printf(" %d", i);
    }
    printf("\n");
    
    // แสดงผล array (เฉพาะจำนวนเฉพาะ)
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            printf(" %d", arr[i]);
        } else {
            printf(" #");
        }
    }
    printf("\n");
    
    return 0;
}
