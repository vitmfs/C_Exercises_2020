
/* Exercício 2. Crie um programa que permita gerir sócios de clubes.
O programa deve permitir:
- Inserir sócios: número e nome
- Inserir clubes
- Inscrever sócios em clubes
- Listar sócios por número: nome, número e clube
- Listar clubes por nome: nome de clube, numero e nome de sócio
*/

// IMPORTACAO DAS LIBRARIAS
#include <stdio.h>
#include <string.h>

// DEFINICAO DAS STRUCTS
// STRUCT SOCIO
typedef struct{
    
     int    num;
     char   nome[20];
     
     int    clube;
     int    ProxSC;
     
     int    elo;   
    
} P;

// STRUCT CLUBE
typedef struct{
    
    char    nome[20];
    int     PrimSC;
    
    int elo;   
    
} C;  
     
 
 // CONTADORES DE SOCIOS E DE CLUBES
 // QUE TAMBEM SERVEM PARA OS INDICES
 // ONDE COLOCAMOS NOVOS SOCIOS E CLUBES
 // NOS RESPECTIVOS ARRAYS
int n;
int nc;


inicializa( P* x, C* y ) {
    
    // NO SOCIO QUE ESTA NA PRIMEIRA POSICAO
    // IGUALAMOS O ELO A ZERO
    x[0].elo=0;
    
    // NO CLUBE QUE ESTA NA PRIMEIRA POSICAO
    // IGUALAMOS O ELO A ZERO
    y[0].elo=0;
    
    // COMO O CLUBE TEM UM NOME
    // VAMOS IGUALAR O NOME DO CLUBE
    // NA PRIMEIRA POSICAO
    // A UM NOME QUE NAO TEM SENTIDO
    strcpy(y[0].nome,"ZZZ");
}


int menu() {
    
    // DECLARAR UMA VARIAVEL PARA GUARDAR A 
    // OPCAO ESCOLHIDA
    int ch;
    
    do {
        printf("\n1. Insere socio ");
        printf("\n2. Insere clube ");
        printf("\n3. Increve socio em clube ");
        printf("\n4. Listar socios");
        printf("\n5. Listar clubes");
        printf("\n6. Sair ");
        
        scanf(" %d", &ch );
        
    } while ( ( ch < 0) || ( ch > 6 ) );
    
    //RETORNAMOS A OPCAO ESCOLHIDA
    return ch;
    
}


P LeUm() {
    
    // DECLARAR UMA STRUCT PARA RETORNAR
	P um;
	
	// PERGUNTAR O NUMERO DE SOCIO
	// E GUARDAR NA VARIAVEL CORRESPONDENTE
	// NA STRUCT QUE CRIAMOS
    do {
        
        printf("\nQual o numero do socio a inserir?");
        scanf(" %d", &um.num);
        
    } while (um.num<=0);
    
    // PERGUNTAR O NOME DO SOCIO
    printf("\nQual o nome do socio %d?", um.num);
    scanf(" %s", &um.nome);
    
    // INICIALIZAR O CLUBE A ZERO
    // PARA INDICAR QUE O SOCIO 
    // AINDA NAO TEM CLUBE
    um.clube=0;
    
    // RETORNAR A STRUCT COM OS VALORES LA METIDOS
    return um;
}


void ColocaUm(P* x, P um ) {
    
    // DECLARAMOS DOIS INTEIROS PARA GUARDAR
    // O ATUAL E O ANTERIOR
    int i, ant;   
    
    // COMO VAMOS GUARDAR O NOVO SOCIO
    // NA POSICAO A SEGUIR
    // TEMOS QUE INCREMENTAR O N QUE E O CONTADOR DE SOCIOS
    // E QUE TAMBEM CORRESPONDE AO INDICE NA LISTA DE SOCIOS
    n++; 
    
    // NA LISTA DE SOCIOS, NA POSICAO N, VAMOS METER LA
    // O NOVO SOCIO
    x[n] = um;
    
    // INICIALIZAR O I Q CORRESPONDE AO ACTUAL 
    // COM O ELO QUE APONTA PARA O PRIMEIRO
    // SOCIO REAL, PORQUE E O ELO DA CABECA
    i=x[0].elo;
    
    // INICIALIZAMOS O ANT
    ant=0;
    
    // ENQUANTO O I FOR DIFERNTE DE ZERO E 
    // ENQUANTO O NUM DO SOCIO QUE EU QUERO INSERIR
    // FOR MAIOR DO QUE O NUMERO DO SOCIO ATUAL
    // GUARDAS O I NO ANT E ATUALIZAS O I
    while ((i!=0) && ( x[i].num < x[n].num)) {
        
        // GUARDAR O VALOR DE I NO ANT
        ant=i;
        
        // ATUALIZAS O I
        i=x[i].elo;
        
    }
    
    
    // QUANDO SE SAIR DO CICLO
    // O ELO DO ANTERIOR VAI APONTAR
    // PARA O SOCIO QUE NOS INSERIMOS
    x[ant].elo=n;
    
    // O ELO DO SOCIO QUE NOS INSERIMOS 
    // VAI APONTAR PARA O PROXIMO
    x[n].elo = i;  
    
    // ???
    x[n].ProxSC=0;
    
}


