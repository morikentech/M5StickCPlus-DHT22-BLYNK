#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"

#include <M5StickCPlus.h>
#include <DHT.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define DHTPIN 26
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

BlynkTimer timer;

void sendSensorData()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);

  // デバッグ出力
  // Serial.printf("Temp: %.1f C, Hum: %.1f %%\n", t, h);

  // M5StickCの画面に表示
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.printf("Temp: %.1f C\n", t);
  M5.Lcd.printf("Hum: %.1f %%\n", h);
}

void setup()
{
  M5.begin();
  dht.begin();
  M5.Lcd.begin();
  M5.Lcd.setRotation(1);
  M5.Lcd.fillScreen(BLACK); // 初期画面を黒に設定
  Serial.begin(115200);

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(2000L, sendSensorData);
}

void loop()
{
  Blynk.run();
  timer.run();
}