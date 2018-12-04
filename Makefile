#Compiler 
CC=gcc
#Compiler parameters
CFLAGS=-c -Wall

OBJ=pthreads.o queue.o

all: pthreads
	
%.o: %.c %.h 
	$(CC) $(CFLAGS) -c $<
	
pthreads: $(OBJ)
	$(CC) -O2 $(OBJ) -o pthreads 
	chmod 777 pthreads
	
clean: 
	rm -rf *o pthreads

