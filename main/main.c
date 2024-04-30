#include <stdio.h>

#include "../components/led_strip/include/led_strip.h"
#include "../components/led_strip/src/led_strip_rmt_ws2812.c"
#include "../components/blocking_delay/include/blocking_delay.h"
#include "../components/blocking_delay/blocking_delay.c"
#include "../components/led_control/include/led_control.c"
#include "../components/led_control/include/led_control.h"

int app_main(void) {
  // Crear un puntero a la estructura led_strip_t
  led_strip_t *strip;

   // Inicializar el LED
    if (led_rgb_init(&strip) != ESP_OK) {
        printf("Error al inicializar la tira de LED\n"); // Si hay error se imprime por pantalla
        return -1;
    }
  
  //El bucle se ejecuta 3 veces
  while (1) {
    // Encender el LED en blanco
    printf("Encendiendo el LED en blanco\n");
    encender_led(strip, 0);

    // Esperamos un tiempo x en segundos
    printf("Esperando 2 segundos\n");
    delay_s(2);

    // Apagar el LED
    printf("Apagando el LED\n");
    apagar_led(strip, 0);

    // Esperamos un tiempo x en mili-segundos 
    delay_ms(1000);
  }

  // Limpiar antes de salir
  strip->clear(strip, 100);
  strip->del(strip);
  return 0;
}

// int app_main(void) {
//     led_strip_t *strip;
//     if (led_rgb_init(&strip) != ESP_OK) {
//         printf("Error al inicializar la tira de LED\n");
//         return -1;
//     }
//
// for (int i = 0; i < 3; i++) {
//     // Configurar el primer LED en rojo
//     strip->set_pixel(strip, 0, 255, 255, 255);
//     strip->refresh(strip, 100);
//     esp_rom_delay_us(1000000);
//     
//     strip->set_pixel(strip, 0, 0, 0, 0);
//     strip->refresh(strip, 100);
//     esp_rom_delay_us(1000000);
//
//   }
//
//     // Limpiar antes de salir
//     strip->clear(strip, 100);
//     strip->del(strip);
//     return 0;
// }


