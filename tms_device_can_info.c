/*
 * device_can_info.c
 *
 *  Created on: 13 12 2022
 *      Author: Olegbom
 */

/* -------------------------------- INCLUDES -------------------------------- */

#include "tms_device_can_info.h"
#include <string.h>
#include <stdio.h>
#include "git_info/include/git_defines.h"
#include "reg_system.h"


/* ------------------------------ STATIC CONST ------------------------------ */

static const char* whoAmIData = "ProjectName: " __PROJECTNAME__ "\n"
                                "Git info:\n"
                                GIT_INFO "\n"
                                "Chip ID: ";

static const char* hexToChar = "0123456789ABCDEF";

/* ----------------------- STATIC FUCNTIONS PROTOTYPES ---------------------- */

static void canCliTxHex(CanCliTx_s* canCli, uint32_t word, uint8_t length);

/* -------------------------------- FUNCTIONS ------------------------------- */

void TmsDeviceWhoAmITransmitAnswer(txCliFunc func, uint8_t *dstCanData)
{
    CanCliTx_s canCli;

    canCliStart(&canCli, func, dstCanData);

    canCliTx(&canCli, (uint8_t *)whoAmIData, strlen(whoAmIData));

    canCliTxHex(&canCli, (systemREG1->DIEIDH >> 16) & 0xFFFF, 4);
    canCliTx(&canCli, (uint8_t *)"-", 1);
    canCliTxHex(&canCli, systemREG1->DIEIDH & 0xFFFF, 4);
    canCliTx(&canCli, (uint8_t *)"-", 1);
    canCliTxHex(&canCli, (systemREG1->DIEIDL >> 16) & 0xFFFF, 4);
    canCliTx(&canCli, (uint8_t *)"-", 1);
    canCliTxHex(&canCli, systemREG1->DIEIDL & 0xFFFF, 4);
    canCliTx(&canCli, (uint8_t *)"\n", 1);

    canCliEnd(&canCli);
}

/* ---------------------------- STATIC FUCNTIONS ---------------------------- */

static void canCliTxHex(CanCliTx_s* canCli, uint32_t word, uint8_t length)
{
    for(int i = length - 1; i >= 0; i--)
    {
        uint8_t byte = (uint8_t) hexToChar[ (word >> (4*i)) & 0xF ];
        canCliTx( canCli, &byte, 1 );
    }
}
