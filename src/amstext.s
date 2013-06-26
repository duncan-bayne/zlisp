;Functions:
;void mode(int mode)
	
.globl _mode

;void mode(int mode)
;Sets the current text mode

_mode::
	ld	a,#2
	call	0xBC0E
	ret

