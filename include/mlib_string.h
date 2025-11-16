#define __STDC_VERSION_STRING_H__ 202311L
#define NULL                      ((void*) 0)

typedef typeof (sizeof (0)) size_t;

// Copy
char* mlib_strcpy (char* restrict dest, const char* restrict src);
char* mlib_strncpy (char* restrict dest, const char* restrict src, size_t count);

// Concatenation
char* mlib_strcat (char* restrict dest, const char* restrict src);
char* mlib_strncat (char* restrict dest, const char* restrict src, size_t count);

// Compare
int mlib_strcmp (const char* s1, const char* s2);

// Miscellaneous
size_t mlib_strlen (const char* str);
