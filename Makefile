CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGETS = ej1 ej2 ej4 ej5 ej6 ej9 ej12 ej13

all: $(TARGETS)

%: %.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGETS)

.PHONY: all clean