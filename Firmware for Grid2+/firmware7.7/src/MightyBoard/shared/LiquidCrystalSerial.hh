#ifndef LIQUID_CRYSTAL_HH
#define LIQUID_CRYSTAL_HH

// TODO: Proper attribution

#include <stdint.h>
#include <avr/pgmspace.h>
#include "Pin.hh"


#define LCD_CUSTOM_CHAR_DOWN                    0

#define LCD_CUSTOM_CHAR_FOLDER                  2 // Must not be 0
#define LCD_CUSTOM_CHAR_RETURN                  3 // Must not be 0

#define LCD_CUSTOM_CHAR_DEGREE		     0x7f  // MAY ALSO BE 0xdf
#define LCD_CUSTOM_CHAR_UP                   0x5e // ^
#define LCD_CUSTOM_CHAR_RIGHT                1 // right pointing arrow (0x7f is left pointing)

// TODO:  make variable names for rs, rw, e places in the output vector

class LiquidCrystalSerial {
public:
  LiquidCrystalSerial(Pin SCK, Pin MOSI, Pin DC, Pin RST, Pin CS);

  void begin();

  void clear();

  void setGrayscale(uint8_t scale);
  void homeCursor(); // faster version of home()
  void clearHomeCursor();  // clear() and homeCursor() combined

  void setAddress(uint8_t, uint8_t);  
  void setCursor(uint8_t, uint8_t); 
  void setRow(uint8_t); 
  void setCursorExt(int8_t col, int8_t row);

  virtual void write(uint8_t);
  void writeCH(uint8_t);
  void writeCH_R(uint8_t);
  void writeInversion(uint8_t);

  void writeNum(uint8_t);
  void writeProgressBar(bool);
  void writeLine(uint8_t);
  void clearLine(uint8_t length);
  void writeBeans(uint8_t);
  void writeBeans(uint8_t first, uint8_t last);
  void clearBeans(uint8_t first, uint8_t last);
  
  /** Added by MakerBot Industries to support storing strings in flash **/
  void writeNumInt(uint16_t value, uint8_t digits);
  void writeInt(uint16_t value, uint8_t digits);
  void writeInt32(uint32_t value, uint8_t digits);
  void writeFloat(float value, uint8_t decimalPlaces, uint8_t rightJustifyToCol);

  void writeString(char message[]);

  /** Display the given line until a newline or null is encountered.
   * Returns a pointer to the first character not displayed.
   */
  char* writeLine(char* message);
  char* writeLineCH(char* message);

  void writeFromPgmspace(const prog_uchar message[]);
  void moveWriteFromPgmspace(uint8_t col, uint8_t row, const prog_uchar message[]);
  void writeFromPgmspace_R(const prog_uchar message[]);
  void moveWriteFromPgmspace_R(uint8_t col, uint8_t row, const prog_uchar message[]);  
  void writeFromPgmspaceCH(const prog_uchar message[]);
  void moveWriteFromPgmspaceCH(uint8_t col, uint8_t row, const prog_uchar message[]);
  void writeFromPgmspaceCH_R(const prog_uchar message[]);
  void moveWriteFromPgmspaceCH_R(uint8_t col, uint8_t row, const prog_uchar message[]); 
  void disp_128x128(const prog_uchar dp[]);
  void disp_pic(const prog_uchar dp[]);
  void disp_icon(uint8_t x, uint8_t y, uint8_t x_total, uint8_t y_total, const prog_uchar dp[]);
  void disp_icon_4(uint8_t x, uint8_t y, uint8_t x_total, uint8_t y_total, const prog_uchar dp[]);
  void disp_icon_bg(uint8_t x, uint8_t y, uint8_t x_total, uint8_t y_total, const prog_uchar dp[]);

private:

 		void LCD_WR_CMD(uint8_t cmd);
		void LCD_WR_DATA(uint8_t data);
		void LCD_WR_BASE(uint8_t data);
		void LCD_MONO_DATA(uint8_t mono_data);
		void LCD_MONO_DATA_BASE(uint8_t mono_data);
		void LCD_MONO_DATA_R(uint8_t mono_data);
		void LCD_MONO_DATA_R_BASE(uint8_t mono_data);
		void LCD_MONO_DATA_BG(uint8_t mono_data);
		void LCD_MONO_DATA_BG_BASE(uint8_t mono_data);
		
		Pin sck_pin;
		Pin mosi_pin;
		Pin dc_pin;
		Pin rst_pin;
		Pin cs_pin;
		
  uint8_t _xcursor;
  uint8_t _ycursor;
  uint8_t grayscale;

};

#endif // LIQUID_CRYSTAL_HH
