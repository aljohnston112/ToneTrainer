//
// Created by aljoh on 4/11/2021.
//

#ifndef TONETRAINER_SQUAREWAVE_H
#define TONETRAINER_SQUAREWAVE_H

#include <list>
#include "SineWave.h"

class SquareWave: public Oscillator {

public:
    void waveOn(bool on);

    void sampleRate(int32_t sampleRate);

    void render(float *const audioSink, int32_t numFrames);

    void amplitude(double amplitude);

    void frequency(double frequency);

private:
    constexpr static double MAX_FREQUENCY = 20000;
    std::list<SineWave> osc_;

    double amplitude_ = 0.3;
    double frequency_ = 440;
    int32_t sampleRate_;
};


#endif //TONETRAINER_SQUAREWAVE_H
