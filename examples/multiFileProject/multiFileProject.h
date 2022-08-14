/****************************************************************************************************************************
  multiFileProject.h
  
  For RP2040W with CYW43439 WiFi
     
  AsyncUDP_RP2040W is a library for the RP2040W with CYW43439 WiFi
  
  Based on and modified from ESPAsyncUDP (https://github.com/me-no-dev/ESPAsyncUDP)
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncUDP_RP2040W
*****************************************************************************************************************************/

// To demo how to include files in multi-file Projects

#pragma once

#define _AUDP_RP2040W_LOGLEVEL_       1

// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include <AsyncUDP_RP2040W.hpp>        // https://github.com/khoih-prog/AsyncUDP_RP2040W
