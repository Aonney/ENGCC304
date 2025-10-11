#include <stdio.h>

// ฟังก์ชันสำหรับสลับค่าตัวเลขโดยใช้ Pointer และห้ามใช้ตัวแปรพักค่า
void swapNumbers(int *a, int *b) {
    // 1. นำค่า a บวกเพิ่มเข้าไปใน b (b = b + a)
    //    ตอนนี้ *b เก็บผลรวมของค่าเดิมของ *a และ *b
    *b = *a + *b;

    // 2. นำผลรวม (*b) ลบด้วยค่า *a ที่อยู่ใน *b
    //    ผลลัพธ์คือค่าเดิมของ *b จะถูกเก็บไว้ใน *a
    //    (*a = (*a + *b_เดิม) - *a_เดิม) => *a = *b_เดิม
    *a = *b - *a;

    // 3. นำผลรวม (*b) ลบด้วยค่า *a ใหม่ (ซึ่งเป็นค่าเดิมของ *b)
    //    ผลลัพธ์คือค่าเดิมของ *a จะถูกเก็บไว้ใน *b
    //    (*b = (*a_เดิม + *b_เดิม) - *b_เดิม) => *b = *a_เดิม
    *b = *b - *a;
}

int main() {
    // 1. ประกาศตัวแปร num1 และ num2
    int num1, num2;

    printf("Enter num1 :\n");
    scanf("%d", &num1);
    printf("Enter num2 :\n");
    scanf("%d", &num2);
    
    // 2. ประกาศ Pointer เพื่อเก็บค่าที่อยู่ของ num1 และ num2
    int *ptr1 = &num1;
    int *ptr2 = &num2;

    // แสดงค่าก่อนการสลับ
    printf("Before swap (num1 & num2) : %d, %d\n", num1, num2);

    // 5. เรียกใช้ฟังก์ชัน swapNumbers โดยส่ง Pointer เข้าไป
    //    การทำงานในฟังก์ชันจะกระทำที่ค่าที่อยู่ของตัวแปร num1 และ num2 โดยตรง
    swapNumbers(ptr1, ptr2);

    // 6. แสดงค่าหลังการสลับ
    printf("After swap (num1 & num2) : %d, %d\n", num1, num2);

    return 0;
}
