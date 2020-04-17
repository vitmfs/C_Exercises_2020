#include <stdio.h>
#include <string.h>


// DEFINICAO DA ESTRUTURA ALUNO
typedef struct {
	
	int 	num;
	char 	nome[20];
	
	int 	elo; 

} ALUNO;


// DECLARACAO DAS FUNCOES QUE TEM 
// DE VIR DEPOIS DA DEFINICAO
// DAS ESTRUTURAS PORQUE SENAO
// AINDA NAO CONHECO OS TIPOS
// DAS ESTRUTURAS
int 	menu();
void 	inicializa( ALUNO* alunos );
void 	escreveTodos( ALUNO* alunos );
ALUNO 	criarAluno();
void 	colocaAluno( ALUNO* alunos, ALUNO um );


// DECLARACAO e INICIALIZACAO DO NUMERO DE ALUNOS
int numeroAlunoBarraIndexDeAluno = 0;


int main() {
	
	printf( "O PROGRAMA DE VETORES DE REGISTOS DOS ALUNOS COMECOU!" );

	// DECLARA O VETOR DE REGISTOS
	ALUNO alunos[10];

	
	// INICIALIZA O VETOR DE REGISTOS
	inicializa( alunos );
	
	// CRIA ALGUNS ALUNOS PARA TESTE
	ALUNO aluno_um;
	aluno_um.num 	= 1;
	strcpy( aluno_um.nome, "Ana" );
	aluno_um.elo 	= 2;
	
	ALUNO aluno_dois;
	aluno_dois.num 	= 2;
	strcpy( aluno_dois.nome, "Berto" );
	aluno_um.elo 	= 3;
	
	ALUNO aluno_tres;
	aluno_tres.num 	= 3;
	strcpy( aluno_tres.nome, "Carlota" );
	aluno_um.elo 	= 0;
	
	// COLOCAR OS ALUNOS DE TESTE NO VETOR DE REGISTOS
	colocaAluno( alunos, aluno_um );
	colocaAluno( alunos, aluno_dois );
	colocaAluno( alunos, aluno_tres );
	
	
	
	// INICIALIZA UM ALUNO TEMPORARIO
	ALUNO um;
	
	
	
	// DECLARAR E INICIALIZAR OPCAO
	int op;
	op=menu();
	
	// ENQUANTO A OPCAO FOR DIFERENTE
	// DE SAIR DO PROGRAMA
	while ( op != 3 ) {
		
		// SE A OPCAO ESCOLHIDA FOR 
		// INSERIR UM NOVO ALUNO
		if ( op == 1) {
			
			// SE O NUMERO DE ALUNOS FOR IGUAL A 10
			// QUER DIZER QUE ATINGIMOS O LIMITE 
			// DE ESPACO NO ARRAY, SENAO CRIAMOS
			// UM ALUNO E INSERIMOS NO ARRAY
			if ( numeroAlunoBarraIndexDeAluno == 10 ) {
				
				printf("\nLimite de 10 alunos excedido!");
				
			} else {
			
				um = (ALUNO) criarAluno();
				colocaAluno( alunos, um );
			}
			
		} else {
			
			// SE A OPCAO NAO FOR INSERIR UM NOVO ALUNO
			// QUER DIZER QUE E PARA ESCREVER TODOS OS 
			// ALUNOS
			escreveTodos( alunos );
			
		}
		
		
		// LER NOVAMENTE A OPCAO ESCOLHIDA
		op = menu();
	}

	printf( "O PROGRAMA DE VETORES DE REGISTOS ACABOU!\n" );
	return 0;
}

// FUNCAO QUE INICIALIZA O VETOR DE REGISTOS,
// RECEBENDO-O COMO ARGUMENTO
void inicializa( ALUNO* alunos ) {
	
	alunos[0].elo = 0;

}


