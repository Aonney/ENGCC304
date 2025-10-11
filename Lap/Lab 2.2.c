#include <stdio.h>
#include <stdbool.h>

// โครงสร้างข้อมูลสำหรับสินค้าแต่ละชนิด
typedef struct {
    char name[60];
    int price;
    int stock;
} Item;

// ฟังก์ชันหลักของระบบลูกค้า
void customer_transaction(Item items[], int num_items);

// ฟังก์ชันสำหรับพนักงานเติมสินค้า
void employee_restock(Item items[], int num_items);

// ฟังก์ชันแสดงสถานะเงินทอนในตู้
void display_change_status(int *change_5, int *change_10, int *change_20, int *change_50);

int main() {
    // 1. กำหนดราคาและรายการสินค้าทั้งหมด
    Item products[] = {
        {"โค้ก", 10, 5},
        {"น้ำเขียว", 12, 5},
        {"อเมริกาโน่", 30, 3},
        {"ลาเต้หวานเจี๊ยบ", 35, 3},
        {"เมล็ดทานตะวัน", 13, 10},
        {"ถั่วแปบ", 20, 10},
        {"จิ้นส้มหมก", 15, 8}
    };
    int num_products = sizeof(products) / sizeof(products[0]);

    // 2. ข้อมูลเงินทอนคงเหลือในตู้ (จำลอง)
    // ใช้หน่วยเป็นจำนวนเหรียญ/ธนบัตร
    int change_5  = 10; // เหรียญ 5 บาท 10 เหรียญ (รวม 50 บาท)
    int change_10 = 10; // เหรียญ 10 บาท 10 เหรียญ (รวม 100 บาท)
    int change_20 = 2;  // ธนบัตร 20 บาท 2 ใบ (รวม 40 บาท)
    int change_50 = 1;  // ธนบัตร 50 บาท 1 ใบ (รวม 50 บาท)
    
    int choice = 0;

    printf("--- 🐢 ระบบเครื่องขายน้ำอัตโนมัติ 'ตะพาบลอย' --- \n");
    
    // วนลูปหลักของเครื่องเพื่อรอรับลูกค้าหรือพนักงาน
    do {
        // ตรวจสอบสถานะก่อนเริ่มบริการ
        display_change_status(&change_5, &change_10, &change_20, &change_50);
        
        printf("\n\nกรุณาเลือกโหมดการทำงาน:\n");
        printf("1. โหมดลูกค้า (ทำรายการซื้อ)\n");
        printf("2. โหมดพนักงาน (เติม Stock)\n");
        printf("3. ปิดระบบ\n");
        printf("เลือก: ");
        scanf("%d", &choice);

        if (choice == 1) {
            customer_transaction(products, num_products);
        } else if (choice == 2) {
            employee_restock(products, num_products);
        } else if (choice == 3) {
            printf("ปิดระบบเรียบร้อยแล้ว...\n");
        } else {
            printf("⚠️ เลือกโหมดไม่ถูกต้อง กรุณาลองใหม่\n");
        }

    } while (choice != 3);

    return 0;
}

