# Malloc/free, dynamic arrays and debugging errors
## Malloc/free
The command `malloc` stands for "memory allocation". This command gives the ability to allocate a certain amount of memory in the operating system. 
The command `free` is then used to free the assigned memory.
#### Important
- Make sure to use the memory allocated using `malloc`, if not used it can cause undefined behavior that can be very tough to debug and work with.
- After using `free` to free the assigned memory, make sure not to use the freed memory.
- If `free` isn't used, there will be issues of memory leakage and will cause the application to run out of memory.
- `stdlib.h` is required for malloc.
```
char *message = malloc(1024); // 1 kB of memory assigned
message[0] = 'H';
message[1] = 'e';
message[2] = '\0';

printf("%s", message);

free(message);
message = NULL; //set to null to remind that the old pointer is not used.
```
#### Alternatives to operating on raw bytes
When not operating on raw bytes, using `sizeof` in conjunction with `malloc` is useul.
This especially comes up when working across different architectures.
```
int n_bodies = 128;
rigid_body_t *bodies = malloc(sizeof(rigid_body_t) * n_bodies); // define the malloc based on the size of
                                                                // the data type
for (int i = 0; i < n_bodies; i++)
{
    create_random_body(&bodies[i]);
}
physics_calculation(bodies);
free(bodies);
bodies = NULL;
```
## Debugging memory errors
Running the following program:
```
#include <stdio.h>

int main(int argc, char **argv) {
    printf("%s\n", argv[1]);
    return 0;
}
```
with `valgrind ./debugging_memory.c`. Error returns:
```
==6832== Invalid read of size 1                                                                   
==6832==    at 0x483EF46: strlen (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-l
inux.so)                                                                                          
==6832==    by 0x527C5B3: puts (ioputs.c:35)                                                      
==6832==    by 0x10916E: main (debugging_memory.c:5)                                              
==6832==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
```
- It's crashing becuase is it reading 1 byte of memory that isn't valid
- The function that is doing this read is on line 5 with `strlen`
- Bad address itself if `0x0` or `NULL` which makes sense because `argv` is `NULL` terminated.
- The `NULL` terminator is read by `strlen` which returns the error.

***LEARN MORE ABOUT STACK VS HEAP AND RETURN TO THIS SUBJECT***

## Dynamic Arrays
Called vactor in C++, list in Python and ArrayList in Java. Expands the list as necessary.
If your program has to read in a certain number of ints, `int numbers[1000];` is sufficient.
If your program will be told the number of elements to read `int *numbers = malloc(sizeof(int) * number_of_ints)` works. 
Dynamic arrays keep track of the following information:
1. Number of elements in the array (size)
2. Number of elements the array space has to hold (capacity)
3. The pointer to the array itself (data)
These data types need to have dedicated method to append as it will need to check its capacity, size and reallocate the capacity as necessary.
For resizing, the `realloc` function is used:
```
// sizeof(*arr) instead of sizeof(int) is used so that
// if the type changes the code still works
int *arr = malloc(sizeof(*arr) * capacity);
...
...
// twice as big
capacity *= 2;
arr = realloc(arr, sizeof(*arr) * capacity);
...
...
free(arr);
```
It is important that the resizing follows a geometric progression. If one tries to resize every time a new element is added, the operation will be very slow. *Allocating memory is one of the slowest operations programs commonly perform!*