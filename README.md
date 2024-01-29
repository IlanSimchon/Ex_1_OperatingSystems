# Linux, Libraries and Debugger

Written by: 
Ilan 
Maya Hayat

This exercise was divided into 4 main part:
## Part A : work with debugger
Work with debugger in which we had to create 2 different bugs (one done by trying to access a location that wasn't set in advance and the other one was an infinite loop). We had to run our code with and without debugger, wait for a core dummped and run the 'gdb' in order to find the exact location of the error.

## Part B: Work with a built-in Library
In the second part we had to create a program that receives 3 numbers that represent 3 different lengths of a triangle. The program had scan the lengths, and decide whether or not it is a Pythagorian triangle, if it is the program will calculate the 3 angles and display them, otherwise it would print error.

 ## Part C: Create a Dynamic Library
 In the third part we had to create a dynamic library. We first had to implement 4 different functions which can be found in the "libcodec.c" class. After having implemented those functions which create a code to encode and decode text as well as free the memeory at the end we had to create 2 last classes which read from either the Input.txt or Output.txt and Encode/Decode the text found in the file depends on the user's need.
 After having done that, we've created a makefile in order to create our Dynamic Library. One thing user must keep in mind is that they must run "export LD_LIBRARY_PATH=." .

 ## Part D: Using Pipes to Compress into Zip
