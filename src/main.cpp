#include <Arduino.h>
#include <String.h>
#include <Wire.h>
#include <SPI.h>

#include <Adafruit_GFX.h>
#include "..\lib\TFT_ILI9163C\TFT_ILI9163C.h" 
#include <Adafruit_BMP280.h>

#include "..\lib\DS3231\DS3231.h"

#include "..\lib\UTF8RUS\utf8rus.h"

#include "..\lib\COLORS\Colors.c"

//PINS to TFT
#define __CS 10
#define __DC 9
#define __RES 8
#define SEALEVELPRESSURE_HPA (1013.25)

TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC, __RES);
Adafruit_BMP280 bmp;



DS3231 clock;
RTCDateTime dt;

String second, minute, hour;

void setup() {
  Serial.begin(9600);
  Serial.println("Initialize DS3231");
  clock.begin();
  tft.begin();
  // if(!bmp.begin())
  //  {
  //     Serial.println("BMP280 SENSOR ERROR"); // Выводим сообщение об ошибке
	//      while(1); // Переходим в бесконечный цикл
	//  }

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
  
  // // Выводим значение температуры

	//  Serial.print(F("Temperature = "));

	//  Serial.print(bmp.readTemperature()); // Функция измерения температуры

	//  Serial.println(" *C");

	  



	//  // Выводим значение атмосферного давления

	//  Serial.print(F("Pressure = "));

	//  Serial.print(bmp.readPressure()); // Функция измерения атм. давления

	//  Serial.println(" Pa");	  



	//  // Выводим значение высоты

	//  Serial.print(F("Approx altitude = "));

	//  Serial.print(bmp.readAltitude(1013.25)); // Функция измерения высоты

	//  Serial.println(" m");

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
 
  tft.setCursor(78,45);  
  tft.setTextColor(RED,BLACK);                                 
  tft.print(bmp.readTemperature());


  tft.setTextSize(1); 
  tft.setCursor(4,65);                                        
  tft.setTextColor(YELLOW,BLACK); 
  tft.print(utf8rus("Давление: "));
 
  tft.setCursor(78,65);  
  tft.setTextColor(RED,BLACK);                                 
  tft.print(bmp.readTemperature());

  delay(500);
}