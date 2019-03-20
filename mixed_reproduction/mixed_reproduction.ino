//#include <CapacitiveSensor.h>

int val;
int multimeterPin = A3; // Analog pin

int chichPin = 9; // Digital PWM

const int maxKeys = 8;
int freqs[maxKeys];
int cycleLength = maxKeys*3; // TODO

bool toPress[maxKeys]; // array to know which keys should be now pressed
int beingPressed[maxKeys]; // array only with the currently sounding keys
int C = 0; int D = 1; int E = 2; int F = 3; int G = 4; int A = 5; int B = 6; int C4 = 7;
int keyPins[maxKeys];
int currentCState; // Measures how long the current keys have been sounding
int currentKey; // Currently sounding key
int totalPressedKeys;

void setup() {
  // Output pin
  pinMode(chichPin, OUTPUT);

  // Initialize frequencies
  freqs[C] = 262; freqs[D] = 294; freqs[E] = 330; freqs[F] = 350; freqs[G] = 392; freqs[A] = 440; freqs[B] = 494; freqs[C4] = 523;
  // Initializing the key pins
  keyPins[C] = 4; keyPins[D] = 5; keyPins[E] = 6; keyPins[F] = 7; keyPins[G] = 8; keyPins[A] = 10; keyPins[B] = 11; keyPins[C4] = 12;

  // Start saying no keys are being pressed
  currentCState = 0; // Current state in the cycle
  for (int key = 0; key < sizeof(toPress)/sizeof(*toPress); key++) toPress[key] = false; 

  // Key pins as input
  for (int key = 0; key < sizeof(toPress)/sizeof(*toPress); key++) pinMode(keyPins[key], INPUT);

  //Serial.begin(9600);

  //Serial.print("Tamanio keyPins (setup): "); Serial.println(sizeof(keyPins)/sizeof(*keyPins));
}

void loop() {
  if (currentCState % cycleLength == 0){
    currentCState = 0;

    // Determine the pressed keys
    for (int key = 0; key < sizeof(toPress)/sizeof(*toPress); key++) {
      toPress[key] = (digitalRead(keyPins[key]) == HIGH); //TODO remove the and part after all keys have been added
    }
    
    mandarSonido(true);
  }
  else {
    mandarSonido(false);
  }

  currentCState += 1;
  //Serial.println(currentCState);
}

void mandarSonido(bool cambio) {
  if (cambio) {
    // Instantiate beingPressed
    totalPressedKeys = 0;
    for (int key = 0; key < sizeof(toPress)/sizeof(*toPress); key++) {
      if (toPress[key]){
        totalPressedKeys += 1;
      }
    }
    //beingPressed = new int[maxKeys];
    //Serial.print("Se contaron las teclas presionadas: "); Serial.println(totalPressedKeys);
    //Serial.print("Tamanio beingPressed (metodo): ");Serial.println(sizeof(beingPressed)/sizeof(*beingPressed) - 1);
    
    // Create beingPressed with the keys that we were told were to be pressed
    int i = 0;
    for (int key = 0; key < sizeof(toPress)/sizeof(*toPress); key++) {
      if (toPress[key]){
        beingPressed[i] = key;
        i += 1;
        //Serial.print("PressedKey: ");Serial.println(key);
      }
    }
  }
  if (totalPressedKeys == 0) {
    noTone(chichPin);
    return;
  }
  // Make for this cycle the sound corresponding to the current key
  currentKey = beingPressed[(totalPressedKeys*currentCState) /cycleLength];
  //Serial.print("La tecla actual es: "); Serial.println(currentKey);
  tone(chichPin, freqs[currentKey]);
}
