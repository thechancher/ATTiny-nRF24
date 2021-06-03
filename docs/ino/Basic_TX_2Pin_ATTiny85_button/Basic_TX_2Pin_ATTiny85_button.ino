/*

Demonstrates simple RX and TX operation using 2 pins for the radio.  This greatly slows down the communication speed between
the microcontroller and radio compared to using the SPI and USI peripherials of the ATmega and ATtiny microcontrollers.
Only AVR architectures (ATMega/ATtiny) support 2 pin operation.

Any of the Basic_RX examples can be used as a receiver.

Radio circuit
* Follow the 2-Pin Hookup Guide on https://github.com/dparson55/NRFLite

Connections
Radio		Arduino
MOMI	|	GR	->	1
SCK		|	YL	->	2
VCC		|		->	No more than 3.6 volts
GND		|		->	GND

*/

#include <NRFLite.h>

const static uint8_t RADIO_ID = 2;
const static uint8_t DESTINATION_RADIO_ID = 0;
const static uint8_t PIN_RADIO_MOMI = 1;
const static uint8_t PIN_RADIO_SCK = 2;
const static uint8_t PIN_LED = 4;
const static uint8_t PIN_BUTTON = 3;
bool status;

struct RadioPacket
{
	uint8_t FromRadioId;
	uint32_t OnTimeMillis;
	uint32_t FailedTxCount;
};

NRFLite _radio;
RadioPacket _radioData;

void setup()
{
	pinMode(PIN_LED, OUTPUT);
	pinMode(PIN_BUTTON, INPUT);

	if (!_radio.initTwoPin(RADIO_ID, PIN_RADIO_MOMI, PIN_RADIO_SCK)) // Note usage of 'initTwoPin' rather than 'init'.
	{
		digitalWrite(PIN_LED, HIGH);
		while (1)
			; // Cannot communicate with radio.
	}

	_radioData.FromRadioId = RADIO_ID;
}

void loop()
{
	_radioData.OnTimeMillis = millis();

	status = digitalRead(PIN_BUTTON);

	if (status)
	{
		if (!_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData)))
		{
			_radioData.FailedTxCount++;
		}

		digitalWrite(PIN_LED, HIGH); // turn the LED on by making the voltage HIGH
		delay(1000);
		digitalWrite(PIN_LED, LOW); // turn the LED off by making the voltage LOW
	}

}