// ===================================== BUTTONS ==================================

// Button Glow FX.
using ButtonStyle_Glowing = Layers<
	White,
	InOutTrL<
		TrInstant, 
		TrInstant, 
		Pulsing<
			Black, 
			White,
			8000
		>
	>,

	// Power Saver
	Battery_Power_Save
>;