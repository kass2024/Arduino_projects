
_check:

;8x40 PC.c,19 :: 		void check(){
;8x40 PC.c,20 :: 		if(portc.f4){delay_ms(300); flag1 = ~flag1; flag2 = 0; flag3 = 0;}
	BTFSS      PORTC+0, 4
	GOTO       L_check0
	MOVLW      8
	MOVWF      R11+0
	MOVLW      157
	MOVWF      R12+0
	MOVLW      5
	MOVWF      R13+0
L_check1:
	DECFSZ     R13+0, 1
	GOTO       L_check1
	DECFSZ     R12+0, 1
	GOTO       L_check1
	DECFSZ     R11+0, 1
	GOTO       L_check1
	NOP
	NOP
	MOVLW
	XORWF      _flag1+0, 1
	BCF        _flag2+0, BitPos(_flag2+0)
	BCF        _flag3+0, BitPos(_flag3+0)
L_check0:
;8x40 PC.c,21 :: 		if(portc.f5){delay_ms(300); flag2 = ~flag2; flag1 = 0; flag3 = 0;}
	BTFSS      PORTC+0, 5
	GOTO       L_check2
	MOVLW      8
	MOVWF      R11+0
	MOVLW      157
	MOVWF      R12+0
	MOVLW      5
	MOVWF      R13+0
L_check3:
	DECFSZ     R13+0, 1
	GOTO       L_check3
	DECFSZ     R12+0, 1
	GOTO       L_check3
	DECFSZ     R11+0, 1
	GOTO       L_check3
	NOP
	NOP
	MOVLW
	XORWF      _flag2+0, 1
	BCF        _flag1+0, BitPos(_flag1+0)
	BCF        _flag3+0, BitPos(_flag3+0)
L_check2:
;8x40 PC.c,22 :: 		if(portc.f6){delay_ms(300); flag3 = ~flag3; flag1 = 0; flag2 = 0;}
	BTFSS      PORTC+0, 6
	GOTO       L_check4
	MOVLW      8
	MOVWF      R11+0
	MOVLW      157
	MOVWF      R12+0
	MOVLW      5
	MOVWF      R13+0
L_check5:
	DECFSZ     R13+0, 1
	GOTO       L_check5
	DECFSZ     R12+0, 1
	GOTO       L_check5
	DECFSZ     R11+0, 1
	GOTO       L_check5
	NOP
	NOP
	MOVLW
	XORWF      _flag3+0, 1
	BCF        _flag1+0, BitPos(_flag1+0)
	BCF        _flag2+0, BitPos(_flag2+0)
L_check4:
;8x40 PC.c,23 :: 		}
L_end_check:
	RETURN
; end of _check

_main:

