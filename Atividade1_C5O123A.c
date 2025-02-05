#include "pico/stdlib.h"
#include <stdio.h>

#define LED_RED 13
#define LED_BLUE 12
#define LED_GREEN 11

typedef enum {
    STATE_RED,
    STATE_BLUE,
    STATE_GREEN
} TrafficLightState;

TrafficLightState current_state = STATE_RED;

bool timer_callback(struct repeating_timer *t) {
    gpio_put(LED_RED, 0);
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);

    switch (current_state) {
        case STATE_RED:
            gpio_put(LED_RED, 1);
            current_state = STATE_BLUE;
            break;
        case STATE_BLUE:
            gpio_put(LED_BLUE, 1);
            current_state = STATE_GREEN;
            break;
        case STATE_GREEN:
            gpio_put(LED_GREEN, 1);
            current_state = STATE_RED;
            break;
    }
    return true;
}

int main() {
    stdio_init_all();
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, timer_callback, NULL, &timer);

    while (true) {
        printf("Semáforo funcionando...\n");
        sleep_ms(1000);
    }
    return 0;
}
