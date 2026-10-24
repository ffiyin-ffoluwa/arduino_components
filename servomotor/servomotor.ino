#include <Bonezegei_DHT11.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_MOSI 11
#define OLED_CLK 13
#define OLED_DC 9
#define OLED_CS 10
#define OLED_RESET 8

#define HumPin 7

Bonezegei_DHT11 dht(HumPin);

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  OLED_MOSI,
  OLED_CLK,
  OLED_DC,
  OLED_RESET,
  OLED_CS
);

void setup() {
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC);
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  dht.begin();
}

void loop() {

  if (dht.getData()) {

    float tempreading = dht.getTemperature();
    float humreading = dht.getHumidity();

    display.clearDisplay();
    display.setCursor(5, 10);

    display.print("Temp:");
    display.println(tempreading);

    display.print("Hum:");
    display.println(humreading);

    display.display();

    Serial.print("Temperature: ");
    Serial.println(tempreading);

    Serial.print("Humidity: ");
    Serial.println(humreading);
  }

  delay(2000);
}