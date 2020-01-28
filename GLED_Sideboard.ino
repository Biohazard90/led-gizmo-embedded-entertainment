
#include <Arduino.h>
#include <ArduinoBLE.h>

#include <Adafruit_NeoPixel.h>

#include <gizmoled.h>

//void AnimateBlink(float frameTime);
void AnimateWheel(float frameTime);
void AnimateVisualizer(float frameTime);
void ConnectionFX(float frameTime, uint8_t *rgb);

//template< uint8_t vs, uint8_t vn, uint8_t ... vd >
//struct Var
//{
//	static constexpr uint8_t size = vs;
//	static constexpr uint8_t name = vn;
//	uint8_t data[] = { vd... };
//};
//
//template< uint8_t ef, Var<>... varData >
//struct Effect
//{
//	static constexpr uint8_t type = ef;
//	static constexpr uint8_t data[] = { varData... };
//};
//
//#define DECL_EFFECT(effectVarName, type, var0Name, var0) \
//	Effect<type, var0> effectVarName; \
//	uint8_t *var0Name = effectVarName::effectVarName[var0::size]
//
//DECL_EFFECT(efTest, EFFECTNAME_WHEEL, vTest, Var<5, GizmoLED::VARNAME_COLOR, 0, 0, 0>);



//#define DECL_EFFECT(effectVarName, type, var0Name, Var0) \
//	Var0 var0; \
//	template <> \
//	struct Effect ## type { \
//		uint8_t data[var0::size] = { }; \
//	} effectVarName;

//DECL_EFFECT(eff, EFFECTNAME_BLINK, asdf, DECL_VAR(5, 1))

//DECL_VAR(5)
//	Var0 var0; \


//#define MAKE_ARRAY_CONTENTS_3(a, b, c) \
//	a, b, c,
//
//
//#define DECL_VAR(vn, vs, vd) \
//	template<uint8_t vsc, uint8_t vsc2> \
//	struct vn { \
//		static constexpr uint8_t type = vsc; \
//		static constexpr uint8_t size = vsc; \
//		static constexpr uint8_t data[] = {vsc}; \
//	}; \
//	typedef vn<vs, vs> vn ## I;
//
//DECL_VAR(vColor, 5, 5);
//
//
//#define DE_EFFECT(effectVarName, type, varData, varInstance) \
//	varData; \
//	template<uint8_t ee, typename var0> \
//	struct Effect ## type { \
//		uint8_t data[var0::size] = { }; \
//	}; \
//	Effect ## type<type, varInstance> eff
//
//
//#define DE_EFFECT_O(effectVarName, type, varMixed) \
//	DE_EFFECT(effectVarName, type, varMixed);
//
////DE_EFFECT(eff, EFFECTNAME_BLINK, vColorI, DECL_VAR(vColor, 5));
//
//#define DECL_VAR_COLOR(name, r, g, b) \
//	DECL_VAR(name, 5, r), name ## I
//
//DE_EFFECT_O(eff, EFFECTNAME_BLINK, DECL_VAR_COLOR(vColor, 1, 2, 3));

//#define MAKE_EFFECT(effectVarName, var0Name, var0Type, var0ParamCount, var0Params) \
//	struct Effect { \
//		uint8_t data[1 + var0ParamCount] = { var0Type, var0Params }; \
//	} effectVarName;
//
//#define MAKE_EFFECT_O(effectVarName, packed0) \
//	MAKE_EFFECT(effectVarName, packed0)
//
//#define MAKE_VAR_COLOR(varName, r, g, b) \
//	varName, GizmoLED::VARNAME_COLOR, 3, MAKE_ARRAY_CONTENTS_3(r, g, b)
//
////MAKE_EFFECT(effect, varName, GizmoLED::VARNAME_COLOR, 3, MAKE_ARRAY_CONTENTS_3(1, 2, 3));
//MAKE_EFFECT_O(effect, MAKE_VAR_COLOR(asdf, 1, 2, 3))

//DECL_VAR(5) asdf;

//		static constexpr uint8_t data[] = { vd... }; \

