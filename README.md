# Simulation environment for MIPS-Intellino and standalone Intellino.
This repository is for providing the benchmark codes for the simulation of the MIPS-Intellino processor and standalone Intellino AI processor.

Note: The HDL codes of the MIPS-Intellino processor and the standalone Intellino AI processor are not provided.


## Prerequisites
Operating system: <b>Ubuntu 22.04 LTS</b>
> Both the standalone Linux and Windows Subsystems for Linux (WSL) works if the path is appropriately set.

<b>Python 3.10</b>

Simulation tool: <b>Verilator v5.009</b> [[Link]](https://verilator.org/guide/latest/install.html)

Compiler: <b>gcc-5.3.0 MIPS cross compiler</b> [[Link]](https://ftp.gnu.org/gnu/gcc/gcc-5.3.0/)
> You should manually build the compiler for MIPS.

The other prerequisites can be fullfilled by these codes:

``` bash
sudo apt install python3.10 python3-pip python3.10-venv
sudo apt install libgl1-mesa-glx
```

## Tutorial

First, clone the repository.

```bash
git clone https://github.com/hopesandbeers/MIPS-Intellino-sim.git
cd MIPS-Intellino-sim
```

### MIPS-Intellino simulation

```bash
cd mips_intellino_sim
```

#### Setting an environment for generation of MNIST-based dataset

As we construct the dataset by resizing the MNIST, following codes are required to generate the dataset.

```bash
cd dataset_gen
# Creating the virtualenv
python3 -m venv .venv
. .venv/bin/activate
# Install required Python packages
pip3 install numpy opencv-python torchvision matplotlib
deactivate
cd ..
```
#### Perform MIPS-Intellino simulation for both C library and optimized assembly codes.

The compilation, build, and simulation can be executed by the <b>Makefile</b> in the <b>mips_intellino_sim</b> directory.

The following code shows the methods:

```bash
make dataset          # Generate the dataset
make sw_[LIB]_[CFG]   # Compile the benchmark program and extract the hex file for simulation.
make sim_[LIB]_[CFG]  # Perform simulation for certain configurations.
```
The available settings are as follows:

<b>[LIB]</b>
> c:  C functions. <br> as: Optimized assembly codes.

<b>[CFG]</b>
> 128 <br> 256 <br> 512 <br> 1024 <br> 2048

The simulation results are stored as *.vcd dump in <b>sim_result</b> directory.

### standalone Intellino processor simulation

```bash
cd intellino_sim
```

The simulation of the standalone Intellino is simply executed by following codes:

```bash
make sim_[CFG]    # Perform simulation for certain configurations.
```

The simulation results are stored as *.vcd dump in <b>sim_result</b> directory.
