/**
* Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
 
int main(void){
	stdio_init_all();
	
	printf("Presiona\n");
	printf("'T' para temperatura\n");
	printf("'v' para voltaje\n");
	
	adc_init();
	adc_set_temp_sensor_enabled(true);
	adc_select_input(4);
	char select = getchar();
while(select == 't'){
	uint16_t raw = adc_read();
	const float conversion_factor = 3.3/ 4096;	
	float result = raw * conversion_factor;
	float temp = 27 -(result - 0.706)/0.001721;
	printf ("temp = %f C \n",temp);
	sleep_ms(1000);
		
	}

while(select == 'v'){
		uint16_t raw = adc_read();
		const float volts = 3.3/ 4096;
		const float mv = volts * 100;	
		printf ("milivolts = %f C \n",mv);
		sleep_ms(1000);
		
	}
}