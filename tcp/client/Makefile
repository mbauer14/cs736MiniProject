C=gcc
CFLAGS=-I. -lrt
DEPS = 
OBJ = client.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

client: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
