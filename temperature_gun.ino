#include <Adafruit_MLX90614.h>
#include <LiquidCrystal.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int greenLED = 9;
int redLED = 10;

void setup() {
  // LCD display
  analogWrite(6, 100);
  lcd.begin(16, 2);
  lcd.clear();
  
  // Temperature sensor
  mlx.begin();

  // LEDs
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  // Get temperature readings
  float fahrenheit = mlx.readObjectTempF();
  float celsius = mlx.readObjectTempC();

  // Display temperature readings
  lcd.clear();
  lcd.print("Temp:");

  lcd.setCursor(6, 0);
  lcd.print(String(fahrenheit) + (char)223 + "F");

  lcd.setCursor(6, 1);
  lcd.print(String(celsius) + (char)223 + "C");

  // Check if temperature is within safe range
  if (celsius > 0 && celsius < 60) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  else {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  }

  delay(500);
}