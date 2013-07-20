;Functions:
;void mode(int mode)
;unsigned char waitchar()

.globl _mode

;void mode(int mode)
;Sets the current text mode

_mode::
	ld	a,#2
	call	0xBC0E
	ret

;unsigned char waitchar()
;Waits for the next character from the keyboard buffer, and returns it.

_waitchar::
	call	0xBB06
	ld	l,a
	ret
