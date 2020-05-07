// ALGORITMO TABULACAO DE FUNCAO
// ESTE ALGORITMO TABULA A FUNCAO F(X)
// COM INTERVALOS DE 0.25 UNIDADES
//
// T10 [Declarar e inicializar variavel fx que guarda o resultado]
// FX <-- 0
//
// T20 [Declarar e inicializar variavel que guarda o valor minimo de x]
// XMIN <-- -5
//
// T30 [eclarar e inicializar variavel que guarda o valor maximo de x]
// XMAX <-- 5
//
// T40 [eclarar e inicializar variavel que guarda intervalo de incremento do ciclo]
// INTERVALO <-- 0.25
//
// T50 [Ciclo para percorrer os valores de x]
// FOR X = XMIN TO XMAX STEP 0.25
//
// 	T60 [Para situacoes em que x e maior ou igual a 1]
//	IF X >= 1 THEN
//
//    T70 [Calcular fx para situacoes em que x e maior ou igual a 1]
//	  FX <-- ( X + SQRT( SEN(X) * SEN(X) + 5) )
//
//    T80 [Imprimir o valor de fx]
//    PRINT( "FX = ", FX )
//
//   T90 [Para situacoes em que x e maior ou igual a 3 e x e menor que 1]
//   IF X >= 3 AND X < 1 THEN
//
//     T100 [Calcular fx para situacoes em que x e maior ou igual a 3 e menor que 1]
//     FX <-- ( X * X ) -( 7 * X ) + 8
//
//     T110 [Imprimir o valor de fx]
//     PRINT( "FX = ", FX )
//
//   T120 [Para situacoes em que x e menor do que -3]
//   IF X < -3 THEN
//   FX <-- 9 * X
//
//   T130 [Imprimir o valor de fx]
//   PRINT( "FX = ", FX )
//
// T140 [Terminar programa]
// EXIT[]

#import <stdio.h>
#import <math.h>

int main() {
	
	double fx = 0;
	
	double xmin = -5;
	double xmax = 5;
	
	double interval = 0.25;
	
	double x = 0;
	for ( x = xmin; x <= xmax; x = x + interval ) {
		
		if ( x >= 1 ) {
			
			fx = ( x + sqrt( sin( x ) * sin( x ) + 5 ) ) / ( 2 * exp( 10 ) * pow( x, ( ( 8 / 3 ) ) ) );
			
			printf( "\nx = %4.2f fx = %4.2f", x, fx );
			
			
			
		}
		
		
		if ( x >= -3 && x < 1 ) {
			
			
			fx = ( x * x ) - ( 7 * x ) + 8;
			
			printf( "\nx = %4.2f fx = %4.2f", x, fx );
	
		}
		
		if ( x < -3 ) {
			
			
			fx = 9 * x;
			
			printf( "\nx = %4.2f fx = %4.2f", x, fx );
			
			
			
			
		}
		
		
		
		
	}
	
	
	
	
	
	
}
