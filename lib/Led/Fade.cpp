#include <Arduino.h>
#include <Fade.h>

FADE::FADE(byte R, byte G, byte B)
{
    _RED = R;
    _GRN = G;
    _BLU = B;

    _BRIGHTNESS = 0;    // how bright the LED is
    _BRIGHTNESS_ = 255;    // how bright the LED is
    _FADEAMOUNT = 5;    // how many points to fade the LED by

    pinMode(_RED, OUTPUT);
    pinMode(_GRN, OUTPUT);
    pinMode(_BLU, OUTPUT);
}

void FADE::fade()
{
    analogWrite(_RED, _BRIGHTNESS);
    analogWrite(_GRN, _BRIGHTNESS);
    analogWrite(_BLU, _BRIGHTNESS_);

    _BRIGHTNESS = _BRIGHTNESS + _FADEAMOUNT;
    _BRIGHTNESS_ = _BRIGHTNESS_ - _FADEAMOUNT;

    if (_BRIGHTNESS <= 0 || _BRIGHTNESS >= 255)
    {
        _FADEAMOUNT = -_FADEAMOUNT;
    }
    
}

// FADE::~FADE()
// {
// }