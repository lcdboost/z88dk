
; int toupper(int c)

SECTION seg_code_ctype

PUBLIC toupper

EXTERN asm_toupper

toupper:

   inc h
   dec h
   ret nz

   ld a,l
   call asm_toupper
   
   ld l,a
   ret
