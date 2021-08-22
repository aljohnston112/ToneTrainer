//
// Created by aljoh on 4/10/2021.
//

#ifndef TONETRAINER_MYCALLBACK_H
#define TONETRAINER_MYCALLBACK_H


#include "SineWave.h"
#include <oboe/Oboe.h>

class MyCallback: public oboe::AudioStreamDataCallback  {

public:

    MyCallback(Oscillator* oscillator){
        oscillator_ = oscillator;
    };

    oboe::DataCallbackResult onAudioReady(
            oboe::AudioStream *audioStream,
            void *audioData,
            int32_t numFrames
    ) {
        auto *outputData = static_cast<float *>(audioData);
        oscillator_->render(static_cast<float *>(audioData), numFrames);
        return oboe::DataCallbackResult::Continue;
    }

private:
    MyCallback();
    Oscillator* oscillator_;

};


#endif //TONETRAINER_MYCALLBACK_H
