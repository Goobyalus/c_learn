CC = gcc
CFLAGS = -Wall

BINARIES = simple_fork

#$(BINARIES):$(addsuffix .c,$@)
#	echo "asd" $^
#	$(CC) $(CFLAGS) $^ -o $@


simple_fork:simple_fork.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm $(BINARIES)
