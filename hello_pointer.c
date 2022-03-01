#include <stdio.h>

int main() {
	int k;				// k is an integer
	unsigned char *c;	// * means a pointer, name c
						// unsigned char: is a character
	double d = 7.0;		// d is a floating number
	// read double by uchar pointer (1 byte)
	c = &d;	
	// c is the memory location (&) of d
	printf("the size of d is %d bytes \n", sizeof(d));
	for(int k=sizeof(d)-1;k>=0;k=k-1) { 
		// k = 7, 6, 5, 4, 3, 2, 1, 0
		// sizeof( ? ), ? size (in bytes) 
		printf("%X", *(c+k) );	
		// *(c+k) = c[k] is the value at c with k shift
		if(k % 4 == 0) printf(" ");
		// k % 4 = the remainder of k divided by 4
	}
	printf("\n");
	//return 0; // exit the main function and return 0
	
	unsigned int  *n;	// n is an uint pointer (4 bytes)
	double v[2] = {12.0, 48.0}; // v is a pointer 
	                             // and v[0] v[1] are set
	// = {6.0, 1.2e-4} => v[0]=6.0, v[1]=1.2x10^{-4}
	// read double by uint pointer (4 bytes)
	n = (unsigned int *) v;
	printf("the size of v is %d bytes\n", sizeof(v));
	for(k=sizeof(v)/sizeof(unsigned int)-1;k>=0;k--) {
		printf("%08X ", *(n+k));
	}

	printf("\n");
	for(k=0;k<4;k=k+2) {
		printf("v[%d] = %f %08X %08X\n", k, v[k/2], n[k+1], n[k]);
	}

	printf("\n");
	
	return 0;
}