// ----------------------------------------------------------------
// [Function 1] การทำรายการของลูกค้า
// ----------------------------------------------------------------
void customer_transaction(Item items[], int num_items) {
    int current_total = 0;
    int selection;
    bool add_more = true;
    
    printf("\n--- โหมดลูกค้า: ยินดีต้อนรับ ---\n");
    
    // Loop (Condition 2: ลูกค้าเลือกสินค้าเพิ่มหรือไม่)
    do {
        printf("\nรายการสินค้า (ยอดรวม: %d บาท):\n", current_total);
        for (int i = 0; i < num_items; i++) {
            printf("%d. %s (%d บาท) - Stock: %d\n", i + 1, items[i].name, items[i].price, items[i].stock);
        }
        printf("%d. จ่ายเงิน/จบการเลือก\n", num_items + 1);
        
        printf("INPUT: เลือกหมายเลขสินค้า: ");
        scanf("%d", &selection);

        if (selection >= 1 && selection <= num_items) {
            int index = selection - 1;
            // Condition: ตรวจสอบ Stock
            if (items[index].stock > 0) {
                current_total += items[index].price; // Process 1: คำนวณยอดรวม
                items[index].stock--;                 // Process 2: ลด Stock (ชั่วคราว)
                printf("✅ เพิ่ม %s เข้าตะกร้าแล้ว ยอดรวม %d บาท\n", items[index].name, current_total);
            } else {
                printf("❌ ขออภัย! สินค้า %s หมดแล้ว\n", items[index].name);
            }
        } else if (selection == num_items + 1) {
            add_more = false; // จบการเลือกสินค้า
        } else {
            printf("⚠️ หมายเลขสินค้าไม่ถูกต้อง\n");
        }

    } while (add_more);
    
    // ถ้าไม่มีสินค้าให้ชำระเงิน
    if (current_total == 0) {
        printf("ไม่มีรายการสินค้าที่ต้องชำระเงิน กลับสู่เมนูหลัก\n");
        return;
    }
    
    // Output: สรุปยอด
    printf("\nรวมยอดที่ต้องชำระ: %d บาท\n", current_total);
    
    // Input 2: การจ่ายเงิน
    int paid_amount;
    printf("INPUT: กรุณาใส่เงิน (จำนวนเต็ม): ");
    scanf("%d", &paid_amount);
    
    int change = paid_amount - current_total;
    
    if (change < 0) {
        printf("❌ จำนวนเงินไม่พอ! รายการถูกยกเลิก\n");
        // ควรคืน Stock ที่ลดไป และคืนเงินที่ใส่มา (แต่ในโค้ดนี้ไม่แสดงการคืนเงิน)
        return; 
    }

    // Output 3: จ่ายสินค้า (จำลอง)
    printf("\nOUTPUT: จ่ายสินค้าตามรายการที่เลือกเรียบร้อยแล้ว\n");

    // Condition 3: ต้องทอนเงินหรือไม่
    if (change > 0) {
        printf("✅ ต้องทอนเงิน: %d บาท\n", change);
        // Process: จำลองการทอนเงิน (ในโค้ดจริงต้องมีการจัดการ Change_status ด้วย)
        printf("OUTPUT: จ่ายเงินทอน %d บาท\n", change);
    } else {
        printf("✅ ไม่ต้องทอนเงิน\n");
    }

    // Process 3: Finalize Transaction
    printf("แสดงข้อความ: 'ขอบคุณครับ/ค่ะ' กลับสู่หน้าจอหลัก\n");
}


// ----------------------------------------------------------------
// [Function 2] การเติม Stock ของพนักงาน (จำลอง)
// ----------------------------------------------------------------
void employee_restock(Item items[], int num_items) {
    int item_choice, restock_amount;
    
    printf("\n--- โหมดพนักงาน: เติม Stock --- \n");
    
    // แสดงรายการปัจจุบัน
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - Stock ปัจจุบัน: %d\n", i + 1, items[i].name, items[i].stock);
    }
    
    printf("เลือกหมายเลขสินค้าที่ต้องการเติม (0 เพื่อยกเลิก): ");
    scanf("%d", &item_choice);
    
    if (item_choice >= 1 && item_choice <= num_items) {
        int index = item_choice - 1;
        printf("ต้องการเติม %s เพิ่มกี่ชิ้น: ", items[index].name);
        scanf("%d", &restock_amount);
        
        if (restock_amount > 0) {
            items[index].stock += restock_amount; // Process: เติม Stock
            printf("✅ เติม %s จำนวน %d ชิ้น เรียบร้อยแล้ว. Stock ใหม่: %d\n", 
                   items[index].name, restock_amount, items[index].stock);
        } else {
            printf("❌ จำนวนเติมไม่ถูกต้อง\n");
        }
    } else if (item_choice != 0) {
        printf("⚠️ หมายเลขสินค้าไม่ถูกต้อง\n");
    }
}

// ----------------------------------------------------------------
// [Function 3] แสดงสถานะเงินทอน (จำลอง)
// ----------------------------------------------------------------
void display_change_status(int *change_5, int *change_10, int *change_20, int *change_50) {
    int total_change = (*change_5 * 5) + (*change_10 * 10) + (*change_20 * 20) + (*change_50 * 50);

    printf("\n--- สถานะเงินทอนในตู้ ---\n");
    printf("รวมเงินทอนคงเหลือ: %d บาท\n", total_change);
    printf(" - เหรียญ 5 บาท: %d เหรียญ\n", *change_5);
    printf(" - เหรียญ 10 บาท: %d เหรียญ\n", *change_10);
    printf(" - ธนบัตร 20 บาท: %d ใบ\n", *change_20);
    printf(" - ธนบัตร 50 บาท: %d ใบ\n", *change_50);
    
    // Condition 1: Low Change Check (จำลองเงื่อนไข)
    if (total_change < 100) {
        printf("⚠️ แจ้งเตือน: เงินทอนเหลือต่ำกว่า 100 บาท กรุณาเติมเงินทอน!\n");
    }
}
