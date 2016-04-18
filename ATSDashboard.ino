#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>

// SCL GPIO5
// SDA GPIO4
#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

const char* ssid     = "WIFI_SSID_HERE";
const char* password = "WIFI_PASS_HERE";

const char* host = "COMPUTER_IP_HERE";

#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 48)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 64x48)
  // init done

  display.display();
  delay(1000);
  display.clearDisplay();
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  display.clearDisplay();

WiFiClient client1;
  const int httpPort = 80;

  while (true)
  {  
  if (!client1.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  // We now create a URI for the request
  String url = "/data.php?key=speed";
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client1.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);
  
  String thing = "";
  
  while(client1.available()){
    String line = client1.readString();
    thing = thing + line;
    Serial.print(line);
  }
  String thespeed = thing.substring(thing.indexOf("<val>") + 5, thing.lastIndexOf("</val>"));
  
  if (!client1.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  // We now create a URI for the request
  String url1 = "/data.php?key=speedLimit";
  Serial.print("Requesting URL: ");
  Serial.println(url1);
  
  // This will send the request to the server
  client1.print(String("GET ") + url1 + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);
  
  String thing1 = "";
  
  while(client1.available()){
    String line = client1.readString();
    thing1 = thing1 + line;
    Serial.print(line);
  }
  String thespeedlimit = thing1.substring(thing1.indexOf("<val>") + 5, thing1.lastIndexOf("</val>"));
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Speed:");
  display.setTextSize(2);
  
  display.print(thespeed.substring(0, thespeed.indexOf(".")));
  display.setTextSize(1);
  display.print("km/h");
  display.setTextSize(2);
  display.println(" ");
  display.setTextSize(1);
  display.println("Limit: ");
  display.setTextSize(2);
  display.print(thespeedlimit);
  display.setTextSize(1);
  display.print("km/h");
  display.display();
  delay(250);
  }
}


void loop() {

}
