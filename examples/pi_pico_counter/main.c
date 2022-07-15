#include "../../lib/MAX7219_digit/include/MAX7219_digit.h"
#include "pico/stdlib.h"

static const int CLK_PIN = 1;
static const int MOSI_PIN = 0;
static const int CS_PIN = 10;

// basic software spi function
static void my_soft_spi_write(uint8_t payload)
{
    for (uint8_t i = 0; i < 8; i++) {
        gpio_put(MOSI_PIN, !!(payload & (1 << (7 - i))));
        gpio_put(CLK_PIN, true);
        gpio_put(CLK_PIN, false);
    }
}

static void fn_write_reg(uint8_t addr, uint8_t data)
{
    uint8_t msg[2] = {addr, data};

    gpio_put(CS_PIN, false);
    my_soft_spi_write(addr);
    my_soft_spi_write(data);
    gpio_put(CS_PIN, true);
}

static MAX7219_digit_dev_t dev = {
    .nb_digits = 2,
    .fn_write_reg = &fn_write_reg,
};

int main()
{
    gpio_init(CS_PIN);
    gpio_set_dir(CS_PIN, GPIO_OUT);
    gpio_put(CS_PIN, true);

    gpio_init(CLK_PIN);
    gpio_set_dir(CLK_PIN, GPIO_OUT);
    gpio_put(CLK_PIN, true);

    gpio_init(MOSI_PIN);
    gpio_set_dir(MOSI_PIN, GPIO_OUT);

    sleep_ms(100);

    MAX7219_digit_init(&dev);

    while (1) {
        for (uint8_t i = 0; i <= 99; i++) {
            MAX7219_digit_set_number(&dev, i);
            sleep_ms(500);
        }
    }
}
