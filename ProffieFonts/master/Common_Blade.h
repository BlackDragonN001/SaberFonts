// ===================== BASE BLADE STYLES =======================
/*
// Basic Audio Filter, BASE color, 50% BASE color (breathing)
using BaseStyle_AudioFilter = AudioFlicker<
	BASECOLOR,
	BASECOLOR_50 // 50%
>;*/

using BaseStyle_Static = BASECOLOR;

// Basic Audio Filter, BASE / ALT color.
using BaseStyle_AudioFilter = AudioFlicker<
	RotateColorsX<Variation, BASECOLOR>,
	RotateColorsX<Variation, ALTCOLOR>
>;

// Random Flicker, BASE / ALT color
using BaseStyle_RandomFlicker = RandomFlicker<
	BASECOLOR,
	ALTCOLOR
>;

// Brownnoise BASE color
using BaseStyle_BrownNoiseFlicker = BrownNoiseFlicker<
	RotateColorsX<Variation, BASECOLOR>,
	Black,
	300
>;

// Pusling Blade
using BaseStyle_Pulsing = Pulsing<
	RotateColorsX<Variation, BASECOLOR>,
	RotateColorsX<Variation, ALTCOLOR>,
	1200
>;


// Stripes (single color)
using BaseStyle_Stripes = Stripes<
	10000,
	-1700,
	RotateColorsX<
		Variation,
		COLOR_MIX_P<33, BASECOLOR>
	>,
	RotateColorsX<
		Variation,
		BASECOLOR
	>,
	RotateColorsX<
		Variation,
		COLOR_MIX_P<50, BASECOLOR>
	>,
	RotateColorsX<
		Variation,
		COLOR_MIX_P<20, BASECOLOR>
	>,
	RotateColorsX<
		Variation,
		BASECOLOR
	>
>;

// StripesX Slow Noise (2 color)
using BaseStyle_StripesX_SlowNoise = StripesX<
	Int<1500>,
	Scale<
		SlowNoise<Int<2500>>,
		Int<-3000>,
		Int<-5000>
	>,
	BASECOLOR,
	COLOR_MIX_P<33, ALTCOLOR>,
	BASECOLOR,
	COLOR_MIX_P<8, ALTCOLOR>,
	BASECOLOR
>;

// Unstable Stripes
using BaseStyle_Stripes_RandomPerLEDFlicker = Stripes<
	3000, 
	-3500, 
	BASECOLOR, 
	RandomPerLEDFlicker<
		COLOR_MIX<Int<7710>, BASECOLOR>,
		Black
	>, 
	BrownNoiseFlicker<
		BASECOLOR,
		COLOR_MIX<Int<3855>, BASECOLOR>,
		200
	>, 
	RandomPerLEDFlicker<
		COLOR_MIX<Int<10280>, BASECOLOR>,
		COLOR_MIX<Int<3855>, BASECOLOR>
	>
>;

// Kestis style
/* // Too similar to above.
using CalKestisStyle = StripesX<
	Int<6000>,
	Scale<
		SlowNoise<Int<2000>>,
		Int<-1600>,
		Int<-3200>
	>,
	BASECOLOR,
	RandomPerLEDFlicker<
		Mix<
			Int<10280>,
			Black,
			BASECOLOR
		>,
		Mix<
			Int<1285>,
			Black,
			BASECOLOR
		>
	>,
	BrownNoiseFlicker<
		Mix<
			Int<1285>,
			Black,
			BASECOLOR
		>,
		Mix<
			Int<16448>,
			Black,
			BASECOLOR
		>,
		300
	>,
	BASECOLOR,
	RandomPerLEDFlicker<
		Black,
		Mix<
			Int<16448>,
			Black,
			BASECOLOR
		>
	>,
	BASECOLOR
>;
*/

