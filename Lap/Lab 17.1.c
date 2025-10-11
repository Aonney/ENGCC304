#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// กำหนดค่าคงที่สำหรับขนาดสูงสุดของอาเรย์หนังสือและขนาดของสตริง
#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100

// 1. Structure สำหรับเก็บข้อมูลหนังสือ
typedef struct {
    int id;
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int year;
} Book;

// Prototypes ของฟังก์ชัน (ตามโจทย์)
void addBook(Book books[], int *count);
void searchBook(Book books[], int count, char title[]);
void displayBooks(Book books[], int count);
void displayMenu();
void clearInputBuffer();

// ฟังก์ชันหลัก
int main() {
    Book library[MAX_BOOKS]; // อาเรย์สำหรับเก็บหนังสือ
    int book_count = 0;      // ตัวนับจำนวนหนังสือปัจจุบัน
    int choice;              // ตัวแปรสำหรับรับตัวเลือกจากเมนู

    do {
        displayMenu();
        printf("Choose an option: ");

        // รับตัวเลือกจากผู้ใช้
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            clearInputBuffer();
            choice = 0; // ตั้งค่าให้วนกลับไปที่เมนู
            continue;
        }

        clearInputBuffer(); // ล้างบัฟเฟอร์หลังจากรับตัวเลข

        switch (choice) {
            case 1:
                addBook(library, &book_count);
                break;
            case 2:
                {
                    char search_title[MAX_TITLE_LEN];
                    printf("Enter Title to Search: ");
                    // ใช้ fgets เพื่อรับชื่อที่มีช่องว่างได้
                    if (fgets(search_title, MAX_TITLE_LEN, stdin) != NULL) {
                        // ลบ newline character ที่อาจติดมากับ fgets
                        search_title[strcspn(search_title, "\n")] = 0; 
                        searchBook(library, book_count, search_title);
                    }
                }
                break;
            case 3:
                displayBooks(library, book_count);
                break;
            case 4:
                printf("\nExiting the program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please select an option between 1 and 4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// ฟังก์ชันสำหรับแสดงเมนู
void displayMenu() {
    printf("\n--- Library Management System ---\n");
    printf("1. Add a new book\n");
    printf("2. Search book by title\n");
    printf("3. Display all books\n");
    printf("4. Exit\n");
    printf("---------------------------------\n");
}

// ฟังก์ชันสำหรับเคลียร์ Input Buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Function: void addBook(Book books[], int *count)
void addBook(Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("\nError: Library is full. Cannot add more books.\n");
        return;
    }

    Book new_book;

    printf("Enter Book ID: ");
    while (scanf("%d", &new_book.id) != 1) {
        printf("Invalid ID. Please enter an integer: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    printf("Enter Title: ");
    // ใช้ fgets เพื่อรับชื่อที่มีช่องว่าง
    fgets(new_book.title, MAX_TITLE_LEN, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0; // ลบ newline

    printf("Enter Author: ");
    // ใช้ fgets เพื่อรับชื่อที่มีช่องว่าง
    fgets(new_book.author, MAX_AUTHOR_LEN, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0; // ลบ newline

    printf("Enter Year: ");
    while (scanf("%d", &new_book.year) != 1) {
        printf("Invalid Year. Please enter an integer: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    
    // เพิ่มหนังสือเข้าในอาเรย์และเพิ่มตัวนับ
    books[*count] = new_book;
    (*count)++;

    printf("Book added successfully!\n");
}

// 2. Function: void displayBooks(Book books[], int count)
void displayBooks(Book books[], int count) {
    if (count == 0) {
        printf("\nLibrary is empty. No books to display.\n");
        return;
    }

    printf("\n--- All Books in Library (%d books) ---\n", count);
    for (int i = 0; i < count; i++) {
        printf("Book ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Year: %d\n", books[i].year);
        printf("-----------------------\n");
    }
}

// ฟังก์ชันช่วยในการเปรียบเทียบสตริงแบบไม่คำนึงถึงขนาดตัวอักษร (Case-Insensitive)
int compareCaseInsensitive(const char *s1, const char *s2) {
    if (s1 == NULL || s2 == NULL) return 0;
    while (*s1 && *s2) {
        if (tolower((unsigned char)*s1) != tolower((unsigned char)*s2)) {
            return 0; // ไม่ตรงกัน
        }
        s1++;
        s2++;
    }
    return (*s1 == '\0' && *s2 == '\0'); // ตรงกันทั้งหมด
}

// 3. Function: void searchBook(Book books[], int count, char title[])
void searchBook(Book books[], int count, char title[]) {
    int found = 0;
    
    printf("\n--- Search Results for '%s' ---\n", title);

    for (int i = 0; i < count; i++) {
        // ใช้ฟังก์ชัน strcmp เพื่อเปรียบเทียบชื่อหนังสือ
        // หรือใช้ compareCaseInsensitive เพื่อให้ค้นหาได้ง่ายขึ้น (ตามโค้ดนี้)
        if (compareCaseInsensitive(books[i].title, title)) { 
            printf("Book ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Year: %d\n", books[i].year);
            found = 1;
            break; // พบแล้ว ออกจากลูปได้เลย
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
    printf("----------------------------------------\n");
}
