#include "leds.h"

#define ALL_LEDS_OFF    0x0000
#define ALL_LEDS_ON     ~ALL_LEDS_OFF
#define LED_ON          1
#define LED_OFFSET      1

static uint16_t * puerto;

uint16_t led_to_int(uint8_t led){
    return (LED_ON << (led - LED_OFFSET));
}

uint16_t mask_led_state(uint8_t led){
    return *puerto &= led_to_int(led);
}

void Leds_Create(uint16_t * puntero){
    puerto = puntero;
    *puerto = ALL_LEDS_OFF;
}

void Led_TurnOn(uint8_t led){
    *puerto |= led_to_int(led);
}

void Led_TurnOff(uint8_t led){
    *puerto &= ~led_to_int(led);
}

void Led_TurnOnAll(void){
    *puerto = ALL_LEDS_ON;
}

void Led_TurnOffAll(void){
    *puerto = ALL_LEDS_OFF;
}

bool Led_IsOff(uint8_t led){
    return (!mask_led_state(led)) ? true : false;
}

bool Led_IsOn(uint8_t led){
    return (mask_led_state(led)) ? true : false;
}