/**
* Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
int main(){
	stdio_init_all();
	if (cyw43_arch_init()) {
			printf ("Wi-Fi init failed");
		return -1;
	}
	while(true) {
		cyw43_arch_gpio_put (CYW43_WL_GPIO_LED_PIN,1);
		printf("Led on\n");
		sleep_ms (2000);
		
		cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN,0);
		printf("Led off\n");
		sleep_ms(2000);
	}
}