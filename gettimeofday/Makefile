C=gcc
CFLAGS=-I.
DEPS = 
OBJ = gettimeofday.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

gettimeofday: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
