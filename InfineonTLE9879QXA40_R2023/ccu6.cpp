/******************************************************************************/
/* File   : ccu6.cpp                                                          */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "types.hpp"

#include "ccu6.hpp"
#include "ccu6_defines.hpp"

#include "sfr_access.hpp"
#include "uC_Ccu6.hpp"

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
CCU6_Type CCU6 = {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0
};

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
void CCU6_Init(void){
   CCU6.TCTR0.reg = (uint16) CCU6_TCTR0;
   CCU6.T12PR.reg = (uint16) CCU6_T12PR;
   CCU6.T13PR.reg = (uint16) CCU6_T13PR;
   CCU6.T12DTC.reg = (uint16) CCU6_T12DTC;
   CCU6.CC60SR.reg = (uint16) CCU6_CC60SR;
   CCU6.CC61SR.reg = (uint16) CCU6_CC61SR;
   CCU6.CC62SR.reg = (uint16) CCU6_CC62SR;
   CCU6.CC63SR.reg = (uint16) CCU6_CC63SR;
   CCU6.TCTR2.reg = (uint16) CCU6_TCTR2;
   CCU6.TRPCTR.reg = (uint16) CCU6_TRPCTR;
   CCU6.MODCTR.reg = (uint16) CCU6_MODCTR;
   CCU6.MCMCTR.reg = (uint16) CCU6_MCMCTR;
   CCU6.T12MSEL.reg = (uint16) CCU6_T12MSEL;
   CCU6.PSLR.reg = (uint16) CCU6_PSLR;
   CCU6.INP.reg = (uint16) CCU6_INP;
   CCU6.IEN.reg = (uint16) CCU6_IEN;
   CCU6.CMPSTAT.reg = (uint16) CCU6_CMPSTAT;
   CCU6.PISEL0.reg = (uint16) CCU6_PISEL0;
   CCU6.PISEL2.reg = (uint16) CCU6_PISEL2;
   CCU6_T12_Str_En();
   CCU6_T13_Str_En();
}

void CCU6_T12_Stop(void){
  Field_Wrt16(&CCU6.TCTR4.reg, (uint16)CCU6_TCTR4_T12RR_Pos, (uint16)CCU6_TCTR4_T12RR_Msk, 1u);
}

