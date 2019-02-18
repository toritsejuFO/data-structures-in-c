CC=gcc
CFLAGS=-I.

IDIR=../include
ODIR=obj

_DEPS=linked_list.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o print_list.o insert.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
