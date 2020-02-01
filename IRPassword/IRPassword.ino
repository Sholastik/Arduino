/*
Vyacheslav Ivanov, 01.02.2020
IR password
Connect IR signal pin to receiverPin
*/

#include <IRremote.h>
#include <string.h>

const int receiverPin = 7;
const String PASSWORD = "1020+-+#";

int pos = 0;
bool unlocked = false, correct = true;

IRrecv ir(receiverPin);
decode_results result;

inline const char getChar(const unsigned long code)
{
  switch (code)
  {
  case CHMINUS:
    return '_';
  case CH:
    return '#';
  case CHPLUS:
    return '=';
  case ZERO:
    return '0';
  case ONE:
    return '1';
  case TWO:
    return '2';
  case THREE:
    return '3';
  case FOUR:
    return '4';
  case FIVE:
    return '5';
  case SIX:
    return '6';
  case SEVEN:
    return '7';
  case EIGHT:
    return '8';
  case NINE:
    return '9';
  case NEXT:
    return '>';
  case PREV:
    return '<';
  case PLAY:
    return '@';
  case EQ:
    return 'E';
  case PLUS:
    return '+';
  case MINUS:
    return '-';
  case ONE_HUNDRED:
    return 'A';
  case TWO_HUNDRED:
    return 'B';
  default:
    return 0;
  }
}

inline const void checkPassword(const unsigned long code)
{
  if (code == EQ)
  {
    pos = 0;
    correct = true;
  }
  else if (getChar(code) == PASSWORD[pos])
  {
    if (correct)
    {
      pos++;
      if (pos == PASSWORD.length())
        unlocked = true;
    }
  }
  else
    correct = false;
}

inline const void mainDecode(const unsigned long value) {

}

inline const void decode(const unsigned long value)
{
  if (!unlocked)
  {
    checkPassword(value);
  }
  if (unlocked)
  {
    mainDecode(value);
  }
}

void setup()
{
  ir.enableIRIn();
  ir.blink13(true);
}

void loop()
{
  if (ir.decode(&result))
  {
    decode(result.value);
    delay(200);
    ir.resume();
  }
}
