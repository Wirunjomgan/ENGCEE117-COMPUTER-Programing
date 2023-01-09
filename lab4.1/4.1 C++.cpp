#include <stdio.h>

void go( int **p, int *z ) {
	*p = z;
	printf("%d %p %p",**p,*p,p);
}

main() {
 	
	int *a, b = 10;
	int 	c = 20;
			
 	go(&a, &b ) ;
	printf( "%d %p %p", *a, a, &a );
 	go( &a, &c );
	printf( "%d %p %p", *a, a, &a );
	return 0 ;
}//end function
