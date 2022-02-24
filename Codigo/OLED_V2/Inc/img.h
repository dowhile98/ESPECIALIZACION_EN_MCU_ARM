/*
 * img.h
 *
 *  Created on: 18 feb. 2022
 *      Author: Lenovo
 */

#ifndef IMG_H_
#define IMG_H_

#include <stdint.h>

 typedef struct {
     const uint8_t *data;
     uint16_t width;
     uint16_t height;
     uint8_t dataSize;
} tImage;

extern const tImage off;
extern const tImage STMiCON;
extern const tImage pajaro;

#endif /* IMG_H_ */
