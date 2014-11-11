#include "LiquidCrystalSerial.hh"
#include "lcdDefaultFonts.hh"
#include "Configuration.hh"

#include <stdio.h>
#include <string.h>
#include <util/delay.h>



LiquidCrystalSerial::LiquidCrystalSerial(Pin SCK, Pin MOSI, Pin DC, Pin RST, Pin CS) 
{
	sck_pin = SCK;
	mosi_pin = MOSI;
	dc_pin = DC;
	rst_pin = RST;
	cs_pin = CS;
	
	sck_pin.setDirection(true);
	mosi_pin.setDirection(true);
	dc_pin.setDirection(true);
	rst_pin.setDirection(true);
	cs_pin.setDirection(true);
	
	grayscale = 0xc0;
}

void LiquidCrystalSerial::begin()
{
	rst_pin.setValue(false);
	_delay_us(200000);
	rst_pin.setValue(true);
	_delay_us(50000);


	LCD_WR_CMD(0xE2);//system reset
	_delay_us(10000);
	LCD_WR_CMD(0x27);
	LCD_WR_CMD(0x2b);
	LCD_WR_CMD(0x2f); //set pump control
	LCD_WR_CMD(0xeb); //set bias=1/11
	LCD_WR_CMD(0x81); //set
	LCD_WR_CMD(0x36); //set PM=12,vop=12.8v,4c
	LCD_WR_CMD(0xa9); //set linerate mux,a2
	LCD_WR_CMD(0xc8);
	LCD_WR_CMD(0x0b);
	LCD_WR_CMD(0x89);
	LCD_WR_CMD(0xc4); //MY=1,MX=0:从左到右，再从上到下。
	LCD_WR_CMD(0xf1); //f1
	LCD_WR_CMD(0x7f);
	LCD_WR_CMD(0xd3); //gray shade set
	LCD_WR_CMD(0xd7); //gray shade set
	LCD_WR_CMD(0xAf); //set display enable
}

void LiquidCrystalSerial::setGrayscale(uint8_t scale)
{
	if(scale == 3)
		grayscale = 0xc0;
	if(scale == 2)
		grayscale = 0x80;
	if(scale == 1)
		grayscale = 0x40;
	if(scale == 0)
		grayscale = 0x00;
}
/********** high level commands, for the user! */
void LiquidCrystalSerial::clear()
{
	uint8_t i,j;
	LCD_WR_CMD(0x70); //行地址高3位
	LCD_WR_CMD(0x60); //行地址低4位
	LCD_WR_CMD(0x00); //列地址
	for(i=0;i<128;i++)
	{
		for(j=0;j<16;j++)
		{
			LCD_MONO_DATA(0x00);
		}
	}
}


// A faster version of home()
void LiquidCrystalSerial::homeCursor()
{
	setCursor(0, 0);
}

void LiquidCrystalSerial::setRow(uint8_t row)
{
	setCursor(0, row);
}

// A faster version of clear and fast home() combined
// Since this is a common combination of calls, it saves code
// space to combine them into one.
void LiquidCrystalSerial::clearHomeCursor()
{
	clear();
	setCursor(0, 0);
}

void LiquidCrystalSerial::setAddress(uint8_t x, uint8_t y)
{
	_xcursor = x;
	_ycursor = y;
}

void LiquidCrystalSerial::setCursor(uint8_t col, uint8_t row)
{
  if ( row > 6 ) {
    row = 6-1;
  }  
  _xcursor = 2*col; _ycursor = 18*row;
}

//If col or row = -1, then the current position is retained
//useful for controlling x when y is already positions, especially
//within drawItem
void LiquidCrystalSerial::setCursorExt(int8_t col, int8_t row)
{
	setCursor((col == -1 ) ? _xcursor : (2*col), (row == -1 ) ? _ycursor : (18*row));
}

