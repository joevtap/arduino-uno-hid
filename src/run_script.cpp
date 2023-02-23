#include "commands.h"
#include "usb_hid_keys.h"
#include "run_script.h"

void run_script(int script)
{
  switch (script)
  {
  case 1:
    keypress(KEY_LEFTMETA);
    delay(200);
    write_str("chrome");
    keypress(KEY_ENTER);
    keypress(KEY_ENTER);
    keypress(KEY_ENTER);
    delay(2000);
    keypress_ctrl(KEY_T);
    delay(500);
    write_str("https://youtu.be/dQw4w9WgXcQ"); // Rick Astley - Never Gonna Give You Up
    keypress(KEY_ENTER);
    break;
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  default:
    break;
  }
}

void blink_when_script_end_running(int pin, int n)
{
  int i;

  for (i = 0; i < n; i++)
  {
    digitalWrite(pin, LOW);
    delay(500);
    digitalWrite(pin, HIGH);
    delay(500);
  }

  digitalWrite(pin, LOW);
}