// Fire Blade
using BaseStyle_FireBlade = StyleFire<
	BrownNoiseFlicker<
		RotateColorsX<Variation, BASECOLOR>, //0, 135, 255
		RandomPerLEDFlicker<
			RotateColorsX<
				Variation,
				COLOR_MIX<Int<3213>, BASECOLOR> //Rgb<0,0,25>  // BASE / 10.2
			>,
			RotateColorsX<
				Variation,
				COLOR_MIX<Int<7710>, BASECOLOR> //Rgb<0,0,60> // BASE / 4.25
			>
		>,
		300
	>,
	RotateColorsX<
		Variation,
		COLOR_MIX<Int<10280>, BASECOLOR> //Rgb<0,0,80> // BASE / 3.1875
	>,
	0,
	6,
	FireConfig<10,1000,2>,
	FireConfig<10,1000,2>,
	FireConfig<10,1000,2>,
	FireConfig<10,1000,2>
>;

// Thunderstorm
using BaseStyle_ThunderstormBlade = TransitionLoop<
	RotateColorsX<
		Variation,
		BASECOLOR //DeepSkyBlue // 0, 135,255
	>,
	TrConcat<
		TrBoing<500,3>,
		Layers<
			Stripes<
				10000,
				100,
				RotateColorsX<
					Variation,
					COLOR_MIX_P<50, BASECOLOR> 	//Rgb<0,40,128> // BASECOLOR / 2
				>,
				RotateColorsX<
					Variation,
					COLOR_MIX<Int<4096>, BASECOLOR> //Rgb<0,8,30> // Base Color / 8
				>,
				RotateColorsX<
					Variation,
					ALTCOLOR //Rgb<0,63,200> // Alt Color? DodgerBlue
				>
			>,
			AlphaL<
				Stripes<
					8000,
					-200,
					RotateColorsX<
						Variation,
						BASECOLOR // Base Color
					>,
					RotateColorsX<
						Variation,
						COLOR_MIX_P<25, ALTCOLOR> //Rgb<0,19,60> // Alt color / 4? DodgerBlue
					>
				>,
				Int<16384> //50%
			>
		>,
		TrDelayX< // Is this the lightning flash??
			Scale<
				SlowNoise<Int<3000>>,
				Int<100>,
				Int<2000>
			>
		>
	>
>;

// Fett263 Smoke Blade
using BaseStyle_SmokeBlade = StripesX<
	Sin<
		Int<12>,
		Int<3000>,
		Int<7000>
	>,
	Scale<
		SwingSpeed<100>,
		Int<75>,
		Int<125>
	>,
	StripesX<
		Sin<
			Int<10>,
			Int<1000>,
			Int<3000>
		>,
		Scale<
			SwingSpeed<100>,
			Int<75>,
			Int<100>
		>,
		Pulsing<
			RotateColorsX<Variation, BASECOLOR>,
			RotateColorsX<
				Variation, 
				COLOR_MIX<Int<2570>, BASECOLOR> //Rgb<15,14,0>>, // BASECOLOR / 12.75
			>,
			1200
		>,
		Mix<
			SwingSpeed<200>,
			RotateColorsX<
				Variation,
				COLOR_MIX<Int<15420>, BASECOLOR> //Rgb<90,87,0> // Mix BASECOLOR / 2.125
			>,
			Black
		>
	>,
	RotateColorsX<
		Variation,
		COLOR_MIX<Int<7710>, BASECOLOR> //Rgb<40,40,0> // BASE / 4.25
	>,
	Pulsing<
		RotateColorsX<
			Variation,
			COLOR_MIX_P<20, BASECOLOR> //Rgb<36,33,0> // BASE / 5.1
		>,
		StripesX<
			Sin<
				Int<10>,
				Int<2000>,
				Int<3000>
			>,
			Sin<
				Int<10>,
				Int<75>,
				Int<100>
			>,
			RotateColorsX<Variation, BASECOLOR>,
			RotateColorsX<
				Variation,
				COLOR_MIX<Int<12336>, BASECOLOR> //Rgb<60,58,0> // BASE / 2.65625
			>
		>,
		2000
	>,
	Pulsing<
		RotateColorsX<
			Variation,
			COLOR_MIX<Int<15420>, BASECOLOR> //Rgb<90,88,0> // BASE / 2.125
		>,
		RotateColorsX<
			Variation,
			COLOR_MIX<Int<643>, BASECOLOR> //Rgb<5,5,0> // BASE / 51
		>,
		3000
	>