//write 8x16 char
inline void LiquidCrystalSerial::write(uint8_t value)
{
	uint8_t i,row;
	if(value >= 0x20)
	{
		value -= 0x1b;
	}
	if(_xcursor<32 && _ycursor<128)
	{
		for(i=0;i<16;i++)
		{
			LCD_WR_CMD(0x00+_xcursor); //列地址，每个地址管4列
			row=_ycursor+i;
			LCD_WR_CMD(0x70+(row>>4)); //行地址的高3位
			LCD_WR_CMD(0x60+(row&0x0f)); //行地址的低4位
			
			uint8_t m=pgm_read_byte(&Font8x16[value*16+i]);
			LCD_MONO_DATA(m);
		}
	}
	_xcursor += 2;
	if(_xcursor>31)
	{
		_xcursor=0;
		_ycursor += 18;
	}
}
// write hanzi16x16
void LiquidCrystalSerial::writeCH(uint8_t value)
{
	uint8_t i,j,row;
	if(_xcursor<32 && _ycursor<128)
	{
		for(i=0;i<16;i++)
		{
			LCD_WR_CMD(0x00+_xcursor); //列地址，每个地址管4列
			row=_ycursor+i;
			LCD_WR_CMD(0x70+(row>>4)); //行地址的高3位
			LCD_WR_CMD(0x60+(row&0x0f)); //行地址的低4位
			for(j=0;j<2;j++)
			{
				uint8_t m=pgm_read_byte(&Font16x16[value*32+2*i+j]);
				LCD_MONO_DATA(m);
			}
		}
	}
	_xcursor += 4;
	if(_xcursor>31)
	{
		_xcursor=0;
		_ycursor += 18;
	}
}

void LiquidCrystalSerial::writeCH_R(uint8_t value)
{
	uint8_t i,j,row;
	if(_xcursor<32 && _ycursor<128)
	{
		for(i=0;i<16;i++)
		{
			LCD_WR_CMD(0x00+_xcursor); //列地址，每个地址管4列
			row=_ycursor+i;
			LCD_WR_CMD(0x70+(row>>4)); //行地址的高3位
			LCD_WR_CMD(0x60+(row&0x0f)); //行地址的低4位
			for(j=0;j<2;j++)
			{
				uint8_t m=pgm_read_byte(&Font16x16[value*32+2*i+j]);
				LCD_MONO_DATA_R(m);
			}
		}
	}
	_xcursor += 4;
	if(_xcursor>31)
	{
		_xcursor=0;
		_ycursor += 18;
	}
}

//像素反转8x16
void LiquidCrystalSerial::writeInversion(uint8_t value)
{
	if(value >= 0x20)
	{
		value -= 0x1b;
	}
	uint8_t i,row;
	if(_xcursor<32 && _ycursor<128)
	{
		for(i=0;i<16;i++)
		{
			LCD_WR_CMD(0x00+_xcursor); //列地址，每个地址管4列
			row=_ycursor+i;
			LCD_WR_CMD(0x70+(row>>4)); //行地址的高3位
			LCD_WR_CMD(0x60+(row&0x0f)); //行地址的低4位
			
			uint8_t m=pgm_read_byte(&Font8x16[value*16+i]);
			LCD_MONO_DATA_R(m);
		}
	}
	_xcursor += 2;
	if(_xcursor>31)
	{
		_xcursor=0;
		_ycursor += 18;
	}
}

//write 16x32 num
void LiquidCrystalSerial::writeNum(uint8_t value)
{
	uint8_t i,j,row;
	if(_xcursor<32 && _ycursor<128)
	{
		for(i=0;i<32;i++)
		{
			LCD_WR_CMD(0x00+_xcursor); //列地址，每个地址管4列
			row=_ycursor+i;
			LCD_WR_CMD(0x70+(row>>4)); //行地址的高3位
			LCD_WR_CMD(0x60+(row&0x0f)); //行地址的低4位
			for(j=0;j<2;j++)
			{
				uint8_t m=pgm_read_byte(&Num16x32[value*64+2*i+j]);
				LCD_MONO_DATA(m);
			}
		}
	}
	_xcursor += 4;
	if(_xcursor>31)
	{
		_xcursor=0;
		_ycursor += 32;
	}
}

