#include <stdio.h>

int main() {
    int position, years, projects;
    int baseSalary = 0;
    float expBonus = 0, specialBonus = 0, netSalary = 0;

    // รับค่าตำแหน่ง
    printf("Enter Position (1=Junior, 2=Mid-Level, 3=Senior): ");
    if (scanf("%d", &position) != 1 ) {
        printf("Error: Invalid input for Position!\n");
        return 1;
    }
    // ตรวจสอบว่าเป็น 1, 2 หรือ 3 เท่านั้น
    if (position != 1 && position != 2 && position != 3) {
        printf("Error: Invalid position! Must be 1, 2, or 3.\n");
        return 1;
    }

    // รับค่าปีประสบการณ์
    printf("Enter Years of Experience: ");
    if (scanf("%d", &years) != 1) {
        printf("Error: Invalid input for Years of Experience!\n");
        return 1;
    }

    // รับค่าจำนวนโปรเจค
    printf("Enter Number of Projects Completed this Year: ");
    if (scanf("%d", &projects) != 1) {
        printf("Error: Invalid input for Projects!\n");
        return 1;
    }

    // กำหนดเงินเดือนพื้นฐาน
    switch(position) {
        case 1: baseSalary = 20000; break;
        case 2: baseSalary = 35000; break;
        case 3: baseSalary = 50000; break;
        default: 
            printf("Invalid Position!\n");
            return 1;
    }

    // คำนวณโบนัสตามอายุงาน
    if (years < 1) {
        expBonus = 0;
    } else if (years <= 3) {
        expBonus = baseSalary * 0.10;
    } else if (years <= 5) {
        expBonus = baseSalary * 0.15;
    } else {
        expBonus = baseSalary * 0.20;
    }

    // คำนวณโบนัสพิเศษจากจำนวนโปรเจค
    if (projects > 5) {
        specialBonus = baseSalary * 0.05;
    }

    // คำนวณเงินเดือนสุทธิ
    netSalary = baseSalary + expBonus + specialBonus;

    // แสดงผล
    printf("Base Salary: %d THB\n", baseSalary);
    printf("Experience Bonus: %.0f THB\n", expBonus);
    printf("Special Bonus: %.0f THB\n", specialBonus);
    printf("Net Salary: %.0f THB\n", netSalary);

    return 0;
}
