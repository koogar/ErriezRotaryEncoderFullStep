/*
 * MIT License
 *
 * Copyright (c) 2018 Erriez
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/* Rotary full step example
 * Source: https://github.com/Erriez/ArduinoLibraryRotary
 */

#include <Arduino.h>
#include <Rotary.h>

// Configure rotary digital pins
#define ROTARY_PIN1   2
#define ROTARY_PIN2   3

// Initialize full step rotary
Rotary rotary(ROTARY_PIN1, ROTARY_PIN2, FullStep);

// Global variables
int count = 0;
int countLast = 0;

void setup()
{
  // Initialize Serial port
  Serial.begin(115200);
  Serial.println(F("Rotary full step example"));
}

void loop()
{
  // Read rotary state
  count += rotary.read();

  // Limit count to a minimum and maximum value
  if (count > 100) {
    count = 100;
  }
  if (count < 0) {
    count = 0;
  }

  // Print count value when rotary changed
  if (countLast != count) {
    countLast = count;
    Serial.print(F("Count: "));
    Serial.println(count);
  }
}