void LiquidCrystalSerial::writeProgressBar(bool value)
{
	uint8_t i,row;
	if(_xcursor<32 && _ycursor<128)
	{
		for(i=0;i<32;i++)
		{
			LCD_WR_CMD(0x00+_xcursor); //列地址，每个地址管4列
			row=_ycursor+i;
			LCD_WR_CMD(0x70+(row>>4)); //行地址的高3位
			LCD_WR_CMD(0x60+(row&0x0f)); //行地址的低4位
			if(i == 0 || i == 31)
			{
				LCD_WR_DATA(0xff);
			}
			else
			{
				if(value == true)
				{
					LCD_WR_DATA(0xff);
				}
				else
				{
					LCD_WR_DATA(0x00);
				}
			}
		}
	}
	_xcursor += 1;
	if(_xcursor>31)
	{
		_xcursor=0;
		_ycursor += 32;
	}
}

void LiquidCrystalSerial::writeLine(uint8_t length)
{
		LCD_WR_CMD(0x00+_xcursor); //列地址，每个地址管4列
		LCD_WR_CMD(0x70+(_ycursor>>4)); //行地址的高3位
		LCD_WR_CMD(0x60+(_ycursor&0x0f)); //行地址的低4位
		for(uint8_t i=0;i<length;i++)
		{
			LCD_WR_DATA(0xff);
		}
}

void LiquidCrystalSerial::writeBeans(uint8_t index)
{
		LCD_WR_CMD(0x00+index); //列地址，每个地址管4列
		LCD_WR_CMD(0x70+(_ycursor>>4)); //行地址的高3位
		LCD_WR_CMD(0x60+(_ycursor&0x0f)); //行地址的低4位
		for(uint8_t i = index; i<32; i++)
		{
			LCD_WR_DATA(0x3c);
		}
}

void LiquidCrystalSerial::writeNumInt(uint16_t value, uint8_t digits) {

    uint32_t currentDigit, nextDigit, uvalue;

    switch (digits) {
    case 1:  currentDigit = 10;	     break;
    case 2:  currentDigit = 100;     break;
    case 3:  currentDigit = 1000;    break;
    case 4:  currentDigit = 10000;   break;
    case 5:  currentDigit = 100000;  break;
    default: return;
    }

    uvalue = (uint32_t)value;
    for (uint8_t i = 0; i < digits; i++) {
	nextDigit = currentDigit / 10;
	writeNum((uvalue % currentDigit) / nextDigit );
	currentDigit = nextDigit;
    }
}

void LiquidCrystalSerial::writeInt(uint16_t value, uint8_t digits) {

    uint32_t currentDigit, nextDigit, uvalue;

    switch (digits) {
    case 1:  currentDigit = 10;	     break;
    case 2:  currentDigit = 100;     break;
    case 3:  currentDigit = 1000;    break;
    case 4:  currentDigit = 10000;   break;
    case 5:  currentDigit = 100000;  break;
    default: return;
    }

    uvalue = (uint32_t)value;
    for (uint8_t i = 0; i < digits; i++) {
	nextDigit = currentDigit / 10;
	write((uvalue % currentDigit) / nextDigit + '0');
	currentDigit = nextDigit;
    }
}

void LiquidCrystalSerial::writeInt32(uint32_t value, uint8_t digits) {

	uint32_t currentDigit;
	uint32_t nextDigit;

	switch (digits) {
	case 1:		currentDigit = 10;			break;
	case 2:		currentDigit = 100;			break;
	case 3:		currentDigit = 1000;		break;
	case 4:		currentDigit = 10000;		break;
	case 5:		currentDigit = 100000;		break;
	case 6:		currentDigit = 1000000;		break;
	case 7:		currentDigit = 10000000;	break;
	case 8:		currentDigit = 100000000;	break;
	case 9:		currentDigit = 1000000000;	break;
	default: 	return;
	}

	for (uint8_t i = 0; i < digits; i++) {
		nextDigit = currentDigit/10;
		write((value%currentDigit)/nextDigit+'0');
		currentDigit = nextDigit;
	}
}

