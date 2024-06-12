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
#define MCALGPT_CORE_FUNCTIONALITIES                                               \
              FUNC(void, MCALGPT_CODE) GetTimeElapsed      (void);                 \
              FUNC(void, MCALGPT_CODE) GetTimeRemaining    (void);                 \
              FUNC(void, MCALGPT_CODE) StartTimer          (void);                 \
              FUNC(void, MCALGPT_CODE) StopTimer           (void);                 \
              FUNC(void, MCALGPT_CODE) DisableNotification (void);                 \
              FUNC(void, MCALGPT_CODE) EnableNotification  (void);                 \
              FUNC(void, MCALGPT_CODE) SetMode             (void);                 \
              FUNC(void, MCALGPT_CODE) CheckWakeup         (void);                 \
              FUNC(void, MCALGPT_CODE) DisableWakeup       (void);                 \
              FUNC(void, MCALGPT_CODE) EnableWakeup        (void);                 \
              FUNC(void, MCALGPT_CODE) GetPredefTimerValue (void);                 \

#define MCALGPT_CORE_FUNCTIONALITIES_VIRTUAL                                       \
      virtual FUNC(void, MCALGPT_CODE) GetTimeElapsed      (void) = 0;             \
      virtual FUNC(void, MCALGPT_CODE) GetTimeRemaining    (void) = 0;             \
      virtual FUNC(void, MCALGPT_CODE) StartTimer          (void) = 0;             \
      virtual FUNC(void, MCALGPT_CODE) StopTimer           (void) = 0;             \
      virtual FUNC(void, MCALGPT_CODE) DisableNotification (void) = 0;             \
      virtual FUNC(void, MCALGPT_CODE) EnableNotification  (void) = 0;             \
      virtual FUNC(void, MCALGPT_CODE) SetMode             (void) = 0;             \
      virtual FUNC(void, MCALGPT_CODE) CheckWakeup         (void) = 0;             \
      virtual FUNC(void, MCALGPT_CODE) DisableWakeup       (void) = 0;             \
      virtual FUNC(void, MCALGPT_CODE) EnableWakeup        (void) = 0;             \
      virtual FUNC(void, MCALGPT_CODE) GetPredefTimerValue (void) = 0;             \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_McalGpt_Functionality{
   public:
      MCALGPT_CORE_FUNCTIONALITIES_VIRTUAL
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

