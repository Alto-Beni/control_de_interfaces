#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

/**
 * @brief Programa principal
*/
int main(void) {
  // Inicializo el USB
  stdio_init_all();
  int suma = 0;
  int suma_apagada = 0;
  if (cyw43_arch_init()) {
        printf("Wi-Fi init failed");
        return -1;
    }
  // Mensaje por USB
  printf("\nHola mundo!\n");

  while (true) {
    // Prendo LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    // Mensaje por USB
    suma += 1;
    printf("LED Encendido %d\n", suma);
   
    // Demora
    sleep_ms(100);
    // Apago LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    suma_apagada += 1;
    // Mensaje por USB
    printf("Led Apagado %d\n", suma_apagada);
    // Demora
    sleep_ms(100);
  }
  return 0;
}