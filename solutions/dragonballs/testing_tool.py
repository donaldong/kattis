#!/usr/bin/env python3
#
# Testing tool for the Dragon Balls problem
#
# Usage:
#
#   python3 testing_tool.py [-f input_file] <program>
#
# If the -f parameter is not specified, sample 2 is used. Otherwise,
# an input file is needed. The file starts with the number of balls
# followed with the coordinates of the balls as pairs, one pair
# per line. For example:
#
# 2
# 10 20
# 100023 43

# You can compile and run your solution as follows.
# - You may have to replace 'python3' by just 'python'.
# - On Windows, you may have to to replace '/' by '\'.

# C++:
#   g++ solution.cpp
#   python3 testing_tool.py ./a.out

# Java
#   javac solution.java
#   python3 testing_tool.py java solution

# Python3
#   python3 testing_tool.py python3 ./solution.py

# The tool is provided as-is, and you should feel free to make
# whatever alterations or augmentations you like to it.
#
# The tool attempts to detect and report common errors, but it
# is not guaranteed that a program that passes the testing tool
# will be accepted.
#

import argparse
import subprocess
import sys
import traceback


def write(p, line):
    assert p.poll() is None, 'Program terminated early'
    print('Write: {}'.format(line), flush=True)
    p.stdin.write('{}\n'.format(line))
    p.stdin.flush()


def read(p):
    assert p.poll() is None, 'Program terminated early'
    line = p.stdout.readline().strip()
    assert line != '', 'Read empty line or closed output pipe. Make sure that your program started successfully.'
    print('Read: %s' % line, flush=True)
    return line


parser = argparse.ArgumentParser(description='Testing tool for the Dragon Balls problem')
parser.add_argument('-f', dest='inputfile', metavar='inputfile', default=None, type=argparse.FileType('r'),
                    help='Custom input file (defaults to sample 2)')
parser.add_argument('program', nargs='+', help='Your solution')

args = parser.parse_args()
steps = 0

if args.inputfile is not None:
    # Read the input file
    pts = []
    with args.inputfile as f:
        points = int(f.readline())
        assert points >= 1 and points <= 7, 'Number of points out of bounds (must be 1 <= points <= 7)'
        for i in range(0, points):
            x, y = map(int, f.readline().split())
            assert x >= 0 and x <= 10 ** 6, 'X point out of bounds (must be 0 <= x <= 10**6)'
            assert y >= 0 and y <= 10 ** 6, 'Y point out of bounds (must be 0 <= y <= 10**6)'
            pts.append((x, y))
        assert f.readline() == '', 'Extra data at end of input file'
else:
    points = 2
    pts = [(4, 3), (5,5)]

with subprocess.Popen(" ".join(args.program), shell=True, stdout=subprocess.PIPE, stdin=subprocess.PIPE,
                          universal_newlines=True) as p:
    try:
        write(p, points)
        while True:
            line = read(p)
            steps += 1
            x, y = map(int, line.split())
            assert x >= 0 and x <= 10 ** 6, 'X point out of bounds (must be 0 <= x <= 10**6)'
            assert y >= 0 and y <= 10 ** 6, 'Y point out of bounds (must be 0 <= x <= 10**6)'
            res = min((x - xp) ** 2 + (y - yp) ** 2 for (xp, yp) in pts)
            write(p, res)
            if res == 0:
                pts.remove((x, y))
                if len(pts) == 0:
                    assert p.stdout.readline() == '', 'Printed extra data after finding solution'
                    assert p.wait() == 0, 'Did not exit cleanly after finishing'
                    break
            if steps == 1000:
                sys.stdout.write('Program used too many guesses\n')
                p.kill()
                break
    except:
        traceback.print_exc()
    finally:
        sys.stdout.flush()
        sys.stderr.flush()
        sys.stdout.write('Guessed {} times, {} points remaining, exit code: {}\n'.format(steps, len(pts), p.wait()))
        sys.stdout.flush()
