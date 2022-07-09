#ifndef MAX7219_DIGIT_H
#define MAX7219_DIGIT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>

typedef struct {
    uint8_t nb_digits;
    void (*fn_write_reg)(uint8_t, uint8_t);
} MAX7219_digit_dev_t;

void MAX7219_digit_init(MAX7219_digit_dev_t *dev);
void MAX7219_digit_clear(MAX7219_digit_dev_t *dev);
void MAX7219_digit_set_digit(MAX7219_digit_dev_t *dev, uint8_t index, uint8_t number);
void MAX7219_digit_set_number(MAX7219_digit_dev_t *dev, uint32_t number);
void MAX7219_digit_turn_on(MAX7219_digit_dev_t *dev);
void MAX7219_digit_turn_off(MAX7219_digit_dev_t *dev);

#ifdef __cplusplus
}
#endif

#endif
