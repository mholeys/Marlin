/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/****************************************************************************************
* Teensy 3.5 (MK64FX512) and Teensy 3.6 (MK66FX1M0) Breadboard pin assignments
* Requires the Teensyduino software with Teensy 3.5 or Teensy 3.6 selected in Arduino IDE!
* http://www.pjrc.com/teensy/teensyduino.html
****************************************************************************************/

#if !IS_32BIT_TEENSY
  #error "Oops!  Make sure you have 'Teensy 3.5' or 'Teensy 3.6' selected from the 'Tools -> Boards' menu."
#endif

#if IS_TEENSY35
  #define BOARD_NAME "TEENSY 35 MH"
#elif IS_TEENSY36
  #define BOARD_NAME "TEENSY 36 MH"
#endif

#define AT90USB 1286   // Disable MarlinSerial etc.
#define USBCON //1286  // Disable MarlinSerial etc.
/*

  teemuatlut plan for Teensy3.5 and Teensy3.6:
                                                     USB
                                          GND |-----#####-----| VIN 5V
      X_STEP_PIN          MOSI1   RX1       0 |     #####     | Analog GND
      X_DIR_PIN           MISO1   TX1       1 |               | 3.3V
      X_ENABLE_PIN                     PWM  2 | *NC     AREF* | 23  A9 PWM                    X_MIN
      X_CHIP_SELECT       SCL2 CAN0TX  PWM  3 | *A26     A10* | 22  A8 PWM                    X_MAX  SERVO0_PIN
      Y_STEP_PIN          SDA2 CAN0RX  PWM  4 | *A25     A11* | 21  A7 PWM  CS0   MOSI1  RX1  Y_MIN
      Y_DIR_PIN           MISO1   TX1  PWM  5 | *GND * * 57   | 20  A6 PWM  CS0   SCK1        Y_MAX  SERVO1_PIN
      Y_ENABLE_PIN                     PWM  6 | *GND * * 56   | 19  A5            SCL0        Z_MIN
      Y_CHIP_SELECT SCL0  MOSI0   RX3  PWM  7 |      * * 55   | 18  A4            SDA0        Z_MAX  SERVO2_PIN
      Z_STEP_PIN    SDA0  MISO0   TX3  PWM  8 |      * * 54   | 17  A3 PWM        SDA0        HEATER_0_PIN
      Z_DIR_PIN           CS0     RX2  PWM  9 |               | 16  A2 PWM        SCL0        HEATER_BED_PIN
      Z_ENABLE_PIN        CS0     TX2  PWM 10 |               | 15  A1      CS0               LED_PIN
      M-OUT-SPI           MOSI0            11 |               | 14  A0 PWM  CS0               HEATER_1_PIN
      M-IN-SPI            MISO0            12 |               | 13 LED            SCK0        SPI_CLOCK0
                                         3.3V |               | GND
      Z_CHIP_SELECT                        24 |   40 * * 53   |    A22 DAC1                   TEMP_BED_PIN
      E0_STEP_PIN                          25 |   41 * * 52   |    A21 DAC0                   TEMP_0_PIN
      E0_DIR_PIN          SCL2    TX1      26 |   42 * * 51   | 39 A20      MISO0             TEMP_1_PIN
      E0_ENABLE_PIN       SCK0    RX1      27 | *  *  *  *  * | 38 A19 PWM        SDA1        FAN_1
      E0_CHIP_SELECT      MOSI0            28 |   43 * * 50   | 37 A18 PWM        SCL1        FAN_2
      E1_STEP_PIN         CAN0TX       PWM 29 |   44 * * 49   | 36 A17 PWM                    FAN_3
      E1_DIR_PIN          CAN0RX       PWM 30 |   45 * * 48   | 35 A16 PWM                    FIL_WIDTH_PIN
      E1_ENABLE_PIN       CS1     RX4  A12 31 |   46 * * 47   | 34 A15 PWM        SDA0  RX5   FIL_RUNOUT_PIN
      E1_CHIP_SELECT      SCK1    TX4  A13 32 |__GND_*_*_3.3V_| 33 A14 PWM        SCL0  TX5   Z_PROBE

          Interior pins:
                                                       * 57               NC
                                                       * 56               NC
                                                       * 55               NC
                                                       * 54               NC
                          LCD_PINS_RS             40 * * 53   SCK2        NC
                          LCD_PINS_ENABLE         41 * * 52   MOSI2       E_MUX2
                          LCD_PINS_D4             42 * * 51   MISO2       E_MUX1
                          LCD_PINS_D5     CS2     43 * * 50   A24         E_MUX0
                          LCD_PINS_D6     MOSI2   44 * * 49   A23         ADC_KEYPAD_PIN
                          LCD_PINS_D7     MISO2   45 * * 48   TX6   SDA0  BTN_ENC
                          BTN_EN1         SCK2    46 * * 47   RX6   SCL0  BTN_EN2
                                                 GND * * 3.3V

*/

