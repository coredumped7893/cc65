;
; Maciej 'YTM/Elysium' Witkowiak
; 2.7.2001
;
; this file provides the _dio_write function
;
; unsigned char __fastcall__ dio_write (dhandle_t handle, unsigned sect_num, const void *buffer);
;

	    .import dio_params, setoserror
	    .export _dio_write

	    .include "geossym.inc"
	    .include "jumptab.inc"

_dio_write:
	jsr dio_params
	jsr WriteBlock
	jmp setoserror
