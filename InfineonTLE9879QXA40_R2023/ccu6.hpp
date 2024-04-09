#pragma once
/******************************************************************************/
/* File   : ccu6.hpp                                                          */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Nagaraja HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/NagarajaHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CCU6_MASK_TCTR4_STOP_T12                       (CCU6_TCTR4_T12RR_Msk)
#define CCU6_MASK_TCTR4_START_T12                      (CCU6_TCTR4_T12RS_Msk)
#define CCU6_MASK_TCTR4_RESET_T12                      (CCU6_TCTR4_T12RES_Msk)
#define CCU6_MASK_TCTR4_SHADOW_T12                     (CCU6_TCTR4_T12STR_Msk)
#define CCU6_MASK_TCTR4_STOP_T13                       (CCU6_TCTR4_T13RR_Msk)
#define CCU6_MASK_TCTR4_START_T13                      (CCU6_TCTR4_T13RS_Msk)
#define CCU6_MASK_TCTR4_RESET_T13                      (CCU6_TCTR4_T13RES_Msk)
#define CCU6_MASK_TCTR4_SHADOW_T13                     (CCU6_TCTR4_T13STR_Msk)
#define CCU6_MASK_MCMOUTS_SHADOW_HALL                  (CCU6_MCMOUTS_STRHP_Msk)
#define CCU6_MASK_MCMOUTS_SHADOW_OUT                   (CCU6_MCMOUTS_STRMCM_Msk)
#define CCU6_MASK_CC60                                 ((uint16)1u << 0u)
#define CCU6_MASK_COUT60                               ((uint16)1u << 1u)
#define CCU6_MASK_CC61                                 ((uint16)1u << 2u)
#define CCU6_MASK_COUT61                               ((uint16)1u << 3u)
#define CCU6_MASK_CC62                                 ((uint16)1u << 4u)
#define CCU6_MASK_COUT62                               ((uint16)1u << 5u)
#define CCU6_MASK_Ch0t                                 CCU6_MASK_CC60
#define CCU6_MASK_Ch0c                                 CCU6_MASK_COUT60
#define CCU6_MASK_Ch1t                                 CCU6_MASK_CC61
#define CCU6_MASK_Ch1c                                 CCU6_MASK_COUT61
#define CCU6_MASK_Ch2t                                 CCU6_MASK_CC62
#define CCU6_MASK_Ch2c                                 CCU6_MASK_COUT62

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef enum{
  CCU6_CC60_0_P04  = 0u
   ,  CCU6_CC60_1_P23  = 1u
}TCCU6_Ch0_Input;

typedef enum{
  CCU6_CC61_0_P10  = 0u
}TCCU6_Ch1_Input;

typedef enum{
  CCU6_CC62_0_P13  = 0u
   ,  CCU6_CC62_2_P22  = 2u
}TCCU6_Ch2_Input;

typedef enum{
  CCU6_CTRAP_0_P24  = 0u
   ,  CCU6_CTRAP_1_P23  = 1u
}TCCU6_Trap_Input;

typedef enum{
  CCU6_CCPOS0_1_P03  = 1u
   ,  CCU6_CCPOS0_2_P13  = 2u
   ,  CCU6_CCPOS0_3_P20  = 3u
#if(UC_SERIES == TLE987)

   ,  CCU6_CCPOS0_BEMF   = 3u
#endif
}TCCU6_Pos0_Input;

typedef enum{
  CCU6_CCPOS1_0_P23  = 0u
   ,  CCU6_CCPOS1_1_P04  = 1u
   ,  CCU6_CCPOS1_2_P14  = 2u
#if(UC_SERIES == TLE987)

   ,  CCU6_CCPOS1_BEMF   = 3u
#endif
}TCCU6_Pos1_Input;

typedef enum{
  CCU6_CCPOS2_1_P02  = 1u
   ,  CCU6_CCPOS2_2_P12  = 2u
   ,  CCU6_CCPOS2_3_P22  = 3u
#if(UC_SERIES == TLE987)

   ,  CCU6_CCPOS2_BEMF   = 3u
#endif
}TCCU6_Pos2_Input;

