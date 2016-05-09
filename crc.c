//------------------------------------------------------------------------------
//
// Section Code
//
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//
// CRC16_Calc
//
//------------------------------------------------------------------------------
//!
//! @brief calculate CRC16
//!
//------------------------------------------------------------------------------
//!
//! This function calculates the CRC16 value according to f the standard
//! 16-BIT CRC CCITT polynomial G(x) = 1 + x^5 + x^12 + x^16
//!
//! <!------------------------------------------------------------------------->
//! @param[in] data pointer to data block
//! @param[in] length number of bytes
//! @param[in] initVal CRC16 initial value
//! <!------------------------------------------------------------------------->
//! @retVal crc16 crc
//------------------------------------------------------------------------------
#include "crc.h"
#ifdef __CRC16_TABLE__

UINT16 CRC16_Calc (UINT8* data, UINT16 length, UINT16 initVal)
{
 // init crc
 UINT16 crc = initVal;
 // iterate over all bytes
 while (length--)
 {
    // calc new crc
    crc = (crc >> 8) ^ CRC16_Table[(crc ^ *data++) & 0x00FF];
 }
 // return result
 return crc;
}
#else
// calculate CRC16 without table
UINT16 CRC16_Calc (UINT8* data, UINT16 length, UINT16 initVal)
{
     // init crc
    UINT16 crc = initVal;
    // iterate over all bytes
    while(length--)
    {
        int bits = 8;
        UINT8 byte = *data++;
        // iterate over all bits per byte
        while(bits--)
            {
                if((byte & 1) ^ (crc & 1))
                    {
                        crc = (crc >> 1) ^ CRC16_POLYNOM;
                    }
                else
                crc >>= 1;
                byte >>= 1;
    }
 }
 // return result
 return crc;
}
#endif
//------------------------------------------------------------------------------
//
// CRC16_Check
//
//------------------------------------------------------------------------------
//!
//! @brief calculate & test CRC16
//!
//------------------------------------------------------------------------------
//!
//! This function checks a data block with attached CRC16
//!
//! <!------------------------------------------------------------------------->
//! @param[in] data pointer to data block
//! @param[in] length number of bytes (including CRC16)
//! @param[in] initVal CRC16 initial value
//! <!------------------------------------------------------------------------->
//! @retVal true CRC16 ok -> data block ok
//! @retVal false CRC16 failed -> data block corrupt
//------------------------------------------------------------------------------
bool CRC16_Check (UINT8* data, UINT16 length, UINT16 initVal)
{
 // calculate ones complement of CRC16
 UINT16 crc = ~CRC16_Calc(data, length, initVal);
 if( crc == CRC16_GOOD_VALUE) return true;
 return false;
}
//------------------------------------------------------------------------------
// end of file
//--------
