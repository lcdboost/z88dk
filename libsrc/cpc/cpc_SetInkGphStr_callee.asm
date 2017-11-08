;
;       Amstrad CPC library
;
;       void __LIB__ __CALLEE__ cpc_SetInkGphStr(char *color, char *valor);
;
;       $Id: cpc_SetInkGphStr_callee.asm $
;

        SECTION   code_clib
        PUBLIC    cpc_SetInkGphStr_callee
        PUBLIC    _cpc_SetInkGphStr_callee
        PUBLIC    ASMDISP_CPC_SET_INKGPHSTR_CALLEE
		
        EXTERN colores_camb
		EXTERN cpc_PrintGphStr0

        INCLUDE "cpcfirm.def"              

.cpc_SetInkGphStr_callee
._cpc_SetInkGphStr_callee

   pop hl
   pop bc	; color
   ex (sp),hl	; valor
   ld	a,l
   

.asmentry
	
ld hl,colores_camb+cpc_PrintGphStr0
ld b,0
add hl,bc
ld (hl),a
	
ret


DEFC ASMDISP_CPC_SET_INKGPHSTR_CALLEE = # asmentry - cpc_SetInkGphStr_callee
