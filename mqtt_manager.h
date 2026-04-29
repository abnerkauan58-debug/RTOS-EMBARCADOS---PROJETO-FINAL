#ifndef MQTT_MANAGER_H
#define MQTT_MANAGER_H

void mqtt_manager_init(void);
void mqtt_publish_sensor_data(float temp, float hum, int light);
void mqtt_task(void *pvParameters);

#endif
