/*!
 * @file TinyLiquidCrystal.h
 */
#ifndef TinyLiquidCrystal_h
#define TinyLiquidCrystal_h

#include "Print.h"
#include "TinyAdafruit_MCP23008.h"
#include <inttypes.h>

// commands
#define LCD_CLEARDISPLAY 0x01 //!< Clear display, set cursor position to zero
#define LCD_RETURNHOME 0x02   //!< Set cursor position to zero
#define LCD_ENTRYMODESET 0x04 //!< Sets the entry mode
#define LCD_DISPLAYCONTROL                                                     \
  0x08 //!< Controls display; does stuff like turning it off and on
#define LCD_CURSORSHIFT 0x10 //!< Lets you move the cursor
#define LCD_FUNCTIONSET 0x20 //!< Used to send the function to set the display
#define LCD_SETCGRAMADDR                                                       \
  0x40 //!< Used to set the CGRAM (character generator RAM)
#define LCD_SETDDRAMADDR 0x80 //!< Used to set the DDRAM (display data RAM)

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00 //!< Used to set the text to flow from right to left
#define LCD_ENTRYLEFT 0x02  //!< Used to set text to flow from left to righ
#define LCD_ENTRYSHIFTINCREMENT                                                \
  0x01 //!< Used to 'right justify' text from the cursor
#define LCD_ENTRYSHIFTDECREMENT                                                \
  0x00 //!< Used to 'left justify' text from the cursor

// flags for display on/off control
#define LCD_DISPLAYON 0x04  //!< Turns the display on
#define LCD_DISPLAYOFF 0x00 //!< Turns the display off
#define LCD_CURSORON 0x02   //!< Turns the cursor on
#define LCD_CURSOROFF 0x00  //!< Turns the cursor off
#define LCD_BLINKON 0x01    //!< Turns on the blinking cursor
#define LCD_BLINKOFF 0x00   //!< Turns off the blinking cursor

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08 //!< Flag for moving the display
#define LCD_CURSORMOVE 0x00  //!< Flag for moving the cursor
#define LCD_MOVERIGHT 0x04   //!< Flag for moving right
#define LCD_MOVELEFT 0x00    //!< Flag for moving left

// flags for function set
#define LCD_8BITMODE 0x10 //!< LCD 8 bit mode
#define LCD_4BITMODE 0x00 //!< LCD 4 bit mode
#define LCD_2LINE 0x08    //!< LCD 2 line mode
#define LCD_1LINE 0x00    //!< LCD 1 line mode
#define LCD_5x10DOTS 0x04 //!< 10 pixel high font mode
#define LCD_5x8DOTS 0x00  //!< 8 pixel high font mode

/*!
 * @brief Main TinyLiquidCrystal class
 */
