#include "../include/MAX7219_digit.h"

void MAX7219_digit_init(MAX7219_digit_dev_t *dev)
{
    dev->fn_write_reg(0x09, 0xFF);               // decoding ：B
    dev->fn_write_reg(0x0a, 0x0f);               // brightness (from 0x01 to 0x0f)
    dev->fn_write_reg(0x0b, dev->nb_digits - 1); // scanlimit
    dev->fn_write_reg(0x0c, 0x01);               // power-down mode：0，normal mode：1
    dev->fn_write_reg(0x0f, 0x00);               // test display：1；EOT，display：0

    MAX7219_digit_clear(dev);
}

void MAX7219_digit_clear(MAX7219_digit_dev_t *dev)
{
    for (uint8_t i = 1; i <= dev->nb_digits; i++) {
        dev->fn_write_reg(i, 0);
    }
}

void MAX7219_digit_set_digit(MAX7219_digit_dev_t *dev, uint8_t index, uint8_t number)
{
    dev->fn_write_reg(index, number);
}

void MAX7219_digit_set_number(MAX7219_digit_dev_t *dev, uint32_t n)
{
    int index = dev->nb_digits;

    if (n == 0) {
        for (uint8_t i = 1; i <= dev->nb_digits; i++) {
            MAX7219_digit_set_digit(dev, i, 0);
        }
    }

    while (n > 0) {
        uint32_t r = n % 10;
        MAX7219_digit_set_digit(dev, index, r);
        index -= 1;
        n /= 10;
    }
}

void MAX7219_digit_turn_on(MAX7219_digit_dev_t *dev)
{
    dev->fn_write_reg(0x0c, 0x01);
}

void MAX7219_digit_turn_off(MAX7219_digit_dev_t *dev)
{
    dev->fn_write_reg(0x0c, 0x00);
}
