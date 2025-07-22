#include <stdio.h>
#include <stdarg.h>

typedef enum{
    TEMPERATURE_SENSOR,
    HUMIDITY_SENSOR,
} SensorType;

void processSensor(SensorType type, ...)
{
    va_list args;
    va_start(args, type);

    switch (type)
    {
        case TEMPERATURE_SENSOR:
            printf("Processing Temperature Sensor Data\n");
            break;
        case HUMIDITY_SENSOR:
            printf("Processing Humidity Sensor Data\n");
            break;
        default:
            printf("Unknown Sensor Type\n");
            break;
    }       

    va_end(args);
}

int main(void)
{
    return 0;
}