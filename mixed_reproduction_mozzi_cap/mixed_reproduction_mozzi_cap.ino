#include <CapacitiveSensor.h>
#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <tables/sin2048_int8.h> // sine table for oscillator

//int val;
//int multimeterPin = 3; // Analog pin

//int chichPin = 9; // Digital PWM

const int maxKeys = 2;
int freqs[maxKeys];
int cycleLength = 5; // TODO

bool toPress[maxKeys]; // array to know which keys should be now pressed
int beingPressed[maxKeys]; // array only with the currently sounding keys
int C = 0; int D = 4; int E = 2; int F = 3; int G = 1; int A = 5; int B = 6; int C5 = 7;
int keyPins[maxKeys];
int currentCState; // Measures how long the current keys have been sounding
int currentKey; // Currently sounding key
int totalPressedKeys;

// For capacitive keys
long capValues[maxKeys];
int capLowThreshold = 20; // Si 2M 20
int capHigThreshold = 2900;
CapacitiveSensor capSensors[maxKeys] = {CapacitiveSensor(2,4), CapacitiveSensor(2,8)};//, CapacitiveSensor(2,8)};        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> oscilators[maxKeys] = {Oscil <SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA), Oscil <SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA)};//, Oscil <SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA), Oscil <SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA), Oscil <SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA), Oscil <SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA), Oscil <SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA), Oscil <SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA)};

// use #define for CONTROL_RATE, not a constant
#define CONTROL_RATE 256 // Hz, powers of 2 are most reliable

bool cambio;
int currentSound;

void setup() {
  Serial.begin(9600);
  startMozzi(CONTROL_RATE);
  
  // Output pin
  //pinMode(chichPin, OUTPUT);

  // Initialize frequencies
  freqs[C] = 262; freqs[D] = 294; freqs[E] = 330; freqs[F] = 350; freqs[G] = 392; freqs[A] = 440; freqs[B] = 494; freqs[C5] = 523;

  // Set oscillator frequencies
  for (int key = 0; key < sizeof(oscilators)/sizeof(*oscilators); key++) {
    oscilators[key].setFreq(freqs[key]);
  }
  Serial.print("Tamanio oscilators (setup): "); Serial.println(sizeof(oscilators)/sizeof(*oscilators));
  
  // Initializing the key pins
  keyPins[C] = 4; keyPins[D] = 5; keyPins[E] = 6; keyPins[F] = 7; keyPins[G] = 8; keyPins[A] = 10; keyPins[B] = 11; keyPins[C5] = 12;

  // Start saying no keys are being pressed
  currentCState = 0; // Current state in the cycle
  for (int key = 0; key < sizeof(toPress)/sizeof(*toPress); key++) toPress[key] = false; 

  // Key pins as input
  for (int key = 0; key < sizeof(toPress)/sizeof(*toPress); key++) pinMode(keyPins[key], INPUT);

  cambio = true;

  //Serial.print("Tamanio keyPins (setup): "); Serial.println(sizeof(keyPins)/sizeof(*keyPins));
}

void loop() {
  if (currentCState % cycleLength == 0){
    currentCState = 0;
    cambio = true;

    int capValue; // Result of measuring capcitance
    // Determine the pressed keys and update toPress
    for (int key = 0; key < sizeof(toPress)/sizeof(*toPress); key++) {
      capValue = capSensors[key].capacitiveSensor(1);
      Serial.print(" ");Serial.print(capValue);
      toPress[key] = (capLowThreshold < capValue) && (capValue < capHigThreshold);  // CHANGES DEPENDING ON THE SENSOR
    }
    Serial.println();
  } else {
    cambio = false;
  }
  currentCState += 1;
  //Serial.println(currentCState);
  
  audioHook(); // required here
}

void updateControl(){
  if (cambio) {
    // Prepare beingPressed with the correct size
    totalPressedKeys = 0;
    for (int key = 0; key < sizeof(toPress)/sizeof(*toPress); key++) {
      if (toPress[key]){
        totalPressedKeys += 1;
      }
    }

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
}

int updateAudio() { 
  if (totalPressedKeys == 0) {
    return 0;
  }

  // Update the current sound given the pressed keys
  currentSound = 0;
  for (int i = 0; i < totalPressedKeys; i++) {
    currentSound += oscilators[beingPressed[i]].next();
  }
  currentSound = currentSound/totalPressedKeys;
  return currentSound;
}
