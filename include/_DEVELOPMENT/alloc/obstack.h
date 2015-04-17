
#ifndef _ALLOC_OBSTACK_H
#define _ALLOC_OBSTACK_H

#include <stddef.h>

// DATA STRUCTURES

struct obstack
{
   void       *fence;
   void       *object;
   void       *end;
};

#ifdef __SDCC

// SDCC

extern void   *obstack_1grow(struct obstack *ob, int c);
extern void   *obstack_1grow_fast(struct obstack *ob, int c);
extern size_t  obstack_align_distance(struct obstack *ob, size_t alignment);
extern int     obstack_align_to(struct obstack *ob, size_t alignment);
extern void   *obstack_alloc(struct obstack *ob, size_t size);
extern void   *obstack_base(struct obstack *ob);
extern void   *obstack_blank(struct obstack *ob, int size);
extern void   *obstack_blank_fast(struct obstack *ob, int size);
extern void   *obstack_copy(struct obstack *ob, void *p, size_t size);
extern void   *obstack_copy0(struct obstack *ob, void *p, size_t size);
extern void   *obstack_finish(struct obstack *ob);
extern void   *obstack_free(struct obstack *ob, void *object);
extern int     obstack_grow(struct obstack *ob, void *data, size_t size);
extern int     obstack_grow0(struct obstack *ob, void *data, size_t size);
extern void   *obstack_init(struct obstack *ob, size_t size);
extern void   *obstack_int_grow(struct obstack *ob, int data);
extern void   *obstack_int_grow_fast(struct obstack *ob, int data);
extern void   *obstack_next_free(struct obstack *ob);
extern size_t  obstack_object_size(struct obstack *ob);
extern size_t  obstack_room(struct obstack *ob);

#ifdef __SDCC_ENABLE_FASTCALL

// SDCC FASTCALL LINKAGE

extern void   *obstack_base_fastcall(struct obstack *ob) __z88dk_fastcall;
extern void   *obstack_finish_fastcall(struct obstack *ob) __z88dk_fastcall;
extern void   *obstack_next_free_fastcall(struct obstack *ob) __z88dk_fastcall;
extern size_t  obstack_object_size_fastcall(struct obstack *ob) __z88dk_fastcall;
extern size_t  obstack_room_fastcall(struct obstack *ob) __z88dk_fastcall;

// SDCC MAKE FASTCALL LINKAGE THE DEFAULT

#define obstack_base(a)             obstack_base_fastcall(a)
#define obstack_finish(a)           obstack_finish_fastcall(a)
#define obstack_next_free(a)        obstack_next_free_fastcall(a)
#define obstack_object_size(a)      obstack_object_size_fastcall(a)
#define obstack_room(a)             obstack_room_fastcall(a)

#endif

#else

// SCCZ80

extern void   __LIB__              *obstack_1grow(struct obstack *ob, int c);
extern void   __LIB__              *obstack_1grow_fast(struct obstack *ob, int c);
extern size_t __LIB__               obstack_align_distance(struct obstack *ob, size_t alignment);
extern int    __LIB__               obstack_align_to(struct obstack *ob, size_t alignment);
extern void   __LIB__              *obstack_alloc(struct obstack *ob, size_t size);
extern void   __LIB__ __FASTCALL__ *obstack_base(struct obstack *ob);
extern void   __LIB__              *obstack_blank(struct obstack *ob, int size);
extern void   __LIB__              *obstack_blank_fast(struct obstack *ob, int size);
extern void   __LIB__              *obstack_copy(struct obstack *ob, void *p, size_t size);
extern void   __LIB__              *obstack_copy0(struct obstack *ob, void *p, size_t size);
extern void   __LIB__ __FASTCALL__ *obstack_finish(struct obstack *ob);
extern void   __LIB__              *obstack_free(struct obstack *ob, void *object);
extern int    __LIB__               obstack_grow(struct obstack *ob, void *data, size_t size);
extern int    __LIB__               obstack_grow0(struct obstack *ob, void *data, size_t size);
extern void   __LIB__              *obstack_init(struct obstack *ob, size_t size);
extern void   __LIB__              *obstack_int_grow(struct obstack *ob, int data);
extern void   __LIB__              *obstack_int_grow_fast(struct obstack *ob, int data);
extern void   __LIB__ __FASTCALL__ *obstack_next_free(struct obstack *ob);
extern size_t __LIB__ __FASTCALL__  obstack_object_size(struct obstack *ob);
extern size_t __LIB__ __FASTCALL__  obstack_room(struct obstack *ob);

// SCCZ80 CALLEE LINKAGE

extern void   __LIB__ __CALLEE__   *obstack_1grow_callee(struct obstack *ob, int c);
extern void   __LIB__ __CALLEE__   *obstack_1grow_fast_callee(struct obstack *ob, int c);
extern size_t __LIB__ __CALLEE__    obstack_align_distance_callee(struct obstack *ob, size_t alignment);
extern int    __LIB__ __CALLEE__    obstack_align_to_callee(struct obstack *ob, size_t alignment);
extern void   __LIB__ __CALLEE__   *obstack_alloc_callee(struct obstack *ob, size_t size);
extern void   __LIB__ __CALLEE__   *obstack_blank_callee(struct obstack *ob, int size);
extern void   __LIB__ __CALLEE__   *obstack_blank_fast_callee(struct obstack *ob, int size);
extern void   __LIB__ __CALLEE__   *obstack_copy_callee(struct obstack *ob, void *p, size_t size);
extern void   __LIB__ __CALLEE__   *obstack_copy0_callee(struct obstack *ob, void *p, size_t size);
extern void   __LIB__ __CALLEE__   *obstack_free_callee(struct obstack *ob, void *object);
extern int    __LIB__ __CALLEE__    obstack_grow_callee(struct obstack *ob, void *data, size_t size);
extern int    __LIB__ __CALLEE__    obstack_grow0_callee(struct obstack *ob, void *data, size_t size);
extern void   __LIB__ __CALLEE__   *obstack_init_callee(struct obstack *ob, size_t size);
extern void   __LIB__ __CALLEE__   *obstack_int_grow_callee(struct obstack *ob, int data);
extern void   __LIB__ __CALLEE__   *obstack_int_grow_fast_callee(struct obstack *ob, int data);

// SCCZ80 MAKE CALLEE LINKAGE THE DEFAULT

#define obstack_1grow(a,b)          obstack_1grow_callee(a,b)
#define obstack_1grow_fast(a,b)     obstack_1grow_fast_callee(a,b)
#define obstack_align_distance(a,b) obstack_align_distance_callee(a,b)
#define obstack_align_to(a,b)       obstack_align_to_callee(a,b)
#define obstack_alloc(a,b)          obstack_alloc_callee(a,b)
#define obstack_blank(a,b)          obstack_blank_callee(a,b)
#define obstack_blank_fast(a,b)     obstack_blank_fast_callee(a,b)
#define obstack_copy(a,b,c)         obstack_copy_callee(a,b,c)
#define obstack_copy0(a,b,c)        obstack_copy0_callee(a,b,c)
#define obstack_free(a,b)           obstack_free_callee(a,b)
#define obstack_grow(a,b,c)         obstack_grow_callee(a,b,c)
#define obstack_grow0(a,b,c)        obstack_grow0_callee(a,b,c)
#define obstack_init(a,b)           obstack_init_callee(a,b)
#define obstack_int_grow(a,b)       obstack_int_grow_callee(a,b)
#define obstack_int_grow_fast(a,b)  obstack_int_grow_fast_callee(a,b)

#endif

#endif
