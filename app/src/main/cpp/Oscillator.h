//
// Created by aljoh on 4/11/2021.
//

#ifndef TONETRAINER_OSCILLATOR_H
#define TONETRAINER_OSCILLATOR_H


#include <cstdint>

class Oscillator {

public:
    virtual void waveOn(bool on) = 0;
    virtual void sampleRate(int32_t sampleRate) = 0;
    virtual void render(float * const audioSink, int32_t numFrames) = 0;
    virtual void amplitude(double amplitude) = 0;
    virtual void frequency(double frequency) = 0;

};


#endif //TONETRAINER_OSCILLATOR_H
