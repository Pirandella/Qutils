CPP := g++
TARGET := qutils_test
CPPFLAGS := -I ../inc -lgtest -lm

TODIR := ./obj
TSDIR := ./src

IDIR := ../inc
SDIR := ../src

_TOBJ := gtest.o statistics_test.o
TOBJ := $(patsubst %,$(TODIR)/%,$(_TOBJ))

_DEPS := qu_statistics.h
DEPS := $(patsubst %,$(IDIR)/%,$(_DEPS))

_TCOBJ := qu_statistics.o
TCOBJ := $(patsubst %,$(TODIR)/%,$(_TCOBJ))

$(TODIR)/%.o: $(TSDIR)/%.cc
	$(CPP) -c $< -o $@ $(CPPFLAGS)

$(TODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CPP) -c $< -o $@ -I $(IDIR) --coverage

$(TARGET): $(TOBJ) $(TCOBJ)
	$(CPP) $^ -o $(TARGET) -I $(IDIR) -lgtest --coverage
	./run_test.sh $(TARGET)

.PHONY: clean test

test:
	./run_test.sh $(TARGET)

clean:
	rm -rf $(TARGET) ./$(TODIR)/*.info $(TODIR)/*.o $(TODIR)/*.gcda $(TODIR)/*.gcno ./html ./files/wirite_header_test.rl