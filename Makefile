CC := gcc
TARGET := qutils
CFLAGS = -std=c99 -I $(IDIR) -Wall -g -lm

ODIR := ./obj
SDIR := ./src
IDIR := ./inc

_DEPS := qu_statistics.h
DEPS := $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ := qu_statistics.o
OBJ := $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	ar rcs $(TARGET).a $^

.PHONY: clean

clean:
	rm -rf $(ODIR)/* ./*.a
