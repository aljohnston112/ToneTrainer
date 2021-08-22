#include <jni.h>
#include <android/input.h>
#include "AudioEngine.h"

static AudioEngine *audioEngine = new AudioEngine();

extern "C" {

JNIEXPORT void JNICALL
Java_com_fourthfinger_tonetrainer_ToneFragment_touchEvent(JNIEnv *env, jobject obj, jint action) {
    switch (action) {
        case AMOTION_EVENT_ACTION_DOWN:
            audioEngine->toneOn(true);
            break;
        case AMOTION_EVENT_ACTION_UP:
            audioEngine->toneOn(false);
            break;
        default:
            break;
    }
}

JNIEXPORT void JNICALL
Java_com_fourthfinger_tonetrainer_ToneFragment_startEngine(JNIEnv *env, jobject /* this */) {
    audioEngine->start();
}

JNIEXPORT void JNICALL
Java_com_fourthfinger_tonetrainer_ToneFragment_stopEngine(JNIEnv *env, jobject /* this */) {
    audioEngine->stop();
}

JNIEXPORT void JNICALL
Java_com_fourthfinger_tonetrainer_ToneFragment_frequency(JNIEnv *env, jobject obj, jdouble frequency) {
    audioEngine->frequency(frequency);
}

JNIEXPORT void JNICALL
Java_com_fourthfinger_tonetrainer_ToneFragment_amplitude(JNIEnv *env, jobject obj, jdouble amplitude) {
    audioEngine->amplitude(amplitude);
}

}