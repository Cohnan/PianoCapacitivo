#include <CapacitiveSensor.h>

int val;
int multimeterPin = 3;

int chichPin = 6;

int maxKeys = 8;
int[] freqs = new int[maxKeys];
int cycleLength = maxKeys*3;

bool[] toPress = new bool[maxKeys];
int C = 0; int D = 1; int E = 2; int F = 3; int G = 4; int A = 5; int B = 6; int C4 = 7;
int Cpin = 8; int Epin = 10;
int currentPState;
int[] beingPressed;

void setup() {
  // put your setup code here, to run once:
  pinMode(chichPin, OUTPUT);

  currentPState = 0; // Current state in the cycle
  for (int i = 0; i < toPress.length; i++) toPress[i] = false; // Start saying no keys are being pressed
  pinMode(Cpin, INPUT);
  pinMode(Epin, INPUT);

  // Initialize frequencies
  freqs[C] = 262; freqs[D] = 294; feqs[E] = 330; freqs[F] = 350; freqs[G] = 392; freqs[A] = 440; freqs[B] = 494; freqs[C3] = 523;
}

void loop() {
  if (currentCState % cycleLength == 0){
    currentCState = 0;

    // Determine the pressed keys
    toPress[C] = (digitalRead(Cpin) == HIGH);
    toPress[E] = (digitalRead(Epin) == HIGH);

    mandarSonido(true);
  }
  else {
    mandarSonido(false);
  }

  currentCState += 1;
}

void mandarSonido(bool cambio) {
  if (cambio){
    // TODO
    int totalSonidos = 0;
    for (int i = 0; i < toPress.length; i++){
      totalSonidos += 1;
    }
  } else {
    tone()
  }

  
  

  
}
