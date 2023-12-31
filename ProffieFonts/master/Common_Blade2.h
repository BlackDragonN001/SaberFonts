// ===================== ALTERNATE BLADE STYLES =======================
// Using template passed in Color and variation timers.

// Audio Flicker
template<class COLOR>
using AltStyle_AudioFilter = AudioFlickerL<
	RotateColorsX<Variation, COLOR>
>;

// Random Flicker
template<class COLOR>
using AltStyle_RandomFlicker = RandomL<
	COLOR
>;

// Pusling
template<class COLOR, class PULSE_MS = Int<1200>>
using AltStyle_Pulsing = PulsingL<
	RotateColorsX<Variation, COLOR>,
	PULSE_MS
>;

// Random Per LED Flicker
template<class COLOR>
using AltStyle_RandomPerLEDFlicker = RandomPerLEDFlickerL<
	COLOR
>;

// Hump Flicker
template<class COLOR>
using AltStyle_HumpFlicker_Random = AlphaL<
	HumpFlickerL<COLOR, 10>,
	Bump<
		RandomF,
		Int<20000>
	>
>;

// Hump Waves (2 Color)
template<class COLORA, class COLORB>
using AltStyle_HumpWave = Layers <
	TransitionLoopL<
		TrWaveX<
			HumpFlickerL<RotateColorsX<Variation, COLORA>, 40>,
			Int<250>,
			Int<100>,
			Int<200>,
			Int<0>
		>
	>,
	TransitionLoopL<
		TrWaveX<
			HumpFlickerL<RotateColorsX<Variation, COLORB>, 40>,
			Int<350>,
			Int<100>,
			Int<300>,
			Int<0>
		>
	>
>;

// Sparkle
template<class COLOR>
using AltStyle_Sparkle = SparkleL<
	COLOR
>;

// Style Fire
template<class COLORA, class COLORB, int SPEED = 2>
using AltStyle_Fire = AlphaL< 
	StyleFire<
		COLORA,
		COLORB,
		0,
		SPEED
	>,
	Int<16384>
>;

// Brown Noise with Stripes
template<class COLOR, class WIDTH = Int<3000>, class SPEED = Int<-4000>>
using AltStyle_BrownNoise_Stripes = BrownNoiseFlickerL<
	//TRANSPARENT,
	StripesX<
		WIDTH, 
		SPEED, 
		COLOR_MIX<Int<9638>, COLOR>, //Rgb<50, 50, 75>, // ALT COLOR / 3.4
		COLOR_MIX<Int<19275>, COLOR>, //Rgb<100, 100, 150>, // ALT COLOR / 1.7
		COLOR_MIX<Int<1928>, COLOR>, //Rgb<10, 10, 15>, // ALT COLOR / 17
		COLOR //Rgb<150, 150, 225> // ALT COLOR
	>, 
	Int<200>
>;

// Fett263 Smoke Blade Fire layer, ALT Color
template<class COLOR, int SPEED = 1>
using AltStyle_SmokeBlade = AlphaL <
	StyleFire<
		RotateColorsX<Variation, COLOR>,
		RotateColorsX<
			Variation,
			COLOR_MIX<Int<256>, COLOR> //Rgb<2,2,0> // ALT / 127.5
		>,
		0,
		SPEED,
		FireConfig<10,2000,2>,
		FireConfig<10,2000,2>,
		FireConfig<10,2000,2>,
		FireConfig<0,0,25>
	>,
	Int<10000>
>;

template<class COLOR>
using AltStyle_SmokeBlade2 = AlphaL<
	StaticFire<
		RotateColorsX<Variation, COLOR>,
		RotateColorsX<
			Variation,
			COLOR_MIX<Int<256>, COLOR>
		>,
		0,
		1,
		10,
		2000,
		2
	>,
	Int<10000>
>;

// Lightning Flash
template<class COLOR>
using AltStyle_LightningFlash = TransitionLoop<
	AlphaL< // Invisible color
		COLOR,
		Int<0>
	>,
	TrConcat<
		TrBoing<500, 3>,
		TrConcat<
			TrFade<100>,
			AlphaL<
				HumpFlickerL<COLOR, 10>,
				Bump<
					RandomF,
					Int<20000>
				>
			>,
			TrFade<100>
		>,
		TrDelayX< // Random Timer
			Scale<
				SlowNoise<Int<3000>>,
				Int<100>,
				Int<2000>
			>
		>
	>
