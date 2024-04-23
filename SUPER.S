; --- CONSTANTS ---
GEMDOS		equ	1
SUPER		equ	$20


;----- SUBROUTINE: enter_super -----
;
; C Prototype:
;     void enter_super()
;
; Purpose: to enter supervisor mode
;----
		xdef		_enter_super

_enter_super:
		link	a6,#0
		movem.l	d0-2/a0-2,-(sp)

		clr.l	-(sp)
		move.w 	#SUPER,-(sp)
		trap	#GEMDOS
		addq.l	#6,sp

		move.l	d0,old_ssp
		movem.l	(sp)+,d0-2/a0-2
		unlk	a6
		rts


;----- SUBROUTINE: exit_super -----
;
; C Prototype:
;     void exit_super()
;
; Purpose: to exit supervisor mode
;----
		xdef		_exit_super

_exit_super:
		link	a6,#0
		movem.l	d0-2/a0-2,-(sp)

		move.l	old_ssp,-(sp)
		move.w	#SUPER,-(sp)
		trap	#GEMDOS
		addq.l	#6,sp

		movem.l	(sp)+,d0-2/a0-2
		unlk	a6
		rts


; --- VARIABLES ---
old_ssp:	ds.l		1
