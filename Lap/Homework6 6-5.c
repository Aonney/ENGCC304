//แบบใช้ for loop
#include <stdio.h>

int main() {
    int n;
    printf("Enter number : ");
    scanf("%d", &n);

    for (int i = n; i >= 2; i--) {       // นับจาก n ลงมาถึง 2
        int isPrime = 1;                 // สมมติว่าเป็นจำนวนเฉพาะ
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
            printf("%d ", i);
    }

    return 0;
}

//แบบใช้ while loop
#include <stdio.h>

int main() {
    int n;
    printf("Enter number : ");
    scanf("%d", &n);

    int i = n;
    while (i >= 2) {
        int isPrime = 1;
        int j = 2;
        while (j * j <= i) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
            j++;
        }
        if (isPrime)
            printf("%d ", i);
        i--;
    }

    return 0;
}

//แบบใช้ do...while loop
#include <stdio.h>

int main() {
    int n;
    printf("Enter number : ");
    scanf("%d", &n);

    int i = n;
    if (i >= 2) {
        do {
            int isPrime = 1;
            int j = 2;
            do {
                if (j * j > i) break;
                if (i % j == 0) {
                    isPrime = 0;
                    break;
                }
                j++;
            } while (j * j <= i);

            if (isPrime)
                printf("%d ", i);
            i--;
        } while (i >= 2);
    }

    return 0;
}
