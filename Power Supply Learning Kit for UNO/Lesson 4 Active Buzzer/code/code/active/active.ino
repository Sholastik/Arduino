#define buzzer 13

int wait = 1000;

void setup()
{
 pinMode(buzzer, OUTPUT);
}

void loop(){
 if (wait > 0) {
    makeSound(50, wait);
     if (wait <= 100) {
        wait -= 4;
     }
     else {
        wait -= 50;
     }
  }
}

void makeSound(int sound_time, int wait_time) {
  digitalWrite(buzzer, HIGH);
  delay(sound_time);
  digitalWrite(buzzer, LOW);
  delay(wait_time);
}
