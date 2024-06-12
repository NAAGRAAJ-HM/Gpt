#pragma once
/******************************************************************************/
/* File   : gpt12e_defines.hpp                                                */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define GPT12E_XML_VERSION                                               (20207)
#define GPT12E_CAPREL                                                   (0xFFF2)
#define GPT12E_CAPREL_TICK                                                 (0x0)
#define GPT12E_CAPREL_TIME                                                (5.50)
#define GPT12E_PISEL                                                    (0x885E)
#define GPT12E_PISEL_ISCAPIN                                               (0x2)
#define GPT12E_T2                                                       (0x4787)
#define GPT12E_T2CON                                                       (0x0)
#define GPT12E_T2CON_T2I_CAPTURE                                           (0x0)
#define GPT12E_T2CON_T2I_COUNTER                                           (0x0)
#define GPT12E_T2CON_T2I_GATED_TIMER_HIGH                                  (0x0)
#define GPT12E_T2CON_T2I_GATED_TIMER_LOW                                   (0x0)
#define GPT12E_T2CON_T2I_INC_EDGE                                          (0x0)
#define GPT12E_T2CON_T2I_INC_ROT                                           (0x0)
#define GPT12E_T2CON_T2I_RELOAD                                            (0x0)
#define GPT12E_T2CON_T2I_TIMER                                             (0x0)
#define GPT12E_T2_TICK                                                  (0xB879)
#define GPT12E_T2_TIME                                                    (0.00)
#define GPT12E_T3                                                       (0xFFFF)
#define GPT12E_T3CON                                                     (0x800)
#define GPT12E_T3CON_T3I_COUNTER                                           (0x0)
#define GPT12E_T3CON_T3I_GATED_TIMER_HIGH                                  (0x0)
#define GPT12E_T3CON_T3I_GATED_TIMER_LOW                                   (0x0)
#define GPT12E_T3CON_T3I_INC_EDGE                                          (0x0)
#define GPT12E_T3CON_T3I_INC_ROT                                           (0x0)
#define GPT12E_T3CON_T3I_TIMER                                             (0x0)
#define GPT12E_T3_TICK                                                     (0x1)
#define GPT12E_T3_TIME                                                    (0.00)
#define GPT12E_T4                                                       (0xD8F0)
#define GPT12E_T4CON                                                       (0x0)
#define GPT12E_T4CON_T4I_CAPTURE                                           (0x0)
#define GPT12E_T4CON_T4I_COUNTER                                           (0x0)
#define GPT12E_T4CON_T4I_GATED_TIMER_HIGH                                  (0x0)
#define GPT12E_T4CON_T4I_GATED_TIMER_LOW                                   (0x0)
#define GPT12E_T4CON_T4I_INC_EDGE                                          (0x0)
#define GPT12E_T4CON_T4I_INC_ROT                                           (0x0)
#define GPT12E_T4CON_T4I_RELOAD                                            (0x0)
#define GPT12E_T4CON_T4I_TIMER                                             (0x0)
#define GPT12E_T4_TICK                                                     (0x0)
#define GPT12E_T4_TIME                                                 (1000.00)
#define GPT12E_T5                                                         (0x24)
#define GPT12E_T5CON                                                       (0x0)
#define GPT12E_T5CON_T5I_COUNTER                                           (0x0)
#define GPT12E_T5CON_T5I_GATED_TIMER_HIGH                                  (0x0)
#define GPT12E_T5CON_T5I_GATED_TIMER_LOW                                   (0x0)
#define GPT12E_T5CON_T5I_TIMER                                             (0x0)
#define GPT12E_T5IN_SEL                                                    (0x0)
#define GPT12E_T5_TICK                                                     (0x0)
#define GPT12E_T5_TIME                                                (26200.00)
#define GPT12E_T6                                                       (0xFFFF)
#define GPT12E_T6CON                                                    (0x1000)
#define GPT12E_T6CON_T6I_COUNTER                                           (0x0)
#define GPT12E_T6CON_T6I_GATED_TIMER_HIGH                                  (0x0)
#define GPT12E_T6CON_T6I_GATED_TIMER_LOW                                   (0x0)
#define GPT12E_T6CON_T6I_TIMER                                             (0x0)
#define GPT12E_T6_TICK                                                     (0x1)
#define GPT12E_T6_TIME                                                    (0.00)
#define GPT12E_TEMP_CAPREL_SEL                                             (0x1)
#define GPT12E_TEMP_T2_PISEL                                               (0x0)
#define GPT12E_TEMP_T2_SEL                                                 (0x0)
#define GPT12E_TEMP_T3OUT                                                  (0x0)
#define GPT12E_TEMP_T3_PISEL                                               (0x0)
#define GPT12E_TEMP_T3_SEL                                                 (0x0)
#define GPT12E_TEMP_T4_PISEL                                               (0x0)
#define GPT12E_TEMP_T4_SEL                                                 (0x1)
#define GPT12E_TEMP_T5_SEL                                                 (0x1)
#define GPT12E_TEMP_T6OUT                                                  (0x0)
#define GPT12E_TEMP_T6_PISEL                                               (0x0)
#define GPT12E_TEMP_T6_SEL                                                 (0x0)
#define GPT1_BASE_CLK                                                      (0xA)
#define GPT1_T2_CLK                                                        (0xA)
#define GPT1_T3_CLK                                                        (0xA)
#define GPT1_T4_CLK                                                        (0xA)
#define GPT2_BASE_CLK                                                      (2.5)
#define GPT2_T5_CLK                                                        (2.5)
#define GPT2_T6_CLK                                                        (2.5)

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

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

