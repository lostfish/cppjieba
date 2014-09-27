#!/usr/bin/env python
# encoding: utf-8

import os
import sys

dir_list = []
root_dir = '/home/jimmy/dataset/ClassFile/'
for dir_name in os.listdir(root_dir):
    dir_list.append(os.path.join(root_dir, dir_name))

def convert():
    for dir_path in dir_list:
        for file_name in os.listdir(dir_path):
            file_path = os.path.join(dir_path, file_name)
            new_file = os.path.join(dir_path, file_name+'.utf8')
            command = "iconv -f gbk -t utf8 %s > %s" % (file_path, new_file)
            os.system(command)

def generate_file_list():
    for dir_path in dir_list:
        for file_name in os.listdir(dir_path):
            if file_name.endswith('.utf8'):
                file_path = os.path.join(dir_path, file_name)
                print file_path
#convert()
generate_file_list()