void CCU6_T12_Start(void){
  Field_Wrt16(&CCU6.TCTR4.reg, (uint16)CCU6_TCTR4_T12RS_Pos, (uint16)CCU6_TCTR4_T12RS_Msk, 1u);
}
/*
void CCU6_T12_Rst(void){
  Field_Wrt16(&CCU6.TCTR4.reg, (uint16)CCU6_TCTR4_T12RES_Pos, (uint16)CCU6_TCTR4_T12RES_Msk, 1u);
}

void CCU6_Deadtime_Rst(void){
  Field_Wrt16(&CCU6.TCTR4.reg, (uint16)CCU6_TCTR4_DTRES_Pos, (uint16)CCU6_TCTR4_DTRES_Msk, 1u);
}

void CCU6_T12_Cnt(void){
  Field_Wrt16(&CCU6.TCTR4.reg, (uint16)CCU6_TCTR4_T12CNT_Pos, (uint16)CCU6_TCTR4_T12CNT_Msk, 1u);
}
*/
void CCU6_T12_Str_En(void){
  Field_Wrt16(&CCU6.TCTR4.reg, (uint16)CCU6_TCTR4_T12STR_Pos, (uint16)CCU6_TCTR4_T12STR_Msk, 1u);
}
/*
void CCU6_T12_Str_Dis(void){
  Field_Wrt16(&CCU6.TCTR4.reg, (uint16)CCU6_TCTR4_T12STD_Pos, (uint16)CCU6_TCTR4_T12STD_Msk, 1u);
}

void CCU6_T13_Stop(void){
  Field_Wrt16(&CCU6.TCTR4.reg, (uint16)CCU6_TCTR4_T13RR_Pos, (uint16)CCU6_TCTR4_T13RR_Msk, 1u);
}

void CCU6_T13_Start(void){
  Field_Wrt16(&CCU6.TCTR4.reg, (uint16)CCU6_TCTR4_T13RS_Pos, (uint16)CCU6_TCTR4_T13RS_Msk, 1u);
}

void CCU6_T13_Rst(void){
  Field_Wrt16(&CCU6.TCTR4.reg, (uint16)CCU6_TCTR4_T13RES_Pos, (uint16)CCU6_TCTR4_T13RES_Msk, 1u);
}

void CCU6_T13_Cnt(void){
  Field_Wrt16(&CCU6.TCTR4.reg, (uint16)CCU6_TCTR4_T13CNT_Pos, (uint16)CCU6_TCTR4_T13CNT_Msk, 1u);
}
*/
void CCU6_T13_Str_En(void){
  Field_Wrt16(&CCU6.TCTR4.reg, (uint16)CCU6_TCTR4_T13STR_Pos, (uint16)CCU6_TCTR4_T13STR_Msk, 1u);
}
/*
void CCU6_T13_Str_Dis(void){
  Field_Wrt16(&CCU6.TCTR4.reg, (uint16)CCU6_TCTR4_T13STD_Pos, (uint16)CCU6_TCTR4_T13STD_Msk, 1u);
}

void CCU6_Ch0_Input_Sel(uint16 iscc60){
  Field_Mod16(&CCU6.PISEL0.reg, (uint16)CCU6_PISEL0_ISCC60_Pos, (uint16)CCU6_PISEL0_ISCC60_Msk, iscc60);
}

void CCU6_Ch1_Input_Sel(uint16 iscc61){
  Field_Mod16(&CCU6.PISEL0.reg, (uint16)CCU6_PISEL0_ISCC61_Pos, (uint16)CCU6_PISEL0_ISCC61_Msk, iscc61);
}

void CCU6_Ch2_Input_Sel(uint16 iscc62){
  Field_Mod16(&CCU6.PISEL0.reg, (uint16)CCU6_PISEL0_ISCC62_Pos, (uint16)CCU6_PISEL0_ISCC62_Msk, iscc62);
}

void CCU6_Trap_Input_Sel(uint16 istrp){
  Field_Mod16(&CCU6.PISEL0.reg, (uint16)CCU6_PISEL0_ISTRP_Pos, (uint16)CCU6_PISEL0_ISTRP_Msk, istrp);
}

void CCU6_CCPOS0_Input_Sel(uint16 ispos0){
  Field_Mod16(&CCU6.PISEL0.reg, (uint16)CCU6_PISEL0_ISPOS0_Pos, (uint16)CCU6_PISEL0_ISPOS0_Msk, ispos0);
}

void CCU6_CCPOS1_Input_Sel(uint16 ispos1){
  Field_Mod16(&CCU6.PISEL0.reg, (uint16)CCU6_PISEL0_ISPOS1_Pos, (uint16)CCU6_PISEL0_ISPOS1_Msk, ispos1);
}

void CCU6_CCPOS2_Input_Sel(uint16 ispos2){
  Field_Mod16(&CCU6.PISEL0.reg, (uint16)CCU6_PISEL0_ISPOS2_Pos, (uint16)CCU6_PISEL0_ISPOS2_Msk, ispos2);
}

void CCU6_T12HR_Input_Sel(uint16 ist12hr){
  Field_Mod16(&CCU6.PISEL0.reg, (uint16)CCU6_PISEL0_IST12HR_Pos, (uint16)CCU6_PISEL0_IST12HR_Msk, ist12hr);
}

void CCU6_T13HR_Input_Sel(uint16 ist13hr){
  Field_Mod16(&CCU6.PISEL2.reg, (uint16)CCU6_PISEL2_IST13HR_Pos, (uint16)CCU6_PISEL2_IST13HR_Msk, ist13hr);
}

void CCU6_T12_Cnt_Input_Sel(uint16 iscnt12){
  Field_Mod16(&CCU6.PISEL2.reg, (uint16)CCU6_PISEL2_ISCNT12_Pos, (uint16)CCU6_PISEL2_ISCNT12_Msk, iscnt12);
}

void CCU6_T13_Cnt_Input_Sel(uint16 iscnt13){
  Field_Mod16(&CCU6.PISEL2.reg, (uint16)CCU6_PISEL2_ISCNT13_Pos, (uint16)CCU6_PISEL2_ISCNT13_Msk, iscnt13);
}

void CCU6_T12_Ext_Input_Sel(uint16 t12ext){
  Field_Mod16(&CCU6.PISEL2.reg, (uint16)CCU6_PISEL2_T12EXT_Pos, (uint16)CCU6_PISEL2_T12EXT_Msk, t12ext);
}

void CCU6_T13_Ext_Input_Sel(uint16 t13ext){
  Field_Mod16(&CCU6.PISEL2.reg, (uint16)CCU6_PISEL2_T13EXT_Pos, (uint16)CCU6_PISEL2_T13EXT_Msk, t13ext);
}

void CCU6_Hall_Delay_Bypass_En(void){
  Field_Mod16(&CCU6.T12MSEL.reg, (uint16)CCU6_T12MSEL_DBYP_Pos, (uint16)CCU6_T12MSEL_DBYP_Msk, 1u);
}

void CCU6_Hall_Delay_Bypass_Dis(void){
  Field_Mod16(&CCU6.T12MSEL.reg, (uint16)CCU6_T12MSEL_DBYP_Pos, (uint16)CCU6_T12MSEL_DBYP_Msk, 0u);
}

void CCU6_Hall_Synchronizaion_Sel(uint16 hsync){
  Field_Mod16(&CCU6.T12MSEL.reg, (uint16)CCU6_T12MSEL_HSYNC_Pos, (uint16)CCU6_T12MSEL_HSYNC_Msk, hsync);
}

void CCU6_Ch2_CapCom_Mode_Sel(uint16 msel62){
  Field_Mod16(&CCU6.T12MSEL.reg, (uint16)CCU6_T12MSEL_MSEL62_Pos, (uint16)CCU6_T12MSEL_MSEL62_Msk, msel62);
}

void CCU6_Ch1_CapCom_Mode_Sel(uint16 msel61){
  Field_Mod16(&CCU6.T12MSEL.reg, (uint16)CCU6_T12MSEL_MSEL61_Pos, (uint16)CCU6_T12MSEL_MSEL61_Msk, msel61);
}

void CCU6_Ch0_CapCom_Mode_Sel(uint16 msel60){
  Field_Mod16(&CCU6.T12MSEL.reg, (uint16)CCU6_T12MSEL_MSEL60_Pos, (uint16)CCU6_T12MSEL_MSEL60_Msk, msel60);
}

uint16 CCU6_T12_Count_Value_Get(void){
   return( u16_Field_Rd16(&CCU6.T12.reg, (uint16)CCU6_T12_T12CV_Pos, (uint16)CCU6_T12_T12CV_Msk) );
}

void CCU6_T12_Count_Value_Set(uint16 t12cv){
  Field_Wrt16(&CCU6.T12.reg, (uint16)CCU6_T12_T12CV_Pos, (uint16)CCU6_T12_T12CV_Msk, t12cv);
}

uint16 CCU6_T12_Period_Value_Get(void){
   return( u16_Field_Rd16(&CCU6.T12PR.reg, (uint16)CCU6_T12PR_T12PV_Pos, (uint16)CCU6_T12PR_T12PV_Msk) );
}

void CCU6_T12_Period_Value_Set(uint16 t12pr){
  Field_Wrt16(&CCU6.T12PR.reg, (uint16)CCU6_T12PR_T12PV_Pos, (uint16)CCU6_T12PR_T12PV_Msk, t12pr);
}

uint16 CCU6_Ch0_Value_Get(void){
   return( u16_Field_Rd16(&CCU6.CC60R.reg, (uint16)CCU6_CC60R_CCV_Pos, (uint16)CCU6_CC60R_CCV_Msk) );
}
*/
void CCU6_Ch0_Value_Set(uint16 cc60sr){
  Field_Wrt16(&CCU6.CC60SR.reg, (uint16)CCU6_CC60R_CCV_Pos, (uint16)CCU6_CC60R_CCV_Msk, cc60sr);
}
/*
uint16 CCU6_Ch1_Value_Get(void){
   return( u16_Field_Rd16(&CCU6.CC61R.reg, (uint16)CCU6_CC61R_CCV_Pos, (uint16)CCU6_CC61R_CCV_Msk) );
}
*/
void CCU6_Ch1_Value_Set(uint16 cc61sr){
  Field_Wrt16(&CCU6.CC61SR.reg, (uint16)CCU6_CC61R_CCV_Pos, (uint16)CCU6_CC61R_CCV_Msk, cc61sr);
}
/*
uint16 CCU6_Ch2_Value_Get(void){
   return( u16_Field_Rd16(&CCU6.CC62R.reg, (uint16)CCU6_CC62R_CCV_Pos, (uint16)CCU6_CC62R_CCV_Msk) );
}
*/
void CCU6_Ch2_Value_Set(uint16 cc62sr){
  Field_Wrt16(&CCU6.CC62SR.reg, (uint16)CCU6_CC62R_CCV_Pos, (uint16)CCU6_CC62R_CCV_Msk, cc62sr);
}
/*
uint8 CCU6_Deadtime_Get(void){
   return( u8_Field_Rd16(&CCU6.T12DTC.reg, (uint16)CCU6_T12DTC_DTM_Pos, (uint16)CCU6_T12DTC_DTM_Msk) );
}

void CCU6_Deadtime_Set(uint16 dtm){
  Field_Mod16(&CCU6.T12DTC.reg, (uint16)CCU6_T12DTC_DTM_Pos, (uint16)CCU6_T12DTC_DTM_Msk, dtm);
}

void CCU6_Ch0_Deadtime_En(void){
  Field_Mod16(&CCU6.T12DTC.reg, (uint16)CCU6_T12DTC_DTE0_Pos, (uint16)CCU6_T12DTC_DTE0_Msk, 1u);
}

void CCU6_Ch1_Deadtime_En(void){
  Field_Mod16(&CCU6.T12DTC.reg, (uint16)CCU6_T12DTC_DTE1_Pos, (uint16)CCU6_T12DTC_DTE1_Msk, 1u);
}

void CCU6_Ch2_Deadtime_En(void){
  Field_Mod16(&CCU6.T12DTC.reg, (uint16)CCU6_T12DTC_DTE2_Pos, (uint16)CCU6_T12DTC_DTE2_Msk, 1u);
}

void CCU6_Ch0_Deadtime_Dis(void){
  Field_Mod16(&CCU6.T12DTC.reg, (uint16)CCU6_T12DTC_DTE0_Pos, (uint16)CCU6_T12DTC_DTE0_Msk, 0u);
}

void CCU6_Ch1_Deadtime_Dis(void){
  Field_Mod16(&CCU6.T12DTC.reg, (uint16)CCU6_T12DTC_DTE1_Pos, (uint16)CCU6_T12DTC_DTE1_Msk, 0u);
}

void CCU6_Ch2_Deadtime_Dis(void){
  Field_Mod16(&CCU6.T12DTC.reg, (uint16)CCU6_T12DTC_DTE2_Pos, (uint16)CCU6_T12DTC_DTE2_Msk, 0u);
}

uint8 CCU6_Ch0_Deadtime_Sts(void){
   return( u1_Field_Rd16(&CCU6.T12DTC.reg, (uint8)CCU6_T12DTC_DTR0_Pos, (uint16)CCU6_T12DTC_DTR0_Msk) );
}

uint8 CCU6_Ch1_Deadtime_Sts(void){
   return( u1_Field_Rd16(&CCU6.T12DTC.reg, (uint16)CCU6_T12DTC_DTR1_Pos, (uint16)CCU6_T12DTC_DTR1_Msk) );
}

uint8 CCU6_Ch2_Deadtime_Sts(void){
   return( u1_Field_Rd16(&CCU6.T12DTC.reg, (uint16)CCU6_T12DTC_DTR2_Pos, (uint16)CCU6_T12DTC_DTR2_Msk) );
}

uint16 CCU6_T13_Count_Value_Get(void){
   return( u16_Field_Rd16(&CCU6.T13.reg, (uint16)CCU6_T13_T13CV_Pos, (uint16)CCU6_T13_T13CV_Msk) );
}

void CCU6_T13_Count_Value_Set(uint16 t13cv){
  Field_Wrt16(&CCU6.T13.reg, (uint16)CCU6_T13_T13CV_Pos, (uint16)CCU6_T13_T13CV_Msk, t13cv);
}
*/
uint16 CCU6_T13_Period_Value_Get(void){
   return( u16_Field_Rd16(&CCU6.T13PR.reg, (uint16)CCU6_T13PR_T13PV_Pos, (uint16)CCU6_T13PR_T13PV_Msk) );
}

