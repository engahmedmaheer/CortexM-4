#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H


/*
 * MEMOREY_TO_MEMOREY
 * MEMOREY_TO_PERIPHERAL
 * PERIPHERAL_TO_MEMORY
 * PERIPHERAL_TO_PERIPHERAL
 */
#define  DMA1_MODE     MEMOREY_TO_MEMOREY
#define  DMA2_MODE     MEMOREY_TO_MEMOREY
/*
 *  Peripheral increment offset size
 *  PSIZE
 *  MAX_SEND -> 4 BYTE
 */
#define Peripheralincrement     P_SIZE

/*
 * BYTE
 * HALF_WORD
 * WORD
 */
#define BLOCK_SIZE              BYTE

/*
 * ENABLE
 * DISABLE
 */
#define MEMEORY_INCREMENT		ENABLE
#define PERIPHERAL_INCREMENT	ENABLE
#define CIRCULAR_MODE           DISABLE

/*
 * FREE_RUNNING
 * TRIGGER
 */
#define PERIPHERAL_FLOW_MODE	FREE_RUNNING




#define  MAX_CHANNEL     7











#endif
