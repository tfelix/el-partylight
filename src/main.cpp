#include <Arduino.h>

const int wireCount = 4;
enum StrandLightMode
{
  SIMPLE, // One after another
  RANDOM,  // Random blinking
  SPECIAL
};

void setup()
{
  // initialize the digital pin as an output.D2~D9 to control channel A to H
  for (int i = 2; i < wireCount + 2; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void simpleLightMode()
{
  for (int i = 2; i < wireCount + 2; i++)
  {
    digitalWrite(i, HIGH);
    delay(2500);
    digitalWrite(i, LOW);
    delay(10);
  }
}

/**
 * Zufälliges an und aus
 */
void randomLightMode()
{
  for (int i = 2; i < wireCount + 2; i++)
  {
    const int wire = 2 + random(wireCount);
    digitalWrite(wire, HIGH);
    delay(2500);
    digitalWrite(i, LOW);
    delay(10);
  }
}

/**
 * Variable Geschwindigkeit der Anzeige
 */
void randomSpecialLightMode()
{
  const int displayTime = 200 + random(800);
  const int switchCount = 20 + random(200);

  for (int i = 0; i < switchCount; i++) {
    const int switchPin = random(wireCount);
    digitalWrite(switchPin, HIGH);
    delay(displayTime);
    digitalWrite(switchPin, LOW);
    delay(10);
  }
}

void loop()
{
  const int mode = random(7);

  switch(mode) {
    case 0:
    case 1:
    case 2:
    simpleLightMode();
    break;
    case 3:
    case 4:
    case 5:
    randomLightMode();
    break;
    case 6:
    randomSpecialLightMode();
    break;
    default:
    simpleLightMode();
  }
}
