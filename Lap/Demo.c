#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// Structure for items in the vending machine
typedef struct {
    char id[10];
    char name[50];
    double price;
    int stock;
    int expiry_day;
    int expiry_month;
    int expiry_year;
} Item;

// Structure for cash (coins and notes) in the machine
typedef struct {
    int value;
    int count;
} CoinNote;

// Function to check if an item is expired based on the current date
int is_expired(int day, int month, int year) {
    time_t t = time(NULL);
    struct tm today = *localtime(&t);
    struct tm item_expiry = {0};
    
    // Set the expiry date of the item
    item_expiry.tm_year = year - 1900;
    item_expiry.tm_mon = month - 1;
    item_expiry.tm_mday = day;
    
    // Compare the expiry date with the current date
    return difftime(mktime(&item_expiry), t) < 0;
}

// Function to display the vending machine menu with item details
void display_menu(Item menu[], int size) {
    printf("\n--- เมนูเครื่องขายสินค้าอัตโนมัติ ---\n");
    printf("----------------------------------------------------------\n");
    printf(" ID\tสินค้า\t\t\tราคา\tจำนวน\tวันหมดอายุ\n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        if (menu[i].stock <= 0) {
            printf(" %s\t%-20s\t%.0f บาท\tสินค้าหมด\n", menu[i].id, menu[i].name, menu[i].price);
        } else if (is_expired(menu[i].expiry_day, menu[i].expiry_month, menu[i].expiry_year)) {
            printf(" %s\t%-20s\t%.0f บาท\tหมดอายุ\n", menu[i].id, menu[i].name, menu[i].price);
        } else {
            printf(" %s\t%-20s\t%.0f บาท\t%d ชิ้น\t%02d/%02d/%d\n", menu[i].id, menu[i].name, menu[i].price, menu[i].stock, menu[i].expiry_day, menu[i].expiry_month, menu[i].expiry_year);
        }
    }
    printf("----------------------------------------------------------\n");
}

// Function to dispense change in the most optimal way
void dispense_change(double change_due, CoinNote cash_in_machine[], int cash_size) {
    if (change_due <= 0) {
        return;
    }

    printf("\n--- กำลังคำนวณเงินทอน: %.2f บาท ---\n", change_due);

    // Sort cash values in descending order for optimal change dispensing
    for (int i = 0; i < cash_size - 1; i++) {
        for (int j = 0; j < cash_size - i - 1; j++) {
            if (cash_in_machine[j].value < cash_in_machine[j+1].value) {
                CoinNote temp = cash_in_machine[j];
                cash_in_machine[j] = cash_in_machine[j+1];
                cash_in_machine[j+1] = temp;
            }
        }
    }
    
    for (int i = 0; i < cash_size; i++) {
        if (change_due >= cash_in_machine[i].value && cash_in_machine[i].count > 0) {
            int num_notes = (int)(change_due / cash_in_machine[i].value);
            if (num_notes > cash_in_machine[i].count) {
                num_notes = cash_in_machine[i].count;
            }
            if (num_notes > 0) {
                // Check if the denomination is a coin or a note
                if (cash_in_machine[i].value >= 20) {
                    printf("  - ทอน %d บาท: %d ใบ\n", cash_in_machine[i].value, num_notes);
                } else {
                    printf("  - ทอน %d บาท: %d เหรียญ\n", cash_in_machine[i].value, num_notes);
                }
                change_due -= num_notes * cash_in_machine[i].value;
                cash_in_machine[i].count -= num_notes;
            }
        }
    }
    
    if (change_due > 0.0) {
        printf("⚠️ ไม่สามารถทอนเงินได้ครบ! เงินทอนเหลือ %.2f บาท\n", change_due);
    } else {
        printf("✅ ทอนเงินเรียบร้อยแล้ว!\n");
    }
}

