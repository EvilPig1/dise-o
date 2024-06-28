CC=g++
CFLAGS=-Wall -std=c++17 -O3
BINS=main 
OBJDIR=obj
SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=$(OBJDIR)/%.o)

all: clean felipe

felipe: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o main

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo " [CLN] Removing binary files and object files"
	@rm -f $(BINS) $(OBJ)

.PHONY: all clean
