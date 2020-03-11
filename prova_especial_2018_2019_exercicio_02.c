#import<stdio.h>
#import<string.h>
#include<stdlib.h> 

// DECLARACAO DE FUNCOES
char* 	lerNome();
int 	lerEValidarUmInteiro( char mensagemParaOUtilizador[], int limiteInferior, int limiteSuperior );
int 	lerPeso();
int 	lerAltura();
int 	lerIdade();
int 	lerCaloriasIngeridas();
double 	numCaloriasIndicadoPorDia( int pesoCorporalEmKg, int alturaEmCm, int idadeEmAnos ) ;


// FUNCAO PRINCIPAL MAIN
int main() {
	
	// DECLARACAO E INICIALIZACAO DE VARIAVEIS
	// APOS LEITURA DO ENUNCIADO
	char alertaAte15PorCento[] 			= "ok";
	char alertaDe15A30PorCento[] 		= "Erro";
	char alertaMaisDe30PorCento[] 		= "Grave";
	
	char stringDeTerminacaoDoPrograma[] = "Fim";
	
	int limiteDeFaltaDeCalorias 		= 15;
	
	int numeroAtletasExcederamCalorias 	= 0;
	
	int numeroAtletasFaltaDeCalorias 	= 0;
	
	// DECLARACAO E INICIALIZACAO DE VARIAVEIS
	// QUE VAO GUARDAR OS VALORES TEMPORARIOS 
	// PARA CADA ATLETA
	char nomeDoAtleta[20];
	int pesoDoAtleta 		= -1;
	int alturaDoAtleta 		= -1;
	int idadeDoAtleta 		= -1;
	int caloriasIngeridas 	= -1;
	
	double caloriasRecomendadas 			= -1;
	double diferencaEntreCalsRecEIngeridas 	= -1;
	
	char alerta[10];
	
	
	// PRIMEIRA LEITURA DO PROGRAMA
	strcpy( nomeDoAtleta, lerNome() );

	// ENQUANTO NAO INSERIRMOS A STRING DE TERMINACAO "Fim" O PROGRAMA CONTINUA
	while ( strcmp( nomeDoAtleta, stringDeTerminacaoDoPrograma) != 0 ) {
		
		
		// PARA EVITAR LER DADOS DESNECESSARIOS QUANDO
		// INSERIMOS A STRING DE TERMINACAO DO PROGRAMA
		// O RESTO DAS LEITURAS SAO FEITAS DENTRO
		// DO CICLO WHILE, LOGO DEPOIS DA ENTRADA
		pesoDoAtleta 		= lerPeso();
		alturaDoAtleta 		= lerAltura();
		idadeDoAtleta 		= lerIdade(); 
		caloriasIngeridas 	= lerCaloriasIngeridas();
		
		// IMPRIMIR A INFORMACAO OBTIDA DO UTILIZADOR
		printf( "\n%s, %d Kg, %d cm, %d anos", nomeDoAtleta, pesoDoAtleta, alturaDoAtleta, idadeDoAtleta );
		
		// CALCULAR AS CALORIAS RECOMENDADAS PARA AQUELE ATLETA E IMPRIMIR
		caloriasRecomendadas = numCaloriasIndicadoPorDia( pesoDoAtleta, alturaDoAtleta, idadeDoAtleta );
		printf( "\nDeveria ingerir %4.2f calorias e ingeriu %d", caloriasRecomendadas, caloriasIngeridas );
		
		// CALCULAR A DIFERENCA ENTRE CALORIAS RECOMENDADAS E CALORIAS INGERIDAS E IMPRIMIR
		diferencaEntreCalsRecEIngeridas = (double) caloriasIngeridas  * 100   / (double) caloriasRecomendadas;
		printf( "\nDiferenca: %4.2f", diferencaEntreCalsRecEIngeridas );
		
		// ALERTA IMPRIMIDO VAI VARIAR CONSOANTE O VALOR DA DIFERENCA
		if ( diferencaEntreCalsRecEIngeridas < 15 ) {
			
			strcpy( alerta, alertaAte15PorCento);
	
		}
		else if ( diferencaEntreCalsRecEIngeridas < 30 ) {
			
			strcpy( alerta, alertaDe15A30PorCento);
		}
		else {
			
			strcpy( alerta, alertaMaisDe30PorCento);
		}
		
		printf( "\nAlerta: %s", alerta );
		
		
		// SE CALORIAS INGERIDAS FOREM MENORES DO
		// QUE AS RECOMENDADAS, INCREMENTAR ATLETAS
		// COM FALTA DE CALORIAS
		if ( diferencaEntreCalsRecEIngeridas > 0) {
			
			numeroAtletasFaltaDeCalorias++;

		}
		
		// SE AS CALORIAS INGERIDAS FOREM MAIORES DO 
		// QUE AS RECOMENDADAS, INCREMENTAR ATLETAS
		// COM EXCESSO DE CALORIAS
		if ( diferencaEntreCalsRecEIngeridas < 0) {
			
			numeroAtletasExcederamCalorias++;

		}
		


		// LEITURAS SUBSEQUENTES DO PROGRAMA
		// NO FINAL DO CICLO WHILE
		strcpy( nomeDoAtleta, lerNome() );
		
		// PARA EVITAR LER DADOS DESNECESSARIOS QUANDO
		// INSERIMOS A STRING DE TERMINACAO DO PROGRAMA
		// O RESTO DAS LEITURAS SAO FEITAS APENAS
		// SE O NOME FOR DIFERENTE DA STRING DE TERMINACAO
		// SENAO TERMINA O CICLO
		if ( strcmp( nomeDoAtleta, stringDeTerminacaoDoPrograma) == 0 ) {
			
			break;	
		}
		pesoDoAtleta 		= lerPeso();
		alturaDoAtleta 		= lerAltura();
		idadeDoAtleta 		= lerIdade(); 
		caloriasIngeridas 	= lerCaloriasIngeridas();
		
	} // FINAL DO CICLO WHILE
	

	// SE EXISTIREM ATLETAS QUE EXCEDERAM CALORIAS RECOMENDADAS
	// IMPRIME ESSE NUMERO
	if ( numeroAtletasExcederamCalorias > 0 ) {
		
		printf( "\nHa %d atletas que excederam as calorias indicativas.");
	}

	// SE EXISTIRAM ATLETAS COM FALTA DE CALORIAS
	// IMPRIME ESSE NUMERO
	if ( numeroAtletasFaltaDeCalorias > 0 ) {
		
		printf( "\nHa %d atletas que apresenta falta de calorias.");
	}
	
	
	// FIM DO PROGRAMA
	return 0;
}


