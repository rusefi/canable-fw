#ifndef _SLCAN_H
#define _SLCAN_H

/**
 * @brief  Parses CAN frame and generates SLCAN message
 * @return Number of bytes in generated SLCAN message
 */
int8_t slcan_parse_frame(uint8_t *buf, CAN_RxHeaderTypeDef *frame_header, uint8_t* frame_data);

/**
 * @brief  Parses SLCAN message and configures CAN peripheral accordingly or transmits CAN frame
 * @param  buf: Pointer to SLCAN message
 * @param  len: Number of bytes in SLCAN message
 * @return Zero if successful, other values indicate an error
 */
int8_t slcan_parse_str(uint8_t *buf, uint8_t len);

// maximum rx buffer len: extended CAN frame with timestamp 
#define SLCAN_MTU 30 // (sizeof("T1111222281122334455667788EA5F\r")+1)

#define SLCAN_STD_ID_LEN 3
#define SLCAN_EXT_ID_LEN 8

#endif // _SLCAN_H
