const int ledPin = LED_BUILTIN;

inline void setup() {
    pinMode(ledPin, OUTPUT);
}

inline void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);   
}