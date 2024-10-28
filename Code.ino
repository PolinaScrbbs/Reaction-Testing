#include <LiquidCrystal.h>
#define ledPin 8
#define btnPin 7

double number;
long sTime;

LiquidCrystal lcd(0, 1, 2, 3, 4, 5);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(btnPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  analogWrite(A1, LOW);
}

void loop() {
  number = random(500, 5000);
  lcd.print("Wait for the LED");
  delay(number);

  lcd.clear();
  lcd.print("PRESS!");
  digitalWrite(ledPin, HIGH);
  sTime = millis();

  while (digitalRead(btnPin)) {
    // Wait for button release
  }

  lcd.clear();
  lcd.print("Reaction time: ");
  lcd.setCursor(0, 1);
  lcd.print(millis() - sTime);
  lcd.print(" s");

  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Another test");
  lcd.setCursor(0, 1);
  lcd.print("in 5 seconds");
  delay(5000);
  lcd.clear();
  digitalWrite(8, LOW);
}