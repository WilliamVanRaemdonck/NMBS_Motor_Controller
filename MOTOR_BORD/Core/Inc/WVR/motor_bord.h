/*
 * motor_bord.h
 *
 *  Created on: Oct 24, 2024
 *      Author: willi
 */

#ifndef INC_WVR_MOTOR_BORD_H_
#define INC_WVR_MOTOR_BORD_H_

void HandleStartStop(GPIO_PinState, GPIO_PinState *);

void ReadADCValue(uint32_t *);

void SetLevelLEDs(uint32_t *);

void SetMotorSpeedAndDirection_DC(uint8_t, GPIO_PinState, uint8_t);

void SetMotorSpeedAndDirection_3Phase(uint8_t , GPIO_PinState);


#endif /* INC_WVR_MOTOR_BORD_H_ */
