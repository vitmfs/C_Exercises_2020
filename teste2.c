




    /*
Faça um programa em C com as 3 primeiras opções do menu:
- Criar ficha de jogador (nome e nacionalidade)
- Listar todos jogadores (nome e nacionalidade, ordenado por nome)
- Listar todas as nacionalidades (nacionalidade e nomes de jogadores, ordenado por nacionalidade e por nome de jogador).
*/


// IMPORTACAO DAS LIBRARIAS
#include <stdio.h>
#include <string.h>

// DEFINICAO DAS STRUCTS

// STRUCT JOGADOR
typedef struct {
    
    char    nome[20];
    int     eloNac;     //corresponde ao indice onde no array de nacionalidades esta a nossa nacionalidade//
    int     ProxJN;     //corresponde ao proximo jogador da mesma nacionalidade eh um elo com o jogador mas da nossa nacionalidade 
    int     Prox;
    
} Joga;


// STRUCT NACAO
typedef struct {
    
    char    nac[20];
    int     PrimJ; //corresponde ah posicao ou indice do primeiro jogador dessa nacao 
    int     Prox; 
    
} Nacao;


// CONTADORES
int nj;
int nn;

//INICIALIZA AS CABECAS QUE ESTAO NA POSICAO OU INDICE 0
void inicializa(Joga* J, Nacao* N) {
    
    J[0].Prox=0;
    N[0].Prox=0;
    strcpy(J[0].nome,"ZZZ");
    strcpy(N[0].nac,"ZZZ");
}


int menu() {
    
    // DECLARA UMA VARIAVEL PARA GURADAR A OPCAO ESCOLHIDA
    int ch;
    
    do {
        printf("\n1. Criar ficha de jogador (nome, nacionalidade) ");
        printf("\n2. Listar todos jogadores ordenados por nome (indicando a nacionalidade) ");
        printf("\n3. Listar todas as nacionalidades ordenada por nome (indicando nome dos jogadores) ");
        printf("\n4. Sair ");
    
        scanf(" %d",&ch);
        
    } while ((ch<0) || (ch>4));
    
    return ch;
    
}



Joga LeJogador() {
    
    //DECLARA  UM JOGADOR PARA DEVOLVER
    Joga um;
    
    printf("\nQual o nome do jogador?");
    scanf(" %s",&um.nome);
    return um;
    
}
    
    
Nacao LeNacional(){
    
    // DECLARA UMA NACAO PARA DEVOLVER
    Nacao outro;
    
    printf("\nQual a nacionalidade do jogador?");
    scanf(" %s",&outro.nac);
    
    outro.PrimJ=0;
    
    return outro;
    
}


void ColocaJogador(Joga* J, Joga um, int posnac, Nacao* N) {
    // o i eh o actual 
    int i, ant;
    
    nj++;
    // o um q eh o jogador vai para a posicao nj do array J
    J[nj]=um;
    // a nacionalidade do novo jogador vai ser igual ah posicao da nacionalidade 
    J[nj].eloNac=posnac;
    //inicializa o i 
    i=J[0].Prox;
    // inicializa o ant
    ant=0;
    while ((i!=0) && (strcmp(J[i].nome,J[nj].nome)<0)){
        // enaquanto que o nome do jogador atual for menor que o nome do jogador q queremos inserir avanca 
        ant=i;
        
        
        
        i=J[i].Prox;
        
    }
    // qdo saio do ciclo while tenho o anterior e o seguinte o elo do anterior aponta para a nossa posicao para a posicao que nos inserimos e o elo do jogador q esta na posicao nj vai apontar para o proximo 
    
    J[ant].Prox=nj;
    J[nj].Prox=i;
    
    // o i passa a apontar para o primeiro jogador da nacionalidade 
    i=N[posnac].PrimJ;
    // se o i for igual a zero ou o nome do jogador actual for maior que o do jogador a inserir 
    if (i==0 || strcmp(J[i].nome,J[nj].nome)>0)
    {
        J[nj].ProxJN=i;
        N[posnac].PrimJ=nj;
    }
    else{
        //se o i for diferente de zero e o nome do jogador atual for menos q o do jogador a inserir 
        while ((i!=0) && (strcmp(J[i].nome,J[nj].nome)<0)){
            ant=i;
            i=J[i].ProxJN;
            
        }
        // o elo do anterior vai apontar para a posicao do inserir e o elo do inserir vai apontar para a seguinte 
        J[ant].ProxJN=nj;
        // atualiza 
        J[nj].ProxJN=i; 
        
    }
}

