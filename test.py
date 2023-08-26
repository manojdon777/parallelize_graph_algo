import random
l = [i for i in range(15)]
new = []
for i in range(len(l)):
	index = random.randint(0,len(l) - 1)
	new.append(l[index])
	l.pop(index)
	print(l,"  |  ",new)
# print(l)