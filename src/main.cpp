/*

Demonstrates simple TX operation with an ATtiny85.  Note in this example the same pin is used for CE and CSN.
This slows the communication between the microcontroller and radio, but it frees up one pin.

Any of the Basic_RX examples can be used as a receiver.

Radio		ATtiny85
CE		|	RD	-> Physical Pin 2, Arduino 3         
CSN		|	OR	-> Physical Pin 2, Arduino 3         
MISO	|	BL	-> Physical Pin 5, Arduino 0 (Hardware USI_DI)  
MOSI	|	GR	-> Physical Pin 6, Arduino 1 (Hardware USI_DO)  
SCK		|	YL	-> Physical Pin 7, Arduino 2 (Hardware USI_SCK) 
IRQ		|		-> No connection
VCC		|		-> No more than 3.6 volts
GND		|		-> GND

*/

#include <NRFLite.h>

const static uint8_t RADIO_ID = 4;
const static uint8_t DESTINATION_RADIO_ID = 0;
const static uint8_t PIN_RADIO_CE = 3;
const static uint8_t PIN_RADIO_CSN = 3;
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

	if (!_radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN))
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

	if (!_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData)))
	{
		_radioData.FailedTxCount++;
	}

	digitalWrite(PIN_LED, HIGH); // turn the LED on by making the voltage HIGH
	delay(1000);
	digitalWrite(PIN_LED, LOW); // turn the LED off by making the voltage LOW
	delay(1000);
}