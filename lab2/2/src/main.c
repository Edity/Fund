#include <stdio.h>
#include "../include/func.h"

int main() {    
    char buffer[100];
    char str1[50] = "Hello, World!";
    char str2[50] = "Hello, World!";
    
    // Test memchr
    printf("1. memchr: ");
    char *result = memchr(str1, 'W', 13);
    if (result != NULL) {
        printf("Found 'W' at position %ld\n", result - str1);
    } else {
        printf("Not found\n");
    }
    
    // Test memcmp
    printf("2. memcmp: ");
    int cmp_result = memcmp(str1, str2, 13);
    printf("Result: %d (%s)\n", cmp_result, cmp_result == 0 ? "equal" : "different");
    
    // Test memcpy
    printf("3. memcpy: ");
    memcpy(buffer, "Test string\0", 12);
    printf("Copied: %s\n", buffer);
    
    // Test memset
    printf("4. memset: ");
    memset(buffer, 'X', 5);
    buffer[5] = '\0';
    printf("Result: %s\n", buffer);
    
    // Test strncat
    printf("5. strncat: ");
    char dest[100] = "Hello";
    strncat(dest, " World!", 6);
    printf("Result: %s\n", dest);
    
    // Test strchr
    printf("6. strchr: ");
    char *chr_result = strchr("Hello World", 'o');
    if (chr_result != NULL) {
        printf("First 'o' : %c\n", chr_result[0]);
    }
    
    // Test strncmp
    printf("7. strncmp: ");
    int strcmp_result = strncmp("Hello", "Hello", 5);
    printf("Result: %d (%s)\n", strcmp_result, strcmp_result == 0 ? "equal" : "different");
    
    // Test strncpy
    printf("8. strncpy: ");
    strncpy(buffer, "Copied text", 11);
    buffer[11] = '\0';
    printf("Result: %s\n", buffer);
    
    // Test strcspn
    printf("9. strcspn: ");
    size_t spn_result = strcspn("Hello World", " W");
    printf("Length without ' ' or 'W': %zu\n", spn_result);
    
    // Test strlen
    printf("10. strlen: ");
    size_t len = strlen("Hello");
    printf("Length of 'Hello': %zu\n", len);
    
    // Test strpbrk
    printf("11. strpbrk: ");
    char *pbrk_result = strpbrk("Hello World", "aeiou");
    if (pbrk_result != NULL) {
        printf("First: %c\n", pbrk_result[0]);
    }
    
    // Test strrchr
    printf("12. strrchr: ");
    char *rchr_result = strrchr("Hello World", 'o');
    if (rchr_result != NULL) {
        printf("Last 'o' at: %c\n", rchr_result[0]);
    }
    
    // Test strstr
    printf("13. strstr: ");
    char *str_result = strstr("Hello World", "World");
    if (str_result != NULL) {
        printf("Found 'World': %s\n", str_result);
    }
    
    // Test strtok
    printf("14. strtok:\n");
    char token_str[] = "Hello,World,Test,Token";
    char *token = strtok(token_str, ",");
    int token_count = 1;
    while (token != NULL) {
        printf("   Token %d: %s\n", token_count++, token);
        token = strtok(NULL, ",");
    }
    
    return 0;
}