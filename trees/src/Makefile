CC=gcc
CFLAGS=-I.

IDIR=../include
ODIR=obj

_DEPS=tree.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o in_order.o insert.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
