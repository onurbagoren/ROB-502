# Class 3: Arrays, ASCII, bytes, and GDB
## ASCII Representation
 - ASCII defines meanings for numbers from 0 to 127
 - This allows an ASCII character to take up only 7 bits (2^7 = 128)
   - Generally, the 8th bit is set to 0
 - `A` through `Z` are codes 65 to 90.
 - `a` through `z` are codes 97 to 122.
   - Difference between an upper and a lower case letter is always 32.

```
char letter_a = 'A';
char letter_a_ascii = 65;

printf("letter_a: %c\n", letter_a); // prints letter_a: a
printf("letter_a_ascii: %d\n", letter_a_ascii); // prints letter_a: 65
```

 - It is good practoce to express the difference between lower and upper letter by writing `'a' - 'A'` rather than 32 directly, so that the intent is known.
 - This is handy when using C define

```
#define TO_LOWERCASE ('a' - 'A')
#define TO_UPPERCASE ('A' - 'a')

/ we explicitly cast to char since C likes to make the addition of chars result in an integer
// which is too big to fit into the 8-bit character
char letter = (char)('z' + TO_UPPERCASE);
```

Other codes:
 - Codes `0-31` are control characters.
   - `10` is new line `\n`
   - `13` is carriage return `\r` 
   - `0` is the NULL terminator
   - `8` is backspace `\b`
 - Codes `32-47` are symbols: `space` and then `!"#$%&'()*+,-./`
 - Codes `48-57` are digits `0123456789`

## Bitwise Operators
### Simple introduction to bits
-  A bit has a value of 1 or 0
 - A byte is 8 bits
 - A word is two bytes.
 - A dword is two words.
```
0 1 0 0 0 1 1 1 1 0 0 0 0 1 1 1 0 1 1 1 0 1 0 0 0 1 1 1 1 0 0 0
||              |               |               |              ||
|+- bit 31      |               |               |       bit 0 -+|
|               |               |               |               |
+-- BYTE 3 -----+--- BYTE 2 ----+--- BYTE 1 ----+-- BYTE 0 -----+
|                               |                               |
+----------- WORD 1 ------------+----------- WORD 0 ------------+
|                                                               |
+--------------------------- DWORD -----------------------------+
```
### Hexadecimal Number and How they Relate to Bits
 - As it is difficult to express numbers in terms of bits (a combinations of 1s and 0s), hexadecimal numbers come in, which are base 16.
 - It takes 4 bits to represent the numbers from 0 to 15 (2^4 = 16 combinations)
   - This is the range of a single digit hexadecimal number (1,2,..,9,A,...,F)
   - This 4 bit representation, is called a nibble.
   - Two hexadecimal digits (or nibbles) can express a byte
   - i.e. `r` in ASCII is code 114, which can be represented as `01110010` in binary. This would the become `7 (0111) 2(0010)`; hence, written as `0x72`.

### Bitwide Operators
 - There are 6 bitwise operators:
    1. `&` - The AND operator
    2. `|` - The OR operator
    3. `^` - The XOR operator
    4. `~` - The Ones Complement or Inversion operator
    5. `>>` - The Right Shift operator
    6. `<<` - The Left Shift operator

#### 1. The `&` Operator
```
1 & 1 == 1
1 & 0 == 0
0 & 1 == 0
0 & 0 == 0
```
The use for this is to set up a mask to check the values of certain bits. If there is a byte that has a bit flag which plays a role in part of the program, the & operator and the masking value (which has the masking bit) can be used to check its location. As an example:
```
BYTE b = 50; // 00110010
BYTE mask = 0x10; // 00010000 in hexidecimal
if ( b & mask )
    print("Bit four is set")
else
    print("Bit four is not set")
```
The table for this looks like:
```
  00110010  - b
& 00010000  - & 0x10
----------    ------
  00010000  - result
```
#### 2. The `|` Operator
```
1   |   1   ==   1
1   |   0   ==   1
0   |   1   ==   1
0   |   0   ==   0
```
The use of this is to set a value in a bit. The OR operator will always return 1 for the set byte, so it is equivalent to the common getter that is used in OOP. As an example:
```
BYTE b = 50;
BYTE c = b | 0x04;
cout << "c = " << c << endl;
```
The calculation is as follows:
```
  00110010  - b
| 00000100  - | 0x04
----------
  00110110  - result
```
#### 3. The `^` Operator
```
1   ^   1   ==   0
1   ^   0   ==   1
0   ^   1   ==   1
0   ^   0   ==   0
```
Is used to toggle bits, meaning that you intentially change the value of the bit in the byte. This can be done by both the use of 1s and 0s, as seen in the following example:
```
BYTE b = 50;
cout << "b = " << b << endl;
b = b ^ 0x18;
cout << "b = " << b << endl;
b = b ^ 0x18;
cout << "b = " << b << endl;
```
The calculation:
```
  00110010  - b
^ 00011000  - ^ 0x18
----------
  00101010  - result (position 1 changed because the toggle bit 0 was different than the bit at the same position on the other byte)

  00101010  - b
^ 00011000  - ^ 0x18
----------
  00110010  - result
```
#### 4. The `~` Operator
The operator inverts the values of the bits in a byte.
```
BYTE b = 0x03;
00000011  - 0x03
11111100  - ~0x03  b

WORD w = 0x03;
0000000000000011  - 0x03
1111111111111100  - ~0x03  w
```

Another use is to use it the `&` operator to ensure that certain bits are set to zero. In the example, the to clear the fourth bit:
```
BYTE b = 50; // 00110010
BYTE c = b & ~0x10; // 00110010 & 11101111 = 00100010
```
The calculation:
```
  00110010  - b
& 11101111  - ~0x10
----------
  00100010  - result
```
#### 5. The `>>` and `<<` Operators
The right (`>>`) and left (`<<`) shift operators move the bits, the number of bit positions specific. The `>>` operator moves from high to low and `<<` operator moves from low to high.
```
00001100  - b
00110000  - b << 2
00000011  - b >> 2
```
### Bit Fields
Bit fields can be used to set up miniature structures in a byte, word or dword.
As an example for this, the efficient implementation of a date struct can use a bit field. See the following example:
```
struct date_struct {
    BYTE day   : 5,   // 1 to 31
         month : 4,   // 1 to 12
         year  : 14;  // 0 to 9999
    } date;
```
- 5 bits are used for the day (2^5 = 32, 31 < 32)
- 4 bits are used for the month (2^4 = 16, 12 < 16)
- 14 bits are used for the year (2^14 = 16384, 9999 < 16384)
This struct can be stored in 3 bytes and the 24th bit can be ignored, because 5+4+14 = 23.
```
|0 0 0 0 0 0 0 0|0 0 0 0 0 0 0 0|0 0 0 0 0 0 0 0|
  |                           |       |         |
  +------ year ---------------+ month +-- day --+
```