//
// Limit Switches
//
#define X_MIN_PIN         23
#define X_MAX_PIN         22
#define Y_MIN_PIN         21
#define Y_MAX_PIN         20
#define Z_MIN_PIN         19
#define Z_MAX_PIN         18

//
// Steppers
//
#define X_STEP_PIN         0
#define X_DIR_PIN          1
#define X_ENABLE_PIN       2
#ifndef X_CS_PIN
  #define X_CS_PIN 3
#endif


#define Y_STEP_PIN         4
#define Y_DIR_PIN          5
#define Y_ENABLE_PIN       6
#ifndef Y_CS_PIN
  #define Y_CS_PIN 7
#endif

#define Z_STEP_PIN         8
#define Z_DIR_PIN          9
#define Z_ENABLE_PIN       10
#ifndef Z_CS_PIN
  #define Z_CS_PIN 24
#endif

#define E0_STEP_PIN        25
#define E0_DIR_PIN         26
#define E0_ENABLE_PIN      27
#ifndef E0_CS_PIN
  #define E0_CS_PIN 28
#endif

#define E1_STEP_PIN        29
#define E1_DIR_PIN         30
#define E1_ENABLE_PIN      31
#ifndef E1_CS_PIN
  #define E1_CS_PIN 32
#endif

#define HEATER_0_PIN       17
#define HEATER_1_PIN       14
#define HEATER_BED_PIN     16
#ifndef FAN_PIN
  #define FAN_PIN           2
#endif

#define TEMP_0_PIN          66   // Extruder 0 / Analog pin numbering: 66 => A21 / DAC1
#define TEMP_1_PIN          39   // Extruder 1 / Analog pin numbering: 39 => A20
#define TEMP_BED_PIN        67   // Bed  / Analog pin numbering: 67 => A22 / DAC0

#define LED_PIN             15

#define FILWIDTH_PIN        35
#define FIL_RUNOUT_PIN      34



#if 0
// Pretty sure this is obsolete!
// Please use Marlin 1.1.x pins files as reference for new pins files.
#ifndef SDSUPPORT
  // these are defined in the SD library if building with SD support
  #define SCK_PIN          13
  #define MISO_PIN         12
  #define MOSI_PIN         11
#endif
#endif

#if ENABLED(ULTRA_LCD)
  #define LCD_PINS_RS      40
  #define LCD_PINS_ENABLE  41
  #define LCD_PINS_D4      42
  #define LCD_PINS_D5      43
  #define LCD_PINS_D6      44
  #define LCD_PINS_D7      45
  #define BTN_EN1          46
  #define BTN_EN2          47
  #define BTN_ENC          48
  #define ADC_KEYPAD_PIN   49 // Analog pin numbering: 49 => A23
#endif

#if ENABLED(MK2_MULTIPLEXER)
  #define E_MUX0_PIN 50
  #define E_MUX1_PIN 51
  #define E_MUX2_PIN 52
#endif