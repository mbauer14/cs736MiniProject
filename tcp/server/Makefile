C=gcc
CFLAGS=-I. -lrt
DEPS = 
OBJ = server.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

server: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
