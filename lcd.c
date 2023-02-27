
#include "lcd.h"



void LCD_Init(void) {
	CLKPR = (1 << CLKPCE); 
	CLKPR = 0x00;

    // Use external asynchronous clock source 
    // 1/3 Bias and 1/4 duty, 25 segments enabled 
    LCDCRB = (1<<LCDCS) | (1<<LCDMUX1)| (1<<LCDMUX0)| (1<<LCDPM2) | (1<<LCDPM1) | (1<<LCDPM0);
	// 
    // Using 16 as prescaler selection and 8 as LCD Clock Divide 
    LCDFRR = (1<<LCDCD2) | (1<<LCDCD1) | (1<<LCDCD0);
    // Set segment drive time to 300 us and output voltage to 3.35 V
    LCDCCR = (1<<LCDCC3) | (1<<LCDCC2) | (1<<LCDCC1)| (1<<LCDCC0);
    // Enable LCD, low power waveform, no frame interrupt, no blanking 
    LCDCRA = (1<<LCDEN) | (1<<LCDAB) |  (0<<LCDBL);
}

int getValueArray(int i){

    switch (i)
    {
    case 0:
        return ZeroValue;

    case 1:
        return OneValue;
    
    case 2:
        return TwoValue;

    case 3:
        return ThreeValue;
    
    case 4:
        return FourValue;

    case 5:
        return FiveValue;
    
    case 6:
        return SixValue;
    
    case 7:
        return SevenValue;
        
    case 8:
        return EightValue;
    
    case 9:
        return NineValue;
    
    default: // 10
        return BlankValue;
    }
}


void writeChar(char ch, int pos) {

	volatile int i = 0;
	if (pos < 0 || pos > 5) {
		return; // do nothing if pos is outside the supported range
	}
	if ((int)ch < (0+48) || (int)ch > (9+48)) {
		i=10;
	}else{
        i = ch - 48;
    }
	if(pos==0){
		LCDDR0 =  (LCDDR0&0xF0)  |        (0xF&getValueArray(i))<<0;
		LCDDR5 =  (LCDDR5&0xF0)  |  (((0xF<<4)&getValueArray(i))>>4);
		LCDDR10 = (LCDDR10&0xF0) |  (((0xF<<8)&getValueArray(i))>>8);
		LCDDR15 = (LCDDR15&0xF0) | (((0xF<<12)&getValueArray(i))>>12);
		
	} else if(pos==1){
		LCDDR0 =     (LCDDR0&0x0F)  |       ((0xF&getValueArray(i))<<4);
		LCDDR5 =     (LCDDR5&0x0F)  |  (((0xF<<4)&getValueArray(i))>>0);
		LCDDR10 =    (LCDDR10&0x0F) |  (((0xF<<8)&getValueArray(i))>>4);
		LCDDR15 =    (LCDDR15&0x0F) | (((0xF<<12)&getValueArray(i))>>8);
	} else if(pos==2){
		LCDDR1 =  (LCDDR1&0xF0)  |        (0xF&getValueArray(i))<<0;
		LCDDR6 =  (LCDDR6&0xF0)  |  (((0xF<<4)&getValueArray(i))>>4);
		LCDDR11 = (LCDDR11&0xF0) |  (((0xF<<8)&getValueArray(i))>>8);
		LCDDR16 = (LCDDR16&0xF0) | (((0xF<<12)&getValueArray(i))>>12);
		
	} else if(pos==3){
		LCDDR1 =     (LCDDR1&0x0F)  |       ((0xF&getValueArray(i))<<4);
		LCDDR6 =     (LCDDR6&0x0F)  |  (((0xF<<4)&getValueArray(i))>>0);
		LCDDR11 =    (LCDDR11&0x0F) |  (((0xF<<8)&getValueArray(i))>>4);
		LCDDR16 =    (LCDDR16&0x0F) | (((0xF<<12)&getValueArray(i))>>8);
		
	} else if(pos==4){
		LCDDR2 =  (LCDDR2&0xF0)  |        (0xF&getValueArray(i))<<0;
		LCDDR7 =  (LCDDR7&0xF0)  |  (((0xF<<4)&getValueArray(i))>>4);
		LCDDR12 = (LCDDR12&0xF0) |  (((0xF<<8)&getValueArray(i))>>8);
		LCDDR17 = (LCDDR17&0xF0) | (((0xF<<12)&getValueArray(i))>>12);
		
	} else if(pos==5){
		LCDDR2 =     (LCDDR2&0x0F)  |       ((0xF&getValueArray(i))<<4);
		LCDDR7 =     (LCDDR7&0x0F)  |  (((0xF<<4)&getValueArray(i))>>0);
		LCDDR12 =    (LCDDR12&0x0F) |  (((0xF<<8)&getValueArray(i))>>4);
		LCDDR17 =    (LCDDR17&0x0F) | (((0xF<<12)&getValueArray(i))>>8);
		
	}
	

}

void printAt(long num, int pos) {
    int pp = pos;
    writeChar( (num % 100) / 10 + '0', pp);
    pp++;
    writeChar( num % 10 + '0', pp);
}