# Monty ByteCode Interpreter
Reads opcodes from a byte code file and performs operations on a stack.
<br>
## Getting Started
-------
### Clone the monty repository to your local directory.
````
$ git clone https: https://github.com/roundhousetally/monty.git
````
### Compile using gcc 4.8.4

`gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

## Usage:

`monty file`

file is the path to the file containing Monty byte code
### Opcodes implemented:
`push` pushes an element to the stack

`pall` prints all the values on the stack

`pint` prints the value at the top of the stack

`pop` removes the top element of the stack

`swap` swaps the top two elements of the stack

`add` adds the top two elements of the stack

`nop` does not do anything

`sub` subtracts the top element of the stack from the second top element

`div` divides the second top element of the stack by the top element

`mul` multiplies the second top element of stack by the top elem

`mod` mods the second top elem of the stack by the top elem

`pchar` prints the char at the top of the stack

`pstr` prints the string starting at the top of the stack

`# handles comments`

### Authors
----
[Sean Taylor](https://github.com/MadmanSilver/)

[Tahlia Roper](https://github.com/roundhousetally/)
