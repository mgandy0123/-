#include <stdio.h>

int main() {
	int k;             // k is an integer
	unsigned char *c;  // unsigned means nonnegative * means a pointer, name c
	                   // unsigned char: is a character 
	double d = 6.0;    // d is a floating number
	// read double by uchar(unsigned char) pointer (1 byte)
	c = (unsigned char *) &d;   
	// c is the 'memory location'(&) of d
	printf("the size of d is %d bytes \n", sizeof(d));
	for(k=sizeof(d)-1;k>=0;k--) { 
	    // k = 7, 6, 5, ... , 0
	    // sizeof(x), x size (in bytes) 
		printf("%02X", c[k]);     
		// 02 means use two letter to describe
		// *(c+k) = c[k] is the value at c with k shift 從c往後面移k個 
		if(k % 4 == 0) printf(" ");
		// k % 4 = the remainder of k divided by 4
	}
	printf("\n");

	unsigned int  *n;  // n is an uint pointer , unsigned int: 4 characters (4 bytes)
	//double v[2] = {6.0, 1.2e-4};  // v is a pointer
	                              // and v[0] v[1] are set
	                              // v[0] = 6.0 , v[1] =  1.2 * 10^-4
	// 1.2e-4 = 1.2 * 10^-4
	// read double by uint pointer (4 bytes)
	double v[2] = {6.0, 12.0};
	n = (unsigned int *) v;
	printf("the size of v is %d bytes\n", sizeof(v));
	//for(k=sizeof(v)/sizeof(unsigned int)-1;k>=0;k--) {
	//	printf("v[%d] = %08X ", *(n+k));
	//}
	//unsigned long long *L = v;
	//printf("%d\n",sizeof(v));
	printf("\n"); 
	for(k=0;k<4;k=k+2) {
		printf("v[%d] = %f %08X %08X\n", k, n[k+1], n[k]);
	}
	printf("\n");
	
	return 0; // exit the main function 
}