#include <Arduino.h>
#include "../lib/Led/RGB.h"
#include "../lib/Led/FADE.h"

byte red = 0;
byte grn = 1;
byte blu = 4;

// RGB rgb(red, grn, blu);
FADE fade(red, grn, blu);

void setup()
{
}

void loop()
{
	// rgb.randomRGB();
	// delay(500);

	fade.fade();
	delay(20);
}