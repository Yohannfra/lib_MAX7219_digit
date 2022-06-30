#include <Arduino.h>

extern "C" {
#include "MAX7219_digit.h"
}

constexpr int CLK_PIN = 13;
constexpr int MOSI_PIN = 11;
constexpr int CS_PIN = 10;

static void fn_write_reg(uint8_t addr, uint8_t data)
{
    digitalWrite(CS_PIN, LOW);
    shiftOut(MOSI_PIN, CLK_PIN, MSBFIRST, addr);
    shiftOut(MOSI_PIN, CLK_PIN, MSBFIRST, data);
    digitalWrite(CS_PIN, HIGH);
}

static MAX7219_digit_dev_t dev = {
    .nb_digits = 2,
    .fn_write_reg = &fn_write_reg,
};

void setup()
{
    pinMode(CS_PIN, OUTPUT);
    digitalWrite(CS_PIN, HIGH);
    pinMode(MOSI, OUTPUT);
    pinMode(CLK_PIN, OUTPUT);
    digitalWrite(CLK_PIN, HIGH);

    delay(100);

    MAX7219_digit_init(&dev);
}

void loop()
{
    for (uint8_t i = 0; i <= 99; i++) {
        MAX7219_digit_set_number(&dev, i);
    }
}
