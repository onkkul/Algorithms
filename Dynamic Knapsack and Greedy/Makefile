# Enables debug messages while compiling
COMPILE_DEBUG=@

# Compile and Link flags, libraries
CC=$(CROSS_PREFIX)g++ -c
CFLAGS= -g -Wall 
LDFLAGS=
LIBS=

PROGS= hw4

all: $(PROGS) 

# Add all object files to be linked in sequence
APEX_OBJS:=GreedyCoins_2A.o GreedyCoins_2B.o GreedyCoins_2D.o Dynamic_Knapsack.o

hw4: $(APEX_OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(COMPILE_DEBUG)$(CC) $(CFLAGS) -c -o $@ $<
	$(COMPILE_DEBUG)echo "CC $<"

clean:
	rm -f *.o *.d *~ $(PROGS) 