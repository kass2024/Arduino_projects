#line 1 "D:/1. Electronics/Abrar's corner/Raktim Sir/led matrix 8x40 - 16F876/FirmwareV1.0/8x40 PC.c"
#line 1 "d:/1. electronics/abrar's corner/raktim sir/led matrix 8x40 - 16f876/firmwarev1.0/font.h"
unsigned int ll;
unsigned char movee[40];
unsigned int adress,count2;
unsigned int count3,i,i2;

const unsigned short Character [] = {
 0, 0, 0, 0, 0, 0, 0, 0,
 0, 6, 95, 95, 6, 0, 0, 0,
 0, 7, 7, 0, 7, 7, 0, 0,
 20, 127, 127, 20, 127, 127, 20, 0,
 36, 46, 107, 107, 58, 18, 0, 0,
 70, 102, 48, 24, 12, 102, 98, 0,
 48, 122, 79, 93, 55, 122, 72, 0,
 4, 7, 3, 0, 0, 0, 0, 0,
 0, 28, 62, 99, 65, 0, 0, 0,
 0, 65, 99, 62, 28, 0, 0, 0,
 8, 42, 62, 28, 28, 62, 42, 8,
 8, 8, 62, 62, 8, 8, 0, 0,
 0, 128, 224, 96, 0, 0, 0, 0,
 8, 8, 8, 8, 8, 8, 0, 0,
 0, 0, 96, 96, 0, 0, 0, 0,
 96, 48, 24, 12, 6, 3, 1, 0,
 62, 127, 113, 89, 77, 127, 62, 0,
 64, 66, 127, 127, 64, 64, 0, 0,
 98, 115, 89, 73, 111, 102, 0, 0,
 34, 99, 73, 73, 127, 54, 0, 0,
 24, 28, 22, 83, 127, 127, 80, 0,
 39, 103, 69, 69, 125, 57, 0, 0,
 60, 126, 75, 73, 121, 48, 0, 0,
 3, 3, 113, 121, 15, 7, 0, 0,
 54, 127, 73, 73, 127, 54, 0, 0,
 6, 79, 73, 105, 63, 30, 0, 0,
 0, 0, 102, 102, 0, 0, 0, 0,
 0, 128, 230, 102, 0, 0, 0, 0,
 8, 28, 54, 99, 65, 0, 0, 0,
 36, 36, 36, 36, 36, 36, 0, 0,
 0, 65, 99, 54, 28, 8, 0, 0,
 2, 3, 81, 89, 15, 6, 0, 0,
 62, 127, 65, 93, 93, 31, 30, 0,
 124, 126, 19, 19, 126, 124, 0, 0,
 65, 127, 127, 73, 73, 127, 54, 0,
 28, 62, 99, 65, 65, 99, 34, 0,
 65, 127, 127, 65, 99, 62, 28, 0,
 65, 127, 127, 73, 93, 65, 99, 0,
 65, 127, 127, 73, 29, 1, 3, 0,
 28, 62, 99, 65, 81, 115, 114, 0,
 127, 127, 8, 8, 127, 127, 0, 0,
 0, 65, 127, 127, 65, 0, 0, 0,
 48, 112, 64, 65, 127, 63, 1, 0,
 65, 127, 127, 8, 28, 119, 99, 0,
 65, 127, 127, 65, 64, 96, 112, 0,
 127, 127, 14, 28, 14, 127, 127, 0,
 127, 127, 6, 12, 24, 127, 127, 0,
 28, 62, 99, 65, 99, 62, 28, 0,
 65, 127, 127, 73, 9, 15, 6, 0,
 30, 63, 33, 113, 127, 94, 0, 0,
 65, 127, 127, 9, 25, 127, 102, 0,
 38, 111, 77, 89, 115, 50, 0, 0,
 3, 65, 127, 127, 65, 3, 0, 0,
 127, 127, 64, 64, 127, 127, 0, 0,
 31, 63, 96, 96, 63, 31, 0, 0,
 127, 127, 48, 24, 48, 127, 127, 0,
 67, 103, 60, 24, 60, 103, 67, 0,
 7, 79, 120, 120, 79, 7, 0, 0,
 71, 99, 113, 89, 77, 103, 115, 0,
 0, 127, 127, 65, 65, 0, 0, 0,
 1, 3, 6, 12, 24, 48, 96, 0,
 0, 65, 65, 127, 127, 0, 0, 0,
 8, 12, 6, 3, 6, 12, 8, 0,
 128, 128, 128, 128, 128, 128, 128, 128,
 0, 0, 3, 7, 4, 0, 0, 0,
 32, 116, 84, 84, 60, 120, 64, 0,
 65, 127, 63, 72, 72, 120, 48, 0,
 56, 124, 68, 68, 108, 40, 0, 0,
 48, 120, 72, 73, 63, 127, 64, 0,
 56, 124, 84, 84, 92, 24, 0, 0,
 72, 126, 127, 73, 3, 2, 0, 0,
 152, 188, 164, 164, 248, 124, 4, 0,
 65, 127, 127, 8, 4, 124, 120, 0,
 0, 68, 125, 125, 64, 0, 0, 0,
 96, 224, 128, 128, 253, 125, 0, 0,
 65, 127, 127, 16, 56, 108, 68, 0,
 0, 65, 127, 127, 64, 0, 0, 0,
 124, 124, 24, 56, 28, 124, 120, 0,
 124, 124, 4, 4, 124, 120, 0, 0,
 56, 124, 68, 68, 124, 56, 0, 0,
 132, 252, 248, 164, 36, 60, 24, 0,
 24, 60, 36, 164, 248, 252, 132, 0,
 68, 124, 120, 76, 4, 28, 24, 0,
 72, 92, 84, 84, 116, 36, 0, 0,
 0, 4, 62, 127, 68, 36, 0, 0,
 60, 124, 64, 64, 60, 124, 64, 0,
 28, 60, 96, 96, 60, 28, 0, 0,
 60, 124, 112, 56, 112, 124, 60, 0,
 68, 108, 56, 16, 56, 108, 68, 0,
 156, 188, 160, 160, 252, 124, 0, 0,
 76, 100, 116, 92, 76, 100, 0, 0,
};
#line 7 "D:/1. Electronics/Abrar's corner/Raktim Sir/led matrix 8x40 - 16F876/FirmwareV1.0/8x40 PC.c"
unsigned char msg1[] = "EID Mubarak.  ";
unsigned char msg2[] = "BanglaDesh  ";
unsigned char msg3[] = "Nice TO meet YOU.  ";
unsigned char msg4[] = "Welcome :)  ";

