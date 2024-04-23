; --- EXTERNAL SUBROUTINES ---
		xref		_enter_super
		xref		_exit_super


; --- CONSTANTS ---
BASE_ADDRESS	equ	$FFFF8201
ADDRESS_OFFSET	equ	8
BASE_OFFSET		equ	64		; offset from SP, not A6


;----- SUBROUTINE: clear_screen -----
;  Author: Marc Schroeder
; Purpose: to clear the entire screen unconventionally quickly
;
; Details: quick clear uses movem to reduce fetch-execute cycle overhead. takes
;          about half the number of clock cycles as the code in clear.s, and
;          sp runs in about 1/100th of a second (at 8MHz) instead of 1/50th
;----
		xdef		_clear_screen

_clear_screen:
		movem.l		d0-7/a0-6,-(sp)

		lea		zeros,a0
		movem.l		(a0)+,d1-7/a1-6
		movea.l		BASE_OFFSET(sp),a0
		adda.l		#32000,a0
		move.w		#614,d0
fill_loop:	
		movem.l		d1-7/a1-6,-(a0)
		dbra		d0,fill_loop
		movem.l		d1-5,-(a0)

		movem.l		(sp)+,d0-7/a0-6
		rts


;----- SUBROUTINE: clear_upper -----
;  Author: Marc Schroeder (edit by George Rostek)
; Purpose: to clear the entire sky, above ground, unconventionally quickly
;
; Details: quick upper uses movem to reduce fetch-execute cycle overhead. takes
;          about half the number of clock cycles as the code in clear.s, and
;          sp runs in about 1/100th of a second (at 8MHz) instead of 1/50th
;----
		xdef		_clear_upper

_clear_upper:
		movem.l		d0-7/a0-6,-(sp)

		lea		zeros,a0
		movem.l		(a0)+,d1-7/a1-6
		movea.l		BASE_OFFSET(sp),a0
		adda.l		#27200,a0					; = GROUND_HEIGHT * 80
		move.w		#522,d0						; = (27200 / 4 / 13) - 1
fill_loop2:	
		movem.l		d1-7/a1-6,-(a0)
		dbra		d0,fill_loop2
		movem.l		d1,-(a0)					; = 32000 - (523 * 4 * 13)
		
		movem.l		(sp)+,d0-7/a0-6
		rts


;----- SUBROUTINE: get_video_base -----
;
; C Prototype:
;     ULONG32 *get_video_base()
;
; Purpose: to replace Physbase system call
;----
		xdef		_get_video_base

_get_video_base:
		link	a6,#0
		move.l	a0,-(sp)

		clr.l	d0
		lea	BASE_ADDRESS,a0

		jsr _enter_super
		movep.w	(a0),d0
		jsr _exit_super

		lsl.l	#8,d0

		move.l	(sp)+,a0
		unlk	a6
		rts


;----- SUBROUTINE: set_video_base -----
;
; C Prototype:
;     void set_video_base(ULONG32 *base)
;
; Purpose: to replace Setscreen system call
;----
		xdef		_set_video_base

_set_video_base:
		link	a6,#0
		movem.l	d0-2/a0-2,-(sp)
		move.l	ADDRESS_OFFSET(a6),d0

		lsr.l 	#8,d0
		lea	BASE_ADDRESS,a0
		
		jsr _enter_super
		movep.w d0,(a0)
		jsr _exit_super

		movem.l 	(sp)+,d0-2/a0-2
		unlk	a6
		rts


; --- VARIABLES ---
zeros:		ds.l		13
