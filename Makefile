CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
TARGETS = ej1 ej2 ej4 ej5 ej6 ej9 ej12 ej13 ej14 ej15 ej15completo ej16 ej17 ej19 ej21

all: $(TARGETS)

%: %.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGETS)

.PHONY: all clean