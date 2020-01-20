#include <Arduino.h>
#include <String.h>
#include <Wire.h>
#include <SPI.h>

#include <Adafruit_GFX.h>
#include "..\lib\TFT_ILI9163C\TFT_ILI9163C.h" 
#include "..\lib\AdafruitBME280\Adafruit_BME280.h"

#include "..\lib\DS3231\DS3231.h"

#include "..\lib\UTF8RUS\utf8rus.h"

#include "..\lib\COLORS\Colors.c"

//PINS to TFT
#define __CS 10
#define __DC 9
#define __RES 8
#define SEALEVELPRESSURE_HPA (1013.25)

TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC, __RES);
Adafruit_BME280 bme; // I2C



DS3231 clock;
RTCDateTime dt;

String second, minute, hour;

void setup() {
  Serial.begin(9600);
  Serial.println("Initialize DS3231");
  clock.begin();
  tft.begin();
  if(!bme.begin(0x76, &Wire))
    {
       Serial.println("BME280 SENSOR ERROR"); // Выводим сообщение об ошибке
	      while(1); // Переходим в бесконечный цикл
	  }

  //clock.setDateTime(__DATE__, __TIME__);
}


void loop() {
  clock.forceConversion();
  dt = clock.getDateTime();
  
  if (dt.second<10)
  {
    second = "0" + String(dt.second);
  } else {
    second =  String(dt.second);
  }
  if (dt.minute<10)
  {
    minute = "0" + String(dt.minute);
  } else {
    minute =  String(dt.minute);
  }
  if (dt.hour<10)
  {
    hour = "0" + String(dt.hour);
  } else {
    hour =  String(dt.hour);
  }
  
  

  tft.drawRect(2,1,126,127,GREEN);
  tft.setTextSize(1); 
  tft.setCursor(4,4);                                        
  tft.setTextColor(YELLOW,BLACK); 
  tft.print(utf8rus("Температура: "));
 
  tft.setCursor(78,4);  
  tft.setTextColor(RED,BLACK);                                 
  tft.print(clock.readTemperature());
  
  tft.setCursor(110,4);
  tft.setTextColor(YELLOW,BLACK);
  tft.print(utf8rus("\x80\C"));

  tft.setTextSize(2);
  tft.setCursor(7,20);
  tft.setTextColor(YELLOW,BLACK);
  tft.print(hour);
  
  tft.setCursor(35,20);
  tft.setTextColor(YELLOW,BLACK);
  tft.print(":");

  tft.setCursor(48,20);
  tft.setTextColor(YELLOW,BLACK);
  tft.print(minute);

  tft.setCursor(75,20);
  tft.setTextColor(YELLOW,BLACK);
  tft.print(":");

  tft.setCursor(88,20);
  tft.setTextColor(YELLOW,BLACK);
  tft.print(utf8rus(second));

  tft.setTextSize(1); 
  tft.setCursor(4,45);                                        
  tft.setTextColor(YELLOW,BLACK); 
  tft.print(utf8rus("Темп 2: "));
   
  tft.setCursor(65,45);  
  tft.setTextColor(RED,BLACK);                                 
  tft.print(bme.readTemperature());
  tft.setCursor(100,45);
  tft.setTextColor(YELLOW,BLACK);
  tft.print(utf8rus("\x80\C"));


  tft.setTextSize(1); 
  tft.setCursor(4,65);                                        
  tft.setTextColor(YELLOW,BLACK); 
  tft.print(utf8rus("Давление: "));
 
  tft.setCursor(65,65);  
  tft.setTextColor(RED,BLACK);                                 
  tft.print(bme.readPressure()*0.0075);
  

  tft.setTextSize(1); 
  tft.setCursor(4,85);                                        
  tft.setTextColor(YELLOW,BLACK); 
  tft.print(utf8rus("Влажность: "));
 
  tft.setCursor(65,85);  
  tft.setTextColor(RED,BLACK);                                 
  tft.print(bme.readHumidity());
  tft.setCursor(100,85);
  tft.setTextColor(YELLOW,BLACK);
  tft.print(utf8rus("%"));

  delay(500);
}