/// EFFECTNAME_BLINK
//BEGIN_EFFECT_SETTINGS(EFFECTNAME_BLINK)
//DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR, 0xFF, 0, 0)
//DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_SPEED, 10, 1, 100)
//DECLARE_EFFECT_SETTINGS_CHECKBOX(GizmoLED::VARNAME_FADEIN, 0)
//DECLARE_EFFECT_SETTINGS_CHECKBOX(GizmoLED::VARNAME_FADEOUT, 0)
//DECLARE_EFFECT_SETTINGS_CHECKBOX(GizmoLED::VARNAME_RAINBOWENABLED, 0)
//DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_RAINBOWSPEED, 10, 1, 100)
//END_EFFECT_SETTINGS()
//
//DECLARE_EFFECT_VAR(blinkColor, EFFECTNAME_BLINK, 0);
//DECLARE_EFFECT_VAR(blinkSpeed, EFFECTNAME_BLINK, 5);
//DECLARE_EFFECT_VAR(blinkFadeIn, EFFECTNAME_BLINK, 10);
//DECLARE_EFFECT_VAR(blinkFadeOut, EFFECTNAME_BLINK, 13);
//DECLARE_EFFECT_VAR(blinkRainbow, EFFECTNAME_BLINK, 16);
//DECLARE_EFFECT_VAR(blinkRainbowSpeed, EFFECTNAME_BLINK, 21);
///


/// EFFECTNAME_WHEEL
//BEGIN_EFFECT_SETTINGS(EFFECTNAME_WHEEL)
//DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_BRIGHTNESS, 127, 1, 255)
//DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR, 0, 0xFF, 0)
//DECLARE_EFFECT_SETTINGS_CHECKBOX(GizmoLED::VARNAME_RAINBOWENABLED, 0)
//DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_RAINBOWSPEED, 10, 1, 100)
//END_EFFECT_SETTINGS()
//
//DECLARE_EFFECT_VAR(wheelBrightness, EFFECTNAME_WHEEL, 0);
//DECLARE_EFFECT_VAR(wheelColor, EFFECTNAME_WHEEL, 5);
///

BEGIN_EFFECT_SETTINGS(wheel, EFFECTNAME_WHEEL,
	DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR, 0, 0xFF, 0)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_BRIGHTNESS, 96, 1, 255)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_SPEED, 10, 1, 100)
DECLARE_EFFECT_SETTINGS_CHECKBOX(GizmoLED::VARNAME_RAINBOWENABLED, 0)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_RAINBOWLENGTH, 10, 1, 100)
)
EFFECT_VAR_COLOR(color)
EFFECT_VAR_SLIDER(brightness)
EFFECT_VAR_SLIDER(speed)
EFFECT_VAR_COLOR(rainbowEnabled)
EFFECT_VAR_COLOR(rainbowLength)
END_EFFECT_SETTINGS()


/// EFFECTNAME_OPAQUE
BEGIN_EFFECT_SETTINGS(opaque, EFFECTNAME_OPAQUE,
	DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR, 0xFF, 0xFF, 0xFF)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_BRIGHTNESS, 96, 1, 255)
)
EFFECT_VAR_COLOR(color)
EFFECT_VAR_SLIDER(brightness)
END_EFFECT_SETTINGS()
//END_EFFECT_SETTINGS()

//DECLARE_EFFECT_VAR(opaqueColor, EFFECTNAME_OPAQUE, 0);
//DECLARE_EFFECT_VAR(opaqueBrightness, EFFECTNAME_OPAQUE, 5);
///

BEGIN_EFFECT_SETTINGS(test, EFFECTNAME_TEST,
	DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_BRIGHTNESS, 96, 1, 255)
)
EFFECT_VAR_SLIDER(brightness)
END_EFFECT_SETTINGS()

/// EFFECTNAME_TEST
//BEGIN_EFFECT_SETTINGS(EFFECTNAME_TEST)
//DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_BRIGHTNESS, 96, 1, 255)
//END_EFFECT_SETTINGS()
//
//DECLARE_EFFECT_VAR(testBrightness, EFFECTNAME_TEST, 0);
///