>;

// Cylon
template<class COLOR, int SIZE = 5, int SPEED = 20>
using AltStyle_Cylon = AlphaL<
	Cylon<
		COLOR,
		SIZE,
		SPEED
	>,
	Int<16384>
>;

// Emitter Tip Flame
template<class COLOR>
using AltStyle_EmitterTipFlame = AlphaL<
	Layers <
		Gradient<COLOR, TRANSPARENT>,
		HumpFlickerL<
			Layers<
				AudioFlickerL<COLOR>, 
				BrownNoiseFlickerL<
					//TRANSPARENT,
					COLOR,
					Int<200>
				>
			>,
			10
		>
	>,
	Bump<
		Scale<
			BladeAngle<>,
			Int<28000>,
			Int<32000>
		>,
		Scale<
			BladeAngle<>,
			Int<20000>,
			Int<8000>
		>
	>
>;


// Emitter Flare
template<class COLOR>
using AltStyle_EmitterFlare = AlphaL<
	AudioFlickerL<COLOR>, 
	SmoothStep<
		Scale<
			NoisySoundLevel,
			IntArg<EMITTER_SIZE_ARG,2000>,
			Sum<
				IntArg<EMITTER_SIZE_ARG,2000>,
				Int<6000>
			>
		>,
		Int<-6000>
	>
>;

// Timed "breathing" emitter flare 
//- NOTE: Due to the way Proffie works, this isn't always "lined up" and might be slightly ahead or slightly behind the hum's breathing. To fix you can turn the saber off and back on until it's lined up. The timing is right, but the code runs in the background even after turning the saber off so it doesn't always start "on time."
template<class COLOR>
using AltStyle_EmitterBreathe = Mix<
	Sin<Int<8>>,
	AlphaL<
		RotateColorsX<Variation, COLOR>,
		Bump<
			Int<0>,
			//Int<6000>
			Percentage<IntArg<EMITTER_SIZE_ARG, 2000>, 100>
			/*
			Mult<
				Int<8937>, //33%
				IntArg<EMITTER_SIZE_ARG, 2000>
			>
			*/
		>
	>,
	AlphaL<
		RotateColorsX<Variation, COLOR>,
		Bump<
			Int<0>,
			//Int<22000>
			Percentage<IntArg<EMITTER_SIZE_ARG, 2000>, 300>
		>
	>
>;

// Emitter Pulse
template<class COLOR>
using AltStyle_Emitter_Pulse = TransitionLoopL<
	TrConcat<
		TrDelayX<
			Scale<
				SlowNoise<Int<1000>>,
				Int<300>,
				Int<3000>
			>
		>,
		AlphaL<
			COLOR,
			Int<0>
		>,
		TrSparkX<
			COLOR,
			Scale<
				NoisySoundLevel,
				Int<200>,
				Int<600>
			>,
			Int<250>,
			Int<0>
		>
	>
>;

// Spark moving with BladeAngle
template<class COLOR>
using AltStyle_Spark_BladeAngle = AlphaL<
	Mix<
		BladeAngle<>,
		AudioFlickerL<
			RotateColorsX<Variation, COLOR>
		>,
		PulsingL<
			RotateColorsX<Variation, COLOR>,
			Int<100>
		>
	>,
	Bump<
		BladeAngle<0, 32000>,
		Int<4000>
	>
>;

/* // Stripes doens't support Transparency, so it never looks good.
// StripesX Slownoise
template<class COLOR>
using AltStyle_StripesX_SlowNoise = AlphaL<
	StripesX<
		Int<1500>,
		Scale<
			SlowNoise<Int<2500>>,
			Int<-3000>,
			Int<-5000>
		>,
		Black,
		COLOR_MIX<10280, RotateColorsX<Variation, COLOR>>, //33%
		Black,
		COLOR_MIX<2570,	RotateColorsX<Variation, COLOR>>,
		Black
	>,
	Int<16384>
>;
//*/


// Style Fire TEST
template<class COLOR>
using AltStyle_FireTEST = AlphaL< 
	StyleFire<
		COLOR,
		TRANSPARENT,
		0,
		2
	>,
	Int<16384>
>;
