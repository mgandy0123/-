#include <stdio.h> // include standard input/output library 標準輸入輸出函式庫
                   // for printf
#include <math.h>  // math library
                   // for sin(x) , M_PI
#include <time.h>  // time library
                   // for clock()

int main()  // define a function 
{
    /* Floating number is different from integer !
    *  That is, 2 →←(<==>) 2.0
    *  ctrl + click can open xxxx.h file
    *  fabs abs
    */
    time_t t1,t2;  // t1 t2 are time
    int i;         // i is an integer
    t1 = clock();  // record time
    
    for(i=1;i<=1000;i=i+1) { // for(initial condition; loop condition; excute every loop)
	    printf("Hello %d Fast Algorithm!\n",123); // output on screen \n is change line
	    printf("Hello %d Fast Algorithm!\n",3/2); // why is 1
		printf("Hello %f Fast Algorithm!\n",123.0); // 記得小數
	    printf("Hello %f Fast Algorithm!\n",3.0/2); // 1.5
	    printf("Hello %f Fast Algorithm!\n",3.0/2.0); // 1.5
	    printf("Hello %f sin(PI/6)!\n",sin(M_PI/6));
	}
	t2 = clock();
	printf("TIME: %f sec(s)\n", 1.0*(t2-t1)/CLOCKS_PER_SEC/1000);
	
	return 8787;   //return one integer for the function 
}

