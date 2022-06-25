#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Automatically generate a README for solved problems
# Usage:
#  python generate_README.py > README.md
from collections import namedtuple, defaultdict
import glob, re

class SourceFile:
  valid_extensions = ['cpp', 'rb', 'py', 'go', 'js', 'ts']

  def __init__(self, path):
    toks = path.split('/')
    if len(toks) == 2:
      self.problem_id = toks[0]
      self.filename = toks[1]
    else: # single file, no wrapper directory
      toks = path.split('.')
      self.problem_id = toks[0]
      self.filename = toks

    self.extension = self.filename.split('.')[-1]
    self.tags = []
    self.difficulty_score = -1
    if self.extension in self.valid_extensions:
      file = open('../solutions/'+path, 'r')
      for line in file:
        match = re.match(r'.*\s+@tags\s+(.*)', line)
        if match:
          self.tags += re.split(r'\s*,\s*', match[1])
        match = re.match(r'.*\s+@difficulty\s+(.*)', line)
        if match:
          try:
            self.difficulty_score = int(match[1])
          except:
            self.difficulty_score = -1

  def __repr__(self) -> str:
    return f'<{self.problem_id}: {self.filename}>'

class Problem:
  def __init__(self, problem_id, solutions):
    self.problem_id = problem_id
    self.solutions = solutions
    self.difficulty_score = -1
    self.tags = set()
    for ext, files in self.solutions.items():
      for file in files:
         self.difficulty_score = max(self.difficulty_score, file.difficulty_score)
         self.tags = self.tags.union(file.tags)

  def __lt__(self, other):
    if self.difficulty_score == other.difficulty_score:
      return self.problem_id < other.problem_id
    a = self.difficulty_score
    b = other.difficulty_score
    if a < 0:
      a = 1e6
    if b < 0:
      b = 1e6
    return a < b

  def to_table_row(self) -> str:
    def get_file_link(ext:str, i:int, problem_id:str, file:SourceFile) -> str:
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
      return f'[{name}](https://github.com/donaldong/kattis/blob/main/solutions/{self.problem_id}/{file.filename})'

    def get_formated_difficulty() -> str:
      level = 'unknown'
      if 0<= self.difficulty_score < 1200:
        level = f'easy ({self.difficulty_score})'
      elif 1200 <= self.difficulty_score < 1600:
        level = f'medium ({self.difficulty_score})'
      elif self.difficulty_score >= 1600:
        level = f'hard ({self.difficulty_score})'
      return level

    problem_link = f'https://open.kattis.com/problems/{self.problem_id}'
    file_links = []
    for ext, files in self.solutions.items():
      for i in range(len(files)):
        file_links.append(get_file_link(ext, i, self.problem_id, files[i]))

    return f'| [{self.problem_id}]({problem_link}) | {get_formated_difficulty()} | {", ".join(sorted(self.tags))} | {", ".join(sorted(file_links))} |'

files = glob.glob('../solutions/**/*')
source_files = [SourceFile(file.split('solutions/')[-1]) for file in files]
problems = defaultdict(lambda: defaultdict(lambda: []))
for file in source_files:
  if not file.extension in SourceFile.valid_extensions:
    continue
  problems[file.problem_id][file.extension].append(file)

sorted_problems = sorted([
  Problem(problem_id, source_files)
  for problem_id, source_files in problems.items()
])
table_rows = "\n".join([problem.to_table_row() for problem in sorted_problems])
print(f'''
### My Kattis Solutions
A collection of solutions since 2016, when I was a 2nd-year CS student in college. This could explain some weird
solutions you might find lol 😛

Number of solved problems in this repo: **{len(problems)}**
| Problem | Difficulty | Tags | Solution |
| ------- | ---------- | ---- | -------- |
{table_rows}
''')

