#include <stdio.h>

// ฟังก์ชันสลับค่าด้วย pointer โดยไม่ใช้ตัวแปรชั่วคราว
void swapNumbers(int *a, int *b) {
    *a = *a + *b;  // บวกค่าของสองตัวเลข
    *b = *a - *b;  // หาค่า b ใหม่
    *a = *a - *b;  // หาค่า a ใหม่
}

int main() {
    int num1, num2;
    int *ptr1, *ptr2;

    // รับค่าจากผู้ใช้
    printf("Enter num1 : ");
    scanf("%d", &num1);
    printf("Enter num2 : ");
    scanf("%d", &num2);

    // กำหนด pointer
    ptr1 = &num1;
    ptr2 = &num2;

    // แสดงค่าก่อนสลับ
    printf("Before swap (num1 & num2) : %d, %d\n", num1, num2);

    // เรียกใช้ฟังก์ชันสลับ
    swapNumbers(ptr1, ptr2);

    // แสดงค่าหลังสลับ
    printf("After swap (num1 & num2) : %d, %d\n", num1, num2);

    return 0;
}
