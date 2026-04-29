#include "keypad_manager.h"
#include "buzzer.h"

void keypad_init(void)
{
}

void keypad_task(void *pvParameters)
{
    while (1) {
        // Ler teclado
        // Desligar buzzer
        vTaskDelay(pdMS_TO_TICKS(200));
    }
}
