/*
Algoritmia e Programação
2019-2020
Ficha pratica nº8
Dois Vetores de registo

Exercício 1. Crie um programa que permita gerir sócios de clubes.
O programa deve permitir:
- Inserir sócios: número e nome
- Inserir clubes
- Inscrever sócios em clubes
- Listar sócios por número: nome, número e clube
- Listar clubes por nome

*/



#include <stdio.h>
#include <string.h>

// ESTRUTURA SOCIO
typedef struct {

     int    num;
     char   nome[20];
     int    clube;

     int elo;

} SOCIO;


// ESCTRUTURA CLUBE
typedef struct {

     char nome[20];
     int elo;

} CLUBE;

// NUMERO DE SOCIOS
int n;

// NUMBERO DE CLUBES 
int nc;

// FUNCAO QUE INICIALIZA A "CABECA" DAS LISTAS
// LIGADAS DOS SOCIOS E DOS CLUBES
void inicializa( SOCIO* socios, CLUBE* clubes ) {

    socios[0].elo = 0;
    clubes[0].elo = 0;
    strcpy( clubes[0].nome,"ZZZ" );

}


// FUNCAO QUE IMPRIME TODOS OS SOCIOS
void escreveTodosSocios( SOCIO* socios, CLUBE* clubes ) {
	
	int i;
	int queclube;
	
	// i COMECA COM O ELO DO PRIMEIRO SOCIO DA LISTA
	i = socios[0].elo;
	
	// ENQUANTO O ELO PARA O PROXIMO SOCIO NAO FOR ZERO
	// O QUE INDICA QUE E O ULTIMO
	while ( i != 0 )
	{
		// SE O CLUBE DO SOCIO ATUAL FOR IGUAL A ZERO
		// ISSO INDICA QUE O SOCIO NAO TEM CLUBE IMPRIME
		// SO O NUMERO E O NOME 
		if ( socios[i].clube == 0 ) {
			
			printf( "\nnum: %d nome %s sem clube", socios[i].num, socios[i].nome );
		} 
		else
		{
			// SENAO IMPRIME TUDO, NUMERO, NOME E CLUBE
			queclube = socios[i].clube;
			printf( "\nnum: %d nome %s clube %s", socios[i].num, socios[i].nome, clubes[queclube].nome );
		}
		
		// ATUALIZA O i COM O NUMERO DO NO ATUAL
		i = socios[i].elo; 
	}  

}


// FUNCAO QUE ESCREVE TODOS OS CLUBES
void escreveTodosClubes( CLUBE* clubes ) {
	
	// INICIALIZA O i COM O ELO DO PRIMEIRO NO
	int i;
	i = clubes[0].elo;
	
	// ENQUANTO O i NAO FOR ZERO
	// O QUE INDICA QUE NAO E O ULTIMO
	while ( i != 0 )
	{
		printf( "\nclube %s", clubes[i].nome );

		// ATUALIZA O i COM O ELO DO NO ATUAL
		i = clubes[i].elo; 
	}  

}


// FUNCAO QUE LE UM SOCIO
SOCIO leUmSocio() {
	
	SOCIO novoSocio;
	
	do {
		
		printf( "\nQual o numero do socio a inserir?" );
		scanf( " %d", &novoSocio.num );
		
	} while ( novoSocio.num <= 0 );
	
	printf( "\nQual o nome do socio %d?", novoSocio.num );
	scanf(" %s", &novoSocio.nome );
	
	novoSocio.clube = 0;
	
	return novoSocio;
}


// FUNCAO QUE COLOCA UM SOCIO NA LISTA LIGADA  DE SOCIOS
void colocaUmSocio( SOCIO* socios, SOCIO um ) {
	
	int i;
	int ant;
	
	// ATUALIZA O NUMERO DE SOCIOS
	n++;
	
	// COLOCA O NOVO SOCIO NO ARRAY DE SOCIOS NO INDICE n
	socios[n] = um;
	
	i = socios[0].elo;
	ant = 0;
	while ( ( i != 0 ) && ( socios[i].num < socios[n].num ) ) {
		
		ant = i;
		
		i = socios[i].elo;
	}
	
	socios[ant].elo = n;
	socios[n].elo = i;  

}


