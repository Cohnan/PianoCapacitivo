//#include <CapacitiveSensor.h>
#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <tables/sin2048_int8.h> // sine table for oscillator

//int val;
//int multimeterPin = A0; // Analog pin para multimetro

// OUTPUT DE MOZZI EN PIN 9

const int maxKeys = 4; // SE PUEDE MODIFICAR SIN PROBLEMA
int freqs[maxKeys];
int cycleLength = 50; // TODO

bool toPress[maxKeys]; // array to know which keys should be now pressed
int beingPressed[maxKeys]; // array only with the currently sounding keys
int C = 0; int D = 1; int E = 2; int F = 3; int G = 4; int A = 5; int B = 6; int C5 = 7;
int pinOf[maxKeys];
int currentCState; // Measures how long the current keys have been sounding
int currentKey; // Currently sounding key
int totalPressedKeys;

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> oscilators[maxKeys] = {Oscil <SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA), 
                                                             Oscil <SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA), 
                                                             Oscil <SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA), 
                                                             Oscil <SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA)//, 
                                                             //Oscil <SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA), 
                                                             //Oscil <SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA), 
                                                             //Oscil <SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA), 
                                                             //Oscil <SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA)
                                                             };

// use #define for CONTROL_RATE, not a constant
#define CONTROL_RATE 256 // Hz, powers of 2 are most reliable

bool cambio;
int currentSound;

void setup() {
  //Serial.begin(9600); // Para tests
  startMozzi(CONTROL_RATE);
  
  // Initialize frequencies and oscillators
  freqs[C] = 262; freqs[D] = 294; freqs[E] = 330; freqs[F] = 350; freqs[G] = 392; freqs[A] = 440; freqs[B] = 494; freqs[C5] = 523;
  //freqs[C] = 50; freqs[D] = 0.5; freqs[E] = 1; freqs[F] = 2; freqs[G] = 392; freqs[A] = 440; freqs[B] = 494; freqs[C5] = 523;
  
  for (int key = 0; key < sizeof(oscilators)/sizeof(*oscilators); key++) {
    oscilators[key].setFreq(freqs[key]);
  }
  //Serial.print("Tamanio oscilators (setup): "); Serial.println(sizeof(oscilators)/sizeof(*oscilators));
  
  // Initializing the key pins
  pinOf[C] = A3; pinOf[D] = A2; pinOf[E] = A1; pinOf[F] = A0; pinOf[G] = 8; pinOf[A] = 10; pinOf[B] = 11; pinOf[C5] = 12;

  // Key pins as input
  //for (int key = 0; key < sizeof(toPress)/sizeof(*toPress); key++) pinMode(pinOf[key], INPUT);
  
  // Start saying no keys are being pressed
  currentCState = 0; // Current state in the cycle
  for (int key = 0; key < sizeof(toPress)/sizeof(*toPress); key++) toPress[key] = false; 

  cambio = true;

  //Serial.print("Tamanio pinOf (setup): "); Serial.println(sizeof(pinOf)/sizeof(*pinOf));
}

void updateControl(){
  if (cambio) {
    // Find out how many keys are being pressed
    totalPressedKeys = 0;
    for (int key = 0; key < sizeof(toPress)/sizeof(*toPress); key++) {
      if (toPress[key]){
        totalPressedKeys += 1;
      }
    }
    
    ////Serial.print("Se contaron las teclas presionadas: "); Serial.println(totalPressedKeys);
    ////Serial.print("Tamanio beingPressed (metodo): ");Serial.println(sizeof(beingPressed)/sizeof(*beingPressed) - 1);
    
    // Make first totalPressedKeys entries of beingPressed to be the (code of the) pressed keys
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

void loop() {
  if (currentCState % cycleLength == 0){
    currentCState = 0;
    cambio = true;

    // Determine the pressed keys and update toPress
    for (int key = 0; key < sizeof(toPress)/sizeof(*toPress); key++) { //maxKeys
      toPress[key] = (analogRead(pinOf[key]) > 20); 
    }
  } else {
    cambio = false;
  }
  currentCState += 1;
  ////Serial.println(currentCState);
  
  audioHook(); // required here
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
  //Serial.println(analogRead(multimeterPin));
  return currentSound;
}
