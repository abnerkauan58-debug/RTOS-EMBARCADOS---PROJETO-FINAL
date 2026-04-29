#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

typedef struct {
    float temperature;
    float humidity;
    int luminosity;
} sensor_data_t;

void sensor_manager_init(void);
void sensor_task(void *pvParameters);
sensor_data_t sensor_get_data(void);

#endif
