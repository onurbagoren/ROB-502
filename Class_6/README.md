# Class 6: Linked Lists
#### Clicker Questions
1. `(0b11101101 >> 1) & 0x70 = 0x50 = 0b01010000`
2. `0x31 ^ 0x52 == 0x63`
3. `char msg[] = "taco cat"; msg[3] = '\0'; printf("%s", msg); // tac`
4. `sizeof("hello!"); // 7 strlen("hello!"); // 6`
5. `int vals[] = {5, 15, 25, 35}; printf("%ld", &vals[2] - &vals[0]); // 2`
6. `int vals[] = {5, 15, 25, 35}; printf("%ld", sizeof(vals)); // 16`

```
typedef struct collection {
    int a;
    int b;
    char *c;
} collection_t;

collection_t coll = {0};
coll.a = 10;
coll.b = 20;
coll.c = malloc(sizeof(*coll.c) * 64);

printf("%ld", sizeof(coll.c)); // 7
printf("%ld", sizeof(coll)); // 8

free(coll.c);
coll.c = NULL;
```
9. N
10. N
11. Y
12. N
13. N
14. N

## Linked Lists
- A linked list is a linear collection of elements, whose order is not given by their physical placement in memory. Instead, it is ordered by each element pointing to the next.
- Each node is independent in memory, so each one will need to be malloc'd and freed individually.
- For a doubly linked list, where the elements point to the next and the previous element, the pointers are to the next and previous.
- The list also needs to keep track of the start and the end nodes in order to crrectly traverse the list.
- We will implement the following functionalities:
  - `push_start`
  - `push_end`
  - `pop_start`, print when popping
  - `pop_end`, if nothing to pop, print an error to `stderr` and exit a non-zero status.
- Also will need to implement a mechanism to destroy the list to prevent memory leaking.
Ex:
```
Input:
push_start 1
push_start 2
pop_start
pop_start
Output:
2
1
```
```
Input:
push_start 1
push_start 2
pop_end
pop_end
Output:
1
2
```
