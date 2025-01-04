#to complete

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: exec

%.o: %.c matrixHeader.h
	gcc -c $< -o $@

exec: $(OBJ)
	gcc $^ -o main.out

clean:
	rm -f *.o