>;

// Flickery Blade style
using BaseStyle_FlickerBlade = Mix<
	Scale<
		IsLessThan<
			SlowNoise<
				Int<2000>
			>, 
			Int<18000>
		>, 
		Int<0>, 
		Int<32768>
	>, 
	COLOR_GRADIENT<BASECOLOR, COLOR_MIX_P<33, BASECOLOR>>,
	Stripes<
		12000, 
		-800, 
		COLOR_GRADIENT<BASECOLOR, COLOR_MIX_P<33, BASECOLOR>>,
		COLOR_GRADIENT<BASECOLOR, COLOR_MIX_P<33, BASECOLOR>>,
		COLOR_MIX<Int<7710>, COLOR_GRADIENT<BASECOLOR, COLOR_MIX_P<33, BASECOLOR>>>,
		COLOR_GRADIENT<BASECOLOR, COLOR_MIX_P<33, BASECOLOR>>,
		COLOR_MIX<Int<16448>, COLOR_GRADIENT<BASECOLOR, COLOR_MIX_P<33, BASECOLOR>>>
	>
>;

// "Coda"
//Rotates   ^3 times per minute between BASE COLOR and ALT COLOR with subtle ALT COLOR / ALT COLOR 2 audioflicker
using CodaBladeStyle = Mix<
	Sin<Int<3>>, 
	AudioFlicker<
		RotateColorsX<
			Variation, 
			BASECOLOR //DodgerBlue //2, 72, 255 DodgerBlue // BASE COLOR
		>, 
		Stripes<
			5000, 
			-90, 
			RotateColorsX<
				Variation, 
				COLOR_MIX<Int<21845>, ALTCOLOR> //Rgb<0, 55, 165> //0, 135, 255 // DeepSkyBlue //// ALT COLOR / 1.5
			>, 
			RotateColorsX<
				Variation, 
				COLOR_MIX<Int<14894>, ALTCOLOR> //Rgb<0, 85, 115> // ALT COLOR / 2.2
			>, 
			RotateColorsX<
				Variation, 
				COLOR_MIX<Int<18725>, COLOR_MIX_P<50, BASECOLOR, ALTCOLOR>> //Rgb<0, 65, 145> // MIX BASE COLOR / ALT COLOR 50%, ALT COLOR / 1.75
			>, 
			RotateColorsX<
				Variation, 
				COLOR_MIX<Int<23206>, COLOR_MIX_P<50, BASECOLOR, ALTCOLOR>> //Rgb<0, 30, 185> // MIX BASE COLOR / ALT COLOR 50%, ALT COLOR / 1.3
			>
		>
	>, 
	AudioFlicker<
		RotateColorsX<
			Variation, 
			ALTCOLOR //Rgb<0, 155, 255> // ALT_COLOR_ARG
		>, 
		Stripes<
			5000, 
			-90, 
			RotateColorsX<
				Variation, 
				COLOR_MIX<Int<21845>, ALTCOLOR> //Rgb<0, 95, 170> // ALT COLOR / 1.5
			>, 
			RotateColorsX<
				Variation, 
				COLOR_MIX<Int<27769>, ALTCOLOR> //Rgb<0, 115, 215> // ALT COLOR / 1.18
			>,
			RotateColorsX<
				Variation, 
				COLOR_MIX<Int<18724>, ALTCOLOR2> //Rgb<0, 145, 145> //ALT_COLOR2_ARG / 1.75
			>, 
			RotateColorsX<
				Variation, 
				COLOR_MIX<Int<28998>, BASECOLOR> //Rgb<0, 65, 225> // BASE COLOR / 1.13
			>
		>
	>
>;

