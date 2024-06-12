/******************************************************************************/
/* File   : Template.hpp                                                      */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "types.hpp"

#include "scu.hpp"

#include "scu_defines.hpp"
#include "isr_defines.hpp"

#include "uC_Scu.hpp"

#include "sfr_access.hpp"
#include "cmsis_misra.hpp"
#include "bootrom.hpp"
#include "wdt1.hpp"
#include "gpt12e.hpp"

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
SCU_Type SCU = {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0
};

SCUPM_Type SCUPM = {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   ,  0, 0, 0, 0
};

uint32 SystemFrequency = (uint32)SCU_FSYS;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
/*
void PLL_setfSYStoLPCLK(void){
   uint8 u8_loc_syscon0;
   u8_loc_syscon0 = SCU.SYSCON0.reg;
   Field_Mod8(&u8_loc_syscon0, (uint8)SCU_SYSCON0_SYSCLKSEL_Pos, (uint8)SCU_SYSCON0_SYSCLKSEL_Msk, 3u);
   SCU_OpenPASSWD();
   SCU.SYSCON0.reg = u8_loc_syscon0;
   SCU_ClosePASSWD();
}

void PLL_setfSYStofPLL(void){
   uint8 u8_loc_syscon0;
   u8_loc_syscon0 = SCU.SYSCON0.reg;
   Field_Mod8(&u8_loc_syscon0, (uint8)SCU_SYSCON0_SYSCLKSEL_Pos, (uint8)SCU_SYSCON0_SYSCLKSEL_Msk, 0u);
   SCU_OpenPASSWD();
   SCU.SYSCON0.reg = u8_loc_syscon0;
   SCU_ClosePASSWD();
}

void PLL_setK1divToOne(void){
   uint8 u8_loc_cmcon1;
   u8_loc_cmcon1 = SCU.CMCON1.reg;
   Field_Mod8(&u8_loc_cmcon1, (uint8)SCU_CMCON1_K1DIV_Pos, (uint8)SCU_CMCON1_K1DIV_Msk, 1u);
   SCU_OpenPASSWD();
   SCU.CMCON1.reg = u8_loc_cmcon1;
   SCU_ClosePASSWD();
}

void PLL_setClkSrcToIntOscSync(void){
   uint8 u8_loc_osc_con;
   u8_loc_osc_con = SCU.OSC_CON.reg;
   Field_Mod8(&u8_loc_osc_con, (uint8)SCU_OSC_CON_OSCSS_Pos, (uint8)SCU_OSC_CON_OSCSS_Msk, 0);
   SCU_OpenPASSWD();
   SCU.OSC_CON.reg = u8_loc_osc_con;
   SCU_ClosePASSWD();
}

void PLL_setClkSrcToXtal(void){
   uint8 u8_loc_osc_con;
   u8_loc_osc_con = SCU.OSC_CON.reg;
   Field_Mod8(&u8_loc_osc_con, (uint8)SCU_OSC_CON_OSCSS_Pos, (uint8)SCU_OSC_CON_OSCSS_Msk, 1);
   SCU_OpenPASSWD();
   SCU.OSC_CON.reg = u8_loc_osc_con;
   SCU_ClosePASSWD();
}

void PLL_enableXTAL(void){
   uint8 u8_loc_osc_con;
   u8_loc_osc_con = SCU.OSC_CON.reg;
   Field_Mod8(&u8_loc_osc_con, (uint8)SCU_OSC_CON_XPD_Pos, (uint8)SCU_OSC_CON_XPD_Msk, 0);
   SCU_OpenPASSWD();
   SCU.OSC_CON.reg = u8_loc_osc_con;
   SCU_ClosePASSWD();
}

void PLL_resetOscWDT(void){
   Field_Mod8(&SCU.OSC_CON.reg, (uint8)SCU_OSC_CON_OSCWDTRST_Pos, (uint8)SCU_OSC_CON_OSCWDTRST_Msk, 1);
}

void PLL_waitForOSC2L(void){
   while(u1_Field_Rd8(&SCU.OSC_CON.reg, (uint8)SCU_OSC_CON_OSC2L_Pos, (uint8)SCU_OSC_CON_OSC2L_Msk) == (uint8)1){
   }
}

void PLL_setOscTrim(void){
   uint8 u8_loc_osc_con;
   u8_loc_osc_con = SCU.OSC_CON.reg;
   Field_Mod8(&u8_loc_osc_con, (uint8)SCU_OSC_CON_OSCTRIM_8_Pos, (uint8)SCU_OSC_CON_OSCTRIM_8_Msk, 1);
   u8_loc_osc_con |= (1u << 5u);
   SCU_OpenPASSWD();
   SCU.OSC_CON.reg = u8_loc_osc_con;
   SCU_ClosePASSWD();
}

void PLL_setNdivFromConfigWizard(void){
   uint8 u8_loc_pll_con;
   u8_loc_pll_con = SCU.PLL_CON.reg;
   u8_loc_pll_con &= (uint8)~SCU_PLL_CON_NDIV_Msk;
   u8_loc_pll_con = u8_loc_pll_con | (uint8)((uint8)SCU_PLL_CON & (uint8)SCU_PLL_CON_NDIV_Msk);
   SCU_OpenPASSWD();
   SCU.PLL_CON.reg = u8_loc_pll_con;
   SCU_ClosePASSWD();
}

void PLL_setVcoselK2divFromConfigWizard(void){
   SCU_OpenPASSWD();
   SCU.CMCON1.reg = (uint8)SCU_CMCON1 | (uint8)SCU_CMCON1_K1DIV_Msk;
   SCU_ClosePASSWD();
}

void PLL_resetPllLockDetection(void){
   Field_Mod8(&SCU.PLL_CON.reg, (uint8)SCU_PLL_CON_RESLD_Pos, (uint8)SCU_PLL_CON_RESLD_Msk, 1u);
}

void PLL_waitForPllLock(void){
   while(u1_Field_Rd8(&SCU.PLL_CON.reg, (uint8)SCU_PLL_CON_LOCK_Pos, (uint8)SCU_PLL_CON_LOCK_Msk) == (uint8)0){
   }
}

void PLL_setPrescalerMode(void){
   Field_Mod8(&SCU.PLL_CON.reg, (uint8)SCU_PLL_CON_VCOBYP_Pos, (uint8)SCU_PLL_CON_VCOBYP_Msk, 1u);
}

void PLL_setNormalMode(void){
   Field_Mod8(&SCU.PLL_CON.reg, (uint8)SCU_PLL_CON_VCOBYP_Pos, (uint8)SCU_PLL_CON_VCOBYP_Msk, 0u);
}

void SCU_toggleAPCLK_SET(void){
   uint8 u8_loc_apclk_ctrl1;
   u8_loc_apclk_ctrl1 = SCU.APCLK_CTRL1.reg;
   Field_Mod8(&u8_loc_apclk_ctrl1, (uint8)SCU_APCLK_CTRL1_APCLK_SET_Pos, (uint8)SCU_APCLK_CTRL1_APCLK_SET_Msk, 1u);
   SCU_OpenPASSWD();
   SCU.APCLK_CTRL1.reg = u8_loc_apclk_ctrl1;
   SCU_ClosePASSWD();
   CMSIS_NOP();
   Field_Mod8(&u8_loc_apclk_ctrl1, (uint8)SCU_APCLK_CTRL1_APCLK_SET_Pos, (uint8)SCU_APCLK_CTRL1_APCLK_SET_Msk, 0u);
   SCU_OpenPASSWD();
   SCU.APCLK_CTRL1.reg = u8_loc_apclk_ctrl1;
   SCU_ClosePASSWD();
}

void SCU_ClkInit(void){
   CMSIS_Irq_Dis();
   (void)USER_CFLASH_WR_PROT_EN((uint16) SCU_CFLASH_WPROT_PW);
   Field_Mod8(&SCU.NMICON.reg, (uint8)SCU_NMICON_NMIPLL_Pos, (uint8)SCU_NMICON_NMIPLL_Msk, 0);
   Field_Mod8(&SCU.NMICON.reg, (uint8)SCU_NMICON_NMIWDT_Pos, (uint8)SCU_NMICON_NMIWDT_Msk, 0);
   PLL_setfSYStoLPCLK();
   PLL_setK1divToOne();
   PLL_setPrescalerMode();
   PLL_setOscTrim();
   PLL_setNdivFromConfigWizard();
   PLL_setVcoselK2divFromConfigWizard();
   PLL_resetPllLockDetection();
   PLL_waitForPllLock();
   PLL_setNormalMode();
   PLL_setfSYStofPLL();
   Field_Mod8(&SCU.NMICLR.reg, (uint8)SCU_NMICLR_NMIPLLC_Pos, (uint8)SCU_NMICLR_NMIPLLC_Msk, 1u);
   Field_Mod8(&SCU.NMICLR.reg, (uint8)SCU_NMICLR_NMIOWDC_Pos, (uint8)SCU_NMICLR_NMIOWDC_Msk, 1u);
   Field_Wrt8all(&SCU.APCLK1.reg, SCU_APCLK1);
   SCU_toggleAPCLK_SET();
   Field_Wrt8all(&SCU.APCLK2.reg, SCU_APCLK2);
   SCU_toggleAPCLK_SET();
   SCU_OpenPASSWD();
   SCU.APCLK_CTRL1.reg = (uint8)SCU_APCLK_CTRL1;
   SCU_ClosePASSWD();
   SCU_OpenPASSWD();
   SCU.APCLK_CTRL2.reg = (uint8)SCU_APCLK_CTRL2;
   SCU_ClosePASSWD();
   SCU_toggleAPCLK_SET();
   CMSIS_Irq_En();
}
*/

