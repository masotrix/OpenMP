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
  
  int i,j,k;
  double a[NRA][NCA], b[NCA][NCB], c[NRA][NCB];

  for (i=0; i<NRA; i++)
    for (j=0; j<NCA; j++)
      a[i][j]=i+j;

  for (i=0; i<NCA; i++)
    for (j=0; j<NCB; j++)
      b[i][j]=i*j;

  for (i=0; i<NRA; i++)
    for (j=0; j<NCB; j++)
      c[i][j]=0;


  for (i=0; i<NRA; i++){
    for (j=0; j<NCB; j++)
      for (k=0; k<NCA; k++)
        c[i][j]+=a[i][k]*b[k][j];
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
