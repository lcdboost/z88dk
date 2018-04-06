    SECTION code_driver
    SECTION code_driver_character_output

    PUBLIC _sioa_putc
    
    EXTERN STAT0, TDR0
    EXTERN STAT0_TDRE, STAT0_TIE
    
    EXTERN __IO_SIO_TX_SIZE

    EXTERN sioaTxCount, sioaTxIn
    EXTERN asm_z80_push_di, asm_z80_pop_ei_jp

    _sioa_putc:

        ; enter    : l = char to output
        ; exit     : l = 1 if Tx buffer is full
        ;            carry reset
        ; modifies : af, hl

;        ld a, (sioaTxCount)         ; get the number of bytes in the Tx buffer
;        or a                        ; check whether the buffer is empty
;        jr nz, put_buffer_tx        ; buffer not empty, so abandon immediate Tx

;        in0 a, (STAT0)              ; get the SIOA status register
;        and STAT0_TDRE              ; test whether we can transmit on SIOA
;        jr z, put_buffer_tx         ; if not, so abandon immediate Tx

;        ld a, l                     ; Retrieve Tx character for immediate Tx
;        out0 (TDR0), a              ; output the Tx byte to the SIOA

;        ld l, 0                     ; indicate Tx buffer was not full
;        ret                         ; and just complete

    put_buffer_tx:

;        ld a, (sioaTxCount)         ; Get the number of bytes in the Tx buffer
;        cp __IO_SIO_TX_SIZE - 1     ; check whether there is space in the buffer
;        ld a,l                      ; Tx byte

;        ld l,1
;        jr nc, clean_up_tx          ; buffer full, so drop the Tx byte and clean up

;        ld hl, (sioaTxIn)           ; get the pointer to where we poke
;        ld (hl), a                  ; write the Tx byte to the sioaTxIn

;        inc l                       ; move the Tx pointer low byte along, 0xFF rollover
;        ld (sioaTxIn), hl           ; write where the next byte should be poked

;        ld hl, sioaTxCount
;        inc (hl)                    ; atomic increment of Tx count

;        ld l, 0                     ; indicate Tx buffer was not full

    clean_up_tx:
        
;        in0 a, (STAT0)              ; load the SIOA status register
;        and STAT0_TIE               ; test whether SIOA interrupt is set
;        ret nz                      ; if so then just return

;        call asm_z80_push_di        ; critical section begin
;        in0 a, (STAT0)              ; get the ASCI status register again
;        or STAT0_TIE                ; mask in (enable) the Tx Interrupt
;        out0 (STAT0), a             ; set the ASCI status register
        
;        jp asm_z80_pop_ei_jp        ; critical section end


    EXTERN _sio_need
    defc NEED = _sio_need
