#include <stdio.h>
#include "pico/stdlib.h"

/**
 * @brief Programa principal
 */
int main(void)
{
    // Inicializo el USB
    stdio_init_all();
    // Demora para esperar la conexion
    sleep_ms(1000);

    // Inicializacion de GPIO con gpio_init()
    int a=0;
    /* Habilito el GPIO25 (LED)
    gpio_init(PICO_DEFAULT_LED_PIN);
    GPIO25 como salida
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    Configuracion de entrada/salida con gpio_set_dir()

    */
    gpio_init(4);
    gpio_set_dir(4, GPIO_OUT);
    gpio_init(5);
    gpio_set_dir(5, GPIO_OUT);
    gpio_init(6);
    gpio_set_dir(6, GPIO_OUT);
    gpio_init(7);
    gpio_set_dir(7, GPIO_OUT);
    
    while (true)
    {

        gpio_put(4, 1);
        sleep_ms(1000);
        gpio_put(4, 0);

        gpio_put(5, 1);
        sleep_ms(1000);
        gpio_put(5, 0);
        
        gpio_put(6, 1);
        sleep_ms(1000);
        gpio_put(6, 0);
        
        gpio_put(7, 1);
        sleep_ms(1000);
        gpio_put(7, 0);


        gpio_put(4, 1);
        gpio_put(5, 1);
        sleep_ms(2000);
        gpio_put(4, 0);
        gpio_put(5, 0);                 


        
    }
    return 0;
}