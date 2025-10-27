CC      := gcc
CFLAGS  := -std=c99 -Wall -Wextra -O2

.PHONY: all clean
all: fork1 fork2 myexec redirect task

fork1: fork1.c
	$(CC) $(CFLAGS) $< -o $@

fork2: fork2.c
	$(CC) $(CFLAGS) $< -o $@

myexec: myexec.c
	$(CC) $(CFLAGS) $< -o $@

redirect: redirect.c
	$(CC) $(CFLAGS) $< -o $@

task: task.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f fork1 fork2 myexec redirect task
