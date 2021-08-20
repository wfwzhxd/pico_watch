#ifndef PICO_I_UTIL_H
#define PICO_I_UTIL_H

#define ARRAY_LEN(ARRAY) (sizeof(ARRAY) / sizeof(ARRAY[0]))

#define BIT2 (1<<2)
#define BIT3 (1<<3)

#define TRIM_LEFT(X) while (' ' == *X) { X++; }

#endif