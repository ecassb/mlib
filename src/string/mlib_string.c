#include "mlib_string.h"
#include <stdio.h> //Just for debug purpose

size_t mlib_strlen(const char* str) {
    size_t length = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    
    return length;
}

char *mlib_strcpy(char* restrict dest, const char* restrict src) {
    for(size_t i = 0; i <= mlib_strlen(src); i++) {
        dest[i] = src[i];
    }

    return dest;
}

char *mlib_strncpy(char* restrict dest, const char* src, size_t count) {
    int src_null_found = 0;

    for(size_t i = 0; i < count; i++) {
        if(src_null_found == 0){
            char c = src[i];
            if (c == '\0') {
                src_null_found = 1;
            }
            dest[i] = c;
        } else {
            dest[i] = '\0';
        }
       
    }

    return dest;
}

char* mlib_strcat(char* restrict dest, const char* restrict src) {
    size_t dest_len = mlib_strlen(dest);
    mlib_strcpy(dest + dest_len, src);

    return dest;
}

char* mlib_strncat(char* restrict dest, const char* restrict src, size_t count) {
    size_t dest_len = mlib_strlen(dest);
    size_t written_bytes = 0;
    for(size_t i = 0; i < count; i ++) {
        if (src[i] == '\0') break;
        dest[dest_len + i] = src[i];
        written_bytes++;
    }
    dest[dest_len + written_bytes] = '\0';

    return dest;
}
