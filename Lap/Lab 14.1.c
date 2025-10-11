#include <stdio.h>
#include <limits.h> // สำหรับใช้ INT_MAX และ INT_MIN

// กำหนดขนาดสูงสุดของอาเรย์
#define MAX_SIZE 100 

// ฟังก์ชันสำหรับค้นหาค่ามากที่สุดในอาเรย์
// รับอาเรย์ (arr) และขนาดของอาเรย์ (size)
int findMax(int arr[], int size) {
    // กำหนดค่าเริ่มต้นของ max เป็นค่าที่น้อยที่สุดที่เป็นไปได้
    int max = INT_MIN; 
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// ฟังก์ชันสำหรับค้นหาค่าน้อยที่สุดในอาเรย์
// รับอาเรย์ (arr) และขนาดของอาเรย์ (size)
int findMin(int arr[], int size) {
    // กำหนดค่าเริ่มต้นของ min เป็นค่าที่มากที่สุดที่เป็นไปได้
    int min = INT_MAX; 
    
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int arr[MAX_SIZE];
    int count = 0;
    int input;

    printf("Enter value:\n");
    
    // วนลูปเพื่อรับค่าจากผู้ใช้ จนกว่าจะไม่มีค่าให้รับ (หรือถึงขนาดสูงสุด)
    // ในภาษา C การรับข้อมูลในลักษณะนี้จะใช้ scanf วนรับจนกว่าจะเจอ EOF หรือข้อมูลไม่ถูกต้อง
    // แต่เพื่อจำลอง Test Case ให้ใกล้เคียงที่สุด จะใช้การวนรับค่าต่อบรรทัด
    
    // --- ส่วนนี้คือการรับค่าแบบต่อเนื่อง (ตามลักษณะโจทย์ที่รับค่าหลายตัวในบรรทัดเดียว) ---
    // Note: ในการใช้งานจริง ผู้ใช้ต้องคั่นด้วย Space หรือ Enter
    while (scanf("%d", &input) == 1 && count < MAX_SIZE) {
        arr[count] = input;
        count++;
    }
    // ล้างบัฟเฟอร์หลังจากรับค่าเสร็จ (อาจจำเป็นหรือไม่จำเป็นขึ้นอยู่กับคอมไพเลอร์)
    // while (getchar() != '\n' && getchar() != EOF); 
    
    if (count == 0) {
        printf("No values entered.\n");
        return 0;
    }
    
    // 1. แสดง Index และ Array
    printf("Index:");
    for (int i = 0; i < count; i++) {
        printf(" %d", i);
    }
    printf("\n");
    
    printf("Array:");
    for (int i = 0; i < count; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
    
    // 2. เรียกใช้ฟังก์ชันหา Min และ Max
    int minValue = findMin(arr, count);
    int maxValue = findMax(arr, count);
    
    // 3. แสดงผลลัพธ์
    printf("\nMin : %d\n", minValue);
    printf("Max : %d\n", maxValue);

    return 0;
}