void CCU6_T13_Period_Value_Set(uint16 t13pr){
  Field_Wrt16(&CCU6.T13PR.reg, (uint16)CCU6_T13PR_T13PV_Pos, (uint16)CCU6_T13PR_T13PV_Msk, t13pr);
}

/*
uint16 CCU6_Ch3_Value_Get(void){
   return( u16_Field_Rd16(&CCU6.CC63R.reg, (uint16)CCU6_CC63R_CCV_Pos, (uint16)CCU6_CC63R_CCV_Msk) );
}
*/
void CCU6_Ch3_Value_Set(uint16 cc63sr){
  Field_Wrt16(&CCU6.CC63SR.reg, (uint16)CCU6_CC63R_CCV_Pos, (uint16)CCU6_CC63R_CCV_Msk, cc63sr);
}
/*
uint8 CCU6_Ch0_CompState_Sts(void){
   return( u1_Field_Rd16(&CCU6.CMPSTAT.reg, (uint16)CCU6_CMPSTAT_CC60ST_Pos, (uint16)CCU6_CMPSTAT_CC60ST_Msk) );
}

uint8 CCU6_Ch1_CompState_Sts(void){
   return( u1_Field_Rd16(&CCU6.CMPSTAT.reg, (uint16)CCU6_CMPSTAT_CC61ST_Pos, (uint16)CCU6_CMPSTAT_CC61ST_Msk) );
}

uint8 CCU6_Ch2_CompState_Sts(void){
   return( u1_Field_Rd16(&CCU6.CMPSTAT.reg, (uint16)CCU6_CMPSTAT_CC62ST_Pos, (uint16)CCU6_CMPSTAT_CC62ST_Msk) );
}

uint8 CCU6_Ch3_CompState_Sts(void){
   return( u1_Field_Rd16(&CCU6.CMPSTAT.reg, (uint16)CCU6_CMPSTAT_CC63ST_Pos, (uint16)CCU6_CMPSTAT_CC63ST_Msk) );
}

uint8 CCU6_Hall_Ch0_Sts(void){
   return( u1_Field_Rd16(&CCU6.CMPSTAT.reg, (uint16)CCU6_CMPSTAT_CCPOS0_Pos, (uint16)CCU6_CMPSTAT_CCPOS0_Msk) );
}

uint8 CCU6_Hall_Ch1_Sts(void){
   return( u1_Field_Rd16(&CCU6.CMPSTAT.reg, (uint16)CCU6_CMPSTAT_CCPOS1_Pos, (uint16)CCU6_CMPSTAT_CCPOS1_Msk) );
}

uint8 CCU6_Hall_Ch2_Sts(void){
   return( u1_Field_Rd16(&CCU6.CMPSTAT.reg, (uint16)CCU6_CMPSTAT_CCPOS2_Pos, (uint16)CCU6_CMPSTAT_CCPOS2_Msk) );
}

void CCU6_T12_PWMMode_Set(TCCU6_PWMMode mode){
  Field_Mod16(&CCU6.CMPSTAT.reg, (uint16)CCU6_CMPSTAT_CC60PS_Pos, (uint16)0x3F00, (uint16_t)mode);
  CCU6_T12_Str_En();
}

void CCU6_Ch3c_Passive_State_After_Compare_Set(void){
  Field_Mod16(&CCU6.CMPSTAT.reg, (uint16)CCU6_CMPSTAT_COUT63PS_Pos, (uint16)CCU6_CMPSTAT_COUT63PS_Msk, 1u);
  CCU6_T13_Str_En();
}

void CCU6_Ch3c_Passive_State_Before_Compare_Set(void){
  Field_Mod16(&CCU6.CMPSTAT.reg, (uint16)CCU6_CMPSTAT_COUT63PS_Pos, (uint16)CCU6_CMPSTAT_COUT63PS_Msk, 0u);
  CCU6_T13_Str_En();
}

void CCU6_T13_Inv_Mod_En(void){
  Field_Mod16(&CCU6.CMPSTAT.reg, (uint16)CCU6_CMPSTAT_T13IM_Pos, (uint16)CCU6_CMPSTAT_T13IM_Msk, 1u);
  CCU6_T13_Str_En();
}

void CCU6_T13_Inv_Mod_Dis(void){
  Field_Mod16(&CCU6.CMPSTAT.reg, (uint16)CCU6_CMPSTAT_T13IM_Pos, (uint16)CCU6_CMPSTAT_T13IM_Msk, 0u);
  CCU6_T13_Str_En();
}

void CCU6_Ch0_CompState_Set(void){
  Field_Wrt16(&CCU6.CMPMODIF.reg, (uint16)CCU6_CMPMODIF_MCC60S_Pos, (uint16)CCU6_CMPMODIF_MCC60S_Msk, 1u);
}

void CCU6_Ch1_CompState_Set(void){
  Field_Wrt16(&CCU6.CMPMODIF.reg, (uint16)CCU6_CMPMODIF_MCC61S_Pos, (uint16)CCU6_CMPMODIF_MCC61S_Msk, 1u);
}

void CCU6_Ch2_CompState_Set(void){
  Field_Wrt16(&CCU6.CMPMODIF.reg, (uint16)CCU6_CMPMODIF_MCC62S_Pos, (uint16)CCU6_CMPMODIF_MCC62S_Msk, 1u);
}

void CCU6_Ch3_CompState_Set(void){
  Field_Wrt16(&CCU6.CMPMODIF.reg, (uint16)CCU6_CMPMODIF_MCC63S_Pos, (uint16)CCU6_CMPMODIF_MCC63S_Msk, 1u);
}

void CCU6_Ch0_CompState_Rst(void){
  Field_Wrt16(&CCU6.CMPMODIF.reg, (uint16)CCU6_CMPMODIF_MCC60R_Pos, (uint16)CCU6_CMPMODIF_MCC60R_Msk, 1u);
}

void CCU6_Ch1_CompState_Rst(void){
  Field_Wrt16(&CCU6.CMPMODIF.reg, (uint16)CCU6_CMPMODIF_MCC61R_Pos, (uint16)CCU6_CMPMODIF_MCC61R_Msk, 1u);
}

void CCU6_Ch2_CompState_Rst(void){
  Field_Wrt16(&CCU6.CMPMODIF.reg, (uint16)CCU6_CMPMODIF_MCC62R_Pos, (uint16)CCU6_CMPMODIF_MCC62R_Msk, 1u);
}

void CCU6_Ch3_CompState_Rst(void){
  Field_Wrt16(&CCU6.CMPMODIF.reg, (uint16)CCU6_CMPMODIF_MCC63R_Pos, (uint16)CCU6_CMPMODIF_MCC63R_Msk, 1u);
}

void CCU6_T12_Edge_Aligned_Mode_En(void){
  Field_Mod16(&CCU6.TCTR0.reg, (uint16)CCU6_TCTR0_CTM_Pos, (uint16)CCU6_TCTR0_CTM_Msk, 0u);
}

void CCU6_T12_Center_Aligned_Mode_En(void){
  Field_Mod16(&CCU6.TCTR0.reg, (uint16)CCU6_TCTR0_CTM_Pos, (uint16)CCU6_TCTR0_CTM_Msk, 1u);
}

void CCU6_T12_Clk_Sel(uint16 t12clk){
  Field_Mod16(&CCU6.TCTR0.reg, (uint16)CCU6_TCTR0_T12CLK_Pos, (uint16)CCU6_TCTR0_T12CLK_Msk, t12clk);
}

void CCU6_T13_Clk_Sel(uint16 t13clk){
  Field_Mod16(&CCU6.TCTR0.reg, (uint16)CCU6_TCTR0_T13CLK_Pos, (uint16)CCU6_TCTR0_T13CLK_Msk, t13clk);
}

void CCU6_T12_Prescaler_En(void){
  Field_Mod16(&CCU6.TCTR0.reg, (uint16)CCU6_TCTR0_T12PRE_Pos, (uint16)CCU6_TCTR0_T12PRE_Msk, 1u);
}

void CCU6_T12_Prescaler_Dis(void){
  Field_Mod16(&CCU6.TCTR0.reg, (uint16)CCU6_TCTR0_T12PRE_Pos, (uint16)CCU6_TCTR0_T12PRE_Msk, 0u);
}

void CCU6_T13_Prescaler_En(void){
  Field_Mod16(&CCU6.TCTR0.reg, (uint16)CCU6_TCTR0_T13PRE_Pos, (uint16)CCU6_TCTR0_T13PRE_Msk, 1u);
}

void CCU6_T13_Prescaler_Dis(void){
  Field_Mod16(&CCU6.TCTR0.reg, (uint16)CCU6_TCTR0_T13PRE_Pos, (uint16)CCU6_TCTR0_T13PRE_Msk, 0u);
}

uint8 CCU6_T12_Run_Sts(void){
   return( u1_Field_Rd16(&CCU6.TCTR0.reg, (uint16)CCU6_TCTR0_T12R_Pos, (uint16)CCU6_TCTR0_T12R_Msk) );
}

uint8 CCU6_T12_Str_Sts(void){
   return( u1_Field_Rd16(&CCU6.TCTR0.reg, (uint16)CCU6_TCTR0_STE12_Pos, (uint16)CCU6_TCTR0_STE12_Msk) );
}

uint8 CCU6_T12_Count_Dir_Sts(void){
   return( u1_Field_Rd16(&CCU6.TCTR0.reg, (uint16)CCU6_TCTR0_CDIR_Pos, (uint16)CCU6_TCTR0_CDIR_Msk) );
}

uint8 CCU6_T13_Run_Sts(void){
   return( u1_Field_Rd16(&CCU6.TCTR0.reg, (uint16)CCU6_TCTR0_T13R_Pos, (uint16)CCU6_TCTR0_T13R_Msk) );
}

uint8 CCU6_T13_Str_Sts(void){
   return( u1_Field_Rd16(&CCU6.TCTR0.reg, (uint16)CCU6_TCTR0_STE13_Pos, (uint16)CCU6_TCTR0_STE13_Msk) );
}

void CCU6_T12_Single_Shot_En(void){
  Field_Mod16(&CCU6.TCTR2.reg, (uint16)CCU6_TCTR2_T12SSC_Pos, (uint16)CCU6_TCTR2_T12SSC_Msk, 1u);
}

void CCU6_T12_Single_Shot_Dis(void){
  Field_Mod16(&CCU6.TCTR2.reg, (uint16)CCU6_TCTR2_T12SSC_Pos, (uint16)CCU6_TCTR2_T12SSC_Msk, 0u);
}

void CCU6_T13_Trig_Event_Sel(uint16 t13tec){
  Field_Mod16(&CCU6.TCTR2.reg, (uint16)CCU6_TCTR2_T13TEC_Pos, (uint16)CCU6_TCTR2_T13TEC_Msk, t13tec);
}

void CCU6_T13_Trig_Event_Dir_Sel(uint16 t13ted){
  Field_Mod16(&CCU6.TCTR2.reg, (uint16)CCU6_TCTR2_T13TED_Pos, (uint16)CCU6_TCTR2_T13TED_Msk, t13ted);
}

void CCU6_T12_Ext_Run_Sel(uint16 t12rsel){
  Field_Mod16(&CCU6.TCTR2.reg, (uint16)CCU6_TCTR2_T12RSEL_Pos, (uint16)CCU6_TCTR2_T12RSEL_Msk, t12rsel);
}

void CCU6_T13_Ext_Run_Sel(uint16 t13rsel){
  Field_Mod16(&CCU6.TCTR2.reg, (uint16)CCU6_TCTR2_T13RSEL_Pos, (uint16)CCU6_TCTR2_T13RSEL_Msk, t13rsel);
}

void CCU6_T12_Modulation_En(uint16 ccu6_mask){
  Field_Mod16(&CCU6.MODCTR.reg, (uint16)CCU6_MODCTR_T12MODEN_Pos, (uint16)CCU6_MODCTR_T12MODEN_Msk, (ccu6_mask));
}

void CCU6_T12_Modulation_Dis(uint16 ccu6_mask){
  Field_Mod16(&CCU6.MODCTR.reg, (uint16)CCU6_MODCTR_T12MODEN_Pos, (uint16)((ccu6_mask << (uint16)CCU6_MODCTR_T12MODEN_Pos) & (uint16)CCU6_MODCTR_T12MODEN_Msk), 0);
}

void CCU6_T13_Modulation_En(uint16 ccu6_mask){
  Field_Mod16(&CCU6.MODCTR.reg, (uint16)CCU6_MODCTR_T13MODEN_Pos, (uint16)CCU6_MODCTR_T13MODEN_Msk, (ccu6_mask));
}

void CCU6_T13_Modulation_Dis(uint16 ccu6_mask){
  Field_Mod16(&CCU6.MODCTR.reg, (uint16)CCU6_MODCTR_T13MODEN_Pos, (uint16)((ccu6_mask << (uint16)CCU6_MODCTR_T13MODEN_Pos) & (uint16)CCU6_MODCTR_T13MODEN_Msk), 0);
}

void CCU6_Multi_Ch_Mode_En(void){
  Field_Mod16(&CCU6.MODCTR.reg, (uint16)CCU6_MODCTR_MCMEN_Pos, (uint16)CCU6_MODCTR_MCMEN_Msk, 1u);
}

void CCU6_Multi_Ch_Mode_Dis(void){
  Field_Mod16(&CCU6.MODCTR.reg, (uint16)CCU6_MODCTR_MCMEN_Pos, (uint16)CCU6_MODCTR_MCMEN_Msk, 0u);
}

void CCU6_T13_Compare_Out_En(void){
  Field_Mod16(&CCU6.MODCTR.reg, (uint16)CCU6_MODCTR_ECT13O_Pos, (uint16)CCU6_MODCTR_ECT13O_Msk, 1u);
}

void CCU6_T13_Compare_Out_Dis(void){
  Field_Mod16(&CCU6.MODCTR.reg, (uint16)CCU6_MODCTR_ECT13O_Pos, (uint16)CCU6_MODCTR_ECT13O_Msk, 0u);
}

void CCU6_Trap_T12_ZM_Exit_En(void){
  Field_Mod16(&CCU6.TRPCTR.reg, (uint16)CCU6_TRPCTR_TRPM0_Pos, (uint16)(CCU6_TRPCTR_TRPM0_Msk | CCU6_TRPCTR_TRPM1_Msk), 0u);
}

void CCU6_Trap_T13_ZM_Exit_En(void){
  Field_Mod16(&CCU6.TRPCTR.reg, (uint16)CCU6_TRPCTR_TRPM0_Pos, (uint16)(CCU6_TRPCTR_TRPM0_Msk | CCU6_TRPCTR_TRPM1_Msk), 1u);
}

void CCU6_Trap_Asynch_Exit_En(void){
  Field_Mod16(&CCU6.TRPCTR.reg, (uint16)CCU6_TRPCTR_TRPM0_Pos, (uint16)(CCU6_TRPCTR_TRPM0_Msk | CCU6_TRPCTR_TRPM1_Msk), 3u);
}

void CCU6_Trap_HW_Clr_En(void){
  Field_Mod16(&CCU6.TRPCTR.reg, (uint16)CCU6_TRPCTR_TRPM2_Pos, (uint16)CCU6_TRPCTR_TRPM2_Msk, 0u);
}

void CCU6_Trap_SW_Clr_En(void){
  Field_Mod16(&CCU6.TRPCTR.reg, (uint16)CCU6_TRPCTR_TRPM2_Pos, (uint16)CCU6_TRPCTR_TRPM2_Msk, 1u);
}

void CCU6_Trap_T13_En(void){
  Field_Mod16(&CCU6.TRPCTR.reg, (uint16)CCU6_TRPCTR_TRPEN13_Pos, (uint16)CCU6_TRPCTR_TRPEN13_Msk, 1u);
}

void CCU6_Trap_T13_Dis(void){
  Field_Mod16(&CCU6.TRPCTR.reg, (uint16)CCU6_TRPCTR_TRPEN13_Pos, (uint16)CCU6_TRPCTR_TRPEN13_Msk, 0u);
}

void CCU6_Trap_Pin_En(void){
  Field_Mod16(&CCU6.TRPCTR.reg, (uint16)CCU6_TRPCTR_TRPPEN_Pos, (uint16)CCU6_TRPCTR_TRPPEN_Msk, 1u);
}

void CCU6_Trap_Pin_Dis(void){
  Field_Mod16(&CCU6.TRPCTR.reg, (uint16)CCU6_TRPCTR_TRPPEN_Pos, (uint16)CCU6_TRPCTR_TRPPEN_Msk, 0u);
}

void CCU6_Trap_Channel_En(uint16 ccu6_mask){
  Field_Mod16(&CCU6.TRPCTR.reg, (uint16)CCU6_TRPCTR_TRPEN_Pos, (uint16)CCU6_TRPCTR_TRPEN_Msk, ccu6_mask);
}

void CCU6_Passive_State_After_Compare_Sel(uint16 ccu6_mask){
  Field_Mod16(&CCU6.CMPSTAT.reg, (uint16)CCU6_CMPSTAT_CC60PS_Pos, (uint16)0x3F00, ccu6_mask);
  CCU6_T12_Str_En();
}

void CCU6_Ch0t_Passive_Level_High_Set(void){
  Field_Mod16(&CCU6.PSLR.reg, 0u, 0x01u, 1u);
}

void CCU6_Ch0t_Passive_Level_Low_Set(void){
  Field_Mod16(&CCU6.PSLR.reg, 0u, 0x01u, 0u);
}

void CCU6_Ch0c_Passive_Level_High_Set(void){
  Field_Mod16(&CCU6.PSLR.reg, 1u, 0x02u, 1u);
}

void CCU6_Ch0c_Passive_Level_Low_Set(void){
  Field_Mod16(&CCU6.PSLR.reg, 1u, 0x02u, 0u);
}

void CCU6_Ch1t_Passive_Level_High_Set(void){
  Field_Mod16(&CCU6.PSLR.reg, 2u, 0x04u, 1u);
}

void CCU6_Ch1t_Passive_Level_Low_Set(void){
  Field_Mod16(&CCU6.PSLR.reg, 2u, 0x04u, 0u);
}

void CCU6_Ch1c_Passive_Level_High_Set(void){
  Field_Mod16(&CCU6.PSLR.reg, 3u, 0x08u, 1u);
}

void CCU6_Ch1c_Passive_Level_Low_Set(void){
  Field_Mod16(&CCU6.PSLR.reg, 3u, 0x08u, 0u);
}

void CCU6_Ch2t_Passive_Level_High_Set(void){
  Field_Mod16(&CCU6.PSLR.reg, 4u, 0x10u, 1u);
}

void CCU6_Ch2t_Passive_Level_Low_Set(void){
  Field_Mod16(&CCU6.PSLR.reg, 4u, 0x10u, 0u);
}

void CCU6_Ch2c_Passive_Level_High_Set(void){
  Field_Mod16(&CCU6.PSLR.reg, 5u, 0x20u, 1u);
}

void CCU6_Ch2c_Passive_Level_Low_Set(void){
  Field_Mod16(&CCU6.PSLR.reg, 5u, 0x20u, 0u);
}

void CCU6_Passive_Level_High_Sel(uint16 ccu6_mask){
  Field_Mod16(&CCU6.PSLR.reg, (uint16)CCU6_PSLR_PSL_Pos, (uint16)CCU6_PSLR_PSL_Msk, ccu6_mask);
}

void CCU6_Passiv_Level_Ch3_Sel(uint16 lvl){
  Field_Mod16(&CCU6.PSLR.reg, (uint16)CCU6_PSLR_PSL63_Pos, (uint16)CCU6_PSLR_PSL63_Msk, lvl);
}
*/
void CCU6_Multi_Ch_PWM_Shadow_Reg_Load(uint16 ccu6_mask){
  Field_Mod16(&CCU6.MCMOUTS.reg, (uint16)CCU6_MCMOUTS_MCMPS_Pos, (uint16)CCU6_MCMOUTS_MCMPS_Msk, ccu6_mask);
}

