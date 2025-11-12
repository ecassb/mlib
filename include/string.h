#define __STDC_VERSION_STRING_H__ 202311L
#define NULL ((void*)0)

typedef typeof(sizeof(0)) size_t;

size_t mlib_strlen(const char* str);

#define strlen(args) mlib_strlen(args)
