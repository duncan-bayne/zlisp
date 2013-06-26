;; FILE: crt0.s
;; adapted for Amstrad CPC ROM creation 2013 by Tim Riemann / Octoate

    .module crt0
    .globl  _main

    .area _HEADER (ABS)

    .org 0xC000

    .db 0x01                    ; background ROM
    .db 0, 0, 1                 ; version 0.0.1

    .dw rsx_name_table          ; link to the RSX command table

    ; RSX jump block
    jp init_rom                 ; initialisation routine
    jp run_tests                ; first RSX command (see table)

rsx_name_table:                 ; NOTE: the "ascis" directive sets the highest bit of the last character
    .ascis "Init ROM"           ; initialisation routine - executed when CPC during boot process
				; use a name, which you can't execute from BASIC here
    .ascis "TESTS"              ; to run tests, you type "|TESTS" in BASIC
    .db 0                       ; end of the RSX command table

init_rom:                       ; show ROM initialisation message
    push hl
    ld hl, #init_msg
    call show_message
    pop hl
    scf                         ; tell the firmware, that initialisation was successful
    ret

init_msg:
    .db 24
    .ascii "Type |TESTS [ENTER] to run tests."
    .db 24, 10, 13, 10, 13, 0xFF

run_tests:
    ; Get the ROM number
    call 0xB912                 ; KL_CURR_SELECTION (A = ROM select address for our rom)
    ld (0x4000), a              ; Save the rom number in a variable in ram

    ;; Stack at the top of memory.
    ;;ld sp,(0xC000 - 1)

    call gsinit
    call _main

    ret                         ; end of the execution -> reset the CPC

show_message:
    ld a, (hl)
loop_show_message:
    call 0xBB5A                 ; TXT_OUTPUT
    inc hl
    ld a, (hl)
    cp #0xFF
    jr nz, loop_show_message
    ret

_putchar::
_putchar_rr_s::
     ld hl,#2
     add hl,sp

     ld a,(hl)
     call 0xBB5A
     ret

_putchar_rr_dbs::
     ld a,e
     call 0xBB5A
     ret

__clock::
    ret

_exit::
    ret

    .area _GSINIT
gsinit::
    .area _GSFINAL
    ret

;; Ordering of segments for the linker.
    .area _HOME
    .area _CODE
    .area _GSINIT
    .area _GSFINAL

    .area _DATA
    .area _BSS
    .area _HEAP

    .area _CODE
