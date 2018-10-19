
void DHT1X_init(DHT1X_DEV* base,void (*read)(uint8_t,uint16_t,uint8_t*,uint8_t)	){

	base->dht1x_read = read;

	base->badrh_crc_count = 0;
	base->goodrh_crc_count = 0;
	base->badtp_crc_count = 0;
	base->goodtp_crc_count = 0;
}
void DHT1X_TemperHumidity(DHT1X_DEV* base,float *temp_adcval,float *rh_adcval)
{	
	float temp = 0;
	float remp = 0;
	uint8_t sum = 0;
	uint8_t ReadBuf[8] = {0x00};
	base->read(0XB8,0xE000,ReadBuf,5);
	remp = ReadBuf[0];
	remp = remp+ReadBuf[1]/10.0;

	temp = ReadBuf[2];
	if(ReadBuf[3]&0x80){//负数
		temp = -(temp + ReadBuf[3]/10);
	}
	*temp_adcval = temp;
	*rh_adcval	= remp;
	sum = ReadBuf[0]+ReadBuf[1]+ReadBuf[2]+ReadBuf[3];
	if(ReadBuf[4] != sum){
		*temp_adcval = 0;
		*rh_adcval = 0;
		return 1;
	}
	return 0;

}