#ifndef _INTERNAL_CLOCK_X_H
#define _INTERNAL_CLOCK_X_H

#include "Types.hpp"

#define cT_STANBY               (uint16) 1140//s 19 min ECU stanby time after ignition off

#define cT_STANBY4AFD           (uint16) 60//s 1 min ECU parking+stanby time for auto filling detection
#define c_100km                 (uint32) 100
#define c_50km                  (uint32) 50
#define c_0km				            (uint32) 0
#define c_FFFFkm                (uint32) 0xFFFFFFFF
#define c_FF9Bkm                (uint32) 0xFFFFFF9B

#define ucDpTxTriggerc (uint8) 1

#define OP_TIME_METHOD_OHDS 0x01U // OHDS
#define OP_TIME_METHOD_CSTDELAY 0x00U //Constant delay

extern void CLOCKS_SetMainOscClock(void);
extern void CLOCKS_SetPllClock(void);
extern void CLOCKS_DisableClockDomainsForDeepSleep(void);
extern void WaitHard(uint32 ulTicks);

#endif
