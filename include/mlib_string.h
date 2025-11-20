#undef __STDC_VERSION_STRING_H__
#define __STDC_VERSION_STRING_H__ 202311L
#undef NULL
#define NULL ((void*) 0)

typedef typeof (sizeof (0)) size_t;

// Copy
char* mlib_strcpy (char* restrict dest, const char* restrict src);
char* mlib_strncpy (char* restrict dest, const char* restrict src, size_t count);

// Concatenation
char* mlib_strcat (char* restrict dest, const char* restrict src);
char* mlib_strncat (char* restrict dest, const char* restrict src, size_t count);

// Compare
int mlib_strcmp (const char* s1, const char* s2);
int mlib_strncmp (const char* s1, const char* s2, size_t count);

// Search
const char* mlib_strchr_const (const char* haystack, int needle);
char* mlib_strchr_noconst (char* haystack, int needle);

#define mlib_strchr(haystack, needle)                                                     \
    _Generic ((haystack), const char*: mlib_strchr_const, default: mlib_strchr_noconst) ( \
      haystack,                                                                           \
      needle                                                                              \
    )

const char* mlib_strrchr_const (const char* haystack, int needle);
char* mlib_strrchr_noconst (char* haystack, int needle);

#define mlib_strrchr(haystack, needle)                                                      \
    _Generic ((haystack), const char*: mlib_strrchr_const, default: mlib_strrchr_noconst) ( \
      haystack,                                                                             \
      needle                                                                                \
    )

const char* mlib_strstr_const (const char* haystack, const char* needle);
char* mlib_strstr_noconst (char* haystack, const char* needle);

#define mlib_strstr(haystack, needle)                                                     \
    _Generic ((haystack), const char*: mlib_strstr_const, default: mlib_strstr_noconst) ( \
      haystack,                                                                           \
      needle                                                                              \
    )

size_t mlib_strspn (const char* str, const char* char_set);
size_t mlib_strcspn (const char* str, const char* char_set);

const char* mlib_strpbrk_const (const char* haystack, const char* char_set);
char* mlib_strpbrk_noconst (char* haystack, const char* char_set);

#define mlib_strpbrk(haystack, char_set)                                                    \
    _Generic ((haystack), const char*: mlib_strpbrk_const, default: mlib_strpbrk_noconst) ( \
      haystack,                                                                             \
      char_set                                                                              \
    )

// Miscellaneous
size_t mlib_strlen (const char* str);
