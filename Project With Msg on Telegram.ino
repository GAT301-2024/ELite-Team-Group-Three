#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

#define WIFI_SSID "Robin's iPhone"
#define WIFI_PASSWORD "lodinRommy"
#define BOT_TOKEN "7424859786:AAGU8X-ACsNF2UzlNZlpoloXrj58ySCGLU4"
#define CHAT_ID "872694934"

WiFiClientSecure secured_client;
UniversalTelegramBot bot (BOT_TOKEN, secured_client);

int trig = 15;
int echo = 5;
int buzzer = 13;

long duration;
int distance;

void setup(){
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(115200);

  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Retrieving time: ");
  configTime(0, 0, "pool.ntp.org"); // get UTC time via NTP
  time_t now = time(nullptr);
  while (now < 24 * 3600)
  {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.println(now);

  bot.sendMessage(CHAT_ID, "Bot started up", "");
}

void loop()
{
  digitalWrite(buzzer, HIGH);
  delayMicroseconds(50);
  digitalWrite(buzzer, LOW);
  
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration*0.034) / 2;

  Serial.print("Distance:= ");
  Serial.println(distance);

delay(1000);
}
