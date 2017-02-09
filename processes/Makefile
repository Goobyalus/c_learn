CC = gcc
CFLAGS = -Wall

BINARIES = simple_fork print_pid fork_multiple wait_no_children wait_null_status restart_children

#$(BINARIES):$(addsuffix .c,$@)
#	echo "asd" $^
#	$(CC) $(CFLAGS) $^ -o $@

all:$(BINARIES)

simple_fork:simple_fork.c
	$(CC) $(CFLAGS) $^ -o $@

print_pid:print_pid.c
	$(CC) $(CFLAGS) $^ -o $@

fork_multiple:fork_multiple.c print_pid
	$(CC) $(CFLAGS) $< -o $@

wait_no_children:wait_no_children.c
	$(CC) $(CFLAGS) $^ -o $@

wait_null_status:wait_null_status.c
	$(CC) $(CFLAGS) $^ -o $@

restart_children:restart_children.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm $(BINARIES)
