; ������� ���
RAM_Flush:	
	LDI	ZL,Low(SRAM_START)	; ����� ������ ��� � ������
	LDI	ZH,High(SRAM_START)
	CLR	R16			; ������� R16
Flush:	
	ST 	Z+,R16			; ��������� 0 � ������ ������
	CPI	ZH,High(RAMEND)		; �������� ����� ����������?
	BRNE Flush			; ���? �������� ������!
 	CPI	ZL,Low(RAMEND)		; � ������� ���� ������ �����?
	BRNE Flush
 
; ������� ��������
	LDI	ZL, 30		; ����� ������ �������� ��������	
	CLR	ZH		; � ��� � ��� ����� ����
	DEC	ZL		; �������� �����
	ST	Z, ZH		; ���������� � ������� 0
	BRNE	PC-2		; ���� �� ��������� ��� �� �����������
		
	LDI R16,Low(RAMEND)	; ������������� �����
	OUT SPL,R16		; �����������!!!

; ������ ����������� ��������
 	LDI		temp,	0x00
	MOV		null,	temp