#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "ssd1306.h"
#include "font8x8_basic.h"
#include "spyrosoftImages.h"
#include <sys/time.h>
#include "driver/gpio.h"

#define CONFIG_SDA_GPIO 21
#define CONFIG_SCL_GPIO 22
#define CONFIG_RESET_GPIO 15
#define CONFIG_OFFSETX 2
#define tag "OLED"

SSD1306_t dev;
uint8_t buff[1024];

void display_sendImage(uint8_t * image, bool invertImages);
void display_invertEverythingNow(void) {
	
}

void oled_init(void)
{
	i2c_master_init(&dev, CONFIG_SDA_GPIO, CONFIG_SCL_GPIO, CONFIG_RESET_GPIO);
	ssd1306_init(&dev, 128, 64);
    ssd1306_clear_screen(&dev, false);
	ssd1306_contrast(&dev, 0xff);

	display_sendImage(image_menuItem1Selected, false);
	//gpio_reset_pin(14);	
	//gpio_set_direction(14, GPIO_MODE_INPUT);
	//gpio_set_pull_mode(14, GPIO_PULLUP_ENABLE);
}

void display_sendChar(uint8_t * image, bool invertImages, int xpos, int ypos, int width, int height) {
	ssd1306_bitmaps(&dev, xpos, ypos, image, width, height, invertImages);
}

void display_sendImage(uint8_t * image, bool invertImages) {
	ssd1306_bitmaps(&dev, 0, 0, image, 128, 64, invertImages);
}

void display_sendImageTest(uint8_t * image, bool invertImages, int xdimension) {
	ssd1306_bitmaps(&dev, 0+2, 0, image, 128, 64, invertImages);
}

void spyrosoftLogo_scrollDown(void) {
ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo_6, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo_5, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo_4, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo_3, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo_2, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo_1, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo1, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo2, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo3, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo4, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo5, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo6, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo7, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo8, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo9, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo10, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo11, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo12, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo13, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo14, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo15, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo16, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo17, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo18, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo19, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo20, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo21, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogo22, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
	ssd1306_bitmaps(&dev, 0, 0, image_spyroLogoAllWhite, 128, 64, false);
	vTaskDelay(10 / portTICK_PERIOD_MS);
}