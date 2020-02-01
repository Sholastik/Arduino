/*
Vyacheslav Ivanov, 01.02.2020
Remote servo
*/

#include <Servo.h>
#include <IRremote.h>
const int receiverPin = 7;
const int servoPin = 8;

int angle = 90;
int delta = 5;
bool toLeft = true;
bool playing = false;

IRrecv ir(receiverPin);
decode_results result;
Servo servo;

inline const void decode(unsigned long code)
{
    if (code == NEXT)
    {
        toLeft = true;
    }
    else if (code == PREV)
    {
        toLeft = false;
    }
    else if (code == PLAY)
    {
        playing = !playing;
    }
}

void setup()
{
    ir.enableIRIn();
    ir.blink13(true);
    servo.attach(servoPin);
    servo.write(angle);
    Serial.begin(9600);
}

void loop()
{
    if (ir.decode(&result))
    {
        decode(result.value);
        ir.resume();
    }
    if (playing)
    {
        if (toLeft)
        {
            if (angle == 0)
                toLeft = false;
            else
                angle -= delta;
        }
        else
        {
            if (angle == 180)
                toLeft = true;
            else
                angle += delta;
        }
        servo.write(angle);
        delay(10);
    }
}
