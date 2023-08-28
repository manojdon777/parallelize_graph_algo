CC=gcc
CFLAGS=-I.
DEPS = queue.h serialbfs.h generategraph.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# queue.o: queue.c queue.h
# 	$(CC) -c -o queue.o queue.c -I queue.h

# serialbfs.o: serialbfs.c serialbfs.h
# 	$(CC) -c -o serialbfs.o serialbfs.c -I serialbfs.h

# generategraph.o: generategraph.c generategraph.h
# 	$(CC) -c -o generategraph.o generategraph.c -I generategraph.h

app: main.o queue.o serialbfs.o generategraph.o
	$(CC) -o app main.o queue.o serialbfs.o generategraph.o

clean:
	rm -rf *.o app
run:
	./app $(vertices) $(edges)