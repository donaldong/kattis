#!/usr/bin/env python
# -*- coding: utf-8 -*-
import optparse
import os

parser = optparse.OptionParser()
parser.add_option('--cpp', action="store_true", default=True)
options, args = parser.parse_args()

path = '/'.join(args)
os.system(f'mkdir -p {path}')
if options.cpp:
  os.system(f'cd {path} && cppg')
print(path)