// FUNCAO DE LER O NOME
// DO ATLETA
char* lerNome() {

	char nomeDoAtleta[20];
	
	fflush(stdin);
	
	do {
		
		printf( "\nInsira o nome do Atleta: ");
		scanf( " %s", nomeDoAtleta );
		
	} while ( strcmp( nomeDoAtleta, "") == 0 );
	
	fflush(stdin);
	
	return nomeDoAtleta;
}


// FUNCAO DE LER E VALIDAR UM INTEIRO QUE VAI
// SER USADA POR OUTRAS FUNCOES PARA REAPROVEITAR
// CODIGO COMUM
int lerEValidarUmInteiro( char mensagemParaOUtilizador[], int limiteInferior, int limiteSuperior ) {
	
	int inteiroLido = -1;
	
	fflush(stdin);
	do {
		
		printf( mensagemParaOUtilizador );
		scanf( " %d", &inteiroLido );
		
	} while ( inteiroLido < limiteInferior || inteiroLido > limiteSuperior );
	fflush(stdin);
	
	return inteiroLido;
		
}


// FUNCAO DE LER PESO QUE
// APROVEITA O CODIGO DA 
// FUNCAO DE LER INTEIROS
int lerPeso() {
	
	int pesoMinimo = 40;
	int pesoMaximo = 150;
	
	int pesoLido = 0;
	
	pesoLido = lerEValidarUmInteiro( "\nInsira o peso do Atleta: ", pesoMinimo, pesoMaximo );;
	
	return pesoLido;
}


// FUNCAO DE LER ALTURA QUE
// APROVEITA O CODIGO DA 
// FUNCAO DE LER INTEIROS
int lerAltura() {
	
	int alturaMinima = 60;
	int alturaMaxima = 250;
	
	int alturaLida = 0;
	
	alturaLida = lerEValidarUmInteiro( "\nInsira a altura do Atleta: ", alturaMinima, alturaMaxima );
	
	return alturaLida;
}


// FUNCAO DE LER IDADE QUE
// APROVEITA O CODIGO DA 
// FUNCAO DE LER INTEIROS
int lerIdade() {
	
	int idadeMinima = 4;
	int idadeMaxima = 150;
	
	int idadeLida = 0;
	
	idadeLida = lerEValidarUmInteiro( "\nInsira a idade do Atleta: ", idadeMinima, idadeMaxima );
	
	return idadeLida;
}


// FUNCAO DE LER CALORIAS QUE
// APROVEITA O CODIGO DA 
// FUNCAO DE LER INTEIROS
int lerCaloriasIngeridas() {
	
	int caloriasMinimas = -1;
	int caloriasMaximas = 10000;
	
	int caloriasLidas = -1;
	
	caloriasLidas = lerEValidarUmInteiro( "\nInsira as calorias ingeridas: ", caloriasMinimas, caloriasMaximas );
	
	return caloriasLidas;
	
	
}


// FUNCAO QUE RETORNA O NUMERO DE CALORIAS INDICADO POR DIA, DANDO COMO ARGUMENTOS
// O PESO EM KG, A ALTURA EM CM E A IDADE EM ANOS
// RETORNA UM DOUBLE PORQUE O RESULTADO PODE SER UM NUMERO DECIMAL
double numCaloriasIndicadoPorDia( int pesoCorporalEmKg, int alturaEmCm, int idadeEmAnos ) {
	
	// DECLARAR E INICIALIZAR VARIAVEL
	// PARA GUARDAR AS CALORIAS INDICADAS
	// POR DIA
	double caloriasIndicadasPorDia = -1.0;
	
	// CALCULA O NUMERO DE CALORIAS INDICADAS POR DIA
	caloriasIndicadasPorDia = 1.8 * ( 655 + ( 9.6 * (double) pesoCorporalEmKg ) + ( 4.7 * (double) idadeEmAnos ) );

	// RETORNA O NUMERO DE CALORIAS INDICADAS POR DIA
	return caloriasIndicadasPorDia;
}
