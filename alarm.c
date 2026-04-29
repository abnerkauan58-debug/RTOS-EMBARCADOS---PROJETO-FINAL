#include "alarm_manager.h"
#include "sensor_manager.h"
#include "buzzer.h"
#include "storage_manager.h"

void alarm_manager_init(void)
{
}

void alarm_task(void *pvParameters)
{
    while (1) {
        sensor_data_t data = sensor_get_data();

        if (data.temperature > 30.0) {
            buzzer_on();
            storage_log_alarm("TEMP_HIGH");
        }

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
