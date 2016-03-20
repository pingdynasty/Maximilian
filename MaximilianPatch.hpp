#ifndef __MaximilianPatch_hpp__
#define __MaximilianPatch_hpp__

#include "StompBox.h"

#include "maximilian.h"

class MaximilianPatch : public Patch {
private:
//This shows how to use maximilian to do basic amplitude modulation. Amplitude modulation is when you multiply waves together. In maximilian you just use the * inbetween the two waveforms.

maxiOsc mySine,myOtherSine;//Two oscillators. They can be called anything. They can be any of the available waveforms. These ones will be sinewaves

void setup() {//some inits
    //nothing to go here this time
}

void play(double *output) {
    
    // This form of amplitude modulation is straightforward multiplication of two waveforms.
    // Notice that the maths is different to when you add waves.
    // The waves aren't 'beating'. Instead, the amplitude of one is modulating the amplitude of the other
    // Remember that the sine wave has positive and negative sections as it oscillates.
    // When you multiply something by -1, its phase is inverted but it retains its amplitude.
    // So you hear 2 waves per second, not 1, even though the frequency is 1.
    output[0]=mySine.sinewave(440)*myOtherSine.sinewave(1);
    output[1]=output[0];

}

public:
  MaximilianPatch(){
    setup();
  }
  void processAudio(AudioBuffer &buffer) {
    float* left = buffer.getSamples(LEFT_CHANNEL);
    float* right = buffer.getSamples(RIGHT_CHANNEL);
    double output[2];
    for(int i=0; i<buffer.getSize(); ++i){
      play(output);
      left[i] = output[0];
      right[i] = output[1];
    }
  }
};

#endif   // __MaximilianPatch_hpp__
