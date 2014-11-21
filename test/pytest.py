#!env python3
import random

size = random.randint(10, 1000)
numCommands = random.randint(10, 10000)
numbers = list(random.sample(list(range(-2147483648, 2147483647)), random.randrange(size/2)))
random.shuffle(numbers)
state = []
infile = open('std_input', 'w')
outfile = open('std_output', 'w')

infile.write(str(size) + "\n")
infile.write(str(numCommands) + "\n");

for i in range(0, numCommands + 1):
	x = random.randrange(0, 5);
	num = random.choice(numbers)
#	if len(state) == 0 and x == 3:
#		x = random.choice([0, 1, 2, 4])
	if (x == 0):
		infile.write(str(x) + " " + str(num) + "\n")
		if (num in state):
			outfile.write(str(num) + " already present\n")
		else:
			if len(state) >= size:
				continue
			state.append(num)
			outfile.write(str(num) + " inserted\n")
	if (x == 1):
		infile.write(str(x) + " " + str(num) + "\n")
		if (num in state):
			outfile.write(str(num) + " found\n")
		else:
			outfile.write(str(num) + " not found\n")
	if (x == 2):
		infile.write(str(x) + "\n")
		if len(state) == 0:
			outfile.write("Cannot remove minimum item, no elements present\n")
		else:
			minimum = min(state)
			state.remove(minimum)
			outfile.write("Minimum key " + str(minimum) + " deleted\n")
	if (x == 3):
		if num not in state:
			continue
		infile.write(str(x) + " " + str(num) + "\n")
		state.remove(num)
		outfile.write(str(num) + " deleted\n")
	if (x == 4):
		infile.write(str(x) + "\n")
		state.sort()
		state.reverse()
		if len(state) > 0:
			outfile.write(" ".join([str(i) for i in reversed(state)]) + " \n")
		else:
			outfile.write("\n")
