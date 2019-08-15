#!/usr/bin/env python

n: int = 1
pi: float = 1.0
factor: float = 0

n = int(input("Ingrese el número de iteraciones: "))

for x in range(1, n):
    factor = 4.0 * x * x / (2 * x - 1) / (2 * x + 1)
    pi *= factor

pi *= 2

print("PI: ", pi)
