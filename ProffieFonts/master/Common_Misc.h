// ================================ COMMON CODE ===========================

// Simple Percentage
template<int PERCENT>
using PERCENTAGE_S = Percentage<Int<32768>, PERCENT>;

// Basic Center position based on blade angle.
using LOCKUPPOSITIONCENTER = Scale<
	BladeAngle<0, 16000>, 
	Sum<
		IntArg<LOCKUP_POSITION_ARG, 16000>, 
		Int<-12000>
	>, 
	Sum<
		IntArg<LOCKUP_POSITION_ARG, 16000>, 
		Int<10000>
	>
>;

// Blade Angle / Lockup Position.
using LOCKUPPOSITION = Scale<
	BladeAngle<>, 
	LOCKUPPOSITIONCENTER,
	Sum<
		IntArg<LOCKUP_POSITION_ARG, 16000>, 
		Int<-10000>
	>
>;

// Blade Angle / Lockup Position Scale with SwingSpeed.
using LOCKUPPOSITIONSWING = Scale<
	BladeAngle<>,
	LOCKUPPOSITIONCENTER,
	Scale<
		SwingSpeed<100>,
		Int<14000>,
		Int<18000>
	>
>;

// Lockup Clash Impact Color
using LOCKUPCLASHCOLOR = Mix<
	IsLessThan<
		ClashImpactF<>, 
		Int<26000>
	>, 
	LOCKUPCOLOR, 
	AlphaL<
		LOCKUPCOLOR, 
		Bump<
			LOCKUPPOSITION,
			Scale<
				ClashImpactF<>, 
				Int<20000>, 
				Int<60000>
			>
		>
	>
>;

// Swing Speed Calculation, used in Swing Options.
template<int SCALE_SPEED1, int SCALE_SPEED2 = 600, int SCALE_MIN = -19300, int SCALE_MAX = 32768>
using SWINGSPEEDSCALE = Scale<
	IsLessThan<
		SwingSpeed<SCALE_SPEED1>,
		Int<13600>
	>,
	Scale<
		SwingSpeed<SCALE_SPEED2>,
		Int<SCALE_MIN>,
		Int<SCALE_MAX>
	>,
	Int<0>
>;

// Ignition Flicker Stripes, used in Stabalize Ignition.
using Ignition_Flicker_Stripes = Stripes<
	3000,
	-3500,
	RotateColorsX<Variation, IGNITIONCOLOR>, //Rgb<90,180,255> //IGNITION_COLOR_ARG
	RandomPerLEDFlicker<
		RotateColorsX<
			Variation,
			COLOR_MIX<Int<7710>, IGNITIONCOLOR> //Rgb<0,26,60> // IGNITION_COLOR_ARG / 4.25
		>,
		Black
	>,
	BrownNoiseFlicker<
		RotateColorsX<Variation, IGNITIONCOLOR>, //Rgb<90,180,255> //IGNITION_COLOR_ARG
		RotateColorsX<
			Variation,
			COLOR_MIX<Int<7710>, IGNITIONCOLOR> //Rgb<0,26,60> //IGNITION_COLOR_ARG / 4.25
		>,
		200
	>,
	RandomPerLEDFlicker<
		RotateColorsX<
			Variation,
			COLOR_MIX<Int<16384>, IGNITIONCOLOR> //Rgb<0,42,128> // IGNITION_COLOR_ARG / 2
		>,
		RotateColorsX<
			Variation,
			COLOR_MIX<Int<7710>, IGNITIONCOLOR> //Rgb<0,26,60> // IGNITION_COLOR_ARG / 4.25
		>
	>
>;

// ShowBatteryLevelHilt
using ShowBatteryLevelHilt = TrConcat<
	TrDelay<1500>,
	Black,
	TrFade<1000>,
	AlphaL<
		Mix<
			BatteryLevel,
			Red,
			Green
		>,
		Bump<
			Int<0>, //BatteryLevel
			IntArg<EMITTER_SIZE_ARG, 2000> //Int<12000>
		>
	>,
	TrFade<3000>
>;

// Battery Monitor on Boot
using BatteryLevelOnBoot = TransitionEffectL<
	ShowBatteryLevelHilt,
	EFFECT_BOOT
>;

// Battery level on font change
using BatteryLevelOnFontChange = TransitionEffectL<
	ShowBatteryLevelHilt,
	EFFECT_NEWFONT
>;

// Battery level
using BatteryLevelOnDemand = TransitionEffectL<
	ShowBatteryLevelHilt,
	EFFECT_BATTERY_LEVEL
>;