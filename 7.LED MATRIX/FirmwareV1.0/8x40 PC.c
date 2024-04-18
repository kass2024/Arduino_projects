#include "font.h"
#define ds PORTC.f0
#define SH_CP PORTC.f1
#define ST_CP PORTC.f2
#define boot PORTC.f3

unsigned char msg[] = "Nice TO meet YOU. ";  // 18 char

unsigned short x, indx, rxbyte;

void main() {
    trisc = 0b01110000;
    trisb = 0;
    portb = 0;
    portc = 0;
    delay_ms(500);
    for (x = 0; x <= 40; x++) movee[x] = 0;

    while (1) {
        for (ll = 0; ll < 18; ll++) {
            adress = msg[ll] - 32;
            adress = adress * 8;
            for (count2 = adress; count2 < adress + 8; count2++) {
                for (count3 = 0; count3 < 40; count3++) {
                    movee[count3] = movee[count3 + 1];
                }
                movee[40] = Character[count2];
                for (i2 = 0; i2 < 4; i2++) {
                    ds = 1;
                    SH_CP = 0; SH_CP = 1;
                    ST_CP = 0; ST_CP = 1;
                    for (i = 0; i <= 40; i++) {
                        PORTB = ~movee[i];
                        delay_us(500);
                        ds = 0;
                        SH_CP = 0; SH_CP = 1;
                        ST_CP = 0; ST_CP = 1;
                    }
                }
            }
        }
    }
}