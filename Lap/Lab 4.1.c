#include <stdio.h>

/**
 * โปรแกรมสำหรับแปลงหน่วยจาก 'วัน' (Days) เป็น 'วินาที' (Seconds)
 * สูตรการแปลง: Seconds = Days * 24 (ชั่วโมง/วัน) * 60 (นาที/ชั่วโมง) * 60 (วินาที/นาที)
 * Seconds = Days * 86400
 */
int main() {
    // 1. ประกาศตัวแปร
    // ใช้ long long เพื่อรองรับจำนวนวินาทีที่มาก
    // (88 วัน คือ 7,603,200 วินาที, 2727 วัน คือ 235,972,800 วินาที)
    // float days; // สามารถใช้ float สำหรับรับค่าวันได้ แต่ int days ก็เพียงพอตาม Test Case
    int days;
    long long total_seconds;
    
    // ค่าคงที่: จำนวนวินาทีในหนึ่งวัน (24 * 60 * 60 = 86400)
    const int SECONDS_PER_DAY = 86400;

    // 2. รับค่า 'วัน' จากผู้ใช้
    printf("Input Days : ");
    
    // ตรวจสอบความถูกต้องของการป้อนค่า (ถ้าไม่ต้องการให้รับค่าลบ ก็สามารถเพิ่มเงื่อนไข days >= 0 ได้)
    if (scanf("%d", &days) != 1 || days < 0) {
        printf("Error: Invalid input or number of days cannot be negative.\n");
        return 1;
    }

    // 3. คำนวณผลลัพธ์
    // ใช้ long long ในการคูณเพื่อให้มั่นใจว่าผลลัพธ์จะไม่เกินขีดจำกัดของ int
    total_seconds = (long long)days * SECONDS_PER_DAY;

    // 4. แสดงผลลัพธ์ตามรูปแบบ Test Case
    printf("%d days = %lld seconds\n", days, total_seconds);

    return 0;
}
