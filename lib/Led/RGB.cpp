#include <Arduino.h>
#include <RGB.h>

RGB::RGB(byte R, byte G, byte B)
{
    _RED = R;
    _GRN = G;
    _BLU = B;

    pinMode(_RED, OUTPUT);
    pinMode(_GRN, OUTPUT);
    pinMode(_BLU, OUTPUT);

    digitalWrite(_RED, false);
    digitalWrite(_GRN, false);
    digitalWrite(_BLU, false);

    randomSeed(analogRead(3));
}

void RGB::randomRGB()
{
    int redValue = random(2);
    int grnValue = random(2);
    int bluValue = random(2);

    digitalWrite(_RED, redValue);
    digitalWrite(_GRN, grnValue);
    digitalWrite(_BLU, bluValue);
}

// RGB::~RGB()
// {
// }