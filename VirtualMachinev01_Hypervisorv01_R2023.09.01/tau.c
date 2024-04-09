

#include "Tau.hpp"
#include "device.hpp"

extern void Tau_Init(void){

  protected_write(PROTCMD0,PROTS0,CKSC_ATAUJS_CTL,0x01u);
  while(CKSC_ATAUJS_CTL!=0x01u){}
  CKSC_ATAUJD_STPM = 0x01u;

  TAUJ0TPS = 0xfff3u;
  TAUJ0BRS = 0x00;

  TAUJ0CMOR0 = 0x0000u;
  TAUJ0CDR0 = 0x0000u;
  TBTAUJ0I0 = 1u;
  MKTAUJ0I0 = 0u;

  TAUJ0CMOR1 = 0x0000u;
  TAUJ0CDR1 = 0x0000u;
  TBTAUJ0I1 = 1u;
  MKTAUJ0I1 = 0u;

  TAUJ0CMOR2 = 0x0000u;
  TAUJ0CDR2 = 0x0000u;
  TBTAUJ0I2 = 1u;
  MKTAUJ0I2 = 0u;

  TAUJ0CMOR3 = 0x0000u;
  TAUJ0CDR3 = 0x0000u;
  TBTAUJ0I3 = 1u;
  MKTAUJ0I3 = 0u;
}

extern void Tau_StartTimer(Tau_Enum_Channels EN_Channel, uint32 U32_TimerValue_ms)
{
  boolean BO_EnableCounter = TRUE;
  uint32 U32_TimerValue_ticks = U32_TimerValue_ms * 1000U;

  switch(EN_Channel)
  {
   case TAU_E_CHANNEL_0:
      TAUJ0CDR0 = U32_TimerValue_ticks;
      break;
   case TAU_E_CHANNEL_1:
      TAUJ0CDR1 = U32_TimerValue_ticks;
      break;
   case TAU_E_CHANNEL_2:
      TAUJ0CDR2 = U32_TimerValue_ticks;
      break;
   case TAU_E_CHANNEL_3:
      TAUJ0CDR3 = U32_TimerValue_ticks;
      break;
    default:
      BO_EnableCounter = FALSE;
      break;
  }

  if(FALSE != BO_EnableCounter)
  {
    TAUJ0TS |= ((((uint8) 1U) << ((uint8) EN_Channel)));
  }
}

extern void Tau_StopTimer(Tau_Enum_Channels EN_Channel)
{
  TAUJ0TT |= (((uint8) 1U) << ((uint8) EN_Channel));
}

extern void Tau_GetTimer(Tau_Enum_Channels EN_Channel, uint32* PU32_TimerValue_ms)
{
  uint32 U32_TimerValue_ticks;
  uint8 U8_TimerEnableMask = (1U << ((uint8) EN_Channel));
  if((TAUJ0TE & U8_TimerEnableMask) == U8_TimerEnableMask)
  {
   switch(EN_Channel)
   {
      case TAU_E_CHANNEL_0:
        U32_TimerValue_ticks = TAUJ0CNT0;
        break;
      case TAU_E_CHANNEL_1:
        U32_TimerValue_ticks = TAUJ0CNT1;
        break;
      case TAU_E_CHANNEL_2:
        U32_TimerValue_ticks = TAUJ0CNT2;
        break;
      case TAU_E_CHANNEL_3:
        U32_TimerValue_ticks = TAUJ0CNT3;
        break;
      default:
        U32_TimerValue_ticks = 0xFFFFFFFFU;
        break;
   }

    *PU32_TimerValue_ms = U32_TimerValue_ticks / 1000U;
  }
  else{
    *PU32_TimerValue_ms = 0xFFFFFFFFU;
  }
}
