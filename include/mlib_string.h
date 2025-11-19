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
const char* mlib_strchr_const (const char* s, int c);
char* mlib_strchr_noconst (char* s, int c);

#define mlib_strchr(s, c) \
    _Generic ((s), const char*: mlib_strchr_const, default: mlib_strchr_noconst) (s, c)

const char* mlib_strrchr_const (const char* s, int c);
char* mlib_strrchr_noconst (char* s, int c);

#define mlib_strrchr(s, c) \
    _Generic ((s), const char*: mlib_strrchr_const, default: mlib_strrchr_noconst) (s, c)

// Miscellaneous
size_t mlib_strlen (const char* str);
