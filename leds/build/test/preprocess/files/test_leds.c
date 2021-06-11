#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.0/vendor/unity/src/unity.h"








uint16_t ledsVirtuales;







void setUp(void){

    Leds_Create(&ledsVirtuales);

}



void tearDown(void){



}





void test_LedsOffAfterCreate(void){

    ledsVirtuales = 0xFFFF;

    Leds_Create(&ledsVirtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_HEX16);



}





void test_TurnOnLedOne(void){

    Led_TurnOn(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << (5 -1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOffLedOne(void){

    Led_TurnOn(5);

    Led_TurnOff(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnAndOffManyLeds(void){

    Led_TurnOn(3);

    Led_TurnOn(5);

    Led_TurnOff(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << (5 -1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnAllLedsAtOnce(void){

    Led_TurnOnAll();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOffAllLedsAtOnce(void){

    ledsVirtuales = 0xFFFF;

    Led_TurnOffAll();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_HEX16);

}





void test_IsLedOff(void){

    

   _Bool 

        ledIsOff = 

                   0

                        ;

    ledsVirtuales = 0xFFFF;

    ledIsOff = Led_IsOff(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((ledIsOff)), (UNITY_INT)(UNITY_INT16)((

   0

   )), (

   ((void *)0)

   ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_HEX16);

    Led_TurnOff(5);

    ledIsOff = Led_IsOff(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((ledIsOff)), (UNITY_INT)(UNITY_INT16)((

   1

   )), (

   ((void *)0)

   ), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_HEX16);

}





void test_IsLedOn(void){

    

   _Bool 

        ledIsOn = 

                  0

                       ;

    ledIsOn = Led_IsOn(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((ledIsOn)), (UNITY_INT)(UNITY_INT16)((

   0

   )), (

   ((void *)0)

   ), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_HEX16);

    Led_TurnOn(5);

    ledIsOn = Led_IsOn(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((ledIsOn)), (UNITY_INT)(UNITY_INT16)((

   1

   )), (

   ((void *)0)

   ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_HEX16);

}





void test_ParameterLimits(void){

    Led_TurnOn(17);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_HEX16);



    ledsVirtuales = 0xFFFF;

    Led_TurnOff(17);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_HEX16);



    ledsVirtuales = 0xFFFF;

    Led_TurnOff(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_HEX16);



    ledsVirtuales = 0x0000;

    Led_TurnOff(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(97), UNITY_DISPLAY_STYLE_HEX16);



}
