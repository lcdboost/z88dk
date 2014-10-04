
; ===============================================================
; Dec 2013
; ===============================================================
; 
; size_t balloc_blockcount(unsigned int queue)
;
; Return number of free blocks in the queue.  O(n).
;
; ===============================================================

SECTION seg_code_balloc

PUBLIC asm_balloc_blockcount

EXTERN __balloc_qtbl

EXTERN asm_p_forward_list_size

asm_balloc_blockcount:

   ; enter : hl = unsigned int queue
   ;
   ; exit  : hl = number of available blocks
   ;
   ; uses  : af, de, hl

   add hl,hl
   ld de,(__balloc_qtbl)
   add hl,de                   ; p_forward_list *q

   jp asm_p_forward_list_size
