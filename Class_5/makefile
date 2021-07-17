CFLAGS = -ggdb3 -std=c11 -Wall -Wunused-parameter -Wstrict-prototypes -Werror -Wextra -Wshadow
CFLAGS += -fsanitize=signed-integer-overflow -Wfloat-conversion
CFLAGS += -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable
# CFLAGS += -fsanitize=address -fsanitize=undefined

class_5: class_5.c
	gcc -o $@ $^ -std=c11 -g

debugging_memory: debugging_memory.c
	gcc -o $@ $^ $(CFLAGS)

problem1: problem1.c
	gcc -o $@ $^ $(CFLAGS)
