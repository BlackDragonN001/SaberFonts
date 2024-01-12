// ================================ COMMON CODE ===========================

const int SWING_SPEED_DEFAULT = 500;

// Simple Percentage
template<int PERCENT>
using PERCENTAGE_S = Percentage<Int<32768>, PERCENT>;

// Blade Angle Scale
template<class MIN = Int<-50>, class MAX = Int<-2000>, class HOLD_TIME = Int<0>, class HOLD_SPEED = Int<0>, int MIN_BLADE = 0, int MAX_BLADE = 32768>
using BLADE_ANGLE_SCLAE = Scale<
	HoldPeakF<
		BladeAngle<MIN_BLADE, MAX_BLADE>,
		HOLD_TIME, // HOLD_TIME_MS
		HOLD_SPEED // TRANSITION SPEED
	>,
	MIN,
	MAX
>;

// Swing Speed Scale with HoldPeak. HoldPeak defaults to 0 so it doesn't hold.
template<int SPEED = 250, class MIN = Int<-50>, class MAX = Int<-2000>, class HOLD_TIME = Int<0>, class HOLD_SPEED = Int<0>>
using SWING_SPEED_SCLAE = Scale<
	//SwingSpeed<SPEED>,
	//Scale<
		HoldPeakF<
			SwingSpeed<SPEED>,
			//SwingAcceleration<250>,
			//TwistAcceleration<250>,
			//TwistAngle<>,
			//BladeAngle<>
			HOLD_TIME, // HOLD_TIME_MS
			HOLD_SPEED // TRANSITION SPEED
		>,
		MIN,
		MAX
//	>,
//	MAX
>;

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


// Random Spark
template<class COLOR, class POSITION = Int<0>, class SPEED = Int<250>, class SPARK_SIZE_MIN = Int<200>, class SPARK_SIZE_MAX = Int<600>, class MIN_DELAY = Int<200>, class MAX_DELAY = Int<600>, class FADE_TIME = Int<100>, class BOING_TIME = Int<500>>
using TrSparkX_Random = TransitionLoopL<
	TrConcat<
		TrBoingX<BOING_TIME, 3>,
		TrConcat<
			TrFadeX<FADE_TIME>,
			TrSparkX<
				COLOR,
				Scale<
					NoisySoundLevel,
					SPARK_SIZE_MIN,
					SPARK_SIZE_MAX
				>,
				SPEED,
				POSITION
			>,
			TrFadeX<FADE_TIME>
		>,
		TrDelayX< // Random Timer
			Scale<
				RandomF,
				MIN_DELAY,
				MAX_DELAY
			>
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