// FUNCAO QUE LE UM CLUBE
CLUBE leUmClube() {
	
	CLUBE novoClube;
	
	printf( "\nQual o nome do clube?" );
	scanf( " %s", &novoClube.nome );
	
	return novoClube;
}


// FUNCAO QUE COLOCA UM CLUBE NO ARRAY DE CLUBES
void colocaClube( CLUBE* clubes, CLUBE clube ) {
	
	int i;
	int ant;
	
	nc++;
	
	clubes[nc] = clube;
	
	i = clubes[0].elo;
	ant = 0;
	while ( i != 0 && strcmp( clubes[i].nome, clubes[nc].nome ) < 0 ) {
		
		ant = i;
	
		i = clubes[i].elo;
	}
	
	clubes[ant].elo = nc;
	clubes[nc].elo = i;  

}


// FUNCAO QUE APRESENTA O MENU E LE A OPCAO
int menu() {
	
    int ch;
    
    do {
    	
		printf( "\n1. Insere socio " );
	    printf( "\n2. Insere clube " );
	    printf( "\n3. Increve socio em clube " );
	    printf( "\n4. Listar socios" );
	    printf( "\n5. Listar clubes" );
	    printf( "\n6. Sair " );
    
    	scanf( " %d", &ch );
		
	} while ( ( ch < 0 ) || ( ch > 6 ) );
	
    return ch;
}


// FUNCAO QUE COLOCA UM SOCIO NUM CLUBE
void socioEmClube( SOCIO* socios, CLUBE* clubes ) {
	
	int num;
	 
	int i; 
	int j; 
	
	CLUBE clube;
	
	do {
		
		printf( "\nQual o numero do socio?" );
		scanf( " %d", &num);
		
	} while ( num <= 0 );
	
	
	i = socios[0].elo;
	while ( ( i != 0 ) && ( socios[i].num < num ) ) {
		
		i = socios[i].elo;
	}
	
	if ( socios[i].num!=num) {
		
		printf("\nEsse socio nao existe");
	} 
	else
	{
		clube = leUmClube();
		
		j = clubes[0].elo;
		while ( j != 0 && strcmp( clubes[j].nome, clube.nome ) < 0 ) {
			
			j = socios[j].elo;
		}
		
		if ( strcmp( clubes[j].nome, clube.nome) != 0 ) {
			
			printf( "\nEsse clube %s nao existe", clube.nome );
			
		}
		else
		{
			socios[i].clube=j;
			printf("\nInscrito!");
		}
	}
}


int main () {

	SOCIO socios[10];
	SOCIO um;
	CLUBE clubes[10];
	CLUBE clube;
	int op;
	n=0; nc=0;
	
	inicializa( socios, clubes );
	
	op=menu();
	while ( op != 6 )
	{
		switch ( op ) {
			
		case 1:
		
			if ( n == 10 ) {
				
				printf("\nLimite de 10 socios excedido!");
			}
			else 
			{
				um = leUmSocio();	
				colocaUmSocio( socios, um );
			}
			
			break;
			
			
		case 2:
		
			if ( nc == 10 ) {
				
				printf("\nLimite de 10 clubes excedido!");
			}
			else
			{
				clube = leUmClube();	
				colocaClube( clubes, clube );
			}
			
			break;
			
		case 3:
		
			socioEmClube( socios, clubes ); 
			
			break;
			
	     case 4: 
		 
		 	escreveTodosSocios( socios , clubes );
		 	
			break;
			
			
		case 5: 
		
			escreveTodosClubes( clubes );
	
	}
	
	
		op = menu();
	
	}
	
	
	system ("pause");
}

