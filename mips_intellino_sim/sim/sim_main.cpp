#include <iostream>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"
#include <time.h>

#define SIM_TICK() \
    top->eval(); \
    tfp->dump(Verilated::time())
#define SIM_TIME(t) \
    Verilated::timeInc(t)

int main(int argc, char** argv, char** env) {
    // Prevent unused variable warnings
    if (false && argc && argv && env) {}

    // Construct a VerilatedContext to hold simulation time, etc.
    VerilatedContext* contextp = new VerilatedContext;

    // Create logs/ directory in case we have traces to put under it
    Verilated::mkdir("logs");
    // Set debug level, 0 is off, 9 is highest presently used
    // May be overridden by commandArgs argument parsing
    Verilated::debug(0);

    // Randomization reset policy
    // May be overridden by commandArgs argument parsing
    Verilated::randReset(2);

    // Verilator must compute traced signals
    Verilated::traceEverOn(true);

    // Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
    Verilated::commandArgs(argc, argv);

    // Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
    Vtop* top = new Vtop{contextp};

    // Construct the VCD dump object
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("logs/wave.vcd");

    //// Start simulation
    std::cout << "================================" << std::endl;
    std::cout << "======= Start Simulation =======" << std::endl;
    std::cout << "================================" << std::endl;

    // Input signal initialization and resetting design
    std::cout << "Reseting top module...." << std::endl;
    top->clk = 1; top->reset_n = 1;
    top->rx0 = 1;
    top->tck = 1; top->tms = 1; top->tdi = 1;
    SIM_TICK(); SIM_TIME(1);
    top->reset_n = 0;
    SIM_TICK(); SIM_TIME(9);
    top->clk = 0; top->reset_n = 1;
    SIM_TICK(); SIM_TIME(10);

    clock_t elapsed_time = clock();
    // Simulates for 500000 cycles
    for (int i = 0; i < 500000 ; ++i) {
        top->clk = !top->clk;
        SIM_TICK(); SIM_TIME(10);
    }
    /*
    while (!Verilated::gotFinish()) {
        // Nonblocking assignments
        top->clk = ~top->clk;
        SIM_TICK(); SIM_TIME(5);
        // Blocking assignments

        // Read outputs
        VL_PRINTF("[%" PRId64 "] clk=%x reset_n=%x \n",
                  Verilated::time(), top->clk, top->reset_n);
    }
    */

    //// Simulation ends
    elapsed_time = clock() - elapsed_time;

    std::cout << "================================" << std::endl;
    std::cout << "======= Simulation Ended =======" << std::endl;
    std::cout << "================================" << std::endl;
    std::cout << "Elapsed time: " << (double)elapsed_time / (CLOCKS_PER_SEC<<2) << std::endl;

    // Final model cleanup
    top->final();

    //// Coverage analysis
    //contextp->coveragep()->write("logs/coverage.dat");

    delete top;
    delete contextp;
    return 0;
}
