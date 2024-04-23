; --- EXTERNAL SUBROUTINES ---
		xref		_vsync_req
		xref		_ikbd_req


;----- SUBROUTINE: vsync_isr -----
;
; C Prototype:
;     void vsync_isr()
;
; Purpose: synchronizes frame updates with screen refresh rate
;----
		xdef	_vsync_isr

_vsync_isr:
		link	a6,#0
		movem.l	d0-2/a0-2,-(sp)

		jsr	_vsync_req

		movem.l	(sp)+,d0-2/a0-2
		unlk	a6
		rte


;----- SUBROUTINE: ikbd_isr -----
;
; C Prototype:
;     void ikbd_isr()
;
; Purpose: process keyboard and mouse input
;----
		xdef	_ikbd_isr

_ikbd_isr:
		link	a6,#0
		movem.l	d0-2/a0-2,-(sp)

		jsr _ikbd_req

		movem.l	(sp)+,d0-2/a0-2
		unlk	a6
		rte
