#include "oled_display.h"
#include "sensor_manager.h"

void oled_init(void)
{
}

void oled_task(void *pvParameters)
{
    while (1) {
        sensor_data_t data = sensor_get_data();
        // Atualizar display
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
