#include <stdint.h>
#include <stdbool.h>

void Leds_Create(uint16_t * puntero);

void Led_TurnOn(uint8_t led);

void Led_TurnOff(uint8_t led);

void Led_TurnOnAll(void);

void Led_TurnOffAll(void);

bool Led_IsOff(uint8_t led);

bool Led_IsOn(uint8_t led);