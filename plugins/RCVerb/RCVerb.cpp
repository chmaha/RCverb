
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: rcverb.dsp
// Name: RCVerb
// Author: Julius O. Smith III, Christopher Arndt, chmaha
// Copyright: Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>
// License: GPLv3
// Version: 0.1.0
//------------------------------------------------------------------------------







#include "RCVerb.hpp"



#include <utility>
#include <cmath>

class RCVerb::BasicDsp {
public:
    virtual ~BasicDsp() {}
};

//------------------------------------------------------------------------------
// Begin the Faust code section

namespace {

template <class T> inline T min(T a, T b) { return (a < b) ? a : b; }
template <class T> inline T max(T a, T b) { return (a > b) ? a : b; }

class Meta {
public:
    // dummy
    void declare(...) {}
};

class UI {
public:
    // dummy
    void openHorizontalBox(...) {}
    void openVerticalBox(...) {}
    void closeBox(...) {}
    void declare(...) {}
    void addButton(...) {}
    void addCheckButton(...) {}
    void addVerticalSlider(...) {}
    void addHorizontalSlider(...) {}
    void addVerticalBargraph(...) {}
    void addHorizontalBargraph(...) {}
};

typedef RCVerb::BasicDsp dsp;

} // namespace

#define FAUSTPP_VIRTUAL // do not declare any methods virtual
#define FAUSTPP_PRIVATE public // do not hide any members
#define FAUSTPP_PROTECTED public // do not hide any members

// define the DSP in the anonymous namespace
#define FAUSTPP_BEGIN_NAMESPACE namespace {
#define FAUSTPP_END_NAMESPACE }


#if defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#ifndef FAUSTPP_PRIVATE
#   define FAUSTPP_PRIVATE private
#endif
#ifndef FAUSTPP_PROTECTED
#   define FAUSTPP_PROTECTED protected
#endif
#ifndef FAUSTPP_VIRTUAL
#   define FAUSTPP_VIRTUAL virtual
#endif

#ifndef FAUSTPP_BEGIN_NAMESPACE
#   define FAUSTPP_BEGIN_NAMESPACE
#endif
#ifndef FAUSTPP_END_NAMESPACE
#   define FAUSTPP_END_NAMESPACE
#endif

FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

FAUSTPP_END_NAMESPACE
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>
FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

static float mydsp_faustpower2_f(float value) {
	return value * value;
}

class mydsp : public dsp {
	
 FAUSTPP_PRIVATE:
	
	FAUSTFLOAT fVslider0;
	int fSampleRate;
	float fConst2;
	FAUSTFLOAT fVslider1;
	float fConst3;
	FAUSTFLOAT fVslider2;
	float fConst4;
	float fRec11[2];
	float fConst5;
	float fRec10[2];
	int IOTA0;
	float fVec0[16384];
	int iConst7;
	float fVec1[16384];
	FAUSTFLOAT fVslider3;
	float fConst8;
	float fVec2[4096];
	int iConst9;
	float fRec8[2];
	float fConst11;
	float fRec15[2];
	float fConst12;
	float fRec14[2];
	float fVec3[16384];
	int iConst14;
	float fVec4[2048];
	int iConst15;
	float fRec12[2];
	float fConst17;
	float fRec19[2];
	float fConst18;
	float fRec18[2];
	float fVec5[16384];
	int iConst20;
	float fVec6[4096];
	int iConst21;
	float fRec16[2];
	float fConst23;
	float fRec23[2];
	float fConst24;
	float fRec22[2];
	float fVec7[16384];
	int iConst26;
	float fVec8[2048];
	int iConst27;
	float fRec20[2];
	float fConst29;
	float fRec27[2];
	float fConst30;
	float fRec26[2];
	float fVec9[32768];
	int iConst32;
	float fVec10[16384];
	float fVec11[4096];
	int iConst33;
	float fRec24[2];
	float fConst35;
	float fRec31[2];
	float fConst36;
	float fRec30[2];
	float fVec12[16384];
	int iConst38;
	float fVec13[4096];
	int iConst39;
	float fRec28[2];
	float fConst41;
	float fRec35[2];
	float fConst42;
	float fRec34[2];
	float fVec14[32768];
	int iConst44;
	float fVec15[4096];
	int iConst45;
	float fRec32[2];
	float fConst47;
	float fRec39[2];
	float fConst48;
	float fRec38[2];
	float fVec16[32768];
	int iConst50;
	float fVec17[2048];
	int iConst51;
	float fRec36[2];
	float fRec0[3];
	float fRec1[3];
	float fRec2[3];
	float fRec3[3];
	float fRec4[3];
	float fRec5[3];
	float fRec6[3];
	float fRec7[3];
	float fConst53;
	float fConst54;
	float fRec40[3];
	float fConst56;
	float fConst57;
	float fRec41[3];
	float fConst58;
	float fConst59;
	FAUSTFLOAT fVslider4;
	float fRec42[2];
	float fRec43[2];
	float fRec44[3];
	float fRec45[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "Julius O. Smith III, Christopher Arndt, chmaha");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.9");
		m->declare("compile_options", "-a /tmp/tmpq_aqunw8.cpp -lang cpp -es 1 -mcd 16 -single -ftz 0");
		m->declare("copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("description", "A feedback-delay-network reverb");
		m->declare("filename", "rcverb.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/peak_eq_rm:author", "Julius O. Smith III");
		m->declare("filters.lib/peak_eq_rm:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/peak_eq_rm:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("license", "GPLv3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "RCVerb");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.3");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "0.2");
		m->declare("routes.lib/hadamard:author", "Remy Muller, revised by Romain Michon");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.3");
		m->declare("version", "0.1.0");
	}

