/*
Exercício 1. Crie um programa que permita gerir sócios de clubes.
O programa deve permitir:
- Inserir sócios: número e nome
- Inserir clubes
- Inscrever sócios em clubes
- Listar sócios por número: nome, número e clube
- Listar clubes por nome
*/

// IMPORTS DAS BIBLIOTECAS
#include <stdio.h>
#include <string.h>

// DEFINICAO DAS STRUCTS

// DEFINICAO DA STRUCT SOCIO
typedef struct{
    
    int    num;
    char   nome[20];
    int    clube;
     
    int    elo;   
    
} P;

// DEFINICAO DA STRUCT CLUBE
typedef struct{
    
    char   nome[20];
     
    int    elo;   
    
} C;  


// DEFINICAO DOS CONTADORES DE SOCIOS E DE CLUBES
int n;
int nc;

void inicializa(P* x, C* y) {
    
    // O PRIMEIRO SOCIO NA LISTA NO INDEX 0 VAI SER INICIALIZADO COM O ELO IGUAL A ZERO
    x[0].elo=0;
    
    // O PRIMEIRO CLUBE DA LISTA NO INDEX 0 VAI SER INICIALIZADO COM O ELO IGUAL A ZERO
    y[0].elo=0;
    
    // PARA O PRIMEIRO CLUBE DA LISTA VAI SER INICIALIZADO COM UM NOME NAO VALIDO
    strcpy(y[0].nome,"ZZZ");
    
}


int menu() {
    
    // INICIALIZAR UMA VARIAVEL PARA GUARDAR A OPCAO
    int ch;
    
    // APRESENTAR AS OPCOES AO UTILIZADOR ENQUANTO ELE INSERIR UM OPCAO 
    // NAO VALIDA
    do {
        
        // IMPRIMIR AS OPCOES DO UTILIZADOR
        printf("\n1. Insere socio ");
        printf("\n2. Insere clube ");
        printf("\n3. Increve socio em clube ");
        printf("\n4. Listar socios");
        printf("\n5. Listar clubes");
        printf("\n6. Sair ");
    
        // LER O INPUT DO UTILIZADOR
        scanf(" %d", &ch);}
        
    while ( (ch<0) || (ch>6) );
    
    // RETORMANOS O INTEIRO CORRESPONDENTE A OPCAO ESCOLHIDA
    return ch;
    
}

P LeUm() {
    
    // DECLARA UM SOCIO PARA GUARDAR A INFORMACAO
	P um;
	
	// PERGUNTAMOS O NUMERO E GUARDAMOS O NUMERO 
    do {
        
        // PERGUNTAR AO UTILIZADOR O NUMERO DO SOCIO A INSERIR
        printf("\nQual o numero do socio a inserir?");
        
        // GUARDAR O VALOR DO NUMERO RECEBIDO NA VARIAVEL DA STRUCT NUM
        scanf(" %d", &um.num);
        
    } while ( um.num <= 0 );
    
    
    // PERGUNTAMOS AO UTILIZADOR O NOME DO SOCIO E GUARDAMOS
    // NA VARIAVEL CORRESPONDENTE DENTRO DA STRUCT
    printf("\nQual o nome do socio %d?", um.num);
    scanf(" %s", &um.nome);
    
    // INICIALIZAMOS O CLUBE, MAS NAO COM O CLUBE REAL
    um.clube = 0;
    
    // RETOMAMOS A STRUCT SOCIO JA COM OS VALORES DE NUMERO E NOME CORRETOS
    return um;
}

