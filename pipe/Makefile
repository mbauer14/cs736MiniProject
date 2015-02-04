C=gcc
CFLAGS=-I. -lrt
DEPS = 
OBJ = runpipe.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

runpipe: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