C LeDois() {
    
    // DECLARAR UMA VARIAVEL PARA RETORNAR
	C dois;
	
	// PERGUNTAR E GUARDAR NA VARIAVEL CORRESPONDE
	// O NOME DO CLUBE
    printf("\nQual o nome do clube?");
    scanf(" %s", &dois.nome);
    
    // RETORNAR A STRUCT CLUBE QUE CRIAMOS JA 
    // COM O VALOR DA VARIAVEL
    return dois;
}


void ColocaDois(C* y, C dois){
    
    // DECLARAR O ATUAL E O ANTERIOR
    int i, ant; 
    
    // COMO VAMOS INSERIR UM CLUBE VAMOS INCREMENTAR
    // O NUMERO DE CLUBES, QUE TAMBEM CORRESPONDE
    // AO INDICE NO ARRAY DE CLUBES ONDE VAMOS 
    // INSERIR O NOVO CLUBE
    nc++; 
    
    // INSERIR O NOVO CLUBE NO ARRAY DE CLUBES NO INDICE
    // JA INCREMENTADO NC
    y[nc]=dois;
    
    // INICIALIZAR O I COM O ELO PARA O PRIMEIRO CLUBE REAL
    i=y[0].elo;
    
    // INICIALIZAR O ANT COM 0
    ant=0;
    
    // ENQUANTO O ATUAL NAO FOR ZERO E O NOME DO CLUBE
    // QUE NOS QUEREMOS INSERIR FOR MAIOR DO QUE O NOME
    // DO CLUBE ATUAR, INCREMENTAMOS
    while (i!=0 && strcmp(y[i].nome,y[nc].nome)<0) {
        
        // GUARDAMOS O ATUAL NO ANTERIOR
        ant=i;
        
        // INCREMENTAMOS O ATUAL
        i=y[i].elo;
        
    }
    
    // O ELO DO SOCIO ANTERIOR VAI APONTAR PARA NOS
    y[ant].elo=nc;
    
    // O NOSSO ELO VAI APONTAR PARA O PROXIMO
    y[nc].elo=i;  
    
    //???
    y[nc].PrimSC=0;
    
}

void socioemclube(P* x,C* y) {
    
    // DECLARAR INTEIROS PARA PERCORRER AS LISTAS
    int i;
    int j;
    
    // DECLARAR NUMERO TEMPORARIO
    int num;
    
    // DECLARAR CLUBE
    C dois;
    
    // PERGUNTAR NUMERO DO SOCIO
    do {
        printf("\nQual o numero do socio?");
        scanf(" %d", &num);
        
    } while (num<=0);
    
    // INICIALIZAMOS O I COM O ELO PARA O PRIMERIO CLUBE REAL
    i=x[0].elo;
    
    // ENQUANTO I FOR DIFERENTE DE ZERO E O NUMERO DO SOCIO QUEREMOS INSERIR
    // ENQUANTO O NUMERO DO ATUAL FOR MENOR DO QUE O NUMERO DO QUE NOS QUEREMOS
    // INSERIR ATUALIZAMOS O I
    while ((i!=0) && (x[i].num<num)) {
        
        i=x[i].elo; 
    }
       
    // DEPOIS DE SAIRMOS DO CICLO SE O NUMERO DO ATUAL FOR DIFERENTE
    // DO NUMERO DAQUELE QUE QUEREMOS INSERIR ISSO QUER DIZER QUE O SOCIO
    // NAO FOI ENCONTRADO
    if (x[i].num!=num)
        printf("\nEsse socio nao existe");
    else {
        dois = LeDois();
        
        // INICIALIZAMOS O J COM O ELO PARA O PRIMEIRO CLUBE REAL
        j=y[0].elo;
        
        // ENQUANTO O J FOR DIFERENTE DE 0 E O NOME DO CLUBE ATUAL
        // FOR MENOR QUE O DO CLUBE QUE QUEREMOS, ATUALIZA O J
        while (j!=0 && strcmp(y[j].nome,dois.nome)<0)
            j=y[j].elo;
            
        // QUANDO SAIRMOS DO CICLO SE O NOME DO CLUBE ATUAL FOR
        // DIFERENTE DO NOME DO CLUBE QUE QUEREMOS QUER DIZER 
        // QUE O CLUBE NAO FOI ENCONTRADO
        if (strcmp(y[j].nome,dois.nome)!=0)
            printf("\nEsse clube %s nao existe",dois.nome);
        else {
            
            // VAMOS DIZER O CLUBE DO SOCIO VAI SER O J
            x[i].clube = j;
            
            
            int ant=y[j].PrimSC;
            
            if ((ant==0) ||x[ant].num>num) {
                y[j].PrimSC=i;
                x[i].ProxSC=ant;
            } else {
                //declara o temp para guardar o ant 
                int temp=x[ant].ProxSC;
                while ((temp!=0) && (x[temp].num<num)) {
                    ant=temp;
                    temp=x[temp].ProxSC;
            }
            //atualiza 
            x[ant].ProxSC=i;
            x[i].ProxSC=temp;
            printf("\nInscrito!");}
        }
    }
}   

    
			  
			  
			  
