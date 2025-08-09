#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int score;
    int winning_number;
    int guess;

    // ทำให้การสุ่มเปลี่ยนทุกครั้งตามเวลา
    srand(time(NULL));

    while (1) {
        printf("Do you want to play game (1=play,-1=exit) : ");
        scanf("%d", &choice);

        if (choice == -1) {
            printf("\nSee you again.\n");
            break;
        } else if (choice == 1) {
            score = 100;
            winning_number = rand() % 100 + 1;

            printf("\n(Score=%d)\n", score);

            while (1) {
                printf("Guess the winning number (1-100) : ");
                scanf("%d", &guess);

                if (guess == winning_number) {
                    printf("\nThat is correct! The winning number is %d.\n", winning_number);
                    printf("Score this game: %d\n\n", score);
                    break; // ออกจากลูปทายเลข
                } else {
                    score -= 10;

                    if (guess < winning_number) {
                        printf("Sorry, the winning number is HIGHER than %d. (Score=%d)\n\n", guess, score);
                    } else {
                        printf("Sorry, the winning number is LOWER than %d. (Score=%d)\n\n", guess, score);
                    }

                    // ถ้าคะแนนหมด ให้หยุดเกม
                    if (score <= 0) {
                        printf("Game over! The winning number was %d.\n\n", winning_number);
                        break;
                    }
                }
            }
        } else {
            printf("Invalid choice. Please enter 1 or -1.\n");
        }
    }

    return 0;
}

