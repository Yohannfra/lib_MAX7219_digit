# Counter (Pi pico)

## Build

```bash
$ mkdir build
$ export PICO_SDK_PATH=... # set the path to the sdk
$ cd build
$ cmake ..
$ make
```

## Flash

Copy and paste the [uf2 file](./build/blinky_74hc595.uf2) onto the pi pico.

## Pinout

Refer to the pinout described in [main.c](./main.c)
```c
static const int CLK_PIN = 1;
static const int MOSI_PIN = 0;
static const int CS_PIN = 10;
```
