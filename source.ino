//DFRobot.com
//Compatible with the Arduino IDE 1.0
//Library version:1.1

int btnStep_player1 = 2;
int btnOk_player1 = 3;
int btnStep_player2 = 5;
int btnOk_player2 = 4;
int led_player1 = 8;
int led_player2 = 9;


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{

  pinMode(led_player1,OUTPUT); //Светодиод первого игрока
  pinMode(led_player2,OUTPUT); //Светодиод второго игрока
  pinMode(btnStep_player1,INPUT); //Кнопка генерации числа #1
  pinMode(btnOk_player1,INPUT); //Кнопка ОК #1
  pinMode(btnStep_player2,INPUT); //Кнопка генерации числа #2
  pinMode(btnOk_player2,INPUT); //Кнопка ОК #2

}

void loop()
{

  int step = 1; //Текущий ход игрок #1 ходит первый.
  
  //Если ходит первый игрок, то светодиод 1 = максимум
  //На экране выводим сообщение о том, что ходит игрок RED(#1)
  //И запускаем процедуру генерации случайного чилса.
  
  if (step == 1) {
    lcd.init(); //Инициализурем дисплей
    lcd.backlight; //Подсветка дисплея
    
    digitalWrite(led_player1,HIGH);
    lcd.cursor(0,1); //Позиция курсора - 2 строка(нумерация начинается с нуля).

    lcd.print("Step: Player #1");
    
  }
  
}
