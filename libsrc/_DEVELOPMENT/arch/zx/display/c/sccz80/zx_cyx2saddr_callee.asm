
; void *zx_cyx2saddr(uchar row, uchar col)

SECTION seg_code_arch

PUBLIC zx_cyx2saddr_callee

zx_cyx2saddr_callee:

   pop hl
   pop de
   ex (sp),hl
   
   ld h,l
   ld l,e
   
   INCLUDE "arch/zx/display/z80/asm_zx_cyx2saddr.asm"
