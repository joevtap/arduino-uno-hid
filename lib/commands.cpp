#include "commands.h"
#include "usb_hid_keys.h"
#include <string.h>

// Keyboard buffer
uint8_t buf[8] = {0};

void keypress_upper(int keycode)
{
  buf[0] = KEY_MOD_LSHIFT;
  buf[2] = keycode;
  Serial.write(buf, 8);
  releasekey();
}

void keypress_alt_gr(int keycode)
{
  buf[0] = KEY_MOD_RALT;
  buf[2] = keycode;
  Serial.write(buf, 8);
  releasekey();
}

void keypress_ctrl(int keycode)
{
  buf[0] = KEY_MOD_LCTRL;
  buf[2] = keycode;
  Serial.write(buf, 8);
  releasekey();
}

void keypress(int keycode)
{
  buf[2] = keycode;
  Serial.write(buf, 8);
  releasekey();
}

void releasekey()
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);
}

// Thanks to @thaolt (https://github.com/thaolt)
void write_ch(uint8_t c)
{
  if (c > 127)
    return;
  if (c < 32)
    return;

  c -= 32; // offset ignore the first 32 symbols in ascii table

  buf[0] = ascii_to_hid_key_map[c][0];
  buf[2] = ascii_to_hid_key_map[c][1];

  Serial.write(buf, 8);
  releasekey();
}

void write_str(const char *str)
{
  uint8_t l = strlen(str);
  for (uint8_t i = 0; i < l; i++)
  {
    write_ch(str[i]);
  }
}