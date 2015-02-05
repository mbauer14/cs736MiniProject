C=gcc
CFLAGS=-I. -lrt -lm
DEPS = 
OBJ = accuracy.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

accuracy: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
