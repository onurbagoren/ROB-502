CFLAGS = -ggdb3 -std=c11 -Wall -Wunused-parameter -Wstrict-prototypes -Werror -Wextra -Wshadow
CFLAGS += -fsanitize=signed-integer-overflow -Wfloat-conversion
CFLAGS += -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable
# CFLAGS += -fsanitize=address -fsanitize=undefined

args: args.c
	gcc -o $@ $^ -std=c11

upper: upper.c
	gcc -o $@ $^ -std=c11

parity: parity.c
	gcc -o $@ $^ -std=c11 -g

read_file: read_file.c
	gcc -o $@ $^ -std=c11 -g
