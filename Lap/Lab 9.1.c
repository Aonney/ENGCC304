#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * ฟังก์ชันสำหรับตรวจสอบว่าจำนวนที่กำหนดเป็นจำนวนเฉพาะหรือไม่
 *
 * @param num จำนวนเต็มที่ต้องการตรวจสอบ
 * @return true ถ้าเป็นจำนวนเฉพาะ, false ถ้าไม่ใช่
 */
bool isPrime(int num) {
    // 1 และจำนวนที่น้อยกว่าหรือเท่ากับ 1 ไม่ใช่จำนวนเฉพาะ
    if (num <= 1) {
        return false;
    }
    // 2 เป็นจำนวนเฉพาะ
    if (num == 2) {
        return true;
    }
    // จำนวนคู่ที่มากกว่า 2 ไม่ใช่จำนวนเฉพาะ
    if (num % 2 == 0) {
        return false;
    }

    // ตรวจสอบตัวหารที่เป็นจำนวนคี่ ตั้งแต่ 3 ถึง sqrt(num)
    // การตรวจสอบถึงแค่ sqrt(num) ก็เพียงพอ เพราะถ้ามีตัวประกอบที่ใหญ่กว่า
    // จะต้องมีตัวประกอบที่เล็กกว่าที่ถูกตรวจสอบไปแล้ว
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;

    // รับขนาดของอาเรย์
    printf("Enter N :\n");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Invalid input for N. N must be a positive integer.\n");
        return 1; // สิ้นสุดโปรแกรมด้วยข้อผิดพลาด
    }

    int arr[N]; // ประกาศอาเรย์ขนาด N

    // รับค่าเข้าสู่อาเรย์
    for (int i = 0; i < N; i++) {
        printf("Enter value[%d] :\n", i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input for value[%d].\n", i);
            return 1; // สิ้นสุดโปรแกรมด้วยข้อผิดพลาด
        }
    }

    // ส่วนแสดงผลลัพธ์
    printf("\nIndex: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", i);
    }
    printf("\nArray: ");

    for (int i = 0; i < N; i++) {
        if (isPrime(arr[i])) {
            // ถ้าเป็นจำนวนเฉพาะ ให้แสดงผลค่านั้น
            printf("%d ", arr[i]);
        } else {
            // ถ้าไม่ใช่จำนวนเฉพาะ ให้แสดงเครื่องหมาย #
            printf("# ");
        }
    }
    printf("\n");

    return 0;
}
