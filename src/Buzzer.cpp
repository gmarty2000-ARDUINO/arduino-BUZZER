#include "Buzzer.h"

/* ------------------------------ CONSTRUCTOR CODE ------------------------------ */

/* Constructor - It saves the pin number of the Buzzer and sets it in OUTPUT mode */
Buzzer::Buzzer(int pinBuzzer) {
    this->pinBuzzer = pinBuzzer;
    this->pinLED = -1;

    pinMode(pinBuzzer, OUTPUT);
}

/* Constructor - It saves the pin number of the Buzzer and the LED and set them in OUTPUT mode */
Buzzer::Buzzer(int pinBuzzer, int pinLED) {
    this->pinBuzzer = pinBuzzer;
    this->pinLED = pinLED;

    pinMode(pinBuzzer, OUTPUT);
    pinMode(pinLED, OUTPUT);
}

/* ------------------------------ SIMPLE APIs ------------------------------ */

/* Method - It sets the pause before the note (in percentage) */
void Buzzer::pauseBetweenNote(int pause) {
    this->pause = pause;
}

/* Method - It makes the Buzzer sound */
void Buzzer::sound(long frequency, long duration) {
    long timeBreak = 1000000 / frequency / 2;
    long numCycles = frequency * duration / 1000;

    if (this->pinLED != -1)
        digitalWrite(this->pinLED, HIGH);

    for (long i = 0; i < numCycles; i++) {
        digitalWrite(this->pinBuzzer, HIGH);
        delayMicroseconds(timeBreak);
        digitalWrite(this->pinBuzzer, LOW);
        delayMicroseconds(timeBreak);
    }

    if (this->pinLED != -1)
        digitalWrite(this->pinLED, LOW);
    
    delay(((duration * this->pause) / 100));
}

/* Method - It returns the Buzzer informations */
String Buzzer::toString() {
    String ret = String("Buzzer: {");
    ret.concat("pinBuzzer=");
    ret.concat(this->pinBuzzer);
    ret.concat(", pinLED=");
    ret.concat(this->pinLED);
    ret.concat("}");
    
    return ret;
}
