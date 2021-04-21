
/* 
   DoSomethingUP_DoSomethingDown full step Rotary Encoder with interrupts
   Rupert Hirst 2021
   Source:         https://github.com/koogar/ErriezRotaryEncoderFullStep
*/

// Connect rotary pins to the DIGITAL pins of the Arduino board with interrupt
// support:
//
// +-----------------------------------+--------------------------------+
// |              Board                |    DIGITAL interrupt pins      |
// +-----------------------------------+--------------------------------+
// | Uno, Nano, Mini, other 328-based  | 2, 3                           |
// | Mega, Mega2560, MegaADK           | 2, 3, 18, 19, 20, 21           |
// | Micro, Leonardo, other 32u4-based | 0, 1, 2, 3, 7                  |
// | WeMos D1 R2 & mini (ESP8266)      | 12 = D6; 13 = D7; 14 = D5      |
// | Zero, ATSAMD21                    | all digital pins, except pin 4 |
// | STM32F103 (BluePill)              | all digital pins,              |
// +-----------------------------------+--------------------------------+
//

#include <TML_ErriezRotaryFullStep.h>

#define ROTARY_A   3
#define ROTARY_B   2
#define ROTARY_BUTTON_PIN   1

RotaryFullStep rotary(ROTARY_A, ROTARY_B);

// Forward declaration
void rotaryInterrupt();

void setup()
{

  // Initialize Serial port
  Serial.begin(115200);

  // Initialize pin change interrupt on both rotary encoder pins
  attachInterrupt(digitalPinToInterrupt(ROTARY_A), rotaryInterrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ROTARY_B), rotaryInterrupt, CHANGE);

  // Enable internal pull-up for the rotary button pin
  pinMode(ROTARY_BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{
  rotaryButton();
  //Do Something else

}


#if defined(ARDUINO_ARCH_ESP8266) || defined(ARDUINO_ARCH_ESP32)
ICACHE_RAM_ATTR
#endif

void rotaryButton()
{
  // Poll Rotary button pin
  if (digitalRead(ROTARY_BUTTON_PIN) == 0) {
    //Do Something Here
    delay(300);// debounce
    Serial.println("Encoder Button Pressed :");
  }
}


void rotaryInterrupt()
{
  int rotaryState;

  // Read rotary state (Counter clockwise) -3, -2, -1, 0, 1, 2, 3 (Clockwise)
  rotaryState = rotary.read();

  if (rotaryState > 0)  {

    //Do Something Here
    Serial.print("Encoder DOWN :");
    Serial.println(rotaryState);

  } else {

    if (rotaryState < 0)  {

      //Do Something Here
      Serial.print("Encoder UP :");
      Serial.println(rotaryState);
    }
  }
}
