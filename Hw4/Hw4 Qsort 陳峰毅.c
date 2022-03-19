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
	// sorting x;  
	for(n=0;n<N;++n) {
		for(k=n+1;k<N;++k) {
			if (x[n] > x[k]) {
				// swap x[n] <-> x[k], then x[n] < x[k]
				z = x[n];
				x[n] = x[k];
				x[k] = z;
			}
		}
		// x[n] be the smallest
		/*for(k=0;k<N;++k); {
			printf("%f %f\n",x[n],y[k]);
		*/
	}
	t = clock() - t;

	// print y, x, and time
	printf("Bubble Sorting %d elements: %f s\n", N, 1.0*t/CLOCKS_PER_SEC);
	if(N<10) {
		printf("y(before) \tx(after)\n");
		for(k=0;k<N;++k) {
			printf("%f\t%f\n",y[k],x[k]);
		}
	}	
	
	// undo the sorting 
	for(k=0;k<N;++k){
		x[k] = y[k];
	}
	
	// Another sorting
	printf("------------------------\n");
	/*
	t = clock();

	// put x[N-1] at the right location
	p = x[N-1]; n = 0;
	for(k=0;k<N-1;k++) {
		// put all elements smaller than p from the beginning
		if (x[k] < p) {
			z = x[n];
			x[n] = x[k];
			x[k] = z;
			n++;
		} // after swap x[0] < p
		printf("k=%d:\n",k);
		for(m=0;m<N;++m) {
			printf("%f \t %f\n",x[m],y[m]);
		}
		printf("\n");
	} // after all swap, x[0]~x[n-1] < x[N-1] 
	z = x[n];
	x[n] = x[N-1];
	x[N-1] = z;
	// x[N-1] is at the correct location!
	*/
	
	t = clock();
	quick_sort(x, 0, N);	
	
	t = clock()-t;
	
	
	if(N<10) {
		printf("y \t\t x\n");
		for(k=0;k<N;++k) {
			printf("%f\t%f\n",x[k],y[k]);
		}
	}
	// sorting


	t = clock() - t;	
	


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