#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
	time_t t;
	unsigned int k, M = 1 << 25;
	double a, x, y, T;
	
	srand( time(NULL) );
	
	t = clock();
	for(k=0;k<M;k++) {
		x = (double) rand() / (RAND_MAX + 1.0);
		y = (double) rand() / (RAND_MAX + 1.0);
		a = x * y;
	}
	
	t = clock()-t;
	T = 1.0*t/CLOCKS_PER_SEC;
	
	printf("Total multiple time = %d ms\n",t);
	printf("Cost %e secs (per multiple)\n",T/M);
	printf("Doing %f multiples (per sec)\n",M/T);
	
	return 100;
}