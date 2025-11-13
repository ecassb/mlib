#define __STDC_VERSION_STRING_H__ 202311L
#define NULL ((void*)0)

typedef typeof(sizeof(0)) size_t;

size_t mlib_strlen(const char* str);
char *mlib_strcpy(char* restrict s1, const char* restrict s2);

#define strlen(args) mlib_strlen(args)
#define strcpy(args) mlib_strcpy(args)