void CCU6_MCM_PWM_Str_SW_En(void){
  Field_Mod16(&CCU6.MCMOUTS.reg, (uint16)CCU6_MCMOUTS_STRMCM_Pos, (uint16)CCU6_MCMOUTS_STRMCM_Msk, 1u);
}
/*
void CCU6_MCM_PWM_Str_HW_En(void){
  Field_Mod16(&CCU6.MCMOUTS.reg, (uint16)CCU6_MCMOUTS_STRMCM_Pos, (uint16)CCU6_MCMOUTS_STRMCM_Msk, 0u);
}

void CCU6_MCM_Expected_Hall_Shadow_Reg_Load(uint16 mcm_mask_ccpos){
  Field_Mod16(&CCU6.MCMOUTS.reg, (uint16)CCU6_MCMOUTS_EXPHS_Pos, (uint16)CCU6_MCMOUTS_EXPHS_Msk, mcm_mask_ccpos);
}

void CCU6_MCM_Current_Hall_Shadow_Reg_Load(uint16 mcm_mask_ccpos){
  Field_Mod16(&CCU6.MCMOUTS.reg, (uint16)CCU6_MCMOUTS_CURHS_Pos, (uint16)CCU6_MCMOUTS_CURHS_Msk, mcm_mask_ccpos);
}

void CCU6_MCM_Hall_Str_SW_En(void){
  Field_Mod16(&CCU6.MCMOUTS.reg, (uint16)CCU6_MCMOUTS_STRHP_Pos, (uint16)CCU6_MCMOUTS_STRHP_Msk, 1u);
}

void CCU6_MCM_Hall_Str_HW_En(void){
  Field_Mod16(&CCU6.MCMOUTS.reg, (uint16)CCU6_MCMOUTS_STRHP_Pos, (uint16)CCU6_MCMOUTS_STRHP_Msk, 0u);
}

uint8 CCU6_MCM_PWM_Pattern_Sts(void){
   return( u8_Field_Rd16(&CCU6.MCMOUT.reg, (uint16)CCU6_MCMOUT_MCMP_Pos, (uint16)CCU6_MCMOUT_MCMP_Msk) );
}

uint8 CCU6_MCM_PWM_Str_Req_Sts(void){
   return( u8_Field_Rd16(&CCU6.MCMOUT.reg, (uint16)CCU6_MCMOUT_R_Pos, (uint16)CCU6_MCMOUT_R_Msk) );
}

uint8 CCU6_MCM_Expected_Hall_Sts(void){
   return( u8_Field_Rd16(&CCU6.MCMOUT.reg, (uint16)CCU6_MCMOUT_EXPH_Pos, (uint16)CCU6_MCMOUT_EXPH_Msk) );
}

uint8 CCU6_MCM_Current_Hall_Sts(void){
   return( u8_Field_Rd16(&CCU6.MCMOUT.reg, (uint16)CCU6_MCMOUT_CURH_Pos, (uint16)CCU6_MCMOUT_CURH_Msk) );
}

void CCU6_MCM_Switch_Sel(uint16 swsel){
  Field_Mod16(&CCU6.MCMCTR.reg, (uint16)CCU6_MCMCTR_SWSEL_Pos, (uint16)CCU6_MCMCTR_SWSEL_Msk, swsel);
}

void CCU6_MCM_Switch_NoTrigger_Set(void){
  Field_Mod16(&CCU6.MCMCTR.reg, (uint16)CCU6_MCMCTR_SWSEL_Pos, (uint16)CCU6_MCMCTR_SWSEL_Msk, 0u);
}

void CCU6_MCM_Switch_CorrectHall_Set(void){
  Field_Mod16(&CCU6.MCMCTR.reg, (uint16)CCU6_MCMCTR_SWSEL_Pos, (uint16)CCU6_MCMCTR_SWSEL_Msk, 1u);
}

void CCU6_MCM_Switch_T13_PM_Set(void){
  Field_Mod16(&CCU6.MCMCTR.reg, (uint16)CCU6_MCMCTR_SWSEL_Pos, (uint16)CCU6_MCMCTR_SWSEL_Msk, 2u);
}

void CCU6_MCM_Switch_T12_ON_Set(void){
  Field_Mod16(&CCU6.MCMCTR.reg, (uint16)CCU6_MCMCTR_SWSEL_Pos, (uint16)CCU6_MCMCTR_SWSEL_Msk, 3u);
}

void CCU6_MCM_Switch_T12_Ch1_CM_Set(void){
  Field_Mod16(&CCU6.MCMCTR.reg, (uint16)CCU6_MCMCTR_SWSEL_Pos, (uint16)CCU6_MCMCTR_SWSEL_Msk, 4u);
}

void CCU6_MCM_Switch_T12_PM_Set(void){
  Field_Mod16(&CCU6.MCMCTR.reg, (uint16)CCU6_MCMCTR_SWSEL_Pos, (uint16)CCU6_MCMCTR_SWSEL_Msk, 5u);
}

void CCU6_MCM_Switch_Sync_direct_Sel(void){
  Field_Mod16(&CCU6.MCMCTR.reg, (uint16)CCU6_MCMCTR_SWSYN_Pos, (uint16)CCU6_MCMCTR_SWSYN_Msk, 0u);
}

void CCU6_MCM_Switch_Sync_T13_ZM_Sel(void){
  Field_Mod16(&CCU6.MCMCTR.reg, (uint16)CCU6_MCMCTR_SWSYN_Pos, (uint16)CCU6_MCMCTR_SWSYN_Msk, 1u);
}

void CCU6_MCM_Switch_Sync_T12_ZM_Sel(void){
  Field_Mod16(&CCU6.MCMCTR.reg, (uint16)CCU6_MCMCTR_SWSYN_Pos, (uint16)CCU6_MCMCTR_SWSYN_Msk, 2u);
}

void CCU6_MCM_Str_T12_Up_Cnt_En(void){
  Field_Mod16(&CCU6.MCMCTR.reg, (uint16)CCU6_MCMCTR_STE12U_Pos, (uint16)CCU6_MCMCTR_STE12U_Msk, 1u);
}

void CCU6_MCM_Str_T12_Up_Cnt_Dis(void){
  Field_Mod16(&CCU6.MCMCTR.reg, (uint16)CCU6_MCMCTR_STE12U_Pos, (uint16)CCU6_MCMCTR_STE12U_Msk, 0u);
}

void CCU6_MCM_Str_T12_Down_Cnt_En(void){
  Field_Mod16(&CCU6.MCMCTR.reg, (uint16)CCU6_MCMCTR_STE12D_Pos, (uint16)CCU6_MCMCTR_STE12D_Msk, 1u);
}

void CCU6_MCM_Str_T12_Down_Cnt_Dis(void){
  Field_Mod16(&CCU6.MCMCTR.reg, (uint16)CCU6_MCMCTR_STE12D_Pos, (uint16)CCU6_MCMCTR_STE12D_Msk, 0u);
}

void CCU6_MCM_Str_T13_Up_Cnt_En(void){
  Field_Mod16(&CCU6.MCMCTR.reg, (uint16)CCU6_MCMCTR_STE13U_Pos, (uint16)CCU6_MCMCTR_STE13U_Msk, 1u);
}

void CCU6_MCM_Str_T13_Up_Cnt_Dis(void){
  Field_Mod16(&CCU6.MCMCTR.reg, (uint16)CCU6_MCMCTR_STE13U_Pos, (uint16)CCU6_MCMCTR_STE13U_Msk, 0u);
}

uint8 CCU6_T12_CM_CC60_Int_Rise_Sts(void){
   return( u1_Field_Rd16(&CCU6.IS.reg, (uint16)CCU6_IS_ICC60R_Pos, (uint16)CCU6_IS_ICC60R_Msk) );
}

uint8 CCU6_T12_CM_CC61_Int_Rise_Sts(void){
   return( u1_Field_Rd16(&CCU6.IS.reg, (uint16)CCU6_IS_ICC61R_Pos, (uint16)CCU6_IS_ICC61R_Msk) );
}

uint8 CCU6_T12_CM_CC62_Int_Rise_Sts(void){
   return( u1_Field_Rd16(&CCU6.IS.reg, (uint16)CCU6_IS_ICC62R_Pos, (uint16)CCU6_IS_ICC62R_Msk) );
}

uint8 CCU6_T12_CM_CC60_Int_Fall_Sts(void){
   return( u1_Field_Rd16(&CCU6.IS.reg, (uint16)CCU6_IS_ICC60F_Pos, (uint16)CCU6_IS_ICC60F_Msk) );
}

uint8 CCU6_T12_CM_CC61_Int_Fall_Sts(void){
   return( u1_Field_Rd16(&CCU6.IS.reg, (uint16)CCU6_IS_ICC61F_Pos, (uint16)CCU6_IS_ICC61F_Msk) );
}

uint8 CCU6_T12_CM_CC62_Int_Fall_Sts(void){
   return( u1_Field_Rd16(&CCU6.IS.reg, (uint16)CCU6_IS_ICC62F_Pos, (uint16)CCU6_IS_ICC62F_Msk) );
}

uint8 CCU6_T12_OM_Int_Sts(void){
   return( u1_Field_Rd16(&CCU6.IS.reg, (uint16)CCU6_IS_T12OM_Pos, (uint16)CCU6_IS_T12OM_Msk) );
}

uint8 CCU6_T12_PM_Int_Sts(void){
   return( u1_Field_Rd16(&CCU6.IS.reg, (uint16)CCU6_IS_T12PM_Pos, (uint16)CCU6_IS_T12PM_Msk) );
}

uint8 CCU6_T13_CM_Int_Sts(void){
   return( u1_Field_Rd16(&CCU6.IS.reg, (uint16)CCU6_IS_T13CM_Pos, (uint16)CCU6_IS_T13CM_Msk) );
}

uint8 CCU6_T13_PM_Int_Sts(void){
   return( u1_Field_Rd16(&CCU6.IS.reg, (uint16)CCU6_IS_T13PM_Pos, (uint16)CCU6_IS_T13PM_Msk) );
}

uint8 CCU6_Trap_Flag_Int_Sts(void){
   return( u1_Field_Rd16(&CCU6.IS.reg, (uint16)CCU6_IS_TRPF_Pos, (uint16)CCU6_IS_TRPF_Msk) );
}

uint8 CCU6_Trap_State_Int_Sts(void){
   return( u1_Field_Rd16(&CCU6.IS.reg, (uint16)CCU6_IS_TRPS_Pos, (uint16)CCU6_IS_TRPS_Msk) );
}

uint8 CCU6_Hall_Correct_Int_Sts(void){
   return( u1_Field_Rd16(&CCU6.IS.reg, (uint16)CCU6_IS_CHE_Pos, (uint16)CCU6_IS_CHE_Msk) );
}

uint8 CCU6_Hall_Wrong_Int_Sts(void){
   return( u1_Field_Rd16(&CCU6.IS.reg, (uint16)CCU6_IS_WHE_Pos, (uint16)CCU6_IS_WHE_Msk) );
}

uint8 CCU6_MCM_Idle_Int_Sts(void){
   return( u1_Field_Rd16(&CCU6.IS.reg, (uint16)CCU6_IS_IDLE_Pos, (uint16)CCU6_IS_IDLE_Msk) );
}

uint8 CCU6_MCM_Str_Int_Sts(void){
   return( u1_Field_Rd16(&CCU6.IS.reg, (uint16)CCU6_IS_STR_Pos, (uint16)CCU6_IS_STR_Msk) );
}

void CCU6_T12_CM_CC60_Int_Rise_Set(void){
  Field_Wrt16(&CCU6.ISS.reg, (uint16)CCU6_ISS_SCC60R_Pos, (uint16)CCU6_ISS_SCC60R_Msk, 1u);
}

void CCU6_T12_CM_CC61_Int_Rise_Set(void){
  Field_Wrt16(&CCU6.ISS.reg, (uint16)CCU6_ISS_SCC61R_Pos, (uint16)CCU6_ISS_SCC61R_Msk, 1u);
}

void CCU6_T12_CM_CC62_Int_Rise_Set(void){
  Field_Wrt16(&CCU6.ISS.reg, (uint16)CCU6_ISS_SCC62R_Pos, (uint16)CCU6_ISS_SCC62R_Msk, 1u);
}

void CCU6_T12_CM_CC60_Int_Fall_Set(void){
  Field_Wrt16(&CCU6.ISS.reg, (uint16)CCU6_ISS_SCC60F_Pos, (uint16)CCU6_ISS_SCC60F_Msk, 1u);
}

void CCU6_T12_CM_CC61_Int_Fall_Set(void){
  Field_Wrt16(&CCU6.ISS.reg, (uint16)CCU6_ISS_SCC61F_Pos, (uint16)CCU6_ISS_SCC61F_Msk, 1u);
}

void CCU6_T12_CM_CC62_Int_Fall_Set(void){
  Field_Wrt16(&CCU6.ISS.reg, (uint16)CCU6_ISS_SCC62F_Pos, (uint16)CCU6_ISS_SCC62F_Msk, 1u);
}

void CCU6_T12_OM_Int_Set(void){
  Field_Wrt16(&CCU6.ISS.reg, (uint16)CCU6_ISS_ST12OM_Pos, (uint16)CCU6_ISS_ST12OM_Msk, 1u);
}

void CCU6_T12_PM_Int_Set(void){
  Field_Wrt16(&CCU6.ISS.reg, (uint16)CCU6_ISS_ST12PM_Pos, (uint16)CCU6_ISS_ST12PM_Msk, 1u);
}

void CCU6_T13_CM_Int_Set(void){
  Field_Wrt16(&CCU6.ISS.reg, (uint16)CCU6_ISS_ST13CM_Pos, (uint16)CCU6_ISS_ST13CM_Msk, 1u);
}

void CCU6_T13_PM_Int_Set(void){
  Field_Wrt16(&CCU6.ISS.reg, (uint16)CCU6_ISS_ST13PM_Pos, (uint16)CCU6_ISS_ST13PM_Msk, 1u);
}

void CCU6_Trap_Flag_Int_Set(void){
  Field_Wrt16(&CCU6.ISS.reg, (uint16)CCU6_ISS_STRPF_Pos, (uint16)CCU6_ISS_STRPF_Msk, 1u);
}

void CCU6_Trap_SW_Hall_Int_Set(void){
  Field_Wrt16(&CCU6.ISS.reg, (uint16)CCU6_ISS_SWHC_Pos, (uint16)CCU6_ISS_SWHC_Msk, 1u);
}

void CCU6_Hall_Correct_Int_Set(void){
  Field_Wrt16(&CCU6.ISS.reg, (uint16)CCU6_ISS_SCHE_Pos, (uint16)CCU6_ISS_SCHE_Msk, 1u);
}

void CCU6_Hall_Wrong_Int_Set(void){
  Field_Wrt16(&CCU6.ISS.reg, (uint16)CCU6_ISS_SWHE_Pos, (uint16)CCU6_ISS_SWHE_Msk, 1u);
}

void CCU6_MCM_Idle_Int_Set(void){
  Field_Wrt16(&CCU6.ISS.reg, (uint16)CCU6_ISS_SIDLE_Pos, (uint16)CCU6_ISS_SIDLE_Msk, 1u);
}

void CCU6_MCM_Str_Int_Set(void){
  Field_Wrt16(&CCU6.ISS.reg, (uint16)CCU6_ISS_SSTR_Pos, (uint16)CCU6_ISS_SSTR_Msk, 1u);
}

void CCU6_Ch0_Int_Node_Sel(uint16 srx){
  Field_Mod16(&CCU6.INP.reg, (uint16)CCU6_INP_INPCC60_Pos, (uint16)CCU6_INP_INPCC60_Msk, srx);
}

void CCU6_Ch1_Int_Node_Sel(uint16 srx){
  Field_Mod16(&CCU6.INP.reg, (uint16)CCU6_INP_INPCC61_Pos, (uint16)CCU6_INP_INPCC61_Msk, srx);
}

void CCU6_Ch2_Int_Node_Sel(uint16 srx){
  Field_Mod16(&CCU6.INP.reg, (uint16)CCU6_INP_INPCC62_Pos, (uint16)CCU6_INP_INPCC62_Msk, srx);
}

void CCU6_Error_Int_Node_Sel(uint16 srx){
  Field_Mod16(&CCU6.INP.reg, (uint16)CCU6_INP_INPERR_Pos, (uint16)CCU6_INP_INPERR_Msk, srx);
}

void CCU6_T12_Int_Node_Sel(uint16 srx){
  Field_Mod16(&CCU6.INP.reg, (uint16)CCU6_INP_INPT12_Pos, (uint16)CCU6_INP_INPT12_Msk, srx);
}

void CCU6_T13_Int_Node_Sel(uint16 srx){
  Field_Mod16(&CCU6.INP.reg, (uint16)CCU6_INP_INPT13_Pos, (uint16)CCU6_INP_INPT13_Msk, srx);
}

void CCU6_Hall_Correct_Int_Node_Sel(uint16 srx){
  Field_Mod16(&CCU6.INP.reg, (uint16)CCU6_INP_INPCHE_Pos, (uint16)CCU6_INP_INPCHE_Msk, srx);
}

void CCU6_CH0_CM_R_Int_Clr(void){
  Field_Wrt16(&CCU6.ISR.reg, (uint16)CCU6_ISR_RCC60R_Pos, (uint16)CCU6_ISR_RCC60R_Msk, 1u);
}

void CCU6_CH0_CM_F_Int_Clr(void){
  Field_Wrt16(&CCU6.ISR.reg, (uint16)CCU6_ISR_RCC60F_Pos, (uint16)CCU6_ISR_RCC60F_Msk, 1u);
}

void CCU6_CH1_CM_R_Int_Clr(void){
  Field_Wrt16(&CCU6.ISR.reg, (uint16)CCU6_ISR_RCC61R_Pos, (uint16)CCU6_ISR_RCC61R_Msk, 1u);
}

void CCU6_CH1_CM_F_Int_Clr(void){
  Field_Wrt16(&CCU6.ISR.reg, (uint16)CCU6_ISR_RCC61F_Pos, (uint16)CCU6_ISR_RCC61F_Msk, 1u);
}

void CCU6_CH2_CM_R_Int_Clr(void){
  Field_Wrt16(&CCU6.ISR.reg, (uint16)CCU6_ISR_RCC62R_Pos, (uint16)CCU6_ISR_RCC62R_Msk, 1u);
}

void CCU6_CH2_CM_F_Int_Clr(void){
  Field_Wrt16(&CCU6.ISR.reg, (uint16)CCU6_ISR_RCC62F_Pos, (uint16)CCU6_ISR_RCC62F_Msk, 1u);
}

void CCU6_T12_OM_Int_Clr(void){
  Field_Wrt16(&CCU6.ISR.reg, (uint16)CCU6_ISR_RT12OM_Pos, (uint16)CCU6_ISR_RT12OM_Msk, 1u);
}

void CCU6_T12_PM_Int_Clr(void){
  Field_Wrt16(&CCU6.ISR.reg, (uint16)CCU6_ISR_RT12PM_Pos, (uint16)CCU6_ISR_RT12PM_Msk, 1u);
}

void CCU6_T13_CM_Int_Clr(void){
  Field_Wrt16(&CCU6.ISR.reg, (uint16)CCU6_ISR_RT13CM_Pos, (uint16)CCU6_ISR_RT13CM_Msk, 1u);
}

void CCU6_T13_PM_Int_Clr(void){
  Field_Wrt16(&CCU6.ISR.reg, (uint16)CCU6_ISR_RT13PM_Pos, (uint16)CCU6_ISR_RT13PM_Msk, 1u);
}

void CCU6_TRAP_Int_Clr(void){
  Field_Wrt16(&CCU6.ISR.reg, (uint16)CCU6_ISR_RTRPF_Pos, (uint16)CCU6_ISR_RTRPF_Msk, 1u);
}

void CCU6_CHE_Int_Clr(void){
  Field_Wrt16(&CCU6.ISR.reg, (uint16)CCU6_ISR_RCHE_Pos, (uint16)CCU6_ISR_RCHE_Msk, 1u);
}

void CCU6_WHE_Int_Clr(void){
  Field_Wrt16(&CCU6.ISR.reg, (uint16)CCU6_ISR_RWHE_Pos, (uint16)CCU6_ISR_RWHE_Msk, 1u);
}

void CCU6_STR_Int_Clr(void){
  Field_Wrt16(&CCU6.ISR.reg, (uint16)CCU6_ISR_RSTR_Pos, (uint16)CCU6_ISR_RSTR_Msk, 1u);
}

void CCU6_CH0_CM_R_Int_En(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENCC60R_Pos, (uint16)CCU6_IEN_ENCC60R_Msk, 1u);
}

void CCU6_CH0_CM_R_Int_Dis(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENCC60R_Pos, (uint16)CCU6_IEN_ENCC60R_Msk, 0u);
}

void CCU6_CH0_CM_F_Int_En(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENCC60F_Pos, (uint16)CCU6_IEN_ENCC60F_Msk, 1u);
}

void CCU6_CH0_CM_F_Int_Dis(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENCC60F_Pos, (uint16)CCU6_IEN_ENCC60F_Msk, 0u);
}

void CCU6_CH1_CM_R_Int_En(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENCC61R_Pos, (uint16)CCU6_IEN_ENCC61R_Msk, 1u);
}

void CCU6_CH1_CM_R_Int_Dis(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENCC61R_Pos, (uint16)CCU6_IEN_ENCC61R_Msk, 0u);
}

void CCU6_CH1_CM_F_Int_En(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENCC61F_Pos, (uint16)CCU6_IEN_ENCC61F_Msk, 1u);
}

void CCU6_CH1_CM_F_Int_Dis(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENCC61F_Pos, (uint16)CCU6_IEN_ENCC61F_Msk, 0u);
}

void CCU6_CH2_CM_R_Int_En(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENCC62R_Pos, (uint16)CCU6_IEN_ENCC62R_Msk, 1u);
}

void CCU6_CH2_CM_R_Int_Dis(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENCC62R_Pos, (uint16)CCU6_IEN_ENCC62R_Msk, 0u);
}

void CCU6_CH2_CM_F_Int_En(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENCC62F_Pos, (uint16)CCU6_IEN_ENCC62F_Msk, 1u);
}

void CCU6_CH2_CM_F_Int_Dis(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENCC62F_Pos, (uint16)CCU6_IEN_ENCC62F_Msk, 0u);
}

void CCU6_T12_OM_Int_En(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENT12OM_Pos, (uint16)CCU6_IEN_ENT12OM_Msk, 1u);
}

void CCU6_T12_OM_Int_Dis(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENT12OM_Pos, (uint16)CCU6_IEN_ENT12OM_Msk, 0u);
}

void CCU6_T12_PM_Int_En(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENT12PM_Pos, (uint16)CCU6_IEN_ENT12PM_Msk, 1u);
}

void CCU6_T12_PM_Int_Dis(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENT12PM_Pos, (uint16)CCU6_IEN_ENT12PM_Msk, 0u);
}

void CCU6_T13_CM_Int_En(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENT13CM_Pos, (uint16)CCU6_IEN_ENT13CM_Msk, 1u);
}

void CCU6_T13_CM_Int_Dis(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENT13CM_Pos, (uint16)CCU6_IEN_ENT13CM_Msk, 0u);
}

void CCU6_T13_PM_Int_En(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENT13PM_Pos, (uint16)CCU6_IEN_ENT13PM_Msk, 1u);
}

void CCU6_T13_PM_Int_Dis(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENT13PM_Pos, (uint16)CCU6_IEN_ENT13PM_Msk, 0u);
}

void CCU6_TRAP_Int_En(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENTRPF_Pos, (uint16)CCU6_IEN_ENTRPF_Msk, 1u);
}

void CCU6_TRAP_Int_Dis(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENTRPF_Pos, (uint16)CCU6_IEN_ENTRPF_Msk, 0u);
}

void CCU6_CHE_Int_En(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENCHE_Pos, (uint16)CCU6_IEN_ENCHE_Msk, 1u);
}

void CCU6_CHE_Int_Dis(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENCHE_Pos, (uint16)CCU6_IEN_ENCHE_Msk, 0u);
}

void CCU6_WHE_Int_En(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENWHE_Pos, (uint16)CCU6_IEN_ENWHE_Msk, 1u);
}

void CCU6_WHE_Int_Dis(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENWHE_Pos, (uint16)CCU6_IEN_ENWHE_Msk, 0u);
}

void CCU6_STR_Int_En(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENSTR_Pos, (uint16)CCU6_IEN_ENSTR_Msk, 1u);
}

void CCU6_STR_Int_Dis(void){
  Field_Mod16(&CCU6.IEN.reg, (uint16)CCU6_IEN_ENSTR_Pos, (uint16)CCU6_IEN_ENSTR_Msk, 0u);
}
*/
void CCU6_StartTmr_T12(void){
  CCU6_T12_Start();
}
/*
void CCU6_StartTmr_T13(void){
  CCU6_T13_Start();
}
*/
void CCU6_StopTmr_T12(void){
  CCU6_T12_Stop();
}
/*
void CCU6_StopTmr_T13(void){
  CCU6_T13_Stop();
}
*/
void CCU6_EnableST_T12(void){
  CCU6_T12_Str_En();
}
/*
void CCU6_EnableST_T13(void){
  CCU6_T13_Str_En();
}
*/

