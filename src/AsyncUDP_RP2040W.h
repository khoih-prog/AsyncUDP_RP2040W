/****************************************************************************************************************************
  AsyncUDP_RP2040W.h

  For RP2040W with CYW43439 WiFi

  AsyncUDP_RP2040W is a library for the RP2040W with CYW43439 WiFi

  Based on and modified from ESPAsyncUDP (https://github.com/me-no-dev/ESPAsyncUDP)
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncUDP_RP2040W

  This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
  as published bythe Free Software Foundation, either version 3 of the License, or (at your option) any later version.
  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
  You should have received a copy of the GNU General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>.

  Version: 1.0.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      14/08/2022 Initial coding for RP2040W with CYW43439 WiFi
 *****************************************************************************************************************************/

#pragma once

#ifndef ASYNC_UDP_RP2040W_H
#define ASYNC_UDP_RP2040W_H

#if ( defined(ARDUINO_RASPBERRY_PI_PICO_W) )

  #if (_ASYNCTCP_RP2040W_LOGLEVEL_ > 2)
    #if defined(ARDUINO_RASPBERRY_PI_PICO_W)
      #warning RASPBERRY_PI_PICO_W board using CYW4343 WiFi selected
    #else
      #warning RP2040-based board selected
    #endif
  #endif

  #if defined(WIFI_USE_RP2040)
    #undef WIFI_USE_RP2040
  #endif
  #define WIFI_USE_RP2040      true

  #if (_ASYNCTCP_RP2040W_LOGLEVEL_ > 2)
    #warning Use RP2040 architecture from WiFiWebServer
  #endif

#else

  #error For RASPBERRY_PI_PICO_W board using CYW43439 WiFi only

#endif

#if defined(SHIELD_TYPE)
  #undef SHIELD_TYPE
#endif

#define SHIELD_TYPE                         "RP2040W CYW43439 WiFi"

#define ASYNC_UDP_RP2040W_VERSION            "AsyncUDP_RP2040W v1.0.0"

#define ASYNC_UDP_RP2040W_VERSION_MAJOR      1
#define ASYNC_UDP_RP2040W_VERSION_MINOR      0
#define ASYNC_UDP_RP2040W_VERSION_PATCH      0

#define ASYNC_UDP_RP2040W_VERSION_INT        1000000

#if 0

#ifndef _AUDP_RP2040W_LOGLEVEL_
  #define _AUDP_RP2040W_LOGLEVEL_       1
#endif

#include "AsyncUDP_RP2040W_Debug.h"

#include "Arduino.h"
#include "IPAddress.h"
#include "Print.h"
#include <functional>


#if defined(__DOXYGEN__)
  #undef __DOXYGEN__
#endif

//#include <WiFiUdp.h>
#include <WiFi.h>

#define LWIP_IGMP         1
#define LWIP_IPV4         1

extern "C"
{
#include "lwip/init.h"
#include "lwip/opt.h"
#include "lwip/ip_addr.h"
#include "lwip/inet.h"
#include "lwip/err.h"
#include "lwip/pbuf.h"
#include "lwip/udp.h"
#include "lwip/igmp.h"
#include "lwip/dns.h"
};

#ifndef TCP_MSS
  #define TCP_MSS       1460
#endif

class AsyncUDP;
class AsyncUDPPacket;
class AsyncUDPMessage;

struct udp_pcb;
struct pbuf;

#if LWIP_VERSION_MAJOR == 1
  struct ip_addr;
  typedef struct ip_addr ip_addr_t;
#else
  struct ip4_addr;
  typedef struct ip4_addr ip_addr_t;
#endif

class AsyncUDPMessage : public Print
{
  protected:
    uint8_t *_buffer;
    size_t _index;
    size_t _size;

  public:
    AsyncUDPMessage(size_t size = TCP_MSS /*1460*/);
    virtual ~AsyncUDPMessage();

