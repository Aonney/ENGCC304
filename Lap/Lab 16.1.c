#include <stdio.h>
#include <stdbool.h>

int main() {
    // ข้อมูลเริ่มต้นตามโจทย์
    int arr[] = { 15, 7, 25, 3, 73, 32, 45 };
    // คำนวณหาขนาดของอาเรย์
    int n = sizeof(arr) / sizeof(arr[0]);
    // ค่าที่ต้องการค้นหาตำแหน่ง
    int target_value = 32;
    // ตัวแปรสำหรับเก็บตำแหน่ง (เริ่มต้นที่ -1 หมายถึงไม่พบ)
    int target_position = -1;
    // ตัวแปรชั่วคราวสำหรับใช้ในการสลับ
    int temp;
    // ตัวแปรสำหรับตรวจสอบว่ามีการสลับเกิดขึ้นหรือไม่
    bool swapped;

    // 1. แสดง Old Series
    printf("Old Series : ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");

    // 2. จัดเรียงอาเรย์จากน้อยไปมากโดยใช้ Bubble Sort
    // Loop นอก: วน n-1 รอบ
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        // Loop ใน: เปรียบเทียบและสลับ
        for (int j = 0; j < n - i - 1; j++) {
            // ถ้าตัวเลขปัจจุบัน (arr[j]) มากกว่าตัวเลขถัดไป (arr[j+1]) ให้สลับ
            if (arr[j] > arr[j+1]) {
                // สลับค่า
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true; // บันทึกว่ามีการสลับ
            }
        }
        // ถ้าไม่มีการสลับในรอบนี้ แสดงว่าเรียงเสร็จแล้ว
        if (swapped == false) {
            break;
        }
    }

    // 3. แสดง New Series
    printf("New Series : ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");

    // 4. ค้นหาตำแหน่งของหมายเลข 32 ในอาเรย์ที่เรียงแล้ว
    // ตำแหน่งอาเรย์เริ่มต้นจาก 0 แต่ตำแหน่งตามโจทย์เริ่มต้นจาก 1
    for (int i = 0; i < n; i++) {
        if (arr[i] == target_value) {
            // ตำแหน่งตามโจทย์คือ index + 1
            target_position = i + 1;
            break; // พบแล้วจึงออกจากลูป
        }
    }

    // 5. แสดงตำแหน่ง
    if (target_position != -1) {
        printf("Pos of %d : %d\n", target_value, target_position);
    } else {
        printf("Pos of %d : Not found\n", target_value);
    }

    return 0;
}
