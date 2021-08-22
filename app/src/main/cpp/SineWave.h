//
// Created by aljoh on 4/5/2021.
//

#ifndef TONETRAINER_SINEWAVE_H
#define TONETRAINER_SINEWAVE_H

#include <atomic>
#include <stdint.h>
#include "Oscillator.h"

#define TWO_PI (3.14159 * 2)

class SineWave: public Oscillator {
public:
    SineWave(double amplitude, double frequency, int32_t sampleRate){
        amplitude_ = amplitude;
        frequency_ = frequency;
        sampleRate_ = sampleRate;
        phaseInc_ = (TWO_PI * frequency_) / (double) sampleRate_;
    };
    SineWave(const SineWave &osc){
        amplitude_ = (osc.amplitude_);
        frequency_ = (osc.frequency_);
    };
    void waveOn(bool on);
    void sampleRate(int32_t sampleRate);
    void render(float * const audioSink, int32_t numFrames);
    void amplitude(double amplitude);
    void frequency(double frequency);

private:
    std::atomic<bool> waveOn_{false};
    double amplitude_ = 0.3;
    double frequency_ = 440;
    int32_t sampleRate_;
    double phase_ = 0.0;
    double phaseInc_ = 0.0;

};


#endif //TONETRAINER_SINEWAVE_H
