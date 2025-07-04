#include <stdio.h>  // ✅ แก้ชื่อ header จาก stduio.h เป็น stdio.h

int main() {
    char Name[50];
    int Age = 0;

    printf("Enter your name: ");           // ✅ ใส่ ; ครบ
    scanf("%s", Name);                     // ✅ รับค่าชื่อ (string)

    printf("Enter your age: ");           
    scanf("%d", &Age);                     // ✅ ต้องใส่ & เพื่อบอกตำแหน่งหน่วยความจำของตัวแปร

    printf("- - - - - -\n");               // ✅ แก้จาก print เป็น printf

    printf("Hello %s\n", Name);            // ✅ แสดงชื่อ
    printf("Age = %d\n", Age);             // ✅ แสดงอายุ

    return 0;                              // ✅ จบโปรแกรมอย่างถูกต้อง
} // end main function
