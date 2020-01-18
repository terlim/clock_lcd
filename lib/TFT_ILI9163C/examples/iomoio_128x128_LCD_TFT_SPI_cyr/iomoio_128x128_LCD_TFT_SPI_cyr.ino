// Видеообзоры и уроки работы с ARDUINO на YouTube-канале IOMOIO: https://www.youtube.com/channel/UCmNXABaTjX_iKH28TTJpiqA

#include <SPI.h>            // Подключаем библиотеку для работы с устройством по интерфейсу SPI
#include <Adafruit_GFX.h>   // Подключаем библиотеку для работы с текстом и графикой
#include <TFT_ILI9163C.h>   // Подключаем библиотеку программных драйверов для работы с дисплеем 1.44 128x128 SPI 

// В следующих 8-и строках опеределяем названия и соответствующие им RGB обозначения цветов, которые будем выводить на дисплей
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800  
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF

#define __CS 10                                           // Определяем пин к которому подключен разъем CS дисплея
#define __DC 9                                            // Определяем пин к которому подключен разъем A0 дисплея
#define __RES 8                                           // Определяем пин к которому подключен разъем RESET дисплея
TFT_ILI9163C display = TFT_ILI9163C(__CS, __DC, __RES);   // Связываем объект display с библиотекой TFT_ILI9163C и сообщаем библиотеке определенные для работы с дисплеем пины

// Начало функции обработки кириллических символов
String utf8rus(String source)     // Функция для конвертации русских символов из кодировки CP1251 в UTF8
{
  int i,k;
  String target;
  unsigned char n;
  char m[2] = { '0', '\0' };
  k = source.length(); i = 0;
  while (i < k) {
    n = source[i]; i++;
 
    if (n >= 0xBF){
      switch (n) {
        case 0xD0: {
          n = source[i]; i++;
          if (n == 0x81) { n = 0xA8; break; }
          if (n >= 0x90 && n <= 0xBF) n = n + 0x2F;
          break;
        }
        case 0xD1: {
          n = source[i]; i++;
          if (n == 0x91) { n = 0xB7; break; }
          if (n >= 0x80 && n <= 0x8F) n = n + 0x6F;
          break;
        }
      }
    }
    m[0] = n; target = target + String(m);
  }
  return target;
}
// Конец функции обработки кириллических симоволов

void setup() {
  display.begin();                                                // Иницализируем дисплей
}

void loop() {
  display.fillScreen();                                           // Очищаем дисплей перед выводом
  display.setTextSize(2);                                         // Определяем размер шрифта
  display.setCursor(10,5);                                        // Устанавливаем курсор в левый верхний угол области вывода
  display.setTextColor(YELLOW);                                   // Определяем цвет вывода на дисплей
  display.print(utf8rus("АБВГДЕЁЖЗ"));                            // Выводим строку на русском
  display.setCursor(10,25);                                       // Устанавливаем курсор в левый верхний угол области вывода
  display.setTextColor(RED);                                      // Определяем цвет вывода на дисплей
  display.print(utf8rus("ИЙКЛМНОПР"));                            // Выводим строку на русском
  display.setCursor(10,45);                                       // Устанавливаем курсор в левый верхний угол области вывода
  display.setTextColor(GREEN);                                    // Определяем цвет вывода на дисплей
  display.print(utf8rus("СТУФХЦЧШЩ"));                            // Выводим строку на русском
  display.setCursor(25,65);                                       // Устанавливаем курсор в левый верхний угол области вывода
  display.setTextColor(MAGENTA);                                  // Определяем цвет вывода на дисплей
  display.print(utf8rus("ЪЫЬЭЮЯ"));                               // Выводим строку на русском

  iomoio();                                                       // Вызываем функцию вывода надписи IOMOIO
  delay(3000);                                                    // Задержка 3 секунды
  
  display.fillScreen();                                           // Очищаем дисплей перед выводом
  display.setTextSize(2);                                         // Определяем размер шрифта
  display.setCursor(10,5);                                        // Устанавливаем курсор в левый верхний угол области вывода
  display.setTextColor(YELLOW);                                   // Определяем цвет вывода на дисплей
  display.print(utf8rus("абвгдеёжз"));                            // Выводим строку на русском
  display.setCursor(10,25);                                       // Устанавливаем курсор в левый верхний угол области вывода
  display.setTextColor(RED);                                      // Определяем цвет вывода на дисплей
  display.print(utf8rus("ийклмнопр"));                            // Выводим строку на русском
  display.setCursor(10,45);                                       // Устанавливаем курсор в левый верхний угол области вывода
  display.setTextColor(GREEN);                                    // Определяем цвет вывода на дисплей
  display.print(utf8rus("стуфхцчшщ"));                            // Выводим строку на русском
  display.setCursor(25,65);                                       // Устанавливаем курсор в левый верхний угол области вывода
  display.setTextColor(MAGENTA);                                  // Определяем цвет вывода на дисплей
  display.print(utf8rus("ъыьэюя"));                               // Выводим строку на русском

  iomoio();                                                       // Вызываем функцию вывода надписи IOMOIO
  delay(3000);                                                    // Задержка 3 секунды
    
  display.fillScreen();                                           // Очищаем дисплей перед выводом
  display.setTextSize(2);                                         // Определяем размер шрифта
  display.setCursor(5,5);                                         // Устанавливаем курсор в левый верхний угол области вывода
  display.setTextColor(YELLOW);                                   // Определяем цвет вывода на дисплей
  display.print("1234567890");                                    // Выводим числа
  display.setCursor(30,25);                                       // Устанавливаем курсор в левый верхний угол области вывода
  display.setTextColor(RED);                                      // Определяем цвет вывода на дисплей
  display.print(utf8rus("!@#\xBC\xBD"));                          // Выводим примеры спецсимволов
  display.setCursor(5,45);                                        // Устанавливаем курсор в левый верхний угол области вывода
  display.setTextColor(GREEN);                                    // Определяем цвет вывода на дисплей
  display.print(utf8rus("1\x80\C 2\x8A\x82 3\x85"));              // Выводим примеры спецсимволов
  display.setCursor(5,65);                                        // Устанавливаем курсор в левый верхний угол области вывода
  display.setTextColor(MAGENTA);                                  // Определяем цвет вывода на дисплей
  display.print("AaBbCcDdEe");                                    // Выводим латинские буквы

  iomoio();                                                       // Вызываем функцию вывода надписи IOMOIO
  delay(3000);                                                    // Задержка 3 секунды
}

// Начало функции вывода надписи IOMOIO
void iomoio() {                                                   // Функция вывода надписи IOMOIO
  display.setTextSize(3); 
  display.setCursor(9,95);
  display.setTextColor(YELLOW);
  display.print("I");
  display.setTextColor(RED);
  display.print("O");
  display.setTextColor(GREEN);
  display.print("M");
  display.setTextColor(MAGENTA);
  display.print("O");
  display.setTextColor(BLUE);
  display.print("I");
  display.setTextColor(CYAN);
  display.print("O");
}
// Конец функции вывода надписи IOMOIO
