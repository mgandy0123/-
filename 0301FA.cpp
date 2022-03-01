#include <stdio.h>
#include <time.h>	
#include <math.h>

int main(){
	
	time_t t;
	unsigned int j, k, M = 1 << 28;
	double a = 0.5*M_PI-1e-9, r, b=M_PI, c, T;
	r = 1+1e-9;
	t = clock();
	for(k=0;k<M;k++) {
		a = sin(a)*r*r;
	}
	t = clock()-t;
	T = 1.0*t/CLOCKS_PER_SEC;
	printf("The final value a = %f\nTotal multiple time = %d\nTime when doing one time = %e\nHow many times per sec = %f\n",a,t,T/M,M/T);
	
	
}