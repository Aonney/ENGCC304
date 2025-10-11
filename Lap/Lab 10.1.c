#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 100 // กำหนดขนาดสูงสุดของคำ

/**
 * ฟังก์ชันสำหรับตรวจสอบว่าคำที่กำหนดเป็น Palindrome หรือไม่
 * โดยมีการแปลงตัวอักษรให้เป็นตัวพิมพ์เล็กทั้งหมดก่อน
 *
 * @param str คำ/วลีที่ต้องการตรวจสอบ
 * @return true ถ้าเป็น Palindrome, false ถ้าไม่ใช่
 */
bool isPalindrome(char str[]) {
    int len = strlen(str);
    int left = 0;
    int right = len - 1;

    // สร้างสำเนาของสตริงเพื่อแปลงเป็นตัวพิมพ์เล็ก
    char lower_str[MAX_SIZE];
    // ตรวจสอบขนาดไม่ให้เกิน MAX_SIZE เพื่อความปลอดภัย (แม้ว่าในกรณีนี้จะรับประกันจาก MAX_SIZE ของ str)
    if (len >= MAX_SIZE) {
        // จัดการกรณีที่ยาวเกินไป ถ้าจำเป็น
        return false;
    }
    strcpy(lower_str, str);

    // 1. แปลงสตริงให้เป็นตัวพิมพ์เล็กทั้งหมด
    for (int i = 0; i < len; i++) {
        lower_str[i] = tolower((unsigned char)lower_str[i]);
    }

    // 2. ตรวจสอบ Palindrome โดยใช้ตัวชี้สองตัว (left และ right)
    while (left < right) {
        // หากตัวอักษรที่ตำแหน่งซ้ายและขวาไม่ตรงกัน แสดงว่าไม่ใช่ Palindrome
        if (lower_str[left] != lower_str[right]) {
            return false;
        }
        // เลื่อนตัวชี้เข้าหากัน
        left++;
        right--;
    }

    // หากวนลูปจนจบโดยไม่มีการคืนค่า false แสดงว่าเป็น Palindrome
    return true;
}

int main() {
    char word[MAX_SIZE];

    // รับคำจากผู้ใช้
    printf("Enter word:\n");
    // ใช้ fgets เพื่อรองรับการรับค่าที่มีช่องว่าง (ถ้าผู้ใช้กรอกวลี) 
    // และปลอดภัยกว่า scanf สำหรับสตริง
    if (fgets(word, MAX_SIZE, stdin) == NULL) {
        return 1; // สิ้นสุดหากรับค่าไม่ได้
    }

    // ลบอักขระขึ้นบรรทัดใหม่ ('\n') ที่ fgets อาจเพิ่มเข้ามา
    word[strcspn(word, "\n")] = 0;

    // ตรวจสอบและแสดงผลลัพธ์
    if (isPalindrome(word)) {
        printf("Pass.\n");
    } else {
        printf("Not Pass.\n");
    }

    return 0;
}
