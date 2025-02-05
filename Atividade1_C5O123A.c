#include "pico/stdlib.h"
#include <stdio.h>

#define LED_RED 13
#define LED_BLUE 12
#define LED_GREEN 11
#define BUTTON_PIN 5

typedef enum {
    STATE_ALL_ON,
    STATE_TWO_ON,
    STATE_ONE_ON
} TrafficLightState;

TrafficLightState current_state = STATE_ALL_ON;
bool button_pressed = false;
absolute_time_t last_button_press_time = 0;


bool button_is_pressed() {
    absolute_time_t current_time = get_absolute_time();
    if (gpio_get(BUTTON_PIN) == 1 && (absolute_time_diff_us(last_button_press_time, current_time) > 200000)) {
        last_button_press_time = current_time;
        return true;
    }
    return false;
}


bool timer_callback(struct repeating_timer *t) {
 
    gpio_put(LED_RED, 0);
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);

    
    switch (current_state) {
        case STATE_ALL_ON:
            gpio_put(LED_RED, 1);
            gpio_put(LED_GREEN, 1);
            gpio_put(LED_BLUE, 1);
            current_state = STATE_TWO_ON;
            break;
        case STATE_TWO_ON:
            gpio_put(LED_RED, 1);
            gpio_put(LED_GREEN, 1);
            current_state = STATE_ONE_ON;
            break;
        case STATE_ONE_ON:
            gpio_put(LED_RED, 1); 
            current_state = STATE_ALL_ON;
            break;
    }
    return true;
}

int main() {
    stdio_init_all();

    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);
    gpio_init(BUTTON_PIN);

    
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);  

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, timer_callback, NULL, &timer); 

    while (true) {
        if (button_is_pressed() && current_state == STATE_ONE_ON) {
            printf("Botão pressionado, iniciando a mudança de estado!\n");
            button_pressed = true;
        }

        sleep_ms(100);
    }

    return 0;
}
