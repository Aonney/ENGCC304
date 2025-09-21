#include <stdio.h>

int main() {
    double score;
    printf("กรุณาใส่คะแนนดิบ: ");
    scanf("%lf", &score);

    if (score < 50) {
        printf("เกรด: F\n");
    }
    else if (score >= 50 && score < 55) {
        printf("เกรด: D\n");
    }
    else if (score >= 55 && score < 60) {
        printf("เกรด: D+\n");
    }
    else if (score >= 60 && score < 65) {
        printf("เกรด: C\n");
    }
    else if (score >= 65 && score < 70) {
        printf("เกรด: C+\n");
    }
    else if (score >= 70 && score < 75) {
        printf("เกรด: B\n");
    }
    else if (score >= 75 && score < 80) {
        printf("เกรด: B+\n");
    }
    else if (score >= 80) {
        printf("เกรด: A\n");
    }
    else {
        printf("คะแนนไม่ถูกต้อง\n");
    }

    return 0;
}
