#include <string.h>

size_t mlib_strlen(const char* str) {
    size_t length = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    
    return length;
}
