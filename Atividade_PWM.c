#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

//#define SERVO_PIN 12  // Descomentar essa linha caso esteja testando com led RGB na BitDogLab
#define SERVO_PIN 22  // GPIO do servomotor
#define PWM_FREQ 50   // Frequência do PWM em Hz
#define WRAP_VALUE 20000 // Valor para período de 20ms (50Hz)

void set_servo_position(uint slice_num, uint16_t pulse_width) {
    pwm_set_gpio_level(SERVO_PIN, pulse_width);
}

int main() {
    stdio_init_all();

    sleep_ms(3000); // Aguarda 3 segundo antes de iniciar

    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 125.0f);  // Ajuste para 50Hz
    pwm_config_set_wrap(&config, WRAP_VALUE);
    pwm_init(slice_num, &config, true);

    set_servo_position(slice_num, 2400); // 180 graus
    sleep_ms(5000);

    set_servo_position(slice_num, 1470); // 90 graus
    sleep_ms(5000);

    set_servo_position(slice_num, 500); // 0 graus
    sleep_ms(5000);

    // Movimentação suave entre 0 e 180 graus
    while (1) {
        for (uint16_t pulse = 500; pulse <= 2400; pulse += 5) {
            set_servo_position(slice_num, pulse);
            sleep_ms(10);
        }
        for (uint16_t pulse = 2400; pulse >= 500; pulse -= 5) {
            set_servo_position(slice_num, pulse);
            sleep_ms(10);
        }
    }
}
