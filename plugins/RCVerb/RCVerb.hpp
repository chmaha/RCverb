
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: rcverb.dsp
// Name: RCVerb
// Author: Julius O. Smith III, Christopher Arndt
// Copyright: Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>
// License: STK-4.3 license
// Version: 0.1.0
//------------------------------------------------------------------------------






#pragma once
#ifndef RCVerb_Faust_pp_Gen_HPP_
#define RCVerb_Faust_pp_Gen_HPP_

#include <memory>

class RCVerb {
public:
    RCVerb();
    ~RCVerb();

    void init(float sample_rate);
    void clear() noexcept;

    void process(
        const float *in0,const float *in1,
        float *out0,float *out1,
        unsigned count) noexcept;

    enum { NumInputs = 2 };
    enum { NumOutputs = 2 };
    enum { NumActives = 5 };
    enum { NumPassives = 0 };
    enum { NumParameters = 5 };

    enum Parameter {
        p_In_Delay,
        p_LowFreq_X,
        p_RT60,
        p_HF_Damping,
        p_Wet_Dry_Mix,
        
    };

    struct ParameterRange {
        float init;
        float min;
        float max;
    };

    static const char *parameter_label(unsigned index) noexcept;
    static const char *parameter_short_label(unsigned index) noexcept;
    static const char *parameter_symbol(unsigned index) noexcept;
    static const char *parameter_unit(unsigned index) noexcept;
    static const ParameterRange *parameter_range(unsigned index) noexcept;
    static bool parameter_is_trigger(unsigned index) noexcept;
    static bool parameter_is_boolean(unsigned index) noexcept;
    static bool parameter_is_integer(unsigned index) noexcept;
    static bool parameter_is_logarithmic(unsigned index) noexcept;

    float get_parameter(unsigned index) const noexcept;
    void set_parameter(unsigned index, float value) noexcept;

    
    float get_In_Delay() const noexcept;
    
    float get_LowFreq_X() const noexcept;
    
    float get_RT60() const noexcept;
    
    float get_HF_Damping() const noexcept;
    
    float get_Wet_Dry_Mix() const noexcept;
    
    
    void set_In_Delay(float value) noexcept;
    
    void set_LowFreq_X(float value) noexcept;
    
    void set_RT60(float value) noexcept;
    
    void set_HF_Damping(float value) noexcept;
    
    void set_Wet_Dry_Mix(float value) noexcept;
    

public:
    class BasicDsp;

private:
    std::unique_ptr<BasicDsp> fDsp;



};




#endif // RCVerb_Faust_pp_Gen_HPP_