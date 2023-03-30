GEN_SRC0 = ../software/dataset/dataset_mnist128x16.c
GEN_SRC1 = ../software/dataset/dataset_mnist256x16.c
GEN_SRC2 = ../software/dataset/dataset_mnist512x16.c
GEN_SRC3 = ../software/dataset/dataset_mnist1024x16.c
GEN_SRC4 = ../software/dataset/dataset_mnist2048x16.c

TARGET = $(GEN_SRC0) $(GEN_SRC1) $(GEN_SRC2) $(GEN_SRC3) $(GEN_SRC4) 

all: $(TARGET)

$(GEN_SRC0):
	. .venv/bin/activate
	python3 mnist_to_uint8.py 0 16
	cp dataset_mnist.c $(GEN_SRC0)
$(GEN_SRC1):
	. .venv/bin/activate
	python3 mnist_to_uint8.py 1 16
	cp dataset_mnist.c $(GEN_SRC1)
$(GEN_SRC2):
	. .venv/bin/activate
	python3 mnist_to_uint8.py 2 16
	cp dataset_mnist.c $(GEN_SRC2)
$(GEN_SRC3):
	. .venv/bin/activate
	python3 mnist_to_uint8.py 3 16
	cp dataset_mnist.c $(GEN_SRC3)
$(GEN_SRC4):
	. .venv/bin/activate
	python3 mnist_to_uint8.py 4 16
	cp dataset_mnist.c $(GEN_SRC4)

clean:
	rm $(TARGET)
