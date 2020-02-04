
#include <Arduino.h>
#include <ArduinoBLE.h>

#include <Adafruit_NeoPixel.h>

#include <gizmoled.h>

void ConnectionFX(float frameTime, uint8_t *rgb);

/// WHEEL
BEGIN_EFFECT_SETTINGS(wheel, EFFECTNAME_WHEEL,
	DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR, 0, 0xFF, 0)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_BRIGHTNESS, 96, 1, 255)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_SPEED, 10, 1, 100)
DECLARE_EFFECT_SETTINGS_CHECKBOX(GizmoLED::VARNAME_RAINBOWENABLED, 1)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_RAINBOWLENGTH, 10, 1, 100)
)
EFFECT_VAR_COLOR(color)
EFFECT_VAR_SLIDER(brightness)
EFFECT_VAR_SLIDER(speed)
EFFECT_VAR_CHECKBOX(rainbowEnabled)
EFFECT_VAR_COLOR(rainbowLength)
END_EFFECT_SETTINGS()

/// OPAQUE
BEGIN_EFFECT_SETTINGS(opaque, EFFECTNAME_OPAQUE,
	DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR, 0xFF, 0xFF, 0xFF)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_BRIGHTNESS, 96, 1, 255)
DECLARE_EFFECT_SETTINGS_CHECKBOX(GizmoLED::VARNAME_RAINBOWENABLED, 1)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_RAINBOWSPEED, 10, 1, 100)
)
EFFECT_VAR_COLOR(color)
EFFECT_VAR_SLIDER(brightness)
EFFECT_VAR_CHECKBOX(rainbowEnabled)
EFFECT_VAR_SLIDER(rainbowSpeed)
END_EFFECT_SETTINGS()

/// GRADIENT
BEGIN_EFFECT_SETTINGS(gradient, EFFECTNAME_GRADIENT,
	DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR1, 0xFF, 0, 0)
DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR2, 0, 0, 0xFF)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_BRIGHTNESS, 96, 1, 255)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_ANGLE, 0, 0, 100)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_SPEED, 0, 0, 100)
)
EFFECT_VAR_COLOR(color1)
EFFECT_VAR_COLOR(color2)
EFFECT_VAR_SLIDER(brightness)
EFFECT_VAR_SLIDER(angle)
EFFECT_VAR_SLIDER(speed)
END_EFFECT_SETTINGS()

/// TEST
BEGIN_EFFECT_SETTINGS(test, EFFECTNAME_TEST,
	DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_BRIGHTNESS, 96, 1, 255)
)
EFFECT_VAR_SLIDER(brightness)
END_EFFECT_SETTINGS()

/// VISUALIZER
BEGIN_EFFECT_SETTINGS(visualizer, EFFECTNAME_VISUALIZER,
	DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_BRIGHTNESS, 255, 1, 255)
DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR1, 0xFF, 0, 0)
DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR2, 0, 0, 0xFF)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_SPEED, 8, 1, 20)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_DECAY, 50, 1, 100)
DECLARE_EFFECT_SETTINGS_CHECKBOX(GizmoLED::VARNAME_RAINBOWENABLED, 1)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_RAINBOWSPEED, 10, 1, 100)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_RAINBOWLENGTH, 40, 1, 100)
)
EFFECT_VAR_SLIDER(brightness)
EFFECT_VAR_COLOR(color1)
EFFECT_VAR_COLOR(color2)
EFFECT_VAR_SLIDER(speed)
EFFECT_VAR_SLIDER(decay)
EFFECT_VAR_CHECKBOX(rainbowEnabled)
EFFECT_VAR_SLIDER(rainbowSpeed)
EFFECT_VAR_SLIDER(rainbowLength)
END_EFFECT_SETTINGS()

/// PULSE
BEGIN_EFFECT_SETTINGS(pulse, EFFECTNAME_PULSE,
	DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_BRIGHTNESS, 96, 1, 255)
DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR1, 0xFF, 0, 0)
DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR2, 0xFF, 0xFF, 0xFF)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_SPEED, 10, 1, 60)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_LENGTH, 10, 1, 100)
DECLARE_EFFECT_SETTINGS_CHECKBOX(GizmoLED::VARNAME_FADEOUT, 0)
DECLARE_EFFECT_SETTINGS_CHECKBOX(GizmoLED::VARNAME_RAINBOWENABLED, 1)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_RAINBOWLENGTH, 30, 1, 60)
)
EFFECT_VAR_SLIDER(brightness)
EFFECT_VAR_COLOR(color1)
EFFECT_VAR_COLOR(color2)
EFFECT_VAR_SLIDER(speed)
EFFECT_VAR_SLIDER(length)
EFFECT_VAR_CHECKBOX(fadeOut)
EFFECT_VAR_CHECKBOX(rainbowEnabled)
EFFECT_VAR_SLIDER(rainbowLength)
END_EFFECT_SETTINGS()

/// SPARKLE
BEGIN_EFFECT_SETTINGS(sparkle, EFFECTNAME_SPARKLE,
	DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_BRIGHTNESS, 96, 1, 255)
DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR, 0xFF, 0, 0)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_DECAY, 10, 1, 100)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_LENGTH, 10, 1, 100)
DECLARE_EFFECT_SETTINGS_CHECKBOX(GizmoLED::VARNAME_RAINBOWENABLED, 1)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_RAINBOWSPEED, 10, 1, 100)
)
EFFECT_VAR_SLIDER(brightness)
EFFECT_VAR_COLOR(color)
EFFECT_VAR_SLIDER(decay)
EFFECT_VAR_SLIDER(length)
EFFECT_VAR_CHECKBOX(rainbowEnabled)
EFFECT_VAR_SLIDER(rainbowSpeed)
END_EFFECT_SETTINGS()


