/******************************************************************************/
/* File   : McalGpt.cpp                                                           */
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
#define GPT_AR_RELEASE_VERSION_MAJOR                                           4
#define GPT_AR_RELEASE_VERSION_MINOR                                           3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(GPT_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible GPT_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(GPT_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible GPT_AR_RELEASE_VERSION_MINOR!"
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
VAR(module_McalGpt, GPT_VAR) McalGpt;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, GPT_CODE) module_McalGpt::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, GPT_CONST,       GPT_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   GPT_CONFIG_DATA, GPT_APPL_CONST) lptrCfgModule
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
#if(STD_ON == McalGpt_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == McalGpt_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  GPT_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, GPT_CODE) module_McalGpt::DeInitFunction(
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
         ,  GPT_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, GPT_CODE) module_McalGpt::MainFunction(
   void
){
#if(STD_ON == McalGpt_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == McalGpt_InitCheck)
   }
   else{
#if(STD_ON == McalGpt_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  GPT_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, GPT_CODE) module_McalGpt::GetTimeElapsed(
   void
){
}

FUNC(void, GPT_CODE) module_McalGpt::GetTimeRemaining(
   void
){
}

FUNC(void, GPT_CODE) module_McalGpt::StartTimer(
   void
){
}

FUNC(void, GPT_CODE) module_McalGpt::StopTimer(
   void
){
}

FUNC(void, GPT_CODE) module_McalGpt::DisableNotification(
   void
){
}

FUNC(void, GPT_CODE) module_McalGpt::EnableNotification(
   void
){
}

FUNC(void, GPT_CODE) module_McalGpt::SetMode(
   void
){
}

FUNC(void, GPT_CODE) module_McalGpt::CheckWakeup(
   void
){
}

FUNC(void, GPT_CODE) module_McalGpt::DisableWakeup(
   void
){
}

FUNC(void, GPT_CODE) module_McalGpt::EnableWakeup(
   void
){
}

FUNC(void, GPT_CODE) module_McalGpt::GetPredefTimerValue(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

