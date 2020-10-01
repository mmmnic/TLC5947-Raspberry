/*!
 *  @file Adafruit_TLC5947.cpp
 *
 *  @mainpage Adafruit 24-channel PWM/LED driver
 *
 *  @section intro_sec Introduction
 *
 * 	Driver for Microchip's TLC5947
 *
 * 	This is a library for the Adafruit TLC5947
 * 	http://www.adafruit.com/products/
 *
 * 	Adafruit invests time and resources providing this open source code,
 *  please support Adafruit and open-source hardware by purchasing products from
 * 	Adafruit!
 *
 *  @section author Author
 *
 *  Limor Fried/Ladyada (Adafruit Industries).
 *	
 *	Update for Raspberry: Quoc Hoang Anh
 */
 
#ifndef _ADAFRUIT_TLC5947_H
#define _ADAFRUIT_TLC5947_H

#include <wiringPi.h>
#include <stdint.h>
#include <cstring>
#include <cstdlib>

/*!
 *    @brief  Class that stores state and functions for interacting with
 *            TLC5947 24-channel PWM/LED driver
 */
class Adafruit_TLC5947 {
public:
  Adafruit_TLC5947(uint16_t n, uint8_t c, uint8_t d, uint8_t l);

  bool begin(void);
  void setPWM(uint16_t chan, uint16_t pwm);
  void setLED(uint16_t lednum, uint16_t r, uint16_t g, uint16_t b);
  void write();

private:
  uint16_t *pwmbuffer;
  uint16_t numdrivers;
  uint8_t _clk, _dat, _lat;
};

#endif
