//
// Created by aljoh on 4/5/2021.
//

#include "AudioEngine.h"
#include <oboe/Oboe.h>
#include <android/log.h>
#include <thread>
#include <mutex>

constexpr int32_t kBufferSizeInBursts = 2;

bool AudioEngine::start() {
    oboe::AudioStreamBuilder builder;
    builder.setDirection(oboe::Direction::Output);
    builder.setPerformanceMode(oboe::PerformanceMode::LowLatency);
    builder.setSharingMode(oboe::SharingMode::Exclusive);
    builder.setFormat(oboe::AudioFormat::Float);
    builder.setChannelCount(oboe::ChannelCount::Mono);
    builder.setDataCallback(&callback_);
    builder.setErrorCallback(&errorCallback_);
    oboe::Result result = builder.openStream(stream_);
    if (result != oboe::Result::OK) {
        __android_log_print(
                ANDROID_LOG_ERROR,
                "AudioEngine",
                "Failed to create stream. Error: %s",
                oboe::convertToText(result)
        );
        return false;
    }
    oscillator_.sampleRate(stream_->getSampleRate());
    stream_->setBufferSizeInFrames(stream_->getFramesPerBurst() * kBufferSizeInBursts);
    result = stream_->requestStart();
    if (result != oboe::Result::OK) {
        __android_log_print(
                ANDROID_LOG_ERROR,
                "AudioEngine",
                "Error starting stream %s",
                oboe::convertToText(result)
        );
        return false;
    }
    return true;
}

void AudioEngine::stop() {
    if (stream_ != nullptr) {
        stream_->requestStop();
        stream_->close();
    }
}

void AudioEngine::restart() {
    static std::mutex restartingLock;
    if (restartingLock.try_lock()) {
        stop();
        start();
        restartingLock.unlock();
    }

}

void AudioEngine::toneOn(bool on) {
    oscillator_.waveOn(on);
}

void AudioEngine::amplitude(double amplitude) {
    oscillator_.amplitude(amplitude);
}

void AudioEngine::frequency(double frequency) {
    oscillator_.frequency(frequency);
}
