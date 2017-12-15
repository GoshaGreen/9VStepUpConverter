.ORG $000      ; (RESET) 
RJMP   Reset
.ORG $001		; IRQ0 Handler
RETI          
.ORG $002		; PCINT0 Handler
RETI	;RJMP	PCINT           
.ORG $003		; Timer0 Overflow Handler
RETI
.ORG $004		; EEPROM Ready Handler
RETI             
.ORG $005		; Analog Comparator Handler
RJMP	ANA_COMP;RETI	;RJMP	T0IO 	    
.ORG $006		; Timer0 CompareA Handler
RETI       
.ORG $007		; Timer0 CompareB Handler
RETI            
.ORG $008		; Watchdog Interrupt Handler
RETI
.ORG $009		; ADC Conversion Handler
RJMP	ADC_COMPL;RETI
.ORG  $016      	; Конец таблицы прерываний
		
; Interrupts ==============================================
ANA_COMP:

	RETI

ADC_COMPL:
	SBI		PINB, pinout
	IN		temp,	ADCH
	;COM		temp		
	CPI		temp, 127
	BRLO	lbl1
	OUTI		OCR0B,	1
	CBI		PORTB, 3
	RETI
lbl1:
	OUTI		OCR0B,	4
	SBI		PORTB, 3
	RETI



; End Interrupts ==========================================
Reset:  
