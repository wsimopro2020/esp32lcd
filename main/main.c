//#include <driver/i2c.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>

#include "esp32_lcd.c"

#define LCD_ADDR 0x27
#define SDA_PIN  21
#define SCL_PIN  22
#define LCD_COLS 16
#define LCD_ROWS 2

static char tag2[] = "LCD test";
void LCD_DemoTask(void* param);

void app_main(void)
{
    ESP_LOGI(tag2, "Starting up application");
    LCD_init(LCD_ADDR, SDA_PIN, SCL_PIN, LCD_COLS, LCD_ROWS);
    xTaskCreate(LCD_DemoTask, "Demo Task", 2048, NULL, 5, NULL);
}



void LCD_DemoTask(void* param)
{
    
     LCD_clearScreen();
    while (true) {
      
        LCD_setCursor(0, 0);
       
        LCD_writeStr("VEC ELECTRONIC");
        LCD_setCursor(0, 1);
        LCD_writeStr("LCD Library Demo");
        
        vTaskDelay(1500 / portTICK_RATE_MS);

       
    }
}