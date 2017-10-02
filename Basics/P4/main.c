#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
//#define DEBUG

#define NRA 30000
#define NCA 15
#define NCB 6

#ifndef DEBUG
#define msg(...)
#else
#define msg(...) printf(__VA_ARGS__)
#endif


int main() {
  
  int nthreads,tid,i,j,k,chunk;
  double a[NRA][NCA], b[NCA][NCB], c[NRA][NCB];

  chunk=1000;

  #pragma omp parallel shared(a,b,c,nthreads,chunk) private(tid,i,j,k)
  {

    tid = omp_get_thread_num();
    if (tid==0) {
      nthreads = omp_get_num_threads();
      msg("Starting matrix-mul example with: %d threads\n", nthreads);
      msg("Initializing matrices...\n");
    }

    #pragma omp for schedule(static,chunk)
    for (i=0; i<NRA; i++)
      for (j=0; j<NCA; j++)
        a[i][j]=i+j;

    #pragma omp for schedule(static,chunk)
    for (i=0; i<NCA; i++)
      for (j=0; j<NCB; j++)
        b[i][j]=i*j;

    #pragma omp for schedule(static,chunk)
    for (i=0; i<NRA; i++)
      for (j=0; j<NCB; j++)
        c[i][j]=0;

    msg("Thread %d starting matrix-mul...", tid);

    #pragma omp for schedule(dynamic,chunk)
    for (i=0; i<NRA; i++){
      msg("Thread=%d did row=%d\n", tid,i);
      for (j=0; j<NCB; j++)
        for (k=0; k<NCA; k++)
          c[i][j]+=a[i][k]*b[k][j];
    }
  }

  puts("------------------------------------------------------------");
  puts("Result Matrix:");
  for (i=0; i<NRA; i++){
    for (j=0; j<NCB; j++)
      printf("%08.0f   ", c[i][j]);
    puts("");
  }
  puts("------------------------------------------------------------");

  return 0;
}
