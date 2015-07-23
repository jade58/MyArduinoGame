//My first game for adruino
//Author - JadeWizard//
//Blog - JadeWizard.ru

int btnStep_player1 = 2;
int btnOk_player1 = 3;
int btnStep_player2 = 5;
int btnOk_player2 = 4;
int led_player1 = 8;
int led_player2 = 9;

int u_step = 1; //Текущий ход игрок #1 ходит первый.

int num1 = 0; //Числа первого игрока
int num2 = 0; //Число второго игрока.

int p_step1 = 0; //Кол-во промежуточных шагов.
int p_step2 = 0; //Кол-во промежуточных шагов второго игрока.

int step1 = 0; //Общее кол-во шагов.
int step2 = 0; //Кол-во промежуточных шагов


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

//Функция генерации рандомного числа для игроков.

int rnd_number () {
  
  int number;

  number = random(48);
 
  return(number);
  
}

void loop()
{

  int rnd = 0; //Рандомное число.

  //Если ходит первый игрок, то светодиод 1 = максимум
  //На экране выводим сообщение о том, что ходит игрок RED(#1)
  //И запускаем процедуру генерации случайного чилса.

    lcd.init(); //Инициализурем дисплей
    lcd.backlight(); //Подсветка дисплея
    
    lcd.setCursor(0,1); //Позиция курсора - 2 строка(нумерация начинается с нуля).

    lcd.print("Step: Player #1");
  
  if (u_step == 1) {
    
    if (digitalRead(btnStep_player1) == HIGH) {
      rnd = rnd_number (); //Число первого игрока
      num1 = num1 + rnd; //Подсчитываем общее число.
      p_step1 = p_step1 + 1; //число промежуточных ходов
    }

    if (num1 != 0 && p_step1 > 1 && digitalRead(btnOk_player1) == HIGH) {
      step1 = step1 + 1; //Число общих ходов;
      u_step = 2;
    }

    if (p_step1 == 3) {
      step1 = step1 + 1; //Число общих ходов
      u_step = 2;
    }

    digitalWrite(led_player1,HIGH);
    digitalWrite(led_player2,LOW);
        
    lcd.print(num1); //Выводим число
    
 } else {
    
    digitalWrite(led_player2,HIGH);
    digitalWrite(led_player1,LOW);

    lcd.init(); //Инициализируем дисплей
    lcd.backlight(); //Подсветка

    lcd.print(10); //Выводим число
    
    lcd.setCursor(0,1); //Смещаем курсор
    lcd.print("Step: Player #2"); //Номер игрока
    
  }
 
}
