/*  Example playing a sinewave at a set frequency,
    using Mozzi sonification library.

    Demonstrates the use of Oscil to play a wavetable.

    Circuit: Audio output on digital pin 9 on a Uno or similar, or
    DAC/A14 on Teensy 3.1, or
    check the README or http://sensorium.github.com/Mozzi/

    Mozzi documentation/API
		https://sensorium.github.io/Mozzi/doc/html/index.html

		Mozzi help/discussion/announcements:
    https://groups.google.com/forum/#!forum/mozzi-users

    Tim Barrass 2012, CC by-nc-sa.
*/

#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <tables/sin2048_int8.h> // sine table for oscillator

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> ESin(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> GSin(SIN2048_DATA);

// use #define for CONTROL_RATE, not a constant
#define CONTROL_RATE 64 // Hz, powers of 2 are most reliable


void setup(){
  startMozzi(CONTROL_RATE); // :)
  ESin.setFreq(330); // set the frequency
  GSin.setFreq(392);
}


void updateControl(){
  // put changing controls in here
}


int updateAudio(){
  return (0*ESin.next()+0*GSin.next())/2; // return an int signal centred around 0
}


void loop(){
  audioHook(); // required here
}
