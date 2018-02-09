#include <xc.h>

void EEPROM_WriteByte(unsigned char Address,unsigned char Data){
    
    unsigned char gie_status;
    
    while (EECON1bits.WR);
    EEADR=Address;
    EEDATA=Data;        
    EECON1bits.WREN=1; //write enable
    gie_status=INTCONbits.GIE;
    INTCONbits.GIE=0;
    EECON2=0x55;
    EECON2=0xaa;
    EECON1bits.WR=1;
    INTCONbits.GIE=gie_status;
    EECON1bits.WREN=0;
    
}

unsigned char EEPROM_ReadByte(unsigned char eepromAddress){
    while(EECON1bits.RD || EECON1bits.WR);           
    EEADR=eepromAddress;       
    RD = 1;                    
    return(EEDATA);           
    
}