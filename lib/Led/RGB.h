#ifndef RGB_h
#define RGB_h

#include <Arduino.h>

class RGB
{
private:
    byte _RED;
    byte _GRN;
    byte _BLU;

public:
    RGB(byte R, byte G, byte B);
    void randomRGB();
    // ~RGB();
};

#endif