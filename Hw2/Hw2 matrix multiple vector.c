#include <stdio.h>
#include <stdlib.h>	
#include <time.h>	

int main() {
	int i, j, k, N;
	double **A, *x, *b;
	time_t t1, t2;

	for(k=0;k<=10;k++) {
		N = 10000 + 1000*k;
		printf("When N = %d\n",N);
		x = (double *) malloc(N*sizeof(double));
		b = (double *) malloc(N*sizeof(double));	
		A = (double **) malloc(N*sizeof(double*));
		
		for(i=0;i<N;++i) {
			A[i] = (double *) malloc(N*sizeof(double));
		}
		t1 = clock();
		srand( time(NULL) );
		for(i=0;i<N;i++) {
			x[i] = 1.0*rand()/RAND_MAX;
			for(j=0;j<N;++j) {
				A[i][j] = 1.0*rand()/RAND_MAX;
			}
		}
		t1 = clock()-t1;
	
		t2 = clock();
		for(i=0;i<N;i++) {
			b[i] = 0.0;
			for(j=0;j<N;++j) {
				b[i] += A[i][j]*x[j];
			}
		}
		t2 = clock()-t2;
		printf("Generate random matrix: %d ms\n",t1);
		printf("Compute b=Ax: %d ms\n",t2);
	  free(x);
	  free(b);
		for(i=0;i<N;++i) {
			free(A[i]);
		}
	}
	return 0;
}