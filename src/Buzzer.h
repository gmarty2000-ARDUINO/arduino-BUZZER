#ifndef __LED_h
#define __LED_h

#include "Arduino.h"
#include "utility/Morse.h"
#include "utility/pitches.h"

class Buzzer {
    public:     Buzzer(int);
                Buzzer(int, int);
                void pauseBetweenNote(int);
                void sound(long, long);
                String toString();
    private:    int pinBuzzer;
                int pinLED;
                int pause;
};

#endif