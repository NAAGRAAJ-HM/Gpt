#include "Std_Types.hpp"

#include "device.hpp"
#include "Os_ConfigInterrupts.hpp"
#include "ostm0X.hpp"
#include "gpioX.hpp"
#include "clocksX.hpp"

void OSTM0_FreeRunMode(void){
   OSTM0TT  = 0x01u;
   OSTM0EMU = 0x00u;
   OSTM0CTL = 0x02u;
}

void OSTM0_InputCaptureMode(void){
   OSTM0TT = 0x01u;
   ICOSTM0 = 0x0047;
   OSTM0TS = 0x01u;
}

void OSTM0_Stop(void){
   OSTM0TT = 0x01u;
}

void OSTM0_SetInterrupt(uint8 ucValue){
   OSTM0CMP |= 0x01;
}

void OSTM0_wait_for_overflow(void){
   while(0u == RFOSTM0){}
   RFOSTM0 = 0u;
}

