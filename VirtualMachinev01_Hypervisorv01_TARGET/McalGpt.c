/******************************************************************************/
/* File   : McalGpt.c                                                         */
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
/* https://github.com/RaajnaagHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

#include "infMcalGptSwcApplEcuM.hpp"

#include "uC_Gpt.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define OSTM0_COMPARE_1MS                                                  40000

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
#if(CfgProject_dSwitchReSim != STD_ON)
#else
volatile       uint32 PROTCMD0;
volatile const uint32 PROTS0;
volatile       uint32 MOSCE;
volatile const uint32 MOSCS;
volatile       uint32 MOSCC;
volatile       uint32 MOSCST;
volatile       uint32 PROTCMD1;
volatile const uint32 PROTS1;
volatile       uint32 PLLE;
volatile const uint32 PLLS;
volatile       uint32 PLLC;
volatile       uint32 CKSC_CPUCLKS_CTL;
volatile const uint32 CKSC_CPUCLKS_ACT;
volatile       uint32 CKSC_CPUCLKD_CTL;
volatile const uint32 CKSC_CPUCLKD_ACT;
#endif

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
static void OSTM0_SetCompareValue(uint16 comp){
   OSTM0CMP = comp;
}

static void OSTM0_IntervalMode(void){
   OSTM0TT  = 0x01u;
   OSTM0EMU = 0x00u;
   OSTM0CTL = 0x00u;
}

static void OSTM0_Start(void){
   OSTM0TS = 0x01u;
}

FUNC(void, MCALGPT_CODE) infMcalGptSwcApplEcuM_InitFunction(void){
   MOSCC  = 0x02; //TBD: Move to CfgMcalGpt
   MOSCST = 0xFFFF;
   protected_write(
         PROTCMD0
      ,  PROTS0
      ,  MOSCE
      ,  0x01
   );
   while((MOSCS & 0x04) != 0x4);

   PLLC = 0x00000a27;
   protected_write(
         PROTCMD1
      ,  PROTS1
      ,  PLLE
      ,  0x01
   );
   while((PLLS & 0x04) != 0x04);

   protected_write(
         PROTCMD1
      ,  PROTS1
      ,  CKSC_CPUCLKD_CTL
      ,  0x01
   );
   while(CKSC_CPUCLKD_ACT != 0x01);

   protected_write(
         PROTCMD1
      ,  PROTS1
      ,  CKSC_CPUCLKS_CTL
      ,  0x03
   );
   while(CKSC_CPUCLKS_ACT != 0x03);

   OSTM0_SetCompareValue(OSTM0_COMPARE_1MS);
   OSTM0_IntervalMode();
   OSTM0_Start();
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
