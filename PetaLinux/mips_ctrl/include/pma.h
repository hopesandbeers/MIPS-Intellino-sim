#ifndef _PMA_H_
#define _PMA_H_
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdint.h>
#include "debug.h"

typedef struct stPMAObj{
    void*       virt_addr;
    uint32_t    mem_alloc_size;
} PMAObj;

#define PMA_OPEN_MEMDEV_SUCCESS     0
#define PMA_OPEN_MEMDEV_FAIL        1


#define PMA_VADDR_MAPPING_SUCCESS   0
#define PMA_VADDR_MAPPING_FAIL      1

uint8_t pma_init();
uint8_t pma_map(PMAObj *pma_obj,  uint32_t paddr, uint32_t mem_size);
uint8_t pma_unmap(PMAObj* pma_obj);
uint8_t pma_deinit();
#endif
