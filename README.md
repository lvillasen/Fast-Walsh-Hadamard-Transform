# Fast-Walsh-Hadamard-Transform
The Walsh-Hadamard transform is a 2^m x 2^m matrix that transforms 2^m real or complex numbers into 2^m real or complex numbers.

One version is written in Python and accelerated with Numba

Usage:

    python Fast-Walsh-Hadamard-Transform.py m
  
other version is written in C

Usage:

    c++ Fast-Walsh-Hadamard.c -o Fast-Walsh-Hadamard
  
    ./Fast-Walsh-Hadamard m
  
the third version is written in C parallelized with openMP

Usage:

    c++ omp-Fast-Walsh-Hadamard.c -o omp-Fast-Walsh-Hadamard -fopenmp
  
    ./omp-Fast-Walsh-Hadamard m