class TinyLiquidCrystal : public Print {
public:
  /*!
   * @brief TinyLiquidCrystal constructor for writing to a display
   * @param rs The reset data line
   * @param enable The enable data line
   * @param d0 The data line 0
   * @param d1 The data line 1
   * @param d2 The data line 2
   * @param d3 The data line 3
   * @param d4 The data line 4
   * @param d5 The data line 5
   * @param d6 The data line 6
   * @param d7 The data line 7
   */
  TinyLiquidCrystal(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1,
                    uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6,
                    uint8_t d7);
  /*!
   * @brief TinyLiquidCrystal constructor for writing to a display
   * @param rs The reset data line
   * @param rw The read-write data line. Determines whether to read from or
   * write to display. Not necessary if only writing  to display
   * @param enable The enable data line
   * @param d0 The data line 0
   * @param d1 The data line 1
   * @param d2 The data line 2
   * @param d3 The data line 3
   * @param d4 The data line 4
   * @param d5 The data line 5
   * @param d6 The data line 6
   * @param d7 The data line 7
   */
  TinyLiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t d0,
                    uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5,
                    uint8_t d6, uint8_t d7);
  /*!
   * @brief TinyLiquidCrystal constructor for writing to a display
   * @param rs The reset data line
   * @param rw The read-write data line. Determines whether to read from or
   * write to display. Not necessary if only writing  to display
   * @param enable The enable data line
   * @param d0 The data line 0
   * @param d1 The data line 1
   * @param d2 The data line 2
   * @param d3 The data line 3
   */
  TinyLiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t d0,
                    uint8_t d1, uint8_t d2, uint8_t d3);
  /*!
   * @brief TinyLiquidCrystal constructor for writing to a display
   * @param rs The reset data line
   * @param enable The enable data line
   * @param d0 The data line 0
   * @param d1 The data line 1
   * @param d2 The data line 2
   * @param d3 The data line 3
   */
  TinyLiquidCrystal(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1,
                    uint8_t d2, uint8_t d3);

  /*!
   * @brief TinyLiquidCrystal constructor for connection over i2c
   * @param i2cAddr I2C address of the display
   */
  TinyLiquidCrystal(uint8_t i2cAddr);
  /*!
   * @brief TinyLiquidCrystal constructor for connection over SPI
   * @param data Data pin
   * @param clock Clock pin
   * @param latch Latch pin
   */
  TinyLiquidCrystal(uint8_t data, uint8_t clock, uint8_t latch);

  /*!
   * @brief Initializes the display
   * @param fourbitmode Sets the mode of the display, either 4 bit or 8 bit
   * @param rs The reset data line
   * @param rw The read-write data line. Determines whether to read from or
   * write to display. Not necessary if only writing  to display
   * @param enable The enable data line
   * @param d0 The data line 0
   * @param d1 The data line 1
   * @param d2 The data line 2
   * @param d3 The data line 3
   * @param d4 The data line 4
   * @param d5 The data line 5
   * @param d6 The data line 6
   * @param d7 The data line 7
   */
  void init(uint8_t fourbitmode, uint8_t rs, uint8_t rw, uint8_t enable,
            uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4,
            uint8_t d5, uint8_t d6, uint8_t d7);

  /*!
   * @brief Stats connectoin with display
   * @param cols Sets the number of columns
   * @param rows Sets the number of rows
   * @param charsize Sets the character size
   * @return Returns true when connection was successful
   */
  void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);

  /*!
   * @brief High-level command to clear the display
   */
  void clear();
  /*!
   * @brief High-level command to set the cursor position to zero
   */
  void home();
  /*!
   * @brief High-level command to turn the display off quickly
   */
  void noDisplay();
  /*!
   * @brief High-level command to turn the display on quickly
   */
  void display();
  /*!
   * @brief High-level command to turn the blinking cursor off
   */
  void noBlink();
  /*!
   * @brief High-level command to turn the blinking cursor on
   */
  void blink();
  /*!
   * @brief High-level command to turn the underline cursor off
   */
  void noCursor();
  /*!
   * @brief High-level command to turn the underline cursor on
   */
  void cursor();
  /*!
   * @brief High-level command to scroll display left without changing the RAM
   */
  void scrollDisplayLeft();
  /*!
   * @brief High-level command to scroll display right without changing the RAM
   */
  void scrollDisplayRight();
  /*!
   * @brief High-level command to make text flow left to right
   */
  void leftToRight();
  /*!
   * @brief High-level command to make text flow right to left
   */
  void rightToLeft();
  /*!
   * @brief High-level command to 'right justify' text from the cursor
   */
  void autoscroll();
  /*!
   * @brief High-level command to 'left justify' text from the cursor
   */
  void noAutoscroll();

  /*!
   * @brief High-level command to set the backlight, only if the LCD backpack is
   * used
   * @param status Status to set the backlight
   */
  void setBacklight(uint8_t status);

  /*!
   * @brief High-level command that creates custom character in CGRAM
   * @param location Location in cgram to fill
   * @param charmap[] Character map
   */
  void createChar(uint8_t, uint8_t[]);
  /*!
   * @brief High-level command that sets the location of the cursor
   * @param col Column to set the cursor in
   * @param row Row to set the cursor in
   */
  void setCursor(uint8_t, uint8_t);
#if ARDUINO >= 100
  virtual size_t write(uint8_t);
#else
  /*!
   * @brief Mid-level command that sends data to the display
   * @param value Data to send to the display
   */
  virtual void write(uint8_t);
#endif
  /*!
   * @brief Sends command to display
   * @param value command to send
   */
  void command(uint8_t);

private:
  void send(uint8_t, uint8_t);
  void write4bits(uint8_t);
  void write8bits(uint8_t);
  void pulseEnable();
  void _digitalWrite(uint8_t, uint8_t);
  void _pinMode(uint8_t, uint8_t);

  uint8_t _rs_pin;     // LOW: command.  HIGH: character.
  uint8_t _rw_pin;     // LOW: write to LCD.  HIGH: read from LCD.
  uint8_t _enable_pin; // activated by a HIGH pulse.
  uint8_t _data_pins[8];

  uint8_t _displayfunction;
  uint8_t _displaycontrol;
  uint8_t _displaymode;

  uint8_t _initialized;

  uint8_t _numlines, _currline;

  uint8_t _SPIclock, _SPIdata, _SPIlatch;
  uint8_t _SPIbuff;

  uint8_t _i2cAddr;
  Adafruit_MCP23008 _i2c;
};

#endif