// FUNCAO QUE RECEBENDO O VETOR DE REGISTOS
// COMO ARGUMENTO ESCREVE TODOS OS ALUNOS
void escreveTodos( ALUNO* alunos ) {
	
	int i;
	
	// i E INICIALIZADO COM O INT
	// QUE CORRESPONDE AO VALOR
	// DO ELO DO NO QUE TEM O NUM
	// DE ALUNO MAIS PEQUENO
	i = alunos[0].elo;
		
	// ENQUANTO O i, QUE CORRSPONDE AO
	// VALOR DO ELO PARA O NO SEGUINTE
	// NAO FOR ZERO, SENDO QUE ZERO
	// CORRESPONDE A SER O ULTIMO NO,
	// ENTAO VAMOS IMPRIMIR O NO E FAZER 
	// CORRESPONDER O VALOR DE i AO VALOR DO ELO SEGUINTE
	while ( i != 0 ) {
	
		// IMPRIMIR O NUMERO E NOME DO ALUNO
		printf( "\nnum: %d nome: %s  \telo: %d", alunos[i].num, alunos[i].nome, alunos[i].elo );
		
		
		// FAZER CORRESPONDER
		// O VALOR DE i AO VALOR DO ELO SEGUINTE
		i = alunos[i].elo; 
	} 
	
} // FIM DA FUNCAO ESCREVETODOS


// FUNCAO QUE LE DO UTILIZADOR OS VALORES 
// NECESSARIOS PARA CRIAR UM ALUNO
ALUNO criarAluno() {
		
	// DECLARAR UM ALUNO PARA RETORNAR
	ALUNO um;
	
	// INSERIR E VALIDAR O NUMERO DO ALUNO
	do {
		
		printf( "\nQual o numero do aluno a inserir? " );
		scanf(" %d", &um.num);
		fflush(stdin);
		
	} while ( um.num <= 0 );
	
	// INSERIR O NOME DO ALUNO
	printf( "\nQual o nome do aluno %d? ", um.num );
	scanf(" %s", &um.nome );
	
	// RETORNAR O ALUNO
	return um;
}


// FUNCAO QUE COLOCA UM ALUNO NO 
// VETOR DE REGISTOS
void colocaAluno( ALUNO* alunos, ALUNO um ) {
	
	int i; 
	int ant;
	
	// ATUALIZAMOS O NUMERO DE Ps
	// SABENDO ASSIM EM QUE INDICE 
	// VAMOS COLOCAR O P NO VETOR DE 
	// REGISTOS
	numeroAlunoBarraIndexDeAluno++;
	
	// COLOCAMOS O P NO VETOR DE REGISTOS
	alunos[numeroAlunoBarraIndexDeAluno] = um;
	
	// INICIALIZAMOS i COM O VALOR DO ELO
	// PARA O NO COM O NUMERO DE ALUNO
	// MAIS PEQUENO 
	i = alunos[0].elo;
	
	// INICIALIZAMOS UMA VARIAVEL PARA GUARDARMOS
	// O ELO DO NO ANTERIOR
	ant = 0;
	
	// ENQUANTO O VALOR DE ELO FOR DIFERENTE DE ZERO
	// O QUE INDICA QUE NAO E O ULTIMO E O VALOR DO
	// NUMERO DE ALUNO FOR MENOR DO QUE O NUMERO DO 
	// ALUNO QUE PRETENDEMOS COLOCAR PASSA PARA O 
	// PROXIMO NO
	while ( (i !=0 ) && ( alunos[i].num < alunos[numeroAlunoBarraIndexDeAluno].num ) ) {
		
		// GUARDAMOS O VALOR ATUAL DE i NO VARIAVEL
		// QUE GUARDA O ANTERIOR
		ant = i;
		
		// ATUALIZAMOS O VALOR DO ELO
		i = alunos[i].elo;
	}
	
	// SAI DO CICLO WHILE QUANDO O VALOR DE NUMERO DO 
	// ALUNO FOR
	alunos[ant].elo = numeroAlunoBarraIndexDeAluno;
	alunos[numeroAlunoBarraIndexDeAluno].elo = i; 
}


int menu() {
	
	// DECLARAR VARIAVEL PARA
	// GUARDAR OPCAO
	int ch;
	
	
	// LER E VALIDAR VARIAVEL
	// ENQUANTO NAO INSERIRMOS UMA
	// OPCAO VALIDA
	do {
		
		printf("\n");
		printf("\n1. Insere aluno ");
		printf("\n2. Escreve todos os alunos");
		printf("\n3. Sair ");
		
		printf("\n\nOpcao escolhida: ");
		
		scanf(" %d", &ch );
		
	} while ( ( ch != 1 ) && ( ch != 2 ) && ( ch != 3 ) );
	
	// RETORNAR VARIAVEL COM OPCAO ESCOLHIDA
	return ch;

}
