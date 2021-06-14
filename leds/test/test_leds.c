/**
 *
 */
#include "unity.h"
#include "leds.h"

uint16_t ledsVirtuales;

 #define LED 5

void setUp(void){
    Leds_Create(&ledsVirtuales);
}

void tearDown(void){
    
}

// Después de la inicialización, todos los LEDs deben quedar apagados.
void test_LedsOffAfterCreate(void){
    ledsVirtuales = 0xFFFF;
    Leds_Create(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
    //TEST_FAIL_MESSAGE("Empezamos");
}

// Se puede prender un LED individual
void test_TurnOnLedOne(void){
    Led_TurnOn(LED);
    TEST_ASSERT_EQUAL_HEX16(1 << (LED-1), ledsVirtuales);
}

// Se puede apagar un LED individual
void test_TurnOffLedOne(void){
    Led_TurnOn(LED);
    Led_TurnOff(LED);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

// Se pueden prender y apagar múltiples LED's
void test_TurnOnAndOffManyLeds(void){
    Led_TurnOn(3);
    Led_TurnOn(LED);
    Led_TurnOff(3);
    TEST_ASSERT_EQUAL_HEX16(1 << (LED-1), ledsVirtuales);
}

// Se pueden prender todos los LED's de una vez
void test_TurnOnAllLedsAtOnce(void){
    Led_TurnOnAll();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}

// Se pueden apagar todos los LED's de una vez
void test_TurnOffAllLedsAtOnce(void){
    ledsVirtuales = 0xFFFF;
    Led_TurnOffAll();
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

// Se puede consultar el estado de un LED apagado
void test_IsLedOff(void){
    Led_TurnOff(LED);
    TEST_ASSERT_TRUE(Led_IsOff(LED));
}

// Se puede consultar el estado de un LED prendido
void test_IsLedOn(void){
    Led_TurnOn(LED);
    TEST_ASSERT_TRUE(Led_IsOn(LED));
}

// Revisar límites de los parámetros
void test_ParameterLimits(void){
    // Límite superior prendiendo
    Led_TurnOn(17);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);

    // Límite superior apagando
    ledsVirtuales = 0xFFFF;
    Led_TurnOff(17);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);

    // Límite inferior apagando
    ledsVirtuales = 0xFFFF;
    Led_TurnOff(0);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);

    // Límite inferior prendiendo
    ledsVirtuales = 0x0000;
    Led_TurnOff(0);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
   
}