/// EFFECTNAME_VISUALIZER
//BEGIN_EFFECT_SETTINGS(EFFECTNAME_VISUALIZER)
//DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR1, 0, 0, 0xFF)
//DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR2, 0, 0, 0xFF)
//END_EFFECT_SETTINGS()
//
//DECLARE_EFFECT_VAR(visualizerColor, EFFECTNAME_VISUALIZER, 0);
///


BEGIN_EFFECTS()
//DECLARE_EFFECT(opaque, AnimateOpaque, GizmoLED::EFFECTTYPE_DEFAULT)
DECLARE_EFFECT(opaque, AnimateOpaque, GizmoLED::EFFECTTYPE_DEFAULT)
DECLARE_EFFECT(wheel, AnimateWheel, GizmoLED::EFFECTTYPE_DEFAULT)
//DECLARE_EFFECT(AnimateVisualizer, EFFECTNAME_VISUALIZER, GizmoLED::EFFECTTYPE_VISUALIZER)
DECLARE_EFFECT(test, AnimateTest, GizmoLED::EFFECTTYPE_DEFAULT)
//DECLARE_EFFECT(AnimateBlink, EFFECTNAME_BLINK, GizmoLED::EFFECTTYPE_DEFAULT)
END_EFFECTS()

#define LED_PIN_SPEAKER_LEFT 3
#define LED_PIN_SPEAKER_RIGHT 4
#define LED_COUNT_SPEAKER 100

#define LED_PIN_SIDEBOARD 2
#define LED_COUNT_SIDEBOARD_BACK_TOP 14
#define LED_COUNT_SIDEBOARD_BACK_SIDE 11
#define LED_COUNT_SIDEBOARD_BOTTOM_SIDE 27
#define LED_COUNT_SIDEBOARD_BOTTOM_FRONT 164

#define LED_PIN_TV 5
#define LED_COUNT_TV_SIDE 51
#define LED_COUNT_TV_TOP 92

#define LED_BUFFER_SIZE_SPEAKER (LED_COUNT_SPEAKER)
#define LED_BUFFER_SIZE_TV (LED_COUNT_TV_SIDE * 2 + LED_COUNT_TV_TOP)
#define LED_BUFFER_SIZE_SIDEBOARD (LED_COUNT_SIDEBOARD_BACK_TOP * 2 + \
	LED_COUNT_SIDEBOARD_BACK_SIDE * 2 + \
	LED_COUNT_SIDEBOARD_BOTTOM_SIDE * 2 + \
	LED_COUNT_SIDEBOARD_BOTTOM_FRONT)

uint8_t *ledBufferSpeakerLeft;
uint8_t *ledBufferSpeakerRight;
uint8_t *ledBufferSideboard;
uint8_t *ledBufferTV;
//Adafruit_NeoPixel ledAccessSpeakerLeft(LED_COUNT_SPEAKER, LED_PIN_SPEAKER_LEFT, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ledAccessSpeakerLeft(LED_BUFFER_SIZE_SPEAKER, LED_PIN_SPEAKER_LEFT, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ledAccessSpeakerRight(LED_BUFFER_SIZE_SPEAKER, LED_PIN_SPEAKER_RIGHT, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ledAccessSideboard(LED_BUFFER_SIZE_SIDEBOARD, LED_PIN_SIDEBOARD, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ledAccessTV(LED_BUFFER_SIZE_TV, LED_PIN_TV, NEO_GRB + NEO_KHZ800);

void setup()
{
	//Serial.begin(115200);

	// LED init
	ledAccessSpeakerLeft.begin();
	ledBufferSpeakerLeft = ledAccessSpeakerLeft.getPixels();
	ledAccessSpeakerRight.begin();
	ledBufferSpeakerRight = ledAccessSpeakerRight.getPixels();
	ledAccessSideboard.begin();
	ledBufferSideboard = ledAccessSideboard.getPixels();
	ledAccessTV.begin();
	ledBufferTV = ledAccessTV.getPixels();

	GizmoLED::connectionAnimation = ConnectionFX;
	GIZMOLED_SETUP();

	//pinMode(ledPinR, OUTPUT);
	//pinMode(ledPinG, OUTPUT);
	//pinMode(ledPinB, OUTPUT);
}

