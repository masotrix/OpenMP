#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define DEBUG

#define N 5
#define B 2
int A[N][N];
#define MIN(x,y)  ((x) < (y) ? (x) : (y))
#ifndef DEBUG
#define msg(...)
#else
#define msg(...) printf(__VA_ARGS__)
#endif

void doIt(int ii, int jj, int kk){

  int i,j,k;
  int kinf, ksup, iinf, isup, jinf, jsup, chunk=20;

  iinf=ii*B; isup=MIN((ii+1)*B,N);
  jinf=jj*B; jsup=MIN((jj+1)*B,N);
  kinf=kk*B; ksup=MIN((kk+1)*B,N);
  for (k=kinf; k<ksup; k++)
    for (i=iinf; i<isup; i++)
      for (j=jinf; j<jsup; j++)
        A[i][j]--;
}


int main() {

  int ii,jj,kk,size=(N+B-1)/B;
 
  for (ii=0; ii<N; ii++){
    for (jj=0; jj<N; jj++){
      A[ii][jj]=2;
  }}
  
#pragma omp parallel for \
  shared(size,A) \
  private(ii,jj,kk) \
  schedule(static)

  for (kk=0; kk<size; kk++){
    for (ii=kk+1; ii<size; ii++){
      for (jj=kk+1; jj<size; jj++){
        doIt(ii,jj,kk);
      }
    }
  }
  
  for (ii=0; ii<N; ii++){
    for (jj=0; jj<N; jj++){
      msg("%d ", A[ii][jj]);
    }
    msg("\n");
  }
  

  return 0;
}