//From: http://www.arduino.cc/playground/Code/PrintFloats
//tim [at] growdown [dot] com   Ammended to write a float to lcd
//If rightJusityToCol = 0, the number is left justified, i.e. printed from the
//current cursor position.  If it's non-zero, it's right justified to end at rightJustifyToCol column.

#define MAX_FLOAT_STR_LEN 20

void LiquidCrystalSerial::writeFloat(float value, uint8_t decimalPlaces, uint8_t rightJustifyToCol) {
        // this is used to cast digits
        int digit;
        float tens = 0.1;
        int tenscount = 0;
        int i;
        float tempfloat = value;
	uint8_t p = 0;
	char str[MAX_FLOAT_STR_LEN + 1];

        // make sure we round properly. this could use pow from <math.h>, but doesn't seem worth the import
        // if this rounding step isn't here, the value  54.321 prints as 54.3209

        // calculate rounding term d:   0.5/pow(10,decimalPlaces)
        float d = 0.5;
        if (value < 0) d *= -1.0;

        // divide by ten for each decimal place
        for (i = 0; i < decimalPlaces; i++) d/= 10.0;

        // this small addition, combined with truncation will round our values properly
        tempfloat +=  d;

        // first get value tens to be the large power of ten less than value
        // tenscount isn't necessary but it would be useful if you wanted to know after this how many chars the number will take

        if (value < 0)  tempfloat *= -1.0;
        while ((tens * 10.0) <= tempfloat) {
                tens *= 10.0;
                tenscount += 1;
        }

        // write out the negative if needed
        if (value < 0) str[p++] = '-';

        if (tenscount == 0) str[p++] = '0';

        for (i=0; i< tenscount; i++) {
                digit = (int) (tempfloat/tens);
                str[p++] = digit + '0';
                tempfloat = tempfloat - ((float)digit * tens);
                tens /= 10.0;
        }

        // if no decimalPlaces after decimal, stop now and return
        if (decimalPlaces > 0) {
		// otherwise, write the point and continue on
		str[p++] = '.';

		// now write out each decimal place by shifting digits one by one into the ones place and writing the truncated value
		for (i = 0; i < decimalPlaces; i++) {
			tempfloat *= 10.0;
			digit = (int) tempfloat;
			str[p++] = digit+'0';
			// once written, subtract off that digit
			tempfloat = tempfloat - (float) digit;
		}
	}

	str[p] = '\0';

	if ( rightJustifyToCol ) {
		setCursorExt(rightJustifyToCol - p, -1);
	}
	writeString(str);
}

char* LiquidCrystalSerial::writeLine(char* message) {
	char* letter = message;
	while (*letter != 0 && *letter != '\n') {
		//INTERFACE_RLED.setValue(true);
		write(*letter);
		letter++;
		
	}
	return letter;
}

void LiquidCrystalSerial::writeString(char message[]) {
	char* letter = message;
	while (*letter != 0) {
		write(*letter);
		letter++;
	}
}

void LiquidCrystalSerial::writeFromPgmspace(const prog_uchar message[]) {
	char letter;
	while ((letter = pgm_read_byte(message++))) {
		write(letter);
	}
}

void LiquidCrystalSerial::moveWriteFromPgmspace(uint8_t col, uint8_t row, const prog_uchar message[]) {
	char letter;
	setCursor(col, row);
	while ((letter = pgm_read_byte(message++))) {
		write(letter);
	}
}

void LiquidCrystalSerial::writeFromPgmspace_R(const prog_uchar message[]) {
	char letter;
	while ((letter = pgm_read_byte(message++))) {
		writeInversion(letter);
	}
}

void LiquidCrystalSerial::moveWriteFromPgmspace_R(uint8_t col, uint8_t row, const prog_uchar message[]) {
	char letter;
	setCursor(col, row);
	while ((letter = pgm_read_byte(message++))) {
		writeInversion(letter);
	}
}

