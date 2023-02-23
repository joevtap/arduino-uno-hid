#ifndef COMMANDS_H
#define COMMANDS_H

#include <Arduino.h>

void keypress(int);
void keypress_upper(int);
void keypress_ctrl(int);
void keypress_alt_gr(int);
void write_ch(uint8_t c);
void write_str(const char *str);
void releasekey();

#endif // COMMANDS_H