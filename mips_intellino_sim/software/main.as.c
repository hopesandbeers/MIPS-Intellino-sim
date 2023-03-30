#include <stdint.h>
#include "calc.h"
#include "uart.h"
#include "counter.h"
#include "intellino.h"
#include "intellino_as.h"
#include "dataset_mnist.c"

int main(void)
{

#ifdef DEBUG_UART
    uart_puts("Hello MIPS-Intellino"); uart_putlf();
#endif

    while (1) {
#ifdef DEBUG_UART
        uart_puts("Dataset Training ...");
#endif
        // Set base address
        INTELLINO_SETBASE(dataset_vec_train[0], dataset_cat_train);

        // Train 0
        INTELLINO_TRAIN(0);
        INTELLINO_TRAIN(1);
        INTELLINO_TRAIN(2);
        INTELLINO_TRAIN(3);
        INTELLINO_TRAIN(4);
        INTELLINO_TRAIN(5);
        INTELLINO_TRAIN(6);
        INTELLINO_TRAIN(7);
        INTELLINO_TRAIN(8);
        INTELLINO_TRAIN(9);
        INTELLINO_TRAIN(10);
        INTELLINO_TRAIN(11);
        INTELLINO_TRAIN(12);
        INTELLINO_TRAIN(13);
        INTELLINO_TRAIN(14);
        INTELLINO_TRAIN(15);


#ifdef DEBUG_UART
        uart_puts("Complete!"); uart_putlf();
#else
        uint8_t r = 0;
#endif
        while (1) {
#ifdef DEBUG_UART
            uart_puts("Select dataset to recognize (0x0-0xF, other to exit): 0x");
            uint32_t r = uart_geth();
#endif
            if (r > 15) 
                break;
            Intellino_Result result = intellino_inference(dataset_vec_inference[r]);
#ifdef DEBUG_UART
            uart_puts("Inference Result=====================");
            uart_puts("Category: "); uart_putd(result.Category); uart_putlf();
            uart_puts("Distance: "); uart_putd(result.Distance); uart_putlf();
            uart_puts("=====================================");
#else
            r++;
#endif
        }
        intellino_forget(0);
        intellino_clear();
    }
    return 0;
}
