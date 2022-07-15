# Counter (Arduino)

## Build

```bash
$ pio run
```

## Flash

```bash
$ pio run --target upload
```

## Pinout

Refer to the pinout described in [main.cpp](./src/main.cpp)

```cpp
constexpr int CLK_PIN = 13;
constexpr int MOSI_PIN = 11;
constexpr int CS_PIN = 10;
```