BEGIN_EFFECTS()
//DECLARE_EFFECT(opaque, AnimateOpaque, GizmoLED::EFFECTTYPE_DEFAULT)
DECLARE_EFFECT(opaque, AnimateOpaque, GizmoLED::EFFECTTYPE_DEFAULT)
DECLARE_EFFECT(gradient, AnimateGradient, GizmoLED::EFFECTTYPE_DEFAULT)
DECLARE_EFFECT(wheel, AnimateWheel, GizmoLED::EFFECTTYPE_DEFAULT)
DECLARE_EFFECT(pulse, AnimatePulse, GizmoLED::EFFECTTYPE_DEFAULT)
DECLARE_EFFECT(sparkle, AnimateSparkle, GizmoLED::EFFECTTYPE_DEFAULT)
DECLARE_EFFECT(visualizer, AnimateVisualizer, GizmoLED::EFFECTTYPE_VISUALIZER)
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

#define ADD_CLAMPED_COLOR(buffer, position, additiveColor, factor) \
					{buffer[(position) * 3] = min(255, buffer[(position) * 3] + additiveColor[1] * (factor)); \
					buffer[(position) * 3 + 1] = min(255, buffer[(position) * 3 + 1] + additiveColor[0] * (factor)); \
					buffer[(position) * 3 + 2] = min(255, buffer[(position) * 3 + 2] + additiveColor[2] * (factor));}

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

float opaqueRainbow = 0.0f;

