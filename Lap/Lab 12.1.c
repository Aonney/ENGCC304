#include <stdio.h>
#include <string.h>

// โครงสร้างข้อมูลนักเรียน (Data Structure)
struct Student {
    char Name[20] ;
    char ID[5] ;
    float ScoreSub1 ;
    float ScoreSub2 ;
    float ScoreSub3 ;
    float ScoreSub4 ;
    float ScoreSub5 ;
} typedef S ;

// ฟังก์ชันสำหรับตัดเกรด (Grading Function)
// การตัดเกรดอิงตาม Test Case ที่กำหนด: 
// A (80+), B+ (75-79), B (70-74), C+ (65-69), C (60-64), D+ (55-59), D (50-54), F (<50)
const char* calculateGrade(float score) {
    if (score >= 80.0) {
        return "A";
    } else if (score >= 75.0) {
        return "B+";
    } else if (score >= 70.0) {
        return "B";
    } else if (score >= 65.0) {
        return "C+";
    } else if (score >= 60.0) {
        return "C";
    } else if (score >= 55.0) {
        return "D+";
    } else if (score >= 50.0) {
        return "D";
    } else {
        return "F";
    }
}

// ฟังก์ชันสำหรับแสดงผลลัพธ์นักเรียน
void displayStudentResults(S student) {
    // คำนวณคะแนนเฉลี่ย
    float averageScore = (student.ScoreSub1 + student.ScoreSub2 + student.ScoreSub3 + student.ScoreSub4 + student.ScoreSub5) / 5.0;

    printf("\nStudent %s:\n", student.ID);
    printf("Name: %s\n", student.Name);
    printf("ID: %s\n", student.ID);
    
    // แสดงคะแนน (แสดงเป็นจำนวนเต็มตามตัวอย่าง)
    printf("Scores: %.0f %.0f %.0f %.0f %.0f\n", 
           student.ScoreSub1, student.ScoreSub2, student.ScoreSub3, 
           student.ScoreSub4, student.ScoreSub5);
    
    // แสดงเกรดของแต่ละวิชา
    printf("Grades: %s %s %s %s %s\n", 
           calculateGrade(student.ScoreSub1), 
           calculateGrade(student.ScoreSub2), 
           calculateGrade(student.ScoreSub3), 
           calculateGrade(student.ScoreSub4), 
           calculateGrade(student.ScoreSub5));
           
    // แสดงคะแนนเฉลี่ย (ปัดเศษทศนิยม 1 ตำแหน่งตามตัวอย่าง)
    printf("Average Scores: %.1f\n", averageScore);
}

int main() {
    // สร้าง Array ของโครงสร้างนักเรียน 3 คน
    S students[3];

    printf("Enter the details of 3 students :\n");

    // วนลูปรับข้อมูลนักเรียน
    for (int i = 0; i < 3; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name:\n");
        // ใช้ fgets เพื่อรับชื่อที่มีช่องว่าง (สำคัญมากสำหรับการป้อนข้อมูลใน C)
        if (fgets(students[i].Name, sizeof(students[i].Name), stdin) != NULL) {
             // ลบอักขระขึ้นบรรทัดใหม่ '\n' ที่ fgets เพิ่มเข้ามา
             students[i].Name[strcspn(students[i].Name, "\n")] = 0;
        } else {
            return 1; 
        }

        printf("ID:\n");
        // รับ ID
        if (scanf("%4s", students[i].ID) != 1) return 1;
        
        printf("Scores in Subject 1:\n");
        if (scanf("%f", &students[i].ScoreSub1) != 1) return 1;
        printf("Scores in Subject 2:\n");
        if (scanf("%f", &students[i].ScoreSub2) != 1) return 1;
        printf("Scores in Subject 3:\n");
        if (scanf("%f", &students[i].ScoreSub3) != 1) return 1;
        printf("Scores in Subject 4:\n");
        if (scanf("%f", &students[i].ScoreSub4) != 1) return 1;
        printf("Scores in Subject 5:\n");
        if (scanf("%f", &students[i].ScoreSub5) != 1) return 1;
        
        // ล้าง buffer หลังจาก scanf เพื่อให้ fgets ทำงานได้อย่างถูกต้องในรอบถัดไป
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    
    // วนลูปแสดงผลลัพธ์ของนักเรียน
    printf("\n");
    for (int i = 0; i < 3; i++) {
        displayStudentResults(students[i]);
    }

    return 0;
}
