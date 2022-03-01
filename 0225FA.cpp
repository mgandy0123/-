#include <stdio.h>

int main() {

	int a,b,r;
	// a = bq + r
	r = 1;
	
	printf("Please input a b :");
	scanf("%d %d", &a, &b);
	
	while( r > 0 ) {
		// q = a / b;
		r = a % b;
		// a → b , b → r
		a = b;
		b = r;
		printf("(%d,%d)\n",a,b);
	}
	printf("gcd = %d\n",a);
	
	return 100 ;
}