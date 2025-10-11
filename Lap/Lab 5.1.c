#include <stdio.h>

/**
 * โปรแกรมคำนวณรายได้พนักงาน
 * รับ รหัสประจำตัว (string), จำนวนชั่วโมงที่ทำงาน (int), และรายได้ต่อชั่วโมง (float)
 * แสดง รหัสประจำตัวพนักงาน และรายได้รวมทั้งหมด
 */
int main() {
    // 1. ประกาศตัวแปร
    // char array สำหรับเก็บรหัสพนักงาน (สูงสุด 10 ตัวอักษร + 1 สำหรับ null terminator)
    char employee_id[11]; 
    int working_hours;
    float salary_per_hour;
    // ใช้ float หรือ double สำหรับรายได้รวม
    float total_salary; 

    // 2. รับข้อมูล รหัสประจำตัวพนักงาน
    printf("Input the Employees ID(Max. 10 chars):\n");
    // ใช้ %10s เพื่อจำกัดการรับข้อมูลไม่ให้เกิน 10 ตัวอักษร
    if (scanf("%10s", employee_id) != 1) {
        printf("Error: Invalid input for Employee ID.\n");
        return 1;
    }

    // 3. รับข้อมูล จำนวนชั่วโมงที่ทำงาน
    printf("Input the working hrs:\n");
    if (scanf("%d", &working_hours) != 1 || working_hours < 0) {
        printf("Error: Invalid input for working hours.\n");
        return 1;
    }
    
    // 4. รับข้อมูล รายได้ต่อชั่วโมง
    printf("Salary amount/hr:\n");
    if (scanf("%f", &salary_per_hour) != 1 || salary_per_hour < 0) {
        printf("Error: Invalid input for salary per hour.\n");
        return 1;
    }

    // 5. คำนวณรายได้ทั้งหมด
    // รายได้ทั้งหมด = จำนวนชั่วโมงที่ทำงาน * รายได้ต่อชั่วโมง
    total_salary = (float)working_hours * salary_per_hour;

    // 6. แสดงผลลัพธ์ตามรูปแบบที่กำหนด
    printf("---- \n"); // เพิ่มบรรทัดแบ่งตาม Test Case
    printf("Expected Output:\n");
    printf("Employees ID = %s\n", employee_id);
    // ใช้ %.2f เพื่อแสดงผลทศนิยม 2 ตำแหน่ง
    printf("Salary = U$ %.2f\n", total_salary);

    return 0;
}