// DarkSaber style
using DarkSaberStyle = AudioFlicker<
	BrownNoiseFlicker<	
		Mix<
			SwingSpeed<400>, 
			BASECOLOR, 
			COLOR_MIX<Int<6425>, BASECOLOR, ALTCOLOR> //20%
		>, 
		Stripes<
			5000, 
			-300, 
			COLOR_MIX<Int<7710>, BASECOLOR>, //23%
			COLOR_MIX<Int<25700>, BASECOLOR>, //80%
			COLOR_MIX<Int<1285>, BASECOLOR>, //4%
			COLOR_MIX_P<50, BASECOLOR> //50%
		>,
		300
	>, 
	COLOR_MIX<Int<6425>, BASECOLOR, ALTCOLOR> //20%
>;

// Interactive FirePulse Style
using BaseStyle_FirePulseInteractive = Layers<
	Black,
	ColorSelect<
		IncrementWithReset<
			ThresholdPulseF<
				SwingSpeed<400>,
				Int<18000>
			>,
			Sum<
				EffectPulseF<EFFECT_CLASH>,
				EffectPulseF<EFFECT_LOCKUP_BEGIN>
			>,
			Int<1>
		>,
		TrSelect<
			IncrementWithReset<
				ThresholdPulseF<
					SwingSpeed<400>,
					Int<18000>
				>,
				Sum<
					EffectPulseF<EFFECT_CLASH>,
					EffectPulseF<EFFECT_LOCKUP_BEGIN>
				>,
				Int<1>
			>,
			TrConcat<
				TrInstant,
				COLOR_MIX_P<50, BASECOLOR, White>,
				TrSmoothFade<500>
			>,
			TrSmoothFade<600>
		>,
		AudioFlicker<
			BASECOLOR,
			COLOR_MIX_P<50, BASECOLOR>
		>,
		Layers<
			StripesX<
				Int<6000>,
				Scale<
					IncrementWithReset<
						ThresholdPulseF<
							SwingSpeed<400>,
							Int<18000>
						>,
						Sum<
							EffectPulseF<EFFECT_CLASH>,
							EffectPulseF<EFFECT_LOCKUP_BEGIN>
						>,
						Int<32000>,
						Int<2000>
					>,
					Int<-100>,
					Int<-3000>
				>,
				COLOR_MIX_P<33, BASECOLOR>,
				BASECOLOR,
				COLOR_MIX_P<50, BASECOLOR>
			>,
			AlphaL<
				RandomPerLEDFlickerL<Black>,
				IncrementWithReset<
					ThresholdPulseF<
						SwingSpeed<400>,
						Int<18000>
					>,
					Sum<
						EffectPulseF<EFFECT_CLASH>,
						EffectPulseF<EFFECT_LOCKUP_BEGIN>
					>,
					Int<30000>,
					Int<4000>
				>
			>
		>
	>
>;

// Ghost Buster
using BaseStyle_GhostBusterBlade = StaticFire<
	Mix<
		SmoothStep<
			Int<2000>,
			Int<-2000>
		>,
		Stripes<
			16000,
			-3900,
			BASECOLOR,
			COLOR_MIX_P<25, BASECOLOR>,
			COLOR_MIX_P<50, BASECOLOR>,
			Stripes<
				2500,
				-3500,
				BASECOLOR,
				BASECOLOR,
				ALTCOLOR, // Blue
				COLOR_MIX_P<50, BASECOLOR>,
				ALTCOLOR2 // DodgerBlue
			>
		>,
		White // White
	>,
	ALTCOLOR, // Blue
	0,
	6,
	1,
	2000,
	3
>;

// ElectroStaff Blade
using BaseStyle_StaffBlade = StyleFire<
	Strobe<
		RotateColorsX<Variation,BASECOLOR>, //Rgb<95,0,210>
		Strobe<
			ALTCOLOR, //Rgb<100,100,150>
			RandomPerLEDFlicker<
				RotateColorsX<Variation,BASECOLOR>, //Rgb<95,0,210>
				Black
			>,
			50,
			1
		>,
		100,
		1
	>,
	RotateColorsX<
		Variation,
		//Rgb<23,0,65> // BASECOLOR / 0.3
		COLOR_MIX<Int<16000>, BASECOLOR>
	>,
	0,
	5,
	FireConfig<2,1000,5>,
	FireConfig<2,1000,5>,
	FireConfig<2,1000,5>,
	FireConfig<2,1000,5>
