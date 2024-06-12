#pragma once
/******************************************************************************/
/* File   : McalGpt_core.hpp                                                      */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_McalGpt.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define GPT_CORE_FUNCTIONALITIES                                               \
              FUNC(void, GPT_CODE) GetTimeElapsed      (void);                 \
              FUNC(void, GPT_CODE) GetTimeRemaining    (void);                 \
              FUNC(void, GPT_CODE) StartTimer          (void);                 \
              FUNC(void, GPT_CODE) StopTimer           (void);                 \
              FUNC(void, GPT_CODE) DisableNotification (void);                 \
              FUNC(void, GPT_CODE) EnableNotification  (void);                 \
              FUNC(void, GPT_CODE) SetMode             (void);                 \
              FUNC(void, GPT_CODE) CheckWakeup         (void);                 \
              FUNC(void, GPT_CODE) DisableWakeup       (void);                 \
              FUNC(void, GPT_CODE) EnableWakeup        (void);                 \
              FUNC(void, GPT_CODE) GetPredefTimerValue (void);                 \

#define GPT_CORE_FUNCTIONALITIES_VIRTUAL                                       \
      virtual FUNC(void, GPT_CODE) GetTimeElapsed      (void) = 0;             \
      virtual FUNC(void, GPT_CODE) GetTimeRemaining    (void) = 0;             \
      virtual FUNC(void, GPT_CODE) StartTimer          (void) = 0;             \
      virtual FUNC(void, GPT_CODE) StopTimer           (void) = 0;             \
      virtual FUNC(void, GPT_CODE) DisableNotification (void) = 0;             \
      virtual FUNC(void, GPT_CODE) EnableNotification  (void) = 0;             \
      virtual FUNC(void, GPT_CODE) SetMode             (void) = 0;             \
      virtual FUNC(void, GPT_CODE) CheckWakeup         (void) = 0;             \
      virtual FUNC(void, GPT_CODE) DisableWakeup       (void) = 0;             \
      virtual FUNC(void, GPT_CODE) EnableWakeup        (void) = 0;             \
      virtual FUNC(void, GPT_CODE) GetPredefTimerValue (void) = 0;             \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_McalGpt_Functionality{
   public:
      GPT_CORE_FUNCTIONALITIES_VIRTUAL
};

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

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