    size_t write(const uint8_t *data, size_t len);
    size_t write(uint8_t data);
    size_t space();
    uint8_t * data();
    size_t length();
    void flush();

    operator bool()
    {
      return _buffer != NULL;
    }
};

//////////////////////////////////

class AsyncUDPPacket : public Print
{
  protected:
    AsyncUDP *_udp;
    ip_addr_t *_localIp;
    uint16_t _localPort;
    ip_addr_t *_remoteIp;
    uint16_t _remotePort;
    uint8_t *_data;
    size_t _len;

  public:
    AsyncUDPPacket(AsyncUDP *udp, ip_addr_t *localIp, uint16_t localPort, ip_addr_t *remoteIp, uint16_t remotePort,
                   uint8_t *data, size_t len);
    virtual ~AsyncUDPPacket();

    uint8_t * data();
    size_t length();
    bool isBroadcast();
    bool isMulticast();

    IPAddress localIP();
    uint16_t localPort();
    IPAddress remoteIP();
    uint16_t remotePort();

    size_t send(AsyncUDPMessage &message);

    size_t write(const uint8_t *data, size_t len);
    size_t write(uint8_t data);
};

//////////////////////////////////

typedef std::function<void(AsyncUDPPacket& packet)> AuPacketHandlerFunction;
typedef std::function<void(void * arg, AsyncUDPPacket& packet)> AuPacketHandlerFunctionWithArg;

//////////////////////////////////

class AsyncUDP : public Print
{
  protected:
    udp_pcb *_pcb;
    bool _connected;
    AuPacketHandlerFunction _handler;

    void _recv(udp_pcb *upcb, pbuf *pb, ip_addr_t *addr, uint16_t port);
#if LWIP_VERSION_MAJOR == 1
    static void _s_recv(void *arg, udp_pcb *upcb, pbuf *p, ip_addr_t *addr, uint16_t port);
#else
    static void _s_recv(void *arg, udp_pcb *upcb, pbuf *p, const ip_addr_t *addr, uint16_t port);
#endif

  public:
    AsyncUDP();
    virtual ~AsyncUDP();

    void onPacket(AuPacketHandlerFunctionWithArg cb, void * arg = NULL);
    void onPacket(AuPacketHandlerFunction cb);

    bool listen(ip_addr_t *addr, uint16_t port);
    bool listen(const IPAddress addr, uint16_t port);
    bool listen(uint16_t port);

    bool listenMulticast(ip_addr_t *addr, uint16_t port, uint8_t ttl = 1);
    bool listenMulticast(const IPAddress addr, uint16_t port, uint8_t ttl = 1);

    bool connect(ip_addr_t *addr, uint16_t port);
    bool connect(const IPAddress addr, uint16_t port);

    void close();

    size_t writeTo(const uint8_t *data, size_t len, ip_addr_t *addr, uint16_t port);
    size_t writeTo(const uint8_t *data, size_t len, const IPAddress addr, uint16_t port);
    size_t write(const uint8_t *data, size_t len);
    size_t write(uint8_t data);

    size_t broadcastTo(uint8_t *data, size_t len, uint16_t port);
    size_t broadcastTo(const char * data, uint16_t port);
    size_t broadcast(uint8_t *data, size_t len);
    size_t broadcast(const char * data);

    size_t sendTo(AsyncUDPMessage &message, ip_addr_t *addr, uint16_t port);
    size_t sendTo(AsyncUDPMessage &message, const IPAddress addr, uint16_t port);
    size_t send(AsyncUDPMessage &message);

    size_t broadcastTo(AsyncUDPMessage &message, uint16_t port);
    size_t broadcast(AsyncUDPMessage &message);

    bool connected();
    operator bool();
};
#endif

#include "AsyncUDP_RP2040W.hpp"
#include "AsyncUDP_RP2040W_Impl.h"

#endif    //ASYNC_UDP_RP2040W_H
