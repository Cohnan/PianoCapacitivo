int chichPin = 6;
unsigned int freq;
int freqC = 262;
int freqD = 294;
int freqE = 330;
int freqF = 350;
int freqG = 392;
int freqA = 440;
int freqB = 494;
int freqC5 = 523;
int val;

int tempo = 60;
int retraso;
int analogPin = 3;

void setup() {
  // put your setup code here, to run once:
  freq = freqA;
  pinMode(chichPin, OUTPUT);
  retraso = 60000/tempo;
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(chichPin, freqC);
  delay(9/10*retraso);
  noTone(chichPin);
  delay(1/10*retraso);
  tone(chichPin, freqC);
  delay(retraso/2);
  tone(chichPin, freqD);
  delay(retraso/2);
  tone(chichPin, freqC);
  delay(retraso);
  tone(chichPin, freqF);
  delay(retraso);
  tone(chichPin, freqE);
  delay(retraso);
  tone(chichPin, freqC);
  delay(9/10*retraso);
  noTone(chichPin);
  delay(1/10*retraso);
  tone(chichPin, freqC);
  delay(retraso/2);
  tone(chichPin, freqD);
  delay(retraso/2);
  tone(chichPin, freqC);
  delay(retraso);
  tone(chichPin, freqG);
  delay(retraso);
  tone(chichPin, freqF);
  delay(retraso);
  
  val = analogRead(analogPin);  // read the input pin
  Serial.println(val*5/1023);

  
}
