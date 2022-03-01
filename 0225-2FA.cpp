#include <stdio.h>

int gcd(int a, int b) {
		
	int r;
	r = a % b;
	if (r == 0) {
		return b;
	}
	else {
		return gcd(b, r);
	}
}

int main(){
	int a,b;
	printf("Please input a b :");
	scanf("%d %d", &a, &b);
	printf("gcd = %d\n",gcd(a,b));
	return 0;
}

