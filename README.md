# Fast-Walsh-Hadamard-Transform
The Walsh-Hadamard transform is a 2^m x 2^m matrix that transforms 2^m real or complex numbers into 2^m real or complex numbers.

One version is written in Python and accelerated with Numba

Usage:

  python Fast-Walsh-Hadamard-Transform.py m
  
the other version is written in C

Usage:

  c++ Fast-Walsh-Hadamard.c -o Fast-Walsh-Hadamard
  
  ./Fast-Walsh-Hadamard m
  
For large m (around 25) the C code is about twice faster than the Python code.
