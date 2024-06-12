/******************************************************************************/
/* File   : gpt12e.cpp                                                        */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "types.hpp"

#include "gpt12e.hpp"

#include "gpt12e_defines.hpp"
#include "sfr_access.hpp"

#include "Mat.hpp" //TBD: remove
#include "ApplSwcFoc_tbd.hpp"

#include "uC_Gpt.hpp"
#include "uC_Scu.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
GPT12E_Type GPT12E = {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0
};

TIMER2x_Type TIMER2 = {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

TIMER2x_Type TIMER21 = {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

TIMER3_Type TIMER3 = {
      0, 0, 0, 0, 0, 0
};

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
void GPT12E_Init(void){
   GPT12E.T2CON.reg = GPT12E_T2CON;
   GPT12E.T2.reg = GPT12E_T2;
   GPT12E.T3CON.reg = GPT12E_T3CON;
   GPT12E.T3.reg = GPT12E_T3;
   GPT12E.T4CON.reg = GPT12E_T4CON;
   GPT12E.T4.reg = GPT12E_T4;
   GPT12E.T5CON.reg = GPT12E_T5CON;
   GPT12E.T5.reg = GPT12E_T5;
   GPT12E.T6CON.reg = GPT12E_T6CON;
   GPT12E.T6.reg = GPT12E_T6;
   GPT12E.CAPREL.reg = GPT12E_CAPREL;
   GPT12E.PISEL.reg = GPT12E_PISEL;
}
/*
bool GPT12E_T3_Interval_Timer_Setup(uint32 timer_interval_us){
  bool res;
  uint64 timer_ticks;
  uint32 gpt_frequency;
  uint32 clk_prescaler;
  res = false;
  gpt_frequency = SystemFrequency >> (GPT12E_GPT1_Clk_Prescaler_Get() + (uint16)2);
  timer_ticks = ((uint64)timer_interval_us * ((uint64)gpt_frequency / (uint64)1000)) / (uint64)1000;
  clk_prescaler = (uint32)GPT_Clk_Div_1;

  while(timer_ticks > (uint64)0xFFFFu){
    clk_prescaler++;
    timer_ticks >>= 1u;
  }

  if(clk_prescaler <= (uint32)GPT_Clk_Div_128){
    GPT12E_T3_Mode_Timer_Sel();
    GPT12E_T3_Mode_Timer_Clk_Prescaler_Sel((uint8)clk_prescaler);
    GPT12E_T3_UpDownCount_Ext_Dis();
    GPT12E_T3_DownCount_Sel();
    GPT12E_T3_Value_Set((uint16)timer_ticks);
    GPT12E_T2_Mode_Reload_Sel();
    GPT12E_T2_Value_Set((uint16)timer_ticks);
    GPT12E_T2_Mode_Reload_Input_T3Out_Sel();
    GPT12E_T2_Mode_Reload_Input_Falling_T3Out_En();
    GPT12E_T2_Mode_Reload_Input_Rising_T3Out_En();
    res = true;
  }
   return(res);
}

bool GPT12E_T6_Interval_Timer_Setup(uint32 timer_interval_us){
  bool res;
  uint64 timer_ticks;
  uint32 gpt_frequency;
  uint32 clk_prescaler;
  res = false;
  gpt_frequency = SystemFrequency >> (GPT12E_GPT2_Clk_Prescaler_Get() + (uint16)1);
  timer_ticks = ((uint64)timer_interval_us * ((uint64)gpt_frequency / (uint64)1000)) / (uint64)1000;
  clk_prescaler = (uint32)GPT_Clk_Div_1;

  while(timer_ticks > (uint64)0xFFFF){
    clk_prescaler++;
    timer_ticks >>= 1u;
  }

  if(clk_prescaler <= (uint32)GPT_Clk_Div_128){
    GPT12E_T6_Mode_Timer_Sel();
    GPT12E_T6_Mode_Timer_Clk_Prescaler_Sel((uint8)clk_prescaler);
    GPT12E_T6_UpDownCount_Ext_Dis();
    GPT12E_T6_DownCount_Sel();
    GPT12E_T6_Value_Set((uint16)timer_ticks);
    GPT12E_T6_Reload_Value_Set((uint16)timer_ticks);
    GPT12E_T6_Reload_En();
    res = true;
  }
   return(res);
}

void GPT12E_GPT1_Clk_Prescaler_Sel(
   uint16 bps1
){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_BPS1_Pos
      ,  (uint16)GPT12E_T3CON_BPS1_Msk
      ,  (bps1 ^ (uint16)1)
   );
}

uint16 GPT12E_GPT1_Clk_Prescaler_Get(void){
   return(
         u16_Field_Rd16(
               &GPT12E.T3CON.reg
            ,  (uint16)GPT12E_T3CON_BPS1_Pos
            ,  (uint16)GPT12E_T3CON_BPS1_Msk
         )
      ^  (uint16)1
   );
}

void GPT12E_T3_T4_CCU6_Sel(
   uint8 gpt
){
   Field_Mod8(
         &SCU.GPT12PISEL.reg
      ,  (uint8)SCU_GPT12PISEL_GPT12_Pos
      ,  (uint8)SCU_GPT12PISEL_GPT12_Msk
      ,  gpt
   );
}

void GPT12E_T2_Mode_Timer_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2M_Pos
      , (uint16)GPT12E_T2CON_T2M_Msk, 0u
   );
}

void GPT12E_T2_Mode_Counter_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2M_Pos
      ,  (uint16)GPT12E_T2CON_T2M_Msk
      ,  1u
   );
}

void GPT12E_T2_Mode_Gated_Timer_Low_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2M_Pos
      ,  (uint16)GPT12E_T2CON_T2M_Msk
      ,  2u
   );
}

void GPT12E_T2_Mode_Gated_Timer_High_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2M_Pos
      ,  (uint16)GPT12E_T2CON_T2M_Msk
      ,  3u
   );
}

void GPT12E_T2_Mode_Reload_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2M_Pos
      ,  (uint16)GPT12E_T2CON_T2M_Msk
      ,  4u
   );
}

void GPT12E_T2_Mode_Capture_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2M_Pos
      ,  (uint16)GPT12E_T2CON_T2M_Msk
      ,  5u
   );
}

void GPT12E_T2_Mode_IncEnc_Rot_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2M_Pos
      ,  (uint16)GPT12E_T2CON_T2M_Msk
      ,  6u
   );
}

void GPT12E_T2_Mode_IncEnc_Edge_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2M_Pos
      ,  (uint16)GPT12E_T2CON_T2M_Msk
      ,  7u
   );
}

void GPT12E_T2_Mode_Timer_Clk_Prescaler_Sel(uint16 t2i){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2I_Pos
      ,  (uint16)GPT12E_T2CON_T2I_Msk
      ,  t2i
   );
}

void GPT12E_T2_Mode_Gated_Timer_Clk_Prescaler_Sel(uint16 t2i){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2I_Pos
      ,  (uint16)GPT12E_T2CON_T2I_Msk
      ,  t2i
   );
}

void GPT12E_T2_Mode_Counter_Input_T2In_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  2u
      ,  4u
      ,  0u
   );
}

void GPT12E_T2_Mode_Counter_Input_Rising_T2In_En(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  0u
      ,  1u
      ,  1u
   );
}

void GPT12E_T2_Mode_Counter_Input_Rising_T2In_Dis(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  0u
      ,  1u
      ,  0u
   );
}

void GPT12E_T2_Mode_Counter_Input_Falling_T2In_En(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  1u
      ,  2u
      ,  1u
   );
}

void GPT12E_T2_Mode_Counter_Input_Falling_T2In_Dis(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  1u
      ,  2u
      ,  0u
   );
}

void GPT12E_T2_Mode_Counter_Input_T3Out_Sel(void){
   Field_Mod16(
        &GPT12E.T2CON.reg
      ,  2u
      ,  4u
      ,  1u
   );
}

void GPT12E_T2_Mode_Counter_Input_Rising_T3Out_En(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  0u
      ,  1u
      ,  1u
   );
}

void GPT12E_T2_Mode_Counter_Input_Rising_T3Out_Dis(void){
   Field_Mod16(
        &GPT12E.T2CON.reg
      ,  0u
      ,  1u
      ,  0u
   );
}

void GPT12E_T2_Mode_Counter_Input_Falling_T3Out_En(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  1u
      ,  2u
      ,  1u
   );
}

void GPT12E_T2_Mode_Counter_Input_Falling_T3Out_Dis(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  1u
      ,  2u
      ,  0u
   );
}

void GPT12E_T2_Mode_Capture_Input_T2In_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  2u
      ,  4u
      ,  0u
   );
}

void GPT12E_T2_Mode_Capture_Input_Rising_T2In_En(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  0u
      ,  1u
      ,  1u
   );
}

void GPT12E_T2_Mode_Capture_Input_Rising_T2In_Dis(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  0u
      ,  1u
      ,  0u
   );
}

void GPT12E_T2_Mode_Capture_Input_Falling_T2In_En(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  1u
      ,  2u
      ,  1u
   );
}

void GPT12E_T2_Mode_Capture_Input_Falling_T2In_Dis(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  1u
      ,  2u
      ,  0u
   );
}

void GPT12E_T2_Mode_Reload_Input_T2In_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  2u
      ,  4u
      ,  0u
   );
}

void GPT12E_T2_Mode_Reload_Input_Rising_T2In_En(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  0u
      ,  1u
      ,  1u
   );
}

void GPT12E_T2_Mode_Reload_Input_Rising_T2In_Dis(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  0u
      ,  1u
      ,  0u
   );
}

void GPT12E_T2_Mode_Reload_Input_Falling_T2In_En(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  1u
      ,  2u
      ,  1u
   );
}

void GPT12E_T2_Mode_Reload_Input_Falling_T2In_Dis(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  1u
      ,  2u
      ,  0u
   );
}

void GPT12E_T2_Mode_Reload_Input_T3Out_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  2u
      ,  4u
      ,  1u
   );
}

void GPT12E_T2_Mode_Reload_Input_Rising_T3Out_En(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  0u
      ,  1u
      ,  1u
   );
}

void GPT12E_T2_Mode_Reload_Input_Rising_T3Out_Dis(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  0u
      ,  1u
      ,  0u
   );
}

void GPT12E_T2_Mode_Reload_Input_Falling_T3Out_En(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  1u
      ,  2u
      ,  1u
   );
}

void GPT12E_T2_Mode_Reload_Input_Falling_T3Out_Dis(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  1u
      ,  2u
      ,  0u
   );
}

void GPT12E_T2_Mode_IncEnc_Input_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  2u
      ,  4u
      ,  0u
   );
}

void GPT12E_T2_Mode_IncEnc_Any_T3In_En(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  0u
      ,  1u
      ,  1u
   );
}

void GPT12E_T2_Mode_IncEnc_Any_T3In_Dis(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  0u
      ,  1u
      ,  0u
   );
}

void GPT12E_T2_Mode_IncEnc_Any_T3EUD_En(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  1u
      ,  2u
      ,  1u
   );
}

void GPT12E_T2_Mode_IncEnc_Any_T3EUD_Dis(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  1u
      ,  2u
      ,  0u
   );
}
*/
void GPT12E_T2_Start(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2R_Pos
      ,  (uint16)GPT12E_T2CON_T2R_Msk
      ,   1u
   );
}
/*
void GPT12E_T2_Stop(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2R_Pos
      ,  (uint16)GPT12E_T2CON_T2R_Msk
      ,   0u
   );
}

void GPT12E_T2_Start_by_T3_En(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2RC_Pos
      ,  (uint16)GPT12E_T2CON_T2RC_Msk
      ,  1u
   );
}

void GPT12E_T2_Start_by_T3_Dis(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2RC_Pos
      ,  (uint16)GPT12E_T2CON_T2RC_Msk
      ,  0u
   );
}

void GPT12E_T2_DownCount_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2UD_Pos
      ,  (uint16)GPT12E_T2CON_T2UD_Msk
      ,  1u
   );
}

void GPT12E_T2_UpCount_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2UD_Pos
      ,  (uint16)GPT12E_T2CON_T2UD_Msk
      ,  0u
   );
}

void GPT12E_T2_UpDownCount_Ext_En(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2UDE_Pos
      ,  (uint16)GPT12E_T2CON_T2UDE_Msk
      ,   1u
   );
}

void GPT12E_T2_UpDownCount_Ext_Dis(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2UDE_Pos
      ,  (uint16)GPT12E_T2CON_T2UDE_Msk
      ,   0u
   );
}

void GPT12E_T2_Mode_IncEnc_DownCount_RotDir_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2RDIR_Pos
      ,  (uint16)GPT12E_T2CON_T2RDIR_Msk
      ,  1u
   );
}

void GPT12E_T2_Mode_IncEnc_UpCount_RotDir_Sel(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2RDIR_Pos
      ,  (uint16)GPT12E_T2CON_T2RDIR_Msk
      ,  0u
   );
}

uint8 GPT12E_T2_Mode_IncEnc_Edge_Detect_Sts(void){
   return(
         u1_Field_Rd16(
               &GPT12E.T2CON.reg
            ,  (uint16)GPT12E_T2CON_T2EDGE_Pos
            ,  (uint16)GPT12E_T2CON_T2EDGE_Msk
         )
   );
}

void GPT12E_T2_Mode_IncEnc_Edge_Detect_Clr(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2EDGE_Pos
      ,  (uint16)GPT12E_T2CON_T2EDGE_Msk
      ,  0u
   );
}

uint8 GPT12E_T2_Mode_IncEnc_Dir_Change_Sts(void){
   return(
         u1_Field_Rd16(
               &GPT12E.T2CON.reg
            ,  (uint16)GPT12E_T2CON_T2CHDIR_Pos
            ,  (uint16)GPT12E_T2CON_T2CHDIR_Msk
         )
   );
}

void GPT12E_T2_Mode_IncEnc_Dir_Change_Clr(void){
   Field_Mod16(
         &GPT12E.T2CON.reg
      ,  (uint16)GPT12E_T2CON_T2CHDIR_Pos
      ,  (uint16)GPT12E_T2CON_T2CHDIR_Msk
      ,  0u
   );
}

uint16 GPT12E_T2_Value_Get(void){
   return(
         u16_Field_Rd16(
               &GPT12E.T2.reg
            ,  (uint16)GPT12E_T2_T2_Pos
            ,  (uint16)GPT12E_T2_T2_Msk
         )
   );
}

void GPT12E_T2_Value_Set(uint16 t2){
   Field_Wrt16(
         &GPT12E.T2.reg
      ,  (uint16)GPT12E_T2_T2_Pos
      ,  (uint16)GPT12E_T2_T2_Msk
      ,  t2
   );
}

void GPT12E_T2_T2In_Sel(uint16 ist2in){
   Field_Mod16(
         &GPT12E.PISEL.reg
      ,  (uint16)GPT12E_PISEL_IST2IN_Pos
      ,  (uint16)GPT12E_PISEL_IST2IN_Msk
      ,  ist2in
   );
}

void GPT12E_T2_T2EUD_Sel(uint16 ist2eud){
   Field_Mod16(
         &GPT12E.PISEL.reg
      ,  (uint16)GPT12E_PISEL_IST2EUD_Pos
      ,  (uint16)GPT12E_PISEL_IST2EUD_Msk
      ,  ist2eud
   );
}

void GPT12E_T3_Mode_Timer_Sel(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3M_Pos
      ,  (uint16)GPT12E_T3CON_T3M_Msk
      ,  0u
   );
}

void GPT12E_T3_Mode_Counter_Sel(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3M_Pos
      ,  (uint16)GPT12E_T3CON_T3M_Msk
      ,  1u
   );
}

void GPT12E_T3_Mode_Gated_Timer_Low_Sel(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3M_Pos
      ,  (uint16)GPT12E_T3CON_T3M_Msk
      ,  2u
   );
}

void GPT12E_T3_Mode_Gated_Timer_High_Sel(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3M_Pos
      ,  (uint16)GPT12E_T3CON_T3M_Msk
      ,  3u
   );
}

void GPT12E_T3_Mode_IncEnc_Rot_Sel(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3M_Pos
      ,  (uint16)GPT12E_T3CON_T3M_Msk
      ,  6u
   );
}

void GPT12E_T3_Mode_IncEnc_Edge_Sel(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3M_Pos
      ,  (uint16)GPT12E_T3CON_T3M_Msk
      ,  7u
   );
}

void GPT12E_T3_Mode_Timer_Clk_Prescaler_Sel(uint16 t3i){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3I_Pos
      ,  (uint16)GPT12E_T3CON_T3I_Msk
      ,  t3i
   );
}

void GPT12E_T3_Mode_Gated_Timer_Clk_Prescaler_Sel(uint16 t3i){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3I_Pos
      ,  (uint16)GPT12E_T3CON_T3I_Msk
      ,  t3i
   );
}

void GPT12E_T3_Mode_Counter_Input_Rising_T3In_En(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  0u
      ,  1u
      ,  1u
   );
}

void GPT12E_T3_Mode_Counter_Input_Rising_T3In_Dis(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  0u
      ,  1u
      ,  0u
   );
}

void GPT12E_T3_Mode_Counter_Input_Falling_T3In_En(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  1u
      ,  2u
      ,  1u
   );
}

void GPT12E_T3_Mode_Counter_Input_Falling_T3In_Dis(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  1u
      ,  2u
      ,  0u
   );
}

void GPT12E_T3_Mode_IncEnc_Any_T3In_En(void){
   Field_Mod16(&GPT12E.T3CON.reg, 0u, 1u, 1u);
}

void GPT12E_T3_Mode_IncEnc_Any_T3In_Dis(void){
   Field_Mod16(&GPT12E.T3CON.reg, 0u, 1u, 0u);
}

void GPT12E_T3_Mode_IncEnc_Any_T3EUD_En(void){
   Field_Mod16(&GPT12E.T3CON.reg, 1u, 2u, 1u);
}

void GPT12E_T3_Mode_IncEnc_Any_T3EUD_Dis(void){
   Field_Mod16(&GPT12E.T3CON.reg, 1u, 2u, 0u);
}

void GPT12E_T3_Start(void){
   Field_Mod16(&GPT12E.T3CON.reg, (uint16)GPT12E_T3CON_T3R_Pos, (uint16)GPT12E_T3CON_T3R_Msk, 1u);
}

void GPT12E_T3_Stop(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3R_Pos
      ,  (uint16)GPT12E_T3CON_T3R_Msk
      ,  0u
   );
}

void GPT12E_T3_Output_En(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3OE_Pos
      ,  (uint16)GPT12E_T3CON_T3OE_Msk
      ,   1u
   );
}

void GPT12E_T3_Output_Dis(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3OE_Pos
      ,  (uint16)GPT12E_T3CON_T3OE_Msk
      ,   0u
   );
}

void GPT12E_T3_Output_Set(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3OTL_Pos
      ,  (uint16)GPT12E_T3CON_T3OTL_Msk
      ,  1u
   );
}

void GPT12E_T3_Output_Rst(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3OTL_Pos
      ,  (uint16)GPT12E_T3CON_T3OTL_Msk
      ,  0u
   );
}

void GPT12E_T3_DownCount_Sel(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3UD_Pos
      ,  (uint16)GPT12E_T3CON_T3UD_Msk
      ,    1u
   );
}

void GPT12E_T3_UpCount_Sel(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3UD_Pos
      ,  (uint16)GPT12E_T3CON_T3UD_Msk
      ,    0u
   );
}

void GPT12E_T3_UpDownCount_Ext_En(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3UDE_Pos
      ,  (uint16)GPT12E_T3CON_T3UDE_Msk
      ,   1u
   );
}

void GPT12E_T3_UpDownCount_Ext_Dis(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3UDE_Pos
      ,  (uint16)GPT12E_T3CON_T3UDE_Msk
      ,   0u
   );
}

void GPT12E_T3_Mode_IncEnc_DownCount_RotDir_Sel(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3RDIR_Pos
      ,  (uint16)GPT12E_T3CON_T3RDIR_Msk
      ,  1u
   );
}

void GPT12E_T3_Mode_IncEnc_UpCount_RotDir_Sel(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3RDIR_Pos
      ,  (uint16)GPT12E_T3CON_T3RDIR_Msk
      ,  0u
   );
}

uint8 GPT12E_T3_Mode_IncEnc_Edge_Detect_Sts(void){
   return(
         u1_Field_Rd16(
               &GPT12E.T3CON.reg
            ,  (uint16)GPT12E_T3CON_T3EDGE_Pos
            ,  (uint16)GPT12E_T3CON_T3EDGE_Msk
         )
   );
}

void GPT12E_T3_Mode_IncEnc_Edge_Detect_Clr(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3EDGE_Pos
      ,  (uint16)GPT12E_T3CON_T3EDGE_Msk
      ,  0u
   );
}

uint8 GPT12E_T3_Mode_IncEnc_Dir_Change_Sts(void){
   return(
         u1_Field_Rd16(
               &GPT12E.T3CON.reg
            ,  (uint16)GPT12E_T3CON_T3CHDIR_Pos
            ,  (uint16)GPT12E_T3CON_T3CHDIR_Msk
         )
   );
}

void GPT12E_T3_Mode_IncEnc_Dir_Change_Clr(void){
   Field_Mod16(
         &GPT12E.T3CON.reg
      ,  (uint16)GPT12E_T3CON_T3CHDIR_Pos
      ,  (uint16)GPT12E_T3CON_T3CHDIR_Msk
      ,  0u
   );
}

uint16 GPT12E_T3_Value_Get(void){
   return(
         u16_Field_Rd16(
               &GPT12E.T3.reg
            ,  (uint16)GPT12E_T3_T3_Pos
            ,  (uint16)GPT12E_T3_T3_Msk
         )
   );
}

void GPT12E_T3_Value_Set(uint16 t3){
   Field_Wrt16(
         &GPT12E.T3.reg
      ,  (uint16)GPT12E_T3_T3_Pos
      ,  (uint16)GPT12E_T3_T3_Msk
      ,  t3
   );
}

void GPT12E_T3_T3In_Sel(uint16 ist3in){
   Field_Mod16(
         &GPT12E.PISEL.reg
      ,  (uint16)GPT12E_PISEL_IST3IN_Pos
      ,  (uint16)GPT12E_PISEL_IST3IN_Msk
      ,   ist3in
   );
}

void GPT12E_T3_T3EUD_Sel(uint16 ist3eud){
   Field_Mod16(
         &GPT12E.PISEL.reg
      ,  (uint16)GPT12E_PISEL_IST3EUD_Pos
      ,  (uint16)GPT12E_PISEL_IST3EUD_Msk
      ,  ist3eud
   );
}

void GPT12E_T4_Mode_Timer_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4M_Pos
      ,  (uint16)GPT12E_T4CON_T4M_Msk
      ,  0u
   );
}

void GPT12E_T4_Mode_Counter_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4M_Pos
      ,  (uint16)GPT12E_T4CON_T4M_Msk
      ,  1u
   );
}

void GPT12E_T4_Mode_Gated_Timer_Low_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4M_Pos
      ,  (uint16)GPT12E_T4CON_T4M_Msk
      ,  2u
   );
}

void GPT12E_T4_Mode_Gated_Timer_High_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4M_Pos
      ,  (uint16)GPT12E_T4CON_T4M_Msk
      ,  3u
   );
}

void GPT12E_T4_Mode_Reload_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4M_Pos
      ,  (uint16)GPT12E_T4CON_T4M_Msk
      ,  4u
   );
}

void GPT12E_T4_Mode_Capture_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4M_Pos
      ,  (uint16)GPT12E_T4CON_T4M_Msk
      ,  5u
   );
}

void GPT12E_T4_Mode_IncEnc_Rot_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4M_Pos
      ,  (uint16)GPT12E_T4CON_T4M_Msk
      ,  6u
   );
}

void GPT12E_T4_Mode_IncEnc_Edge_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4M_Pos
      ,  (uint16)GPT12E_T4CON_T4M_Msk
      ,  7u
   );
}

void GPT12E_T4_Mode_Timer_Clk_Prescaler_Sel(uint16 t4i){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4I_Pos
      ,  (uint16)GPT12E_T4CON_T4I_Msk
      ,  t4i
   );
}

void GPT12E_T4_Mode_Gated_Timer_Clk_Prescaler_Sel(uint16 t4i){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4I_Pos
      ,  (uint16)GPT12E_T4CON_T4I_Msk
      ,  t4i
   );
}

void GPT12E_T4_Mode_Counter_Input_T4In_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  2u
      ,  4u
      ,  0u
   );
}

void GPT12E_T4_Mode_Counter_Input_Rising_T4In_En(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  0u
      ,  1u
      ,  1u
   );
}

void GPT12E_T4_Mode_Counter_Input_Rising_T4In_Dis(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  0u
      ,  1u
      ,  0u
   );
}

void GPT12E_T4_Mode_Counter_Input_Falling_T4In_En(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  1u
      ,  2u
      ,  1u
   );
}

void GPT12E_T4_Mode_Counter_Input_Falling_T4In_Dis(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  1u
      ,  2u
      ,  0u
   );
}

void GPT12E_T4_Mode_Counter_Input_T3Out_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  2u
      ,  4u
      ,  1u
   );
}

void GPT12E_T4_Mode_Counter_Input_Rising_T3Out_En(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  0u
      ,  1u
      ,  1u
   );
}

void GPT12E_T4_Mode_Counter_Input_Rising_T3Out_Dis(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  0u
      ,  1u
      ,  0u
   );
}

void GPT12E_T4_Mode_Counter_Input_Falling_T3Out_En(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  1u
      ,  2u
      ,  1u
   );
}

void GPT12E_T4_Mode_Counter_Input_Falling_T3Out_Dis(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  1u
      ,  2u
      ,  0u
   );
}

void GPT12E_T4_Mode_Capture_Input_T4In_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  2u
      ,  4u
      ,  0u
   );
}

void GPT12E_T4_Mode_Capture_Input_Rising_T4In_En(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  0u
      ,  1u
      ,  1u
   );
}

void GPT12E_T4_Mode_Capture_Input_Rising_T4In_Dis(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  0u
      ,  1u
      ,  0u
   );
}

void GPT12E_T4_Mode_Capture_Input_Falling_T4In_En(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  1u
      ,  2u
      ,  1u
   );
}

void GPT12E_T4_Mode_Capture_Input_Falling_T4In_Dis(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  1u
      ,  2u
      ,  0u
   );
}

void GPT12E_T4_Mode_Reload_Input_T4In_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  2u
      ,  4u
      ,  0u
   );
}

void GPT12E_T4_Mode_Reload_Input_Rising_T4In_En(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  0u
      ,  1u
      ,  1u
   );
}

void GPT12E_T4_Mode_Reload_Input_Rising_T4In_Dis(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  0u
      ,  1u
      ,  0u
   );
}

void GPT12E_T4_Mode_Reload_Input_Falling_T4In_En(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  1u
      ,  2u
      ,  1u
   );
}

void GPT12E_T4_Mode_Reload_Input_Falling_T4In_Dis(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  1u
      ,  2u
      ,  0u
   );
}

void GPT12E_T4_Mode_Reload_Input_T3Out_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  2u
      ,  4u
      ,  1u
   );
}

void GPT12E_T4_Mode_Reload_Input_Rising_T3Out_En(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  0u
      ,  1u
      ,  1u
   );
}

void GPT12E_T4_Mode_Reload_Input_Rising_T3Out_Dis(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  0u
      ,  1u
      ,  0u
   );
}

void GPT12E_T4_Mode_Reload_Input_Falling_T3Out_En(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  1u
      ,  2u
      ,  1u
   );
}

void GPT12E_T4_Mode_Reload_Input_Falling_T3Out_Dis(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  1u
      ,  2u
      ,  0u
   );
}

void GPT12E_T4_Mode_IncEnc_Any_T3In_En(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  0u
      ,  1u
      ,  1u
   );
}

void GPT12E_T4_Mode_IncEnc_Any_T3In_Dis(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  0u
      ,  1u
      ,  0u
   );
}

void GPT12E_T4_Mode_IncEnc_Any_T3EUD_En(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  1u
      ,  2u
      ,  1u
   );
}

void GPT12E_T4_Mode_IncEnc_Any_T3EUD_Dis(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  1u
      ,  2u
      ,  0u
   );
}

void GPT12E_T4_Start(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4R_Pos
      ,  (uint16)GPT12E_T4CON_T4R_Msk
      ,   1u
   );
}

void GPT12E_T4_Stop(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4R_Pos
      ,  (uint16)GPT12E_T4CON_T4R_Msk
      ,   0u
   );
}

void GPT12E_T4_Start_by_T3_En(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4RC_Pos
      ,  (uint16)GPT12E_T4CON_T4RC_Msk
      ,  1u
   );
}

void GPT12E_T4_Start_by_T3_Dis(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4RC_Pos
      ,  (uint16)GPT12E_T4CON_T4RC_Msk
      ,  0u
   );
}

void GPT12E_T4_DownCount_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4UD_Pos
      ,  (uint16)GPT12E_T4CON_T4UD_Msk
      ,   1u
   );
}

void GPT12E_T4_UpCount_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4UD_Pos
      ,  (uint16)GPT12E_T4CON_T4UD_Msk
      ,   0u
   );
}

void GPT12E_T4_UpDownCount_Ext_En(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4UDE_Pos
      ,  (uint16)GPT12E_T4CON_T4UDE_Msk
      ,  1u
   );
}

void GPT12E_T4_UpDownCount_Ext_Dis(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4UDE_Pos
      ,  (uint16)GPT12E_T4CON_T4UDE_Msk
      ,  0u
   );
}

void GPT12E_T4_Mode_IncEnc_DownCount_RotDir_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4RDIR_Pos
      ,  (uint16)GPT12E_T4CON_T4RDIR_Msk
      ,  1u
   );
}

void GPT12E_T4_Mode_IncEnc_UpCount_RotDir_Sel(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4RDIR_Pos
      ,  (uint16)GPT12E_T4CON_T4RDIR_Msk
      ,  0u
   );
}

void GPT12E_T4_Clr_T2_En(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_CLRT2EN_Pos
      ,  (uint16)GPT12E_T4CON_CLRT2EN_Msk
      ,   1u
   );
}

void GPT12E_T4_Clr_T2_Dis(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_CLRT2EN_Pos
      ,  (uint16)GPT12E_T4CON_CLRT2EN_Msk
      ,   0u
   );
}

void GPT12E_T4_Clr_T3_En(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_CLRT3EN_Pos
      ,  (uint16)GPT12E_T4CON_CLRT3EN_Msk
      ,   1u
   );
}

void GPT12E_T4_Clr_T3_Dis(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_CLRT3EN_Pos
      ,  (uint16)GPT12E_T4CON_CLRT3EN_Msk
      ,   0u
   );
}

uint8 GPT12E_T4_Mode_IncEnc_Edge_Detect_Sts(void){
   return(
         u1_Field_Rd16(
               &GPT12E.T4CON.reg
            ,  (uint16)GPT12E_T4CON_T4EDGE_Pos
            ,  (uint16)GPT12E_T4CON_T4EDGE_Msk
         )
   );
}

void GPT12E_T4_Mode_IncEnc_Edge_Detect_Clr(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4EDGE_Pos
      ,  (uint16)GPT12E_T4CON_T4EDGE_Msk
      ,  0u
   );
}

uint8 GPT12E_T4_Mode_IncEnc_Dir_Change_Sts(void){
   return(
         u1_Field_Rd16(
               &GPT12E.T4CON.reg
            ,  (uint16)GPT12E_T4CON_T4CHDIR_Pos
            ,  (uint16)GPT12E_T4CON_T4CHDIR_Msk
         )
   );
}

void GPT12E_T4_Mode_IncEnc_Dir_Change_Clr(void){
   Field_Mod16(
         &GPT12E.T4CON.reg
      ,  (uint16)GPT12E_T4CON_T4CHDIR_Pos
      ,  (uint16)GPT12E_T4CON_T4CHDIR_Msk
      ,  0u
   );
}

uint16 GPT12E_T4_Value_Get(void){
   return(
         u16_Field_Rd16(
               &GPT12E.T4.reg
            ,  (uint16)GPT12E_T4_T4_Pos
            ,  (uint16)GPT12E_T4_T4_Msk
         )
   );
}

void GPT12E_T4_Value_Set(uint16 t4){
   Field_Wrt16(
         &GPT12E.T4.reg
      ,  (uint16)GPT12E_T4_T4_Pos
      ,  (uint16)GPT12E_T4_T4_Msk
      ,  t4
   );
}

void GPT12E_T4_T4In_Sel(uint16 ist4in){
   Field_Mod16(
         &GPT12E.PISEL.reg
      ,  (uint16)GPT12E_PISEL_IST4IN_Pos
      ,  (uint16)GPT12E_PISEL_IST4IN_Msk
      ,   ist4in
   );
}

void GPT12E_T4_T4EUD_Sel(uint16 ist4eud){
   Field_Mod16(
         &GPT12E.PISEL.reg
      ,  (uint16)GPT12E_PISEL_IST4EUD_Pos
      ,  (uint16)GPT12E_PISEL_IST4EUD_Msk
      ,  ist4eud
   );
}

void GPT12E_GPT2_Clk_Prescaler_Sel(uint16 bps2){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_BPS2_Pos
      ,  (uint16)GPT12E_T6CON_BPS2_Msk
      ,  (bps2 ^ (uint16
   )1));
}

uint16 GPT12E_GPT2_Clk_Prescaler_Get(void){
   return(
         u16_Field_Rd16(
               &GPT12E.T6CON.reg
            ,  (uint16)GPT12E_T6CON_BPS2_Pos
            ,  (uint16)GPT12E_T6CON_BPS2_Msk
         )
      ^  (uint16)1
   );
}

void GPT12E_T5_Mode_Timer_Sel(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5M_Pos
      ,  (uint16)GPT12E_T5CON_T5M_Msk
      ,  0u
   );
}

void GPT12E_T5_Mode_Counter_Sel(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5M_Pos
      ,  (uint16)GPT12E_T5CON_T5M_Msk
      ,  1u
   );
}

void GPT12E_T5_Mode_Gated_Timer_Low_Sel(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5M_Pos
      ,  (uint16)GPT12E_T5CON_T5M_Msk
      ,  2u
   );
}

void GPT12E_T5_Mode_Gated_Timer_High_Sel(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5M_Pos
      ,  (uint16)GPT12E_T5CON_T5M_Msk
      ,  3u
   );
}

void GPT12E_T5_Mode_Timer_Clk_Prescaler_Sel(uint16 t5i){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5I_Pos
      ,  (uint16)GPT12E_T5CON_T5I_Msk
      ,  t5i
   );
}

void GPT12E_T5_Mode_Gated_Timer_Clk_Prescaler_Sel(uint16 t5i){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5I_Pos
      ,  (uint16)GPT12E_T5CON_T5I_Msk
      ,  t5i
   );
}

void GPT12E_T5_Mode_Counter_Input_T5In_Sel(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  2u
      ,  4u
      ,  0u
   );
}

void GPT12E_T5_Mode_Counter_Input_Rising_T5In_Sel(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  0u
      ,  1u
      ,  1u
   );
}

void GPT12E_T5_Mode_Counter_Input_Falling_T5In_Sel(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  1u
      ,  2u
      ,  1u
   );
}

void GPT12E_T5_Mode_Counter_Input_Any_T5In_Sel(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  0u
      ,  3u
      ,  3u
   );
}

void GPT12E_T5_Mode_Counter_Input_T6Out_Sel(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  2u
      ,  4u
      ,  1u
   );
}

void GPT12E_T5_Mode_Counter_Input_Rising_T6Out_En(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  0u
      ,  1u
      ,  1u
   );
}

void GPT12E_T5_Mode_Counter_Input_Rising_T6Out_Dis(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  0u
      ,  1u
      ,  0u
   );
}

void GPT12E_T5_Mode_Counter_Input_Falling_T6Out_En(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  1u
      ,  2u
      ,  1u
   );
}

void GPT12E_T5_Mode_Counter_Input_Falling_T6Out_Dis(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  1u
      ,  2u
      ,  0u
   );
}

void GPT12E_T5_Capture_En(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5SC_Pos
      ,  (uint16)GPT12E_T5CON_T5SC_Msk
      ,  1u
   );
}

void GPT12E_T5_Capture_Dis(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5SC_Pos
      ,  (uint16)GPT12E_T5CON_T5SC_Msk
      ,  0u
   );
}

void GPT12E_T5_Capture_Trig_CapIn_Sel(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_CT3_Pos
      ,  (uint16)GPT12E_T5CON_CT3_Msk
      ,  1u
   );
}

void GPT12E_T5_Capture_Trig_Rising_CapIn_En(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  12u
      ,  ((uint16)1u << 12u)
      ,  1u
   );
}

void GPT12E_T5_Capture_Trig_Rising_CapIn_Dis(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  12u
      ,  ((uint16)1u << 12u)
      ,  0u
   );
}

void GPT12E_T5_Capture_Trig_Falling_CapIn_En(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  13u
      ,  ((uint16)1u << 13u)
      ,  1u
   );
}

void GPT12E_T5_Capture_Trig_Falling_CapIn_Dis(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  13u
      ,  ((uint16)1u << 13u)
      ,  0u
   );
}

void GPT12E_T5_Capture_Trig_T3In_T3EUD_Sel(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_CT3_Pos
      ,  (uint16)GPT12E_T5CON_CT3_Msk
      ,  0u
   );
}

void GPT12E_T5_Capture_Trig_Any_T3In_En(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  12u
      ,  ((uint16)1u << 12u)
      ,  1u
   );
}

void GPT12E_T5_Capture_Trig_Any_T3In_Dis(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  12u
      ,  ((uint16)1u << 12u)
      ,  0u
   );
}

void GPT12E_T5_Capture_Trig_Any_T3EUD_En(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  13u
      ,  ((uint16)1u << 13u)
      ,  1u
   );
}

void GPT12E_T5_Capture_Trig_Any_T3EUD_Dis(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  13u
      ,  ((uint16)1u << 13u)
      ,  0u
   );
}

void GPT12E_T5_Cleared_On_Capture_En(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5CLR_Pos
      ,  (uint16)GPT12E_T5CON_T5CLR_Msk
      ,  1u
   );
}

void GPT12E_T5_Cleared_On_Capture_Dis(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5CLR_Pos
      ,  (uint16)GPT12E_T5CON_T5CLR_Msk
      ,  0u
   );
}

uint16 GPT12E_T5_Capture_Value_Get(void){
   return(
         u16_Field_Rd16(
               &GPT12E.CAPREL.reg
            ,  (uint16)GPT12E_CAPREL_CAPREL_Pos
            ,  (uint16)GPT12E_CAPREL_CAPREL_Msk
         )
   );
}

void GPT12E_T5_Start(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5R_Pos
      ,  (uint16)GPT12E_T5CON_T5R_Msk
      ,   1u
   );
}

void GPT12E_T5_Stop(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5R_Pos
      ,  (uint16)GPT12E_T5CON_T5R_Msk
      ,   0u
   );
}

void GPT12E_T5_Start_by_T6_Dis(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5RC_Pos
      ,  (uint16)GPT12E_T5CON_T5RC_Msk
      ,  0u
   );
}

void GPT12E_T5_Start_by_T6_En(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5RC_Pos
      ,  (uint16)GPT12E_T5CON_T5RC_Msk
      ,  1u
   );
}

void GPT12E_T5_DownCount_Sel(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5UD_Pos
      ,  (uint16)GPT12E_T5CON_T5UD_Msk
      ,   1u
   );
}

void GPT12E_T5_UpCount_Sel(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5UD_Pos
      ,  (uint16)GPT12E_T5CON_T5UD_Msk
      ,   0u
   );
}

void GPT12E_T5_UpDownCount_Ext_En(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5UDE_Pos
      ,  (uint16)GPT12E_T5CON_T5UDE_Msk
      ,  1u
   );
}

void GPT12E_T5_UpDownCount_Ext_Dis(void){
   Field_Mod16(
         &GPT12E.T5CON.reg
      ,  (uint16)GPT12E_T5CON_T5UDE_Pos
      ,  (uint16)GPT12E_T5CON_T5UDE_Msk
      ,  0u
   );
}

uint16 GPT12E_T5_Value_Get(void){
   return(
         u16_Field_Rd16(
               &GPT12E.T5.reg
            ,  (uint16)GPT12E_T5_T5_Pos
            ,  (uint16)GPT12E_T5_T5_Msk
         )
   );
}

void GPT12E_T5_Value_Set(uint16 t5){
   Field_Wrt16(
         &GPT12E.T5.reg
      ,  (uint16)GPT12E_T5_T5_Pos
      ,  (uint16)GPT12E_T5_T5_Msk
      ,  t5
   );
}

void GPT12E_T5_T5In_Sel(uint16 ist5in){
   Field_Mod16(
         &GPT12E.PISEL.reg
      ,  (uint16)GPT12E_PISEL_IST5IN_Pos
      ,  (uint16)GPT12E_PISEL_IST5IN_Msk
      ,  ist5in  
   );
}

void GPT12E_T5_T5EUD_Sel(uint16 ist5eud){
   Field_Mod16(
         &GPT12E.PISEL.reg
      ,  (uint16)GPT12E_PISEL_IST5EUD_Pos
      ,  (uint16)GPT12E_PISEL_IST5EUD_Msk
      ,  ist5eud
   );
}

void GPT12E_T6_Mode_Timer_Sel(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6M_Pos
      ,  (uint16)GPT12E_T6CON_T6M_Msk
      ,  0u
   );
}

void GPT12E_T6_Mode_Counter_Sel(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6M_Pos
      ,  (uint16)GPT12E_T6CON_T6M_Msk
      ,  1u
   );
}

void GPT12E_T6_Mode_Gated_Timer_Low_Sel(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6M_Pos
      ,  (uint16)GPT12E_T6CON_T6M_Msk
      ,  2u
   );
}

void GPT12E_T6_Mode_Gated_Timer_High_Sel(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6M_Pos
      ,  (uint16)GPT12E_T6CON_T6M_Msk
      ,  3u
   );
}

void GPT12E_T6_Mode_Timer_Clk_Prescaler_Sel(uint16 t6i){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6I_Pos
      ,  (uint16)GPT12E_T6CON_T6I_Msk
      ,  t6i
   );
}

void GPT12E_T6_Mode_Gated_Timer_Clk_Prescaler_Sel(uint16 t6i){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6I_Pos
      ,  (uint16)GPT12E_T6CON_T6I_Msk
      ,  t6i
   );
}

void GPT12E_T6_Mode_Counter_Input_T6In_Sel(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)2u
      ,  (uint16)4u
      ,  0u
   );
}

void GPT12E_T6_Mode_Counter_Input_Rising_T6In_Sel(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)0u
      ,  (uint16)1u
      ,  1u
   );
}

void GPT12E_T6_Mode_Counter_Input_Falling_T6In_Sel(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)1u
      ,  (uint16)2u
      ,  1u
   );
}

void GPT12E_T6_Mode_Counter_Input_Any_T6In_Sel(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)0u
      ,  (uint16)3u
      ,  3u
   );
}

void GPT12E_T6_Reload_En(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,   (uint16)GPT12E_T6CON_T6SR_Pos
      ,  (uint16)GPT12E_T6CON_T6SR_Msk
      ,     1u
   );
}

void GPT12E_T6_Reload_Dis(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,   (uint16)GPT12E_T6CON_T6SR_Pos
      ,  (uint16)GPT12E_T6CON_T6SR_Msk
      ,     0u
   );
}

void GPT12E_T6_Reload_Value_Set(uint16 rl){
   Field_Mod16(
         &GPT12E.CAPREL.reg
      ,  (uint16)GPT12E_CAPREL_CAPREL_Pos
      ,  (uint16)GPT12E_CAPREL_CAPREL_Msk
      ,  rl
   );
}

void GPT12E_T6_On_Capture_Cleared_En(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6CLR_Pos
      ,  (uint16)GPT12E_T6CON_T6CLR_Msk
      ,  1u
   );
}

void GPT12E_T6_On_Capture_Cleared_Dis(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6CLR_Pos
      ,  (uint16)GPT12E_T6CON_T6CLR_Msk
      ,  0u
   );
}

void GPT12E_T6_Start(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6R_Pos
      ,  (uint16)GPT12E_T6CON_T6R_Msk
      ,     1u
   );
}

void GPT12E_T6_Stop(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6R_Pos
      ,  (uint16)GPT12E_T6CON_T6R_Msk
      ,     0u
   );
}

void GPT12E_T6_Output_En(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6OE_Pos
      ,  (uint16)GPT12E_T6CON_T6OE_Msk
      ,   1u
   );
}

void GPT12E_T6_Output_Dis(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6OE_Pos
      ,  (uint16)GPT12E_T6CON_T6OE_Msk
      ,   0u
   );
}

void GPT12E_T6_Output_Set(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6OTL_Pos
      ,  (uint16)GPT12E_T6CON_T6OTL_Msk
      ,  1u
   );
}

void GPT12E_T6_Output_Rst(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6OTL_Pos
      ,  (uint16)GPT12E_T6CON_T6OTL_Msk
      ,  0u
   );
}

void GPT12E_T6_DownCount_Sel(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6UD_Pos
      ,  (uint16)GPT12E_T6CON_T6UD_Msk
      ,   1u
   );
}

void GPT12E_T6_UpCount_Sel(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6UD_Pos
      ,  (uint16)GPT12E_T6CON_T6UD_Msk
      ,   0u
   );
}

void GPT12E_T6_UpDownCount_Ext_En(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6UDE_Pos
      ,  (uint16)GPT12E_T6CON_T6UDE_Msk
      ,  1u
   );
}

void GPT12E_T6_UpDownCount_Ext_Dis(void){
   Field_Mod16(
         &GPT12E.T6CON.reg
      ,  (uint16)GPT12E_T6CON_T6UDE_Pos
      ,  (uint16)GPT12E_T6CON_T6UDE_Msk
      ,  0u
   );
}

uint16 GPT12E_T6_Value_Get(void){
   return(
         u16_Field_Rd16(
               &GPT12E.T6.reg
            ,  (uint16)GPT12E_T6_T6_Pos
            ,  (uint16)GPT12E_T6_T6_Msk
         )
   );
}

void GPT12E_T6_Value_Set(uint16 t6){
   Field_Wrt16(
         &GPT12E.T6.reg
      ,  (uint16)GPT12E_T6_T6_Pos
      ,  (uint16)GPT12E_T6_T6_Msk
      ,  t6
   );
}

void GPT12E_T6_T6In_Sel(uint16 ist6in){
   Field_Mod16(
         &GPT12E.PISEL.reg
      ,  (uint16)GPT12E_PISEL_IST6IN_Pos
      ,  (uint16)GPT12E_PISEL_IST6IN_Msk
      ,   ist6in 
   );
}

void GPT12E_T6_T6EUD_Sel(uint16 ist6eud){
   Field_Mod16(
         &GPT12E.PISEL.reg
      ,  (uint16)GPT12E_PISEL_IST6EUD_Pos
      ,  (uint16)GPT12E_PISEL_IST6EUD_Msk
      ,  ist6eud
   );
}

void GPT12E_CapRel_CAPIn_Sel(uint16 iscapin){
   Field_Mod16(
         &GPT12E.PISEL.reg
      ,  (uint16)GPT12E_PISEL_ISCAPIN_Pos
      ,  (uint16)GPT12E_PISEL_ISCAPIN_Msk
      ,  iscapin
   );
}

uint8 GPT12E_T2_Int_Sts(void){
   return(
         u1_Field_Rd8(
               &SCU.GPT12IRC.reg
            ,  (uint8)SCU_GPT12IRC_T2_Pos
            ,  (uint8)SCU_GPT12IRC_T2_Msk
         )
   );
}

uint8 GPT12E_T3_Int_Sts(void){
   return(
         u1_Field_Rd8(
               &SCU.GPT12IRC.reg
            ,  (uint8)SCU_GPT12IRC_T3_Pos
            ,  (uint8)SCU_GPT12IRC_T3_Msk
         )
   );
}

uint8 GPT12E_T4_Int_Sts(void){
   return(
         u1_Field_Rd8(
               &SCU.GPT12IRC.reg
            ,  (uint8)SCU_GPT12IRC_T4_Pos
            ,  (uint8)SCU_GPT12IRC_T4_Msk
         )
   );
}

uint8 GPT12E_T5_Int_Sts(void){
   return(
         u1_Field_Rd8(
               &SCU.GPT12IRC.reg
            ,  (uint8)SCU_GPT12IRC_T5_Pos
            ,  (uint8)SCU_GPT12IRC_T5_Msk
         )
   );
}

uint8 GPT12E_T6_Int_Sts(void){
   return(
         u1_Field_Rd8(
               &SCU.GPT12IRC.reg
            ,  (uint8)SCU_GPT12IRC_T6_Pos
            ,  (uint8)SCU_GPT12IRC_T6_Msk
         )
   );
}

uint8 GPT12E_CapRel_Int_Sts(void){
   return(
         u1_Field_Rd8(
               &SCU.GPT12IRC.reg
            ,  (uint8)SCU_GPT12IRC_CR_Pos
            ,  (uint8)SCU_GPT12IRC_CR_Msk
         )
   );
}
*/
void GPT12E_T2_Int_Clr(void){
   Field_Wrt8(
         &SCU.GPT12ICLR.reg
      ,  (uint8)SCU_GPT12ICLR_T2C_Pos
      ,  (uint8)SCU_GPT12ICLR_T2C_Msk
      ,  1u
   );
}
/*
void GPT12E_T3_Int_Clr(void){
   Field_Wrt8(
         &SCU.GPT12ICLR.reg
      ,  (uint8)SCU_GPT12ICLR_T3C_Pos
      ,  (uint8)SCU_GPT12ICLR_T3C_Msk
      ,  1u
   );
}

void GPT12E_T4_Int_Clr(void){
   Field_Wrt8(
         &SCU.GPT12ICLR.reg
      ,  (uint8)SCU_GPT12ICLR_T4C_Pos
      ,  (uint8)SCU_GPT12ICLR_T4C_Msk
      ,  1u
   );
}

void GPT12E_T5_Int_Clr(void){
   Field_Wrt8(
         &SCU.GPT12ICLR.reg
      ,  (uint8)SCU_GPT12ICLR_T5C_Pos
      ,  (uint8)SCU_GPT12ICLR_T5C_Msk
      ,  1u
   );
}

void GPT12E_T6_Int_Clr(void){
   Field_Wrt8(
         &SCU.GPT12ICLR.reg
      ,  (uint8)SCU_GPT12ICLR_T6C_Pos
      ,  (uint8)SCU_GPT12ICLR_T6C_Msk
      ,  1u
   );
}

void GPT12E_CapRel_Int_Clr(void){
   Field_Wrt8(
         &SCU.GPT12ICLR.reg
      ,  (uint8)SCU_GPT12ICLR_CRC_Pos
      ,  (uint8)SCU_GPT12ICLR_CRC_Msk
      ,  1u
   );
}

void GPT12E_T2_Int_En(void){
   Field_Mod8(
         &SCU.GPT12IEN.reg
      ,  (uint8)SCU_GPT12IEN_T2IE_Pos
      ,  (uint8)SCU_GPT12IEN_T2IE_Msk
      ,  1u
   );
}

void GPT12E_T2_Int_Dis(void){
   Field_Mod8(
         &SCU.GPT12IEN.reg
      ,  (uint8)SCU_GPT12IEN_T2IE_Pos
      ,  (uint8)SCU_GPT12IEN_T2IE_Msk
      ,  0u
   );
}

void GPT12E_T3_Int_En(void){
   Field_Mod8(
         &SCU.GPT12IEN.reg
      ,  (uint8)SCU_GPT12IEN_T3IE_Pos
      ,  (uint8)SCU_GPT12IEN_T3IE_Msk
      ,  1u
   );
}

void GPT12E_T3_Int_Dis(void){
   Field_Mod8(
         &SCU.GPT12IEN.reg
      ,  (uint8)SCU_GPT12IEN_T3IE_Pos
      ,  (uint8)SCU_GPT12IEN_T3IE_Msk
      ,  0u
   );
}

void GPT12E_T4_Int_En(void){
   Field_Mod8(
         &SCU.GPT12IEN.reg
      ,  (uint8)SCU_GPT12IEN_T4IE_Pos
      ,  (uint8)SCU_GPT12IEN_T4IE_Msk
      ,  1u
   );
}

void GPT12E_T4_Int_Dis(void){
   Field_Mod8(
         &SCU.GPT12IEN.reg
      ,  (uint8)SCU_GPT12IEN_T4IE_Pos
      ,  (uint8)SCU_GPT12IEN_T4IE_Msk
      ,  0u
   );
}

void GPT12E_T5_Int_En(void){
   Field_Mod8(
         &SCU.GPT12IEN.reg
      ,  (uint8)SCU_GPT12IEN_T5IE_Pos
      ,  (uint8)SCU_GPT12IEN_T5IE_Msk
      ,  1u
   );
}

void GPT12E_T5_Int_Dis(void){
   Field_Mod8(
         &SCU.GPT12IEN.reg
      ,  (uint8)SCU_GPT12IEN_T5IE_Pos
      ,  (uint8)SCU_GPT12IEN_T5IE_Msk
      ,  0u
   );
}

void GPT12E_T6_Int_En(void){
   Field_Mod8(
         &SCU.GPT12IEN.reg
      ,  (uint8)SCU_GPT12IEN_T6IE_Pos
      ,  (uint8)SCU_GPT12IEN_T6IE_Msk
      ,  1u
   );
}

void GPT12E_T6_Int_Dis(void){
   Field_Mod8(
         &SCU.GPT12IEN.reg
      ,  (uint8)SCU_GPT12IEN_T6IE_Pos
      ,  (uint8)SCU_GPT12IEN_T6IE_Msk
      ,  0u
   );
}

void GPT12E_CapRel_Int_En(void){
   Field_Mod8(
         &SCU.GPT12IEN.reg
      ,  (uint8)SCU_GPT12IEN_CRIE_Pos
      ,  (uint8)SCU_GPT12IEN_CRIE_Msk
      ,  1u
   );
}

void GPT12E_CapRel_Int_Dis(void){
   Field_Mod8(
         &SCU.GPT12IEN.reg
      ,  (uint8)SCU_GPT12IEN_CRIE_Pos
      ,  (uint8)SCU_GPT12IEN_CRIE_Msk
      ,  0u
   );
}
*/

void GPT1_T2_Handler(void){
   GPT12E.T2.reg += GPT12E_T2_TICK;
   Emo_HandleT2Overflow();
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

