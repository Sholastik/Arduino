#include <Arduino.h>
#line 1 "c:\\Users\\Sholastik\\Development\\Arduino\\Code.ino"
const int ledPin = LED_BUILTIN;

#line 3 "c:\\Users\\Sholastik\\Development\\Arduino\\Code.ino"
void setup();
#line 7 "c:\\Users\\Sholastik\\Development\\Arduino\\Code.ino"
void loop();
#line 3 "c:\\Users\\Sholastik\\Development\\Arduino\\Code.ino"
inline void setup() {
    pinMode(ledPin, OUTPUT);
}

inline void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);   
}
