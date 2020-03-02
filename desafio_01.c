#import <stdio.h>

int main() {
	
	// Um
	// Abra um programa em C e grave-o com o seu numero_um.c 
	// (exemplo aluno 111 grava como 111_um.c)
	// Faça um programa em C que tabele uma função f(x)=x2 
	// para x inteiro pertencente ao intervalo [2, 9].
	printf( "Exercicio Um\n" );
	
	int xmin = 2;
	int xmax = 9;
	
	int i = -1;
	for ( i = xmin; i <= xmax; i++ ) {
		
		printf( "\nF( %2d )= %4d", i, ( i * i) );

	}
	
	
	
	// Dois
	// Grave-o agora como o seu numero_dois.c (exemplo aluno 111 grava como 111_dois.c).
	// Faça um programa em C que tabele uma função
	// x^2 para x pertence a [2,9]
	// 2x para x > 9
	// para x inteiro pertencente ao intervalo [2, 19].
	printf( "\n\nExercicio Dois\n" );
	
	xmin = 2;
	xmax = 19;
	
	int j = -1;
	for ( j = xmin; j <= xmax; j++ ) {
		
		if ( j <= 9 ) {
			
			printf( "\nF( %2d ) = %4d", j, ( j * j ) );

		} else {
			
			printf( "\nF( %2d ) = %4d", j, ( 2 * j ) );

		}
	}
	
	// Três
	// Grave-o agora como o seu numero_tres.c (exemplo aluno 111 grava como 111_tres.c).
	// Faça um programa em C que tabele uma função
	/// x^2 para x pertence a [2,9]
	// 2x para x > 9
	// para x inteiro pertencente ao intervalo [a, b], sendo a e b inteiros e positivos.
	printf( "\n\nExercicio Tres\n" );
	
	int a = -1;
	int b = -1;
	
	do {
		
		printf( "\nQual o limite inferior? ");
		scanf( " %d", &a );

	} while ( a < 0 );
	
	
	do {
		
		printf( "\nQual o limite superior? ");
		scanf( " %d", &b );

	} while ( b < 0 || b <= a );
	
	xmin = a;
	xmax = b;
	
	int k = -1;
	for ( k = xmin; k <= xmax; k++ ) {
		
		if ( k <= 9 ) {
			
			printf( "\nF( %2d ) = %4d", k, ( k * k ) );

		} else {
			
			printf( "\nF( %2d ) = %4d", k, ( 2 * k ) );

		}
	}
	
	
	
	// Quatro
	// Grave-o agora como o seu numero_quatro.c (exemplo aluno 111 grava como 111_quatro.c).
	// Faça um programa em C que tabele uma função
	// ( x - y )^2 para x pertence a [2,9]
	// ( 2x - y ) para x > 9
	// 	para x inteiro pertencente ao intervalo [a, b], sendo a e b inteiros e positivos. E y inteiro pertencente ao
	// intervalo [2, 4]
	printf( "\n\nExercicio Quatro\n" );
	
	a = -1;
	b = -1;
	
	do {
		
		printf( "\nQual o limite inferior? ");
		scanf( " %d", &a );

	} while ( a < 2 );
	
	
	do {
		
		printf( "\nQual o limite superior? ");
		scanf( " %d", &b );

	} while ( b < 0 || b <= a );
	
	xmin = a;
	xmax = b;
	
	int ymin = 2;
	int ymax = 4;
	
	int y = -1;
	
	int x = -1;
	for ( x = xmin; x <= xmax; x++ ) {
		
		for ( y = ymin; y <= ymax; y++ ) {
			
			if ( x <= 9 ) {
			
				printf( "\nF( %2d, %2d ) = %4d", x, y, ( ( x - y ) * ( x - y) ) ) ;
	
			} else {
				
				printf( "\nF( %2d, %2d ) = %4d", x, y, ( 2 * x - y ) );
	
			}

		}
		
		
		
		
	}
	
	// Cinco
	// Grave-o agora como o seu numero_cinco.c (exemplo aluno 111 grava como 111_cinco.c).
	// Faça um programa em C que tabele uma função
	/// ( x - y )^2 para x pertence a [2,9]
	// ( 2x - y ) para x > 9
	// para x inteiro pertencente ao intervalo [a, b], y inteiro pertencente ao intervalo [c, d], sendo a, b, c e d
	// inteiros e positivos.
	printf( "\n\nExercicio Cinco\n" );
	
	a = -1;
	b = -1;
	int c = -1;
	int d = -1;
	
	do {
		
		printf( "\nQual o limite inferior de x? ");
		scanf( " %d", &a );

	} while ( a < 2 );
	
	
	do {
		
		printf( "\nQual o limite superior de x? ");
		scanf( " %d", &b );

	} while ( b < 0 || b <= a );
	
	do {
		
		printf( "\nQual o limite inferior de y? ");
		scanf( " %d", &c );

	} while ( c < 0 );
	
	
	do {
		
		printf( "\nQual o limite superior de y? ");
		scanf( " %d", &d );

	} while ( d < 0 || d <= c );
	
	xmin = a;
	xmax = b;
	ymin = c;
	ymax = d;
	
	
	y = -1;
	x = -1;
	
	for ( x = xmin; x <= xmax; x++ ) {
		
		for ( y = ymin; y <= ymax; y++ ) {
			
			if ( x <= 9 ) {
			
				printf( "\nF( %2d, %2d ) = %4d", x, y, ( ( x - y ) * ( x - y) ) ) ;
	
			} else {
				
				printf( "\nF( %2d, %2d ) = %4d", x, y, ( 2 * x - y ) );
	
			}

		}
	}
	
	
	
	

	
	
	
	
	
	
	
	return 0;
}


