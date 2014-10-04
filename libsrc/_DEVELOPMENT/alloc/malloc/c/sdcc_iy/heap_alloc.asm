
; void *heap_alloc(void *heap, size_t size)

INCLUDE "clib_cfg.asm"

SECTION seg_code_malloc

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
IF __CLIB_OPT_MULTITHREAD & $01
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUBLIC _heap_alloc

_heap_alloc:

   pop af
   pop de
   pop hl
   
   push hl
   push de
   push af
   
   INCLUDE "alloc/malloc/z80/asm_heap_alloc.asm"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ELSE
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUBLIC _heap_alloc

EXTERN _heap_alloc_unlocked

defc _heap_alloc = _heap_alloc_unlocked
   
INCLUDE "alloc/malloc/z80/asm_heap_alloc.asm"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ENDIF
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
