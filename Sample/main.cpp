#include "Adafruit_TLC5947.h"

#define NUM_TLC5974 	     1
#define LED_CNT              8
#define PIN_SCK              11
#define PIN_MOSI             10
#define PIN_LATCH            5
#define PIN_BLANK            26

int main()
{
    // Setup wiringPi
    wiringPiSetupGpio();

    // Init for TLC5947
    Adafruit_TLC5947 tlc(NUM_TLC5974, PIN_SCK, PIN_MOSI, PIN_LATCH);
	pinMode(PIN_BLANK, OUTPUT);
    digitalWrite(PIN_BLANK, LOW);
    tlc.begin();

    while(true)
	{
		for (int i = 0; i < LED_CNT; i++)
		{
			tlc.setLED(i, 50, 0, 0);
		}
		tlc.write();
		delay(500);
		for (int i = 0; i < LED_CNT; i++)
		{
			tlc.setLED(i, 0, 50, 0);
		}
		tlc.write();
		delay(500);
		for (int i = 0; i < LED_CNT; i++)
		{
			tlc.setLED(i, 0, 0, 50);
		}
		tlc.write();
		delay(500);
        for (int i = 0; i < LED_CNT; i++)
		{
			tlc.setLED(i, 0, 0, 0);
		}
		tlc.write();
		delay(500);
	}
	return 1;
}