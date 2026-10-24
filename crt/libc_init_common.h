#ifndef _LIBC_INIT_COMMON_H
#define _LIBC_INIT_COMMON_H

#include <stddef.h>
#include <stdint.h>

typedef void (*init_func_t)(int, char**, char**);
typedef void (*fini_func_t)(void);

typedef struct {
  init_func_t* preinit_array;
  size_t preinit_array_count;
  init_func_t* init_array;
  size_t init_array_count;
  fini_func_t** fini_array;
  size_t fini_array_count;
} structors_array_t;

extern int main(int, char**, char**);
extern void __libc_init(void* raw_args, void (*onexit)(void), int (*main)(int, char**, char**), structors_array_t const * const structors);

#endif