void LiquidCrystalSerial::writeFromPgmspaceCH(const prog_uchar message[]) {
	char letter;
	while ((letter = pgm_read_byte(message++))) {
		writeCH(letter);
	}
}

void LiquidCrystalSerial::moveWriteFromPgmspaceCH(uint8_t col, uint8_t row, const prog_uchar message[]) {
	char letter;
	setCursor(col, row);
	while ((letter = pgm_read_byte(message++))) {
		writeCH(letter);
	}
}

void LiquidCrystalSerial::writeFromPgmspaceCH_R(const prog_uchar message[]) {
	char letter;
	while ((letter = pgm_read_byte(message++))) {
		writeCH_R(letter);
	}
}

void LiquidCrystalSerial::moveWriteFromPgmspaceCH_R(uint8_t col, uint8_t row, const prog_uchar message[]) {
	char letter;
	setCursor(col, row);
	while ((letter = pgm_read_byte(message++))) {
		writeCH_R(letter);
	}
}

/*显示点阵的图像*/
void LiquidCrystalSerial::disp_128x128(const prog_uchar dp[])
{
	uint8_t i,j,y=0,x=0,row;
	for(i=0;i<128;i++)
	{
		LCD_WR_CMD(0x00+x); //列地址，每个地址管4列
		row=y+i;
		LCD_WR_CMD(0x70+(row>>4)); //行地址的高3位
		LCD_WR_CMD(0x60+(row&0x0f)); //行地址的低4位
		for(j=0;j<16;j++)
		{
			uint8_t m=pgm_read_byte(&dp[i*16+j]);
			LCD_MONO_DATA(m);
		}
	}
}

void LiquidCrystalSerial::disp_icon(uint8_t x, uint8_t y, uint8_t x_total, uint8_t y_total, const prog_uchar dp[])
{
	uint8_t i,j,row;
	for(i=0;i<y_total;i++)
	{
		LCD_WR_CMD(0x00+(x/4)); //列地址，每个地址管4列
		row=y+i;
		LCD_WR_CMD(0x70+(row>>4)); //行地址的高3位
		LCD_WR_CMD(0x60+(row&0x0f)); //行地址的低4位
		for(j=0;j<(x_total/8);j++)
		{
			uint8_t m=pgm_read_byte(&dp[i*(x_total/8)+j]);
			LCD_MONO_DATA(m);
		}
	}
}

void LiquidCrystalSerial::disp_icon_4(uint8_t x, uint8_t y, uint8_t x_total, uint8_t y_total, const prog_uchar dp[])
{
	uint8_t i,j,row;
	for(i=0;i<y_total;i++)
	{
		LCD_WR_CMD(0x00+(x/4)); //列地址，每个地址管4列
		row=y+i;
		LCD_WR_CMD(0x70+(row>>4)); //行地址的高3位
		LCD_WR_CMD(0x60+(row&0x0f)); //行地址的低4位
		for(j=0;j<(x_total/4);j++)
		{
			uint8_t m=pgm_read_byte(&dp[i*(x_total/4)+j]);
			LCD_WR_DATA(m);
		}
	}
}

void LiquidCrystalSerial::disp_icon_bg(uint8_t x, uint8_t y, uint8_t x_total, uint8_t y_total, const prog_uchar dp[])
{
	uint8_t i,j,row;
	for(i=0;i<y_total;i++)
	{
		LCD_WR_CMD(0x00+(x/4)); //列地址，每个地址管4列
		row=y+i;
		LCD_WR_CMD(0x70+(row>>4)); //行地址的高3位
		LCD_WR_CMD(0x60+(row&0x0f)); //行地址的低4位
		for(j=0;j<(x_total/8);j++)
		{
			uint8_t m=pgm_read_byte(&dp[i*(x_total/8)+j]);
			LCD_MONO_DATA_BG(m);
		}
	}
}

