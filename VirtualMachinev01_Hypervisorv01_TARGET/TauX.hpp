#ifndef TAU_X_H
#define TAU_X_H

typedef enum{
  TAU_E_CHANNEL_0 = 0U
   ,  TAU_E_CHANNEL_1 = 1U
   ,  TAU_E_CHANNEL_2 = 2U
   ,  TAU_E_CHANNEL_3 = 3U
}Tau_Enum_Channels;

extern void Tau_Init(void);
extern void Tau_StartTimer(Tau_Enum_Channels EN_Channel, uint32 U32_TimeValue_ms);
extern void Tau_StopTimer(Tau_Enum_Channels EN_Channel);
extern void Tau_GetTimer(Tau_Enum_Channels EN_Channel, uint32* PU32_TimerValue_ms);

#endif
