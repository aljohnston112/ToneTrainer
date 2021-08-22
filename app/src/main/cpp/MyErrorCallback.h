//
// Created by aljoh on 4/10/2021.
//

#ifndef TONETRAINER_MYERRORCALLBACK_H
#define TONETRAINER_MYERRORCALLBACK_H


#include <oboe/AudioStreamCallback.h>
#include <thread>

class MyErrorCallback: public oboe::AudioStreamErrorCallback {

public:
    MyErrorCallback(std::function<void(void)>* restartFunction){
        restartFunction_ = restartFunction;
    };

    bool onError(oboe::AudioStream* audioStream, oboe::Result result){
        if(result == oboe::Result::ErrorDisconnected) {
            new std::thread(*restartFunction_);
        }
        return true;
    };

private:
    MyErrorCallback();

    std::function<void(void)>* restartFunction_;
};


#endif //TONETRAINER_MYERRORCALLBACK_H
