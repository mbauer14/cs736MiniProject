C=gcc
CFLAGS=-I. -lrt
DEPS = 
OBJ = rdtsc.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

rdtsc: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
