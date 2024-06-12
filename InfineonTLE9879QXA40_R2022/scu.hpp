#pragma once
/******************************************************************************/
/* File   : scu.hpp                                                           */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define PASSWD_Open                                                      (0x98U)
#define PASSWD_Close                                                     (0xA8U)
#define NVM_DATA_WRITE                                                   (0U)
#define NVM_CODE_WRITE                                                   (1U)
#define NVM_DATA_READ                                                    (2U)
#define NVM_CODE_READ                                                    (3U)
#define PROTECTION_CLEAR                                                 (1U)
#define PROTECTION_SET                                                   (0U)
#define SLOWDOWN_PRESCALER_1                                             (0U)
#define SLOWDOWN_PRESCALER_2                                             (1U)
#define SLOWDOWN_PRESCALER_3                                             (2U)
#define SLOWDOWN_PRESCALER_4                                             (3U)
#define SLOWDOWN_PRESCALER_8                                             (4U)
#define SLOWDOWN_PRESCALER_16                                            (5U)
#define SLOWDOWN_PRESCALER_24                                            (6U)
#define SLOWDOWN_PRESCALER_32                                            (7U)
#define SLOWDOWN_PRESCALER_48                                            (8U)
#define SLOWDOWN_PRESCALER_64                                            (9U)
#define SLOWDOWN_PRESCALER_96                                            (10U)
#define SLOWDOWN_PRESCALER_128                                           (11U)
#define SLOWDOWN_PRESCALER_192                                           (12U)
#define SLOWDOWN_PRESCALER_256                                           (13U)
#define SLOWDOWN_PRESCALER_384                                           (14U)
#define SLOWDOWN_PRESCALER_512                                           (15U)

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef enum{
      Mod_ADC1    = 0x00
   ,  Mod_SSC1    = 0x01
   ,  Mod_CCU6    = 0x02
   ,  Mod_Timer2  = 0x03
   ,  Mod_GPT12   = 0x04
   ,  Mod_SSC2    = 0x11
   ,  Mod_Timer21 = 0x13
   ,  Mod_Timer3  = 0x15
}TScu_Mod;

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
extern void PLL_setfSYStoLPCLK                 (void);
extern void PLL_setfSYStofPLL                  (void);
extern void PLL_setK1divToOne                  (void);
extern void PLL_setClkSrcToIntOscSync          (void);
extern void PLL_setClkSrcToXtal                (void);
extern void PLL_enableXTAL                     (void);
extern void PLL_resetOscWDT                    (void);
extern void PLL_waitForOSC2L                   (void);
extern void PLL_setOscTrim                     (void);
extern void PLL_setNdivFromConfigWizard        (void);
extern void PLL_setVcoselK2divFromConfigWizard (void);
extern void PLL_resetPllLockDetection          (void);
extern void PLL_waitForPllLock                 (void);
extern void PLL_setPrescalerMode               (void);
extern void PLL_setNormalMode                  (void);
extern void SCU_toggleAPCLK_SET                (void);
extern void SCU_ClkInit                        (void);
extern void SCU_Init                           (void);
extern void SCU_EnterSleepMode                 (void);
extern void PLL_setClkSrcToIntOscAsync         (void);
extern void SCU_EnterStopMode                  (void);
extern void SCU_EnterSlowMode                  (uint8 divider_scaled);
extern void SCU_ExitSlowMode                   (void);
extern bool SCU_ChangeNVMProtection            (uint32 mode, uint32 action);
extern void SCU_WDT_Start                      (void);
extern void SCU_WDT_Stop                       (void);
extern void SCU_WDT_Service                    (void);
extern void SCU_Disable_Module                 (TScu_Mod Module);
extern void SCU_Enable_Module                  (TScu_Mod Module);
extern void SCU_OpenPASSWD                     (void);
extern void SCU_ClosePASSWD                    (void);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