	FAUSTPP_VIRTUAL int getNumInputs() {
		return 2;
	}
	FAUSTPP_VIRTUAL int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::floor(0.174713f * fConst0 + 0.5f);
		fConst2 = (0.0f - 6.9077554f * fConst1) / fConst0;
		fConst3 = 6.2831855f / fConst0;
		fConst4 = 3.1415927f / fConst0;
		fConst5 = 0.6666667f * fConst2;
		float fConst6 = std::floor(0.022904f * fConst0 + 0.5f);
		iConst7 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst1 - fConst6)));
		fConst8 = 0.001f * fConst0;
		iConst9 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst6 + -1.0f)));
		float fConst10 = std::floor(0.153129f * fConst0 + 0.5f);
		fConst11 = (0.0f - 6.9077554f * fConst10) / fConst0;
		fConst12 = 0.6666667f * fConst11;
		float fConst13 = std::floor(0.020346f * fConst0 + 0.5f);
		iConst14 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst10 - fConst13)));
		iConst15 = int(std::min<float>(1024.0f, std::max<float>(0.0f, fConst13 + -1.0f)));
		float fConst16 = std::floor(0.127837f * fConst0 + 0.5f);
		fConst17 = (0.0f - 6.9077554f * fConst16) / fConst0;
		fConst18 = 0.6666667f * fConst17;
		float fConst19 = std::floor(0.031604f * fConst0 + 0.5f);
		iConst20 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst16 - fConst19)));
		iConst21 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst19 + -1.0f)));
		float fConst22 = std::floor(0.125f * fConst0 + 0.5f);
		fConst23 = (0.0f - 6.9077554f * fConst22) / fConst0;
		fConst24 = 0.6666667f * fConst23;
		float fConst25 = std::floor(0.013458f * fConst0 + 0.5f);
		iConst26 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst22 - fConst25)));
		iConst27 = int(std::min<float>(1024.0f, std::max<float>(0.0f, fConst25 + -1.0f)));
		float fConst28 = std::floor(0.210389f * fConst0 + 0.5f);
		fConst29 = (0.0f - 6.9077554f * fConst28) / fConst0;
		fConst30 = 0.6666667f * fConst29;
		float fConst31 = std::floor(0.024421f * fConst0 + 0.5f);
		iConst32 = int(std::min<float>(16384.0f, std::max<float>(0.0f, fConst28 - fConst31)));
		iConst33 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst31 + -1.0f)));
		float fConst34 = std::floor(0.192303f * fConst0 + 0.5f);
		fConst35 = (0.0f - 6.9077554f * fConst34) / fConst0;
		fConst36 = 0.6666667f * fConst35;
		float fConst37 = std::floor(0.029291f * fConst0 + 0.5f);
		iConst38 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst34 - fConst37)));
		iConst39 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst37 + -1.0f)));
		float fConst40 = std::floor(0.256891f * fConst0 + 0.5f);
		fConst41 = (0.0f - 6.9077554f * fConst40) / fConst0;
		fConst42 = 0.6666667f * fConst41;
		float fConst43 = std::floor(0.027333f * fConst0 + 0.5f);
		iConst44 = int(std::min<float>(16384.0f, std::max<float>(0.0f, fConst40 - fConst43)));
		iConst45 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst43 + -1.0f)));
		float fConst46 = std::floor(0.219991f * fConst0 + 0.5f);
		fConst47 = (0.0f - 6.9077554f * fConst46) / fConst0;
		fConst48 = 0.6666667f * fConst47;
		float fConst49 = std::floor(0.019123f * fConst0 + 0.5f);
		iConst50 = int(std::min<float>(16384.0f, std::max<float>(0.0f, fConst46 - fConst49)));
		iConst51 = int(std::min<float>(1024.0f, std::max<float>(0.0f, fConst49 + -1.0f)));
		float fConst52 = 1979.2034f / fConst0;
		fConst53 = (1.0f - fConst52) / (fConst52 + 1.0f);
		fConst54 = 0.0f - std::cos(fConst52) * (fConst53 + 1.0f);
		float fConst55 = 9424.778f / fConst0;
		fConst56 = (1.0f - fConst55) / (fConst55 + 1.0f);
		fConst57 = 0.0f - std::cos(fConst55) * (fConst56 + 1.0f);
		fConst58 = 44.1f / fConst0;
		fConst59 = 1.0f - fConst58;
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fVslider0 = FAUSTFLOAT(2.0f);
		fVslider1 = FAUSTFLOAT(3e+03f);
		fVslider2 = FAUSTFLOAT(2.5e+02f);
		fVslider3 = FAUSTFLOAT(4e+01f);
		fVslider4 = FAUSTFLOAT(0.0f);
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec11[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec10[l1] = 0.0f;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 16384; l2 = l2 + 1) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 16384; l3 = l3 + 1) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 4096; l4 = l4 + 1) {
			fVec2[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec8[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec15[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec14[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 16384; l8 = l8 + 1) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2048; l9 = l9 + 1) {
			fVec4[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec12[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec19[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec18[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 16384; l13 = l13 + 1) {
			fVec5[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 4096; l14 = l14 + 1) {
			fVec6[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec16[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec23[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec22[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 16384; l18 = l18 + 1) {
			fVec7[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2048; l19 = l19 + 1) {
			fVec8[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec20[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec27[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec26[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 32768; l23 = l23 + 1) {
			fVec9[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 16384; l24 = l24 + 1) {
			fVec10[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 4096; l25 = l25 + 1) {
			fVec11[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fRec24[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec31[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fRec30[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 16384; l29 = l29 + 1) {
			fVec12[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 4096; l30 = l30 + 1) {
			fVec13[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			fRec28[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fRec35[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fRec34[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 32768; l34 = l34 + 1) {
			fVec14[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 4096; l35 = l35 + 1) {
			fVec15[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fRec32[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			fRec39[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fRec38[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 32768; l39 = l39 + 1) {
			fVec16[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2048; l40 = l40 + 1) {
			fVec17[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			fRec36[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 3; l42 = l42 + 1) {
			fRec0[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 3; l43 = l43 + 1) {
			fRec1[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 3; l44 = l44 + 1) {
			fRec2[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 3; l45 = l45 + 1) {
			fRec3[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 3; l46 = l46 + 1) {
			fRec4[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 3; l47 = l47 + 1) {
			fRec5[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 3; l48 = l48 + 1) {
			fRec6[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 3; l49 = l49 + 1) {
			fRec7[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 3; l50 = l50 + 1) {
			fRec40[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 3; l51 = l51 + 1) {
			fRec41[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			fRec42[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = l53 + 1) {
			fRec43[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 3; l54 = l54 + 1) {
			fRec44[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 3; l55 = l55 + 1) {
			fRec45[l55] = 0.0f;
		}
	}
	
	FAUSTPP_VIRTUAL void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	FAUSTPP_VIRTUAL void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	FAUSTPP_VIRTUAL mydsp* clone() {
		return new mydsp();
	}
	
	FAUSTPP_VIRTUAL int getSampleRate() {
		return fSampleRate;
	}
	
	FAUSTPP_VIRTUAL void buildUserInterface(UI* ui_interface) {
		ui_interface->declare(0, "0", "");
		ui_interface->declare(0, "tooltip", "~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references");
		ui_interface->openHorizontalBox("Zita_Rev1");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("Input");
		ui_interface->declare(&fVslider3, "1", "");
		ui_interface->declare(&fVslider3, "style", "knob");
		ui_interface->declare(&fVslider3, "tooltip", "Delay in ms         before reverberation begins");
		ui_interface->declare(&fVslider3, "unit", "ms");
		ui_interface->addVerticalSlider("In Delay", &fVslider3, FAUSTFLOAT(4e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("Decay Times in Bands (see tooltips)");
		ui_interface->declare(&fVslider2, "1", "");
		ui_interface->declare(&fVslider2, "scale", "log");
		ui_interface->declare(&fVslider2, "style", "knob");
		ui_interface->declare(&fVslider2, "tooltip", "Crossover frequency (Hz) separating low and middle frequencies");
		ui_interface->declare(&fVslider2, "unit", "Hz");
		ui_interface->addVerticalSlider("LowFreq X", &fVslider2, FAUSTFLOAT(2.5e+02f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider0, "3", "");
		ui_interface->declare(&fVslider0, "scale", "log");
		ui_interface->declare(&fVslider0, "style", "knob");
		ui_interface->declare(&fVslider0, "tooltip", "T60 = time (in seconds) to decay 60dB in middle band");
		ui_interface->declare(&fVslider0, "unit", "s");
		ui_interface->addVerticalSlider("RT60", &fVslider0, FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fVslider1, "4", "");
		ui_interface->declare(&fVslider1, "scale", "log");
		ui_interface->declare(&fVslider1, "style", "knob");
		ui_interface->declare(&fVslider1, "tooltip", "Frequency (Hz) at which the high-frequency T60 is half the middle-band's T60");
		ui_interface->declare(&fVslider1, "unit", "Hz");
		ui_interface->addVerticalSlider("HF Damping", &fVslider1, FAUSTFLOAT(3e+03f), FAUSTFLOAT(1.5e+03f), FAUSTFLOAT(2.352e+04f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "5", "");
		ui_interface->openHorizontalBox("Output");
		ui_interface->declare(&fVslider4, "1", "");
		ui_interface->declare(&fVslider4, "style", "knob");
		ui_interface->declare(&fVslider4, "tooltip", "-1 = dry, 1 = wet");
		ui_interface->addVerticalSlider("Wet/Dry Mix", &fVslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fVslider0);
		float fSlow1 = std::exp(fConst2 / fSlow0);
		float fSlow2 = mydsp_faustpower2_f(fSlow1);
		float fSlow3 = 1.0f - fSlow2;
		float fSlow4 = std::cos(fConst3 * float(fVslider1));
		float fSlow5 = 1.0f - fSlow4 * fSlow2;
		float fSlow6 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow5) / mydsp_faustpower2_f(fSlow3) + -1.0f));
		float fSlow7 = fSlow5 / fSlow3;
		float fSlow8 = fSlow7 - fSlow6;
		float fSlow9 = 1.0f / std::tan(fConst4 * float(fVslider2));
		float fSlow10 = 1.0f - fSlow9;
		float fSlow11 = 1.0f / (fSlow9 + 1.0f);
		float fSlow12 = std::exp(fConst5 / fSlow0) / fSlow1 + -1.0f;
		float fSlow13 = fSlow1 * (fSlow6 + (1.0f - fSlow7));
		int iSlow14 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst8 * float(fVslider3))));
		float fSlow15 = std::exp(fConst11 / fSlow0);
		float fSlow16 = mydsp_faustpower2_f(fSlow15);
		float fSlow17 = 1.0f - fSlow16;
		float fSlow18 = 1.0f - fSlow16 * fSlow4;
		float fSlow19 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow18) / mydsp_faustpower2_f(fSlow17) + -1.0f));
		float fSlow20 = fSlow18 / fSlow17;
		float fSlow21 = fSlow20 - fSlow19;
		float fSlow22 = std::exp(fConst12 / fSlow0) / fSlow15 + -1.0f;
		float fSlow23 = fSlow15 * (fSlow19 + (1.0f - fSlow20));
		float fSlow24 = std::exp(fConst17 / fSlow0);
		float fSlow25 = mydsp_faustpower2_f(fSlow24);
		float fSlow26 = 1.0f - fSlow25;
		float fSlow27 = 1.0f - fSlow4 * fSlow25;
		float fSlow28 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow27) / mydsp_faustpower2_f(fSlow26) + -1.0f));
		float fSlow29 = fSlow27 / fSlow26;
		float fSlow30 = fSlow29 - fSlow28;
		float fSlow31 = std::exp(fConst18 / fSlow0) / fSlow24 + -1.0f;
		float fSlow32 = fSlow24 * (fSlow28 + (1.0f - fSlow29));
		float fSlow33 = std::exp(fConst23 / fSlow0);
		float fSlow34 = mydsp_faustpower2_f(fSlow33);
		float fSlow35 = 1.0f - fSlow34;
		float fSlow36 = 1.0f - fSlow4 * fSlow34;
		float fSlow37 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow36) / mydsp_faustpower2_f(fSlow35) + -1.0f));
		float fSlow38 = fSlow36 / fSlow35;
		float fSlow39 = fSlow38 - fSlow37;
		float fSlow40 = std::exp(fConst24 / fSlow0) / fSlow33 + -1.0f;
		float fSlow41 = fSlow33 * (fSlow37 + (1.0f - fSlow38));
		float fSlow42 = std::exp(fConst29 / fSlow0);
		float fSlow43 = mydsp_faustpower2_f(fSlow42);
		float fSlow44 = 1.0f - fSlow43;
		float fSlow45 = 1.0f - fSlow4 * fSlow43;
		float fSlow46 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow45) / mydsp_faustpower2_f(fSlow44) + -1.0f));
		float fSlow47 = fSlow45 / fSlow44;
		float fSlow48 = fSlow47 - fSlow46;
		float fSlow49 = std::exp(fConst30 / fSlow0) / fSlow42 + -1.0f;
		float fSlow50 = fSlow42 * (fSlow46 + (1.0f - fSlow47));
		float fSlow51 = std::exp(fConst35 / fSlow0);
		float fSlow52 = mydsp_faustpower2_f(fSlow51);
		float fSlow53 = 1.0f - fSlow52;
		float fSlow54 = 1.0f - fSlow4 * fSlow52;
		float fSlow55 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow54) / mydsp_faustpower2_f(fSlow53) + -1.0f));
		float fSlow56 = fSlow54 / fSlow53;
		float fSlow57 = fSlow56 - fSlow55;
		float fSlow58 = std::exp(fConst36 / fSlow0) / fSlow51 + -1.0f;
		float fSlow59 = fSlow51 * (fSlow55 + (1.0f - fSlow56));
		float fSlow60 = std::exp(fConst41 / fSlow0);
		float fSlow61 = mydsp_faustpower2_f(fSlow60);
		float fSlow62 = 1.0f - fSlow61;
		float fSlow63 = 1.0f - fSlow4 * fSlow61;
		float fSlow64 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow63) / mydsp_faustpower2_f(fSlow62) + -1.0f));
		float fSlow65 = fSlow63 / fSlow62;
		float fSlow66 = fSlow65 - fSlow64;
		float fSlow67 = std::exp(fConst42 / fSlow0) / fSlow60 + -1.0f;
		float fSlow68 = fSlow60 * (fSlow64 + (1.0f - fSlow65));
		float fSlow69 = std::exp(fConst47 / fSlow0);
		float fSlow70 = mydsp_faustpower2_f(fSlow69);
		float fSlow71 = 1.0f - fSlow70;
		float fSlow72 = 1.0f - fSlow4 * fSlow70;
		float fSlow73 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow72) / mydsp_faustpower2_f(fSlow71) + -1.0f));
		float fSlow74 = fSlow72 / fSlow71;
		float fSlow75 = fSlow74 - fSlow73;
		float fSlow76 = std::exp(fConst48 / fSlow0) / fSlow69 + -1.0f;
		float fSlow77 = fSlow69 * (fSlow73 + (1.0f - fSlow74));
		float fSlow78 = fConst58 * float(fVslider4);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec11[0] = 0.0f - fSlow11 * (fSlow10 * fRec11[1] - (fRec4[1] + fRec4[2]));
			fRec10[0] = fSlow13 * (fRec4[1] + fSlow12 * fRec11[0]) + fSlow8 * fRec10[1];
			fVec0[IOTA0 & 16383] = 0.35355338f * fRec10[0] + 1e-20f;
			float fTemp0 = float(input0[i0]);
			fVec1[IOTA0 & 16383] = fTemp0;
			float fTemp1 = 0.3f * fVec1[(IOTA0 - iSlow14) & 16383];
			float fTemp2 = fTemp1 + fVec0[(IOTA0 - iConst7) & 16383] - 0.6f * fRec8[1];
			fVec2[IOTA0 & 4095] = fTemp2;
			fRec8[0] = fVec2[(IOTA0 - iConst9) & 4095];
			float fRec9 = 0.6f * fTemp2;
			fRec15[0] = 0.0f - fSlow11 * (fSlow10 * fRec15[1] - (fRec0[1] + fRec0[2]));
			fRec14[0] = fSlow23 * (fRec0[1] + fSlow22 * fRec15[0]) + fSlow21 * fRec14[1];
			fVec3[IOTA0 & 16383] = 0.35355338f * fRec14[0] + 1e-20f;
			float fTemp3 = fVec3[(IOTA0 - iConst14) & 16383] + fTemp1 - 0.6f * fRec12[1];
			fVec4[IOTA0 & 2047] = fTemp3;
			fRec12[0] = fVec4[(IOTA0 - iConst15) & 2047];
			float fRec13 = 0.6f * fTemp3;
			float fTemp4 = fRec13 + fRec9;
			fRec19[0] = 0.0f - fSlow11 * (fSlow10 * fRec19[1] - (fRec2[1] + fRec2[2]));
			fRec18[0] = fSlow32 * (fRec2[1] + fSlow31 * fRec19[0]) + fSlow30 * fRec18[1];
			fVec5[IOTA0 & 16383] = 0.35355338f * fRec18[0] + 1e-20f;
			float fTemp5 = fVec5[(IOTA0 - iConst20) & 16383] - (fTemp1 + 0.6f * fRec16[1]);
			fVec6[IOTA0 & 4095] = fTemp5;
			fRec16[0] = fVec6[(IOTA0 - iConst21) & 4095];
			float fRec17 = 0.6f * fTemp5;
			fRec23[0] = 0.0f - fSlow11 * (fSlow10 * fRec23[1] - (fRec6[1] + fRec6[2]));
			fRec22[0] = fSlow41 * (fRec6[1] + fSlow40 * fRec23[0]) + fSlow39 * fRec22[1];
			fVec7[IOTA0 & 16383] = 0.35355338f * fRec22[0] + 1e-20f;
			float fTemp6 = fVec7[(IOTA0 - iConst26) & 16383] - (fTemp1 + 0.6f * fRec20[1]);
			fVec8[IOTA0 & 2047] = fTemp6;
			fRec20[0] = fVec8[(IOTA0 - iConst27) & 2047];
			float fRec21 = 0.6f * fTemp6;
			float fTemp7 = fRec21 + fRec17 + fTemp4;
			fRec27[0] = 0.0f - fSlow11 * (fSlow10 * fRec27[1] - (fRec1[1] + fRec1[2]));
			fRec26[0] = fSlow50 * (fRec1[1] + fSlow49 * fRec27[0]) + fSlow48 * fRec26[1];
			fVec9[IOTA0 & 32767] = 0.35355338f * fRec26[0] + 1e-20f;
			float fTemp8 = float(input1[i0]);
			fVec10[IOTA0 & 16383] = fTemp8;
			float fTemp9 = 0.3f * fVec10[(IOTA0 - iSlow14) & 16383];
			float fTemp10 = fTemp9 + 0.6f * fRec24[1] + fVec9[(IOTA0 - iConst32) & 32767];
			fVec11[IOTA0 & 4095] = fTemp10;
			fRec24[0] = fVec11[(IOTA0 - iConst33) & 4095];
			float fRec25 = 0.0f - 0.6f * fTemp10;
			fRec31[0] = 0.0f - fSlow11 * (fSlow10 * fRec31[1] - (fRec5[1] + fRec5[2]));
			fRec30[0] = fSlow59 * (fRec5[1] + fSlow58 * fRec31[0]) + fSlow57 * fRec30[1];
			fVec12[IOTA0 & 16383] = 0.35355338f * fRec30[0] + 1e-20f;
			float fTemp11 = fVec12[(IOTA0 - iConst38) & 16383] + fTemp9 + 0.6f * fRec28[1];
			fVec13[IOTA0 & 4095] = fTemp11;
			fRec28[0] = fVec13[(IOTA0 - iConst39) & 4095];
			float fRec29 = 0.0f - 0.6f * fTemp11;
			fRec35[0] = 0.0f - fSlow11 * (fSlow10 * fRec35[1] - (fRec3[1] + fRec3[2]));
			fRec34[0] = fSlow68 * (fRec3[1] + fSlow67 * fRec35[0]) + fSlow66 * fRec34[1];
			fVec14[IOTA0 & 32767] = 0.35355338f * fRec34[0] + 1e-20f;
			float fTemp12 = 0.6f * fRec32[1] + fVec14[(IOTA0 - iConst44) & 32767] - fTemp9;
			fVec15[IOTA0 & 4095] = fTemp12;
			fRec32[0] = fVec15[(IOTA0 - iConst45) & 4095];
			float fRec33 = 0.0f - 0.6f * fTemp12;
			fRec39[0] = 0.0f - fSlow11 * (fSlow10 * fRec39[1] - (fRec7[1] + fRec7[2]));
			fRec38[0] = fSlow77 * (fRec7[1] + fSlow76 * fRec39[0]) + fSlow75 * fRec38[1];
			fVec16[IOTA0 & 32767] = 0.35355338f * fRec38[0] + 1e-20f;
			float fTemp13 = 0.6f * fRec36[1] + fVec16[(IOTA0 - iConst50) & 32767] - fTemp9;
			fVec17[IOTA0 & 2047] = fTemp13;
			fRec36[0] = fVec17[(IOTA0 - iConst51) & 2047];
			float fRec37 = 0.0f - 0.6f * fTemp13;
			fRec0[0] = fRec36[1] + fRec32[1] + fRec28[1] + fRec24[1] + fRec20[1] + fRec16[1] + fRec8[1] + fRec12[1] + fRec37 + fRec33 + fRec29 + fRec25 + fTemp7;
			fRec1[0] = fRec20[1] + fRec16[1] + fRec8[1] + fRec12[1] + fTemp7 - (fRec36[1] + fRec32[1] + fRec28[1] + fRec24[1] + fRec37 + fRec33 + fRec25 + fRec29);
			float fTemp14 = fRec17 + fRec21;
			fRec2[0] = fRec28[1] + fRec24[1] + fRec8[1] + fRec12[1] + fRec29 + fRec25 + fTemp4 - (fRec36[1] + fRec32[1] + fRec20[1] + fRec16[1] + fRec37 + fRec33 + fTemp14);
			fRec3[0] = fRec36[1] + fRec32[1] + fRec8[1] + fRec12[1] + fRec37 + fRec33 + fTemp4 - (fRec28[1] + fRec24[1] + fRec20[1] + fRec16[1] + fRec29 + fRec25 + fTemp14);
			float fTemp15 = fRec9 + fRec21;
			float fTemp16 = fRec13 + fRec17;
			fRec4[0] = fRec32[1] + fRec24[1] + fRec16[1] + fRec12[1] + fRec33 + fRec25 + fTemp16 - (fRec36[1] + fRec28[1] + fRec20[1] + fRec8[1] + fRec37 + fRec29 + fTemp15);
			fRec5[0] = fRec36[1] + fRec28[1] + fRec16[1] + fRec12[1] + fRec37 + fRec29 + fTemp16 - (fRec32[1] + fRec24[1] + fRec20[1] + fRec8[1] + fRec33 + fRec25 + fTemp15);
			float fTemp17 = fRec9 + fRec17;
			float fTemp18 = fRec13 + fRec21;
			fRec6[0] = fRec36[1] + fRec24[1] + fRec20[1] + fRec12[1] + fRec37 + fRec25 + fTemp18 - (fRec32[1] + fRec28[1] + fRec16[1] + fRec8[1] + fRec33 + fRec29 + fTemp17);
			fRec7[0] = fRec32[1] + fRec28[1] + fRec20[1] + fRec12[1] + fRec33 + fRec29 + fTemp18 - (fRec36[1] + fRec24[1] + fRec16[1] + fRec8[1] + fRec37 + fRec25 + fTemp17);
			float fTemp19 = 0.37f * (fRec1[0] + fRec2[0]);
			float fTemp20 = fConst54 * fRec40[1];
			fRec40[0] = fTemp19 - (fTemp20 + fConst53 * fRec40[2]);
			float fTemp21 = fConst53 * fRec40[0];
			float fTemp22 = 0.5f * (fTemp21 + fRec40[2] + fTemp19 + fTemp20 + (fTemp21 + fTemp20 + fRec40[2] - fTemp19));
			float fTemp23 = fConst57 * fRec41[1];
			fRec41[0] = fTemp22 - (fTemp23 + fConst56 * fRec41[2]);
			float fTemp24 = fConst56 * fRec41[0];
			fRec42[0] = fSlow78 + fConst59 * fRec42[1];
			float fTemp25 = fRec42[0] + 1.0f;
			float fTemp26 = 1.0f - 0.5f * fTemp25;
			fRec43[0] = fConst58 + fConst59 * fRec43[1];
			output0[i0] = FAUSTFLOAT(0.5f * fRec43[0] * (fTemp0 * fTemp25 + fTemp26 * (fTemp24 + fRec41[2] + fTemp22 + fTemp23 + (fTemp24 + fTemp23 + fRec41[2] - fTemp22))));
			float fTemp27 = 0.37f * (fRec1[0] - fRec2[0]);
			float fTemp28 = fConst54 * fRec44[1];
			fRec44[0] = fTemp27 - (fTemp28 + fConst53 * fRec44[2]);
			float fTemp29 = fConst53 * fRec44[0];
			float fTemp30 = 0.5f * (fTemp29 + fRec44[2] + fTemp27 + fTemp28 + (fTemp29 + fTemp28 + fRec44[2] - fTemp27));
			float fTemp31 = fConst57 * fRec45[1];
			fRec45[0] = fTemp30 - (fTemp31 + fConst56 * fRec45[2]);
			float fTemp32 = fConst56 * fRec45[0];
			output1[i0] = FAUSTFLOAT(0.5f * fRec43[0] * (fTemp8 * fTemp25 + fTemp26 * (fTemp32 + fRec45[2] + fTemp30 + fTemp31 + (fTemp32 + fTemp31 + fRec45[2] - fTemp30))));
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			IOTA0 = IOTA0 + 1;
			fRec8[1] = fRec8[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec12[1] = fRec12[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec16[1] = fRec16[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec20[1] = fRec20[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			fRec28[1] = fRec28[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec32[1] = fRec32[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec36[1] = fRec36[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			fRec42[1] = fRec42[0];
			fRec43[1] = fRec43[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
		}
	}

};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif



//------------------------------------------------------------------------------
// End the Faust code section




RCVerb::RCVerb()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();

}

RCVerb::~RCVerb()
{
}

void RCVerb::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();

}

void RCVerb::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();

}

void RCVerb::process(
    const float *in0,const float *in1,
    float *out0,float *out1,
    unsigned count) noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    float *inputs[] = {
        const_cast<float *>(in0),const_cast<float *>(in1),
    };
    float *outputs[] = {
        out0,out1,
    };
    dsp.compute(count, inputs, outputs);

}

const char *RCVerb::parameter_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "In Delay";
    
    case 1:
        return "LowFreq X";
    
    case 2:
        return "RT60";
    
    case 3:
        return "HF Damping";
    
    case 4:
        return "Wet/Dry Mix";
    
    default:
        return 0;
    }
}

const char *RCVerb::parameter_short_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    case 3:
        return "";
    
    case 4:
        return "";
    
    default:
        return 0;
    }
}

const char *RCVerb::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "In_Delay";
    
    case 1:
        return "LowFreq_X";
    
    case 2:
        return "RT60";
    
    case 3:
        return "HF_Damping";
    
    case 4:
        return "Wet_Dry_Mix";
    
    default:
        return 0;
    }
}

const char *RCVerb::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "ms";
    
    case 1:
        return "Hz";
    
    case 2:
        return "s";
    
    case 3:
        return "Hz";
    
    case 4:
        return "";
    
    default:
        return 0;
    }
}

const RCVerb::ParameterRange *RCVerb::parameter_range(unsigned index) noexcept
{
    switch (index) {
    
    case 0: {
        static const ParameterRange range = { 40.0, 20.0, 100.0 };
        return &range;
    }
    
    case 1: {
        static const ParameterRange range = { 250.0, 50.0, 1000.0 };
        return &range;
    }
    
    case 2: {
        static const ParameterRange range = { 2.0, 1.0, 8.0 };
        return &range;
    }
    
    case 3: {
        static const ParameterRange range = { 3000.0, 1500.0, 23520.0 };
        return &range;
    }
    
    case 4: {
        static const ParameterRange range = { 0.0, -1.0, 1.0 };
        return &range;
    }
    
    default:
        return 0;
    }
}

bool RCVerb::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool RCVerb::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool RCVerb::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool RCVerb::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    
    case 1:
        return true;
    
    case 2:
        return true;
    
    case 3:
        return true;
    
    default:
        return false;
    }
}

float RCVerb::get_parameter(unsigned index) const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        return dsp.fVslider3;
    
    case 1:
        return dsp.fVslider2;
    
    case 2:
        return dsp.fVslider0;
    
    case 3:
        return dsp.fVslider1;
    
    case 4:
        return dsp.fVslider4;
    
    default:
        (void)dsp;
        return 0;
    }
}

void RCVerb::set_parameter(unsigned index, float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        dsp.fVslider3 = value;
        break;
    
    case 1:
        dsp.fVslider2 = value;
        break;
    
    case 2:
        dsp.fVslider0 = value;
        break;
    
    case 3:
        dsp.fVslider1 = value;
        break;
    
    case 4:
        dsp.fVslider4 = value;
        break;
    
    default:
        (void)dsp;
        (void)value;
        break;
    }
}


float RCVerb::get_In_Delay() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fVslider3;
}

float RCVerb::get_LowFreq_X() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fVslider2;
}

float RCVerb::get_RT60() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fVslider0;
}

float RCVerb::get_HF_Damping() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fVslider1;
}

float RCVerb::get_Wet_Dry_Mix() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fVslider4;
}


void RCVerb::set_In_Delay(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fVslider3 = value;
}

void RCVerb::set_LowFreq_X(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fVslider2 = value;
}

void RCVerb::set_RT60(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fVslider0 = value;
}

void RCVerb::set_HF_Damping(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fVslider1 = value;
}

void RCVerb::set_Wet_Dry_Mix(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fVslider4 = value;
}



