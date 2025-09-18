#include <stdio.h>
#include <string.h>
#include <ctype.h>
//เช่น - madam , noon , dad , mom
int main() {
    char word[100];
    
    printf("Enter word :");
    fgets(word, sizeof(word), stdin);
    
    // ลบ newline character ที่อาจมาจาก fgets
    word[strcspn(word, "\n")] = '\0';
    
    int length = strlen(word);
    int isPalindrome = 1; // สมมติว่าเป็น palindrome ก่อน
    
    for(int i = 0; i < length / 2; i++) {
        // เปรียบเทียบตัวอักษรโดยไม่สนใจ case sensitivity
        if(tolower(word[i]) != tolower(word[length - 1 - i])) {
            isPalindrome = 0;
            break;
        }
    }
    
    if(isPalindrome) {
        printf("~ ~ ~ ~ Pass. ~ ~ ~ ~\n");
    } else {
        printf("~ ~ ~ ~ Not Pass. ~ ~ ~ ~ \n");
    }
    
    return 0;
}
