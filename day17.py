import numpy as np
from parse import parse

with open("input_example.txt") as file:

    line = file.read()
    print(line)
    r = parse("target area: x={d}..{d}, y={d}..{d}", line)
    print(r)