>;

// Smash Blade
using BaseStyle_SmashBlade = Layers<
	StripesX<
		Sin<
			Int<4>,
			Int<3000>,
			Int<6000>
		>,
		Scale<
			TwistAngle<>,
			Int<-50>,
			Int<-100>
		>,
		StripesX<
			Sin<
				Int<3>,
				Int<1000>,
				Int<3000>
			>,
			Scale<
				TwistAngle<>,
				Int<25>,
				Int<80>
			>,
			Pulsing<
				RotateColorsX<
					Sin<Int<10>>,
					Rgb<255,50,50>
				>,
				RotateColorsX<
					Sin<Int<12>>,
					Rgb<200,0,0>
				>,
				3000
			>,
			Mix<
				Sin<Int<2>>,
				RotateColorsX<
					Sin<Int<12>>,
					Rgb<200,0,0>
				>,
				RotateColorsX<
					Sin<
						Scale<
							TwistAngle<>,
							Int<4>,
							Int<0>
						>
					>,
					Rgb<10,0,0>
				>
			>
		>,
		RotateColorsX<
			Sin<
				Scale<
					TwistAngle<>,
					Int<4>,
					Int<0>
				>
			>,
			Rgb<60,0,0>
		>,
		Pulsing<
			RotateColorsX<
				Sin<
					Scale<
						TwistAngle<>,
						Int<4>,
						Int<0>
					>
				>,
				Rgb<50,0,0>
			>,
			StripesX<
				Sin<
					Int<2>,
					Int<2000>,
					Int<4000>
				>,
				Sin<
					Int<2>,
					Int<25>,
					Int<75>
				>,
				Mix<
					Sin<Int<4>>,
					RotateColorsX<
						Sin<Int<4>>,
						Red
					>,
					RotateColorsX<
						Sin<
							Scale<
								TwistAngle<>,
								Int<14>,
								Int<2>
							>
						>,
						Rgb<255,50,50>
					>
				>,
				RotateColorsX<
					Sin<
						Scale<
							TwistAngle<>,
							Int<4>,
							Int<0>
						>
					>,
					Rgb<96,0,0>
				>
			>,
			2000
		>,
		Pulsing<
			RotateColorsX<
				Sin<
					Scale<
						TwistAngle<>,
						Int<10>,
						Int<6>
					>
				>,
				Rgb<128,0,0>
			>,
			RotateColorsX<
				Sin<
					Scale<
						TwistAngle<>,
						Int<4>,
						Int<10>
					>
				>,
				Rgb<50,0,0>
			>,
			3000
		>
	>,
	// Blade part 2?
	AlphaL<
		StripesX<
			Sin<
				Int<8>,
				Int<3000>,
				Int<6000>
			>,
			Scale<
				TwistAngle<>,
				Int<60>,
				Int<140>
			>,
			StripesX<
				Sin<
					Int<6>,
					Int<1000>,
					Int<3000>
				>,
				Scale<
					TwistAngle<>,
					Int<-25>,
					Int<-80>
				>,
				Pulsing<
					Mix<
						Sin<Int<4>>,
						RotateColorsX<
							Sin<Int<8>>,
							Red
						>,
						RotateColorsX<
							Sin<Int<6>>,
							Rgb<255,50,50>
						>
					>,
					RotateColorsX<
						Sin<
							Scale<
								TwistAngle<>,
								Int<4>,
								Int<0>
							>
						>,
						Rgb<20,0,0>
					>,
					4000
				>,
				Mix<
					Sin<Int<2>>,
					RotateColorsX<
						Sin<Int<8>>,
						Rgb<255,50,50>
					>,
					Black
				>
			>,
			RotateColorsX<
				Sin<Int<12>>,
				Rgb<60,0,0>
			>,
			Pulsing<
				RotateColorsX<
					Sin<Int<4>>,
					Rgb<50,0,0>
				>,
				StripesX<
					Sin<
						Int<2>,
						Int<2000>,
						Int<4000>
					>,
					Sin<
						Int<2>,
						Int<-25>,
						Int<-75>
					>,
					Mix<
						Sin<Int<4>>,
						RotateColorsX<
							Sin<Int<5>>,
							Red
						>,
						RotateColorsX<
							Sin<Int<16>>,
							Rgb<255,50,50>
						>
					>,
					RotateColorsX<
						Sin<Int<10>>,
						Rgb<96,0,0>
					>
				>,
				2000
			>,
			Pulsing<
				RotateColorsX<
					Sin<Int<9>>,
					Rgb<128,0,0>
				>,
				Black,
				3000
			>
		>,
		Int<10000>
	>
