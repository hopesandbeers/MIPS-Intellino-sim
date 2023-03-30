#include <stdint.h>
#include "calc.h"
#include "uart.h"
#include "counter.h"
#include "intellino.h"
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
        intellino_train(dataset_vec_train[0], dataset_cat_train[0]);
        intellino_train(dataset_vec_train[1], dataset_cat_train[1]);
        intellino_train(dataset_vec_train[2], dataset_cat_train[2]);
        intellino_train(dataset_vec_train[3], dataset_cat_train[3]);
        intellino_train(dataset_vec_train[4], dataset_cat_train[4]);
        intellino_train(dataset_vec_train[5], dataset_cat_train[5]);
        intellino_train(dataset_vec_train[6], dataset_cat_train[6]);
        intellino_train(dataset_vec_train[7], dataset_cat_train[7]);
        intellino_train(dataset_vec_train[8], dataset_cat_train[8]);
        intellino_train(dataset_vec_train[9], dataset_cat_train[9]);
        intellino_train(dataset_vec_train[10], dataset_cat_train[10]);
        intellino_train(dataset_vec_train[11], dataset_cat_train[11]);
        intellino_train(dataset_vec_train[12], dataset_cat_train[12]);
        intellino_train(dataset_vec_train[13], dataset_cat_train[13]);
        intellino_train(dataset_vec_train[14], dataset_cat_train[14]);
        intellino_train(dataset_vec_train[15], dataset_cat_train[15]);
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
