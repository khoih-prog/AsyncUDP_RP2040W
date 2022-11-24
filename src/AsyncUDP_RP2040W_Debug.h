/****************************************************************************************************************************
  AsyncUDP_RP2040W_Debug.h

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

#ifndef AUDP_RP2040W_DEBUG_H
#define AUDP_RP2040W_DEBUG_H

#ifdef AUDP_RP2040W_DEBUG_PORT
  #define DBG_PORT_AUDP      AUDP_RP2040W_DEBUG_PORT
#else
  #define DBG_PORT_AUDP      Serial
#endif

// Change _AUDP_RP2040W_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _AUDP_RP2040W_LOGLEVEL_
  #define _AUDP_RP2040W_LOGLEVEL_       1
#endif

/////////////////////////////////////////////////////////

#define AUDP_PRINT           DBG_PORT_AUDP.print
#define AUDP_PRINTLN         DBG_PORT_AUDP.println

#define AUDP_PRINT_MARK      DBG_PORT_AUDP.print("[AUDP] ")
#define AUDP_PRINT_SP        DBG_PORT_AUDP.print(" ")

/////////////////////////////////////////////////////////

#define AUDP_LOGERROR(x)         if(_AUDP_RP2040W_LOGLEVEL_>0) { AUDP_PRINT_MARK; AUDP_PRINTLN(x); }
#define AUDP_LOGERROR0(x)        if(_AUDP_RP2040W_LOGLEVEL_>0) { AUDP_PRINT(x); }
#define AUDP_LOGERROR1(x,y)      if(_AUDP_RP2040W_LOGLEVEL_>0) { AUDP_PRINT_MARK; AUDP_PRINT(x); AUDP_PRINT_SP; AUDP_PRINTLN(y); }
#define AUDP_LOGERROR2(x,y,z)    if(_AUDP_RP2040W_LOGLEVEL_>0) { AUDP_PRINT_MARK; AUDP_PRINT(x); AUDP_PRINT_SP; AUDP_PRINT(y); AUDP_PRINT_SP; AUDP_PRINTLN(z); }
#define AUDP_LOGERROR3(x,y,z,w)  if(_AUDP_RP2040W_LOGLEVEL_>0) { AUDP_PRINT_MARK; AUDP_PRINT(x); AUDP_PRINT_SP; AUDP_PRINT(y); AUDP_PRINT_SP; AUDP_PRINT(z); AUDP_PRINT_SP; AUDP_PRINTLN(w); }

#define AUDP_LOGWARN(x)          if(_AUDP_RP2040W_LOGLEVEL_>1) { AUDP_PRINT_MARK; AUDP_PRINTLN(x); }
#define AUDP_LOGWARN0(x)         if(_AUDP_RP2040W_LOGLEVEL_>1) { AUDP_PRINT(x); }
#define AUDP_LOGWARN1(x,y)       if(_AUDP_RP2040W_LOGLEVEL_>1) { AUDP_PRINT_MARK; AUDP_PRINT(x); AUDP_PRINT_SP; AUDP_PRINTLN(y); }
#define AUDP_LOGWARN2(x,y,z)     if(_AUDP_RP2040W_LOGLEVEL_>1) { AUDP_PRINT_MARK; AUDP_PRINT(x); AUDP_PRINT_SP; AUDP_PRINT(y); AUDP_PRINT_SP; AUDP_PRINTLN(z); }
#define AUDP_LOGWARN3(x,y,z,w)   if(_AUDP_RP2040W_LOGLEVEL_>1) { AUDP_PRINT_MARK; AUDP_PRINT(x); AUDP_PRINT_SP; AUDP_PRINT(y); AUDP_PRINT_SP; AUDP_PRINT(z); AUDP_PRINT_SP; AUDP_PRINTLN(w); }

#define AUDP_LOGINFO(x)          if(_AUDP_RP2040W_LOGLEVEL_>2) { AUDP_PRINT_MARK; AUDP_PRINTLN(x); }
#define AUDP_LOGINFO0(x)         if(_AUDP_RP2040W_LOGLEVEL_>2) { AUDP_PRINT(x); }
#define AUDP_LOGINFO1(x,y)       if(_AUDP_RP2040W_LOGLEVEL_>2) { AUDP_PRINT_MARK; AUDP_PRINT(x); AUDP_PRINT_SP; AUDP_PRINTLN(y); }
#define AUDP_LOGINFO2(x,y,z)     if(_AUDP_RP2040W_LOGLEVEL_>2) { AUDP_PRINT_MARK; AUDP_PRINT(x); AUDP_PRINT_SP; AUDP_PRINT(y); AUDP_PRINT_SP; AUDP_PRINTLN(z); }
#define AUDP_LOGINFO3(x,y,z,w)   if(_AUDP_RP2040W_LOGLEVEL_>2) { AUDP_PRINT_MARK; AUDP_PRINT(x); AUDP_PRINT_SP; AUDP_PRINT(y); AUDP_PRINT_SP; AUDP_PRINT(z); AUDP_PRINT_SP; AUDP_PRINTLN(w); }

#define AUDP_LOGDEBUG(x)         if(_AUDP_RP2040W_LOGLEVEL_>3) { AUDP_PRINT_MARK; AUDP_PRINTLN(x); }
#define AUDP_LOGDEBUG0(x)        if(_AUDP_RP2040W_LOGLEVEL_>3) { AUDP_PRINT(x); }
#define AUDP_LOGDEBUG1(x,y)      if(_AUDP_RP2040W_LOGLEVEL_>3) { AUDP_PRINT_MARK; AUDP_PRINT(x); AUDP_PRINT_SP; AUDP_PRINTLN(y); }
#define AUDP_LOGDEBUG2(x,y,z)    if(_AUDP_RP2040W_LOGLEVEL_>3) { AUDP_PRINT_MARK; AUDP_PRINT(x); AUDP_PRINT_SP; AUDP_PRINT(y); AUDP_PRINT_SP; AUDP_PRINTLN(z); }
#define AUDP_LOGDEBUG3(x,y,z,w)  if(_AUDP_RP2040W_LOGLEVEL_>3) { AUDP_PRINT_MARK; AUDP_PRINT(x); AUDP_PRINT_SP; AUDP_PRINT(y); AUDP_PRINT_SP; AUDP_PRINT(z); AUDP_PRINT_SP; AUDP_PRINTLN(w); }

#endif    //AUDP_RP2040W_DEBUG_H
