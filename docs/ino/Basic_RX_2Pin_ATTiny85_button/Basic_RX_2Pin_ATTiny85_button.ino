/*

Demonstrates simple RX and TX operation using 2 pins for the radio.
Any of the Basic_TX examples can be used as a transmitter.
Only AVR architectures (ATtiny/ATmega) support 2 pin operation.

Radio circuit
* Follow the 2-Pin Hookup Guide on https://github.com/dparson55/NRFLite

Connections
Radio		Arduino
MOMI	|	GR	->	1
SCK		|	YL	->	2
VCC		|		->	No more than 3.6 volts
GND

*/

#include <NRFLite.h>

const static uint8_t RADIO_ID = 0;
const static uint8_t PIN_RADIO_MOMI = 1;
const static uint8_t PIN_RADIO_SCK = 2;
const static uint8_t PIN_LED = 4;

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

	if (!_radio.initTwoPin(RADIO_ID, PIN_RADIO_MOMI, PIN_RADIO_SCK)) // Note usage of 'initTwoPin' rather than 'init'.
	{
		digitalWrite(PIN_LED, HIGH);
		while (1)
			; // Wait here forever.
	}
}

void loop()
{
	while (_radio.hasData())
	{
		_radio.readData(&_radioData);

		String msg = "Radio ";
		msg += _radioData.FromRadioId;
		msg += ", ";
		msg += _radioData.OnTimeMillis;
		msg += " ms, ";
		msg += _radioData.FailedTxCount;
		msg += " Failed TX";

		digitalWrite(PIN_LED, HIGH); // turn the LED on by making the voltage HIGH
		delay(1000);
		digitalWrite(PIN_LED, LOW); // turn the LED off by making the voltage LOW
	}
}