typedef enum{
  CCU6_T12HR_0_P00  = 0u
   ,  CCU6_T12HR_2_P20  = 2u
}TCCU6_T12HR_Input;

typedef enum{
  CCU6_T13HR_0_P01  = 0u
   ,  CCU6_T13HR_2_P22  = 2u
}TCCU6_T13HR_Input;

typedef enum{
  CCU6_T12_Prescaler      = 0u
   ,  CCU6_TCTR4_T12CNT       = 1u
   ,  CCU6_T12HR_Rising_Edge  = 2u
   ,  CCU6_T12HR_Falling_Edge = 3u
}TCCU6_T12_Cnt_Input;

typedef enum{
  CCU6_T13_Prescaler      = 0u
   ,  CCU6_TCTR4_T13CNT       = 1u
   ,  CCU6_T13HR_Rising_Edge  = 2u
   ,  CCU6_T13HR_Falling_Edge = 3u
}TCCU6_T13_Cnt_Input;

typedef enum{
  CCU6_T12HR_D_A      = 0u
   ,  CCU6_T12HR_H_E      = 1u
}TCCU6_T12_Ext_Input;

typedef enum{
  CCU6_T13HR_D_A      = 0u
   ,  CCU6_T13HR_H_E      = 1u
}TCCU6_T13_Ext_Input;

typedef enum{
  CCU6_CCPOS0x_Any_Edge     = 0u
   ,  CCU6_T13_CM               = 1u
   ,  CCU6_T13_PM               = 2u
   ,  CCU6_HW_Hall_Sampling_Off = 3u
   ,  CCU6_T12_PM               = 4u
   ,  CCU6_T12_OM               = 5u
   ,  CCU6_T12_CM_Ch1_up        = 6u
   ,  CCU6_T12_CM_Ch1_down      = 7u
}TCCU6_HSYNC;

typedef enum{
  CCU6_Clk_Div_1   = 0
   ,  CCU6_Clk_Div_2   = 1
   ,  CCU6_Clk_Div_4   = 2
   ,  CCU6_Clk_Div_8   = 3
   ,  CCU6_Clk_Div_16  = 4
   ,  CCU6_Clk_Div_32  = 5
   ,  CCU6_Clk_Div_64  = 6
   ,  CCU6_Clk_Div_128 = 7
}TCCU6_Clk_Prescaler;

typedef enum{
  CCU6_T13TEC_No_Trigger = 0
   ,  CCU6_T13TEC_T12_CM_Ch0 = 1
   ,  CCU6_T13TEC_T12_CM_Ch1 = 2
   ,  CCU6_T13TEC_T12_CM_Ch2 = 3
   ,  CCU6_T13TEC_T12_CM_Chx = 4
   ,  CCU6_T13TEC_T12_PM     = 5
   ,  CCU6_T13TEC_T12_ZM     = 6
   ,  CCU6_T13TEC_CCPOSx     = 7
}TCCU6_T13TEC;

typedef enum{
  CCU6_T13ED_No_Action   = 0
   ,  CCU6_T13ED_T12_Up      = 1
   ,  CCU6_T13ED_T12_Down    = 2
   ,  CCU6_T13ED_T12_UpDown  = 3
}TCCU6_T13ED;

typedef enum{
  CCU6_T12RSEL_Dis        = 0
   ,  CCU6_T12RSEL_T12HR_Rise = 1
   ,  CCU6_T12RSEL_T12HR_Fall = 2
   ,  CCU6_T12RSEL_T12HR_Any  = 3
}TCCU6_T12RSEL;

typedef enum{
  CCU6_T13RSEL_Dis        = 0
   ,  CCU6_T13RSEL_T13HR_Rise = 1
   ,  CCU6_T13RSEL_T13HR_Fall = 2
   ,  CCU6_T13RSEL_T13HR_Any  = 3
}TCCU6_T13RSEL;

typedef enum{
  CCU6_PSL63_Low  = 0
   ,  CCU6_PSL63_High = 1
}TCCU6_PSL63;

