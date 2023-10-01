// ===================== BLADE STYLES 2 =======================
// Using ALTCOLOR and ALTCOLOR2

// Pusling Blade
using Style2_Pulsing_Rotate = Pulsing<
	TRANSPARENT,
	RotateColorsX<Variation, ALTCOLOR2>,
	1200
>;

// Hump Waves (2 Color)
using Style2_HumpWave = Layers <
	TransitionLoopL<
		TrWaveX<
			HumpFlickerL<RotateColorsX<Variation, ALTCOLOR>, 40>,
			Int<250>,
			Int<100>,
			Int<200>,
			Int<0>
		>
	>,
	TransitionLoopL<
		TrWaveX<
			HumpFlickerL<RotateColorsX<Variation, ALTCOLOR2>, 40>,
			Int<350>,
			Int<100>,
			Int<300>,
			Int<0>
		>
	>
>;

// RandomPerLEDFlicker (2 Color)
using Style2_RandomPerLEDFlicker = RandomPerLEDFlicker<
	Mix<
		Int<10280>, 
		Black, 
		ALTCOLOR
	>, 
	Mix<
		Int<3855>, 
		Black, 
		ALTCOLOR2
	>
>;

// Fett263 Smoke Blade Fire layer, ALT Color
using Style2_FireBlade = AlphaL <
	StyleFire<
		RotateColorsX<Variation, ALTCOLOR2>,
		RotateColorsX<
			Variation,
			//Rgb<2,2,0> // ALT / 127.5
			Mix<
				Int<257>,
				Black,
				ALTCOLOR2
			>
		>,
		0,
		1,
		FireConfig<10,2000,2>,
		FireConfig<10,2000,2>,
		FireConfig<10,2000,2>,
		FireConfig<0,0,25>
	>,
	Int<10000>
>;

// StripesX Slownoise
using Style2_StripesX_SlowNoise = StripesX<
	Int<1500>,
	Scale<
		SlowNoise<Int<2500>>,
		Int<-3000>,
		Int<-5000>
	>,
	Black,
	Mix<
		Int<10280>,
		Black,
		ALTCOLOR2
	>,
	Black,
	Mix<
		Int<2570>,
		Black,
		ALTCOLOR2
	>,
	Black
>;


// Brown Noise with Stripes, ALTCOLOR2
using Style2_BrownNoiseFlicker = BrownNoiseFlicker<
	TRANSPARENT,
	Stripes<
		3000, 
		-4000, 
		//Rgb<50, 50, 75>, // ALT COLOR / 3.4
		Mix<
			Int<9638>,
			Black, 
			ALTCOLOR2
		>,
		//Rgb<100, 100, 150>, // ALT COLOR / 1.7
		Mix<
			Int<19275>,
			Black, 
			ALTCOLOR2
		>,
		//Rgb<10, 10, 15>, // ALT COLOR / 17
		Mix<
			Int<1928>,
			Black, 
			ALTCOLOR2
		>,
		//Rgb<150, 150, 225> // ALT COLOR
		ALTCOLOR2
	>, 
	200
>;

// Thunderstorm ???
using Style2_LightningFlash = TransitionLoop<
	RotateColorsX<
		Variation,
		ALTCOLOR2
	>,
	TrConcat<
		TrBoing<500,3>,
		TRANSPARENT,
		/*
		Layers<
			Stripes<
				10000,
				100,
				RotateColorsX<
					Variation,
					BASECOLOR_50
				>,
				RotateColorsX<
					Variation,
					Mix<
						Int<4096>, //12.5%
						Black, 
						BASECOLOR
					>
				>,
				RotateColorsX<
					Variation,
					ALTCOLOR3
				>
			>,
			AlphaL<
				Stripes<
					8000,
					-200,
					RotateColorsX<
						Variation,
						BASECOLOR
					>,
					RotateColorsX<
						Variation,
						ALTCOLOR_25
					>
				>,
				Int<16384> //50%
			>
		>,
		*/
		TrDelayX< // Random Timer
			Scale<
				SlowNoise<Int<3000>>,
				Int<100>,
				Int<2000>
			>
		>
	>
>;
