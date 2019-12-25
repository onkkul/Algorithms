# Enables debug messages while compiling
COMPILE_DEBUG=@

# Compile and Link flags, libraries
CC=$(CROSS_PREFIX)g++
CFLAGS= -g -Wall
LDFLAGS=
LIBS=

PROGS= okulkar4

all: $(PROGS)

# Add all object files to be linked in sequence
hw6:= Main.o

okulkar4: $(hw6)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(COMPILE_DEBUG)$(CC) $(CFLAGS) -c -o $@ $<
	$(COMPILE_DEBUG)echo "CC $<"

clean:
	rm -f *.o *.d *~ $(PROGS)
