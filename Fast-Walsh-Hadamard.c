#include <iostream>
#include <stdio.h>
#include <math.h>

int main (int argc,char *argv[]) {
   int n_qbits;
   if (argc == 2) {
      n_qbits = atoi(argv[1]);
   }
  int N = pow(2,n_qbits);
  double* A = new double[N]; 
  for (int i = 0 ; i < N; i++) {
        A[i]=0;
      }
  A[0] =1.0; // Initialized to |000..00> 
  double* B = new double[N];  
  printf("Number of qubits: %d\n",n_qbits);
  printf("Number of states: %d\n",N);
  double isq2 = 1./sqrt(2);  
  for (int qbit = 0; qbit < n_qbits; qbit++) {
    for (int i = 0; i < N; ++i) {B[i] = 0;}
    for (int j = 0; j < N; ++j) {
      if (A[j] != 0) {
        int bit_parity=(j>>qbit)%2 ;
        if (bit_parity == 0) {
          B[j] += isq2*A[j];
          int set_bit = j | (1<<qbit);
          B[set_bit] += isq2*A[j];
        }
        else if (bit_parity == 1) {
          B[j] += -isq2*A[j];
          int clear_bit = j & ~(1<<qbit);
          B[clear_bit] += isq2*A[j];
        }
      }
    }
    for (int i = 0; i < N; ++i) {A[i] = B[i];}
  }
  for (int i = 0 ; i < 10; i++) {
    printf("i= %d B[i] %.5f:\n",i,B[i]);
  }
  for (int i = N -10 ; i < N; i++) {
    printf("i= %d  B[i] %.5f:\n",i,B[i]);
  }
  return 0;
}
