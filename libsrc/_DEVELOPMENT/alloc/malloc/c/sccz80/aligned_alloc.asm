
; void *aligned_alloc(size_t alignment, size_t size)

INCLUDE "clib_cfg.asm"

SECTION seg_code_malloc

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
IF __CLIB_OPT_MULTITHREAD & $01
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUBLIC aligned_alloc

EXTERN asm_aligned_alloc

aligned_alloc:

   pop af
   pop hl
   pop bc
   
   push bc
   push hl
   push af
   
   jp asm_aligned_alloc

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ELSE
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUBLIC aligned_alloc

EXTERN aligned_alloc_unlocked

defc aligned_alloc = aligned_alloc_unlocked

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ENDIF
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
