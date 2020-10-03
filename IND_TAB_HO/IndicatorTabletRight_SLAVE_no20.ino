// Indicator tablet Right side
// AJS37 Viggen
// Code modified by outbaxx from [FSF]Ian´s A-10 CLP

//#define DCSBIOS_IRQ_SERIAL
//#define DCSBIOS_DEFAULT_SERIAL
#define DCSBIOS_RS485_SLAVE 20
#define TXENABLE_PIN 2
#include <DcsBios.h>
#include <LedControl.h>
//bool power_is_on;
//pin 10 is connected to LOAD
//pin 11 is connected to the CLK 
//pin 12 is connected to the DataIn 
LedControl lc=LedControl(12,11,10,1);//DIN,CLK,LOAD,# OF IC's

// Map of the DIG on MAX7219
unsigned char it_row_map[20] = {
  0, 0, 0, 0,
  1, 1, 1, 1,
  2, 2, 2, 2,
  3, 3, 3, 3,
  4, 4, 4, 4,
   };

// SEG to byte
#define SEG_DP (1<<7)
#define SEG_A (1<<6)
#define SEG_B (1<<5)
#define SEG_C (1<<4)
#define SEG_D (1<<3)
#define SEG_E (1<<2)
#define SEG_F (1<<1)
#define SEG_G (1<<0)
//Map for SEG on MAX7219
unsigned char it_seg_map[20]= {
  SEG_DP, SEG_A, SEG_B, SEG_C,
  SEG_DP, SEG_A, SEG_B, SEG_C,
  SEG_DP, SEG_A, SEG_B, SEG_C,
  SEG_DP, SEG_A, SEG_B, SEG_C,
  SEG_DP, SEG_A, SEG_B, SEG_C,
 
  };
  

unsigned char max7219_rows[5];

void setup() {
  DcsBios::setup();
  memset(max7219_rows, 0xff, sizeof(max7219_rows));
  
  lc.shutdown(0,false);   //turn on the display
  lc.setIntensity(0,15);   //set the brightness
  lc.clearDisplay(0);     //clear the display and get ready for new data
}
  
void updateIndicatorTabletRight(unsigned int address, unsigned int data) {
    unsigned char it_row = (address - 0x4670) * 2;
    unsigned char start_index = it_row * 4;
    unsigned char column = 0;
    unsigned char i;

    bool is_on;
    for (i=0; i<16; i++) {
        is_on = data & 0x01;
        // set caution light state (clp_row, column, is_on)
        if (is_on) {
          max7219_rows[it_row_map[start_index+i]] |= it_seg_map[start_index+i];
        } else {
          max7219_rows[it_row_map[start_index+i]] &= ~(it_seg_map[start_index+i]);
        }
        data >>= 1;
        column++;
        if (column == 4) {
           it_row++;
           column = 0;
        }
    }

}

//Läs Höger Indikeringstablå
void onIndTabRData1Change(unsigned int newValue) {
    updateIndicatorTabletRight(0x4670, newValue);
}
DcsBios::IntegerBuffer IndTabRData1(0x4670, 0xffff, 0, onIndTabRData1Change);

void onIndTabRData2Change(unsigned int newValue) {
    updateIndicatorTabletRight(0x4672, newValue);
}
DcsBios::IntegerBuffer IndTabRData2(0x4672, 0xffff, 0, onIndTabRData2Change);

void loop() {
  DcsBios::loop();
  
  // update MAX7219
  unsigned char i;
  for (i=0; i<5; i++) {
    lc.setRow(0, i, max7219_rows[i]);
  }
}
