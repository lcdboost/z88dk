
; uint zx_bitmask2px(uchar bitmask)

SECTION seg_code_arch

PUBLIC _zx_bitmask2px

_zx_bitmask2px:

   pop af
   pop hl
   
   push hl
   push af

   INCLUDE "arch/zx/display/z80/asm_zx_bitmask2px.asm"