#if(STD_ON == _ReSIM)
uint8 ReSim_T2IE = (uint8)1;
uint8 ReSim_T2   = (uint8)1;
#else
#endif

void SCU_Init(void){
   SCU.COCON.reg      = (uint8) (SCU_COCON);
   SCU.WDTREL.reg     = (uint8) SCU_WDTREL;
   SCU.WDTWINB.reg    = (uint8) SCU_WDTWINB;
   SCU.WDTCON.reg     = (uint8) SCU_WDTCON;
   SCU.MODPISEL.reg   = (uint8) SCU_MODPISEL;
   SCU.MODPISEL1.reg  = (uint8) SCU_MODPISEL1;
   SCU.MODPISEL2.reg  = (uint8) SCU_MODPISEL2;
   SCU.MODPISEL3.reg  = (uint8) SCU_MODPISEL3;
   SCU.GPT12PISEL.reg = (uint8) SCU_GPT12PISEL;
   SCU.DMASRCSEL.reg  = (uint8) SCU_DMASRCSEL;
   SCU.DMASRCSEL2.reg = (uint8) SCU_DMASRCSEL2;

#if(STD_ON == _ReSIM)
   SCU.GPT12IEN.bit.T2IE = ReSim_T2IE;
   SCU.GPT12IRC.bit.T2   = ReSim_T2;
#else
#endif
}
/*
#if(PMU_SLEEP_MODE == 1)
#ifndef UNIT_TESTING_LV2
   void __attribute__((noreturn)) SCU_EnterSleepMode(void)
#else
   void SCU_EnterSleepMode(void)
#endif{
   uint8 u8_loc_pmcon0;
   uint8 dummy;
   dummy = 0;
   dummy = dummy;
   LIN_Set_Mode(LIN_MODE_SLEEP);

   while(LIN_Get_Mode() != LIN_GET_MODE_SLEEP){}

   Delay_us(100u);
   dummy = u8_Field_Rd8(&PMU.WAKE_STATUS.reg, 0, 0xFF);
   dummy = u8_Field_Rd8(&PMU.WAKE_STS_MON.reg, 0, 0xFF);
   WDT1_Stop();
   WDT1_SOW_Service(1u);
   CMSIS_Irq_Dis();
   u8_loc_pmcon0 = SCU.PMCON0.reg;
   Field_Mod8(&u8_loc_pmcon0, (uint8)SCU_PMCON0_SL_Pos, (uint8)SCU_PMCON0_SL_Msk, 1U);
   SCU_OpenPASSWD();
   SCU.PMCON0.reg = u8_loc_pmcon0;
   CMSIS_WFE();
   CMSIS_WFE();
#ifndef UNIT_TESTING_LV2
   while(1){}
#endif
}
#endif

#if(PMU_STOP_MODE == 1)
void PLL_setClkSrcToIntOscAsync(void){
   uint8 u8_loc_osc_con;
   u8_loc_osc_con = SCU.OSC_CON.reg;
   Field_Mod8(&u8_loc_osc_con, (uint8)SCU_OSC_CON_OSCSS_Pos, (uint8)SCU_OSC_CON_OSCSS_Msk, 3u);
   SCU_OpenPASSWD();
   SCU.OSC_CON.reg = u8_loc_osc_con;
   SCU_ClosePASSWD();
}

void SCU_EnterStopMode(void){
   uint8 u8_loc_pmcon0;
   uint8 dummy;
   dummy = 0;
   dummy = dummy;
   dummy = u8_Field_Rd8(&PMU.WAKE_STATUS.reg, 0, 0xFF);
   dummy = u8_Field_Rd8(&PMU.WAKE_STS_MON.reg, 0, 0xFF);
   dummy = u8_Field_Rd8(&PMU.WAKE_STS_GPIO0.reg, 0, 0xFF);
   dummy = u8_Field_Rd8(&PMU.WAKE_STS_GPIO1.reg, 0, 0xFF);
   WDT1_Stop();
   WDT1_SOW_Service(1u);
   CMSIS_Irq_Dis();
   PLL_setfSYStoLPCLK();
   PLL_setClkSrcToIntOscAsync();
   u8_loc_pmcon0 = SCU.PMCON0.reg;
   Field_Mod8(&u8_loc_pmcon0, (uint8)SCU_PMCON0_PD_Pos, (uint8)SCU_PMCON0_PD_Msk, 1U);
   SCU_OpenPASSWD();
   SCU.PMCON0.reg = u8_loc_pmcon0;
   CMSIS_SEV();
   CMSIS_WFE();
   CMSIS_WFE();
   CMSIS_NOP();
   CMSIS_NOP();
   CMSIS_NOP();
   PLL_resetPllLockDetection();
   PLL_waitForPllLock();
   PLL_setNormalMode();
   PLL_setfSYStofPLL();
   CMSIS_Irq_En();
   SysTick_Init();
   WDT1_Init();
}
#endif

void SCU_EnterSlowMode(uint8 divider_scaled){
   uint8 u8_loc_pmcon0;
   uint16 divider[16] = {1, 2, 3, 4, 8, 16, 24, 32, 48, 64, 96, 128, 192, 256, 384, 512};
   uint32 reload_value;
   uint8 divider_scaled_local = divider_scaled;

   if(divider_scaled_local > (uint8)0x0F){
      divider_scaled_local = 0x0F;
   }

   Field_Mod8(&SCU.CMCON1.reg, (uint8)SCU_CMCON1_CLKREL_Pos, (uint8)SCU_CMCON1_CLKREL_Msk, divider_scaled_local);
   WDT1_Stop();
   WDT1_SOW_Service(3u);
   CMSIS_Irq_Dis();
   u8_loc_pmcon0 = SCU.PMCON0.reg;
   Field_Mod8(&u8_loc_pmcon0, (uint8)SCU_PMCON0_SD_Pos, (uint8)SCU_PMCON0_SD_Msk, 1U);
   SCU_OpenPASSWD();
   SCU.PMCON0.reg = u8_loc_pmcon0;
   SCU_ClosePASSWD();
   CMSIS_Irq_En();
   reload_value = ((uint32)SCU_FSYS /  divider[divider_scaled_local]) / SysTickFreq;
   SysTick_ReloadValue_Set(reload_value);
   CPU.SYSTICK_CS.bit.ENABLE = 1;
   WDT1_Init();
}

void SCU_ExitSlowMode(void){
   uint8 u8_loc_pmcon0;
   WDT1_Stop();
   WDT1_SOW_Service(3);
   CMSIS_Irq_Dis();
   u8_loc_pmcon0 = SCU.PMCON0.reg;
   Field_Mod8(&u8_loc_pmcon0, (uint8)SCU_PMCON0_SD_Pos, (uint8)SCU_PMCON0_SD_Msk, 0U);
   SCU_OpenPASSWD();
   SCU.PMCON0.reg = u8_loc_pmcon0;
   SCU_ClosePASSWD();
   CMSIS_Irq_En();
   SysTick_Init();
   WDT1_Init();
}

bool SCU_ChangeNVMProtection(uint32 mode, uint32 action){
   bool result;
   result = true;

   if(action == PROTECTION_CLEAR){
      if(mode == NVM_DATA_WRITE){
         result = USER_DFLASH_WR_PROT_DIS((uint16) SCU_DFLASH_WPROT_PW);
      }
      else if(mode == NVM_CODE_WRITE){
         result = USER_CFLASH_WR_PROT_DIS((uint16) SCU_CFLASH_WPROT_PW);
      }
      else if(mode == NVM_DATA_READ){
         result = USER_DFLASH_RD_PROT_DIS((uint16) SCU_DFLASH_WPROT_PW);
      }
      else if(mode == NVM_CODE_READ){
         result = USER_CFLASH_RD_PROT_DIS((uint16) SCU_CFLASH_WPROT_PW);
      }
      else{
      }
   }
   else{
      if(mode == NVM_DATA_WRITE){
         result = USER_DFLASH_WR_PROT_EN((uint16) SCU_DFLASH_WPROT_PW);
      }
      else if(mode == NVM_CODE_WRITE){
         result = USER_CFLASH_WR_PROT_EN((uint16) SCU_CFLASH_WPROT_PW);
      }
      else if(mode == NVM_DATA_READ){
         result = USER_DFLASH_RD_PROT_EN((uint16) SCU_DFLASH_WPROT_PW);
      }
      else if(mode == NVM_CODE_READ){
         result = USER_CFLASH_RD_PROT_EN((uint16) SCU_CFLASH_WPROT_PW);
      }
      else{}
   }
   return(result);
}

void SCU_WDT_Start(void){
   SCU_OpenPASSWD();
   Field_Mod8(&SCU.WDTCON.reg, (uint8)SCU_WDTCON_WDTEN_Pos, (uint8)SCU_WDTCON_WDTEN_Msk, 1u);
   SCU_ClosePASSWD();
}

void SCU_WDT_Stop(void){
   SCU_OpenPASSWD();
   Field_Mod8(&SCU.WDTCON.reg, (uint8)SCU_WDTCON_WDTEN_Pos, (uint8)SCU_WDTCON_WDTEN_Msk, 0u);
   SCU_ClosePASSWD();
}

void SCU_WDT_Service(void){
   Field_Mod8(&SCU.WDTCON.reg, (uint8)SCU_WDTCON_WDTRS_Pos, (uint8)SCU_WDTCON_WDTRS_Msk, 1u);
}

void SCU_Disable_Module(TScu_Mod Module){
   if(((uint8)Module & (uint8)0x10) == (uint8)0x10){
      SCU.PMCON2.reg |= (uint8) (1u << ((uint8)Module & (uint8)0x07));
   }
   else{
      SCU.PMCON1.reg |= (uint8) (1u << ((uint8)Module & (uint8)0x07));
   }
}

void SCU_Enable_Module(TScu_Mod Module){
   if(((uint8)Module & (uint8)0x10) == (uint8)0x10){
      SCU.PMCON2.reg &= (uint8) ~ (1u << ((uint8)Module & (uint8)0x07));
   }
   else{
      SCU.PMCON1.reg &= (uint8) ~ (1u << ((uint8)Module & (uint8)0x07));
   }
}
*/
void SCU_OpenPASSWD(void){
   Field_Wrt8all(&SCU.PASSWD.reg, PASSWD_Open);
}

void SCU_ClosePASSWD(void){
   Field_Wrt8all(&SCU.PASSWD.reg, PASSWD_Close);
}

void GPT1_IRQHandler(void){
   if(
         (uint8)1
      == (uint8)SCU.GPT12IEN.bit.T2IE
   ){
      if(
            (uint8)1
         == (uint8)SCU.GPT12IRC.bit.T2
      ){
         GPT1_T2_CALLBACK();
         GPT12E_T2_Int_Clr();
      }
   }
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

