all: sim_128 sim_256 sim_512 sim_1024 sim_2048
## Simulation for each cases
sim_128:
	sed "s/<0>/128/g" < sim/makefile.template > sim/makefile
	sed "s/<0>/128/g" < sim/sim_main.cpp.template > sim/sim_main.cpp
	make clean -C sim && make -C sim
	mv sim/logs/wave.vcd sim_result/wave_128.vcd
sim_256:
	sed "s/<0>/256/g" < sim/makefile.template > sim/makefile
	sed "s/<0>/256/g" < sim/sim_main.cpp.template > sim/sim_main.cpp
	make clean -C sim && make -C sim
	mv sim/logs/wave.vcd sim_result/wave_256.vcd
sim_512:
	sed "s/<0>/512/g" < sim/makefile.template > sim/makefile
	sed "s/<0>/512/g" < sim/sim_main.cpp.template > sim/sim_main.cpp
	make clean -C sim && make -C sim
	mv sim/logs/wave.vcd sim_result/wave_512.vcd
sim_1024:
	sed "s/<0>/1024/g" < sim/makefile.template > sim/makefile
	sed "s/<0>/1024/g" < sim/sim_main.cpp.template > sim/sim_main.cpp
	make clean -C sim && make -C sim
	mv sim/logs/wave.vcd sim_result/wave_1024.vcd
sim_2048:
	sed "s/<0>/2048/g" < sim/makefile.template > sim/makefile
	sed "s/<0>/2048/g" < sim/sim_main.cpp.template > sim/sim_main.cpp
	make clean -C sim && make -C sim
	mv sim/logs/wave.vcd sim_result/wave_2048.vcd

clean:
	make -C sim clean
	# Remove generated sources
	rm -f sim/sim_main.cpp
	rm -f sim/makefile
	# Remove simulation result
	rm sim_result/*.vcd

