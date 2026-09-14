#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

/**
 * @brief Programa principal
 */

void setup_pwm(uint pin, uint *slice);
void set_speed(uint slice, uint chan, uint8_t duty);
void avanzar();
void retroceder();
void izq();
void der();

int main(void)
{
    // Inicializo el USB
    stdio_init_all();
    // Demora para esperar la conexion
    sleep_ms(1000);

    // Inicializacion de GPIO con gpio_init()
    int a=0;

    gpio_init(IN1);
    gpio_set_dir(IN1, GPIO_OUT);
    gpio_init(IN2);
    gpio_set_dir(IN2, GPIO_OUT);
    gpio_init(IN3);
    gpio_set_dir(IN3, GPIO_OUT);
    gpio_init(IN4);
    gpio_set_dir(IN4, GPIO_OUT);
    
    while (true){
        gpio_put(IN1, 1);
        sleep_ms(1000);
        gpio_put(IN1, 0);

        gpio_put(IN2, 1);
        sleep_ms(1000);
        gpio_put(IN2, 0);
        
        gpio_put(IN3, 1);
        sleep_ms(1000);
        gpio_put(IN3, 0);
        
        gpio_put(IN4, 1);
        sleep_ms(1000);
        gpio_put(IN4, 0);


        gpio_put(IN1, 1);
        gpio_put(IN2, 1);
        sleep_ms(2000);
        gpio_put(IN1, 0);
        gpio_put(IN2, 0);        
    }
    return 0;
}

void setup_pwm(uint pin, uint *slice){
    gpio_set_function(pin, GPIO_FUNC_PWM);
    *slice =  pwm_gpio_to_slice_num(pin);
    pwm_set_wrap(*slice, 225);
    pwm_set_clkdiv(*slice, 100.0f);
    pwm_set_enabled(*slice, true);
}

void set_speed(uint slice, uint chan, uint8_t duty){
    pwm_set_chan_level(slice, chan, duty);
}

void avanzar(){
    gpio_put(IN1, 1);
    gpio_put(IN2, 0);
    gpio_put(IN3, 1);
    gpio_put(IN4, 0);
}
void retroceder(){
    gpio_put(IN1, 0);
    gpio_put(IN2, 1);
    gpio_put(IN3, 0);
    gpio_put(IN4, 1);
}
void izq(){
    gpio_put(IN1, 0);
    gpio_put(IN2, 0);
    gpio_put(IN3, 1);
    gpio_put(IN4, 0);
}
void der(){
    gpio_put(IN1, 1);
    gpio_put(IN2, 0);
    gpio_put(IN3, 0);
    gpio_put(IN4, 0);
}