int main() {
    // Load item list from the flowchart
    Item products[] = {
        {"D01", "โค้ก", 10.0, 5, 30, 8, 2025},
        {"D02", "น้ำเขียว", 12.0, 3, 29, 8, 2025},
        {"C03", "อเมริกาโน่", 30.0, 2, 28, 8, 2025},
        {"C04", "ลาเต้ หวานเจี๊ยบ", 35.0, 4, 25, 8, 2025},
        {"S01", "เมล็ดทานตะวัน", 13.0, 10, 31, 8, 2025},
        {"S02", "ถั่วแปบ", 20.0, 1, 27, 8, 2025},
        {"S03", "จิ้นส้มหมก", 15.0, 7, 26, 8, 2025},
    };
    int num_products = sizeof(products) / sizeof(products[0]);

    // Load cash data with 500 for each denomination
    CoinNote cash_in_machine[] = {
        {1000, 500}, {500, 500}, {100, 500}, {50, 500}, {20, 500}, {10, 500},
        {5, 500}, {2, 500}, {1, 500}
    };
    int num_cash_types = sizeof(cash_in_machine) / sizeof(cash_in_machine[0]);
    double total_machine_cash = 0;
    for (int i = 0; i < num_cash_types; i++) {
        total_machine_cash += cash_in_machine[i].value * cash_in_machine[i].count;
    }
    
    double total_cost = 0;
    char choice_str[10];
    char continue_shopping;

    printf("--- เริ่มต้นการทำงานของเครื่อง ---\n");
    printf("\n--- สรุปยอดเงินและรายการสินค้าในตู้ (ตั้งต้น) ---\n");
    printf("เงินในตู้มีทั้งหมด: %.2f บาท\n", total_machine_cash);
    display_menu(products, num_products);
    printf("----------------------------------------------------------\n");
    
    do {
        printf("\nกรุณาเลือกสินค้า (ใส่ ID สินค้า เช่น D01) หรือ 'n' เพื่อชำระเงิน: ");
        scanf("%s", choice_str);

        if (strcmp(choice_str, "n") == 0 || strcmp(choice_str, "N") == 0) {
            break;
        }

        int found = 0;
        int chosen_index = -1;
        for (int i = 0; i < num_products; i++) {
            if (strcmp(choice_str, products[i].id) == 0) {
                found = 1;
                chosen_index = i;
                break;
            }
        }

        if (found) {
            if (products[chosen_index].stock <= 0) {
                printf("❌ ขออภัย! สินค้า %s หมดแล้ว.\n", products[chosen_index].name);
            } else if (is_expired(products[chosen_index].expiry_day, products[chosen_index].expiry_month, products[chosen_index].expiry_year)) {
                 printf("❌ ขออภัย! สินค้า %s หมดอายุแล้ว.\n", products[chosen_index].name);
            } else {
                printf("✅ เพิ่มรายการ %s ในตะกร้าแล้ว. ยอดรวมปัจจุบัน: %.2f บาท\n", products[chosen_index].name, total_cost + products[chosen_index].price);
                total_cost += products[chosen_index].price;
                products[chosen_index].stock--;
            }
        } else {
            printf("❌ ไม่พบสินค้า ID '%s' กรุณาลองใหม่\n", choice_str);
        }
    
        printf("\nต้องการเลือกสินค้าเพิ่มหรือไม่? (y/n): ");
        scanf(" %c", &continue_shopping);

    } while (continue_shopping == 'y' || continue_shopping == 'Y');
    
    if (total_cost > 0) {
        printf("\n--- สรุปรายการสินค้า ---\n");
        printf("ยอดรวมทั้งหมด: %.2f บาท\n", total_cost);

        double amountPaid;
        printf("กรุณาใส่เงิน: ");
        scanf("%lf", &amountPaid);

        double change = amountPaid - total_cost;
        
        if (change < 0) {
            printf("❌ เงินไม่เพียงพอ! คืนเงิน %.2f บาท\n", amountPaid);
            return 1;
        }
        
        // Add paid money to the machine
        int paid_int = (int)amountPaid;
        for (int i = 0; i < num_cash_types; i++) {
            if (paid_int >= cash_in_machine[i].value) {
                int count = paid_int / cash_in_machine[i].value;
                cash_in_machine[i].count += count;
                paid_int %= cash_in_machine[i].value;
            }
        }

        double available_change = 0;
        for (int i = 0; i < num_cash_types; i++) {
            available_change += cash_in_machine[i].value * cash_in_machine[i].count;
        }

        if (available_change < change) {
            printf("❌ ขออภัย! เงินทอนในเครื่องไม่เพียงพอ\n");
            printf("คืนเงินลูกค้า %.2f บาท\n", amountPaid);
            return 1;
        }
        
        dispense_change(change, cash_in_machine, num_cash_types);
        
        // Final Summary
        printf("\n\n--- สรุปยอดคงเหลือในตู้ (หลังทำรายการ) ---\n");
        printf("----------------------------------------------------------\n");
        printf("ID\tสินค้า\t\t\tจำนวนคงเหลือ\n");
        printf("----------------------------------------------------------\n");
        for (int i = 0; i < num_products; i++) {
            printf("%s\t%-20s\t%d ชิ้น\n", products[i].id, products[i].name, products[i].stock);
        }
        printf("----------------------------------------------------------\n");
        
        printf("\n--- สรุปยอดเงินคงเหลือในตู้ (หลังทำรายการ) ---\n");
        printf("----------------------------------------------------------\n");
        printf("มูลค่า\tจำนวนคงเหลือ\n");
        printf("----------------------------------------------------------\n");
        double final_machine_cash = 0;
        for (int i = 0; i < num_cash_types; i++) {
            printf("%d บาท\t%d ใบ/เหรียญ\n", cash_in_machine[i].value, cash_in_machine[i].count);
            final_machine_cash += cash_in_machine[i].value * cash_in_machine[i].count;
        }
        printf("----------------------------------------------------------\n");
        printf("เงินในตู้ทั้งหมด: %.2f บาท\n", final_machine_cash);
        printf("----------------------------------------------------------\n");
    }
    
    printf("\n--- ขอบคุณที่ใช้บริการค่ะ 🙏 ---\n");
    return 0;
}
