/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SC_1AudioProcessorEditor::SC_1AudioProcessorEditor (SC_1AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 50);
    addAndMakeVisible(gainSlider);
    
    gainSliderAttachement = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "GAIN", gainSlider);
    
    
    
    setSize (400, 300);
}

SC_1AudioProcessorEditor::~SC_1AudioProcessorEditor()
{
}

//==============================================================================
void SC_1AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    
}

void SC_1AudioProcessorEditor::resized()
{
    gainSlider.setBounds (getWidth() / 2 - 100, getHeight() / 2 - 50, 200, 100);
}