unsigned short x, indx, rxbyte;


bit flag1;
bit flag2;
bit flag3;

void check(){
 if(portc.f4){delay_ms(300); flag1 = ~flag1; flag2 = 0; flag3 = 0;}
 if(portc.f5){delay_ms(300); flag2 = ~flag2; flag1 = 0; flag3 = 0;}
 if(portc.f6){delay_ms(300); flag3 = ~flag3; flag1 = 0; flag2 = 0;}
}

void main() {
trisc = 0b01110000;
trisb=0; portb=0; portc = 0;
delay_ms(500);
flag1 = 0; flag2 = 0; flag3 = 0;
 for(x=0;x<=40;x++){
 movee[x] = 0;
 }

 while(1){
 if(flag1){
 for(ll=0;ll<14;ll++){
 adress = msg1[ll] - 32;
 adress = adress * 8 ;
 for(count2=adress;count2<adress+8;count2++){
 for(count3=0;count3<40;count3++){movee[count3] = movee[count3 + 1];}
 movee[40] = Character[count2] ;
 for(i2=0;i2<4;i2++){
  PORTC.f0 =1; PORTC.f1 =0; PORTC.f1 =1; PORTC.f2 =0; PORTC.f2 =1;
 for(i=0;i<=40;i++){
 PORTB =~ movee[i];
 delay_us(500);
  PORTC.f0 =0; PORTC.f1 =0; PORTC.f1 =1; PORTC.f2 =0; PORTC.f2 =1;
 check();
 }
 }
 }
 }
 }
 else if(flag2){
 for(ll=0;ll<12;ll++){
 adress = msg2[ll] - 32;
 adress = adress * 8 ;
 for(count2=adress;count2<adress+8;count2++){
 for(count3=0;count3<40;count3++){movee[count3] = movee[count3 + 1];}
 movee[40] = Character[count2] ;
 for(i2=0;i2<4;i2++){
  PORTC.f0 =1; PORTC.f1 =0; PORTC.f1 =1; PORTC.f2 =0; PORTC.f2 =1;
 for(i=0;i<=40;i++){
 PORTB =~ movee[i];
 delay_us(500);
  PORTC.f0 =0; PORTC.f1 =0; PORTC.f1 =1; PORTC.f2 =0; PORTC.f2 =1;
 check();
 }
 }
 }
 }
 }
 else if(flag3){
 for(ll=0;ll<19;ll++){
 adress = msg3[ll] - 32;
 adress = adress * 8 ;
 for(count2=adress;count2<adress+8;count2++){
 for(count3=0;count3<40;count3++){movee[count3] = movee[count3 + 1];}
 movee[40] = Character[count2] ;
 for(i2=0;i2<4;i2++){
  PORTC.f0 =1; PORTC.f1 =0; PORTC.f1 =1; PORTC.f2 =0; PORTC.f2 =1;
 for(i=0;i<=40;i++){
 PORTB =~ movee[i];
 delay_us(500);
  PORTC.f0 =0; PORTC.f1 =0; PORTC.f1 =1; PORTC.f2 =0; PORTC.f2 =1;
 check();
 }
 }
 }
 }
 }
 else{
 for(ll=0;ll<12;ll++){
 adress = msg4[ll] - 32;
 adress = adress * 8 ;
 for(count2=adress;count2<adress+8;count2++){
 for(count3=0;count3<40;count3++){movee[count3] = movee[count3 + 1];}
 movee[40] = Character[count2] ;
 for(i2=0;i2<4;i2++){
  PORTC.f0 =1; PORTC.f1 =0; PORTC.f1 =1; PORTC.f2 =0; PORTC.f2 =1;
 for(i=0;i<=40;i++){
 PORTB =~ movee[i];
 delay_us(500);
  PORTC.f0 =0; PORTC.f1 =0; PORTC.f1 =1; PORTC.f2 =0; PORTC.f2 =1;
 check();
 }
 }
 }
 }
 }
 }
}
