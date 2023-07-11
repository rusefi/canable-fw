#ifndef _SLCAN_H
#define _SLCAN_H

int8_t slcan_parse_frame(uint8_t *buf, CAN_RxHeaderTypeDef *frame_header, uint8_t* frame_data);
int8_t slcan_parse_str(uint8_t *buf, uint8_t len);

/**
 * The maximum transfer unit (MTU),
 * i.e. the maximum number of bytes possible in one SLCAN message,
 * is the length of an extended CAN frame with timestamp:
 *
 *  sizeof("T1111222281122334455667788EA5F\r")+1
 */
#define SLCAN_MTU 30

#define SLCAN_STD_ID_LEN 3
#define SLCAN_EXT_ID_LEN 8

#endif // _SLCAN_H