void AnimateOpaque(float frameTime)
{
	const float brightness = *opaqueSettings::brightness / 255.0f;
	uint8_t adjustedColor[3] =
	{
		opaqueSettings::color[0] * brightness,
		opaqueSettings::color[1] * brightness,
		opaqueSettings::color[2] * brightness,
	};

	if (*opaqueSettings::rainbowEnabled != 0)
	{
		HSV2RGB(opaqueRainbow, 100.0f, brightness * 100.0f, adjustedColor);
		opaqueRainbow += *opaqueSettings::rainbowSpeed * frameTime;
		while (opaqueRainbow >= 360.0f)
		{
			opaqueRainbow -= 360.0f;
		}
	}

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

float gradientTime = 0.0f;

void AnimateGradient(float frameTime)
{
	const float brightness = *gradientSettings::brightness / 255.0f;
	uint8_t adjustedColor1[3] =
	{
		gradientSettings::color1[0] * brightness,
		gradientSettings::color1[1] * brightness,
		gradientSettings::color1[2] * brightness,
	};
	uint8_t adjustedColor2[3] =
	{
		gradientSettings::color2[0] * brightness,
		gradientSettings::color2[1] * brightness,
		gradientSettings::color2[2] * brightness,
	};
	int adjustedColorD[3] =
	{
		adjustedColor2[0] - adjustedColor1[0],
		adjustedColor2[1] - adjustedColor1[1],
		adjustedColor2[2] - adjustedColor1[2],
	};

	const float gradientSpeed = *gradientSettings::speed / 100.0f;
	if (gradientSpeed == 0.0f)
	{
		gradientTime = *gradientSettings::angle / 100.0f;
	}
	const float pos = gradientTime * (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
	gradientTime += frameTime * gradientSpeed;
	while (gradientTime >= 1.0f)
	{
		gradientTime -= 1.0f;
	}

	for (int l = 0; l < LED_BUFFER_SIZE_SIDEBOARD; ++l)
	{
		const int ledRotation = fmod(pos + l, LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
		const float light = abs(ledRotation - (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2) /
			float((LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2);

		ledBufferSideboard[l * 3] = adjustedColor1[1] + adjustedColorD[1] * light;
		ledBufferSideboard[l * 3 + 1] = adjustedColor1[0] + adjustedColorD[0] * light;
		ledBufferSideboard[l * 3 + 2] = adjustedColor1[2] + adjustedColorD[2] * light;
	}

	for (int l = 0; l < LED_BUFFER_SIZE_TV; ++l)
	{
		const float ledRotation = fmod(pos + (LED_BUFFER_SIZE_TV - l - 1) + LED_BUFFER_SIZE_SIDEBOARD, LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
		const float light = abs(ledRotation - (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2) /
			float((LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2);

		ledBufferTV[l * 3] = adjustedColor1[1] + adjustedColorD[1] * light;
		ledBufferTV[l * 3 + 1] = adjustedColor1[0] + adjustedColorD[0] * light;
		ledBufferTV[l * 3 + 2] = adjustedColor1[2] + adjustedColorD[2] * light;
	}

	for (int l = 0; l < LED_BUFFER_SIZE_SPEAKER; ++l)
	{
		const int speakerOffset = (LED_BUFFER_SIZE_TV - l + LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_SIDEBOARD_BACK_TOP + LED_COUNT_SIDEBOARD_BOTTOM_SIDE);
		const float ledRotation = fmod(pos + speakerOffset + LED_BUFFER_SIZE_SIDEBOARD, LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
		const float light = abs(ledRotation - (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2) /
			float((LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2);

		ledBufferSpeakerLeft[l * 3] = adjustedColor1[1] + adjustedColorD[1] * light;
		ledBufferSpeakerLeft[l * 3 + 1] = adjustedColor1[0] + adjustedColorD[0] * light;
		ledBufferSpeakerLeft[l * 3 + 2] = adjustedColor1[2] + adjustedColorD[2] * light;
	}

	for (int l = 0; l < LED_BUFFER_SIZE_SPEAKER; ++l)
	{
		const int speakerOffset = (l + (LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_SIDEBOARD_BACK_TOP + LED_COUNT_SIDEBOARD_BOTTOM_SIDE + LED_COUNT_SIDEBOARD_BOTTOM_FRONT));
		const int ledRotation = fmod(pos + speakerOffset, LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
		const float light = abs(ledRotation - (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2) /
			float((LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2);

		ledBufferSpeakerRight[l * 3] = adjustedColor1[1] + adjustedColorD[1] * light;
		ledBufferSpeakerRight[l * 3 + 1] = adjustedColor1[0] + adjustedColorD[0] * light;
		ledBufferSpeakerRight[l * 3 + 2] = adjustedColor1[2] + adjustedColorD[2] * light;
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

	if (*wheelSettings::rainbowEnabled != 0)
	{
		for (int l = 0; l < LED_BUFFER_SIZE_SIDEBOARD; ++l)
		{
			const float ledRotation = fmod(pos + l, LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
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

			ledBufferSideboard[l * 3] = adjustedColor[1] * light * light;
			ledBufferSideboard[l * 3 + 1] = adjustedColor[0] * light * light;
			ledBufferSideboard[l * 3 + 2] = adjustedColor[2] * light * light;
		}

		for (int l = 0; l < LED_BUFFER_SIZE_TV; ++l)
		{
			const float ledRotation = fmod(pos + (LED_BUFFER_SIZE_TV - l - 1) + LED_BUFFER_SIZE_SIDEBOARD, LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
			const float light = abs(ledRotation - (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2) /
				float((LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2);

			ledBufferTV[l * 3] = adjustedColor[1] * light * light;
			ledBufferTV[l * 3 + 1] = adjustedColor[0] * light * light;
			ledBufferTV[l * 3 + 2] = adjustedColor[2] * light * light;
		}

		for (int l = 0; l < LED_BUFFER_SIZE_SPEAKER; ++l)
		{
			const int speakerOffset = (LED_BUFFER_SIZE_TV - l + LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_SIDEBOARD_BACK_TOP + LED_COUNT_SIDEBOARD_BOTTOM_SIDE);
			const float ledRotation = fmod(pos + speakerOffset + LED_BUFFER_SIZE_SIDEBOARD, LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
			const float light = abs(ledRotation - (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2) /
				float((LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2);

			ledBufferSpeakerLeft[l * 3] = adjustedColor[1] * light * light;
			ledBufferSpeakerLeft[l * 3 + 1] = adjustedColor[0] * light * light;
			ledBufferSpeakerLeft[l * 3 + 2] = adjustedColor[2] * light * light;
		}

		for (int l = 0; l < LED_BUFFER_SIZE_SPEAKER; ++l)
		{
			const int speakerOffset = (l + (LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_SIDEBOARD_BACK_TOP + LED_COUNT_SIDEBOARD_BOTTOM_SIDE + LED_COUNT_SIDEBOARD_BOTTOM_FRONT));
			const int ledRotation = fmod(pos + speakerOffset, LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
			const float light = abs(ledRotation - (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2) /
				float((LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV) / 2);

			ledBufferSpeakerRight[l * 3] = adjustedColor[1] * light * light;
			ledBufferSpeakerRight[l * 3 + 1] = adjustedColor[0] * light * light;
			ledBufferSpeakerRight[l * 3 + 2] = adjustedColor[2] * light * light;
		}
	}
}

float visualizerSpeakerFillAmount = 0.0f;

//const int sparkleCount = NUM_AUDIO_POINTS - 1;
//float visualizerSparkleTimers[sparkleCount] = { 0.0f };
//int visualizerSparklePositions[sparkleCount] = { 0 };
//#define SPARKLE_TIME 1.2f
//#define SPARKLE_FADE_IN 0.2f

const int beatCount = NUM_AUDIO_POINTS - 1;
float beatTimers[beatCount] = { 0.0f };
#define BEAT_TIME 1.2f
#define BEAT_FADE_IN 0.2f

float beatRainbowHue = 0.0f;

void AnimateVisualizer(float frameTime)
{
	bool audioTrigger = GizmoLED::audioData[0] > 0;

	float speakerFillDesired = audioTrigger ? 1.0f : 0.0f;
	float speakerMaxAdjust = min(abs(speakerFillDesired - visualizerSpeakerFillAmount), frameTime * *visualizerSettings::speed);
	if (visualizerSpeakerFillAmount != speakerFillDesired)
		visualizerSpeakerFillAmount += (speakerFillDesired > visualizerSpeakerFillAmount) ? speakerMaxAdjust : -speakerMaxAdjust;

	const float brightness = *visualizerSettings::brightness / 255.0f;
	uint8_t adjustedColor0[] =
	{
		visualizerSettings::color1[0] * brightness,
		visualizerSettings::color1[1] * brightness,
		visualizerSettings::color1[2] * brightness
	};
	uint8_t adjustedColor1[] =
	{
		visualizerSettings::color2[0] * brightness,
		visualizerSettings::color2[1] * brightness,
		visualizerSettings::color2[2] * brightness
	};
	uint8_t adjustedColor2[] = { adjustedColor1[0], adjustedColor1[1], adjustedColor1[2] };
	uint8_t adjustedColor3[] = { adjustedColor1[0], adjustedColor1[1], adjustedColor1[2] };
	uint8_t adjustedColor4[] = { adjustedColor1[0], adjustedColor1[1], adjustedColor1[2] };
	uint8_t adjustedColor5[] = { adjustedColor1[0], adjustedColor1[1], adjustedColor1[2] };

	if (*visualizerSettings::rainbowEnabled)
	{
		beatRainbowHue += frameTime * *visualizerSettings::rainbowSpeed;
		while (beatRainbowHue >= 360.0f)
		{
			beatRainbowHue -= 360.0f;
		}

		HSV2RGB(beatRainbowHue, 100.0f, brightness * 100.0f, adjustedColor0);

		const float rainbowLength = *visualizerSettings::rainbowLength;
		HSV2RGB(fmod(beatRainbowHue + 180.0f - rainbowLength, 360.0f), 100.0f, brightness * 100.0f, adjustedColor1);
		HSV2RGB(fmod(beatRainbowHue + 180.0f - rainbowLength * 0.5f, 360.0f), 100.0f, brightness * 100.0f, adjustedColor2);
		HSV2RGB(fmod(beatRainbowHue + 180.0f, 360.0f), 100.0f, brightness * 100.0f, adjustedColor3);
		HSV2RGB(fmod(beatRainbowHue + 180.0f + rainbowLength * 0.5f, 360.0f), 100.0f, brightness * 100.0f, adjustedColor4);
		HSV2RGB(fmod(beatRainbowHue + 180.0f + rainbowLength, 360.0f), 100.0f, brightness * 100.0f, adjustedColor5);
	}

	// Speaker fill
	for (int l = 0; l < LED_BUFFER_SIZE_SPEAKER; ++l)
	{
		float fillPercent = l / float(LED_BUFFER_SIZE_SPEAKER);
		if (fillPercent < visualizerSpeakerFillAmount)
		{
			ledBufferSpeakerLeft[l * 3] = adjustedColor0[1];
			ledBufferSpeakerLeft[l * 3 + 1] = adjustedColor0[0];
			ledBufferSpeakerLeft[l * 3 + 2] = adjustedColor0[2];

			ledBufferSpeakerRight[l * 3] = adjustedColor0[1];
			ledBufferSpeakerRight[l * 3 + 1] = adjustedColor0[0];
			ledBufferSpeakerRight[l * 3 + 2] = adjustedColor0[2];
		}
		else
		{
			ledBufferSpeakerLeft[l * 3] = 0;
			ledBufferSpeakerLeft[l * 3 + 1] = 0;
			ledBufferSpeakerLeft[l * 3 + 2] = 0;

			ledBufferSpeakerRight[l * 3] = 0;
			ledBufferSpeakerRight[l * 3 + 1] = 0;
			ledBufferSpeakerRight[l * 3 + 2] = 0;
		}
	}

	// Clear sideboard and TV
	for (int l = 0; l < LED_BUFFER_SIZE_TV; ++l)
	{
		ledBufferTV[l * 3] = 0;
		ledBufferTV[l * 3 + 1] = 0;
		ledBufferTV[l * 3 + 2] = 0;
	}

	for (int l = 0; l < LED_BUFFER_SIZE_SIDEBOARD; ++l)
	{
		ledBufferSideboard[l * 3] = 0;
		ledBufferSideboard[l * 3 + 1] = 0;
		ledBufferSideboard[l * 3 + 2] = 0;
	}

	// Sideboard lower blend
	uint8_t *writeBassSideboard = ledBufferSideboard + (LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_SIDEBOARD_BACK_TOP) * 3;
	for (int l = 0; l < LED_COUNT_SIDEBOARD_BOTTOM_SIDE * 2 + LED_COUNT_SIDEBOARD_BOTTOM_FRONT; ++l)
	{
		const float blendPercent = abs(l - LED_COUNT_SIDEBOARD_BOTTOM_SIDE - LED_COUNT_SIDEBOARD_BOTTOM_FRONT / 2) /
			float(LED_COUNT_SIDEBOARD_BOTTOM_SIDE + LED_COUNT_SIDEBOARD_BOTTOM_FRONT / 2);
		writeBassSideboard[0] = adjustedColor0[1] * blendPercent * visualizerSpeakerFillAmount;
		writeBassSideboard[1] = adjustedColor0[0] * blendPercent * visualizerSpeakerFillAmount;
		writeBassSideboard[2] = adjustedColor0[2] * blendPercent * visualizerSpeakerFillAmount;
		writeBassSideboard += 3;
	}

	const float beatDecay = *visualizerSettings::decay / 100.0f * 10.0f;
	for (int i = 0; i < beatCount; ++i)
	{
		// Induce new beat
		if (GizmoLED::audioData[1 + i] > 0.0f &&
			beatTimers[i] <= 0.0f)
		{
			beatTimers[i] = BEAT_TIME;
		}

		if (beatTimers[i] > 0.0f)
		{
			beatTimers[i] -= frameTime * beatDecay;
			float beatLight = beatTimers[i];
			if (beatLight > 1.0f)
				beatLight = 1.0f - (beatLight - 1.0f) / BEAT_FADE_IN;

			switch (i)
			{
			case 0:
			{
				uint8_t *writeBeatSideboard = ledBufferSideboard + (LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_SIDEBOARD_BACK_TOP) * 3;
				for (int l = 0; l < LED_COUNT_SIDEBOARD_BOTTOM_SIDE * 2 + LED_COUNT_SIDEBOARD_BOTTOM_FRONT; ++l)
				{
					const float blendPercent = 1.0f - abs(l - LED_COUNT_SIDEBOARD_BOTTOM_SIDE - LED_COUNT_SIDEBOARD_BOTTOM_FRONT / 2) /
						float(LED_COUNT_SIDEBOARD_BOTTOM_SIDE + LED_COUNT_SIDEBOARD_BOTTOM_FRONT / 2);

					ADD_CLAMPED_COLOR(writeBeatSideboard, l, adjustedColor1, blendPercent * beatLight);
				}
			}
			break;

			case 1:
			{
				for (int l = LED_COUNT_SIDEBOARD_BACK_TOP; l < LED_COUNT_SIDEBOARD_BACK_TOP + LED_COUNT_SIDEBOARD_BACK_SIDE; ++l)
					ADD_CLAMPED_COLOR(ledBufferSideboard, l, adjustedColor2, beatLight);

				for (int l = LED_BUFFER_SIZE_SIDEBOARD - LED_COUNT_SIDEBOARD_BACK_TOP - LED_COUNT_SIDEBOARD_BACK_SIDE; l < LED_BUFFER_SIZE_SIDEBOARD - LED_COUNT_SIDEBOARD_BACK_TOP; ++l)
					ADD_CLAMPED_COLOR(ledBufferSideboard, l, adjustedColor2, beatLight);
			}
			break;

			case 2:
			{
				for (int l = 0; l < LED_COUNT_SIDEBOARD_BACK_TOP; ++l)
					ADD_CLAMPED_COLOR(ledBufferSideboard, l, adjustedColor3, beatLight);

				for (int l = LED_BUFFER_SIZE_SIDEBOARD - LED_COUNT_SIDEBOARD_BACK_TOP; l < LED_BUFFER_SIZE_SIDEBOARD; ++l)
					ADD_CLAMPED_COLOR(ledBufferSideboard, l, adjustedColor3, beatLight);
			}
			break;

			case 3:
			{
				for (int l = 0; l < LED_COUNT_TV_SIDE; ++l)
				{
					ADD_CLAMPED_COLOR(ledBufferTV, l, adjustedColor4, beatLight);
					ADD_CLAMPED_COLOR(ledBufferTV, LED_COUNT_TV_SIDE + LED_COUNT_TV_TOP + l, adjustedColor4, beatLight);
				}
			}
			break;

			case 4:
			{
				for (int l = 0; l < LED_COUNT_TV_TOP; ++l)
				{
					ADD_CLAMPED_COLOR(ledBufferTV, LED_COUNT_TV_SIDE + l, adjustedColor5, beatLight);
				}
			}
			break;
			}
		}
	}


	//const int sparkleSize = LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV;
	//const float sparkleDecay = *visualizerSettings::decay / 100.0f;
	//const float sparkleLength = *visualizerSettings::length;

	//// Update sparkle data
	//for (int s = 0; s < sparkleCount; ++s)
	//{
	//	if (visualizerSparkleTimers[s] > 0.0f)
	//	{
	//		visualizerSparkleTimers[s] -= frameTime * sparkleDecay * 10.0f;
	//		if (visualizerSparkleTimers[s] <= 0.0f)
	//		{
	//			visualizerSparkleTimers[s] = 0.0f;
	//		}
	//		else
	//		{
	//			int basePos = visualizerSparklePositions[s] - sparkleLength / 2;
	//			float sparkleB = visualizerSparkleTimers[s];
	//			if (sparkleB > 1.0f)
	//				sparkleB = 1.0f - (sparkleB - 1.0f) / SPARKLE_FADE_IN;

	//			if (basePos < 0)
	//				basePos += (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);

	//			for (int i = 0; i < sparkleLength; ++i)
	//			{
	//				const int pos = (basePos + i) % (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
	//				const float amp = 1.0f - abs(i - sparkleLength / 2.0f) / sparkleLength * 2.0f;
	//				if (pos >= LED_BUFFER_SIZE_TV)
	//				{
	//					ADD_CLAMPED_COLOR(ledBufferSideboard, LED_BUFFER_SIZE_SIDEBOARD - (1 + pos - LED_BUFFER_SIZE_TV), adjustedColor2, sparkleB * amp);
	//				}
	//				else
	//				{
	//					ADD_CLAMPED_COLOR(ledBufferTV, pos, adjustedColor2, sparkleB * amp);
	//				}
	//			}
	//			continue;
	//		}
	//	}

	//	if (GizmoLED::audioData[1 + s] > 0.0f)
	//	{
	//		visualizerSparklePositions[s] = random(0, sparkleSize);
	//		visualizerSparkleTimers[s] = SPARKLE_TIME;
	//	}
	//}
}

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

void ConnectionFX(float frameTime, float percent)
{
	float brightness = cos(float(2.0f * percent * M_PI * 2 - M_PI)) * 0.5f + 0.5f;
	const uint8_t rgb[] =
	{
		0 * brightness,
		96 * brightness,
		255 * brightness
	};

	for (int l = 0; l < LED_BUFFER_SIZE_SPEAKER; ++l)
	{
		const float amp = (LED_BUFFER_SIZE_SPEAKER - l - 1) / float(LED_BUFFER_SIZE_SPEAKER - 1);
		ledBufferSpeakerLeft[l * 3] = rgb[1] * amp;
		ledBufferSpeakerLeft[l * 3 + 1] = rgb[0] * amp;;
		ledBufferSpeakerLeft[l * 3 + 2] = rgb[2] * amp;

		ledBufferSpeakerRight[l * 3] = rgb[1] * amp;
		ledBufferSpeakerRight[l * 3 + 1] = rgb[0] * amp;
		ledBufferSpeakerRight[l * 3 + 2] = rgb[2] * amp;
	}

	uint8_t *writeBassSideboard = ledBufferSideboard + (LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_SIDEBOARD_BACK_TOP) * 3;
	for (int l = 0; l < LED_COUNT_SIDEBOARD_BOTTOM_FRONT + LED_COUNT_SIDEBOARD_BOTTOM_SIDE * 2; ++l)
	{
		writeBassSideboard[0] = rgb[1];
		writeBassSideboard[1] = rgb[0];
		writeBassSideboard[2] = rgb[2];
		writeBassSideboard += 3;
	}

	for (int l = LED_COUNT_TV_SIDE; l < LED_COUNT_TV_SIDE + LED_COUNT_TV_TOP; ++l)
	{
		ledBufferTV[l * 3] = 0;
		ledBufferTV[l * 3 + 1] = 0;
		ledBufferTV[l * 3 + 2] = 0;
	}

	const int sideboardRiseCount = LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_TV_SIDE;
	for (int l = 0; l < sideboardRiseCount; ++l)
	{
		const float amp = 1.0f - (l / float(sideboardRiseCount - 1));

		if (l < LED_COUNT_SIDEBOARD_BACK_SIDE)
		{
			const int base = LED_COUNT_SIDEBOARD_BACK_TOP + LED_COUNT_SIDEBOARD_BACK_SIDE - 1 - l;
			ledBufferSideboard[base * 3] = rgb[1] * amp;
			ledBufferSideboard[base * 3 + 1] = rgb[0] * amp;
			ledBufferSideboard[base * 3 + 2] = rgb[2] * amp;
			const int base2 = LED_BUFFER_SIZE_SIDEBOARD - LED_COUNT_SIDEBOARD_BACK_TOP - LED_COUNT_SIDEBOARD_BACK_SIDE + l;
			ledBufferSideboard[base2 * 3] = rgb[1] * amp;
			ledBufferSideboard[base2 * 3 + 1] = rgb[0] * amp;
			ledBufferSideboard[base2 * 3 + 2] = rgb[2] * amp;

			if (l == LED_COUNT_SIDEBOARD_BACK_SIDE - 1)
			{
				for (int s = 0; s < LED_COUNT_SIDEBOARD_BACK_TOP; ++s)
				{
					ledBufferSideboard[s * 3] = rgb[1] * amp;
					ledBufferSideboard[s * 3 + 1] = rgb[0] * amp;
					ledBufferSideboard[s * 3 + 2] = rgb[2] * amp;

					const int base = LED_BUFFER_SIZE_SIDEBOARD - 1 - s;
					ledBufferSideboard[base * 3] = rgb[1] * amp;
					ledBufferSideboard[base * 3 + 1] = rgb[0] * amp;
					ledBufferSideboard[base * 3 + 2] = rgb[2] * amp;
				}
			}
		}
		else
		{
			const int base = l - LED_COUNT_SIDEBOARD_BACK_SIDE;
			ledBufferTV[base * 3] = rgb[1] * amp;
			ledBufferTV[base * 3 + 1] = rgb[0] * amp;
			ledBufferTV[base * 3 + 2] = rgb[2] * amp;

			const int base2 = LED_BUFFER_SIZE_TV - 1 - l;
			ledBufferTV[base2 * 3] = rgb[1] * amp;
			ledBufferTV[base2 * 3 + 1] = rgb[0] * amp;
			ledBufferTV[base2 * 3 + 2] = rgb[2] * amp;
		}
	}
}

uint32_t pulseCount = 0;
float pulseTimer = 0.0f;

void AnimatePulse(float frameTime)
{
	pulseTimer += frameTime * *pulseSettings::speed / 40.0f;
	while (pulseTimer >= 1.0f)
	{
		pulseTimer -= 1.0f;
		++pulseCount;
	}

	const float brightness = *pulseSettings::brightness / 255.0f;
	uint8_t adjustedColor1[] =
	{
		pulseSettings::color1[0] * brightness,
		pulseSettings::color1[1] * brightness,
		pulseSettings::color1[2] * brightness
	};
	uint8_t adjustedColor0[] =
	{
		pulseSettings::color2[0] * brightness,
		pulseSettings::color2[1] * brightness,
		pulseSettings::color2[2] * brightness
	};
	int adjustedColorD[] =
	{
		adjustedColor1[0] - adjustedColor0[0],
		adjustedColor1[1] - adjustedColor0[1],
		adjustedColor1[2] - adjustedColor0[2],
	};

	const float pulseLength = float(*pulseSettings::length) / 10.0f;
	const float rainbowLength = float(*pulseSettings::rainbowLength);
	const bool useRainbow = *pulseSettings::rainbowEnabled != 0;
	const bool fadeOut = *pulseSettings::fadeOut != 0;
	if (useRainbow)
	{
		adjustedColorD[0] = 0;
		adjustedColorD[1] = 0;
		adjustedColorD[2] = 0;
	}

#define PULSE_LED_POS(width) \
		const float pos = i / float(width); \
		const float posFull = i / float(width - 1.0f); \
		const float pulseAlignment = pulseLength - pulseTimer * pulseLength; \
		float light = fmod(pos + pulseAlignment, pulseLength) / pulseLength * 1.2f; \
		if (light > 1.0f) \
			light = 1.0f - ((light - 1.0f) / 0.2f); \
		if (useRainbow) \
		{ \
			float hue = fmod(pulseCount * rainbowLength - ((pos + pulseAlignment >= pulseLength) ? rainbowLength : 0.0f), 360.0f); \
			HSV2RGB(hue, 100.0f, brightness * 100.0f, adjustedColor1); \
		} \
		else \
		{ \
			float colMix = fmod(posFull + pulseAlignment, pulseLength) / pulseLength; \
			adjustedColor1[0] = adjustedColor0[0] + adjustedColorD[0] * colMix; \
			adjustedColor1[1] = adjustedColor0[1] + adjustedColorD[1] * colMix; \
			adjustedColor1[2] = adjustedColor0[2] + adjustedColorD[2] * colMix; \
		} \
		if (fadeOut) \
		{ \
			light *= 1.0f - posFull; \
		} \
		light *= light

	// SPEAKER
	for (int i = 0; i < LED_BUFFER_SIZE_SPEAKER; ++i)
	{
		PULSE_LED_POS(LED_BUFFER_SIZE_SPEAKER);

		ledBufferSpeakerLeft[i * 3] = adjustedColor1[1] * light;
		ledBufferSpeakerLeft[i * 3 + 1] = adjustedColor1[0] * light;
		ledBufferSpeakerLeft[i * 3 + 2] = adjustedColor1[2] * light;

		ledBufferSpeakerRight[i * 3] = adjustedColor1[1] * light;
		ledBufferSpeakerRight[i * 3 + 1] = adjustedColor1[0] * light;
		ledBufferSpeakerRight[i * 3 + 2] = adjustedColor1[2] * light;
	}

	// SIDEBOARD
	const int vSideboard = LED_COUNT_SIDEBOARD_BOTTOM_SIDE + LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_TV_SIDE;
	for (int i = 0; i < vSideboard; ++i)
	{
		PULSE_LED_POS(vSideboard);

		if (i < LED_COUNT_SIDEBOARD_BOTTOM_SIDE + LED_COUNT_SIDEBOARD_BACK_SIDE)
		{
			const int iL = LED_COUNT_SIDEBOARD_BACK_TOP + LED_COUNT_SIDEBOARD_BACK_SIDE + (LED_COUNT_SIDEBOARD_BOTTOM_SIDE - i - 1);
			const int iR = LED_BUFFER_SIZE_SIDEBOARD - LED_COUNT_SIDEBOARD_BACK_TOP - LED_COUNT_SIDEBOARD_BACK_SIDE - LED_COUNT_SIDEBOARD_BOTTOM_SIDE + i;

			ledBufferSideboard[iL * 3] = adjustedColor1[1] * light;
			ledBufferSideboard[iL * 3 + 1] = adjustedColor1[0] * light;
			ledBufferSideboard[iL * 3 + 2] = adjustedColor1[2] * light;

			ledBufferSideboard[iR * 3] = adjustedColor1[1] * light;
			ledBufferSideboard[iR * 3 + 1] = adjustedColor1[0] * light;
			ledBufferSideboard[iR * 3 + 2] = adjustedColor1[2] * light;

			if (i == 0)
			{
				for (int l = LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_SIDEBOARD_BACK_TOP + LED_COUNT_SIDEBOARD_BOTTOM_SIDE;
					l < LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_SIDEBOARD_BACK_TOP + LED_COUNT_SIDEBOARD_BOTTOM_SIDE + LED_COUNT_SIDEBOARD_BOTTOM_FRONT; ++l)
				{
					ledBufferSideboard[l * 3] = adjustedColor1[1] * light;
					ledBufferSideboard[l * 3 + 1] = adjustedColor1[0] * light;
					ledBufferSideboard[l * 3 + 2] = adjustedColor1[2] * light;
				}
			}

			if (i == LED_COUNT_SIDEBOARD_BOTTOM_SIDE + LED_COUNT_SIDEBOARD_BACK_SIDE - 1)
			{
				for (int l = 0; l < LED_COUNT_SIDEBOARD_BACK_TOP; ++l)
				{
					ledBufferSideboard[l * 3] = adjustedColor1[1] * light;
					ledBufferSideboard[l * 3 + 1] = adjustedColor1[0] * light;
					ledBufferSideboard[l * 3 + 2] = adjustedColor1[2] * light;
				}

				for (int l = LED_BUFFER_SIZE_SIDEBOARD - LED_COUNT_SIDEBOARD_BACK_TOP; l < LED_BUFFER_SIZE_SIDEBOARD; ++l)
				{
					ledBufferSideboard[l * 3] = adjustedColor1[1] * light;
					ledBufferSideboard[l * 3 + 1] = adjustedColor1[0] * light;
					ledBufferSideboard[l * 3 + 2] = adjustedColor1[2] * light;
				}
			}
		}
		else if (i < LED_COUNT_SIDEBOARD_BOTTOM_SIDE + LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_TV_SIDE)
		{
			const int tvPos = i - LED_COUNT_SIDEBOARD_BOTTOM_SIDE - LED_COUNT_SIDEBOARD_BACK_SIDE;

			const int iL = tvPos;
			const int iR = LED_BUFFER_SIZE_TV - tvPos - 1;

			ledBufferTV[iL * 3] = adjustedColor1[1] * light;
			ledBufferTV[iL * 3 + 1] = adjustedColor1[0] * light;
			ledBufferTV[iL * 3 + 2] = adjustedColor1[2] * light;

			ledBufferTV[iR * 3] = adjustedColor1[1] * light;
			ledBufferTV[iR * 3 + 1] = adjustedColor1[0] * light;
			ledBufferTV[iR * 3 + 2] = adjustedColor1[2] * light;

			if (i == LED_COUNT_SIDEBOARD_BOTTOM_SIDE + LED_COUNT_SIDEBOARD_BACK_SIDE + LED_COUNT_TV_SIDE - 1)
			{
				for (int l = LED_COUNT_TV_SIDE; l < LED_COUNT_TV_SIDE + LED_COUNT_TV_TOP; ++l)
				{
					ledBufferTV[l * 3] = adjustedColor1[1] * light;
					ledBufferTV[l * 3 + 1] = adjustedColor1[0] * light;
					ledBufferTV[l * 3 + 2] = adjustedColor1[2] * light;
				}
			}
		}
	}
}

const int sparkleCount = 10;
float visualizerSparkleTimers[sparkleCount] = { 0.0f };
int visualizerSparklePositions[sparkleCount] = { 0 };
float sparkleRainbowHue[sparkleCount] = { 0.0f };

#define SPARKLE_TIME 1.2f
#define SPARKLE_FADE_IN 0.2f

float nextSparkleHue = 0.0f;
float sparkleTriggerTimers[sparkleCount] = { 0.0f };
void SimulateSparkle(float frameTime)
{
	for (int a = 0; a < sparkleCount; ++a)
	{
		sparkleTriggerTimers[a] += frameTime * 1.5f * (sparkleCount * 2 - a) / float(sparkleCount * 2);

		if (sparkleTriggerTimers[a] >= 1.0f &&
			visualizerSparkleTimers[a] == 0.0f)
		{
			//GizmoLED::audioData[a] = 1.0f;
			sparkleTriggerTimers[a] = 0.0f;

			const int sparkleSize = LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV + LED_BUFFER_SIZE_SPEAKER * 2;
			visualizerSparklePositions[a] = random(0, sparkleSize);
			visualizerSparkleTimers[a] = SPARKLE_TIME;
			if (*sparkleSettings::rainbowEnabled != 0)
			{
				sparkleRainbowHue[a] = nextSparkleHue;
				nextSparkleHue += *sparkleSettings::rainbowSpeed;
				while (nextSparkleHue >= 360.0f)
				{
					nextSparkleHue -= 360.0f;
				}
			}
		}
	}
}

void AnimateSparkle(float frameTime)
{
	SimulateSparkle(frameTime);

	const float sparkleDecay = *sparkleSettings::decay / 100.0f;
	const float sparkleLength = *sparkleSettings::length;

	for (int l = 0; l < LED_BUFFER_SIZE_SPEAKER; ++l)
	{
		ledBufferSpeakerLeft[l * 3] = 0;
		ledBufferSpeakerLeft[l * 3 + 1] = 0;
		ledBufferSpeakerLeft[l * 3 + 2] = 0;
		ledBufferSpeakerRight[l * 3] = 0;
		ledBufferSpeakerRight[l * 3 + 1] = 0;
		ledBufferSpeakerRight[l * 3 + 2] = 0;
	}

	for (int l = 0; l < LED_BUFFER_SIZE_SIDEBOARD; ++l)
	{
		ledBufferSideboard[l * 3] = 0;
		ledBufferSideboard[l * 3 + 1] = 0;
		ledBufferSideboard[l * 3 + 2] = 0;
	}

	for (int l = 0; l < LED_BUFFER_SIZE_TV; ++l)
	{
		ledBufferTV[l * 3] = 0;
		ledBufferTV[l * 3 + 1] = 0;
		ledBufferTV[l * 3 + 2] = 0;
	}

	const float brightness = *sparkleSettings::brightness / 255.0f;
	uint8_t adjustedColor[] =
	{
		sparkleSettings::color[0] * brightness,
		sparkleSettings::color[1] * brightness,
		sparkleSettings::color[2] * brightness
	};

	// Update sparkle data
	for (int s = 0; s < sparkleCount; ++s)
	{
		if (visualizerSparkleTimers[s] > 0.0f)
		{
			visualizerSparkleTimers[s] -= frameTime * sparkleDecay * 10.0f;
			if (visualizerSparkleTimers[s] <= 0.0f)
			{
				visualizerSparkleTimers[s] = 0.0f;
			}
			else
			{
				if (*sparkleSettings::rainbowEnabled != 0)
				{
					HSV2RGB(sparkleRainbowHue[s], 100.0f, brightness * 100.0f, adjustedColor);
				}

				int basePos = visualizerSparklePositions[s];
				if (basePos > LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV)
				{
					uint8_t *speakerTarget;
					if (basePos > LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV + LED_BUFFER_SIZE_SPEAKER)
					{
						speakerTarget = ledBufferSpeakerRight;
						basePos -= LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV + LED_BUFFER_SIZE_SPEAKER;
					}
					else
					{
						speakerTarget = ledBufferSpeakerLeft;
						basePos -= LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV;
					}

					basePos -= sparkleLength / 2;
					float sparkleB = visualizerSparkleTimers[s];
					if (sparkleB > 1.0f)
						sparkleB = 1.0f - (sparkleB - 1.0f) / SPARKLE_FADE_IN;

					for (int i = 0; i < sparkleLength; ++i)
					{
						int pos = basePos + i;
						if (pos < 0 || pos >= LED_BUFFER_SIZE_SPEAKER)
							continue;
						const float amp = 1.0f - abs(i - sparkleLength / 2.0f) / sparkleLength * 2.0f;
						ADD_CLAMPED_COLOR(speakerTarget, pos, adjustedColor, sparkleB * amp);
					}
				}
				else
				{
					basePos -= sparkleLength / 2;
					float sparkleB = visualizerSparkleTimers[s];
					if (sparkleB > 1.0f)
						sparkleB = 1.0f - (sparkleB - 1.0f) / SPARKLE_FADE_IN;

					if (basePos < 0)
						basePos += (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);

					for (int i = 0; i < sparkleLength; ++i)
					{
						const int pos = (basePos + i) % (LED_BUFFER_SIZE_SIDEBOARD + LED_BUFFER_SIZE_TV);
						const float amp = 1.0f - abs(i - sparkleLength / 2.0f) / sparkleLength * 2.0f;
						if (pos >= LED_BUFFER_SIZE_TV)
						{
							ADD_CLAMPED_COLOR(ledBufferSideboard, LED_BUFFER_SIZE_SIDEBOARD - (1 + pos - LED_BUFFER_SIZE_TV), adjustedColor, sparkleB * amp);
						}
						else
						{
							ADD_CLAMPED_COLOR(ledBufferTV, pos, adjustedColor, sparkleB * amp);
						}
					}
				}
			}
		}
	}
}
