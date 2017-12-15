	.def	temp = r17
	.def	null = r10
	.equ	pinin = 4
	.equ	pinout = 2
	.include "macro.inc"	
;88 RAM ========================================================
.DSEG ; ������� 
;CCNT:	.byte	4
;TCNT:	.byte	4

;88 END RAM / FLASH ============================================
.CSEG ; �������
; Include ======================================================
	.include "interrupts.inc"
	.include "coreinit.inc"	
; END Include / Internal Hardware Init  ========================
//��������� ������
	OUTI	DDRB,		0xff-(1<<pinin)

//��������� �������
	OUTI	TCCR0A,		(0<<COM0A1)|(1<<COM0A0)|(1<<COM0B1)|(0<<COM0B0)|(1<<WGM01)|(1<<WGM00)		//���������� ������ �������
	OUTI	TCCR0B,		(1<<WGM02)|(1<<CS00)		//������ ����������, ������� ��� 0x01
	OUT		TIMSK0,		null	//���������� �� ������������
	OUT		TCNT0,		null		//��������� ��������� ��������
	OUT		TIFR0,		null		//�������� �������
	OUTI	OCR0A,		8

// ��������� ADC
	LDI		temp,		(1<<REFS0)|(1<<ADLAR)|(1<<MUX1)|(0<<MUX0);0x62
	OUT		ADMUX,		temp
	LDI		temp,		(1<<ADEN)|(1<<ADSC)|(1<<ADATE)|(0<<ADIF)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)
	OUT 	ADCSRA,		temp
	OUT		ADCSRB,		null
	OUTI	DIDR0,		(1<<ADC2D)
	NOP
	NOP
	NOP
	NOP
	NOP
; END Internal Hardware Init / External Hardware Init  =========

; END External Hardware Init / Main ============================

	/*OUTI	MCUCR,	0b00100000		//��� Idle
	LDI		mode,	1	//����� ������� (���������)
	CLR		R25*/
main:
	;SBI		PINB, pinout
	SEI
	NOP 
/*	SLEEP*/
 	RJMP main

; END Main / Procedure =========================================

; END Procedure ================================================
;88 END FLASH / EEPROM =========================================
.ESEG				; ������� EEPROM

;88 End EEPROM =================================================
