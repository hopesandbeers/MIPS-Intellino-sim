#include "pma.h"


int32_t mem_dev;

uint8_t pma_init() {
    // Open /dev/mem to know where the physical address mapped to virtual address
    mem_dev = open("/dev/mem", O_RDWR | O_SYNC);
    if (mem_dev == -1) {
        debug_printf("error number = %d, error str = %s\n", errno, strerror(errno));
        return PMA_OPEN_MEMDEV_FAIL;
    }
    return PMA_OPEN_MEMDEV_SUCCESS;
}

uint8_t pma_map(PMAObj *pmaobj,  uint32_t paddr, uint32_t mem_size) {
    /*
    uint32_t page_mask, page_size;

    page_size = sysconf(_SC_PAGESIZE);
    page_mask = (page_size - 1);
    debug_printf("Page Size: 0x%08X\n", page_size);
    debug_printf("Page Mask: 0x%08X\n", page_mask);

    pmaobj->mem_alloc_size = (((mem_size / page_size) + 1 ) * page_size);
    debug_printf("Memory Allocation Size: 0x%08X\n", pmaobj->mem_alloc_size);

    pmaobj->mem_ptr = mmap(NULL,
                            pmaobj->mem_alloc_size,
                            PROT_READ | PROT_WRITE,
                            MAP_SHARED,
                            mem_dev,
                            (paddr & ~page_mask));
                            */
    pmaobj->mem_alloc_size = mem_size;
    debug_printf("Memory Allocation Size: 0x%08X\n", mem_size);
    pmaobj->virt_addr = mmap(NULL,
                             mem_size,
                             PROT_READ | PROT_WRITE,
                             MAP_SHARED,
                             mem_dev,
                             paddr
                            );
    if (pmaobj->virt_addr == MAP_FAILED) {
        debug_printf("error number = %d, error str = %s\n", errno, strerror(errno));
        return PMA_VADDR_MAPPING_FAIL;
    }
    debug_printf("Virtual Address: 0x%08X\n", pmaobj->virt_addr);
    return PMA_VADDR_MAPPING_SUCCESS;
}

uint8_t pma_unmap(PMAObj* pmaobj) {
    int result = munmap(pmaobj->virt_addr, pmaobj->mem_alloc_size);
    if (result)
        debug_printf("error number = %d, error str = %s\n", errno, strerror(errno));
    return result;
}
uint8_t pma_deinit() {
    return close(mem_dev);
}
