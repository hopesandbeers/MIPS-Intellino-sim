all: dataset sim_c_128 sim_c_256 sim_c_512 sim_c_1024 sim_c_2048

## MNIST dataset conversion
dataset:
	make -C dataset_gen clean
	make -C dataset_gen

## Simulation for each cases
sim_c_128: sw_c_128
	sed "s/<0>/128/g" < sim/makefile.template > sim/makefile
	make clean -C sim && make -C sim
	mv sim/logs/wave.vcd sim_result/wave_c128.vcd
sim_c_256: sw_c_256
	sed "s/<0>/256/g" < sim/makefile.template > sim/makefile
	make clean -C sim && make -C sim
	mv sim/logs/wave.vcd sim_result/wave_c256.vcd
sim_c_512: sw_c_512
	sed "s/<0>/512/g" < sim/makefile.template > sim/makefile
	make clean -C sim && make -C sim
	mv sim/logs/wave.vcd sim_result/wave_c512.vcd
sim_c_1024: sw_c_1024
	sed "s/<0>/1024/g" < sim/makefile.template > sim/makefile
	make clean -C sim && make -C sim
	mv sim/logs/wave.vcd sim_result/wave_c1024.vcd
sim_c_2048: sw_c_2048
	sed "s/<0>/2048/g" < sim/makefile.template > sim/makefile
	make clean -C sim && make -C sim
	mv sim/logs/wave.vcd sim_result/wave_c2048.vcd
sim_as_128: sw_as_128
	sed "s/<0>/128/g" < sim/makefile.template > sim/makefile
	make clean -C sim && make -C sim
	mv sim/logs/wave.vcd sim_result/wave_as128.vcd
sim_as_256: sw_as_256
	sed "s/<0>/256/g" < sim/makefile.template > sim/makefile
	make clean -C sim && make -C sim
	mv sim/logs/wave.vcd sim_result/wave_as256.vcd
sim_as_512: sw_as_512
	sed "s/<0>/512/g" < sim/makefile.template > sim/makefile
	make clean -C sim && make -C sim
	mv sim/logs/wave.vcd sim_result/wave_as512.vcd
sim_as_1024: sw_as_1024
	sed "s/<0>/1024/g" < sim/makefile.template > sim/makefile
	make clean -C sim && make -C sim
	mv sim/logs/wave.vcd sim_result/wave_as1024.vcd
sim_as_2048: sw_as_2048
	sed "s/<0>/2048/g" < sim/makefile.template > sim/makefile
	make clean -C sim && make -C sim
	mv sim/logs/wave.vcd sim_result/wave_as2048.vcd

## Building software for each cases
sw_c_128: sw_c
	cp -f software/dataset/dataset_mnist128x16.c software/dataset_mnist.c
	cp -f software/intellino_c/intellino128.c software/intellino.c
	make -C software
sw_c_256: sw_c
	cp -f software/dataset/dataset_mnist256x16.c software/dataset_mnist.c
	cp -f software/intellino_c/intellino256.c software/intellino.c
	make -C software
sw_c_512: sw_c
	cp -f software/dataset/dataset_mnist512x16.c software/dataset_mnist.c
	cp -f software/intellino_c/intellino512.c software/intellino.c
	make -C software
sw_c_1024: sw_c
	cp -f software/dataset/dataset_mnist1024x16.c software/dataset_mnist.c
	cp -f software/intellino_c/intellino1024.c software/intellino.c
	make -C software
sw_c_2048: sw_c
	cp -f software/dataset/dataset_mnist2048x16.c software/dataset_mnist.c
	cp -f software/intellino_c/intellino2048.c software/intellino.c
	make -C software
sw_as_128: sw_as
	cp -f software/dataset/dataset_mnist128x16.c software/dataset_mnist.c
	cp -f software/intellino_as/intellino128.h software/include/intellino_as.h
	cp -f software/intellino_c/intellino128.c software/intellino.c
	make -C software
sw_as_256: sw_as
	cp -f software/dataset/dataset_mnist256x16.c software/dataset_mnist.c
	cp -f software/intellino_as/intellino256.h software/include/intellino_as.h
	cp -f software/intellino_c/intellino256.c software/intellino.c
	make -C software
sw_as_512: sw_as
	cp -f software/dataset/dataset_mnist512x16.c software/dataset_mnist.c
	cp -f software/intellino_as/intellino512.h software/include/intellino_as.h
	cp -f software/intellino_c/intellino512.c software/intellino.c
	make -C software
sw_as_1024: sw_as
	cp -f software/dataset/dataset_mnist1024x16.c software/dataset_mnist.c
	cp -f software/intellino_as/intellino1024.h software/include/intellino_as.h
	cp -f software/intellino_c/intellino1024.c software/intellino.c
	make -C software

sw_as_2048: sw_as
	cp -f software/dataset/dataset_mnist2048x16.c software/dataset_mnist.c
	cp -f software/intellino_as/intellino2048.h software/include/intellino_as.h
	cp -f software/intellino_c/intellino2048.c software/intellino.c
	make -C software

sw_c:
	cp -f software/main.c.c software/main.c
	cp -f software/makefile.c.m software/makefile
	cp -f software/intellino_c/intellino.h software/include/intellino.h

sw_as:
	cp -f software/main.as.c software/main.c
	cp -f software/makefile.as.m software/makefile


clean:
	# Remove dataset
	rm -f dataset_gen/dataset_mnist.c
	rm -rf dataset_gen/mnist_data
	# Remove generated source codes
	make -C software clean
	rm -f software/dataset_mnist.c
	rm -f software/intellino.c
	rm -f software/include/intellino_as.h
	rm -f software/main.c
	# Remove simulation makefile
	make -C sim clean
	rm -f sim/makefile
	# Remove simulation result
	rm -f sim_result/*.vcd
