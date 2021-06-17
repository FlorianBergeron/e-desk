#include <Adafruit_NeoPixel.h>

#define NEOpin 2
#define NUMPIXELS 10
#define MOTOR 5

#define FAN_SPEED(i)	analogWrite(MOTOR, map(i, 0, 100, 0, 255))

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOpin, NEO_GRB + NEO_KHZ800);

int capteurTemp = A0;
int capteurLum = A2;

void setup()
{
  pixels.begin();
  Serial.begin(9600);
  pinMode(MOTOR, OUTPUT);
}

void loop()
{
  int temp_tension = analogRead(capteurTemp);
  // La tension est un entier qui va de 0 à 1024 fois la tension de 5V
  // On convertit en temperature en degré Celcius
  float temperature = (((temp_tension * 5) / 1024.0) - 0.5) * 100;
  Serial.print(temperature);
  Serial.println(" degres Celsius");
  
  float light_tension = analogRead(capteurLum);
  Serial.print(light_tension);
  Serial.println(" lightness");
  
  int l = ((light_tension / 500) * 127) - 64; //[-64,63]

  uint32_t color = pixels.Color(128+l, 128+l, 128+l);
  
  if (temperature > 40){
    int blue = 128 + l + (temperature - 40) * 5;
  	color = pixels.Color(128+l, 128+l, ((blue < 255)?blue:255));
    FAN_SPEED(temperature - 40);
  } else if (temperature < 20) {
    int red = 128 + l + (20 - temperature) * 5;
    color = pixels.Color(((red < 255)?red:255), 128+l, 128+l);
    FAN_SPEED(0);
  }
  pixels.fill(color);
  pixels.show();
  
  delay(1000);
}
