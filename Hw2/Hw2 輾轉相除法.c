#include <stdio.h>
#include <time.h>	
#include <stdlib.h>	
#include <math.h>

int main() {
	unsigned int k, m, n, r, a, b, c, d, T, N=1 << 25;
	time_t t;
	srand( time(NULL) );
	m = (rand()/2)*(rand()/2)+1;
	n = (rand()/2)*(rand()/2)+1;
	printf("%d,%d\n",m,n);
	if (n>m) {
		t = m;
		m = n;
		n = t;
	}
	t = clock();
	for (k=1;k<N;++k) {
		a = m;
		b = n;
		c = 1;
		while (b != 0) {
			while((a % 2 == 0) && (b % 2 == 0)) {
				c = c * 2;
				a = a / 2;
				b = b / 2;
			}
			while((a % 2 == 0) && (b % 2 == 1)) {
				a = a / 2;
			}	
			while((a % 2 == 1) && (b % 2 == 0)) {
				b = b / 2;
			}	
			r = a % b;
			a = b;
			b = r;
		}
		a = a * c;
	}
	t = clock()-t;
	T = 1.0*t/CLOCKS_PER_SEC;
	//printf("GCD of %d and %d is %d\n",m,n,a);
	
	printf("GCD time : %d ms\n", t); 
	
}