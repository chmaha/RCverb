declare name "RCVerb";
declare description "A feedback-delay-network reverb";
declare author "Julius O. Smith III, Christopher Arndt, chmaha";
declare copyright "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>";
declare license "STK-4.3 license";
declare version "0.1.0";

import("stdfaust.lib");

zita_rev1 = _,_ <: re.zita_rev1_stereo(rdel,f1,f2,t60dc,t60m,fsmax),_,_ : out_eq,_,_ :
    dry_wet : out_level
with{
    fsmax = 48000.0;  // highest sampling rate that will be used

    fdn_group(x) = hgroup(
    "[0] Zita_Rev1 [tooltip: ~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER
    ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and
    references]", x);

    in_group(x) = fdn_group(hgroup("[1] Input", x));

    rdel = in_group(vslider("[1] In Delay [unit:ms] [style:knob] [tooltip: Delay in ms
        before reverberation begins]",40,20,100,1));

    freq_group(x) = fdn_group(hgroup("[2] Decay Times in Bands (see tooltips)", x));

    f1 = freq_group(vslider("[1] LowFreq X [unit:Hz] [style:knob] [scale:log] [tooltip:
        Crossover frequency (Hz) separating low and middle frequencies]", 250, 50, 1000, 1));

    t60dc = 1.5*t60m;

    t60m = freq_group(vslider("[3] RT60 [unit:s] [style:knob] [scale:log] [tooltip:
        T60 = time (in seconds) to decay 60dB in middle band]",2, 1, 8, 0.1));

    f2 = freq_group(vslider("[4] HF Damping [unit:Hz] [style:knob] [scale:log]
    [tooltip: Frequency (Hz) at which the high-frequency T60 is half the middle-band's T60]",
    3000, 1500, 0.49*fsmax, 1));

    out_eq = pareq_stereo(eq1f,eq1l,eq1q) : pareq_stereo(eq2f,eq2l,eq2q);
    // Zolzer style peaking eq (not used in zita-rev1) (filters.lib):
    // pareq_stereo(eqf,eql,Q) = peak_eq(eql,eqf,eqf/Q), peak_eq(eql,eqf,eqf/Q);
    // Regalia-Mitra peaking eq with "Q" hard-wired near sqrt(g)/2 (filters.lib):
    pareq_stereo(eqf,eql,Q) = fi.peak_eq_rm(eql,eqf,tpbt), fi.peak_eq_rm(eql,eqf,tpbt)
    with {
        tpbt = wcT/sqrt(max(0,g)); // tan(PI*B/SR), B bw in Hz (Q^2 ~ g/4)
        wcT = 2*ma.PI*eqf/ma.SR;  // peak frequency in rad/sample
        g = ba.db2linear(eql); // peak gain
    };

    eq1_group(x) = fdn_group(hgroup("[3] RM Peaking Equalizer 1", x));

    eq1f = 315;

    eq1l = 0;

    eq1q = 3;

    eq2_group(x) = fdn_group(hgroup("[4] RM Peaking Equalizer 2", x));

    eq2f = 1500;

    eq2l = 0;

    eq2q = 3;

    out_group(x) = fdn_group(hgroup("[5] Output", x));

    dry_wet(x,y) = *(wet) + dry*x, *(wet) + dry*y with {
        wet = 0.5*(drywet+1.0);
        dry = 1.0-wet;
    };

    drywet = out_group(vslider("[1] Wet/Dry Mix [style:knob] [tooltip: -1 = dry, 1 = wet]",
    0, -1.0, 1.0, 0.01)) : si.smoo;

    out_level = *(gain),*(gain);

    gain = 0 : ba.db2linear : si.smoo;
};

process = _,_ : zita_rev1 : _,_;

