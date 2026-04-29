
```c
#include <stdio.h>
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "wifi_manager.h"
#include "mqtt_manager.h"
#include "sensor_manager.h"
#include "alarm_manager.h"
#include "storage_manager.h"
#include "oled_display.h"
#include "keypad_manager.h"
#include "rgb_led.h"
#include "buzzer.h"

void app_main(void)
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    storage_manager_init();
    oled_init();
    keypad_init();
    rgb_led_init();
    buzzer_init();
    wifi_manager_init();
    mqtt_manager_init();
    sensor_manager_init();
    alarm_manager_init();

    xTaskCreate(sensor_task, "sensor_task", 4096, NULL, 5, NULL);
    xTaskCreate(mqtt_task, "mqtt_task", 4096, NULL, 5, NULL);
    xTaskCreate(oled_task, "oled_task", 4096, NULL, 4, NULL);
    xTaskCreate(keypad_task, "keypad_task", 4096, NULL, 4, NULL);
    xTaskCreate(alarm_task, "alarm_task", 4096, NULL, 6, NULL);
}
