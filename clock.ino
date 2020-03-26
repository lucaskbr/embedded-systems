#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int seconds = 0;
int minutes = 0;
int hours = 0;

void setup()
{

  lcd.begin(16, 2);
}

void loop()
{

  if (seconds >= 60)
  {
    seconds = 0.0;
    minutes += 1;
    lcd.clear();
  }

  if (minutes >= 60)
  {
    minutes = 0.0;
    hours += 1;
    lcd.clear();
  }

  if (hours >= 24)
  {
    hours = 0;
    minutes = 0;
    seconds = 0;
    lcd.clear();
  }

  lcd.setCursor(1, 1);

  lcd.print(hours);
  lcd.print(':');
  lcd.print(minutes);
  lcd.print(':');
  lcd.print(seconds);

  seconds += 1;

  delay(1000);
}