void ColocaUm( P* x, P um ){
    
    // INDICES
    int i, ant;  
    
    // INCREMENTAR O NUMERO DE SOCIOS
    n++; 
    
    // NA LISTA DE SOCION NO INDICE N QUE ESTA VAZIO
    // TU VAIS METER O SOCIO UM
    x[n] = um;
    
    // NA LISTA X NA PRIMEIRA POSICAO ( INDICE 0 ) VAMOS VER PARA ONDE APONTA O ELO
    // E GUARDAMOS NO I, O I VAI CORRESPONDER AO ELO PARA O PRIMEIRO SOCIO REAL
    i = x[0].elo;
    
    // INICIALIZAMOS O ANTERIOR A ZERO
    ant = 0;
    
    // ENQUANTO O I FOR DIFERENTE DE 0 E O NUMERO DO SOCIO QUE ESTA NA POSICAO I FOR MENOR DO QUE
    // O NUMERO DO SOCIO QUE NOS QUEREMOS INSERIR
    // O x[i] CORRESPONDE AO NUM DO SOCIO QUE JA ESTA NA LISTA NO INDICE I
    // O x[n] CORRESPONDE AO NUM DO SOCIO QUE A GENTE QUER COLOCAR NA LISTA
    while ( (i!=0) && (x[i].num < x[n].num) ) {
        
        // GUARDAR O INDICE I NO ANTERIOR
        ant = i;
        
        // ATUALIZAR O I COM O ELO DO I ATUAL
        i = x[i].elo;
        
    }
    
    // QUANDO SE SAIR DO CICLO
    // VALOR FAZER CORRESPONDER O ELO
    // DO ANTERIOR AO INDICE DO NOSSO SOCIO INSERIDO
    x[ant].elo=n;
    
    // O ELO DO  NOSSO SOCIO INSERIDO VAI LIGAR
    // AO INDICE DO SOCIO A SEGUIR
    x[n].elo = i;  
    
}


C LeDois() {
    
    // DECLARAMOS UMA STRUCT CLUBE
    C dois;
    
    // PERGUNTAMOS AO UTILIZADOR O NOME DO CLUBE
    printf("\nQual o nome do clube?");
    
    // GUARDAMOS NA VARIAVEL CORRESPONDENTE
    scanf(" %s", &dois.nome);
    
    // RETORNAMOS A STRUCT CLUBE 
    return dois;
}
    			  




void ColocaDois(C* y, C dois){
    
    // DECLARAR OS INDICES DOS CLUBES A SEGUIR AO NOSSO E DO ANTERIOR
    int i, ant; 
    
    // INCREMENTAR O NUMERO DE CLUBES O QUE CORRESPONDE AO INDICE ONDE
    // VAMOS INSERIR O NOVO CLUBE
    nc++; 
    
    // INSERIMOS O NOSSO CLUBE NA LISTA DE CLUBES NO INDICE nc
    y[nc] =dois;
    
    // i VAI SER INICIALIZADO COM O ELO DO CLUBE NA POSICAO 0
    // QUE APONTA PARA O PRIMEIRO CLUBE REAL
    i=y[0].elo;
    
    // ant VAI SER INICIALIZADO COM O VALOR DO ELO DO PRIMEIRO CLUBE, A CABECA
    ant = 0;
    
    // ENQUANTO O i FOR DIFERENTE DE 0 E O NOME DO CLUBE INSERIDO FOR MAIOR DO QUE O NOME 
    // DO CLUBE QUE ESTA NA POSICAO i
    while (i!=0 && strcmp(y[i].nome,y[nc].nome)<0) {
        
        // A POSICAO I ATUAL PASSA A SER A POSICAO ANTERIOR ant
        ant=i;
        
        // ATUALIZAS O I
        i=y[i].elo;
        
    }
    
    // QUANDO SAIRES DO CICLO JA TENS O ELO DO ANTERIOR E JA SABES O NUMERO DO POSTERIOR
    // NA LISTA DE CLUBES O ELO DO ANTERIOR VAI APONTAR PARA O TEU INDICE
    y[ant].elo =nc;
    
    // O ELO DO CLUBE QUE INSERISTE VAI APONTAR PARA O SEGUINTE
    y[nc].elo = i;  
    
}


