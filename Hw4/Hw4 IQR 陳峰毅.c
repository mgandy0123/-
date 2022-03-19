#include <stdio.h>	// for printf function
#include <stdlib.h>	// for memory allocation
#include <time.h>	// for time calculation
#include <math.h>	// for sine and cosine functions
int main() {
	// Declare all the variables
	int k, m, n, N;
	double *x, *y, z, p;
	time_t t;

	// Input the number N
	printf("Input N: ");
	scanf("%d",&N);
	
	// Locate the memory for x and y;
	x = (double *) malloc(N*sizeof(double));
	y = (double *) malloc(N*sizeof(double));

	// Initial setting for x, for example, x[k] = 1.0*rand()/RAND_MAX
	srand( time(NULL) );
	for(k=0;k<N;++k){
		x[k] = y[k] = 1.0*rand()/RAND_MAX;
	}
		
	t = clock();
	quick_sort(y, 0, N);	
	t = clock()-t;
	
	if(N<10) {
		printf("x(before) \ty(after)\n");
		for(k=0;k<N;++k) {
			printf("%f\t%f\n",x[k],y[k]);
		}
	}	
	
	printf("\n");
	
	if(N % 4 == 0) { //Ex: N=4
		printf("Q1 is %f\n", (y[N/4]+y[N/4-1])/2);
		printf("Q3 is %f\n", (y[3*N/4]+y[3*N/4-1])/2);
		printf("The IQR is %f\n", (y[3*N/4]+y[3*N/4-1])/2-(y[N/4]+y[N/4-1])/2);
	} else if(N % 4 == 2) { //Ex: N=6
		printf("Q1 is %f\n", y[(N/2-1)/2]);
		printf("Q3 is %f\n", y[(N/2-1)/2+N/2]);
		printf("The IQR is %f\n", y[(N/2-1)/2+N/2]-y[(N/2-1)/2]);
	} else if(N % 4 == 1) { //Ex: N=5
		printf("Q1 is %f\n", (y[(N-1)/4]+y[(N-1)/4-1])/2);
		printf("Q3 is %f\n", (y[(3*N+1)/4]+y[(3*N+1)/4-1])/2);
		printf("The IQR is %f\n", (y[(3*N+1)/4]+y[(3*N+1)/4-1])/2-(y[(N-1)/4]+y[(N-1)/4-1])/2);
	} else { //Ex: N=7
		printf("Q1 is %f\n", y[((N-1)/2-1)/2]);
		printf("Q3 is %f\n", y[(N-1)/2+((N-1)/2-1)]);
		printf("The IQR is %f\n", y[(N-1)/2+((N-1)/2-1)/2]-y[((N-1)/2-1)]);
	}
	
	printf("\n");
	printf("Quick Sorting %d elements: %f s\n", N, 1.0*t/CLOCKS_PER_SEC);
	
	// free the memory located by x, y
	free(x);
	free(y);	
	
	return 100;
}

int quick_sort(double *x, int L, int R){
	
	// sorting x from L to R-1
	// put x[R-1] at the right location
	if(R<=L) return 100; // stop sorting
	
	double p, z;
	int k, n;
	p = x[R-1]; n = L;
	for(k=L;k<R-1;k++) {
		// put all elements smaller than p from the beginning
		if (x[k] < p) {
			z = x[n];
			x[n] = x[k];
			x[k] = z;
			n++;
		} // after swap x[0] < p
	} // after all swap, x[0]~x[n-1] < x[R-1] 
	z = x[n];
	x[n] = x[R-1];
	x[R-1] = z;
	// x[R-1] is at the correct location!
	quick_sort(x,L,n); // from L to n-1
	quick_sort(x,n+1,R); // from n+1 to R-1
	return 100;
}