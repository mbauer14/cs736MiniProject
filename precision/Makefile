C=gcc
CFLAGS=-I. -lrt
DEPS = 
OBJ = precision.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

precision: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
