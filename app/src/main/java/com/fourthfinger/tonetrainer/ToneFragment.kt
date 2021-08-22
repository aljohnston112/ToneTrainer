package com.fourthfinger.tonetrainer

import android.annotation.SuppressLint
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Toast
import androidx.core.view.doOnPreDraw
import androidx.databinding.DataBindingUtil
import androidx.fragment.app.Fragment
import androidx.fragment.app.viewModels
import com.fourthfinger.tonetrainer.databinding.ToneFragmentBinding

class ToneFragment: Fragment() {

    @ExperimentalStdlibApi
    private val toneViewModel: ToneViewModel by viewModels()

    private lateinit var binding: ToneFragmentBinding

    private lateinit var currentTone: String;

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        startEngine()
    }

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {
        binding = DataBindingUtil.inflate(
            inflater,
            R.layout.tone_fragment,
            container,
            false
        )
        setUpButtons()
        return binding.root
    }

    @ExperimentalStdlibApi
    @SuppressLint("ClickableViewAccessibility")
    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        binding.toneFragment = this
        binding.lifecycleOwner = viewLifecycleOwner
        binding.toneViewModel = toneViewModel
        toneViewModel.frequency.observe(viewLifecycleOwner){
            frequency(it)
        }
        toneViewModel.tone.observe(viewLifecycleOwner){
            currentTone = it
        }
        binding.play.setOnTouchListener { _, event ->
            event?.action?.let { touchEvent(it) }
            binding.play.onTouchEvent(event)
        }
    }

    private fun setUpButtons() {
        binding.aSharp.doOnPreDraw {
            val dimen = binding.aSharp.measuredWidth
            val lp = it.layoutParams
            lp.height = dimen
            lp.width = dimen
            it.layoutParams = lp
            binding.a.doOnPreDraw {
                val lp = it.layoutParams
                lp.height = dimen
                lp.width = dimen
                it.layoutParams = lp
            }
            binding.b.doOnPreDraw {
                val lp = it.layoutParams
                lp.height = dimen
                lp.width = dimen
                it.layoutParams = lp
            }
            binding.c.doOnPreDraw {
                val lp = it.layoutParams
                lp.height = dimen
                lp.width = dimen
                it.layoutParams = lp
            }
            binding.cSharp.doOnPreDraw {
                val lp = it.layoutParams
                lp.height = dimen
                lp.width = dimen
                it.layoutParams = lp
            }
            binding.d.doOnPreDraw {
                val lp = it.layoutParams
                lp.height = dimen
                lp.width = dimen
                it.layoutParams = lp
            }
            binding.dSharp.doOnPreDraw {
                val lp = it.layoutParams
                lp.height = dimen
                lp.width = dimen
                it.layoutParams = lp
            }
            binding.e.doOnPreDraw {
                val lp = it.layoutParams
                lp.height = dimen
                lp.width = dimen
                it.layoutParams = lp
            }
            binding.f.doOnPreDraw {
                val lp = it.layoutParams
                lp.height = dimen
                lp.width = dimen
                it.layoutParams = lp
            }
            binding.fSharp.doOnPreDraw {
                val lp = it.layoutParams
                lp.height = dimen
                lp.width = dimen
                it.layoutParams = lp
            }
            binding.g.doOnPreDraw {
                val lp = it.layoutParams
                lp.height = dimen
                lp.width = dimen
                it.layoutParams = lp
            }
            binding.gSharp.doOnPreDraw {
                val lp = it.layoutParams
                lp.height = dimen
                lp.width = dimen
                it.layoutParams = lp
            }
        }

    }

    @ExperimentalStdlibApi
    fun checkTone(tone: String){
        if(currentTone.equals(tone, true)) {
            toneViewModel.incrementNoteCount()
        } else {
            val duration = Toast.LENGTH_LONG
            val toast = Toast.makeText(requireContext(), requireContext().getText(R.string.try_again), duration)
            toast.show()
        }
    }

    override fun onDestroy() {
        super.onDestroy()
        stopEngine()
    }

    private external fun touchEvent(action: Int)
    private external fun startEngine()
    private external fun stopEngine()
    private external fun amplitude(amplitude: Double)
    private external fun frequency(frequency: Double)

}