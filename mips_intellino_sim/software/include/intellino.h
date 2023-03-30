#ifndef _INTELLINO_H
#define _INTELLINO_H
#include <stdint.h>

#define INTELLINO_VECTOR_LENGTH 128
#define INTELLINO_NCELL_COUNT 16

#define INTELLINO_TRAIN_ITER_COUNT (INTELLINO_VECTOR_LENGTH/4)

typedef struct intellino_result {
    uint8_t Category;
    uint16_t Distance;
} Intellino_Result;


void intellino_train (uint32_t* data_ptr, uint8_t cat);
Intellino_Result intellino_inference (uint32_t* data_ptr);


void intellino_forget (uint8_t nid);
void intellino_clear ();

#endif
