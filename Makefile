#to complete

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: exec

%.o: %.c matrixHeader.h
	gcc -c $< -o $@ -lm

exec: $(OBJ)
	gcc $^ -o main.out -lm

clean:
	rm -f *.o