#include <xc.h>

void SerialInit(){
    ANSELB = 0x00;
    TRISBbits.RB6=1;
    TRISBbits.RB7=1;
     
    RCSTA2bits.CREN=1;
    TXSTA2bits.SYNC=0;
    RCSTA2bits.SPEN=1;
    
    BAUDCON2 = 0x08;//0x38;
    SPBRG2 = 0x82;//BaudRate 9600 64Mhz Kristal icin 0x0682
    SPBRGH2 = 0x06;//0x03;//0;
    TXSTA2 = 0x24;
    RCSTA2 = 0x90;
    
    INTCONbits.GIE=1;
    INTCONbits.TMR0IE=1;
    INTCONbits.TMR0IF=0;
    
    PIE3bits.RC2IE=1;
    INTCONbits.PEIE=1;
    INTCONbits.GIE=1;
    
}

void OscTune(){
    OSCCONbits.IRCF     = 0b111; //freq
    OSCCONbits.SCS      = 0b00; //
    OSCCON2bits.PLLRDY  = 0b1;
    OSCCON2bits.SOSCRUN = 0b0;
    OSCTUNEbits.PLLEN   = 0b1;

}

void SerialWrite(char data){
    while(!TXSTA2bits.TRMT);
    TXREG2=data;
}