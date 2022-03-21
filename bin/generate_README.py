#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Automatically generate a README for solved problems
# Usage:
#  python generate_README.py > README.md
from collections import namedtuple, defaultdict
import glob

class SourceFile:
  def __init__(self, path):
    toks = path.split('/')
    if len(toks) == 2:
      self.problem_id = toks[0]
      self.file = toks[1]
    else: # single file, no wrapper directory
      toks = path.split('.')
      self.problem_id = toks[0]
      self.file = toks

    self.extension = self.file.split('.')[-1]

  def __repr__(self) -> str:
    return f'<{self.problem_id}: {self.file}>'

def solution_to_table_row(name:str, source_files:dict) -> str:
  def get_file_link(ext:str, i:int, problem_id:str, file:str) -> str:
    ext_display_name = {
      'cpp': 'C++',
      'rb': 'Ruby',
      'py': 'Python',
      'go': 'Go',
      'js': 'JavaScript',
      'ts': 'TypeScript',
    }
    name = ext_display_name[ext]
    if i >= 1:
      name += f'({i+1})'
    return f'[{name}](https://github.com/donaldong/kattis/blob/main/solutions/{problem_id}/{file})'

  problem_link = f'https://open.kattis.com/problems/{name}'
  file_links = []
  for ext, files in source_files.items():
    files = sorted(files)
    for i in range(len(files)):
      file_links.append(get_file_link(ext, i, name, files[i]))

  return f'| [{name}]({problem_link}) | {",".join(sorted(file_links))} |'

files = glob.glob('../solutions/**/*')
source_files = [SourceFile(file.split('solutions/')[-1]) for file in files]
solutions = defaultdict(lambda: defaultdict(lambda: []))
for file in source_files:
  if not file.extension in ['cpp', 'rb', 'py', 'go', 'js', 'ts']:
    continue
  solutions[file.problem_id][file.extension].append(file.file)

table_rows = "\n".join(sorted([
  solution_to_table_row(problem_id, source_files)
  for problem_id, source_files in solutions.items()
]))

print(f'''
### My Kattis Solutions
A collection of solutions since 2016, when I was a 2nd-year CS student in college. This could explain some weird
solutions you might find lol 😛

Number of solved problems in this repo: **{len(solutions)}**
| Problem | Solution |
| --- | ----------- |
{table_rows}
''')