void EscreveTodossocios(P* x, C* y) { 
    
    // INTS PARA PERCORRER AS LISTAS
    int i,queclube;
    
    // INICIALIZAR I COM O ELO PARA O PRIMEIRO SOCIO REAL
    i=x[0].elo;
    
    // ENQUANTO O I FOR DIFERENTE DE 0
    while (i!=0) {
        
        // SE O CLUBE DO SOCIO FOR 0, ISSO QUE DIZER
        // QUE ELE AINDA NAO TEM CLUBE
        if (x[i].clube==0)
            printf("\nnum: %d nome %s sem clube",x[i].num, x[i].nome);
        else {
            
            // SE TIVER CLUBE, IMPRIME O CLUBE
            queclube=x[i].clube;
            printf("\nnum: %d nome %s clube %s",x[i].num, x[i].nome,y[queclube].nome);
        }
        
        // INCREMENTA O I
        i=x[i].elo; 
        
    }  
    
}


void EscreveTodosclubes(P* x, C* y) {   
    
    // INTS PARA PERCORRER AS LISTAS
    int i;
    int temp;
    
    // INICIALIZAMOS A I COM O ELO PARA O PRIMEIRO CLUBE REAL
    i=y[0].elo;
    
    // ENQUANTO O I FOR DIFERENTE DE 0
    while (i!=0) {
        
        
        temp=y[i].PrimSC;
        
        // SE O PRIMEIRO SOCIO DAQUELE CLUBE FOR IGUAL A 0
        // SIGNIFICA QUE AQUELE CLUBE NAO TEM SOCIOS
        if (temp==0)
            printf("\nclube %s sem socios",y[i].nome);
        else
        {
            // SE TIVER SOCIOS, IMPRIME O NOME DO CLUBE 
            printf("\nclube %s",y[i].nome);
            
            // ENQUANTO O TEMP NAO FOR 0, IMPRIME O NUMERO E NOME DOS SOCIOS
            while (temp!=0) {
                
                printf("\nnum: %d nome %s ",x[temp].num, x[temp].nome);
                
                
                temp=x[temp].ProxSC;
                
            }
        
        }
        i=y[i].elo; 
        
    }  
    
}








// PROGRAMA PRINCIPAL A PARTIR DO QUAL 
// CHAMAMOS AS OUTRAS FUNCOES
int main ()
{
    // ARRAY DE SOCIOS COM 10 LUGARES
    P x[10]; 
    
    // DECLARACAO DO SOCIO PARA INSERIR
    P um;
    
    // ARRAY DE CLUBES COM 10 LUGARES
    C y[10];
    
    // DECLARACAO DO CLUBE PARA INSERIR
    C dois;
    
    // VARIAVEL DO TIPO INT QUE VAI GUARDAR A OPCAO ESCOLHIDA
    int op;
    
    // INICIALIZACAO DOS CONTADORES DE SOCIOS E DE CLUBES
    n=0; 
    nc=0;
    
    // FUNCAO PARA INICIALIZAR OS ARRAYS DE SOCIOS E DE CLUBES
    inicializa(x,y);
    
    // VAMOS USAR A FUNCAO MENU PARA ESCOLHER E RETORNAR O NUMERO
    // CORRESPONDENTE A OPCAO ESCOLHIDA
    op = menu();
    
    while ( op != 6 )
    {
    	switch (op) {
    	    
    	case 1:
    	    if ( n == 10 )
    				printf("\nLimite de 10 socios excedido!");
    		else{
    		    
    		    um = LeUm();	
    		    ColocaUm( x, um );
    		    
    		}
    		
    		break;
    		
    	case 2:
    	    if (nc==10)
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
            EscreveTodosclubes(x,y);
    	    
    	}
    	
        op=menu();
        
    }
system ("pause");
}

