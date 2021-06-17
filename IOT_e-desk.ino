#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>

#define NEOpin 2
#define NUMPIXELS 10
#define MOTOR 5

#define FAN_SPEED(i)	analogWrite(MOTOR, map(i, 0, 100, 0, 255))

int capteurTemp = A0;
int capteurLum = A2;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOpin, NEO_GRB + NEO_KHZ800);
LiquidCrystal lcd(12, 11, 7, 6, 4, 3);

void setup()
{
  pixels.begin();
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(MOTOR, OUTPUT);
}

void loop()
{
  int temp_tension = analogRead(capteurTemp);
  // Voltage goes from 0 to 1024, multiplied by
  // input voltage of 5V
  // It's converted to Celcius degrees
  float temperature = (((temp_tension * 5) / 1024.0) - 0.5) * 100;
  
  float light_tension = analogRead(capteurLum);
  // Lightness values go from 0 to 471
  // Compute lightness coefficient: [-64,63[
  int l = ((light_tension / 500) * 127) - 64;

  // Default color with lightness coef
  uint32_t color = pixels.Color(128 + l, 128 + l, 128 + l);
  
  // Increase blue or red color and fan speed
  // according to temperature
  if (temperature > 40){
    int blue = 128 + l + (temperature - 40) * 5;
  	color = pixels.Color(128 + l, 128 + l, ((blue < 255)?blue:255));
    FAN_SPEED(temperature - 40);
  } else if (temperature < 20) {
    int red = 128 + l + (20 - temperature) * 5;
    color = pixels.Color(((red < 255)?red:255), 128 + l, 128 + l);
    FAN_SPEED(0);
  }
  pixels.fill(color);
  pixels.show();
  
  // Display temprature on LCD screen
  lcd.setCursor(1, 0);
  lcd.print("TEMPERATURE = ");
  lcd.setCursor(4, 1);
  lcd.print(temperature);
  lcd.print("*C");

  // Simulating data sent to server
  Serial.print(temperature);
  Serial.println(" degres Celsius");
  Serial.print(l);
  Serial.println(" lightness");
  
  delay(1000);
}
