int ledpin = 13;
volatile int state = LOW;

void setup()
{
  pinMode(pin, OUTPUT);
  attachInterrupt(0, blink, CHANGE); //pin 2
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(ledpin, state);
}

void blink()
{
  int a = digitalRead(3);
  int b = digitalRead(4);
  int c = digitalRead(5);
  int d = digitalRead(6);
  Serial.println(String(a) + " " + String(b) + " " + String(c) + " " + String(d) + " ");
  if (a+b+c+d>0){
    state = true;
  } else{
    state = false;
  }
}