;8x40 PC.c,25 :: 		void main() {
;8x40 PC.c,26 :: 		trisc = 0b01110000;
	MOVLW      112
	MOVWF      TRISC+0
;8x40 PC.c,27 :: 		trisb=0; portb=0; portc = 0;
	CLRF       TRISB+0
	CLRF       PORTB+0
	CLRF       PORTC+0
;8x40 PC.c,28 :: 		delay_ms(500);
	MOVLW      13
	MOVWF      R11+0
	MOVLW      175
	MOVWF      R12+0
	MOVLW      182
	MOVWF      R13+0
L_main6:
	DECFSZ     R13+0, 1
	GOTO       L_main6
	DECFSZ     R12+0, 1
	GOTO       L_main6
	DECFSZ     R11+0, 1
	GOTO       L_main6
	NOP
;8x40 PC.c,29 :: 		flag1 = 0; flag2 = 0; flag3 = 0;
	BCF        _flag1+0, BitPos(_flag1+0)
	BCF        _flag2+0, BitPos(_flag2+0)
	BCF        _flag3+0, BitPos(_flag3+0)
;8x40 PC.c,30 :: 		for(x=0;x<=40;x++){
	CLRF       _x+0
L_main7:
	MOVF       _x+0, 0
	SUBLW      40
	BTFSS      STATUS+0, 0
	GOTO       L_main8
;8x40 PC.c,31 :: 		movee[x] = 0;
	MOVF       _x+0, 0
	ADDLW      _movee+0
	MOVWF      FSR
	CLRF       INDF+0
;8x40 PC.c,30 :: 		for(x=0;x<=40;x++){
	INCF       _x+0, 1
;8x40 PC.c,32 :: 		}
	GOTO       L_main7
L_main8:
;8x40 PC.c,34 :: 		while(1){
L_main10:
;8x40 PC.c,35 :: 		if(flag1){
	BTFSS      _flag1+0, BitPos(_flag1+0)
	GOTO       L_main12
;8x40 PC.c,36 :: 		for(ll=0;ll<14;ll++){
	CLRF       _ll+0
	CLRF       _ll+1
L_main13:
	MOVLW      0
	SUBWF      _ll+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main84
	MOVLW      14
	SUBWF      _ll+0, 0
L__main84:
	BTFSC      STATUS+0, 0
	GOTO       L_main14
;8x40 PC.c,37 :: 		adress = msg1[ll] - 32;
	MOVF       _ll+0, 0
	ADDLW      _msg1+0
	MOVWF      FSR
	MOVLW      32
	SUBWF      INDF+0, 0
	MOVWF      R3+0
	CLRF       R3+1
	BTFSS      STATUS+0, 0
	DECF       R3+1, 1
	MOVF       R3+0, 0
	MOVWF      _adress+0
	MOVF       R3+1, 0
	MOVWF      _adress+1
;8x40 PC.c,38 :: 		adress = adress * 8 ;
	MOVLW      3
	MOVWF      R2+0
	MOVF       R3+0, 0
	MOVWF      R0+0
	MOVF       R3+1, 0
	MOVWF      R0+1
	MOVF       R2+0, 0
L__main85:
	BTFSC      STATUS+0, 2
	GOTO       L__main86
	RLF        R0+0, 1
	RLF        R0+1, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__main85
L__main86:
	MOVF       R0+0, 0
	MOVWF      _adress+0
	MOVF       R0+1, 0
	MOVWF      _adress+1
;8x40 PC.c,39 :: 		for(count2=adress;count2<adress+8;count2++){
	MOVF       R0+0, 0
	MOVWF      _count2+0
	MOVF       R0+1, 0
	MOVWF      _count2+1
L_main16:
	MOVLW      8
	ADDWF      _adress+0, 0
	MOVWF      R1+0
	MOVF       _adress+1, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	MOVWF      R1+1
	MOVF       R1+1, 0
	SUBWF      _count2+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main87
	MOVF       R1+0, 0
	SUBWF      _count2+0, 0
L__main87:
	BTFSC      STATUS+0, 0
	GOTO       L_main17
;8x40 PC.c,40 :: 		for(count3=0;count3<40;count3++){movee[count3] = movee[count3 + 1];}
	CLRF       _count3+0
	CLRF       _count3+1
L_main19:
	MOVLW      0
	SUBWF      _count3+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main88
	MOVLW      40
	SUBWF      _count3+0, 0
L__main88:
	BTFSC      STATUS+0, 0
	GOTO       L_main20
	MOVF       _count3+0, 0
	ADDLW      _movee+0
	MOVWF      R2+0
	MOVF       _count3+0, 0
	ADDLW      1
	MOVWF      R0+0
	MOVLW      0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      _count3+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	ADDLW      _movee+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R2+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
	INCF       _count3+0, 1
	BTFSC      STATUS+0, 2
	INCF       _count3+1, 1
	GOTO       L_main19
L_main20:
;8x40 PC.c,41 :: 		movee[40] = Character[count2] ;
	MOVF       _count2+0, 0
	ADDLW      _Character+0
	MOVWF      R0+0
	MOVLW      hi_addr(_Character+0)
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      _count2+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       R0+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoICP+0
	MOVWF      _movee+40
;8x40 PC.c,42 :: 		for(i2=0;i2<4;i2++){
	CLRF       _i2+0
	CLRF       _i2+1
L_main22:
	MOVLW      0
	SUBWF      _i2+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main89
	MOVLW      4
	SUBWF      _i2+0, 0
L__main89:
	BTFSC      STATUS+0, 0
	GOTO       L_main23
;8x40 PC.c,43 :: 		ds=1;SH_CP=0;SH_CP=1;ST_CP=0;ST_CP=1;
	BSF        PORTC+0, 0
	BCF        PORTC+0, 1
	BSF        PORTC+0, 1
	BCF        PORTC+0, 2
	BSF        PORTC+0, 2
;8x40 PC.c,44 :: 		for(i=0;i<=40;i++){
	CLRF       _i+0
	CLRF       _i+1
L_main25:
	MOVF       _i+1, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__main90
	MOVF       _i+0, 0
	SUBLW      40
L__main90:
	BTFSS      STATUS+0, 0
	GOTO       L_main26
;8x40 PC.c,45 :: 		PORTB =~ movee[i];
	MOVF       _i+0, 0
	ADDLW      _movee+0
	MOVWF      FSR
	COMF       INDF+0, 0
	MOVWF      PORTB+0
;8x40 PC.c,46 :: 		delay_us(500);
	MOVLW      4
	MOVWF      R12+0
	MOVLW      61
	MOVWF      R13+0
L_main28:
	DECFSZ     R13+0, 1
	GOTO       L_main28
	DECFSZ     R12+0, 1
	GOTO       L_main28
	NOP
	NOP
;8x40 PC.c,47 :: 		ds=0;SH_CP=0;SH_CP=1;ST_CP=0;ST_CP=1;
	BCF        PORTC+0, 0
	BCF        PORTC+0, 1
	BSF        PORTC+0, 1
	BCF        PORTC+0, 2
	BSF        PORTC+0, 2
;8x40 PC.c,48 :: 		check();
	CALL       _check+0
;8x40 PC.c,44 :: 		for(i=0;i<=40;i++){
	INCF       _i+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i+1, 1
;8x40 PC.c,49 :: 		}
	GOTO       L_main25
L_main26:
;8x40 PC.c,42 :: 		for(i2=0;i2<4;i2++){
	INCF       _i2+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i2+1, 1
;8x40 PC.c,50 :: 		}
	GOTO       L_main22
L_main23:
;8x40 PC.c,39 :: 		for(count2=adress;count2<adress+8;count2++){
	INCF       _count2+0, 1
	BTFSC      STATUS+0, 2
	INCF       _count2+1, 1
;8x40 PC.c,51 :: 		}
	GOTO       L_main16
L_main17:
;8x40 PC.c,36 :: 		for(ll=0;ll<14;ll++){
	INCF       _ll+0, 1
	BTFSC      STATUS+0, 2
	INCF       _ll+1, 1
;8x40 PC.c,52 :: 		}
	GOTO       L_main13
L_main14:
;8x40 PC.c,53 :: 		}
	GOTO       L_main29
L_main12:
;8x40 PC.c,54 :: 		else if(flag2){
	BTFSS      _flag2+0, BitPos(_flag2+0)
	GOTO       L_main30
;8x40 PC.c,55 :: 		for(ll=0;ll<12;ll++){
	CLRF       _ll+0
	CLRF       _ll+1
L_main31:
	MOVLW      0
	SUBWF      _ll+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main91
	MOVLW      12
	SUBWF      _ll+0, 0
L__main91:
	BTFSC      STATUS+0, 0
	GOTO       L_main32
;8x40 PC.c,56 :: 		adress = msg2[ll] - 32;
	MOVF       _ll+0, 0
	ADDLW      _msg2+0
	MOVWF      FSR
	MOVLW      32
	SUBWF      INDF+0, 0
	MOVWF      R3+0
	CLRF       R3+1
	BTFSS      STATUS+0, 0
	DECF       R3+1, 1
	MOVF       R3+0, 0
	MOVWF      _adress+0
	MOVF       R3+1, 0
	MOVWF      _adress+1
;8x40 PC.c,57 :: 		adress = adress * 8 ;
	MOVLW      3
	MOVWF      R2+0
	MOVF       R3+0, 0
	MOVWF      R0+0
	MOVF       R3+1, 0
	MOVWF      R0+1
	MOVF       R2+0, 0
L__main92:
	BTFSC      STATUS+0, 2
	GOTO       L__main93
	RLF        R0+0, 1
	RLF        R0+1, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__main92
L__main93:
	MOVF       R0+0, 0
	MOVWF      _adress+0
	MOVF       R0+1, 0
	MOVWF      _adress+1
;8x40 PC.c,58 :: 		for(count2=adress;count2<adress+8;count2++){
	MOVF       R0+0, 0
	MOVWF      _count2+0
	MOVF       R0+1, 0
	MOVWF      _count2+1
L_main34:
	MOVLW      8
	ADDWF      _adress+0, 0
	MOVWF      R1+0
	MOVF       _adress+1, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	MOVWF      R1+1
	MOVF       R1+1, 0
	SUBWF      _count2+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main94
	MOVF       R1+0, 0
	SUBWF      _count2+0, 0
L__main94:
	BTFSC      STATUS+0, 0
	GOTO       L_main35
;8x40 PC.c,59 :: 		for(count3=0;count3<40;count3++){movee[count3] = movee[count3 + 1];}
	CLRF       _count3+0
	CLRF       _count3+1
L_main37:
	MOVLW      0
	SUBWF      _count3+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main95
	MOVLW      40
	SUBWF      _count3+0, 0
L__main95:
	BTFSC      STATUS+0, 0
	GOTO       L_main38
	MOVF       _count3+0, 0
	ADDLW      _movee+0
	MOVWF      R2+0
	MOVF       _count3+0, 0
	ADDLW      1
	MOVWF      R0+0
	MOVLW      0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      _count3+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	ADDLW      _movee+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R2+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
	INCF       _count3+0, 1
	BTFSC      STATUS+0, 2
	INCF       _count3+1, 1
	GOTO       L_main37
L_main38:
;8x40 PC.c,60 :: 		movee[40] = Character[count2] ;
	MOVF       _count2+0, 0
	ADDLW      _Character+0
	MOVWF      R0+0
	MOVLW      hi_addr(_Character+0)
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      _count2+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       R0+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoICP+0
	MOVWF      _movee+40
;8x40 PC.c,61 :: 		for(i2=0;i2<4;i2++){
	CLRF       _i2+0
	CLRF       _i2+1
L_main40:
	MOVLW      0
	SUBWF      _i2+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main96
	MOVLW      4
	SUBWF      _i2+0, 0
L__main96:
	BTFSC      STATUS+0, 0
	GOTO       L_main41
;8x40 PC.c,62 :: 		ds=1;SH_CP=0;SH_CP=1;ST_CP=0;ST_CP=1;
	BSF        PORTC+0, 0
	BCF        PORTC+0, 1
	BSF        PORTC+0, 1
	BCF        PORTC+0, 2
	BSF        PORTC+0, 2
;8x40 PC.c,63 :: 		for(i=0;i<=40;i++){
	CLRF       _i+0
	CLRF       _i+1
L_main43:
	MOVF       _i+1, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__main97
	MOVF       _i+0, 0
	SUBLW      40
L__main97:
	BTFSS      STATUS+0, 0
	GOTO       L_main44
;8x40 PC.c,64 :: 		PORTB =~ movee[i];
	MOVF       _i+0, 0
	ADDLW      _movee+0
	MOVWF      FSR
	COMF       INDF+0, 0
	MOVWF      PORTB+0
;8x40 PC.c,65 :: 		delay_us(500);
	MOVLW      4
	MOVWF      R12+0
	MOVLW      61
	MOVWF      R13+0
L_main46:
	DECFSZ     R13+0, 1
	GOTO       L_main46
	DECFSZ     R12+0, 1
	GOTO       L_main46
	NOP
	NOP
;8x40 PC.c,66 :: 		ds=0;SH_CP=0;SH_CP=1;ST_CP=0;ST_CP=1;
	BCF        PORTC+0, 0
	BCF        PORTC+0, 1
	BSF        PORTC+0, 1
	BCF        PORTC+0, 2
	BSF        PORTC+0, 2
;8x40 PC.c,67 :: 		check();
	CALL       _check+0
;8x40 PC.c,63 :: 		for(i=0;i<=40;i++){
	INCF       _i+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i+1, 1
;8x40 PC.c,68 :: 		}
	GOTO       L_main43
L_main44:
;8x40 PC.c,61 :: 		for(i2=0;i2<4;i2++){
	INCF       _i2+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i2+1, 1
;8x40 PC.c,69 :: 		}
	GOTO       L_main40
L_main41:
;8x40 PC.c,58 :: 		for(count2=adress;count2<adress+8;count2++){
	INCF       _count2+0, 1
	BTFSC      STATUS+0, 2
	INCF       _count2+1, 1
;8x40 PC.c,70 :: 		}
	GOTO       L_main34
L_main35:
;8x40 PC.c,55 :: 		for(ll=0;ll<12;ll++){
	INCF       _ll+0, 1
	BTFSC      STATUS+0, 2
	INCF       _ll+1, 1
;8x40 PC.c,71 :: 		}
	GOTO       L_main31
L_main32:
;8x40 PC.c,72 :: 		}
	GOTO       L_main47
L_main30:
;8x40 PC.c,73 :: 		else if(flag3){
	BTFSS      _flag3+0, BitPos(_flag3+0)
	GOTO       L_main48
;8x40 PC.c,74 :: 		for(ll=0;ll<19;ll++){
	CLRF       _ll+0
	CLRF       _ll+1
L_main49:
	MOVLW      0
	SUBWF      _ll+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main98
	MOVLW      19
	SUBWF      _ll+0, 0
L__main98:
	BTFSC      STATUS+0, 0
	GOTO       L_main50
;8x40 PC.c,75 :: 		adress = msg3[ll] - 32;
	MOVF       _ll+0, 0
	ADDLW      _msg3+0
	MOVWF      FSR
	MOVLW      32
	SUBWF      INDF+0, 0
	MOVWF      R3+0
	CLRF       R3+1
	BTFSS      STATUS+0, 0
	DECF       R3+1, 1
	MOVF       R3+0, 0
	MOVWF      _adress+0
	MOVF       R3+1, 0
	MOVWF      _adress+1
;8x40 PC.c,76 :: 		adress = adress * 8 ;
	MOVLW      3
	MOVWF      R2+0
	MOVF       R3+0, 0
	MOVWF      R0+0
	MOVF       R3+1, 0
	MOVWF      R0+1
	MOVF       R2+0, 0
L__main99:
	BTFSC      STATUS+0, 2
	GOTO       L__main100
	RLF        R0+0, 1
	RLF        R0+1, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__main99
L__main100:
	MOVF       R0+0, 0
	MOVWF      _adress+0
	MOVF       R0+1, 0
	MOVWF      _adress+1
;8x40 PC.c,77 :: 		for(count2=adress;count2<adress+8;count2++){
	MOVF       R0+0, 0
	MOVWF      _count2+0
	MOVF       R0+1, 0
	MOVWF      _count2+1
L_main52:
	MOVLW      8
	ADDWF      _adress+0, 0
	MOVWF      R1+0
	MOVF       _adress+1, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	MOVWF      R1+1
	MOVF       R1+1, 0
	SUBWF      _count2+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main101
	MOVF       R1+0, 0
	SUBWF      _count2+0, 0
L__main101:
	BTFSC      STATUS+0, 0
	GOTO       L_main53
;8x40 PC.c,78 :: 		for(count3=0;count3<40;count3++){movee[count3] = movee[count3 + 1];}
	CLRF       _count3+0
	CLRF       _count3+1
L_main55:
	MOVLW      0
	SUBWF      _count3+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main102
	MOVLW      40
	SUBWF      _count3+0, 0
L__main102:
	BTFSC      STATUS+0, 0
	GOTO       L_main56
	MOVF       _count3+0, 0
	ADDLW      _movee+0
	MOVWF      R2+0
	MOVF       _count3+0, 0
	ADDLW      1
	MOVWF      R0+0
	MOVLW      0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      _count3+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	ADDLW      _movee+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R2+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
	INCF       _count3+0, 1
	BTFSC      STATUS+0, 2
	INCF       _count3+1, 1
	GOTO       L_main55
L_main56:
;8x40 PC.c,79 :: 		movee[40] = Character[count2] ;
	MOVF       _count2+0, 0
	ADDLW      _Character+0
	MOVWF      R0+0
	MOVLW      hi_addr(_Character+0)
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      _count2+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       R0+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoICP+0
	MOVWF      _movee+40
;8x40 PC.c,80 :: 		for(i2=0;i2<4;i2++){
	CLRF       _i2+0
	CLRF       _i2+1
L_main58:
	MOVLW      0
	SUBWF      _i2+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main103
	MOVLW      4
	SUBWF      _i2+0, 0
L__main103:
	BTFSC      STATUS+0, 0
	GOTO       L_main59
;8x40 PC.c,81 :: 		ds=1;SH_CP=0;SH_CP=1;ST_CP=0;ST_CP=1;
	BSF        PORTC+0, 0
	BCF        PORTC+0, 1
	BSF        PORTC+0, 1
	BCF        PORTC+0, 2
	BSF        PORTC+0, 2
;8x40 PC.c,82 :: 		for(i=0;i<=40;i++){
	CLRF       _i+0
	CLRF       _i+1
L_main61:
	MOVF       _i+1, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__main104
	MOVF       _i+0, 0
	SUBLW      40
L__main104:
	BTFSS      STATUS+0, 0
	GOTO       L_main62
;8x40 PC.c,83 :: 		PORTB =~ movee[i];
	MOVF       _i+0, 0
	ADDLW      _movee+0
	MOVWF      FSR
	COMF       INDF+0, 0
	MOVWF      PORTB+0
;8x40 PC.c,84 :: 		delay_us(500);
	MOVLW      4
	MOVWF      R12+0
	MOVLW      61
	MOVWF      R13+0
L_main64:
	DECFSZ     R13+0, 1
	GOTO       L_main64
	DECFSZ     R12+0, 1
	GOTO       L_main64
	NOP
	NOP
;8x40 PC.c,85 :: 		ds=0;SH_CP=0;SH_CP=1;ST_CP=0;ST_CP=1;
	BCF        PORTC+0, 0
	BCF        PORTC+0, 1
	BSF        PORTC+0, 1
	BCF        PORTC+0, 2
	BSF        PORTC+0, 2
;8x40 PC.c,86 :: 		check();
	CALL       _check+0
;8x40 PC.c,82 :: 		for(i=0;i<=40;i++){
	INCF       _i+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i+1, 1
;8x40 PC.c,87 :: 		}
	GOTO       L_main61
L_main62:
;8x40 PC.c,80 :: 		for(i2=0;i2<4;i2++){
	INCF       _i2+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i2+1, 1
;8x40 PC.c,88 :: 		}
	GOTO       L_main58
L_main59:
;8x40 PC.c,77 :: 		for(count2=adress;count2<adress+8;count2++){
	INCF       _count2+0, 1
	BTFSC      STATUS+0, 2
	INCF       _count2+1, 1
;8x40 PC.c,89 :: 		}
	GOTO       L_main52
L_main53:
;8x40 PC.c,74 :: 		for(ll=0;ll<19;ll++){
	INCF       _ll+0, 1
	BTFSC      STATUS+0, 2
	INCF       _ll+1, 1
;8x40 PC.c,90 :: 		}
	GOTO       L_main49
L_main50:
;8x40 PC.c,91 :: 		}
	GOTO       L_main65
L_main48:
;8x40 PC.c,93 :: 		for(ll=0;ll<12;ll++){
	CLRF       _ll+0
	CLRF       _ll+1
L_main66:
	MOVLW      0
	SUBWF      _ll+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main105
	MOVLW      12
	SUBWF      _ll+0, 0
L__main105:
	BTFSC      STATUS+0, 0
	GOTO       L_main67
;8x40 PC.c,94 :: 		adress = msg4[ll] - 32;
	MOVF       _ll+0, 0
	ADDLW      _msg4+0
	MOVWF      FSR
	MOVLW      32
	SUBWF      INDF+0, 0
	MOVWF      R3+0
	CLRF       R3+1
	BTFSS      STATUS+0, 0
	DECF       R3+1, 1
	MOVF       R3+0, 0
	MOVWF      _adress+0
	MOVF       R3+1, 0
	MOVWF      _adress+1
;8x40 PC.c,95 :: 		adress = adress * 8 ;
	MOVLW      3
	MOVWF      R2+0
	MOVF       R3+0, 0
	MOVWF      R0+0
	MOVF       R3+1, 0
	MOVWF      R0+1
	MOVF       R2+0, 0
L__main106:
	BTFSC      STATUS+0, 2
	GOTO       L__main107
	RLF        R0+0, 1
	RLF        R0+1, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__main106
L__main107:
	MOVF       R0+0, 0
	MOVWF      _adress+0
	MOVF       R0+1, 0
	MOVWF      _adress+1
;8x40 PC.c,96 :: 		for(count2=adress;count2<adress+8;count2++){
	MOVF       R0+0, 0
	MOVWF      _count2+0
	MOVF       R0+1, 0
	MOVWF      _count2+1
L_main69:
	MOVLW      8
	ADDWF      _adress+0, 0
	MOVWF      R1+0
	MOVF       _adress+1, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	MOVWF      R1+1
	MOVF       R1+1, 0
	SUBWF      _count2+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main108
	MOVF       R1+0, 0
	SUBWF      _count2+0, 0
L__main108:
	BTFSC      STATUS+0, 0
	GOTO       L_main70
;8x40 PC.c,97 :: 		for(count3=0;count3<40;count3++){movee[count3] = movee[count3 + 1];}
	CLRF       _count3+0
	CLRF       _count3+1
L_main72:
	MOVLW      0
	SUBWF      _count3+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main109
	MOVLW      40
	SUBWF      _count3+0, 0
L__main109:
	BTFSC      STATUS+0, 0
	GOTO       L_main73
	MOVF       _count3+0, 0
	ADDLW      _movee+0
	MOVWF      R2+0
	MOVF       _count3+0, 0
	ADDLW      1
	MOVWF      R0+0
	MOVLW      0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      _count3+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	ADDLW      _movee+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R2+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
	INCF       _count3+0, 1
	BTFSC      STATUS+0, 2
	INCF       _count3+1, 1
	GOTO       L_main72
L_main73:
;8x40 PC.c,98 :: 		movee[40] = Character[count2] ;
	MOVF       _count2+0, 0
	ADDLW      _Character+0
	MOVWF      R0+0
	MOVLW      hi_addr(_Character+0)
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      _count2+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       R0+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoICP+0
	MOVWF      _movee+40
;8x40 PC.c,99 :: 		for(i2=0;i2<4;i2++){
	CLRF       _i2+0
	CLRF       _i2+1
L_main75:
	MOVLW      0
	SUBWF      _i2+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main110
	MOVLW      4
	SUBWF      _i2+0, 0
L__main110:
	BTFSC      STATUS+0, 0
	GOTO       L_main76
;8x40 PC.c,100 :: 		ds=1;SH_CP=0;SH_CP=1;ST_CP=0;ST_CP=1;
	BSF        PORTC+0, 0
	BCF        PORTC+0, 1
	BSF        PORTC+0, 1
	BCF        PORTC+0, 2
	BSF        PORTC+0, 2
;8x40 PC.c,101 :: 		for(i=0;i<=40;i++){
	CLRF       _i+0
	CLRF       _i+1
L_main78:
	MOVF       _i+1, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__main111
	MOVF       _i+0, 0
	SUBLW      40
L__main111:
	BTFSS      STATUS+0, 0
	GOTO       L_main79
;8x40 PC.c,102 :: 		PORTB =~ movee[i];
	MOVF       _i+0, 0
	ADDLW      _movee+0
	MOVWF      FSR
	COMF       INDF+0, 0
	MOVWF      PORTB+0
;8x40 PC.c,103 :: 		delay_us(500);
	MOVLW      4
	MOVWF      R12+0
	MOVLW      61
	MOVWF      R13+0
L_main81:
	DECFSZ     R13+0, 1
	GOTO       L_main81
	DECFSZ     R12+0, 1
	GOTO       L_main81
	NOP
	NOP
;8x40 PC.c,104 :: 		ds=0;SH_CP=0;SH_CP=1;ST_CP=0;ST_CP=1;
	BCF        PORTC+0, 0
	BCF        PORTC+0, 1
	BSF        PORTC+0, 1
	BCF        PORTC+0, 2
	BSF        PORTC+0, 2
;8x40 PC.c,105 :: 		check();
	CALL       _check+0
;8x40 PC.c,101 :: 		for(i=0;i<=40;i++){
	INCF       _i+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i+1, 1
;8x40 PC.c,106 :: 		}
	GOTO       L_main78
L_main79:
;8x40 PC.c,99 :: 		for(i2=0;i2<4;i2++){
	INCF       _i2+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i2+1, 1
;8x40 PC.c,107 :: 		}
	GOTO       L_main75
L_main76:
;8x40 PC.c,96 :: 		for(count2=adress;count2<adress+8;count2++){
	INCF       _count2+0, 1
	BTFSC      STATUS+0, 2
	INCF       _count2+1, 1
;8x40 PC.c,108 :: 		}
	GOTO       L_main69
L_main70:
;8x40 PC.c,93 :: 		for(ll=0;ll<12;ll++){
	INCF       _ll+0, 1
	BTFSC      STATUS+0, 2
	INCF       _ll+1, 1
;8x40 PC.c,109 :: 		}
	GOTO       L_main66
L_main67:
;8x40 PC.c,110 :: 		}
L_main65:
L_main47:
L_main29:
;8x40 PC.c,111 :: 		}
	GOTO       L_main10
;8x40 PC.c,112 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
