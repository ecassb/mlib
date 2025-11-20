#include "mlib_string.h"
// #include <stdio.h> //Just for debug purpose

size_t mlib_strlen (const char* str) {
    size_t length = 0;

    for (int i = 0; str[i] != '\0'; i++) { length++; }

    return length;
}

char* mlib_strcpy (char* restrict dest, const char* restrict src) {
    for (size_t i = 0; i <= mlib_strlen (src); i++) { dest[i] = src[i]; }

    return dest;
}

char* mlib_strncpy (char* restrict dest, const char* src, size_t count) {
    int src_null_found = 0;

    for (size_t i = 0; i < count; i++) {
        if (src_null_found == 0) {
            char c = src[i];
            if (c == '\0') { src_null_found = 1; }
            dest[i] = c;
        } else {
            dest[i] = '\0';
        }
    }

    return dest;
}

char* mlib_strcat (char* restrict dest, const char* restrict src) {
    size_t dest_len = mlib_strlen (dest);
    mlib_strcpy (dest + dest_len, src);

    return dest;
}

char* mlib_strncat (char* restrict dest, const char* restrict src, size_t count) {
    size_t dest_len = mlib_strlen (dest);
    size_t written_bytes = 0;
    for (size_t i = 0; i < count; i++) {
        if (src[i] == '\0') break;
        dest[dest_len + i] = src[i];
        written_bytes++;
    }
    dest[dest_len + written_bytes] = '\0';

    return dest;
}

int mlib_strcmp (const char* s1, const char* s2) {
    size_t s1_len = mlib_strlen (s1);
    size_t s2_len = mlib_strlen (s2);

    if (s1_len < s2_len) {
        return -1;
    } else if (s1_len > s2_len) {
        return 1;
    }

    for (size_t i = 0; i < s1_len; i++) {
        if (s1[i] < s2[i]) {
            return -1;
        } else if (s1[i] > s2[i]) {
            return 1;
        }
    }

    return 0;
}

int mlib_strncmp (const char* s1, const char* s2, size_t count) {
    char sized_s1[count];
    char sized_s2[count];
    int s1_null_found = 0;
    int s2_null_found = 0;

    for (size_t i = 0; i < count; i++) {
        if (s1_null_found == 0) {
            sized_s1[i] = s1[i];
            if (s1[i] == '\0') s1_null_found = 1;
        } else {
            sized_s1[i] = '\0';
        }

        if (s2_null_found == 0) {
            sized_s2[i] = s2[i];
            if (s2[i] == '\0') s2_null_found = 1;
        } else {
            sized_s2[i] = '\0';
        }
    }

    return mlib_strcmp (sized_s1, sized_s2);
}

const char* mlib_strchr_const (const char* s, int c) {
    char cc = (char) c;
    size_t len = mlib_strlen (s);

    for (size_t i = 0; i < len; i++) {
        if (s[i] == cc) { return &s[i]; }
    }

    return nullptr;
}

char* mlib_strchr_noconst (char* s, int c) {
    char cc = (char) c;
    size_t len = mlib_strlen (s);

    for (size_t i = 0; i < len; i++) {
        if (s[i] == cc) { return &s[i]; }
    }

    return nullptr;
}

const char* mlib_strrchr_const (const char* s, int c) {
    char cc = (char) c;
    size_t len = mlib_strlen (s);

    for (size_t i = len - 1; i > 0; i--) {
        if (s[i] == cc) { return &s[i]; }
    }

    if (s[0] == cc) return s;

    return nullptr;
}

char* mlib_strrchr_noconst (char* s, int c) {
    char cc = (char) c;
    size_t len = mlib_strlen (s);

    for (size_t i = len - 1; i > 0; i--) {
        if (s[i] == cc) { return &s[i]; }
    }
    if (s[0] == cc) return s;
    return nullptr;
}

const char* mlib_strstr_const (const char* haystack, const char* needle) {
    const size_t needle_length = mlib_strlen (needle);
    const size_t haystack_lenght = mlib_strlen (haystack);

    if (needle_length > haystack_lenght) { return nullptr; }

    if (needle_length == 0) { return haystack; }

    for (size_t i = 0; i <= (haystack_lenght - needle_length); i++) {
        if (mlib_strncmp (haystack + i, needle, needle_length) == 0) { return &haystack[i]; }
    }

    return nullptr;
}

char* mlib_strstr_noconst (char* haystack, const char* needle) {
    const size_t needle_length = mlib_strlen (needle);
    const size_t haystack_lenght = mlib_strlen (haystack);

    if (needle_length > haystack_lenght) { return nullptr; }

    if (needle_length == 0) { return haystack; }

    for (size_t i = 0; i <= (haystack_lenght - needle_length); i++) {
        if (mlib_strncmp (haystack + i, needle, needle_length) == 0) { return &haystack[i]; }
    }

    return nullptr;
}

size_t mlib_strspn (const char* str, const char* char_set) {
    size_t max_span_length = 0;
    size_t current_span_length = 0;
    size_t str_length = mlib_strlen (str);
    for (size_t i = 0; i < str_length; i++) {
        if (mlib_strchr (char_set, str[i]) != nullptr) {
            current_span_length++;
        } else {
            if (current_span_length > max_span_length) { max_span_length = current_span_length; }
            current_span_length = 0;
        }
    }

    return max_span_length;
}

size_t mlib_strcspn (const char* str, const char* char_set) {
    size_t max_span_length = 0;
    size_t current_span_length = 0;
    size_t str_length = mlib_strlen (str);
    for (size_t i = 0; i < str_length; i++) {
        if (mlib_strchr (char_set, str[i]) == nullptr) {
            current_span_length++;
        } else {
            if (current_span_length > max_span_length) { max_span_length = current_span_length; }
            current_span_length = 0;
        }
    }

    if (current_span_length > max_span_length) { return current_span_length; }

    return max_span_length;
}
