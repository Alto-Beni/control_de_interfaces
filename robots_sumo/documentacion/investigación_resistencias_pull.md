Las resistencias pull-up y pull-down se usan en circuitos digitales para fijar un estado lógico estable (alto o bajo) en un pin de entrada y evitar que capte ruido eléctrico cuando está en reposo.

¿Qué es una resistencia Pull-Up?

Conecta el pin de entrada al voltaje positivo (
) a través de una resistencia.
Mantiene el pin en un nivel lógico ALTO (HIGH / 1) por defecto.
Al pulsar un botón o activar un interruptor conectado a tierra (GND), el pin cambia a un nivel BAJO (LOW / 0).
Evita cortocircuitos y lecturas erráticas.

¿Qué es una resistencia Pull-Down?

Conecta el pin de entrada a tierra (GND) a través de una resistencia.
Mantiene el pin en un nivel lógico BAJO (LOW / 0) por defecto.
Al pulsar un botón o activar un interruptor conectado al voltaje positivo (
), el pin cambia a un nivel ALTO (HIGH / 1).
Valores recomendados y detalles
El valor más común para estas resistencias está entre 1K y 10K ohmios.
Muchos microcontroladores (como Arduino) incluyen resistencias pull-up internas que puedes activar mediante código.
las líneas fundamentales para configurar las resistencias en una Pi pico W son estas:

#include "pico/stdlib.h"
#include "hardware/gpio.h"

gpio_pull_up(BOTON); //pull up

gpio_pull_down(BOTON);//pull down

y esto sería un código de ejemplo:
gpio_init(BOTON);                    // Inicializa el GPIO
gpio_set_dir(BOTON, GPIO_IN);       // Lo configura como entrada

gpio_pull_up(BOTON);                // Pull-up
gpio_pull_down(BOTON);              // Pull-down

gpio_get(BOTON);                    / /Lee el GPIO

¿qué es un ADC?

Un ADC (Conversor Analógico-Digital) en un microcontrolador es un circuito interno o externo que transforma señales eléctricas continuas (como el voltaje de un sensor) en valores numéricos discretos que el procesador puede leer y manipular.

¿Cómo funciona?

• Señal analógica: Varía de manera continua en el tiempo (por ejemplo, la temperatura de un sensor que marca entre 0V y 5V).
• Resolución (Bits): Define cuántos valores posibles puede generar el conversor. Un ADC de 10 bits ofrece 1024 valores (2¹⁰, de 0 a 1023), mientras que uno de 12 bits ofrece 4095 valores (2¹², de 0 to 4095).
• Voltaje de referencia (\(V_{ref}\)): Es el límite máximo de voltaje que el ADC puede medir de forma precisa.