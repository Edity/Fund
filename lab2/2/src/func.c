#include <stddef.h>
#include <stdint.h>
#include "../include/func.h"


void *memchr(const void *str, int c, size_t n) {
    if (str == NULL) return NULL;
    
    const unsigned char *p = (const unsigned char *)str;
    unsigned char uc = (unsigned char)c;
    
    for (size_t i = 0; i < n; i++) {
        if (p[i] == uc) {
            return (void *)(p + i);
        }
    }
    return NULL;
}

int memcmp(const void *str1, const void *str2, size_t n) {
    if (str1 == NULL || str2 == NULL) return 0;
    
    const unsigned char *p1 = (const unsigned char *)str1;
    const unsigned char *p2 = (const unsigned char *)str2;
    
    for (size_t i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return p1[i] - p2[i];
        }
    }
    return 0;
}

void *memcpy(void *dest, const void *src, size_t n) {
    if (dest == NULL || src == NULL) return NULL;
    
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dest;
}

void *memset(void *str, int c, size_t n) {
    if (str == NULL) return NULL;
    
    unsigned char *p = (unsigned char *)str;
    unsigned char uc = (unsigned char)c;
    
    for (size_t i = 0; i < n; i++) {
        p[i] = uc;
    }
    return str;
}

char *strncat(char *dest, const char *src, size_t n) {
    if (dest == NULL || src == NULL) return NULL;
    
    char *original_dest = dest;
    
    while (*dest != '\0') {
        dest++;
    }
    
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    
    dest[i] = '\0';
    
    return original_dest;
}

char *strchr(const char *str, int c) {
    if (str == NULL) return NULL;
    
    unsigned char uc = (unsigned char)c;
    
    while (*str != '\0') {
        if (*str == uc) {
            return (char *)str;
        }
        str++;
    }
    
    if (uc == '\0') {
        return (char *)str;
    }
    
    return NULL;
}

int strncmp(const char *str1, const char *str2, size_t n) {
    if (str1 == NULL || str2 == NULL) return 0;
    
    for (size_t i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            return (unsigned char)str1[i] - (unsigned char)str2[i];
        }
        if (str1[i] == '\0') {
            break;
        }
    }
    return 0;
}
char *strncpy(char *dest, const char *src, size_t n) {
    if (dest == NULL || src == NULL) return NULL;
    
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    
    return dest;
}
size_t strcspn(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) return 0;
    
    size_t count = 0;
    while (str1[count] != '\0') {
        const char *d = str2;
        while (*d != '\0') {
            if (str1[count] == *d) {
                return count;
            }
            d++;
        }
        count++;
    }
    return count;
}

size_t strlen(const char *str) {
    if (str == NULL) return 0;
    
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char *strpbrk(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) return NULL;
    
    while (*str1 != '\0') {
        const char *d = str2;
        while (*d != '\0') {
            if (*str1 == *d) {
                return (char *)str1;
            }
            d++;
        }
        str1++;
    }
    return NULL;
}

char *strrchr(const char *str, int c) {
    if (str == NULL) return NULL;
    
    const char *last = NULL;
    unsigned char uc = (unsigned char)c;
    
    while (*str != '\0') {
        if (*str == uc) {
            last = str;
        }
        str++;
    }
    
    if (uc == '\0') {
        return (char *)str;
    }
    
    return (char *)last;
}

char *strstr(const char *haystack, const char *needle) {
    if (haystack == NULL || needle == NULL) return NULL;
    if (*needle == '\0') return (char *)haystack;
    
    for (size_t i = 0; haystack[i] != '\0'; i++) {
        size_t j = 0;
        while (needle[j] != '\0' && haystack[i + j] == needle[j]) {
            j++;
        }
        if (needle[j] == '\0') {
            return (char *)(haystack + i);
        }
    }
    return NULL;
}

char *strtok(char *str, const char *delim) {
    static char *saved_str = NULL;
    
    if (str != NULL) {
        saved_str = str;
    } else if (saved_str == NULL) {
        return NULL;
    }
    
    char *start = saved_str;
    while (*start != '\0') {
        const char *d = delim;
        int is_delim = 0;
        while (*d != '\0') {
            if (*start == *d) {
                is_delim = 1;
                break;
            }
            d++;
        }
        if (!is_delim) break;
        start++;
    }
    
    if (*start == '\0') {
        saved_str = NULL;
        return NULL;
    }

    char *end = start;
    while (*end != '\0') {
        const char *d = delim;
        int is_delim = 0;
        while (*d != '\0') {
            if (*end == *d) {
                is_delim = 1;
                break;
            }
            d++;
        }
        if (is_delim) break;
        end++;
    }
    
    if (*end == '\0') {
        saved_str = NULL;
    } else {
        *end = '\0';
        saved_str = end + 1;
    }
    
    return start;
}