#include <stdio.h>
#include <stdlib.h>	// for memory allocation
#include <time.h>	// for random seed

int main() {
	int i, j, N=20000;
	//double A[1000][1000], x[1000], b[1000];		// only for small integer!
	double **A, *x, *b;
	time_t t1, t2;

	x = (double *) malloc(N*sizeof(double));
	// locate N*sizeof(double) bytes in memory
	// x is pointer at the beginning
	b = (double *) malloc(N*sizeof(double));	
	A = (double **) malloc(N*sizeof(double*));
	// A[0], A[1], A[2], A[N-1] are pointers
	// *a    *b    *c    *d
	// A[0][1] = a[1]
	for(i=0;i<N;++i) {
		A[i] = (double *) malloc(N*sizeof(double));
	}
	
	t1 = clock();
	srand( time(NULL) );
	for(i=0;i<N;i++) {
		x[i] = 1.0*rand()/RAND_MAX;	
		// rand() generate 0~RAND_MAX-1
		// 1.0*rand()/RAND_MAX generate 0~1 random floating number
		for(j=0;j<N;++j) {
			A[i][j] = 1.0*rand()/RAND_MAX;
		}
	}
	t1 = clock()-t1;
	// Compute b = Ax
	t2 = clock();
	for(i=0;i<N;i++) {
		// sum(A_{i,j} x_j, j=0..N-1)
		b[i] = 0.0;
		for(j=0;j<N;++j) {
			b[i] += A[i][j]*x[j];
			// b[i] = b[i] + A[i][j]*x[j]
		}
	}
	t2 = clock()-t2;
	printf("Generate random matrix: %d ms\nCompute b=Ax: %d ms\n",t1,t2);
  	
	free(x);
  	free(b);
	for(i=0;i<N;++i) {
		free(A[i]);
	}
	free(A);
	return 100;
}