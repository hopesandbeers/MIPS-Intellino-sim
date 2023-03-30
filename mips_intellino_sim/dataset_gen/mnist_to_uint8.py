import sys
import numpy as np
import math
import cv2
import matplotlib.pyplot as plt

from torchvision import datasets
# Extract Train dataset
train_mnist = datasets.MNIST('./mnist_data/',
        download=True,
        train=True)


mode_id = 0
dataset_len = 16
if len(sys.argv) > 1:
    mode_id = int(sys.argv[1])
if len(sys.argv) > 2:
    dataset_len = int(sys.argv[2])

resize_modes = [(8, 16), (16, 16), (16, 32), (32, 32), (32, 64)]
names = ["128x16", "256x16", "512x16", "1024x16", "2048x16"]
word_cnt = int(resize_modes[mode_id][0] * resize_modes[mode_id][1] / 4)

lbl_cnt = [0,0,0,0,0,0,0,0,0,0]
total_cnt = 0;
idx = 0
train_data_extracted = []
train_lbl_extracted = []
while True:
    data, label = train_mnist[idx]
    idx = idx + 1
    if lbl_cnt[label] == 0:
        np_img = np.array(data)
        opencv_img = cv2.cvtColor(np_img, cv2.COLOR_RGB2BGR)
        opencv_img = cv2.cvtColor(opencv_img, cv2.COLOR_BGR2GRAY)
        resized_img = cv2.resize(opencv_img, dsize=resize_modes[mode_id])
        flatten_img = resized_img.reshape(1, -1).squeeze()
        hex_img = []
        for i in range(word_cnt):
            hex_data = (flatten_img[4*i] << 24) | (flatten_img[4*i+1] << 16) | (flatten_img[4*i+2] << 8) | flatten_img[4*i+3]
            hex_img.append(hex_data)
        train_data_extracted.append(hex_img)
        train_lbl_extracted.append(label)
        lbl_cnt[label] = 1;

        print(hex_img)
        total_cnt += 1
    if total_cnt == dataset_len:
        break
    if sum(lbl_cnt) == 10:
        lbl_cnt = [0,0,0,0,0,0,0,0,0,0]

# Extract Inference dataset
inference_mnist = datasets.MNIST('./mnist_data/',
        download=True,
        train=False)

inference_data_extracted = []
inference_lbl_extracted = []
lbl_cnt = [0,0,0,0,0,0,0,0,0,0]
total_cnt = 0;
idx = 0

while True:
    data, label = inference_mnist[idx]
    idx = idx + 1
    if lbl_cnt[label] == 0:
        np_img = np.array(data)
        opencv_img = cv2.cvtColor(np_img, cv2.COLOR_RGB2BGR)
        opencv_img = cv2.cvtColor(opencv_img, cv2.COLOR_BGR2GRAY)
        resized_img = cv2.resize(opencv_img, dsize=resize_modes[mode_id])
        flatten_img = resized_img.reshape(1, -1).squeeze()
        hex_img = []
        for i in range(word_cnt):
            hex_data = (flatten_img[4*i] << 24) | (flatten_img[4*i+1] << 16) | (flatten_img[4*i+2] << 8) | flatten_img[4*i+3]
            hex_img.append(hex_data)
        inference_data_extracted.append(hex_img)
        inference_lbl_extracted.append(label)
        lbl_cnt[label] = 1;

        print(hex_img)
        total_cnt += 1
    if total_cnt == dataset_len:
        break
    if sum(lbl_cnt) == 10:
        lbl_cnt = [0,0,0,0,0,0,0,0,0,0]

### Write extracted datasets to C file ###
f = open(f"dataset_mnist.c", "wt") # Open file

cols = resize_modes[mode_id][0] / 4
rows = resize_modes[mode_id][1]
# Write vector data to train
f.write(f"uint32_t dataset_vec_train[{dataset_len}][{word_cnt}] = {{\n")
for i in range(dataset_len):
    idx = 0;
    f.write("    {")
    while True:
        if idx == word_cnt:
            break
        if idx % cols == 0:
            f.write("\n        ")
        f.write(f"0x{train_data_extracted[i][idx]:08X}")
        if idx != word_cnt - 1:
            f.write(", ")
        idx += 1
    
    f.write("\n    }")
    if i != dataset_len - 1:
        f.write(",")
    f.write("\n")
f.write("};\n\n")

# Write category data to train
f.write(f"uint32_t dataset_cat_train[{dataset_len}] = {{\n")
f.write(f"    {train_lbl_extracted[0]}")
for i in range(1, dataset_len):
    f.write(f",\n    {train_lbl_extracted[i]}")
f.write("\n};\n\n")

# Write vector data to inference
f.write(f"uint32_t dataset_vec_inference[{dataset_len}][{word_cnt}] = {{\n")
for i in range(dataset_len):
    idx = 0;
    f.write("    {")
    while True:
        if idx == word_cnt:
            break
        if idx % cols == 0:
            f.write("\n        ")
        f.write(f"0x{inference_data_extracted[i][idx]:08X}")
        if idx != word_cnt - 1:
            f.write(", ")
        idx += 1
    
    f.write("\n    }")
    if i != dataset_len - 1:
        f.write(",")
    f.write("\n")
f.write("};\n\n")

# Write category data to train
f.write(f"uint32_t dataset_cat_inrefence[{dataset_len}] = {{\n")
f.write(f"    {inference_lbl_extracted[0]}")
for i in range(1, dataset_len):
    f.write(f",\n    {inference_lbl_extracted[i]}")
f.write("\n};\n\n")
f.close()
