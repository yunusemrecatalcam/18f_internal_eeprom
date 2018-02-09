/*
 * File:   main.c
 * Author: Monster
 *
 * Created on 09 ?ubat 2018 Cuma, 12:20
 */


#include <xc.h>
#include "eeprom.h"
#include "main.h"
#include "config.h"
#include "serial.h"

#define _XTAL_FREQ 64000000

void main(void) {
    TRISC=0x00;
    
    while(1){
        
        PORTCbits.RC3=1;
        PORTCbits.RC2=1;
        PORTCbits.RC4=1;
        //EEPROM_WriteByte('0','3');
        SerialWrite('u');
        __delay_ms(100);
    }
    
    return;
}
