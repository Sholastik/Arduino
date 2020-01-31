# 1 "c:\\Users\\Sholastik\\Development\\Arduino\\Code.ino"
const int ledPin = 13;

inline void setup() {
    pinMode(ledPin, 0x1);
}

inline void loop() {
    digitalWrite(13, 0x1);
    delay(100);
    digitalWrite(13, 0x0);
    delay(100);
}
