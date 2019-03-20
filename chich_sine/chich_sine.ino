int chichPin = 6;      // LED connected to digital pin 9
int analogPin = 3;   // potentiometer connected to analog pin 3
//int onOffPin = 2;
int val = 0;         // variable to store the read value
unsigned long time;
float freq = 261.63;

void setup() {
  pinMode(chichPin, OUTPUT);  // sets the pin as output
  //pinMode(onOffPin, INPUT)
  time = millis();
  Serial.begin(9600);
}

void loop() {
  //val = analogRead(analogPin);  // read the input pin
  //analogWrite(ledPin, val / 4); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  //analogWrite(chichPin, sin(2*3.14159265*millis()*freq/1000));
  analogWrite(chichPin, 128 + 128*sin((2*3.14159265*freq)*(millis()/1000)));
  val = analogRead(analogPin);  // read the input pin
  Serial.println(val*5/1023);
  
  //time = millis();
}
