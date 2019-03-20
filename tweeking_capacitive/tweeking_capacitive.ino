#include <CapacitiveSensor.h>

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
int chichPin = 3; // Digital PWM


void setup() {
  pinMode(chichPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  long total1 =  cs_4_2.capacitiveSensor(80);
  long total2 =  cs_4_6.capacitiveSensor(80);

   Serial.print(total1);                  // print sensor output 1
   Serial.print("\t");
   Serial.println(total2);

   delay(100);
}
