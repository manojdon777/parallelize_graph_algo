import random
vertices = 100
edges = 2000 #  { <= max edges = n(n-1)/2 }
graph = []
all_possible_edges = []
for i in range(1, vertices + 1):
	for j in range(1, i):
		if i != j:
			all_possible_edges.append((i,j))
# print(all_possible_edges)

for i in range(edges):
	index = random.randint(0,len(all_possible_edges)-1)
	graph.append(all_possible_edges[index])
	all_possible_edges.pop(index)

f = open("input/in100.txt", "w")

for tup1 in graph:

	f.write(str(tup1[0]))
	f.write(" ")
	f.write(str(tup1[1]))
	f.write("\n")

	f.write(str(tup1[1]))
	f.write(" ")
	f.write(str(tup1[0]))
	f.write("\n")

f.close()