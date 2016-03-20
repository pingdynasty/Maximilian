#ifndef __MaximilianPatch_hpp__
#define __MaximilianPatch_hpp__

#include "StompBox.h"

#include "maximilian.h"

class MaximilianPatch : public Patch {
private:
#include "14.monosynth.cpp"

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
