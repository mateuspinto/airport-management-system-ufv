# xAERO Airport System - TP1-AEDS1-UFV
![xAERO running ](https://i.imgur.com/VP99atn.png)
xAero is an airport system that can manipulate flights with time, which as option to insert new flight from interface and from file. Also, it has option to store all flights in a file to be read later.
# About used programming language

The present code was written in pure C.

# Okay, cool, but there is no executable. How can I run this?

To avoid compatible errors, no executable was distributed with this code, but you can make for you own.
You have two ways to do this:

## 1 - Optimal: Using Clang

If you don't have Clang installed or you're not sure about this, run those commands:

### On Ubuntu based distros
    sudo apt install clang
    
### On Arch based distros
    su
    pacman -Sy clang
After that, simple clone this repository, compile and run using these commands:

    git clone https://github.com/mateusps10/xAero_Airport_System-TP1-AEDS1-UFV
    make clang
    make run
   For more information about Clang, please visit they [homepage](https://clang.llvm.org/)
## 2 - Without installing anything (or almost this): Using GCC

### On Linux or MAC based systems
    git clone https://github.com/mateusps10/xAero_Airport_System-TP1-AEDS1-UFV
    make
    make run

### On Windows based systems
Download Clion or CodeBlocks, follow installation steps and run *main.c* from there
\
\
\
***IMPORTANT:** Note that you can download the zipfile instead of cloning the rep if you don't have git installed on your PC.*




# About data structs and why I chose them
All the code was written using chained lists for its efficiency with data not calculable, since the number of flights is uncertain.
# Complexity Analysis
Since the most expensive primary struct is a chained list, the complexity is **O(N)**.
# Who am I?
My name is **Mateus Pinto da Silva**, I'm a Brazilian redhead computer scientist (currently graduating), who loves to program in Python using Object-oriented Programming and to describe hardware in Verilog HDL. I'm a data science enthusiast, current intern of a Brazilian Enterprise called Cinnecta. I like to train models in TensorFlowAPI when I have nothing better to do, and if you check my github profile, you will see that I usually don't have nothing better to do in fact. I study on Federal University of Viçosa.

## About my trajectory with C
All that I learned from C language came from my university lessons of AEDS I and AEDS II (Algorithms and Data Structures) and obviously from standalone researchs that I made, especially in "*The C Programming Language*", by Brian W. Kernighan and Dennis M. Ritchie


> Written with [StackEdit](https://stackedit.io/).
