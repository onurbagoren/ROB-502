# Class 2: Using git to commit and submit code; expressing logic
## On Make files
The makefile is used for specifying how to make an executable. In this specific instance, we will be writing a file `helloworld.c` and the `makefile` will be used to make the file `helloworld`.
With make files, only tabs can be used.
```
helloworld: helloworld.c
    gcc -o helloworld helloworld.c -std=c11
```
First line says that the program `helloworld` has one source code file: `helloworld.c`. The second line says that to compile the code, `gcc` should be used. The `-o` flag tells gcc that the program will be called `helloworld`.

To make editing the make files easier, certain make variables can be used.
 - `$@` will be replaced with the name of the "target"
 - `$^` will be replaced with the list of dependencies.