>;

// Party Blade
using BaseStyle_PartyBlade = StyleFire<
	StripesX<
		Int<3000>,
		Scale<
			TwistAngle<>,
			Int<-500>,
			Int<0>
		>,
		Red,
		Orange,
		Yellow,
		Green,
		Blue,
		Magenta
	>,
	StripesX<
		Int<3000>,
		Scale<
			TwistAngle<>,
			Int<-500>,
			Int<0>
		>,
		Tomato,
		OrangeRed,
		Orange,
		Yellow,
		SteelBlue,
		DeepPink
	>,
	0,
	3,
	FireConfig<0,2000,5>,
	FireConfig<0,2000,5>,
	FireConfig<0,2000,5>
>;

// Fire blade with bright tip? TODO: separate bright tip for secondary/tirtiary styles...
using BaseStyle_FireTipBlade =	Layers<
	StaticFire<
		Mix<
			SmoothStep<
				Scale<
					BladeAngle<>,
					Int<38000>,
					Int<23000>
				>,
				Int<8000>
			>,
			COLOR_MIX<Int<400>, BASECOLOR>,
			COLOR_MIX<Int<6000>, BASECOLOR>
		>,
		TRANSPARENT,
		0,
		2,
		4,
		2000,
		2
	>
>;

using BaseStyle_FireTipBase = Layers<
	StaticFire <
		StripesX<
			Int<14000>,
			Scale<
				BladeAngle<>,
				Int<-5>,
				Int<-50>
			>,
			BASECOLOR,
			Mix<
				Scale<
					HoldPeakF<
						SwingSpeed<250>,
						Int<1000>,
						Int<8000>
					>,
					Int<6000>,
					Int<16000>
				>,
				Black,
				BASECOLOR
			>
		>,
		TRANSPARENT,
		0,
		2,
		4,
		2000,
		2
	>
>;

// Water blade style
using BaseStyle_WaterBlade = StripesX<
	Scale<
		IsLessThan<
			BladeAngle<>,
			PERCENTAGE_S<50> //Int<16384>
		>,
		Scale<
			BladeAngle<>,
			Int<20000>,
			Int<10000>
		>,
		Scale<
			BladeAngle<>,
			Int<10000>,
			Int<20000>
		>
	>,
	Scale<
		BladeAngle<>,
		Int<-1000>,
		Scale<
			IsGreaterThan<
				HoldPeakF<
					SwingAcceleration<>,
					Scale<
						HoldPeakF<
							SwingAcceleration<>,
							Int<200>,
							Int<4000>
						>,
						Int<100>,
						Int<600>
					>,
					Scale<
						BladeAngle<>,
						Int<3000>,
						Int<6000>
					>
				>,
				Int<16384>
			>,
			Int<1000>,
			Int<-1000>
		>
	>,
	BASECOLOR,
	COLOR_MIX_P<50, BASECOLOR>,
	COLOR_MIX<Int<10280>, BASECOLOR>,
	COLOR_MIX<Int<25700>, BASECOLOR>,
	COLOR_MIX<Int<7710>, BASECOLOR>
>;