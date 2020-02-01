const int xPin = A1;
const int yPin = A0;
const int buttonPin = 2;

int xPosition = 0;
int yPosition = 0;
bool buttonPressed = false;

void setup() {
    Serial.begin(9600);
    pinMode(xPin, INPUT);
    pinMode(yPin, INPUT);
    pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
    xPosition = analogRead(xPin);
    yPosition = analogRead(yPin);
    buttonPressed = digitalRead(buttonPin);

    Serial.print("x: ");
    Serial.print(xPosition);
    Serial.print(" y: ");
    Serial.print(yPosition);
    Serial.print(" button is ");
    Serial.print(buttonPressed? "not " : "");
    Serial.println("pressed");

    delay(1000);
}