void loop()
{
	GIZMOLED_LOOP();

	ledAccessSpeakerLeft.show();
	ledAccessSpeakerRight.show();
	ledAccessSideboard.show();
	ledAccessTV.show();
}

//void AnimateBlink(float frameTime)
//{
//	//digitalWrite(ledPinR, LOW);
//	//digitalWrite(ledPinG, HIGH);
//	//digitalWrite(ledPinB, HIGH);
//	//Serial.println(String("g: ") + String(blinkColor[1]));
//	if (blinkColor[0] > 127)
//		digitalWrite(ledPinR, LOW);
//	else
//		digitalWrite(ledPinR, HIGH);
//
//	if (blinkColor[1] > 127)
//		digitalWrite(ledPinG, LOW);
//	else
//		digitalWrite(ledPinG, HIGH);
//
//	if (blinkColor[2] > 127)
//		digitalWrite(ledPinB, LOW);
//	else
//		digitalWrite(ledPinB, HIGH);
//}

void AnimateOpaque(float frameTime)
{
	const float brightness = *opaqueSettings::brightness / 255.0f;
	uint8_t adjustedColor[3] =
	{
		opaqueSettings::color[0] * brightness,
		opaqueSettings::color[1] * brightness,
		opaqueSettings::color[2] * brightness,
	};

	for (int l = 0; l < LED_BUFFER_SIZE_SPEAKER; ++l)
	{
		ledBufferSpeakerLeft[l * 3] = adjustedColor[1];
		ledBufferSpeakerLeft[l * 3 + 1] = adjustedColor[0];
		ledBufferSpeakerLeft[l * 3 + 2] = adjustedColor[2];

		ledBufferSpeakerRight[l * 3] = adjustedColor[1];
		ledBufferSpeakerRight[l * 3 + 1] = adjustedColor[0];
		ledBufferSpeakerRight[l * 3 + 2] = adjustedColor[2];
	}

	for (int l = 0; l < LED_BUFFER_SIZE_SIDEBOARD; ++l)
	{
		ledBufferSideboard[l * 3] = adjustedColor[1];
		ledBufferSideboard[l * 3 + 1] = adjustedColor[0];
		ledBufferSideboard[l * 3 + 2] = adjustedColor[2];
	}

	for (int l = 0; l < LED_BUFFER_SIZE_TV; ++l)
	{
		ledBufferTV[l * 3] = adjustedColor[1];
		ledBufferTV[l * 3 + 1] = adjustedColor[0];
		ledBufferTV[l * 3 + 2] = adjustedColor[2];
	}
}

float wheelTime = 0.0f;

