#ifndef __MaximilianPatch_hpp__
#define __MaximilianPatch_hpp__

#include "StompBox.h"

namespace maxi {

#include "maximilian_examples/5.FM1.cpp"
  
}

class MaximilianPatch : public Patch {
private:
public:
  MaximilianPatch(){
    maxi::setup();
  }
  void processAudio(AudioBuffer &buffer) {
    float* left = buffer.getSamples(LEFT_CHANNEL);
    float* right = buffer.getSamples(RIGHT_CHANNEL);
    double pair[2];
    for(int i=0; i<buffer.getSize(); ++i){
      pair[0] = left[i];
      pair[1] = right[i];
      maxi::play(pair);
    }
  }
};

#endif   // __MaximilianPatch_hpp__