// tenho que fazer a funcao a int porque tem retorna a pocicao da nacao 

int ColocaouVeNacao(Nacao* N, Nacao outro) {
    
    int i, ant,posnac;
    
    // I E INICIALIZADO COM O ELO PARA A PRIMEIRA NACAO REAL
    i=N[0].Prox;
    
    // ANT E INICIALIZADO A 0
    ant=0;
    
    // EN QUANTO I FOR DIFERENTE DE 0 
    
    // ENQUANTO O NOME DA NACIONALIDADE ATUAL FOR MENOR DO QUE O NME DA NACIONALIDADE QUE NOS QUEREMOS INSERIR
    while ((i!=0) && (strcmp(N[i].nac,outro.nac)<0)){
        
        // O ANTERIOR PASSA A SER O INDICE ATUAL
        ant=i;
        
        // O INDICE ATUAL PASSA A SER O PROXIMO INDICE
        i=N[i].Prox;
        
    }
    
    if (strcmp(N[i].nac,outro.nac)!=0)
    {
        // INCREMENTAR O CONTADOR DE NACIONALIDADES
        nn++;
        
        // O ELO NA NACIONALIDADE ANTERIOR PASSA A APONTAR PARA A NOSSA POSICAO
        N[ant].Prox=nn;
        
        // COPIAMOS A NOSSO NACIONALIDADE PARA O ARRAY NA POSICAO NN
        N[nn]=outro;
        
        // O ELO DA NOSSA NACIONALIDA PASSA A APONTAR PARA A POSICAO DA NACIONALIDADE SEGUINTE
        N[nn].Prox=i;
        
        posnac=nn;
        
    }
    else
    // eh qdo for o msmo nome 
        posnac=i;
        
    return posnac;
}



EscreveTodosJogadores(Joga* J,Nacao* N) {
    // o i eh para percorrer o array de  jogadores 
    // quenac é para percorrer  o array de  nacionalidade  
    int i=J[0].Prox;
    
    while (i!=0)
    // enquanto o i diferente de zero quer dizer q n eh o ultimo jogador 
    {
        int quenac=J[i].eloNac;
        printf("\nnome %s nacionalidade %s",J[i].nome,N[quenac].nac);
        //para avancar no array
        i=J[i].Prox; 
        
    } 
    
}



EscreveTodasNacoes(Nacao* N,Joga* J){
    // o i percorrer o array de nacionalidades 
    // o i2 percorrer o array de jogadores 
    int i,i2;
    
    i=N[0].Prox;
    
    // enquanto n for a ultima nacao 
    while (i!=0)
    {
        printf("\nNacionalidade %s dos jogadores",N[i].nac);
        // i2 contador para percorrer os jogadores de cada nacao 
        i2=N[i].PrimJ;
        
        // enquanto q houver jogadores 
        while (i2!=0)
        {
            printf("\nnome %s ",J[i2].nome);
            // enquanto q houver jogadores passa o proximo
            i2=J[i2].ProxJN; 
            
        }
        
        i=N[i].Prox; 
        
    } 
    
}



int main ()
{
    // DECLARACAO DO ARRAY DE JOGADORES
    Joga J[100];
    
    // JOGADOR TEMPORARIO
    Joga um;
    
    // DECLARACAO DO ARRAY DE NACOES
    Nacao N[10];
    
    // NACAO TEMPORARIO
    Nacao outro;
    
    // POSICAO DA NACAO NO ARRAY DE NACOES
    int posnac;
    
    // VARIAVEL TEMPORARIA PARA GUARDAR A OPCAO
    int op;
    
    // INICIALIZACAO DO NUMERO DE JOGADORES E DO NUMERO DE NACOES
    nj=0; nn=0;
    
    // INICIALIZA OS ARRAYS DE JOGADORES E NACOES
    inicializa(J,N);
    
    // ESCOLHER A OPCAO PRETENDIDA
    op=menu();
    
    while (op!=4)
    {
        switch (op) {
            
            case 1:
            
                if (nj==100)
                    printf("\nLimite de 100 jogadores excedido!");
                else
                {
                    um      = LeJogador(); 
                    outro   = LeNacional();
                    posnac  = ColocaouVeNacao(N, outro);
                    ColocaJogador(J,um, posnac,N);
                    
                }
            break;
            
            case 2: EscreveTodosJogadores(J,N); break;
            case 3: EscreveTodasNacoes(N,J);
        }
        
        op=menu();
        
    }
    system ("pause");
}

