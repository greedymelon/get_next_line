# **get_next_line**
School project 1

## **Description**
This function take as an argument the file descriptor of the file to read and returns it line by line, when the end of the line is define as a '\n' or the end of the file itself.
It can hendle different file descriptors at the same time.

## **How to get started:**
Copy the files in your program folder , add the header in your main and compile the .c file with your main. To make the function more you can set a buffer of  your choice adding -D BUFFER_SIZE= while you compile.
Example 
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
```
Call the function with the file descriptor of the file you want to read.
The function will return an allocated string with the line including the '\n' at the end.
The returned string has to be free.

#### Output
The next line of the file.
NULL if an error is encountered or there are no more lines to read.


