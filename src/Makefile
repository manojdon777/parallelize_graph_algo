CC=gcc
CFLAGS=-I.
DEPS = queue.h serialbfs.h generategraph.h inputcheck.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

app: main.o queue.o serialbfs.o generategraph.o inputcheck.o
	$(CC) -o app main.o queue.o serialbfs.o generategraph.o inputcheck.o

clean:
	rm -rf *.o app
run:
	./app $(vertices) $(edges)

runDebug:
	gdb app $(vertices) $(edges)