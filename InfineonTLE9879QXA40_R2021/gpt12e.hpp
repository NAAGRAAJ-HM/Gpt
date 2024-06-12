#pragma once
/******************************************************************************/
/* File   : Template.hpp                                                      */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef enum{
      GPT1_fSYS_Div_4  = 1u
   ,  GPT1_fSYS_Div_8  = 0u
   ,  GPT1_fSYS_Div_16 = 3u
   ,  GPT1_fSYS_Div_32 = 2u
}TGPT1_Clk_Prescaler;

typedef enum{
      GPT12E_CCU6_CH0        = 0u
   ,  GPT12E_CCU6_CH1        = 1u
   ,  GPT12E_CCU6_CH2        = 2u
   ,  GPT12E_CCU6_T12_ZM     = 3u
   ,  GPT12E_CCU6_T12_PM     = 4u
   ,  GPT12E_CCU6_T12_CM_CH0 = 5u
   ,  GPT12E_CCU6_T12_CM_CH1 = 6u
   ,  GPT12E_CCU6_T12_CM_CH2 = 7u
   ,  GPT12E_CCU6_T13_PM     = 8u
   ,  GPT12E_CCU6_T13_ZM     = 9u
   ,  GPT12E_CCU6_T13_CM     = 10u
   ,  GPT12E_CCU6_ANY_CHx    = 11u
}TGPT12E_CCU6_SEL;

typedef enum{
      GPT12E_T2INA_P12  = 0u
   ,  GPT12E_T2INB_P14  = 1u
}TGPT12E_T2IN;

typedef enum{
      GPT12E_T2EUDA_P02 = 0u
   ,  GPT12E_T2EUDB_P24 = 1u
}TGPT12E_T2EUD;

typedef enum{
      GPT12E_T3INA_CCU6_CH0 = 0u
   ,  GPT12E_T3INB_CCU6_SEL = 1u
   ,  GPT12E_T3INC_P10      = 2u
   ,  GPT12E_T3IND_MON      = 3u
}TGPT12E_T3IN;

typedef enum{
      GPT12E_T3EUDA_P04     = 0u
   ,  GPT12E_T3EUDB_P25     = 1u
}TGPT12E_T3EUD;

typedef enum{
      GPT12E_T4INA_P00      = 0u
   ,  GPT12E_T4INB_CCU6_CH0 = 1u
   ,  GPT12E_T4INC_P01      = 2u
   ,  GPT12E_T4IND_CCU6_SEL = 3u
}TGPT12E_T4IN;

typedef enum{
      GPT12E_T4EUDA_P03     = 0u
   ,  GPT12E_T4EUDB_P10     = 1u
}TGPT12E_T4EUD;

typedef enum{
      GPT2_fSYS_Div_2  = 1u
   ,  GPT2_fSYS_Div_4  = 0u
   ,  GPT2_fSYS_Div_8  = 3u
   ,  GPT2_fSYS_Div_16 = 2u
}TGPT2_Clk_Prescaler;

typedef enum{
      GPT12E_T5INA_P03 = 0u
   ,  GPT12E_T5INB_P20 = 1u
}TGPT12E_T5IN;

typedef enum{
      GPT12E_T5EUDA_P14 = 0u
   ,  GPT12E_T5EUDB_P20 = 1u
}TGPT12E_T5EUD;

typedef enum{
      GPT12E_T6INA_P02 = 0u
   ,  GPT12E_T6INB_P13 = 1u
}TGPT12E_T6IN;

typedef enum{
      GPT12E_T6EUDA_P11 = 0u
   ,  GPT12E_T6EUDB_P13 = 1u
}TGPT12E_T6EUD;

typedef enum{
      GPT12E_CAPINA_P01           = 0u
   ,  GPT12E_CAPINB_P03           = 1u
   ,  GPT12E_CAPINC_T3_READ       = 2u
   ,  GPT12E_CAPIND_T2_T3_T4_READ = 3u
}TGPT12E_CAPIN;

typedef enum{
      GPT_Clk_Div_1   = 0
   ,  GPT_Clk_Div_2   = 1
   ,  GPT_Clk_Div_4   = 2
   ,  GPT_Clk_Div_8   = 3
   ,  GPT_Clk_Div_16  = 4
   ,  GPT_Clk_Div_32  = 5
   ,  GPT_Clk_Div_64  = 6
   ,  GPT_Clk_Div_128 = 7
}TGPT12E_Mode_Timer_Prescaler;

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
extern void GPT12E_Init                                                  (void);
extern bool GPT12E_T3_Interval_Timer_Setup           (uint32 timer_interval_us);
extern bool GPT12E_T6_Interval_Timer_Setup           (uint32 timer_interval_us);
extern void GPT12E_T2_Start                                              (void);
extern void GPT12E_T2_Int_Clr                                            (void);
extern void GPT1_T2_Handler                                              (void);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

