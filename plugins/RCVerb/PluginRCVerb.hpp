/*
 * RCVerb audio effect based on DISTRHO Plugin Framework (DPF)
 *
 * GPLv3 license
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

#ifndef PLUGIN_RCVERB_H
#define PLUGIN_RCVERB_H

#include "DistrhoPlugin.hpp"
#include "RCVerb.hpp"

START_NAMESPACE_DISTRHO

#ifndef MIN
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#endif

#ifndef MAX
#define MAX(a,b) ( (a) > (b) ? (a) : (b) )
#endif

#ifndef CLAMP
#define CLAMP(v, min, max) (MIN((max), MAX((min), (v))))
#endif

// -----------------------------------------------------------------------

class PluginRCVerb : public Plugin {
public:
    PluginRCVerb();

    ~PluginRCVerb();

protected:
    // -------------------------------------------------------------------
    // Information

    const char* getLabel() const noexcept override {
        return "RCVerb";
    }

    const char* getDescription() const override {
        return "A feedback-delay-network reverb";
    }

    const char* getMaker() const noexcept override {
        return "reaclassical.org";
    }

    const char* getHomePage() const override {
        return DISTRHO_PLUGIN_URI;
    }

    const char* getLicense() const noexcept override {
        return "https://www.gnu.org/licenses/gpl-3.0-standalone.html";
    }

    uint32_t getVersion() const noexcept override {
        return d_version(0, 1, 1);
    }

    // Go to:
    //
    // http://service.steinberg.de/databases/plugin.nsf/plugIn
    //
    // Get a proper plugin UID and fill it in here!
    int64_t getUniqueId() const noexcept override {
        return d_cconst('r', 'c', 'v', 'b');
    }

    // -------------------------------------------------------------------
    // Init

    void initParameter(uint32_t index, Parameter& parameter) override;
    // void initProgramName(uint32_t index, String& programName) override;

    // -------------------------------------------------------------------
    // Internal data

    float getParameterValue(uint32_t index) const override;
    void setParameterValue(uint32_t index, float value) override;
    // void loadProgram(uint32_t index) override;

    // -------------------------------------------------------------------
    // Optional

    // Optional callback to inform the plugin about a sample rate change.
    void sampleRateChanged(double newSampleRate) override;

    // -------------------------------------------------------------------
    // Process

    void activate() override;
    void run(const float**, float** outputs, uint32_t frames) override;

    // -------------------------------------------------------------------

private:
    double          fSampleRate;
    RCVerb*     dsp;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginRCVerb)
};

struct Preset {
    const char* name;
    float params[RCVerb::NumParameters];
};

const Preset factoryPresets[] = {
    //{
    //    "Preset name",
    //    {1.0, ...}      // array of RCVerb::NumParameters float param values
    //},
    // {
    //     "Warm Hall (Insert)",
    //     {
    //         35.0,       // In_Delay
    //         200.0,      // LF_X
    //         2.2,        // Low_RT60
    //         2.0,        // Mid_RT60
    //         4000.0,     // HF_Damping
    //         500.0,      // Eq1_Freq
    //         -2.0,       // Eq1_Level
    //         2500.0,     // Eq2_Freq
    //         -2.0,       // Eq2_Level
    //         0.5,        // Dry_Wet_Mix
    //         2.0         // Level
    //     }
    // },
    // {"Warm Hall (Send)", {35.0, 200.0, 2.2, 2.0, 4000.0, 500.0, -2.0, 2500.0, -2.0, -1.0, 20.0}},
    // {"Dark Hall (Insert)", {50.0, 200.0, 2.0, 1.8, 5500.0, 120, -3.0, 4500.0, -3.0, 0.5, 2.0}},
    // {"Dark Hall (Send)", {50.0, 200.0, 2.0, 1.8, 5500.0, 120, -3.0, 4500.0, -3.0, -1.0, 20.0}},
    // {"Medium Church (Insert)", {85.0, 200.0, 2.8, 2.5, 10000.0, 200.0, 0.0, 4000.0, 0.0, 0.3, 2.0}},
    // {"Medium Church (Send)", {85.0, 200.0, 2.8, 2.5, 10000.0, 200.0, 0.0, 4000.0, 0.0, -1.0, 20.0}},
};

const uint presetCount = sizeof(factoryPresets) / sizeof(Preset);

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif  // #ifndef PLUGIN_RCVERB_H
