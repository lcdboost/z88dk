
; void dzx7_standard(void *src, void *dst)

SECTION seg_code_zx7

PUBLIC dzx7_standard

EXTERN asm_dzx7_standard

dzx7_standard:

   pop af
   pop de
   pop hl
   
   push hl
   push de
   push af
   
   jp asm_dzx7_standard
