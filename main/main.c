#include <stdio.h>

#include "../components/led_strip/src/led_strip_rmt_ws2812.c"
#include "../components/blocking_delay/blocking_delay.c"
#include "../components/led_control/include/led_control.c"

// #include "../components/blocking_delay/include/blocking_delay.h"
// #include "../components/led_strip/include/led_strip.h"
// #include "../components/led_control/include/led_control.h"

int app_main(void) {
  // Crear un puntero a la estructura led_strip_t
  led_strip_t *strip;

  // Inicializar el LED
  if (led_rgb_init(&strip) != ESP_OK) {
      printf("Error al inicializar la tira de LED\n"); // Si hay error se imprime por pantalla
      return -1;
  }

  while (1) {
    // Encender el LED en color personalizado
    encender_led_custom(strip, 0, 102, 0, 102);
    delay_ms(1000);
    apagar_led(strip, 0);
    delay_ms(1000);

    // Funcion que recorre todos los colores predeterminados  
    color_cycle(strip, 500);
    }

  // Limpiar antes de salir
  strip->clear(strip, 100);
  strip->del(strip);
  return 0;
}

