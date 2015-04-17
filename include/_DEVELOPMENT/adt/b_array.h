
#ifndef _ADT_B_ARRAY_H
#define _ADT_B_ARRAY_H

#include <stddef.h>

// DATA STRUCTURES

typedef struct b_array_s
{

   void       *data;
   size_t      size;
   size_t      capacity;

} b_array_t;

#ifdef __SDCC

// SDCC

extern size_t    b_array_append(b_array_t *a, int c);
extern void     *b_array_append_block(b_array_t *a, size_t n);
extern size_t    b_array_append_n(b_array_t *a, size_t n, int c);
extern int       b_array_at(b_array_t *a, size_t idx);
extern int       b_array_back(b_array_t *a);
extern size_t    b_array_capacity(b_array_t *a);
extern void      b_array_clear(b_array_t *a);
extern void     *b_array_data(b_array_t *a);
extern void      b_array_destroy(b_array_t *a);
extern int       b_array_empty(b_array_t *a);
extern size_t    b_array_erase(b_array_t *a, size_t idx);
extern size_t    b_array_erase_block(b_array_t *a, size_t idx, size_t n);
extern size_t    b_array_erase_range(b_array_t *a, size_t idx_first, size_t idx_last);
extern int       b_array_front(b_array_t *a);
extern b_array_t *b_array_init(void *p, void *data, size_t capacity);
extern size_t    b_array_insert(b_array_t *a, size_t idx, int c);
extern void     *b_array_insert_block(b_array_t *a, size_t idx, size_t n);
extern size_t    b_array_insert_n(b_array_t *a, size_t idx, size_t n, int c);
extern int       b_array_pop_back(b_array_t *a);
extern size_t    b_array_push_back(b_array_t *a, int c);
extern size_t    b_array_read_block(void *dst, size_t n, b_array_t *a, size_t idx);
extern int       b_array_resize(b_array_t *a, size_t n);
extern size_t    b_array_size(b_array_t *a);
extern size_t    b_array_write_block(void *src, size_t n, b_array_t *a, size_t idx);

#ifdef __SDCC_ENABLE_FASTCALL

// SDCC FASTCALL LINKAGE

extern int       b_array_back_fastcall(b_array_t *a) __z88dk_fastcall;
extern size_t    b_array_capacity_fastcall(b_array_t *a) __z88dk_fastcall;
extern void      b_array_clear_fastcall(b_array_t *a) __z88dk_fastcall;
extern void     *b_array_data_fastcall(b_array_t *a) __z88dk_fastcall;
extern void      b_array_destroy_fastcall(b_array_t *a) __z88dk_fastcall;
extern int       b_array_empty_fastcall(b_array_t *a) __z88dk_fastcall;
extern int       b_array_front_fastcall(b_array_t *a) __z88dk_fastcall;
extern int       b_array_pop_back_fastcall(b_array_t *a) __z88dk_fastcall;
extern size_t    b_array_size_fastcall(b_array_t *a) __z88dk_fastcall;

// SDCC MAKE FASTCALL LINKAGE THE DEFAULT

#define b_array_back(a)                b_array_back_fastcall(a)
#define b_array_capacity(a)            b_array_capacity_fastcall(a)
#define b_array_clear(a)               b_array_clear_fastcall(a)
#define b_array_data(a)                b_array_data_fastcall(a)
#define b_array_destroy(a)             b_array_destroy_fastcall(a)
#define b_array_empty(a)               b_array_empty_fastcall(a)
#define b_array_front(a)               b_array_front_fastcall(a)
#define b_array_pop_back(a)            b_array_pop_back_fastcall(a)
#define b_array_size(a)                b_array_size_fastcall(a)

#endif

#else

// SCCZ80

