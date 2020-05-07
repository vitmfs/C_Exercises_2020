// ALGORITMO TABULACAO DE FUNCAO

// ESTE ALGORITMO TABELA UMA FUNCAO E
// DETERMINA O NUMERO TOTAL DE VALORES
// ASSIM COMO A PERCENTAGEM DE VALORES 
// POSITIVOS E NEGATIVOS

// T10 [Declarar e inicializar contador de negativos]
// CONTA_NEGATIVOS <-- 0

// T20 [Declarar e inicializar contador de positivos]
// CONTA_POSITIVOS <-- 0

// T30 [Declarar e inicializar y]
// Y <-- 0
//
// T40 [Declarar e inicializar valor minimo de x]
// XMIN <-- 0
//
// T50 [Declarar e inicializar valor maximo de x]
// XMAX <-- 0

// T60 [Declarar e inicializar x]
// X <-- 0

// T70 [Declarar e inicializar intervalo]
// INTERVALO <-- 0.2

// T80 [Ciclo for para passar por valores de x]
// FOR X = XMIN TO XMAX STEP INTERVALO

//   T90 [Para casos em que x e menor que 4]
//   IF X < 4 THEN
//   
//     T100 [Calcular valor de y para casos onde x e menor que 4]
//     Y <-- LOG( EXP( X ) / (10 * X) )
//     
//     T110 [Escrever x e y]
//     PRINT(" X = ", X, " Y = ", Y)
//    
//     T120 [Se o x for menor que 0]
//     IF X < 0 THEN
//
//       T130 [Incrementar contador de negativos]
//       CONTA_NEGATIVOS = CONTA_NEGATIVOS + 1
//
//   T200 [Para casos onde x e maior ou igual a 4]
//   IF X > 4 THEN
//   
//     T 210 [Calcular y para valores de x maiores ou iguais a 4]
//     Y <-- ( X * X ) + ( 10 * X ) + 25
//
//     T220 [Escrever x e y]
//     PRINT(" X = ", X, " Y = ", Y)
//
//     T230 [Incrementar contador de positivos]
//     CONTA_POSITIVOS <-- CONTA_POSITIVOS + 1
//
// T240 [Calcular percentagem de negativos]
// PERCENTAGEM_NEGATIVOS <-- 100 * ( CONTA_NEGATIVOS / ( CONTA_NEGATIVOS + CONTA_POSITIVOS ) )
//
// T250 [Escrever percentagem de negativos]
// PRINT(" PERCENTAGEM DE NEGATIVOS = ", PERCENTAGEM_NEGATIVOS)
//
// T260 [Calcular percentagem de positivos]
// PERCENTAGEM_POSITIVOS <-- 100 * ( CONTA_POSITIVOS / ( CONTA_NEGATIVOS + CONTA_POSITIVOS ) )

// T270 [Escrever percentagem de positivos]
// PRINT(" PERCENTAGEM DE POSITIVOS = ", PERCENTAGEM_POSITIVOS)
//
// T280 [Calcular numero total]
// TOTAL_NUMEROS<-- CONTA_NEGATIVOS+ CONTA_POSITIVOS

// T290 [Escrever numero total]
// PRINT(" NUMERO TOTAL = ", TOTAL_NUMEROS)
//  
// T300 [Terminar Programa]
// EXIT
//   



#import <stdio.h>
#import <math.h>

int main() {
	
	int counterNegative = 0;
	int counterPositive = 0;
	
	double y = 0;
	
	
	double xmin = 2;
	double xmax = 6;
	 
	double x = 0;
	double interval = 0.2;
	
	for ( x = xmin; x <= xmax; x = x + interval ) {
		
		if ( x < 4 ) {
			
			y = log( exp( x ) / (10 * x ) );
			
			//printf( "\nx = %4.2f y = %4.2f");
			
			if ( x <= 0 ) {
				
				counterNegative++;
			}
			
			
		}
		
		
		if ( x >= 4 ) {
			
			y = ( x * x ) + ( 10 * x ) + 25;
			
			//printf( "\nx = %4.2f y = %4.2f");
			
			counterPositive++;
			
			
		}
	}
	
	double percentageOfNegativeValues = 100* ( counterNegative / ( counterNegative + counterPositive ) );
	
	double percentageOfPositiveValues = 100* ( counterPositive / ( counterNegative + counterPositive ) );
	
	//printf( "\nThe percentage of negative values is %4.2f", percentageOfNegativeValues );
	
	//printf( "\nThe percentage of positive values is %4.2f", percentageOfPositiveValues );
	
	//printf( "\nThe total of numbers  is %d", counterNegative + counterPositive );
	
	
	
	
} 
