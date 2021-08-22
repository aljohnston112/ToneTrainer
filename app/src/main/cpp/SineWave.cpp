//
// Created by aljoh on 4/5/2021.
//

#include "SineWave.h"
#include <cmath>
#include <android/log.h>

void SineWave::waveOn(bool on) {
    waveOn_.store(on);
}

void SineWave::sampleRate(int32_t sampleRate) {
    sampleRate_ = sampleRate;
    phaseInc_ = (TWO_PI * frequency_) / (double) sampleRate_;
}

void SineWave::render(float * const audioSink, int32_t numFrames) {
    for(int i = 0; i < numFrames; i++){
        if(waveOn_.load()){
            audioSink[i] = (float) (sin(phase_) * amplitude_);
            phase_ += phaseInc_;
            if(phase_ > TWO_PI){
                phase_ -= TWO_PI;
            }
        } else {
                audioSink[i] = 0;
        }
    }
}

void SineWave::amplitude(double amplitude) {
    amplitude_ = amplitude;
}

void SineWave::frequency(double frequency) {
    frequency_ = frequency;
    phaseInc_ = (TWO_PI * frequency_) / (double) sampleRate_;
}
