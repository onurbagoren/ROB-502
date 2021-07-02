#  Class 4: Addresses, Pointers
### Quick information about memory allocation
The `sizeof()` function will returns the number of bytes that a type uses:
- `char` and `uint8`: 1 byte
- `short` and `int16_t`: 2 bytes
- `int32_t` and `int`: 4 bytes
- `pointers` and `double`: 8 bytes
- If the variable is declared as an array, it will return the total number of bytes in that whole array.

## About Pointers
Arrays can be looked as pointers:
```
str[0]   == *str        // get the 0th element
str[1]   == *(str + 1)  // get the 1st element
str[-1]  == *(str - 1)  // get the -1st element
&str[0]  == str         // get the whole string
&str[1]  == str + 1     // get the string starting from the 1st element
&str[-1] == str - 1     // get the string starting from the -1st element
```
They are also useful when allowing a function to modify a variable you pass in.
```
void add_one( int a )
{
    a += 1;
}

void add_one2( int *a )
{
    *a += 1;
}

int main(void)
{
    int b = 1;

    add_one( b );
    printf( "%d\n", b );  // prints 1

    add_one2( &b ); / call the memory address of it
    printf( "%d\n", b ); // prints 2

    return 0;
}
```
## Addresses
On a computer, every piece of data lives somewhere in the computer’s memory and has an address, specifying that location. In C, we can get the address of a piece of data by prefixing the variable with `&`. 
We can also print out the address by using the %p specifier of printf and casting the type to void *, which is the type of a generic address.
```
int main(void) {
    int variable = 10;
    printf("%p\n", (void *)&variable); // does NOT print 10!
    return 0;
}
```