/*显示4灰度图像*/
void LiquidCrystalSerial::disp_pic(const prog_uchar dp[])
{
	uint8_t i,j,y=0,x=0,row;
	for(i=0;i<128;i++)
	{
		LCD_WR_CMD(0x00+x); //列地址，每个地址管4列
		row=y+i;
		LCD_WR_CMD(0x70+(row>>4)); //行地址的高3位
		LCD_WR_CMD(0x60+(row&0x0f)); //行地址的低4位
		for(j=0;j<32;j++)
		{
			uint8_t m=pgm_read_byte(&dp[i*32+j]);
			LCD_WR_DATA(m);
		}
	}
}

/************ low level data pushing commands **********/
void LiquidCrystalSerial::LCD_WR_CMD(uint8_t cmd)
{
	cs_pin.setValue(false);
	dc_pin.setValue(false);

	for (uint8_t c=0; c<8; c++)
	{
		sck_pin.setValue(false);
		if (cmd & 0x80)
			mosi_pin.setValue(true);
		else
			mosi_pin.setValue(false);
		sck_pin.setValue(true);
		cmd <<= 1;	
	}

	cs_pin.setValue(true);
}

void LiquidCrystalSerial::LCD_WR_DATA(uint8_t data)
{
	cs_pin.setValue(false);
	dc_pin.setValue(true);

	for (uint8_t c=0; c<8; c++)
	{
		sck_pin.setValue(false);
		if (data & 0x80)
			mosi_pin.setValue(true);
		else
			mosi_pin.setValue(false);
		sck_pin.setValue(true);
		data <<= 1;	
	}

	cs_pin.setValue(true);
}

void LiquidCrystalSerial::LCD_MONO_DATA(uint8_t mono_data)
{
	uint8_t i,j,four_gray_data=0;
	for(j=0;j<2;j++)
	{
		four_gray_data=0;
		for(i=0;i<4;i++)
		{
			four_gray_data>>=2; //4灰度级的数据右移2位
			if(mono_data&0x80) //单色黑白数据与0x80（二进制10000000）进行“与”运算
			{
			four_gray_data+=grayscale; //4灰度级的数据+0xc0(二进制11000000）/0x80(二进制10000000）/0x40(二进制01000000）/0x00(二进制00000000）
			}
			else;
			mono_data<<=1; //单色黑白数据左移一位
		}
		LCD_WR_DATA(four_gray_data); //写进一个8bits的数据，驱动了4个像素点，因为每个像素点用了2bits数据
	}
}

//像素反转
void LiquidCrystalSerial::LCD_MONO_DATA_R(uint8_t mono_data)
{
	uint8_t i,j,four_gray_data=0;
	for(j=0;j<2;j++)
	{
		four_gray_data=0;
		for(i=0;i<4;i++)
		{
			four_gray_data>>=2; //4灰度级的数据右移2位
			if(!(mono_data&0x80)) //单色黑白数据与0x80（二进制10000000）进行“与”运算
			{
			four_gray_data+=grayscale; //4灰度级的数据+0xc0(二进制11000000）/0x80(二进制10000000）/0x40(二进制01000000）/0x00(二进制00000000）
			}
			else;
			mono_data<<=1; //单色黑白数据左移一位
		}
		LCD_WR_DATA(four_gray_data); //写进一个8bits的数据，驱动了4个像素点，因为每个像素点用了2bits数据
	}
}

//有灰色背景
void LiquidCrystalSerial::LCD_MONO_DATA_BG(uint8_t mono_data)
{
	uint8_t i,j,four_gray_data=0;
	for(j=0;j<2;j++)
	{
		four_gray_data=0;
		for(i=0;i<4;i++)
		{
			four_gray_data>>=2; //4灰度级的数据右移2位
			if(mono_data&0x80) //单色黑白数据与0x80（二进制10000000）进行“与”运算
			{
			four_gray_data+=grayscale; //4灰度级的数据+0xc0(二进制11000000）/0x80(二进制10000000）/0x40(二进制01000000）/0x00(二进制00000000）
			}
			else
			{
			four_gray_data+=0x40;				
			}
			mono_data<<=1; //单色黑白数据左移一位
		}
		LCD_WR_DATA(four_gray_data); //写进一个8bits的数据，驱动了4个像素点，因为每个像素点用了2bits数据
	}
}