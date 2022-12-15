/*
 * tms_device_can_info.h
 *
 *  Created on: 13 12 2022
 *      Author: Olegbom
 */

#pragma once

/* -------------------------------- INCLUDES -------------------------------- */

#include "can_cli.h"

/* --------------------------------- DEFINES -------------------------------- */

#define TMS_DEVICE_CAN_WHO_AM_I_REQUEST_ID(dev_id)  ( (uint32_t)0x180100F1 | ((uint32_t)(dev_id) << 8) )
#define TMS_DEVICE_CAN_WHO_AM_I_ANSWER_ID(dev_id)   ( (uint32_t)0x1801F100 | ((uint32_t)(dev_id)     ) )

/* -------------------------------- TYPEDEFS -------------------------------- */


/* -------------------------- FUNCTIONS PROTOTYPES -------------------------- */

void TmsDeviceWhoAmITransmitAnswer(txCliFunc func, uint8_t *dstCanData);
