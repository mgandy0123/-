#include <stdio.h>
#include <stdlib.h>	
#include <time.h>	
#include <math.h>	

int main() {
	int i, j, M = 10000000, N =20;
	double *c, x, p1, p2;
	time_t t1, t2;

	srand( time(NULL) );
	c = (double *) malloc(N*sizeof(double));
	x = 1.0*rand()/RAND_MAX;
	for(j=0;j<N;++j) {
		c[j] = 1.0*rand()/RAND_MAX;
	}
	t1 = clock();
	for(i=0;i<M;++i) {
		p1 = 0.0;
		for(j=0;j<N;++j) {
			p1 += c[j]*pow(x,j);
		}
	}
	t1 = clock()-t1;
	t2 = clock();
	for(i=0;i<M;++i) {
		p2 = c[N-1];	
		for(j=N-2;j>=0;--j) {
			p2 = p2*x+c[j];
		}
	}
	t2 = clock()-t2;
	printf("Method1: %d ms, Method2: %d ms\n", t1,t2);
	printf("Polynomial p(%f): Method1: %f Method2: %f,\n",x, p1, p2);
	printf("Their difference is %e,\n", p1-p2);
	printf("Where p(x)=\n");
	for(j=N-1;j>=0;j--) {
		printf("     %f * x^%d \n",c[j],j);
	}
	free(c);
	return 100;
}
