#include <stdio.h>

// กำหนดค่าคงที่สำหรับเงินเดือนพื้นฐาน
#define SALARY_JUNIOR 20000.00
#define SALARY_MID 35000.00
#define SALARY_SENIOR 50000.00

// ฟังก์ชันสำหรับคำนวณเงินเดือนพื้นฐานตามตำแหน่ง
double calculateBaseSalary(int position) {
    if (position == 1) {
        return SALARY_JUNIOR; // Junior Programmer
    } else if (position == 2) {
        return SALARY_MID;    // Mid-Level Programmer
    } else if (position == 3) {
        return SALARY_SENIOR; // Senior Programmer
    } else {
        return 0.00; // ตำแหน่งไม่ถูกต้อง
    }
}

// ฟังก์ชันสำหรับคำนวณโบนัสตามอายุงาน (เป็นเปอร์เซ็นต์)
double calculateExperienceBonusRate(int years) {
    if (years <= 0) {
        return 0.00; // น้อยกว่า 1 ปี ไม่ได้รับโบนัส
    } else if (years >= 1 && years <= 3) {
        return 0.10; // 1-3 ปี, 10%
    } else if (years >= 4 && years <= 5) {
        return 0.15; // 4-5 ปี, 15%
    } else { // years > 5
        return 0.20; // มากกว่า 5 ปี, 20%
    }
}

// ฟังก์ชันหลักของโปรแกรม
int main() {
    int position;
    int yearsOfExperience;
    int projectsCompleted;

    // 1. รับข้อมูลจากผู้ใช้
    printf("Position: 1 (Junior), 2 (Mid-Level), 3 (Senior): \n");
    if (scanf("%d", &position) != 1) {
        printf("Invalid input for Position.\n");
        return 1;
    }

    printf("Years of Experience: \n");
    if (scanf("%d", &yearsOfExperience) != 1) {
        printf("Invalid input for Years of Experience.\n");
        return 1;
    }

    printf("Number of Projects Completed this Year: \n");
    if (scanf("%d", &projectsCompleted) != 1) {
        printf("Invalid input for Number of Projects.\n");
        return 1;
    }
    
    // ตรวจสอบความถูกต้องของตำแหน่ง
    if (position < 1 || position > 3) {
        printf("Error: Invalid position entered. Position must be 1, 2, or 3.\n");
        return 1;
    }

    // 2. คำนวณเงินเดือนพื้นฐาน
    double baseSalary = calculateBaseSalary(position);

    // 3. คำนวณโบนัสตามอายุงาน
    double experienceRate = calculateExperienceBonusRate(yearsOfExperience);
    double experienceBonus = baseSalary * experienceRate;
    
    // 4. คำนวณโบนัสพิเศษจากโปรเจค
    double specialBonus = 0.00;
    if (projectsCompleted > 5) {
        double specialRate = 0.05; // โบนัสพิเศษ 5%
        specialBonus = baseSalary * specialRate;
    }
    
    // 5. คำนวณเงินเดือนสุทธิ
    double netSalary = baseSalary + experienceBonus + specialBonus;

    // 6. แสดงผลลัพธ์
    printf("\n--- Calculation Results ---\n");
    printf("Base Salary: %.2f THB\n", baseSalary);
    printf("Experience Bonus: %.2f THB\n", experienceBonus);
    printf("Special Bonus: %.2f THB\n", specialBonus);
    printf("Net Salary: %.2f THB\n", netSalary);

    return 0;
}
