
; int isupper(int c)

SECTION seg_code_ctype

PUBLIC _isupper

EXTERN asm_isupper, error_zc

_isupper:

   pop af
   pop hl
   
   push hl
   push af

   inc h
   dec h
   jp nz, error_zc

   ld a,l
   call asm_isupper
   
   ld l,h
   ret c
   
   inc l
   ret
