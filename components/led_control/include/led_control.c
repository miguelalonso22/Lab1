#include "../../led_strip/include/led_strip.h"
#include "led_control.h"


void encender_led(led_strip_t *strip, uint32_t index){
    strip->set_pixel(strip, index, 255, 255, 255);
    strip->refresh(strip, 100);
} 

void apagar_led(led_strip_t *strip, uint32_t index){
    strip->set_pixel(strip, index, 0, 0, 0);
    strip->refresh(strip, 100);
}


