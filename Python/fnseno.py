#!/usr/bin/env python

resultado: float = None

posicion: int = None

valor = float(input("Ingrese el valor: "))
presicion = int(input("Ingrese el número de iteraciones: "))

resultado = valor

for i in (1, presicion):
    posicion = i * 2 + 1
