#ifndef FADE_h
#define FADE_h

#include <Arduino.h>

class FADE
{
private:
    byte _RED;
    byte _GRN;
    byte _BLU;

    int _BRIGHTNESS;
    int _BRIGHTNESS_;
    int _FADEAMOUNT;

public:
    FADE(byte R, byte G, byte B);
    void fade();
    // ~FADE();
};

#endif