extern size_t    __LIB__               b_array_append(b_array_t *a, int c);
extern void      __LIB__              *b_array_append_block(b_array_t *a, size_t n);
extern size_t    __LIB__               b_array_append_n(b_array_t *a, size_t n, int c);
extern int       __LIB__               b_array_at(b_array_t *a, size_t idx);
extern int       __LIB__ __FASTCALL__  b_array_back(b_array_t *a);
extern size_t    __LIB__ __FASTCALL__  b_array_capacity(b_array_t *a);
extern void      __LIB__ __FASTCALL__  b_array_clear(b_array_t *a);
extern void      __LIB__ __FASTCALL__ *b_array_data(b_array_t *a);
extern void      __LIB__ __FASTCALL__  b_array_destroy(b_array_t *a);
extern int       __LIB__ __FASTCALL__  b_array_empty(b_array_t *a);
extern size_t    __LIB__               b_array_erase(b_array_t *a, size_t idx);
extern size_t    __LIB__               b_array_erase_block(b_array_t *a, size_t idx, size_t n);
extern size_t    __LIB__               b_array_erase_range(b_array_t *a, size_t idx_first, size_t idx_last);
extern int       __LIB__ __FASTCALL__  b_array_front(b_array_t *a);
extern b_array_t __LIB__              *b_array_init(void *p, void *data, size_t capacity);
extern size_t    __LIB__               b_array_insert(b_array_t *a, size_t idx, int c);
extern void      __LIB__              *b_array_insert_block(b_array_t *a, size_t idx, size_t n);
extern size_t    __LIB__               b_array_insert_n(b_array_t *a, size_t idx, size_t n, int c);
extern int       __LIB__ __FASTCALL__  b_array_pop_back(b_array_t *a);
extern size_t    __LIB__               b_array_push_back(b_array_t *a, int c);
extern size_t    __LIB__               b_array_read_block(void *dst, size_t n, b_array_t *a, size_t idx);
extern int       __LIB__               b_array_resize(b_array_t *a, size_t n);
extern size_t    __LIB__ __FASTCALL__  b_array_size(b_array_t *a);
extern size_t    __LIB__               b_array_write_block(void *src, size_t n, b_array_t *a, size_t idx);

// SCCZ80 CALLEE LINKAGE

extern size_t    __LIB__ __CALLEE__    b_array_append_callee(b_array_t *a, int c);
extern void      __LIB__ __CALLEE__   *b_array_append_block_callee(b_array_t *a, size_t n);
extern size_t    __LIB__ __CALLEE__    b_array_append_n_callee(b_array_t *a, size_t n, int c);
extern int       __LIB__ __CALLEE__    b_array_at_callee(b_array_t *a, size_t idx);
extern size_t    __LIB__ __CALLEE__    b_array_erase_callee(b_array_t *a, size_t idx);
extern size_t    __LIB__ __CALLEE__    b_array_erase_block_callee(b_array_t *a, size_t idx, size_t n);
extern size_t    __LIB__ __CALLEE__    b_array_erase_range_callee(b_array_t *a, size_t idx_first, size_t idx_last);
extern b_array_t __LIB__ __CALLEE__   *b_array_init_callee(void *p, void *data, size_t capacity);
extern size_t    __LIB__ __CALLEE__    b_array_insert_callee(b_array_t *a, size_t idx, int c);
extern void      __LIB__ __CALLEE__   *b_array_insert_block_callee(b_array_t *a, size_t idx, size_t n);
extern size_t    __LIB__ __CALLEE__    b_array_insert_n_callee(b_array_t *a, size_t idx, size_t n, int c);
extern size_t    __LIB__ __CALLEE__    b_array_push_back_callee(b_array_t *a, int c);
extern size_t    __LIB__ __CALLEE__    b_array_read_block_callee(void *dst, size_t n, b_array_t *a, size_t idx);
extern int       __LIB__ __CALLEE__    b_array_resize_callee(b_array_t *a, size_t n);
extern size_t    __LIB__ __CALLEE__    b_array_write_block_callee(void *src, size_t n, b_array_t *a, size_t idx);

// SCCZ80 MAKE CALLEE LINKAGE THE DEFAULT

#define b_array_append(a,b)                      b_array_append_callee(a,b);
#define b_array_append_block(a,b)                b_array_append_block_callee(a,b)
#define b_array_append_n(a,b,c)                  b_array_append_n_callee(a,b,c);
#define b_array_at(a,b)                          b_array_at_callee(a,b);
#define b_array_erase(a,b)                       b_array_erase_callee(a,b);
#define b_array_erase_range(a,b,c)               b_array_erase_range_callee(a,b,c);
#define b_array_init(a,b,c)                      b_array_init_callee(a,b,c);
#define b_array_insert(a,b,c)                    b_array_insert_callee(a,b,c);
#define b_array_insert_block(a,b,c)              b_array_insert_block_callee(a,b,c);
#define b_array_insert_n(a,b,c,d)                b_array_insert_n_callee(a,b,c,d);
#define b_array_push_back(a,b)                   b_array_push_back_callee(a,b);
#define b_array_read_block(a,b,c,d)              b_array_read_block_callee(a,b,c,d);
#define b_array_resize(a,b)                      b_array_resize_callee(a,b);
#define b_array_write_block(a,b,c,d)             b_array_write_block_callee(a,b,c,d);

#endif

#endif
