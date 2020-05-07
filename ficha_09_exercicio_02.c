#import <stdio.h>
#import <math.h>

int main() {
	
	double a = -5;
	double b = 5;
	double c = -5;
	double d = 5;
	
	double x = 0;
	double y = 0;
	
	double xmin = a;
	double xmax = b;
	
	double ymin = c;
	double ymax = d;
	
	int i = 0;
	double sum = 0;
	
	
	for ( x = xmin; x <= xmax; x = x + 0.25 )  {
		
		for ( y = ymin; y <= ymax; y = y + 0.25 ) {
			
			for ( i = 1; i <= 20; i++ ) {
				
				sum += sin( pow( x, 2 ) + pow( x, i ) * pow( y, i ) );
				
				printf( "\nx = %4.2f y = %4.2f sum = %4.2f ");
				
			}
			
			
		}
		
		
		
	}
}
