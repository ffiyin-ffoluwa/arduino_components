#include <Bonezegei_DHT11.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH   128
#define SCREEN_HEIGHT  64     
#define OLED_DC    9
#define OLED_CS    10
#define OLED_RESET 8
#define dhtPin 12
#define beeperPin 4

Bonezegei_DHT11 dht(dhtPin);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

static const unsigned char PROGMEM image_weather_cloud_sunny_bits[] = {
  0x00,0x20,0x00,0x02,0x02,0x00,0x00,0x70,0x00,0x01,0x8c,0x00,
  0x09,0x04,0x80,0x02,0x02,0x00,0x02,0x02,0x00,0x07,0x82,0x00,
  0x08,0x44,0x80,0x10,0x2c,0x00,0x30,0x30,0x00,0x60,0x1e,0x00,
  0x80,0x03,0x00,0x80,0x01,0x00,0x80,0x01,0x00,0x7f,0xfe,0x00
};

static const unsigned char PROGMEM image_weather_sun_bits[] = {
  0x01,0x00,0x21,0x08,0x10,0x10,0x03,0x80,0x8c,0x62,0x48,0x24,0x10,0x10,0x10,0x10,
  0x10,0x10,0x48,0x24,0x8c,0x62,0x03,0x80,0x10,0x10,0x21,0x08,0x01,0x00,0x00,0x00
};

void drawScreen(float tempC, int humidity) {
  float tempF = tempC * 9.0 / 5.0 + 32.0;

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextWrap(false);
  display.setTextSize(1);

  // Labels
  display.setCursor(4, 7);
  display.print("Temp(C)");
  display.setCursor(88, 7);
  display.print("Humi");

  // Values
  display.setCursor(4, 19);
  display.print(tempC, 0);
  display.setCursor(88, 19);
  display.print(humidity);
  display.print("%");

  // Weather icon
  if (tempC < 20) {
    display.drawBitmap(56, 13, image_weather_cloud_sunny_bits, 17, 21, SSD1306_WHITE);
    display.setCursor(2, 29);
    display.print("Stay Warm");
  } else {
    display.drawBitmap(57, 8, image_weather_sun_bits, 15, 16, SSD1306_WHITE);
    display.setCursor(2, 29);
    display.print("Stay Hydrated");
  }

  display.display();=M
}1111111111

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println("OLED not found");
    for (;;);
  }

  dht.begin();
  display.clearDisplay();
  display.display();
}
void loop() {
  if (dht.getData()) {
    float tempC = dht.getTemperature();
    int humidity = dht.getHumidity();
    Serial.print(tempC);
    Serial.print(", ");
    Serial.println(humidity);


    drawScreen(tempC, humidity);
  } else {
    Serial.println("DHT11 read failed");
  }

  delay(2000); 
}