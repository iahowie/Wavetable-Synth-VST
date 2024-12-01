#pragma once
#include "JuceHeader.h"
#include "WavetableOscillator.h"

class WavetableSynth
{
public:
	void prepareToPlay(double sampleRate);
	void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&);

private:
	void initializeOscillators();
	std::vector<float> generateSineWaveTable();
	void handleMidiEvent(const juce::MidiMessage& midiEvent);
	float midiNoteNumberToFrequency(int midiNoteNumber);
	void render(juce::AudioBuffer<float>& buffer, int startSample, int endSample);

	double sampleRate;
	std::vector<WavetableOscillator> oscillators;
};

