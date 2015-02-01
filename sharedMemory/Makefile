C=gcc
CFLAGS=-I. -lrt
DEPS = 
OBJ = sharedMemory.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sharedMemory: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
