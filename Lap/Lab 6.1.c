#include <stdio.h>

/**
 * โปรแกรมสำหรับแปลงตัวเลขที่ผู้ใช้ป้อนให้เป็นตัวหนังสือ
 * รองรับตัวเลขในช่วง 0 ถึง 20
 */
int main() {
    int num;

    // 1. รับค่าตัวเลขจากผู้ใช้
    printf("User Input :");
    
    if (scanf("%d", &num) != 1) {
        printf("Error: Invalid input. Please enter a valid number.\n");
        return 1;
    }

    printf("Result : ");

    // 2. ใช้ if-else if เพื่อตรวจสอบและแสดงผลลัพธ์
    if (num == 0) {
        printf("zero\n");
    } 
    else if (num == 1) {
        printf("one\n");
    } 
    else if (num == 2) {
        printf("two\n");
    } 
    else if (num == 3) {
        printf("three\n");
    } 
    else if (num == 4) {
        printf("four\n");
    } 
    else if (num == 5) {
        printf("five\n");
    } 
    else if (num == 6) {
        printf("six\n");
    } 
    else if (num == 7) {
        printf("seven\n");
    } 
    else if (num == 8) {
        printf("eight\n");
    } 
    else if (num == 9) {
        printf("nine\n");
    } 
    else if (num == 10) {
        printf("ten\n");
    } 
    else if (num == 11) {
        printf("eleven\n");
    } 
    else if (num == 12) {
        printf("twelve\n");
    } 
    // เพิ่มตัวเลขอื่นๆ ที่มักใช้ในการสอน เช่น 13-20
    else if (num == 13) {
        printf("thirteen\n");
    } 
    else if (num == 14) {
        printf("fourteen\n");
    } 
    else if (num == 15) {
        printf("fifteen\n");
    } 
    else if (num == 16) {
        printf("sixteen\n");
    } 
    else if (num == 17) {
        printf("seventeen\n");
    } 
    else if (num == 18) {
        printf("eighteen\n");
    } 
    else if (num == 19) {
        printf("nineteen\n");
    } 
    else if (num == 20) {
        printf("twenty\n");
    } 
    else {
        // จัดการกรณีที่ตัวเลขอยู่นอกช่วงที่กำหนด
        printf("Number is out of range (0-20) or unknown.\n");
    }

    return 0;
}
