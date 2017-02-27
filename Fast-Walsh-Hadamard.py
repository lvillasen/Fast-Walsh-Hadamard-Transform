#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Fast Walsh-Hadamard Transform
# Luis Villasenor
# lvillasen@gmail.com
# 2/27/2017 

import numpy as np
import numba

n_qbits = 16
A = np.zeros(2**n_qbits,dtype=np.complex_) # Set initial value of array A
A[0] =1

@numba.autojit
def set_bit(value, bit):
    return value | (1<<bit)

@numba.autojit
def clear_bit(value, bit):
    return value & ~(1<<bit)

@numba.autojit
def Hn(n_qbits,A):
	isq2 = 1/np.sqrt(2)
	for qbit in range(n_qbits):
		B = np.zeros(2**n_qbits,dtype=np.complex_)
		for j in range(2**n_qbits):
			bit_parity=(j>>qbit)%2
			B[j] += isq2*A[j]*(1-2*bit_parity)				
			B[set_bit(j,qbit)] += isq2*A[j]*(1-bit_parity)
			B[clear_bit(j,qbit)] += isq2*A[j] * bit_parity
		A = B
	return B

C = Hn(n_qbits,A)
print(C) # Transformed array

