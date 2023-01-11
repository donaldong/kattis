#!/usr/bin/env python
# -*- coding: utf-8 -*-
import argparse
import os

parser = argparse.ArgumentParser()
parser.add_argument('prob_id')
parser.add_argument('-l', '--lang', choices=['cpp', 'py'], default='cpp')
options = parser.parse_args()

path = os.path.join('./', options.prob_id)
os.system(f'mkdir -p {path}')
if options.lang == 'cpp':
  os.system(f'cd {path} && cppg')
else:
  os.system(f'cd {path} && pyg')

print(path, f"a.{options.lang}")
