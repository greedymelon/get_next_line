# **get_next_line**
School project 1

## **Description**
This function take as an argument the file descriptor of the file to read and returns it line by line (When the end of the line is defined as a '\n' or the end of the file itself)
It can hendle different file descriptors at the same time.

## **How to get started:**
Copy the files in the folder where you main.c is, add the header in your main and compile the .c file with your main. This function can be enhanced by setting a buffer of your choice by adding a value to the MACRO BUFFER_SIZE while you compile it.
<br>Example:
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
```
Call the function with the file descriptor of the file you want to read.
The function will return an allocated string with the line including the '\n' at the end.
The returned string has to be free.

#### Output
The next line of the file.
NULL if an error is encountered or there are no more lines to read.


