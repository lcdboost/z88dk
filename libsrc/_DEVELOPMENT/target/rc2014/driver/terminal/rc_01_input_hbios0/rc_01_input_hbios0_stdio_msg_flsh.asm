SECTION code_driver
SECTION code_driver_terminal_input

PUBLIC rc_01_input_hbios0_stdio_msg_flsh

EXTERN BF_CIOINIT
EXTERN asm_hbios
EXTERN console_01_input_stdio_msg_flsh

rc_01_input_hbios0_stdio_msg_flsh:
 
   ; get rid of any pending chars in the hbios0 buffer
   ld bc,BF_CIOINIT<<8|0x00
   ld de,0xffff
   call asm_hbios

   jp console_01_input_stdio_msg_flsh