void CCU6_LoadShadowRegister_CC60(uint16 tick){
  CCU6_Ch0_Value_Set(tick);
}

void CCU6_LoadShadowRegister_CC61(uint16 tick){
  CCU6_Ch1_Value_Set(tick);
}

void CCU6_LoadShadowRegister_CC62(uint16 tick){
  CCU6_Ch2_Value_Set(tick);
}

/*
void CCU6_LoadShadowRegister_CC63(uint16 tick){
  CCU6_Ch3_Value_Set(tick);
}

void CCU6_LoadPeriodRegister_T13_Time(uint32 us){
  CCU6_T13_Period_Value_Set((uint16)((uint32)CCU6_T13_CLK * us));
}

void CCU6_LoadPeriodRegister_T13_Tick(uint16 tick){
  CCU6_T13_Period_Value_Set(tick);
}

bool CCU6_IsT13Running(void){
  bool res = false;

  if(CCU6_T13_Run_Sts() == (uint8)1){
    res = true;
  }

   return(res);
}
*/

void CCU6_SetT13Trigger(uint16 Mask){
  Field_Wrt16(&CCU6.TCTR2.reg, 0, (uint16)0xFFFF, Mask);
}

void CCU6_SetT13Compare(
   uint16 Compare
){
   if(
         CCU6_T13_Period_Value_Get()
      >  Compare
   ){
      CCU6_Ch3_Value_Set(Compare);
   }
   else{
      if(
            (uint16)0xFFFE
         >= Compare
      ){
         CCU6_Ch3_Value_Set(Compare);
         CCU6_T13_Period_Value_Set((Compare + 1u));
      }
      else{
         CCU6_Ch3_Value_Set((uint16)0xFFFE);
         CCU6_T13_Period_Value_Set((uint16)0xFFFF);
      }
   }

   CCU6_T13_Str_En();
}

