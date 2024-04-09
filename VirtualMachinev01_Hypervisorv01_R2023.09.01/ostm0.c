#include "device.hpp"
#include "Os_ConfigInterrupts.hpp"
#include "ostm0.hpp"
#include "gpioX.hpp"
#include "clocksX.hpp"

void infSwcServiceOsSwcApplEcuM_InitFunction(void){
  OSTM0_SetCompareValue(OSTM0_COMPARE_1MS);
  OSTM0_IntervalMode();
  OSTM0_Start();
}

void OSTM0_FreeRunMode(void){
  OSTM0TT = 0x01u;
  OSTM0EMU = 0x00u;
   //if(OSTM0TE = 0x00u)  OSTM0CTL writing is only possible if OSTM0TE=0! */
  OSTM0CTL = 0x02u;
 }

void OSTM0_IntervalMode(void){
  OSTM0TT = 0x01u;
  OSTM0EMU = 0x00u;
   //if(OSTM0TE = 0x00u) OSTM0CTL writing is only possible if OSTM0TE=0! */
  OSTM0CTL = 0x00u;
}

void OSTM0_InputCaptureMode(void){
  OSTM0TT = 0x01u;
  ICOSTM0 = 0x0047;
  OSTM0TS = 0x01u;
}

void OSTM0_Start(void){
  OSTM0TS = 0x01u;
}

void OSTM0_Stop(void){
  OSTM0TT = 0x01u;
}

void OSTM0_SetCompareValue(uint16 comp)
{
  OSTM0CMP = comp;
}

void OSTM0_SetInterrupt(uint8 ucValue)
{
  OSTM0CMP |= 0x01;
}

void OSTM0_wait_for_overflow(void){
  while(RFOSTM0==0u){}
    RFOSTM0=0u;
}

