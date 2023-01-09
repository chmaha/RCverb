/*
 * RCVerb audio effect based on DISTRHO Plugin Framework (DPF)
 *
 * GPLv3 License
 *
 * Copyright © 2023 chmaha <reaclassical@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "PluginRCVerb.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

PluginRCVerb::PluginRCVerb()
    : Plugin(RCVerb::NumParameters, presetCount, 0)  // # of params, # of programs, 0 states
{
    dsp = new RCVerb;
    fSampleRate = getSampleRate();

    for (unsigned p = 0; p < RCVerb::NumParameters; ++p) {
        Parameter param;
        initParameter(p, param);
        setParameterValue(p, param.ranges.def);
    }
}

PluginRCVerb::~PluginRCVerb() {
    delete dsp;
}

// -----------------------------------------------------------------------
// Init

void PluginRCVerb::initParameter(uint32_t index, Parameter& parameter) {
    if (index >= RCVerb::NumParameters)
        return;

    const RCVerb::ParameterRange* range = dsp->parameter_range(index);
    parameter.name = dsp->parameter_label(index);
    parameter.shortName = dsp->parameter_short_label(index);
    parameter.symbol = dsp->parameter_symbol(index);
    parameter.unit = dsp->parameter_unit(index);
    parameter.ranges.min = range->min;
    parameter.ranges.max = range->max;
    parameter.ranges.def = range->init;
    parameter.hints = kParameterIsAutomatable;

    if (dsp->parameter_is_boolean(index))
        parameter.hints |= kParameterIsBoolean;
    if (dsp->parameter_is_integer(index))
        parameter.hints |= kParameterIsInteger;
    if (dsp->parameter_is_logarithmic(index))
        parameter.hints |= kParameterIsLogarithmic;
    if (dsp->parameter_is_trigger(index))
        parameter.hints |= kParameterIsTrigger;
}

/**
  Set the name of the program @ index.
  This function will be called once, shortly after the plugin is created.
*/
void PluginRCVerb::initProgramName(uint32_t index, String& programName) {
    if (index < presetCount) {
        programName = factoryPresets[index].name;
    }
}

// -----------------------------------------------------------------------
// Internal data

/**
  Optional callback to inform the plugin about a sample rate change.
*/
void PluginRCVerb::sampleRateChanged(double newSampleRate) {
    fSampleRate = newSampleRate;
    dsp->init(newSampleRate);
}

/**
  Get the current value of a parameter.
*/
float PluginRCVerb::getParameterValue(uint32_t index) const {
    return dsp->get_parameter(index);
}

/**
  Change a parameter value.
*/
void PluginRCVerb::setParameterValue(uint32_t index, float value) {
    if (index >= RCVerb::NumParameters)
        return;

    const RCVerb::ParameterRange* range = dsp->parameter_range(index);
    dsp->set_parameter(index, CLAMP(value, range->min, range->max));
}

/**
  Load a program.
  The host may call this function from any context,
  including realtime processing.
*/
void PluginRCVerb::loadProgram(uint32_t index) {
    if (index < presetCount) {
        for (int i=0; i < RCVerb::NumParameters; i++) {
            setParameterValue(i, factoryPresets[index].params[i]);
        }
    }
}

// -----------------------------------------------------------------------
// Process

/**
  Plugin is activated.
*/
void PluginRCVerb::activate() {
    fSampleRate = getSampleRate();
    dsp->init(fSampleRate);
}


void PluginRCVerb::run(const float** inputs, float** outputs,
                           uint32_t frames) {
    dsp->process(inputs[0], inputs[1], outputs[0], outputs[1], (unsigned)frames);
}

// -----------------------------------------------------------------------

Plugin* createPlugin() {
    return new PluginRCVerb();
}

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO
