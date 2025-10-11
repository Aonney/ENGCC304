#include <stdio.h>
#include <math.h>
#include <stdbool.h> // สำหรับใช้ชนิดข้อมูล bool (True/False)
#include <stdlib.h> // 💡 แก้ไข: จำเป็นสำหรับฟังก์ชัน malloc และ free

// ฟังก์ชันสำหรับตรวจสอบว่าจำนวนเต็มเป็นจำนวนเฉพาะหรือไม่
// คืนค่า true หากเป็นจำนวนเฉพาะ, คืนค่า false หากไม่ใช่
bool isPrime(int num) {
    // 1. ตรวจสอบเงื่อนไขพื้นฐาน
    if (num < 2) {
        return false;
    }

    // 2. ตรวจสอบการหารลงตัว
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // พบตัวหาร, ไม่ใช่จำนวนเฉพาะ
        }
    }
    
    return true; // เป็นจำนวนเฉพาะ
}

int main() {
    int n; // จำนวนสมาชิกของ Array
    
    // 1. รับค่า N จากผู้ใช้
    printf("Enter N (Array size): ");
    
    // ตรวจสอบความถูกต้องของการป้อนค่า
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Invalid input or N must be a positive integer.\n");
        return 1;
    }

    // 💡 แก้ไข Bug ที่ใหญ่ที่สุด: ขาด <stdlib.h> ทำให้ compiler ไม่รู้จัก malloc/free
    // ใช้การจัดสรรหน่วยความจำแบบไดนามิก (Dynamic Allocation)
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // 2. รับค่าสมาชิกแต่ละตัวของ Array
    for (int i = 0; i < n; i++) {
        printf("Enter value[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // 3. แสดงผล Index ของ Array
    printf("\nIndex:  ");
    for (int i = 0; i < n; i++) {
        printf("%3d", i); // ใช้ %3d เพื่อจัดรูปแบบให้สวยงาม
    }
    printf("\n");

    // 4. แสดงผล Array พร้อมทำเครื่องหมายจำนวนเฉพาะ
    printf("Array:  ");
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            printf("%3d", arr[i]); // แสดงจำนวนเฉพาะ
        } else {
            printf("%3s", "#"); // แสดงเครื่องหมาย #
        }
    }
    printf("\n");

    // คืนหน่วยความจำที่จัดสรร
    free(arr);
    
    return 0;
}
