IDIR =./include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=./build/obj
LDIR =../lib

LIBS=-lm

_DEPS = extreme_maths.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = add.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: ./src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

extreme_maths: $(OBJ)
	$(CC) -o ./bin/$@ $^ $(CFLAGS) $(LIBS)
	$(CC) -shared -o ./bin/libem.so $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

run: 
	@./bin/extreme_maths