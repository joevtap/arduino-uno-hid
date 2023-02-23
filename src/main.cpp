#include <Arduino.h>
#include "run_script.h"

const int led_indicator_pin = LED_BUILTIN;

void execute()
{
  run_script(1);
}

void setup()
{
  Serial.begin(9600);
  pinMode(led_indicator_pin, OUTPUT);

  delay(100);

  execute();
  blink_when_script_end_running(led_indicator_pin, 5);
}

void loop() {}
