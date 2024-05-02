#include "../../led_strip/include/led_strip.h"
#include "led_control.h"


void encender_led(led_strip_t *strip, uint32_t index, char color){

    switch (color){
        case 'R':
            strip->set_pixel(strip, index, 255, 0, 0);
            break;
        case 'G':
            strip->set_pixel(strip, index, 0, 255, 0);
            break;
        case 'B':
            strip->set_pixel(strip, index, 0, 0, 255);
            break;
        case 'W':
            strip->set_pixel(strip, index, 255, 255, 255);
            break;
        case 'Y':
            strip->set_pixel(strip, index, 255, 255, 0);
            break;
        case 'V':
            strip->set_pixel(strip, index, 255, 0, 255);
            break;
        case 'C':
            strip->set_pixel(strip, index, 0, 255, 255);
            break;

        default:
            strip->set_pixel(strip, index, 255, 255, 255);
            break;
    }
    strip->refresh(strip, 100);
   } 

void apagar_led(led_strip_t *strip, uint32_t index){
    strip->set_pixel(strip, index, 0, 0, 0);
    strip->refresh(strip, 100);
}

void encender_led_custom(led_strip_t *strip, uint32_t index, uint32_t r, uint32_t g, uint32_t b){
    strip->set_pixel(strip, index, r, g, b);
    strip->refresh(strip, 100); 
}

void demo_led(led_strip_t *strip){
      encender_led(strip, 0, 'R');
      delay_s(1);
      apagar_led(strip, 0);
      delay_ms(1000);

      encender_led(strip, 0, 'G');
      delay_s(1);
      apagar_led(strip, 0);
      delay_ms(1000);

      encender_led(strip, 0, 'B');
      delay_s(1);
      apagar_led(strip, 0);
      delay_ms(1000);

      encender_led(strip, 0, 'Y');
      delay_s(1);
      apagar_led(strip, 0);
      delay_ms(1000);

      encender_led(strip, 0, 'V');
      delay_s(1);
      apagar_led(strip, 0);
      delay_ms(1000);

      encender_led(strip, 0, 'C');
      delay_s(1);
      apagar_led(strip, 0);
      delay_ms(1000);

      encender_led(strip, 0, 'W');
      delay_s(1);
      apagar_led(strip, 0);
      delay_ms(1000);

    }
