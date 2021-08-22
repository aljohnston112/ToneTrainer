package com.fourthfinger.tonetrainer

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.map
import kotlin.math.pow


private const val MIDDLE_A = 440.0
private const val NOTES_PER_OCTAVE = 12
// There is a corresponding MAX_FREQUENCY
private const val MAX_FREQUENCY = 4187.0
private val TONES = listOf("a", "a#", "b", "c", "c#", "d", "d#", "e", "f", "f#","g", "g#" ,)

@ExperimentalStdlibApi
class ToneViewModel: ViewModel() {

    // The frequency 2 octaves under middle A
    private val bottomFrequency: Double = MIDDLE_A / 2.0.pow(2.0)

    // The scale for calculating note frequencies
    private val multiplier = StrictMath.pow(2.0, 1.0 / NOTES_PER_OCTAVE)

    @ExperimentalStdlibApi
    val tones = buildMap<Double, String> {
        var hertz = bottomFrequency
        var i = 0
        while (hertz < MAX_FREQUENCY) {
            hertz = bottomFrequency * StrictMath.pow(multiplier, i.toDouble())
            this[hertz] = TONES[i% TONES.size]
            i++
        }
    }

    @ExperimentalStdlibApi
    private val _frequency = MutableLiveData(tones.keys.random())
    @ExperimentalStdlibApi
    val frequency: LiveData<Double> get() = _frequency

    val tone: LiveData<String> get() = frequency.map {
        tones[it]!!
    }

    private val _currentNoteCount = MutableLiveData(0)
    val currentNoteCount: LiveData<Int> get() = _currentNoteCount
    fun incrementNoteCount(){
        _currentNoteCount.value = _currentNoteCount.value?.plus(1)
        _frequency.value = tones.keys.random()
    }

}