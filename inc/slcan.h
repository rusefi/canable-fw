#ifndef _SLCAN_H
#define _SLCAN_H

int8_t slcan_parse_frame(uint8_t *buf, CAN_RxHeaderTypeDef *frame_header, uint8_t* frame_data);
int8_t slcan_parse_str(uint8_t *buf, uint8_t len);

// maximum rx buffer len: extended CAN frame with timestamp 
#define SLCAN_MTU 30 // (sizeof("T1111222281122334455667788EA5F\r")+1)

#define SLCAN_STD_ID_LEN 3
#define SLCAN_EXT_ID_LEN 8

/**
 * Serial CAN message types
 *
 * The SLCAN protocol was specified by Lawicel AB, Sweden,
 * for their CAN232 and CANUSB adapters.
 * Several products exist on the market,
 * which use the protocol and add their own extensions,
 * including CANtact, USBTIN and Mictronics USB-CAN.
 *
 * @attention
 * The following specification collisions exist:
 * 'A': between Lawicel CAN232 and Mictronics CAN-USB
 * 'm': between Lawicel CAN232 and CANtact
 * 'M': between Lawicel CAN232 and CANtact
 */
enum slcan_message_type {
    SLCAN_OPEN_CHANNEL = 'O',
    SLCAN_CLOSE_CHANNEL = 'C',

    SLCAN_GET_HARDWARE_VERSION = 'V',

    SLCAN_SET_BITRATE_CANONICAL = 'S',
    SLCAN_SET_BITRATE_ARBITRARY = 's',

    SLCAN_TRANSMIT_STANDARD = 't',
    SLCAN_TRANSMIT_EXTENDED = 'T',
    SLCAN_TRANSMIT_REQUEST_STANDARD = 'r',
    SLCAN_TRANSMIT_REQUEST_EXTENDED = 'R',

    SLCAN_FIFO_POLL_ALL = 'A',

    CANTACT_SET_MODE1 = 'm',
    CANTACT_SET_MODE2 = 'M',

    MICTRONICS_GET_ERROR = 'E',
};

#endif // _SLCAN_H
