/****************************************************************************************************************************
  AsyncUDPClient.ino

  For RP2040W with CYW43439 WiFi

  AsyncUDP_RP2040W is a library for the RP2040W with CYW43439 WiFi

  Based on and modified from ESPAsyncUDP (https://github.com/me-no-dev/ESPAsyncUDP)
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncUDP_RP2040W
 *****************************************************************************************************************************/

#if !( defined(ARDUINO_RASPBERRY_PI_PICO_W) )
  #error For RASPBERRY_PI_PICO_W only
#endif

#include <WiFi.h>

// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include <AsyncUDP_RP2040W.h>         // https://github.com/khoih-prog/AsyncUDP_RP2040W

char ssid[] = "your_ssid";        // your network SSID (name)
char pass[] = "12345678";         // your network password (use for WPA, or use as key for WEP), length must be 8+

AsyncUDP udp;

int status = WL_IDLE_STATUS;

void printWifiStatus()
{
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("Local IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

void setup()
{
  Serial.begin(115200);

  while (!Serial && millis() < 5000);

  Serial.print("\nStart AsyncUDPClient on ");
  Serial.println(BOARD_NAME);
  Serial.println(ASYNC_UDP_RP2040W_VERSION);

  ///////////////////////////////////

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE)
  {
    Serial.println("Communication with WiFi module failed!");

    // don't continue
    while (true);
  }

  Serial.print(F("Connecting to SSID: "));
  Serial.println(ssid);

  status = WiFi.begin(ssid, pass);

  delay(1000);

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED)
  {
    delay(500);

    // Connect to WPA/WPA2 network
    status = WiFi.status();
  }

  printWifiStatus();

  ///////////////////////////////////

  if (udp.connect(IPAddress(192, 168, 1, 100), 1234))
  {
    Serial.println("UDP connected");

    udp.onPacket([](AsyncUDPPacket packet)
    {
      Serial.print("UDP Packet Type: ");
      Serial.print(packet.isBroadcast() ? "Broadcast" : packet.isMulticast() ? "Multicast" : "Unicast");
      Serial.print(", From: ");
      Serial.print(packet.remoteIP());
      Serial.print(":");
      Serial.print(packet.remotePort());
      Serial.print(", To: ");
      Serial.print(packet.localIP());
      Serial.print(":");
      Serial.print(packet.localPort());
      Serial.print(", Length: ");
      Serial.print(packet.length());
      Serial.print(", Data: ");
      Serial.write(packet.data(), packet.length());
      Serial.println();
      //reply to the client
      packet.printf("Got %u bytes of data", packet.length());
    });

    //Send unicast
    udp.print("Hello Server!");
  }
}

void loop()
{
  delay(1000);
  //Send broadcast on port 1234
  udp.broadcastTo("Anyone here?", 1234);
}