/*
void CCU6_SetT12T13ControlBits(uint16 Mask){
  Field_Wrt16(&CCU6.TCTR4.reg, 0, (uint16)0xFFFF, Mask);
}

uint32 CCU6_ReadHallReg(void){
   return(uint32)u16_Field_Rd16(&CCU6.CMPSTAT.reg, (uint8)CCU6_CMPSTAT_CCPOS0_Pos, 0x38u);
}

uint16 CCU6_ReadMultichannelPatterns(void){
   return u16_Field_Rd16(&CCU6.MCMOUT.reg, 0, (uint16)0xFFFF);
}

void CCU6_WriteMultichannelPatterns(uint16 Patterns){
  Field_Wrt16(&CCU6.MCMOUTS.reg, 0, (uint16)0xFFFF, Patterns);
}

void CCU6_ConfigureMultichannelModulation(uint16 Mode){
  Field_Wrt16(&CCU6.MCMCTR.reg, 0, (uint16)0xFFFF, Mode);
}

void CCU6_ConfigureGlobalModulation(uint16 Mode){
  Field_Wrt16(&CCU6.MODCTR.reg, 0, (uint16)0xFFFF, Mode);
}

void CCU6_EnableInt(uint16 Mask){
  Field_Wrt16(&CCU6.IEN.reg, 0, (uint16)0xFFFF, Mask);
}

void CCU6_ClearIntStatus(uint16 Mask){
  Field_Wrt16(&CCU6.ISR.reg, 0, (uint16)0xFFFF, Mask);
}
*/

bool Emo_lExeSvm_Ccu6_1(void){
   return CCU6.TCTR0.bit.CDIR;
}

void Emo_lExeSvm_Ccu6_2(void){
   CCU6.IEN.bit.ENT12PM = 1;
}

void Emo_HandleCcu6(
      uint16 lu16CompT13ValueDown
   ,  uint16 lu16Comp60down
   ,  uint16 lu16Comp61down
   ,  uint16 lu16Comp62down
){
   CCU6_SetT13Compare(lu16CompT13ValueDown);
   CCU6_SetT13Trigger(0x76);
   CCU6_LoadShadowRegister_CC60(lu16Comp60down);
   CCU6_LoadShadowRegister_CC61(lu16Comp61down);
   CCU6_LoadShadowRegister_CC62(lu16Comp62down);
   CCU6_EnableST_T12();
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

