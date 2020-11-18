IDIR =./include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=./build/obj
LDIR =../lib

LIBS=-lm

_DEPS = extreme_maths.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = add.o vector.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: ./src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

extreme_maths: $(OBJ)
	$(CC) -c -o $(ODIR)/main.o ./src/main.c $(CFLAGS)
	$(CC) -o ./bin/$@ $^ $(ODIR)/main.o $(CFLAGS) $(LIBS)

test: $(OBJ)
	$(CC) -c -o $(ODIR)/test.o ./src/test.c $(CFLAGS)
	$(CC) -o ./bin/$@ $^ $(ODIR)/test.o $(CFLAGS) $(LIBS)
	@./bin/test

shared:
	$(CC) -c -fPIC -o build/shared/add.o src/add.c $(CFLAGS)
	$(CC) -c -fPIC -o build/shared/vector.o src/vector.c $(CFLAGS)
	$(CC) -shared -o ./bin/libem.so build/shared/add.o build/shared/vector.o $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

run: 
	@./bin/extreme_maths
