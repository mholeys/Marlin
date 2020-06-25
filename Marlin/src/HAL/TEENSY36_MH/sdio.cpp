

// Teensy 3.6 SDIO interface for marlin
// Written by Matthew Holey
// Started 19/11/2019

#include "SdFat.h"

#include "../../inc/MarlinConfig.h" // Allow pins/pins.h to set density


#define CARD_V1_X                            0x00000000U
#define CARD_V2_X                            0x00000001U
#define CARD_SDSC                            0x00000000U
#define CARD_SDHC_SDXC                       0x00000001U

SdFatSdio sd;


bool SDIO_Init() {

    if (!sd.begin()) {
        // Failed to open SD card!
        SERIAL_ECHOLNPGM("Failed to setup SD Card!");
        sd.initErrorPrint("SdFatSdio begin() failed");
        return false;
    }
    SERIAL_ECHOLNPGM("Setup Sdio!");
    return true;
}

bool SDIO_ReadBlock(uint32_t blockAddress, uint8_t *data) {
    return sd.card()->readBlock(blockAddress, data);
}

bool SDIO_WriteBlock(uint32_t blockAddress, const uint8_t *data) {
    return sd.card()->writeBlock(blockAddress, data);
}