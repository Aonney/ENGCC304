#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// ฟังก์ชันสำหรับคำนวณเลขยกกำลัง (Base^Exp)
// เนื่องจาก math.h มีฟังก์ชัน pow() ที่คืนค่าเป็น double
// เราจะเขียนฟังก์ชันสำหรับจำนวนเต็มเอง เพื่อความแม่นยำในการคำนวณตัวเลข Armstrong
int integer_power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

/**
 * ฟังก์ชันหลักในการตรวจสอบตัวเลขอาร์มสตรอง
 *
 * @param n ตัวเลขที่ต้องการตรวจสอบ
 * @return true ถ้าเป็น Armstrong Number, false ถ้าไม่ใช่
 */
bool isArmstrong(int n) {
    if (n < 0) {
        return false; // ตัวเลข Armstrong มักจะนิยามสำหรับจำนวนเต็มบวก
    }
    if (n >= 0 && n < 10) {
        return true; // ตัวเลขหลักเดียวทั้งหมดเป็น Armstrong (เช่น 5^1 = 5)
    }

    // 1. นับจำนวนหลักของตัวเลข (power)
    int temp = n;
    int power = 0;
    while (temp != 0) {
        temp /= 10;
        power++;
    }

    // 2. คำนวณผลรวมของเลขยกกำลังของแต่ละหลัก
    int sum = 0;
    temp = n;
    int digit;

    while (temp != 0) {
        digit = temp % 10; // ดึงหลักสุดท้าย
        sum += integer_power(digit, power);
        temp /= 10; // ตัดหลักสุดท้ายออก
    }

    // 3. ตรวจสอบเงื่อนไข
    return sum == n;
}

int main() {
    int number;

    // รับตัวเลขจากผู้ใช้
    printf("Enter Number:\n");
    // ตรวจสอบความถูกต้องของการรับค่า
    if (scanf("%d", &number) != 1) {
        printf("Invalid Input.\n");
        return 1;
    }

    // เรียกใช้ฟังก์ชันตรวจสอบและแสดงผลลัพธ์
    if (isArmstrong(number)) {
        printf("Pass.\n");
    } else {
        printf("Not Pass.\n");
    }

    return 0;
}