void AnimateWheel(float frameTime)
{
	const float brightness = *wheelSettings::brightness / 255.0f;
	uint8_t adjustedColor[3] =
	{
		wheelSettings::color[0] * brightness,
		wheelSettings::color[1] * brightness,
		wheelSettings::color[2] * brightness,
	};

	const float pos = wheelTime * (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
	wheelTime += frameTime * *wheelSettings::speed / 100.0f;
	while (wheelTime >= 1.0f)
	{
		wheelTime -= 1.0f;
	}

	if (*wheelSettings::rainbowEnabled || 1)
	{
		for (int l = 0; l < LED_BUFFER_SIZE_SIDEBOARD; ++l)
		{
			const float ledRotation = fmod(pos + l, LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
			//const float hue = huePosition / float(LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
			const float hue = abs(ledRotation / float(LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV));

			HSV2RGB(hue * 360.0f, 100, brightness * 100.0f, adjustedColor);
			ledBufferSideboard[l * 3] = adjustedColor[1];
			ledBufferSideboard[l * 3 + 1] = adjustedColor[0];
			ledBufferSideboard[l * 3 + 2] = adjustedColor[2];
		}

		for (int l = 0; l < LED_BUFFER_SIZE_TV; ++l)
		{
			const float ledRotation = fmod(pos + (LED_BUFFER_SIZE_TV - l - 1) + LED_BUFFER_SIZE_SIDEBOARD, LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
			const float hue = abs(ledRotation / float(LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV));

			HSV2RGB(hue * 360.0f, 100, brightness * 100.0f, adjustedColor);
			ledBufferTV[l * 3] = adjustedColor[1];
			ledBufferTV[l * 3 + 1] = adjustedColor[0];
			ledBufferTV[l * 3 + 2] = adjustedColor[2];
		}

		for (int l = 0; l < LED_BUFFER_SIZE_SPEAKER; ++l)
		{
			const int speakerOffset = (LED_BUFFER_SIZE_TV - l + LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_SIDEBOARD_BACK_TOP + LED_COUNT_SIDEBOARD_BOTTOM_SIDE);
			const float ledRotation = fmod(pos + speakerOffset + LED_BUFFER_SIZE_SIDEBOARD, LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
			const float hue = abs(ledRotation / float(LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV));

			HSV2RGB(hue * 360.0f, 100, brightness * 100.0f, adjustedColor);
			ledBufferSpeakerLeft[l * 3] = adjustedColor[1];
			ledBufferSpeakerLeft[l * 3 + 1] = adjustedColor[0];
			ledBufferSpeakerLeft[l * 3 + 2] = adjustedColor[2];
		}

		for (int l = 0; l < LED_BUFFER_SIZE_SPEAKER; ++l)
		{
			const int speakerOffset = (l + (LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_SIDEBOARD_BACK_TOP + LED_COUNT_SIDEBOARD_BOTTOM_SIDE + LED_COUNT_SIDEBOARD_BOTTOM_FRONT));
			const int ledRotation = fmod(pos + speakerOffset, LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
			const float hue = abs(ledRotation / float(LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV));

			HSV2RGB(hue * 360.0f, 100, brightness * 100.0f, adjustedColor);
			ledBufferSpeakerRight[l * 3] = adjustedColor[1];
			ledBufferSpeakerRight[l * 3 + 1] = adjustedColor[0];
			ledBufferSpeakerRight[l * 3 + 2] = adjustedColor[2];
		}
	}
	else
	{
		for (int l = 0; l < LED_BUFFER_SIZE_SIDEBOARD; ++l)
		{
			const int ledRotation = fmod(pos + l, LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
			const float light = abs(ledRotation - (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2) /
				float((LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2);

			ledBufferSideboard[l * 3] = adjustedColor[1] * light;
			ledBufferSideboard[l * 3 + 1] = adjustedColor[0] * light;
			ledBufferSideboard[l * 3 + 2] = adjustedColor[2] * light;
		}

		for (int l = 0; l < LED_BUFFER_SIZE_TV; ++l)
		{
			const float ledRotation = fmod(pos + (LED_BUFFER_SIZE_TV - l - 1) + LED_BUFFER_SIZE_SIDEBOARD, LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
			const float light = abs(ledRotation - (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2) /
				float((LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2);

			ledBufferTV[l * 3] = adjustedColor[1] * light;
			ledBufferTV[l * 3 + 1] = adjustedColor[0] * light;
			ledBufferTV[l * 3 + 2] = adjustedColor[2] * light;
		}

		for (int l = 0; l < LED_BUFFER_SIZE_SPEAKER; ++l)
		{
			const int speakerOffset = (LED_BUFFER_SIZE_TV - l + LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_SIDEBOARD_BACK_TOP + LED_COUNT_SIDEBOARD_BOTTOM_SIDE);
			const float ledRotation = fmod(pos + speakerOffset + LED_BUFFER_SIZE_SIDEBOARD, LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
			const float light = abs(ledRotation - (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2) /
				float((LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2);

			ledBufferSpeakerLeft[l * 3] = adjustedColor[1] * light;
			ledBufferSpeakerLeft[l * 3 + 1] = adjustedColor[0] * light;
			ledBufferSpeakerLeft[l * 3 + 2] = adjustedColor[2] * light;
		}

		for (int l = 0; l < LED_BUFFER_SIZE_SPEAKER; ++l)
		{
			const int speakerOffset = (l + (LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_SIDEBOARD_BACK_TOP + LED_COUNT_SIDEBOARD_BOTTOM_SIDE + LED_COUNT_SIDEBOARD_BOTTOM_FRONT));
			const int ledRotation = fmod(pos + speakerOffset, LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
			const float light = abs(ledRotation - (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2) /
				float((LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2);

			ledBufferSpeakerRight[l * 3] = adjustedColor[1] * light;
			ledBufferSpeakerRight[l * 3 + 1] = adjustedColor[0] * light;
			ledBufferSpeakerRight[l * 3 + 2] = adjustedColor[2] * light;
		}
	}
}

float speakerFillAmount = 0.0f;

//void AnimateVisualizer(float frameTime)
//{
//	bool audioTrigger = GizmoLED::audioData[0] > 0;
//	//if (visualizerColor[0] > 127 && audioTrigger)
//	//	digitalWrite(ledPinR, LOW);
//	//else
//	//	digitalWrite(ledPinR, HIGH);
//
//	//if (visualizerColor[1] > 127 && audioTrigger)
//	//	digitalWrite(ledPinG, LOW);
//	//else
//	//	digitalWrite(ledPinG, HIGH);
//
//	//if (visualizerColor[2] > 127 && audioTrigger)
//	//	digitalWrite(ledPinB, LOW);
//	//else
//	//	digitalWrite(ledPinB, HIGH);
//
//	float speakerFillDesired = audioTrigger ? 1.0f : 0.0f;
//	float speakerMaxAdjust = min(abs(speakerFillDesired - speakerFillAmount), frameTime * 5.0f);
//	if (speakerFillAmount != speakerFillDesired)
//		speakerFillAmount += (speakerFillDesired > speakerFillAmount) ? speakerMaxAdjust : -speakerMaxAdjust;
//
//	for (int l = 0; l < LED_BUFFER_SIZE_SPEAKER; ++l)
//	{
//		float fillPercent = l / float(LED_BUFFER_SIZE_SPEAKER);
//		if (fillPercent < speakerFillAmount)
//		{
//			ledBufferSpeakerLeft[l * 3] = visualizerColor[1];
//			ledBufferSpeakerLeft[l * 3 + 1] = visualizerColor[0];
//			ledBufferSpeakerLeft[l * 3 + 2] = visualizerColor[2];
//
//			ledBufferSpeakerRight[l * 3] = visualizerColor[1];
//			ledBufferSpeakerRight[l * 3 + 1] = visualizerColor[0];
//			ledBufferSpeakerRight[l * 3 + 2] = visualizerColor[2];
//		}
//		else
//		{
//			ledBufferSpeakerLeft[l * 3] = 0;
//			ledBufferSpeakerLeft[l * 3 + 1] = 0;
//			ledBufferSpeakerLeft[l * 3 + 2] = 0;
//
//			ledBufferSpeakerRight[l * 3] = 0;
//			ledBufferSpeakerRight[l * 3 + 1] = 0;
//			ledBufferSpeakerRight[l * 3 + 2] = 0;
//		}
//	}
//
//	for (int l = 0; l < LED_BUFFER_SIZE_TV; ++l)
//	{
//		ledBufferTV[l * 3] = 0;
//		ledBufferTV[l * 3 + 1] = 0;
//		ledBufferTV[l * 3 + 2] = 0;
//	}
//
//	for (int l = 0; l < LED_BUFFER_SIZE_SIDEBOARD; ++l)
//	{
//		ledBufferSideboard[l * 3] = 0;
//		ledBufferSideboard[l * 3 + 1] = 0;
//		ledBufferSideboard[l * 3 + 2] = 0;
//	}
//}

void AnimateTest(float frameTime)
{
	uint8_t b = *testSettings::brightness;
	int sideboard = 0;
	int tv = 0;

	// SPEAKER
	for (int l = 0; l < LED_COUNT_SPEAKER; ++l)
	{
		ledBufferSpeakerLeft[l * 3] = 0;
		ledBufferSpeakerLeft[l * 3 + 1] = b;
		ledBufferSpeakerLeft[l * 3 + 2] = 0;

		ledBufferSpeakerRight[l * 3] = b;
		ledBufferSpeakerRight[l * 3 + 1] = 0;
		ledBufferSpeakerRight[l * 3 + 2] = 0;
	}

	// SIDEBOARD
	for (int l = 0; l < LED_COUNT_SIDEBOARD_BACK_TOP; ++l)
	{
		ledBufferSideboard[sideboard * 3] = 0;
		ledBufferSideboard[sideboard * 3 + 1] = b;
		ledBufferSideboard[sideboard * 3 + 2] = 0;
		++sideboard;
	}
	for (int l = 0; l < LED_COUNT_SIDEBOARD_BACK_SIDE; ++l)
	{
		ledBufferSideboard[sideboard * 3] = b;
		ledBufferSideboard[sideboard * 3 + 1] = 0;
		ledBufferSideboard[sideboard * 3 + 2] = 0;
		++sideboard;
	}
	for (int l = 0; l < LED_COUNT_SIDEBOARD_BOTTOM_SIDE; ++l)
	{
		ledBufferSideboard[sideboard * 3] = 0;
		ledBufferSideboard[sideboard * 3 + 1] = 0;
		ledBufferSideboard[sideboard * 3 + 2] = b;
		++sideboard;
	}
	for (int l = 0; l < LED_COUNT_SIDEBOARD_BOTTOM_FRONT; ++l)
	{
		ledBufferSideboard[sideboard * 3] = 0;
		ledBufferSideboard[sideboard * 3 + 1] = b;
		ledBufferSideboard[sideboard * 3 + 2] = 0;
		++sideboard;
	}
	for (int l = 0; l < LED_COUNT_SIDEBOARD_BOTTOM_SIDE; ++l)
	{
		ledBufferSideboard[sideboard * 3] = b;
		ledBufferSideboard[sideboard * 3 + 1] = 0;
		ledBufferSideboard[sideboard * 3 + 2] = 0;
		++sideboard;
	}
	for (int l = 0; l < LED_COUNT_SIDEBOARD_BACK_SIDE; ++l)
	{
		ledBufferSideboard[sideboard * 3] = 0;
		ledBufferSideboard[sideboard * 3 + 1] = 0;
		ledBufferSideboard[sideboard * 3 + 2] = b;
		++sideboard;
	}
	for (int l = 0; l < LED_COUNT_SIDEBOARD_BACK_TOP; ++l)
	{
		ledBufferSideboard[sideboard * 3] = 0;
		ledBufferSideboard[sideboard * 3 + 1] = b;
		ledBufferSideboard[sideboard * 3 + 2] = 0;
		++sideboard;
	}


	// TV
	for (int l = 0; l < LED_COUNT_TV_SIDE; ++l)
	{
		ledBufferTV[tv * 3] = 0;
		ledBufferTV[tv * 3 + 1] = b;
		ledBufferTV[tv * 3 + 2] = 0;
		++tv;
	}
	for (int l = 0; l < LED_COUNT_TV_TOP; ++l)
	{
		ledBufferTV[tv * 3] = b;
		ledBufferTV[tv * 3 + 1] = 0;
		ledBufferTV[tv * 3 + 2] = 0;
		++tv;
	}
	for (int l = 0; l < LED_COUNT_TV_SIDE; ++l)
	{
		ledBufferTV[tv * 3] = 0;
		ledBufferTV[tv * 3 + 1] = 0;
		ledBufferTV[tv * 3 + 2] = b;
		++tv;
	}
}

void ConnectionFX(float frameTime, uint8_t *rgb)
{
	//if (rgb[0] > 127)
	//	digitalWrite(ledPinR, LOW);
	//else
	//	digitalWrite(ledPinR, HIGH);

	//if (rgb[1] > 127)
	//	digitalWrite(ledPinG, LOW);
	//else
	//	digitalWrite(ledPinG, HIGH);

	//if (rgb[2] > 127)
	//	digitalWrite(ledPinB, LOW);
	//else
	//	digitalWrite(ledPinB, HIGH);
}

