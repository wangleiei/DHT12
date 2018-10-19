#ifndef __DHT1X
#define __DHT1X 
#include <stdint.h>

typedef void (*DHT1X_READ)(uint8_t i2caddr,uint16_t regaddr,uint8_t*databuf,uint8_t datalen);
typedef struct DHT1X_DEV
{
	DHT1X_READ  dht1x_read;
	float temperature;
	float humidity;
	uint16_t badrh_check_count;
	uint16_t goodrh_check_count;
	uint16_t badtp_check_count;
	uint16_t goodtp_check_count;

}DHT1X_DEV;
// read参数是i2c读函数，要求i2c的地址宽度是1字节
void DHT1X_init(DHT1X_DEV* base,void (*read)(uint8_t,uint16_t,uint8_t*,uint8_t)	);

void DHT1X_TemperHumidity(DHT1X_DEV* base,float *temp_adcval,float *rh_adcval);
#endif