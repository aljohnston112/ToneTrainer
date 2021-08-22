//
// Created by aljoh on 4/5/2021.
//

#ifndef TONETRAINER_AUDIOENGINE_H
#define TONETRAINER_AUDIOENGINE_H

#include "SineWave.h"
#include "MyCallback.h"
#include "MyErrorCallback.h"
#include "SquareWave.h"

class AudioEngine {
public:
    bool start();
    void stop();
    void restart();
    void toneOn(bool on);
    void amplitude(double amplitude);
    void frequency(double frequency);

private:
    SquareWave oscillator_{};
    MyCallback callback_{&oscillator_};
    std::function<void(void)> restartFunction = std::bind(&AudioEngine::restart, this);
    MyErrorCallback errorCallback_{&restartFunction};
    std::shared_ptr<oboe::AudioStream> stream_;
};


#endif //TONETRAINER_AUDIOENGINE_H