typedef enum{
  CCU6_SWSEL_No_Action    = 0
   ,  CCU6_SWSEL_Correct_Hall = 1
   ,  CCU6_SWSEL_T13_PM       = 2
   ,  CCU6_SWSEL_T12_OM       = 3
   ,  CCU6_SWSEL_T12_Ch1_CM   = 4
   ,  CCU6_SWSEL_T12_PM       = 5
}TCCU6_MCM_SWSEL;

typedef enum{
  CCU6_Node0 = 0
   ,  CCU6_Node1 = 1
   ,  CCU6_Node2 = 2
   ,  CCU6_Node3 = 3
}TCCU6_Node_Sel;

typedef enum{
  CCU6_T12_ActiveLeftAligned  = 0x15
   ,  CCU6_T12_ActiveRightAligned  = 0x2A
   ,  CCU6_T12_ActiveCenterAligned  = 0x2A
   ,  CCU6_T12_ActiveCenterAlignedInverted  = 0x15
}TCCU6_PWMMode;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
extern void   CCU6_Init                                  (void);
extern void   CCU6_T12_Stop                              (void);
extern void   CCU6_T12_Start                             (void);
extern void   CCU6_T12_Rst                               (void);
extern void   CCU6_Deadtime_Rst                          (void);
extern void   CCU6_T12_Cnt                               (void);
extern void   CCU6_T12_Str_En                            (void);
extern void   CCU6_T12_Str_Dis                           (void);
extern void   CCU6_T13_Stop                              (void);
extern void   CCU6_T13_Start                             (void);
extern void   CCU6_T13_Rst                               (void);
extern void   CCU6_T13_Cnt                               (void);
extern void   CCU6_T13_Str_En                            (void);
extern void   CCU6_T13_Str_Dis                           (void);
extern void   CCU6_Ch0_Input_Sel                         (uint16 iscc60);
extern void   CCU6_Ch1_Input_Sel                         (uint16 iscc61);
extern void   CCU6_Ch2_Input_Sel                         (uint16 iscc62);
extern void   CCU6_Trap_Input_Sel                        (uint16 istrp);
extern void   CCU6_CCPOS0_Input_Sel                      (uint16 ispos0);
extern void   CCU6_CCPOS1_Input_Sel                      (uint16 ispos1);
extern void   CCU6_CCPOS2_Input_Sel                      (uint16 ispos2);
extern void   CCU6_T12HR_Input_Sel                       (uint16 ist12hr);
extern void   CCU6_T13HR_Input_Sel                       (uint16 ist13hr);
extern void   CCU6_T12_Cnt_Input_Sel                     (uint16 iscnt12);
extern void   CCU6_T13_Cnt_Input_Sel                     (uint16 iscnt13);
extern void   CCU6_T12_Ext_Input_Sel                     (uint16 t12ext);
extern void   CCU6_T13_Ext_Input_Sel                     (uint16 t13ext);
extern void   CCU6_Hall_Delay_Bypass_En                  (void);
extern void   CCU6_Hall_Delay_Bypass_Dis                 (void);
extern void   CCU6_Hall_Synchronizaion_Sel               (uint16 hsync);
extern void   CCU6_Ch2_CapCom_Mode_Sel                   (uint16 msel62);
extern void   CCU6_Ch1_CapCom_Mode_Sel                   (uint16 msel61);
extern void   CCU6_Ch0_CapCom_Mode_Sel                   (uint16 msel60);
extern uint16 CCU6_T12_Count_Value_Get                   (void);
extern void   CCU6_T12_Count_Value_Set                   (uint16 t12cv);
extern uint16 CCU6_T12_Period_Value_Get                  (void);
extern void   CCU6_T12_Period_Value_Set                  (uint16 t12pr);
extern uint16 CCU6_Ch0_Value_Get                         (void);
extern void   CCU6_Ch0_Value_Set                         (uint16 cc60sr);
extern uint16 CCU6_Ch1_Value_Get                         (void);
extern void   CCU6_Ch1_Value_Set                         (uint16 cc61sr);
extern uint16 CCU6_Ch2_Value_Get                         (void);
extern void   CCU6_Ch2_Value_Set                         (uint16 cc62sr);
extern uint8  CCU6_Deadtime_Get                          (void);
extern void   CCU6_Deadtime_Set                          (uint16 dtm);
extern void   CCU6_Ch0_Deadtime_En                       (void);
extern void   CCU6_Ch1_Deadtime_En                       (void);
extern void   CCU6_Ch2_Deadtime_En                       (void);
extern void   CCU6_Ch0_Deadtime_Dis                      (void);
extern void   CCU6_Ch1_Deadtime_Dis                      (void);
extern void   CCU6_Ch2_Deadtime_Dis                      (void);
extern uint8  CCU6_Ch0_Deadtime_Sts                      (void);
extern uint8  CCU6_Ch1_Deadtime_Sts                      (void);
extern uint8  CCU6_Ch2_Deadtime_Sts                      (void);
extern uint16 CCU6_T13_Count_Value_Get                   (void);
extern void   CCU6_T13_Count_Value_Set                   (uint16 t13cv);
extern uint16 CCU6_T13_Period_Value_Get                  (void);
extern void   CCU6_T13_Period_Value_Set                  (uint16 t13pr);
extern uint16 CCU6_Ch3_Value_Get                         (void);
extern void   CCU6_Ch3_Value_Set                         (uint16 cc63sr);
extern uint8  CCU6_Ch0_CompState_Sts                     (void);
extern uint8  CCU6_Ch1_CompState_Sts                     (void);
extern uint8  CCU6_Ch2_CompState_Sts                     (void);
extern uint8  CCU6_Ch3_CompState_Sts                     (void);
extern uint8  CCU6_Hall_Ch0_Sts                          (void);
extern uint8  CCU6_Hall_Ch1_Sts                          (void);
extern uint8  CCU6_Hall_Ch2_Sts                          (void);
extern void   CCU6_T12_PWMMode_Set                       (TCCU6_PWMMode mode);
extern void   CCU6_Ch3c_Passive_State_After_Compare_Set  (void);
extern void   CCU6_Ch3c_Passive_State_Before_Compare_Set (void);
extern void   CCU6_T13_Inv_Mod_En                        (void);
extern void   CCU6_T13_Inv_Mod_Dis                       (void);
extern void   CCU6_Ch0_CompState_Set                     (void);
extern void   CCU6_Ch1_CompState_Set                     (void);
extern void   CCU6_Ch2_CompState_Set                     (void);
extern void   CCU6_Ch3_CompState_Set                     (void);
extern void   CCU6_Ch0_CompState_Rst                     (void);
extern void   CCU6_Ch1_CompState_Rst                     (void);
extern void   CCU6_Ch2_CompState_Rst                     (void);
extern void   CCU6_Ch3_CompState_Rst                     (void);
extern void   CCU6_T12_Edge_Aligned_Mode_En              (void);
extern void   CCU6_T12_Center_Aligned_Mode_En            (void);
extern void   CCU6_T12_Clk_Sel                           (uint16 t12clk);
extern void   CCU6_T13_Clk_Sel                           (uint16 t13clk);
extern void   CCU6_T12_Prescaler_En                      (void);
extern void   CCU6_T12_Prescaler_Dis                     (void);
extern void   CCU6_T13_Prescaler_En                      (void);
extern void   CCU6_T13_Prescaler_Dis                     (void);
extern uint8  CCU6_T12_Run_Sts                           (void);
extern uint8  CCU6_T12_Str_Sts                           (void);
extern uint8  CCU6_T12_Count_Dir_Sts                     (void);
extern uint8  CCU6_T13_Run_Sts                           (void);
extern uint8  CCU6_T13_Str_Sts                           (void);
extern void   CCU6_T12_Single_Shot_En                    (void);
extern void   CCU6_T12_Single_Shot_Dis                   (void);
extern void   CCU6_T13_Trig_Event_Sel                    (uint16 t13tec);
extern void   CCU6_T13_Trig_Event_Dir_Sel                (uint16 t13ted);
extern void   CCU6_T12_Ext_Run_Sel                       (uint16 t12rsel);
extern void   CCU6_T13_Ext_Run_Sel                       (uint16 t13rsel);
extern void   CCU6_T12_Modulation_En                     (uint16 ccu6_mask);
extern void   CCU6_T12_Modulation_Dis                    (uint16 ccu6_mask);
extern void   CCU6_T13_Modulation_En                     (uint16 ccu6_mask);
extern void   CCU6_T13_Modulation_Dis                    (uint16 ccu6_mask);
extern void   CCU6_Multi_Ch_Mode_En                      (void);
extern void   CCU6_Multi_Ch_Mode_Dis                     (void);
extern void   CCU6_T13_Compare_Out_En                    (void);
extern void   CCU6_T13_Compare_Out_Dis                   (void);
extern void   CCU6_Trap_T12_ZM_Exit_En                   (void);
extern void   CCU6_Trap_T13_ZM_Exit_En                   (void);
extern void   CCU6_Trap_Asynch_Exit_En                   (void);
extern void   CCU6_Trap_HW_Clr_En                        (void);
extern void   CCU6_Trap_SW_Clr_En                        (void);
extern void   CCU6_Trap_T13_En                           (void);
extern void   CCU6_Trap_T13_Dis                          (void);
extern void   CCU6_Trap_Pin_En                           (void);
extern void   CCU6_Trap_Pin_Dis                          (void);
extern void   CCU6_Trap_Channel_En                       (uint16 ccu6_mask);
extern void   CCU6_Ch0t_Passive_Level_High_Set           (void);
extern void   CCU6_Ch0t_Passive_Level_Low_Set            (void);
extern void   CCU6_Ch0c_Passive_Level_High_Set           (void);
extern void   CCU6_Ch0c_Passive_Level_Low_Set            (void);
extern void   CCU6_Ch1t_Passive_Level_High_Set           (void);
extern void   CCU6_Ch1t_Passive_Level_Low_Set            (void);
extern void   CCU6_Ch1c_Passive_Level_High_Set           (void);
extern void   CCU6_Ch1c_Passive_Level_Low_Set            (void);
extern void   CCU6_Ch2t_Passive_Level_High_Set           (void);
extern void   CCU6_Ch2t_Passive_Level_Low_Set            (void);
extern void   CCU6_Ch2c_Passive_Level_High_Set           (void);
extern void   CCU6_Ch2c_Passive_Level_Low_Set            (void);
extern void   CCU6_Passive_Level_High_Sel                (uint16 ccu6_mask);
extern void   CCU6_Passiv_Level_Ch3_Sel                  (uint16 lvl);
extern void   CCU6_Multi_Ch_PWM_Shadow_Reg_Load          (uint16 ccu6_mask);
extern void   CCU6_MCM_PWM_Str_SW_En                     (void);
extern void   CCU6_MCM_PWM_Str_HW_En                     (void);
extern void   CCU6_MCM_Expected_Hall_Shadow_Reg_Load     (uint16 mcm_mask_ccpos);
extern void   CCU6_MCM_Current_Hall_Shadow_Reg_Load      (uint16 mcm_mask_ccpos);
extern void   CCU6_MCM_Hall_Str_SW_En                    (void);
extern void   CCU6_MCM_Hall_Str_HW_En                    (void);
extern uint8  CCU6_MCM_PWM_Pattern_Sts                   (void);
extern uint8  CCU6_MCM_PWM_Str_Req_Sts                   (void);
extern uint8  CCU6_MCM_Expected_Hall_Sts                 (void);
extern uint8  CCU6_MCM_Current_Hall_Sts                  (void);
extern void   CCU6_MCM_Switch_Sel                        (uint16 swsel);
extern void   CCU6_MCM_Switch_NoTrigger_Set              (void);
extern void   CCU6_MCM_Switch_CorrectHall_Set            (void);
extern void   CCU6_MCM_Switch_T13_PM_Set                 (void);
extern void   CCU6_MCM_Switch_T12_ON_Set                 (void);
extern void   CCU6_MCM_Switch_T12_Ch1_CM_Set             (void);
extern void   CCU6_MCM_Switch_T12_PM_Set                 (void);
extern void   CCU6_MCM_Switch_Sync_direct_Sel            (void);
extern void   CCU6_MCM_Switch_Sync_T13_ZM_Sel            (void);
extern void   CCU6_MCM_Switch_Sync_T12_ZM_Sel            (void);
extern void   CCU6_MCM_Str_T12_Up_Cnt_En                 (void);
extern void   CCU6_MCM_Str_T12_Up_Cnt_Dis                (void);
extern void   CCU6_MCM_Str_T12_Down_Cnt_En               (void);
extern void   CCU6_MCM_Str_T12_Down_Cnt_Dis              (void);
extern void   CCU6_MCM_Str_T13_Up_Cnt_En                 (void);
extern void   CCU6_MCM_Str_T13_Up_Cnt_Dis                (void);
extern uint8  CCU6_T12_CM_CC60_Int_Rise_Sts              (void);
extern uint8  CCU6_T12_CM_CC61_Int_Rise_Sts              (void);
extern uint8  CCU6_T12_CM_CC62_Int_Rise_Sts              (void);
extern uint8  CCU6_T12_CM_CC60_Int_Fall_Sts              (void);
extern uint8  CCU6_T12_CM_CC61_Int_Fall_Sts              (void);
extern uint8  CCU6_T12_CM_CC62_Int_Fall_Sts              (void);
extern uint8  CCU6_T12_OM_Int_Sts                        (void);
extern uint8  CCU6_T12_PM_Int_Sts                        (void);
extern uint8  CCU6_T13_CM_Int_Sts                        (void);
extern uint8  CCU6_T13_PM_Int_Sts                        (void);
extern uint8  CCU6_Trap_Flag_Int_Sts                     (void);
extern uint8  CCU6_Trap_State_Int_Sts                    (void);
extern uint8  CCU6_Hall_Correct_Int_Sts                  (void);
extern uint8  CCU6_Hall_Wrong_Int_Sts                    (void);
extern uint8  CCU6_MCM_Idle_Int_Sts                      (void);
extern uint8  CCU6_MCM_Str_Int_Sts                       (void);
extern void   CCU6_T12_CM_CC60_Int_Rise_Set              (void);
extern void   CCU6_T12_CM_CC61_Int_Rise_Set              (void);
extern void   CCU6_T12_CM_CC62_Int_Rise_Set              (void);
extern void   CCU6_T12_CM_CC60_Int_Fall_Set              (void);
extern void   CCU6_T12_CM_CC61_Int_Fall_Set              (void);
extern void   CCU6_T12_CM_CC62_Int_Fall_Set              (void);
extern void   CCU6_T12_OM_Int_Set                        (void);
extern void   CCU6_T12_PM_Int_Set                        (void);
extern void   CCU6_T13_CM_Int_Set                        (void);
extern void   CCU6_T13_PM_Int_Set                        (void);
extern void   CCU6_Trap_Flag_Int_Set                     (void);
extern void   CCU6_Trap_SW_Hall_Int_Set                  (void);
extern void   CCU6_Hall_Correct_Int_Set                  (void);
extern void   CCU6_Hall_Wrong_Int_Set                    (void);
extern void   CCU6_MCM_Idle_Int_Set                      (void);
extern void   CCU6_MCM_Str_Int_Set                       (void);
extern void   CCU6_Ch0_Int_Node_Sel                      (uint16 srx);
extern void   CCU6_Ch1_Int_Node_Sel                      (uint16 srx);
extern void   CCU6_Ch2_Int_Node_Sel                      (uint16 srx);
extern void   CCU6_Error_Int_Node_Sel                    (uint16 srx);
extern void   CCU6_T12_Int_Node_Sel                      (uint16 srx);
extern void   CCU6_T13_Int_Node_Sel                      (uint16 srx);
extern void   CCU6_Hall_Correct_Int_Node_Sel             (uint16 srx);
extern void   CCU6_CH0_CM_R_Int_Clr                      (void);
extern void   CCU6_CH0_CM_F_Int_Clr                      (void);
extern void   CCU6_CH1_CM_R_Int_Clr                      (void);
extern void   CCU6_CH1_CM_F_Int_Clr                      (void);
extern void   CCU6_CH2_CM_R_Int_Clr                      (void);
extern void   CCU6_CH2_CM_F_Int_Clr                      (void);
extern void   CCU6_T12_OM_Int_Clr                        (void);
extern void   CCU6_T12_PM_Int_Clr                        (void);
extern void   CCU6_T13_CM_Int_Clr                        (void);
extern void   CCU6_T13_PM_Int_Clr                        (void);
extern void   CCU6_TRAP_Int_Clr                          (void);
extern void   CCU6_CHE_Int_Clr                           (void);
extern void   CCU6_WHE_Int_Clr                           (void);
extern void   CCU6_STR_Int_Clr                           (void);
extern void   CCU6_CH0_CM_R_Int_En                       (void);
extern void   CCU6_CH0_CM_R_Int_Dis                      (void);
extern void   CCU6_CH0_CM_F_Int_En                       (void);
extern void   CCU6_CH0_CM_F_Int_Dis                      (void);
extern void   CCU6_CH1_CM_R_Int_En                       (void);
extern void   CCU6_CH1_CM_R_Int_Dis                      (void);
extern void   CCU6_CH1_CM_F_Int_En                       (void);
extern void   CCU6_CH1_CM_F_Int_Dis                      (void);
extern void   CCU6_CH2_CM_R_Int_En                       (void);
extern void   CCU6_CH2_CM_R_Int_Dis                      (void);
extern void   CCU6_CH2_CM_F_Int_En                       (void);
extern void   CCU6_CH2_CM_F_Int_Dis                      (void);
extern void   CCU6_T12_OM_Int_En                         (void);
extern void   CCU6_T12_OM_Int_Dis                        (void);
extern void   CCU6_T12_PM_Int_En                         (void);
extern void   CCU6_T12_PM_Int_Dis                        (void);
extern void   CCU6_T13_CM_Int_En                         (void);
extern void   CCU6_T13_CM_Int_Dis                        (void);
extern void   CCU6_T13_PM_Int_En                         (void);
extern void   CCU6_T13_PM_Int_Dis                        (void);
extern void   CCU6_TRAP_Int_En                           (void);
extern void   CCU6_TRAP_Int_Dis                          (void);
extern void   CCU6_CHE_Int_En                            (void);
extern void   CCU6_CHE_Int_Dis                           (void);
extern void   CCU6_WHE_Int_En                            (void);
extern void   CCU6_WHE_Int_Dis                           (void);
extern void   CCU6_STR_Int_En                            (void);
extern void   CCU6_STR_Int_Dis                           (void);
extern void   CCU6_StartTmr_T12                          (void);
extern void   CCU6_StartTmr_T13                          (void);
extern void   CCU6_StopTmr_T12                           (void);
extern void   CCU6_StopTmr_T13                           (void);
extern void   CCU6_EnableST_T12                          (void);
extern void   CCU6_EnableST_T13                          (void);
extern void   CCU6_LoadShadowRegister_CC60               (uint16 tick);
extern void   CCU6_LoadShadowRegister_CC61               (uint16 tick);
extern void   CCU6_LoadShadowRegister_CC62               (uint16 tick);
extern void   CCU6_LoadShadowRegister_CC63               (uint16 tick);
extern void   CCU6_LoadPeriodRegister_T13_Time           (uint32 us);
extern void   CCU6_LoadPeriodRegister_T13_Tick           (uint16 tick);
extern bool   CCU6_IsT13Running                          (void);
extern void   CCU6_SetT13Trigger                         (uint16 Mask);
extern void   CCU6_SetT13Compare                         (uint16 Compare);
extern void   CCU6_SetT12T13ControlBits                  (uint16 Mask);
extern uint32 CCU6_ReadHallReg                           (void);
extern uint16 CCU6_ReadMultichannelPatterns              (void);
extern void   CCU6_WriteMultichannelPatterns             (uint16 Patterns);
extern void   CCU6_ConfigureMultichannelModulation       (uint16 Mode);
extern void   CCU6_ConfigureGlobalModulation             (uint16 Mode);
extern void   CCU6_EnableInt                             (uint16 Mask);
extern void   CCU6_ClearIntStatus                        (uint16 Mask);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

