/******************************************************************************/
/* File   : McalGpt.cpp                                                       */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "McalGpt.hpp"
#include "infMcalGpt_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define MCALGPT_AR_RELEASE_VERSION_MAJOR                                       4
#define MCALGPT_AR_RELEASE_VERSION_MINOR                                       3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(MCALGPT_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible MCALGPT_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(MCALGPT_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible MCALGPT_AR_RELEASE_VERSION_MINOR!"
#endif

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
VAR(module_McalGpt, MCALGPT_VAR) McalGpt;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
extern void SCU_Init    (void); //TBD: use interface headers as per architecture
extern void CCU6_Init   (void); //TBD: use interface headers as per architecture
extern void GPT12E_Init (void); //TBD: use interface headers as per architecture

FUNC(void, MCALGPT_CODE) module_McalGpt::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, MCALGPT_CONST,       MCALGPT_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   MCALGPT_CONFIG_DATA, MCALGPT_APPL_CONST) lptrCfgModule
){
#if(STD_ON == McalGpt_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = (const ConstMcalGpt_Type*)lptrConstModule;
         lptrCfg   = lptrCfgModule;
      }
      else{
#if(STD_ON == McalGpt_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
      SCU_Init();
      CCU6_Init();
      GPT12E_Init();
#if(STD_ON == McalGpt_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == McalGpt_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALGPT_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALGPT_CODE) module_McalGpt::DeInitFunction(
   void
){
#if(STD_ON == McalGpt_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == McalGpt_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == McalGpt_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALGPT_E_UNINIT
      );
#endif
   }
#endif
}

#include "isr.hpp" //TBD: move to ISR
FUNC(void, MCALGPT_CODE) module_McalGpt::MainFunction(
   void
){
#if(STD_ON == McalGpt_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif

   GPT1_IRQHandler(); //TBD: move to ISR

#if(STD_ON == McalGpt_InitCheck)
   }
   else{
#if(STD_ON == McalGpt_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALGPT_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALGPT_CODE) module_McalGpt::GetTimeElapsed(
   void
){
}

FUNC(void, MCALGPT_CODE) module_McalGpt::GetTimeRemaining(
   void
){
}

FUNC(void, MCALGPT_CODE) module_McalGpt::StartTimer(
   void
){
}

FUNC(void, MCALGPT_CODE) module_McalGpt::StopTimer(
   void
){
}

FUNC(void, MCALGPT_CODE) module_McalGpt::DisableNotification(
   void
){
}

FUNC(void, MCALGPT_CODE) module_McalGpt::EnableNotification(
   void
){
}

FUNC(void, MCALGPT_CODE) module_McalGpt::SetMode(
   void
){
}

FUNC(void, MCALGPT_CODE) module_McalGpt::CheckWakeup(
   void
){
}

FUNC(void, MCALGPT_CODE) module_McalGpt::DisableWakeup(
   void
){
}

FUNC(void, MCALGPT_CODE) module_McalGpt::EnableWakeup(
   void
){
}

FUNC(void, MCALGPT_CODE) module_McalGpt::GetPredefTimerValue(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

