
#ifndef RFID_H
#define	RFID_H

#include "hardware.h"

typedef struct // A struct used for passing the UID of a PICC.
{
  uint8	size;			// Number of uint8s in the UID. 4, 7 or 10.
  uint8	uiduint8[10];
  char  SerialNo[16];
  uint8	sak;			// The SAK (Select acknowledge) uint8 returned from the PICC after successful selection.
} tuid;

// declare RFID Global Variables available to other modules

extern tuid uid;            // structure containing tag id and type
extern char RFIDData[64];  // General RFID Data buffer as char so we can use string funcs

// declare RFID Global functions available to other modules

void  CloseRFID();                 // put RFID reader into sleep/power-save
uint8 ReadRFIDBlock(uint8 block);  // return 1 if block read and 0 if fail block is 64 bytes (sector is 4 x 16 bytes) Valid blocks are 0..15
uint8 ReadRFIDUID();               // public function encapsulates above to read just the uid


#endif	/* RFID_H */

