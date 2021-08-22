//
// Created by aljoh on 4/11/2021.
//

#include <vector>
#include "SquareWave.h"

void SquareWave::waveOn(bool on) {
    for (auto &it : osc_) {
        it.waveOn(on);
    }
}

void SquareWave::sampleRate(int32_t sampleRate) {
    sampleRate_ = sampleRate;
    for (auto &it : osc_) {
        it.sampleRate(sampleRate);
    }
}

void SquareWave::render(float *const audioSink, int32_t numFrames) {
    std::vector<float> out(numFrames, 0);
    for (auto &it : osc_) {
        std::vector<float> out2(numFrames);
        it.render(out2.data(), numFrames);
        for (int i = 0; i < numFrames; i++) {
            out[i] = out[i] + out2[i];
        }
    }
    for (int i = 0; i < numFrames; i++) {
        audioSink[i] = out[i];
    }
}

void SquareWave::amplitude(double amplitude) {
    amplitude_ = amplitude;
    double harmonicAmplitude;
    double freq;
    int harmonicNumber = 1;
    osc_.clear();
    do {
        harmonicAmplitude = (amplitude_) / ((2.0 * harmonicNumber) - 1.0);
        freq = (((harmonicNumber * 2) - 1) * frequency_);
        osc_.emplace_back(harmonicAmplitude, freq, sampleRate_);
        harmonicNumber++;
    } while ((freq < (MAX_FREQUENCY)));
}

void SquareWave::frequency(double frequency) {
    frequency_ = frequency;
    double harmonicAmplitude;
    double freq;
    int harmonicNumber = 1;
    osc_.clear();
    do {
        harmonicAmplitude = (amplitude_) / ((2.0 * harmonicNumber) - 1.0);
        freq = (((harmonicNumber * 2) - 1) * frequency_);
        osc_.emplace_back(harmonicAmplitude, freq, sampleRate_);
        harmonicNumber++;
    } while ((freq < (MAX_FREQUENCY)));
}
