
#include <Arduino.h>
#include <ArduinoBLE.h>

#include <Adafruit_NeoPixel.h>

#include <gizmoled.h>

void AnimateBlink(float frameTime);
void AnimateWheel(float frameTime);
void AnimateVisualizer(float frameTime);
void ConnectionFX(float frameTime, uint8_t *rgb);

const int ledPinR = 22;
const int ledPinG = 23;
const int ledPinB = 24;

BEGIN_EFFECT_SETTINGS(EFFECTNAME_BLINK)
DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR, 0xFF, 0, 0)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_SPEED, 10, 1, 100)
DECLARE_EFFECT_SETTINGS_CHECKBOX(GizmoLED::VARNAME_FADEIN, 0)
DECLARE_EFFECT_SETTINGS_CHECKBOX(GizmoLED::VARNAME_FADEOUT, 0)
DECLARE_EFFECT_SETTINGS_CHECKBOX(GizmoLED::VARNAME_RAINBOWENABLED, 0)
DECLARE_EFFECT_SETTINGS_SLIDER(GizmoLED::VARNAME_RAINBOWSPEED, 10, 1, 100)
END_EFFECT_SETTINGS()

DECLARE_EFFECT_VAR(blinkColor, EFFECTNAME_BLINK, 0);
DECLARE_EFFECT_VAR(blinkSpeed, EFFECTNAME_BLINK, 5);
DECLARE_EFFECT_VAR(blinkFadeIn, EFFECTNAME_BLINK, 10);
DECLARE_EFFECT_VAR(blinkFadeOut, EFFECTNAME_BLINK, 13);
DECLARE_EFFECT_VAR(blinkRainbow, EFFECTNAME_BLINK, 16);
DECLARE_EFFECT_VAR(blinkRainbowSpeed, EFFECTNAME_BLINK, 21);

BEGIN_EFFECT_SETTINGS(EFFECTNAME_WHEEL)
DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR, 0, 0xFF, 0)
END_EFFECT_SETTINGS()

DECLARE_EFFECT_VAR(wheelColor, EFFECTNAME_WHEEL, 0);

BEGIN_EFFECT_SETTINGS(EFFECTNAME_VISUALIZER)
DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR1, 0, 0, 0xFF)
DECLARE_EFFECT_SETTINGS_COLOR(GizmoLED::VARNAME_COLOR2, 0, 0, 0xFF)
END_EFFECT_SETTINGS()

DECLARE_EFFECT_VAR(visualizerColor, EFFECTNAME_VISUALIZER, 0);

BEGIN_EFFECTS()
DECLARE_EFFECT(AnimateVisualizer, EFFECTNAME_VISUALIZER, GizmoLED::EFFECTTYPE_VISUALIZER)
DECLARE_EFFECT(AnimateBlink, EFFECTNAME_BLINK, GizmoLED::EFFECTTYPE_DEFAULT)
DECLARE_EFFECT(AnimateWheel, EFFECTNAME_WHEEL, GizmoLED::EFFECTTYPE_DEFAULT)
END_EFFECTS()

#define LED_COUNT_SPEAKER 101
#define LED_PIN_SPEAKER_LEFT 2

uint8_t *ledBufferSpeakerLeft;
Adafruit_NeoPixel ledAccessSpeakerLeft(LED_COUNT_SPEAKER, LED_PIN_SPEAKER_LEFT, NEO_GRB + NEO_KHZ800);

void setup()
{
	//Serial.begin(115200);

	// LED init
	ledAccessSpeakerLeft.begin();
	ledBufferSpeakerLeft = ledAccessSpeakerLeft.getPixels();

	GizmoLED::connectionAnimation = ConnectionFX;
	GIZMOLED_SETUP();

	pinMode(ledPinR, OUTPUT);
	pinMode(ledPinG, OUTPUT);
	pinMode(ledPinB, OUTPUT);
}

void loop()
{
	GIZMOLED_LOOP();
}

void AnimateBlink(float frameTime)
{
	//digitalWrite(ledPinR, LOW);
	//digitalWrite(ledPinG, HIGH);
	//digitalWrite(ledPinB, HIGH);
	//Serial.println(String("g: ") + String(blinkColor[1]));
	if (blinkColor[0] > 127)
		digitalWrite(ledPinR, LOW);
	else
		digitalWrite(ledPinR, HIGH);

	if (blinkColor[1] > 127)
		digitalWrite(ledPinG, LOW);
	else
		digitalWrite(ledPinG, HIGH);

	if (blinkColor[2] > 127)
		digitalWrite(ledPinB, LOW);
	else
		digitalWrite(ledPinB, HIGH);
}

void AnimateWheel(float frameTime)
{
	if (wheelColor[0] > 127)
		digitalWrite(ledPinR, LOW);
	else
		digitalWrite(ledPinR, HIGH);

	if (wheelColor[1] > 127)
		digitalWrite(ledPinG, LOW);
	else
		digitalWrite(ledPinG, HIGH);

	if (wheelColor[2] > 127)
		digitalWrite(ledPinB, LOW);
	else
		digitalWrite(ledPinB, HIGH);
}

float speakerFillAmount = 0.0f;

void AnimateVisualizer(float frameTime)
{
	bool audioTrigger = GizmoLED::audioData[0] > 0;
	if (visualizerColor[0] > 127 && audioTrigger)
		digitalWrite(ledPinR, LOW);
	else
		digitalWrite(ledPinR, HIGH);

	if (visualizerColor[1] > 127 && audioTrigger)
		digitalWrite(ledPinG, LOW);
	else
		digitalWrite(ledPinG, HIGH);

	if (visualizerColor[2] > 127 && audioTrigger)
		digitalWrite(ledPinB, LOW);
	else
		digitalWrite(ledPinB, HIGH);

	float speakerFillDesired = audioTrigger ? 1.0f : 0.0f;
	float speakerMaxAdjust = min(abs(speakerFillDesired - speakerFillAmount), frameTime * 5.0f);
	if (speakerFillAmount != speakerFillDesired)
		speakerFillAmount += (speakerFillDesired > speakerFillAmount) ? speakerMaxAdjust : -speakerMaxAdjust;

	for (int l = 0; l < LED_COUNT_SPEAKER; ++l)
	{
		float fillPercent = l / float(LED_COUNT_SPEAKER);
		if (fillPercent < speakerFillAmount)
		{
			ledBufferSpeakerLeft[l * 3] = visualizerColor[1];
			ledBufferSpeakerLeft[l * 3 + 1] = visualizerColor[0];
			ledBufferSpeakerLeft[l * 3 + 2] = visualizerColor[2];
		}
		else
		{
			ledBufferSpeakerLeft[l * 3] = 0;
			ledBufferSpeakerLeft[l * 3 + 1] = 0;
			ledBufferSpeakerLeft[l * 3 + 2] = 0;
		}
	}

	ledAccessSpeakerLeft.show();
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

