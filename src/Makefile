# CC=gdb gcc
CC=gcc
CFLAGS=-I.
DEPS = queue.h serialbfs.h generategraph.h

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

app: main.o queue.o serialbfs.o generategraph.o
	$(CC) -o app main.o queue.o serialbfs.o generategraph.o

clean:
	rm -rf *.o app
run:
	./app $(vertices) $(edges)

runDebug:
	gdb app $(vertices) $(edges)