void socioemclube( P* x,C* y) {
    
    int num;
    int i;
    int j; 
    
    C dois;
    
    // LER O NUMERO DE SOCIO QUE QUERES METER NO CLUBE E VALIDAR
    do {
        
        printf("\nQual o numero do socio?");
        scanf(" %d",&num);
        
    } while (num<=0);
    
    // INICIALIZAR O I APONTA PARA O PRIMEIRO SOCIO REAL
    i = x[0].elo;
    
    // ENQUANTO O NUM DO SOCIO QUE QUERES INSERIR FOR MAIOR DO QUE
    // O NUMERO DO SOCIO NO INDICE I ATUAL VAI ATUALIZANDO O I
    while ((i!=0) && (x[i].num < num))
        i=x[i].elo;
        
    // QUANDO SAIRES DO CICLO QUER DIZER QUE JA ENCONTRASTE O SOCIO QUE QUERES INSERIR
        
    // SE O NUMERO INSERIDO NAO CORRESPONDER AO NUMERO DE NENHUM SOCIO DA LISTA
    // INDICAR QUE O SOCIO NAO EXISTE
    if (x[i].num!=num)
        printf("\nEsse socio nao existe");
    else {
        // LER O CLUBE QUE TU QUERES
        dois = LeDois();
        
        // INICIALIZAR J COM O ELO PARA O PRIMEIRO CLUBE REAL
        j  =y[0].elo;
        
        // ENQUANTO QUE O NOME DO CLUBE QUE INSERISTE FOR MAIOR DO QUE
        // O NOME DO CLUBE ATUAL PASSA PARA O CLUBE SEGUINT
        while (j!=0 && strcmp(y[j].nome,dois.nome)<0)
            j = x[j].elo;
            
        // QUANDO SAIRES DO CICLO´
        // SE O NOME DO CLUBE QUE INSERISTE NAO EXISTE
        if (strcmp(y[j].nome,dois.nome)!=0)
            printf("\nEsse clube %s nao existe",dois.nome);
        else {
            
            x[i].clube = j;
            printf("\nInscrito!");
            
        }
    }
}    


void EscreveTodossocios(P* x, C* y) {  
    
    // O i E PARA PERCORRER OS SOCIOS
    int i;
    
    int queclube;
    
    // INICIALAR O I COM O ELO PARA O PRIMEIRO SOCIO REAL
    i = x[0].elo;
    
    while (i != 0) {
        
        // SE O SOCIO NAO TIVER CLUBE 
        if (x[i].clube == 0)
            printf("\nnum: %d nome %s sem clube",x[i].num, x[i].nome);
        else {
            queclube = x[i].clube;
            printf("\nnum: %d nome %s clube %s",x[i].num, x[i].nome,y[queclube].nome);
        }
        
        i = x[i].elo; 
        
    }  
    
}
  
    
void EscreveTodosclubes(C* y) {  
    
    // O I E PARA PERCORRER OS CLUBES 
    int i;
    
    // INICIALIZAMOS O I COM O ELO PARA O PRIMEIRO CLUBE REAL
    i = y[0].elo;
    
    while (i != 0) {
        
        // IMPRIMIR O NOME DO CLUBE ATUAL
        printf("\nclube %s",y[i].nome);
        
        // ATUALIZAR O CLUBE ATUAL
        i = y[i].elo; 
        
    }  
    
}

int main ()
{
    // LISTA DE SOCIOS
    P x[10];  
    
    // SOCIO A COLOCAR
    P um;
    
    // LISTA DE CLUBES
    C y[10];
    
    // CLUBE A COLOCAR
    C dois;
    
    // OPCAO A ESCOLHER
    int op;
    
    // INICIALIZAR A ZERO O NUMERO DE SOCIOS E DE CLUBES
    n=0; nc=0;
    
    // ESTA FUNCAO RECEBE AS LISTAS DE SOCIO E DE CLUBE
    // COLOCAR INFORMACAO INICIAL NO SOCIO UM E NO CLUBE DOIS
    inicializa(x,y);
    
    // LER A OPCAO ESCOLHIDA PELO UTILIZADOR
    op = menu();
    
    while ( op != 6 )
    {
    	switch (op) {
    	    
    	    // SE A OPCAO FOR 1 QUE CORRESPONDE A INSERIR UM SOCIO
        	case 1:
        	    
        	    // SE O NUMERO DE SOCIOS JA ESTIVER NO MAXIMO
        	    if ( n == 10 )
        				printf("\nLimite de 10 socios excedido!");
                else {
                    
                    um = LeUm();	
                    ColocaUm(x,um);
                }
                
                break;
                
        	case 2:
        	
        	    if ( nc==10 )
        				printf("\nLimite de 10 clubes excedido!");
                else {
                    dois = LeDois();	
                    ColocaDois(y,dois);
                    
                }
                
                break;
                
        	case 3:
        	
        	    socioemclube(x,y); 
        	    
        	    break;
        	    
             case 4: 
             
                EscreveTodossocios(x,y);
                
                break;
                
            case 5: 
            
                EscreveTodosclubes(y);
                
                break;
    	    
    	}
    	
    	
        op=menu();
        
    }
    
    return 0;
    
}




