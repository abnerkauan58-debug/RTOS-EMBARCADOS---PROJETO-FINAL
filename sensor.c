#include "sensor_manager.h"
#include "mqtt_manager.h"

static sensor_data_t current_data;

void sensor_manager_init(void)
{
    // Inicialização ADC + DHT11
}

sensor_data_t sensor_get_data(void)
{
    return current_data;
}

void sensor_task(void *pvParameters)
{
    while (1) {
        current_data.temperature = 25.0;
        current_data.humidity = 60.0;
        current_data.luminosity = 500;

        mqtt_publish_sensor_data(
            current_data.temperature,
            current_data.humidity,
            current_data.luminosity
        );

        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}
