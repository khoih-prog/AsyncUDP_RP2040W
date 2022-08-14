# AsyncUDP_RP2040W


[![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncUDP_RP2040W.svg?)](https://www.ardu-badge.com/AsyncUDP_RP2040W)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/AsyncUDP_RP2040W.svg)](https://github.com/khoih-prog/AsyncUDP_RP2040W/releases)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/AsyncUDP_RP2040W.svg)](http://github.com/khoih-prog/AsyncUDP_RP2040W/issues)

<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>

---
---

## Table of Contents


* [Why do we need this AsyncUDP_RP2040W library](#why-do-we-need-this-AsyncUDP_RP2040W-library)
  * [Features](#features)
  * [Why Async is better](#why-async-is-better)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [HOWTO Fix `Multiple Definitions` Linker Error](#howto-fix-multiple-definitions-linker-error) 
* [HOWTO Setting up the Async UDP Client](#howto-setting-up-the-async-udp-client)
* [Examples](#examples)
  * [1. For RASPBERRY_PI_PICO_W](#1-for-RASPBERRY_PI_PICO_W)
    * [ 1. AsyncUDPClient](examples/AsyncUDPClient)
    * [ 2. AsyncUdpNTPClient](examples/AsyncUdpNTPClient)
    * [ 3. AsyncUdpSendReceive](examples/AsyncUdpSendReceive)
    * [ 4. AsyncUDPServer](examples/AsyncUDPServer)
    * [ 5. AsyncUDPMulticastServer](examples/AsyncUDPMulticastServer)
    * [ 6. multiFileProject](examples/multiFileProject)
  * [2. Python test program](#2-Python-test-program)
    * [ 1. UDP_packet_send.py](examples/UDP_packet_send/UDP_packet_send.py)
* [Example AsyncUdpNTPClient](#example-asyncudpntpclient)
  * [1. File AsyncUdpNTPClient.ino](#1-file-asyncudpntpclientino)
  * [2. File defines.h](#2-file-definesh) 
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. AsyncUdpNTPClient on RASPBERRY_PI_PICO_W using CYW43439 WiFi](#1-asyncudpntpclient-on-RASPBERRY_PI_PICO_W-using-CYW43439-WiFi)
  * [2. AsyncUDPServer on RASPBERRY_PI_PICO_W using CYW43439 WiFi](#2-AsyncUDPServer-on-RASPBERRY_PI_PICO_W-using-CYW43439-WiFi)
  * [3. AsyncUDPMulticastServer on RASPBERRY_PI_PICO_W using CYW43439 WiFi](#3-AsyncUDPMulticastServer-on-RASPBERRY_PI_PICO_W-using-CYW43439-WiFi)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [AsyncUDP_RP2040W library](https://github.com/khoih-prog/AsyncUDP_RP2040W)

#### Features

This [AsyncUDP_RP2040W library](https://github.com/khoih-prog/AsyncUDP_RP2040W) is a fully asynchronous UDP library, designed for a trouble-free, multi-connection network environment, for **RASPBERRY_PI_PICO_W using CYW43439 WiFi**. The library is easy to use and includes support for Unicast, Broadcast and Multicast environments.

This library is based on, modified from:

1. [Hristo Gochkov's ESPAsyncUDP](https://github.com/me-no-dev/ESPAsyncUDP)
2. [Khoi Hoang's AsyncUDP_STM32](https://github.com/khoih-prog/AsyncUDP_STM32)

to apply the better and faster **asynchronous** feature of the **powerful** [ESPAsyncUDP Library](https://github.com/me-no-dev/ESPAsyncUDP) into **RASPBERRY_PI_PICO_W using CYW43439 WiFi** using [arduino-pico core v2.4.0+](https://github.com/earlephilhower/arduino-pico).


#### Why Async is better

- Using asynchronous network means that you can handle **more than one connection at the same time**
- You are called once the request is ready and parsed
- When you send the response, you are **immediately ready** to handle other connections while the server is taking care of sending the response in the background
- **Speed is OMG**
- After connecting to a UDP server as an Async Client, you are **immediately ready** to handle other connections while the Client is taking care of receiving the UDP responding packets in the background.
- You are not required to check in a tight loop() the arrival of the UDP responding packets to process them.


### Currently supported Boards

1. **RASPBERRY_PI_PICO_W with CYW43439 WiFi** using [**arduino-pico core v2.4.0+**](https://github.com/earlephilhower/arduino-pico)

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncUDP_RP2040W/blob/main/pics/RP2040W-pinout.svg">
</p>

---
---

## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`Earle Philhower's arduino-pico core v2.4.0+`](https://github.com/earlephilhower/arduino-pico) for **RASPBERRY_PI_PICO_W with CYW43439 WiFi**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)
 
---

### Installation

The suggested way to install is to:

#### Use Arduino Library Manager

The best way is to use `Arduino Library Manager`. Search for `AsyncUDP_RP2040W`, then select / install the latest version. You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncUDP_RP2040W.svg?)](https://www.ardu-badge.com/AsyncUDP_RP2040W) for more detailed instructions.

### Manual Install

1. Navigate to [AsyncUDP_RP2040W](https://github.com/khoih-prog/AsyncUDP_RP2040W) page.
2. Download the latest release `AsyncUDP_RP2040W-main.zip`.
3. Extract the zip file to `AsyncUDP_RP2040W-main` directory 
4. Copy the whole `AsyncUDP_RP2040W-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**AsyncUDP_RP2040W** library](https://registry.platformio.org/libraries/khoih-prog/AsyncUDP_RP2040W) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/AsyncUDP_RP2040W/installation). Search for AsyncUDP_RP2040W in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---

### HOWTO Fix `Multiple Definitions` Linker Error

The current library implementation, using `xyz-Impl.h` instead of standard `xyz.cpp`, possibly creates certain `Multiple Definitions` Linker error in certain use cases.

You can include this `.hpp` file

```
// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include "AsyncUDP_RP2040W.hpp"         //https://github.com/khoih-prog/AsyncUDP_RP2040W
```

in many files. But be sure to use the following `.h` file **in just 1 `.h`, `.cpp` or `.ino` file**, which must **not be included in any other file**, to avoid `Multiple Definitions` Linker Error

```
// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include "AsyncUDP_RP2040W.h"           //https://github.com/khoih-prog/AsyncUDP_RP2040W
```

Check the [**multiFileProject** example](examples/multiFileProject) for a `HOWTO` demo.

Have a look at the discussion in [Different behaviour using the src_cpp or src_h lib #80](https://github.com/khoih-prog/ESPAsync_WiFiManager/discussions/80)


---
---


## HOWTO Setting up the Async UDP Client

```cpp
#include "defines.h"
#include <time.h>

// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include <AsyncUDP_RP2040W.h>         // https://github.com/khoih-prog/AsyncUDP_RP2040W

// 0.ca.pool.ntp.org
IPAddress timeServerIP = IPAddress(208, 81, 1, 244);
// time.nist.gov
//IPAddress timeServerIP = IPAddress(132, 163, 96, 1);

#define NTP_REQUEST_PORT      123

//char timeServer[] = "time.nist.gov";  // NTP server
char timeServer[] = "0.ca.pool.ntp.org";

const int NTP_PACKET_SIZE = 48;       // NTP timestamp is in the first 48 bytes of the message

byte packetBuffer[NTP_PACKET_SIZE];   // buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
AsyncUDP Udp;

int status = WL_IDLE_STATUS;

// send an NTP request to the time server at the given address
void createNTPpacket()
{
  Serial.println("============= createNTPpacket =============");

  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)

  packetBuffer[0]   = 0b11100011;   // LI, Version, Mode
  packetBuffer[1]   = 0;     // Stratum, or type of clock
  packetBuffer[2]   = 6;     // Polling Interval
  packetBuffer[3]   = 0xEC;  // Peer Clock Precision
  
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;
}

void parsePacket(AsyncUDPPacket packet)
{
  ...
}

void sendNTPPacket()
{
  createNTPpacket();

  Serial.println("Sending UDP Packet");
  
  //Send unicast
  Udp.write(packetBuffer, sizeof(packetBuffer));

  Serial.println("Sent UDP Packet");
}

void printWifiStatus()
{
  ...
}

void setup()
{
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.print("\nStart AsyncUdpNTPClient on "); Serial.println(BOARD_NAME);
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

  //NTP requests are to port NTP_REQUEST_PORT = 123
  if (Udp.connect(timeServerIP, NTP_REQUEST_PORT))
  {
    Serial.println("UDP connected");

    Udp.onPacket([](AsyncUDPPacket packet)
    {
      parsePacket(packet);
    });
  }
}

void loop()
{
  sendNTPPacket();

  // wait 60 seconds before asking for the time again
  delay(60000);
}
```

---
---

### Examples

#### 1. For RASPBERRY_PI_PICO_W

 1. [AsyncUDPClient](examples/AsyncUDPClient)
 2. [AsyncUdpNTPClient](examples/AsyncUdpNTPClient)
 3. [AsyncUdpSendReceive](examples/AsyncUdpSendReceive) 
 4. [AsyncUDPServer](examples/AsyncUDPServer)
 5. [AsyncUDPMulticastServer](examples/AsyncUDPMulticastServer)
 6. [multiFileProject](examples/multiFileProject)

#### 2. Python test program

  1. [UDP_packet_send.py](examples/UDP_packet_send/UDP_packet_send.py)
    
    
---

### Example [AsyncUdpNTPClient](examples/AsyncUdpNTPClient)

#### 1. File [AsyncUdpNTPClient.ino](examples/AsyncUdpNTPClient/AsyncUdpNTPClient.ino)

https://github.com/khoih-prog/AsyncUDP_RP2040W/blob/0e4b84496ab39cb0e00a79accdc8b8559bbcfd35/examples/AsyncUdpNTPClient/AsyncUdpNTPClient.ino#L10-L195

#### 2. File [defines.h](examples/AsyncUdpNTPClient/defines.h)

https://github.com/khoih-prog/AsyncUDP_RP2040W/blob/0e4b84496ab39cb0e00a79accdc8b8559bbcfd35/examples/AsyncUdpNTPClient/defines.h#L1-L25

---

### Debug Terminal Output Samples

#### 1. AsyncUdpNTPClient on RASPBERRY_PI_PICO_W using CYW43439 WiFi

This is terminal debug output when running [AsyncUdpNTPClient](examples/AsyncUdpNTPClient) on **PRASPBERRY_PI_PICO_W using CYW43439 WiFi**. It connects to NTP Server `0.ca.pool.ntp.org` (IP=`208.81.1.244:123`) using AsyncUDP_RP2040W library, and requests NTP time every 60s. The packet is then **received and processed asynchronously** to print current UTC/GMT time.

```
Start AsyncUdpNTPClient on RASPBERRY_PI_PICO_W
AsyncUDP_RP2040W v1.0.0
Connecting to SSID: HueNet1
SSID: HueNet1
Local IP Address: 192.168.2.87
signal strength (RSSI):-25 dBm
UDP connected
============= createNTPpacket =============
Sending UDP Packet
Sent UDP Packet
Received UDP Packet Type: Unicast
From: 208.81.1.244:123, To: 192.168.2.87:58997, Length: 48
Seconds since Jan 1 1900 = 3842738319
Epoch/Unix time = 1633749519
The UTC/GMT time is Sat 2021-10-09 03:18:39 GMT
============= createNTPpacket =============
Sending UDP Packet
Sent UDP Packet
Received UDP Packet Type: Unicast
From: 208.81.1.244:123, To: 192.168.2.87:58997, Length: 48
Seconds since Jan 1 1900 = 3842738378
Epoch/Unix time = 1633749578
The UTC/GMT time is Sat 2021-10-09 03:19:38 GMT
```

---

#### 2. AsyncUDPServer on RASPBERRY_PI_PICO_W using CYW43439 WiFi

This is terminal debug output when running [AsyncUDPServer](examples/AsyncUDPServer) on **RASPBERRY_PI_PICO_W using CYW43439 WiFi**. It receives UDP packets from a PC running test Python program [UDP_packet_send.py](examples/UDP_packet_send/UDP_packet_send.py) to send UDP packets.

```
Start AsyncUDPServer on RASPBERRY_PI_PICO_W
AsyncUDP_RP2040W v1.0.0
Connecting to SSID: HueNet1
SSID: HueNet1
Local IP Address: 192.168.2.87
signal strength (RSSI):-25 dBm
UDP Listening on IP: 192.168.2.87
UDP Packet Type: Unicast, From: 192.168.2.30:33380, To: 192.168.2.87:1234, Length: 27, Data: Hello, RASPBERRY_PI_PICO_W!
```

---

#### 3. AsyncUDPMulticastServer on RASPBERRY_PI_PICO_W using CYW43439 WiFi

This is terminal debug output when running [AsyncUDPMulticastServer](examples/AsyncUDPMulticastServer) on **RASPBERRY_PI_PICO_W using CYW43439 WiFi**. It receives UDP packets from from a PC running test Python program [UDP_packet_send.py](examples/UDP_packet_send/UDP_packet_send.py) to send UDP packets.

```
Start AsyncUDPMulticastServer on RASPBERRY_PI_PICO_W
AsyncUDP_RP2040W v1.0.0
Connecting to SSID: HueNet1
SSID: HueNet1
Local IP Address: 192.168.2.87
signal strength (RSSI):-25 dBm
UDP Listening on IP: 192.168.2.87
UDP Packet Type: Unicast, From: 192.168.2.30:50119, To: 192.168.2.87:1234, Length: 27, Data: Hello, RASPBERRY_PI_PICO_W!
```

---
---

### Debug

Debug is enabled by default on Serial. To disable, use level 0

```cpp
#define AUDP_RP2040W_DEBUG_PORT      Serial

// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _AUDP_RP2040W_LOGLEVEL_      0
```

You can also change the debugging level from 0 to 4, default is 1 to output only error messages

```cpp
#define AUDP_RP2040W_DEBUG_PORT      Serial

// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _AUDP_RP2040W_LOGLEVEL_      4
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the [**arduino-pico core**](https://github.com/earlephilhower/arduino-pico)

Sometimes, the library will only work if you update the [**arduino-pico core**](https://github.com/earlephilhower/arduino-pico) core to the latest version because I am using newly added functions.

---
---


### Issues ###

Submit issues to: [AsyncUDP_RP2040W issues](https://github.com/khoih-prog/AsyncUDP_RP2040W/issues)

---

## TO DO

 1. Fix bug. Add enhancement


## DONE

 1. Add support to **RASPBERRY_PI_PICO_W with CYW43439 WiFi**, using [**arduino-pico core v2.4.0+**](https://github.com/earlephilhower/arduino-pico)
 2. Add Table of Contents

---
---

### Contributions and Thanks

1. Based on and modified from [Hristo Gochkov's ESPAsyncUDP](https://github.com/me-no-dev/ESPAsyncUDP). Many thanks to [Hristo Gochkov](https://github.com/me-no-dev) for great [ESPAsyncUDP Library](https://github.com/me-no-dev/ESPAsyncUDP)


<table>
  <tr>
    <td align="center"><a href="https://github.com/me-no-dev"><img src="https://github.com/me-no-dev.png" width="100px;" alt="me-no-dev"/><br /><sub><b>⭐️⭐️ Hristo Gochkov</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [GPLv3](https://github.com/khoih-prog/Portenta_H7_AsyncWebServer/blob/main/LICENSE)

---

## Copyright

Copyright 2022- Khoi Hoang


