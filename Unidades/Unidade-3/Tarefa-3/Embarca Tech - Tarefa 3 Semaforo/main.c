// https://wokwi.com/projects/417804472114568193
// Declarando bibliotecas
#include <stdio.h>                   // Biblioteca padrão para funções de entrada e saída, como printf
#include "pico/stdlib.h"             // Biblioteca padrão do Raspberry Pi Pico, inclui funções para controlar GPIO e temporização
#include "hardware/pwm.h"            // Biblioteca para controlar PWM (Pulse Width Modulation), usada para o buzzer
#include "hardware/clocks.h"         // Biblioteca para manipulação de clocks do sistema, necessária para o ajuste da frequência do buzzer

// Configuração dos pinos dos LEDs
#define LED_VERMELHO 2               // Pino do LED vermelho
#define LED_AMARELO 3                // Pino do LED amarelo
#define LED_VERDE 4                  // Pino do LED verde
#define LED_PEDESTRE 5               // Pino do LED verde para pedestres

const uint BOTAO_PEDESTRE = 6;       // Pino do botão de pedestres (constante para não ser alterado)
#define BUZINA_PEDESTRE 7            // Pino do buzzer (alarme sonoro)

#define FREQUENCIA_BUZINA 2000       // Frequência do som do buzzer

// Inicialização dos LEDs
void inicializar_leds() {
    // Configura os pinos dos LEDs como saída
    gpio_init(LED_PEDESTRE);
    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);

    // Define a taxa de slew rate para evitar ruído de sinal
    gpio_set_slew_rate(LED_PEDESTRE, GPIO_SLEW_RATE_SLOW);
    gpio_set_slew_rate(LED_VERMELHO, GPIO_SLEW_RATE_SLOW);
    gpio_set_slew_rate(LED_AMARELO, GPIO_SLEW_RATE_SLOW);
    gpio_set_slew_rate(LED_VERDE, GPIO_SLEW_RATE_SLOW);

    // Define os pinos como saída
    gpio_set_dir(LED_PEDESTRE, GPIO_OUT);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
}

// Função para controlar o estado do semáforo de carros
void semaforo_configurar(bool vermelho, bool amarelo, bool verde) {
    gpio_put(LED_VERMELHO, vermelho);   // Acende o LED vermelho se 'vermelho' for verdadeiro
    gpio_put(LED_AMARELO, amarelo);    // Acende o LED amarelo se 'amarelo' for verdadeiro
    gpio_put(LED_VERDE, verde);       // Acende o LED verde se 'verde' for verdadeiro
}

// Função para controlar o LED do semáforo de pedestres
void led_pedestre_configurar(bool verde) {
    gpio_put(LED_PEDESTRE, verde); // Acende ou apaga o LED de pedestres com base no valor de 'verde'
}

// Inicialização do PWM para o buzzer (usando a técnica Pulse Width Modulation)
void inicializar_pwm_buzzer(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM);               // Configura o pino para função PWM
    uint slice_num = pwm_gpio_to_slice_num(pin);          // Obtém o número do slice PWM associado ao pino
    pwm_config config = pwm_get_default_config();         // Obtém a configuração padrão do PWM

    // Define o divisor de clock correto para a frequência do buzzer
    pwm_config_set_clkdiv(&config, (float)clock_get_hz(clk_sys) / (FREQUENCIA_BUZINA * 4096));
    pwm_init(slice_num, &config, true);                   // Inicializa o PWM com a configuração
    pwm_set_gpio_level(pin, 0);                            // Inicia com o buzzer desligado
}

// Função para emitir som intermitente no buzzer
void beep(uint pin, uint duration_ms) {
    uint slice_num = pwm_gpio_to_slice_num(pin);  // Obtém o número do slice PWM associado ao pino
    uint cycles = duration_ms / 200;              // Calcula quantos ciclos intermitentes o buzzer fará
    for (uint i = 0; i < cycles; i++) {
        pwm_set_gpio_level(pin, 32768);  // Liga o buzzer (valor PWM alto)
        sleep_ms(100);                  // Mantém o buzzer ligado por 100ms
        pwm_set_gpio_level(pin, 0);      // Desliga o buzzer (valor PWM baixo)
        sleep_ms(100);                  // Mantém o buzzer desligado por 100ms
    }
}

// Função para verificar o botão com debounce
bool botao_pressionado() {
    if (gpio_get(BOTAO_PEDESTRE) == 0) {  // Verifica se o botão foi pressionado (pino em nível baixo)
        sleep_ms(50);                 // Aguarda 50ms para evitar ruído (debounce)
        return gpio_get(BOTAO_PEDESTRE) == 0; // Retorna o estado final após o debounce
    }
    return false; // Retorna falso se o botão não estiver pressionado
}

// Ciclo do semáforo de pedestres
void sequencia_pedestre() {
    semaforo_configurar(false, true, false); // Acende o LED amarelo por 2 segundos
    sleep_ms(2000);                          // Espera 2 segundos

    semaforo_configurar(true, false, false); // Acende o LED vermelho dos carros
    led_pedestre_configurar(true);           // Acende o LED verde dos pedestres
    beep(BUZINA_PEDESTRE, 15000);            // Emite som intermitente no buzzer por 15 segundos
    led_pedestre_configurar(false);          // Desliga o LED verde dos pedestres
}

// Ciclo normal do semáforo de carros
void sequencia_semaforo() {
    semaforo_configurar(false, false, true); // Acende o LED verde para os carros
    for (int i = 0; i < 8000; i++) {  // Ciclo de 8 segundos
        if (botao_pressionado()) {    // Verifica se o botão foi pressionado
            sequencia_pedestre();     // Inicia o ciclo de pedestres
            return;                   // Sai do ciclo normal
        }
        sleep_ms(1);  // Espera 1ms
    }

    semaforo_configurar(false, true, false); // Acende o LED amarelo para os carros
    sleep_ms(2000);                   // Espera 2 segundos

    semaforo_configurar(true, false, false); // Acende o LED vermelho para os carros
    for (int i = 0; i < 10000; i++) { // Ciclo de 10 segundos
        if (botao_pressionado()) {    // Verifica se o botão foi pressionado
            sequencia_pedestre();     // Inicia o ciclo de pedestres
            return;                   // Sai do ciclo normal
        }
        sleep_ms(1);  // Espera 1ms
    }
}

// Função principal
int main() {
    stdio_init_all();  // Inicializa a biblioteca padrão (necessária para o uso de printf e outros)

    // Inicializa LEDs e botão
    inicializar_leds();  // Inicializa os pinos dos LEDs
    gpio_init(BOTAO_PEDESTRE);  // Inicializa o pino do botão
    gpio_set_dir(BOTAO_PEDESTRE, GPIO_IN);  // Configura o pino do botão como entrada
    gpio_pull_up(BOTAO_PEDESTRE);  // Habilita o resistor pull-up interno no pino do botão

    // Inicializa o buzzer
    inicializar_pwm_buzzer(BUZINA_PEDESTRE);  // Inicializa o buzzer para emissão de som

    // Loop principal
    while (true) {
        sequencia_semaforo();  // Executa o ciclo do semáforo para os carros
    }
}
