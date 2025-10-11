#include <stdio.h>
#include <stdlib.h> // สำหรับ rand() และ srand()
#include <time.h>   // สำหรับ time()

// กำหนดค่าคงที่
#define MAX_SCORE 100
#define SCORE_DEDUCTION 10
#define MIN_NUM 1
#define MAX_NUM 100

// ฟังก์ชันหลักของเกมหนึ่งรอบ
void playGame() {
    int winningNumber;
    int guess;
    int currentScore = MAX_SCORE;
    int minGuess = MIN_NUM;
    int maxGuess = MAX_NUM;
    
    // 1. สุ่มตัวเลข 1-100
    // ใช้ rand() % (MAX - MIN + 1) + MIN
    winningNumber = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
    
    printf("(Score=%d)\n\n", currentScore);

    // 2. Loop หลักของเกม
    do {
        // แสดงช่วงตัวเลขที่ทายได้ (มีการบอกใบ้)
        printf("Guess the winning number (%d-%d) : \n", minGuess, maxGuess);
        
        // รับค่าทายตัวเลข
        if (scanf("%d", &guess) != 1) {
            // กรณีรับค่าผิดพลาด (เช่น กรอกตัวอักษร)
            printf("Invalid input. Please enter a number.\n");
            // ล้าง buffer input ที่เหลืออยู่
            while (getchar() != '\n'); 
            continue; // ข้ามการทำงานที่เหลือในรอบนี้
        }

        // 3. ตรวจสอบว่าทายถูกหรือไม่
        if (guess == winningNumber) {
            // ทายถูก
            printf("\nThat is correct! The winning number is %d.\n", winningNumber);
            printf("\nScore this game: %d\n", currentScore);
            break; // ออกจาก Loop do-while
        } else {
            // ทายผิด: ลบคะแนนและแสดงผล
            currentScore -= SCORE_DEDUCTION;
            
            // ตรวจสอบคะแนนหมด
            if (currentScore <= 0) {
                currentScore = 0;
                printf("\nSorry, that is incorrect. Your score is now 0.\n");
                printf("You have run out of score! The winning number was %d.\n", winningNumber);
                break; // ออกจาก Loop do-while
            }

            // ทายผิด: บอกใบ้
            if (guess < winningNumber) {
                printf("\nSorry, the winning number is HIGHER than %d. (Score=%d)\n\n", guess, currentScore);
                // อัปเดตช่วงทาย
                if (guess >= minGuess) {
                    minGuess = guess + 1;
                }
            } else { // guess > winningNumber
                printf("\nSorry, the winning number is LOWER than %d. (Score=%d)\n\n", guess, currentScore);
                // อัปเดตช่วงทาย
                if (guess <= maxGuess) {
                    maxGuess = guess - 1;
                }
            }
        }
    } while (currentScore > 0);
}

int main() {
    int command;
    
    // ตั้งค่าตัวสุ่มเริ่มต้นด้วยเวลา เพื่อให้ได้ตัวเลขสุ่มที่ต่างกันทุกครั้งที่รัน
    srand(time(NULL));

    do {
        // 1. รับคำสั่งจากผู้ใช้
        printf("Do you want to play game (1=play,-1=exit) :\n");
        if (scanf("%d", &command) != 1) {
             // กรณีรับค่าผิดพลาด
            printf("Invalid input. Please enter 1 or -1.\n");
            while (getchar() != '\n');
            command = 0; // ตั้งค่า command เป็นค่าอื่นที่ไม่ใช่ 1 หรือ -1 เพื่อวนซ้ำ
            continue; 
        }

        if (command == 1) {
            // 2. เข้าสู่โหมดเล่นเกม
            playGame();
        } else if (command == -1) {
            // 3. ออกจากโปรแกรม
            printf("\nSee you again.\n");
        } else {
            // 4. คำสั่งไม่ถูกต้อง
            printf("\nInvalid command. Please enter 1 to play or -1 to exit.\n\n");
        }

    } while (command != -1); // ทำซ้ำจนกว่าผู้ใช้จะกรอก -1

    return 0;
}
