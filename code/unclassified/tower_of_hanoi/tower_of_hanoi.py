#!/usr/bin/python3

# created by Flavian Feugueur
# flavian.feugueur@epitech.eu

# source, middle, and target represent the number of rod

import sys

def tower_hanoi(nb, source, target, middle):
	if nb is 1:
		print("move", nb, "from", source, "to", target)
	else:
		tower_hanoi(nb - 1, source, middle, target)
		print("move", nb, "from", source, "to", target)
		tower_hanoi(nb - 1, middle, target, source)

if len(sys.argv) != 2:
	print("Usage: python3 tower_of_hanoi.py <nb of discs>")
	sys.exit(1)
nb = int(sys.argv[1])
source = 1
middle = 2
target = 3
tower_hanoi(nb, source, target, middle)