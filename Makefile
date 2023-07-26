CC=gcc
CFLAGS=-I.
DEPS = passgen.h
OBJ = passgen.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

passgen: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean install

clean:
	rm -f $(OBJ)

install:
	cp -i passgen /bin/passgen
