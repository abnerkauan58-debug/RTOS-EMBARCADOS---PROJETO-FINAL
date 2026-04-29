#include "mqtt_manager.h"
#include "mqtt_client.h"

static esp_mqtt_client_handle_t client;

void mqtt_manager_init(void)
{
    esp_mqtt_client_config_t mqtt_cfg = {
        .broker.address.uri = CONFIG_BROKER_URL,
    };

    client = esp_mqtt_client_init(&mqtt_cfg);
    esp_mqtt_client_start(client);
}

void mqtt_publish_sensor_data(float temp, float hum, int light)
{
    char msg[64];

    snprintf(msg, sizeof(msg), "%.2f", temp);
    esp_mqtt_client_publish(client, "temperatura", msg, 0, 1, 0);

    snprintf(msg, sizeof(msg), "%.2f", hum);
    esp_mqtt_client_publish(client, "umidade", msg, 0, 1, 0);

    snprintf(msg, sizeof(msg), "%d", light);
    esp_mqtt_client_publish(client, "luminosidade", msg, 0, 1, 0);
}

void mqtt_task(void *pvParameters)
{
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
