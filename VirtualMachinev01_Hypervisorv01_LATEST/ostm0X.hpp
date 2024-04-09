#ifndef _OSTM0X_H
#define _OSTM0X_H

#define cOSTM0_IRQ_NOT_ACTIVE  0
#define cOSTM0_IRQ_ACTIVE      1
#define OP_TIME_METHOD_OHDS 0x01U
#define OP_TIME_METHOD_CSTDELAY 0x00U
#define PalAbsConstantDelay		12U

extern uint8 aucRe1DatenString[10];


extern void OSTM0_FreeRunMode(void);
extern void OSTM0_IntervalMode(void);
extern void OSTM0_SetCompareValue(uint16);
extern void OSTM0_Start(void);
extern void OSTM0_Stop(void);
extern void OSTM0_wait_for_overflow(void);
extern void OSTM0_SetInterrupt(uint8 ucValue);
extern uint8 GetPalAbsConstantDelay(void);

#endif
