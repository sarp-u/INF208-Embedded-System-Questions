#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define GPIO_DEVICE "/dev/gpiochip0"
int main(void) {

	struct gpiod_chip *chip = NULL;
	struct gpiod_line *line = NULL;
	int req = -1;
	int value = 0;
	int toplam = 0;
	int k = 8;
	float girdi = 0;
	float pwm;

	chip = gpiod_chip_open(GPIO_DEVICE);
	if(!chip){
	    return 1;
	}

	printf("0 ile 100 arasında bir sayı giriniz: ");
	scanf("%f",&girdi);
	if(girdi<0 || girdi>100){
		printf("Hatalı format");
		return -1;
	}

	for(int i=0; i<4; i++){
		line = gpiod_chip_get_line(chip, i);
		req = gpiod_line_request_input(line, "gpio_state");
		value = gpiod_line_get_value(line);
		printf("Pin %d:%d ", i, value);
		toplam += k * value;
		k = k/2;
	}

	pwm = (toplam * girdi)/100;
	printf("\nPeriyot: %d \n", toplam);
	while(1){
		gpiod_ctxless_set_value(GPIO_DEVICE, 4, 1, false, "gpio_toggle", NULL, NULL);
		printf("Pin 4 ist %d %.2f sek. lang\n", 1, pwm);
		sleep(pwm);
		gpiod_ctxless_set_value(GPIO_DEVICE, 4, 0, false, "gpio_toggle", NULL, NULL);
		printf("Pin 4 ist %d %.2f sek. lang\n", 0, toplam-pwm);
		sleep(toplam-pwm);

	}
	gpiod_chip_close(chip);
	return 0;

	return EXIT_SUCCESS;
}
