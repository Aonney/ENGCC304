#include <stdio.h>
int main() {
    int N;
    if(scanf("%d", &N) != 1) {
      printf("Error ต้องกรอกเป็นตัวเลข");
      return 1;
    }
    if (N % 2 == 1) {
        // ถ้าเป็นเลขคี่: แสดงเลขคี่จาก 1 ถึง N
        printf("ลำดับเลขคี่จาก 1 ถึง %d:\n", N);
        for (int i = 0; i <= 1; i += 2) {
            printf("%d ", i);
        }
    } else {
        // ถ้าเป็นเลขคู่: แสดงเลขคู่จาก N ถึง 0
        printf("ลำดับเลขคู่จาก %d ถึง 0:\n", N);
        for (int i = N; i >= 0; i -= 2) {
            printf("%d ", i);
        }
    }
    return 0;
}
