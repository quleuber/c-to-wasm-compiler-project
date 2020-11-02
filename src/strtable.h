#if !defined(STRTABLE_H)
#define STRTABLE_H

#include <stdlib.h>
#include <stdio.h>

size_t strtb_add(char *cstr);
const char *strtb_get(size_t i);
void strtb_print(FILE *f);

#endif /* STRTABLE_H */
