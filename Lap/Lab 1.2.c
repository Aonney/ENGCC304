#include <stdio.h> // แก้ไข stduio.h เป็น stdio.h

int main() {
    char Name[50];
    int  Age = 0;

    // การรับค่าตัวแปร
    printf("Enter your name: "); // ต้องมีเครื่องหมาย ; ปิดท้าย
    scanf("%s", Name); // บรรทัดนี้ถูกต้องแล้ว

    printf("Enter your age: ");
    scanf("%d", &Age); // *** สำคัญ: ต้องใส่เครื่องหมาย & หน้าตัวแปร Age เมื่อรับค่า int ด้วย scanf ***

    // การแสดงผล
    printf("- - - - - -\n"); // แก้ไข print เป็น printf
    printf("Hello %s \n", Name); // เติมตัวแปร Name
    printf("Age = %d\n", Age); // เติมตัวแปร Age
    
    return 0; // เพิ่ม return 0 เพื่อจบการทำงานของ main function อย่างสมบูรณ์
} //end main function
