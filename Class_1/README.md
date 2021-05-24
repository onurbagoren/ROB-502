# Linux and the Bash Terminal
## Basic Commands
### Directories
 - `pwd` - (print working directory)
 - `cd` - (change directory)
 - `ls` - (list files)
Extraneous information:
 - `~` - home directory
 - `.` - current directory
 - `..` parent directory
 - `/` can separate directories or represents the "root" direcotry
### Files
 - `cat` - short for concatenate: outputs the contents of the file
 - `touch` - creates an empty file
 - `rm` - deletes a file, `rm -r` (recursive) deletes a whole folder
 - `mkdir` - creates a new directory
 - `mv` - moves a file or folder
 - `cp` - copies a file or a folder, `cp -r` is used to copy a folder that has content
### Output Redirection
Right arrows (`>`) can be used to sent the output of a program to a file, instead of the screen.
There are two types of output:
1. standard (stdout)
2. error (stderr)
    - If the error is to be redirected, `2>` is used instead of `>`

-`echo` - repears/outputs its own command line arguments
### Filtering Outputs
Linux keeps a disctionary of about 100,000 words in `/usr/share/dict/words`.
Its is useful to know how to filter some large files using bash commands.
- `wc` - counts the number of lines (`wc -l`) or words(`wc -w`)
- `head` - outputs the first 10 lines. `-n` flag allows the selection of the number of lines
- `tail` - outputs the last 10 lines.
- `grep` - searches and outputs lines that match a [regular expression](https://ryanstutorials.net/regular-expressions-tutorial/)
- `sort` - sorts the input lines alphabetically
- `uniq` - removes adjacent duplicate lines. Typically `sort` is used before this is used
- `tr -d` - deletes specific characters from its input
- `ps aux` - prints a list of all currently running processes
- `awk` - powerful but simple programming language that is great at working with data in columns.
### Processes
- `top` - opens a real time view of all the currently running processes.
- `kilall` - force quits all processes witha  certain name
- `kill` - quits a program witha  specific program ID (PID)
- `fg` - resumes a process that has been stopped by pressing Ctrl+Z.
- `sleep` - waits a given number of seconds
- `xargs` redirects its stdin to the arguments of another command
### Scripting
We can put everything in the commands line into a script file as well. The `.sh` extension is not important for bash scripts, but is a helpful convention.
A bash script can be run by entering `bash <FILE_NAME>.sh`
A "shebang" `#!` can be entered as the first line on a bash script to inform the compiler how to run the program, if pointed to the full path of the executable.
 - `which` - gives the full path ro a commands executable file.
 - `chmod` sets the file permissions/modes
```
#!/bin/bash
echo "Hello, world!"
echo "Your current directory is:"
pwd
```
#### Scripting - Variables
You can give command line arguments to your script when you run it.
 - `$#` is the number of arguments applied
 - `$0` is the "zero" argument, which is the name that the script was run with
 - `$1` to `$9` are the actual arguments given

Variables can also be assigned using the `=` operator. Don't use spaces with this assignment. Use the `$` operator in order to reference this variables value.
```
#!/bin/bash
one=1
echo $one # 1
another="a long string"
echo $another # a long string
echo '$another' # $another
echo "$another" # a long string
```

You can also assign the output of a command to a variable by using `$( command )`. i.e. `files=$( ls )`
The `$?` variable lets you get the "status" or "exit" code of the last command. This is useful to klnow if the last command succeeded or not. It is useful to assign this to a variable. the value will change between each command, but typically 0 means success.
#### Scripting - If Statements
Spaces are important in if statemts that use the square brackets
```
if [ condition ] ; then
    echo 'It was true';
elif [ consition ] ; then
    echo 'Something else was true';
else
    echo 'Nothing is true!';
fi
```
##### Operators
 - `A = B` - strings are equal
 - `A != B` - strings are not equal
 - `-z A` - tests if a string is zero length (empty)
 - `-n A` - tests if a string is not zero length
 - `A -eq B` - tests if numbers are equal
 - `A -ne B` - tests if numbers are not equal
 - `A -gt B` - tests if A is greater than B
 - `A -lt B` - tests if A is less than B
 - `-e A` - tests if a file or directory exists
 - `-f A` tests if a file exists
 - `-d A` tests if a directory exists
 - `! condition` is a negation of the statement/condition

The operators can be tried with the command `test`. i.e `test -f asd.txt; echo $? # returns 0 if the file exists, otherwise it does not`
The `&&` and `||` operators also exists with the consitions, but must be used outside of the condition brackets.
```
if [ 1 -eq 1 ] && [ "String" = "String" ] ; then
    echo 'True!'
fi
```

In addition, the `&&` and `||`commands can be run in standard bash commands. The `&&` commmand will execute the second command only if the first one is true (no error). For `||`, the second command with execute only if the first one returns an error. A semicolon `'` can be used to run both regardless.

### Scripting - For Loops
Some prerequisite knowledge
```
# parenthesis define an array
list=(Apples Bananas Cherries)

# this will echo only the first element
echo $list

# this gives the wwhole array
echo ${list[@]}

# this gives the second element
echo $list[1]}

# This can be written in a loop as such
for var in ${list[@]} ; do
    echo "Item: $var"
done

# or can be expressed as the items directly
for var in Apples Bananas Cherries ; do
    echo "Processing $var"
done

# for a range between numbers
for var in {1..10} ; do
    echo "Processing $var"
done

# You can't put it in a variable, though
list={1..10}
for var in $list ; do
    echo "Processing $var" # Processing {1..10}. This doesn't work!
done

# you can also go in high to low!
for var in {10..1} ; do
    echo "Processing $var"
done

# we can go by 2's or any other increment (may not work on Mac OS, no big deal!)
for var in {10..1..2} ; do
    echo "Processing $var"
done

# or go through the output lines of another program
for var in $(ls) ; do
    echo "Processing $var"
done

# or directly go through files based on a wildcard pattern
for var in *.txt ; do
    echo "Processing $var"
done
```