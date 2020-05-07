
// IMPORTACAO DAS LIBRARIAS
#include <stdio.h>
#include <string.h>


// DEFINICAO DA STRUCT ALUNO
typedef struct {
    
    int     numeroDoAluno;
    char    nomeDoAluno[20];
    int     primeiroGRUPO_DO_ALUNO;
    
    int     proximoALUNO; 
    
} ALUNO;


// DEFINICAO DA STRUCT GRUP0
typedef struct{
    
    char nomeDoGrupo[20];
    int primeiroALUNO_DO_GRUPO;
    
    int proximoGRUPO; 
    
} GRUPO;


//DEFINICAO DA STRUCT GRUPO_DO_ALUNO
typedef struct {
    
    int grupo;
    
    int proximoGRUPO_DO_ALUNO; 
    
} GRUPO_DO_ALUNO;



// DEFINICAO DA STRUCT ALUNO_DO_GRUPO
typedef struct {
    
    int aluno;
    
    int proximoALUNO_DO_GRUPO; 
    
    
} ALUNO_DO_GRUPO;


// CONTADORES DO NUMERO DE STRUCTS DE CADA TIPO CRIADAS
int numeroDeALUNOs;
int numeroDeGRUPOs;
int numeroDeGRUPOS_DO_ALUNO;
int numeroDeALUNOS_DO_GRUPO;



// FUNCAO INICIALIZA
void inicializa(ALUNO* alunos, GRUPO* grupos, GRUPO_DO_ALUNO* gruposDoAluno, ALUNO_DO_GRUPO* alunosDoGrupo) { 
    
    alunos[0].proximoALUNO                  = 0;
    grupos[0].proximoGRUPO                  = 0;
    strcpy(grupos[0].nomeDoGrupo,"ZZZ");
    gruposDoAluno[0].proximoGRUPO_DO_ALUNO  = 0;
    alunosDoGrupo[0].proximoALUNO_DO_GRUPO  = 0;
}


//FUNCAO MENU
int menu() {

    // DECLARAR A VARIAVEL PARA GUARDAR A OPCAO ESCOLHIDA
    int ch;
    
    do {
        
        printf("\n1. Insere aluno ");
        printf("\n2. Insere grupo ");
        printf("\n3. Increve aluno em grupo ");
        printf("\n4. Listar alunos");
        printf("\n5. Listar grupos");
        printf("\n6. Sair ");
        
        scanf(" %d", &ch);
        
    } while ((ch<0) || (ch>6));
    
    return ch;
    
}


// FUNCAO PARA LER ALUNO
ALUNO lerAluno() {
    
    // DECLARAR ALUNO PARA GUARDAR INFORMACAO
    ALUNO alunoLido;
    
    do {
        
        printf("\nQual o número do aluno a inserir?");
        scanf(" %d", &alunoLido.numeroDoAluno);
        
    } while (alunoLido.numeroDoAluno <= 0 );
    
    printf("\nQual o nome do aluno %d?", alunoLido.numeroDoAluno );
    scanf(" %s",&alunoLido.nomeDoAluno);
    
    alunoLido.primeiroGRUPO_DO_ALUNO = 0;
    
    return alunoLido;
}

// FUNCAO LER GRUPO
GRUPO lerGrupo(){
    
    // DECLARAR GRUPO PARA GUARDAR INFORMACAO
    GRUPO grupLido;
    
    printf("\nQual o nome do grupo?");
    scanf(" %s",&grupLido.nomeDoGrupo);
    
    grupLido.primeiroALUNO_DO_GRUPO=0;
    
    return grupLido;
}


// FUNCAO COLOCA ALUNO NO ARRAY DE ALUNOS
void colocaAlunoNoArrayDeAlunos(ALUNO* alunos, ALUNO alunoParaInserir) {
    
    // INDICES DO ATUAL E DO ANTERIOR NO ARRAY
    int i, ant;
    
    // VAMOS INCREMENTAR O NUMERO DE ALUNOS
    // PARA METERNOS NA POSICAO VAZIA
    numeroDeALUNOs++;
    
    // INSERIR O ALUNO NA POSICAO VAZIA
    alunos[numeroDeALUNOs] = alunoParaInserir;
    
    // INDICE DO PRIMEIRO ALUNO REAL
    i = alunos[0].proximoALUNO;
    
    // ANTERIOR VAI SER O ZERO QUE CORRESPONDE 
    // AO INDICE DA CABECA, QUE INDICA QUE A LISTA ACABOU
    ant = 0;
    
    // ENQUANTO A LISTA NAO ACABAR E ENQUANTO O NUMERO DO ALUNO ATUAL FOR MENOR
    // DO QUE O NUMERO DO ALUNO QUE EU PRETENTO INSERIR
    while ((i!=0) && (alunos[i].numeroDoAluno  < alunos[numeroDeALUNOs].numeroDoAluno)) {
        
        // GUARDO O INDICE DO ATUAL DO ATUAL NO ANTERIOR
        ant = i;
        
        // O INDICE ATUAL PASSA AO PROXIMO
        i = alunos[i].proximoALUNO;
        
    }
    
    // QUANDO SE SAIR DO CICLO O INDICE DO PROXIMO ALUNO
    // VAI SER IGUAL AO INDICE DO ALUNO QUE NOS QUEREMOS INSERIR
    
    alunos[ant].proximoALUNO = numeroDeALUNOs;
    
    // O PROXIMO ALUNO DO ALUNO QUE NOS INSERIMOS VAI SER IGUAL AO INDICE DO PROXIMO
    alunos[numeroDeALUNOs].proximoALUNO = i;
    
    
}


//  FUNCAO COLOCA GRUPO NO ARRAY DE GRUPOS
colocaGrupoNoArrayDeGrupos (GRUPO* grupos, GRUPO grupoParaInserir ) {
    
    // INDICES DO ATUAL E DO ANTERIOR NO ARRAY
    int i, ant;
    
    // INCREMENTAMOS O NUMERO DE GRUPOS PARA SABERMOS EM QUE 
    // INDICE DO ARRAY DE GRUPOS VAMOS INSERIR O NOVO GRUPO
    numeroDeGRUPOs++;
    
    // INSERIMOS O NOVO GRUPO NO ARRAY DE GRUPOS NO INDICE CORRESPONDENTE 
    // AO NUMERO DE GRUPOS
    grupos[numeroDeGRUPOs] = grupoParaInserir;
    
    // INDICE DO PRIMEIRO ALUNO REAL
    i = grupos[0].proximoGRUPO;
    
    // ANTERIOR VAI SER O ZERO QUE CORRESPONDE 
    // AO INDICE DA CABECA 0, QUE INDICA QUE A LISTA ACABOU
    ant = 0;
    
    // ENQUANTO A LISTA NAO ACABAR E ENQUANTO O NOME DO GRUPO ATUAL
    // FOR MENOR DO QUE O NOME DO GRUPO QUE PRETENDEMOS INSERIR
    // PASSAMOS A FRENTE
    while (i!=0 && strcmp(grupos[i].nomeDoGrupo , grupos[numeroDeGRUPOs].nomeDoGrupo) < 0) {
        
        // O INDICE DO ATUAL GUARDAMOS NO ANTERIO
        ant= i;
        
        // O INDICE DO ATUAL PASSA A SER O INDICE DO PROXIMO
        i = grupos[i].proximoGRUPO;
        
    }
    
    // QUANDO SE SAIR DO CICLO O PROXIMO GRUPO DO ANTERIOR
    // VAI TER QUE CORRESPONDER AO INDICE DO GRUPO QUE NOS INSERIOMOS
    grupos[ant].proximoGRUPO = numeroDeGRUPOs;
    
    // O PROXIMO GRUPO DO GRUPO QUE NOS INSERIMOS VAI TER DE SER IGUAL AO INDICE DO SEGUINTE
    grupos[numeroDeGRUPOs].proximoGRUPO = i;
    

    
}

/*
// FUNCAO PARA ASSOCIAR UM GRUPO E UM AL
2


void alunoemGrupo( ALUNO* alunos, GRUPO* grupos, GRUPO_DO_ALUNO* gruposDoAluno,  ALUNO_DO_GRUPO* alunosDoGrupo ) {
    
    int numeroDoAlunoAAssociar;
    
    // O I E PARA PERCORRER OS ALUNOS
    int i;
    
    // O J E PARA PERCORRER OS GRUPOS
    int j; 

    
    GRUPO grupoAAssociar;
    
    // PERGUNTAR QUAL O NUMERO DE ALUNO
    do {
        
        printf("\nQual o número do aluno?");
        scanf(" %d",&numeroDoAlunoAAssociar);
        
    }  while ( numeroDoAlunoAAssociar<=0 );
    
    
    // TENTAMOS ENCONTRAR O ALUNO NO ARRAY DE ALUNOS ATRAVES DO NUMERO DE ALUNO
    
    // O I VAI SER O INDICE DO PRIMEIRO ALUNO POR ORDEM DE NUMERO
    i = alunos[0].proximoALUNO;
    
    // ENQUANTO A LISTA NAO ACABAR E ENQUANTO O NUMERO DO ALUNO ATUAL FOR MENOR DO QUE
    // O NUMERO DO ALUNO QUE NOS QUEREMOS PASSAMOS PARA O PROXIMO
    while ((i!=0) && ( alunos[i].numeroDoAluno < numeroDoAlunoAAssociar))
         i = alunos[i].proximoALUNO;
         
    // SALTA FORA DO CICLO QUANDO O NOME FOR IGUAL OU MAIOR
    if (alunos[i].numeroDoAluno != numeroDoAlunoAAssociar)
        printf("\nEsse aluno nao existe");
    else
    {
        grupoAAssociar = lerGrupo();
        
        
        // PERCORRER O ARRAY DOS GRUPOS
        
        // INICIALIZAR J COM O PRIMEIRO GRUPO POR ORDEM ALFABETICA
        j = grupos[0].nomeDoGrupo;
        
        // ENQUANTO A LISTA DE GRUPOS NAO TERMINAR E
        // O NOME DO GRUPO ATUAL FOR MENOR DO QUE O NOME DO
        // GRUPO A ASSOCIAR PASSA A FRENTE
        while ( j!=0 && strcmp(grupos[j].nomeDoGrupo, grupoAAssociar.nomeDoGrupo) < 0 )
            j = grupos[j].proximoGRUPO;
        
        // SAI QUANDO FOR IGUAL OU MAIOR
        // SE O NOME NAO FOR IGUAL QUER DIZER QUE O GRUPO NAO EXISTE
        if (strcmp(grupos[j].nomeDoGrupo , grupoAAssociar.nomeDoGrupo) !=0 )
            printf("\nEsse grupo %s nao existe",grupoAAssociar.nomeDoGrupo);
        else
        { 
        	// NESTE MOMENTO TEMOS O INDICE I DO ALUNO QUE QUEREMOS INSERIR
        	// NESTE MOMENTO TEMOS O INDICE J DO GRUPO QUE QUEREMOS INSERIR
        	// E VAMOS FAZER AS INCRICOES
            printf("\nInscrito!");
            
            numeroDeGRUPOS_DO_ALUNO++;
            
            
            // O J VAI SER O INDICE DO GRUPO NO ARRAY DE GRUPOS QUE TEM O NOME IGUAL AO QUE TU INSERISTE QUANDO LESTE O GRUPO
            // E GUARDAR NO GRUPOAASSOCIAR
            gruposDoAluno[numeroDeGRUPOS_DO_ALUNO].grupo = j;
            
            // O PRIMEIRO GRUPO_DO_ALUNO DO ALUNO QUE TU QUERES ASSOCIAR
            int primeiroGRUPO_DO_ALUNODoAlunoAAssociar = alunos[i].primeiroGRUPO_DO_ALUNO;
            
            // VAI BUSCAR O INDICE DO GRUPO NO GRUPO_DO_ALUNO
            int indiceDoGrupo = gruposDoAluno[primeiroGRUPO_DO_ALUNODoAlunoAAssociar].grupo;
            
            // SE O PRIMEIRO GRUPO_DO_ALUNO ESTIVER A 0 OU SE O NOME DO GRUPO A ASSOCIAR FOR MAIOR DO QUE O DO GRUPO ATUAL
            if ((alunos[i].primeiroGRUPO_DO_ALUNO==0) || (strcmp(grupos[indiceDoGrupo].nomeDoGrupo ,grupoAAssociar.nomeDoGrupo) > 0) )
            {
                gruposDoAluno[numeroDeGRUPOS_DO_ALUNO].proximoGRUPO_DO_ALUNO = primeiroGRUPO_DO_ALUNODoAlunoAAssociar;
                alunos[i].primeiroGRUPO_DO_ALUNO = numeroDeGRUPOS_DO_ALUNO;
            }
            else
            {
            	// INICIALIZAR INDICE DO PROXIMO GRUPO_DE_ALUNO COM PRIMEIRO INDICE
                int indiceDoProximoGRUPO_DE_ALUNO = gruposDoAluno[numeroDeGRUPOS_DO_ALUNO].proximoGRUPO_DO_ALUNO;
                int indiceDoGRUPO_DE_ALUNOAnterior = 0;
                
                // ENQUANTO O NOME DO GRUPO ATUAL FOR MENOR DO QUE O NOME DO GRUPO A ASSOCIAR PASSA A FRENTE
                while ((indiceDoProximoGRUPO_DE_ALUNO!=0) && (strcmp(grupos[j].nomeDoGrupo, grupoAAssociar.nomeDoGrupo)<0)) {
                    
					indiceDoProximoGRUPO_DE_ALUNO = indiceDoGRUPO_DE_ALUNOAnterior;
                    //segaponta=gruposDoAluno[segaponta].ProxGA;
                    //Ondeaponta=gruposDoAluno[segaponta].eloG;
                }
                
                gruposDoAluno[indiceDoProximoGRUPO_DE_ALUNO].proximoGRUPO_DO_ALUNO = numeroDeGRUPOS_DO_ALUNO;
                //gruposDoAluno[numeroDeGRUPOS_DO_ALUNO].proximoGRUPO_DO_ALUNO=segaponta;
            }
            
            numeroDeGRUPOS_DO_ALUNO++;
            
            
            alunosDoGrupo[numeroDeALUNOS_DO_GRUPO].aluno = i;
            int ant=grupos[j].primeiroALUNO_DO_GRUPO;
            int alunoDoGrupoAnterior=alunosDoGrupo[ant].aluno;
            
            if ((alunoDoGrupoAnterior==0) ||alunos[i].numeroDoAluno> 8) {
                alunosDoGrupo[numeroDeALUNOS_DO_GRUPO].proximoALUNO_DO_GRUPO=alunoDoGrupoAnterior;
                grupos[j].primeiroALUNO_DO_GRUPO=numeroDeALUNOS_DO_GRUPO;
                
            } else {
                int temp=alunosDoGrupo[alunoDoGrupoAnterior].proximoALUNO_DO_GRUPO;
                 while ((temp!=0) && (grupos[temp].proximoGRUPO < numeroDeGRUPOs)) {
                     ant=temp;
                    temp=alunosDoGrupo[temp].proximoALUNO_DO_GRUPO;
                    alunoDoGrupoAnterior=alunosDoGrupo[temp].aluno;
            }
            
            alunosDoGrupo[ant].proximoALUNO_DO_GRUPO=numeroDeALUNOS_DO_GRUPO;
            alunosDoGrupo[numeroDeALUNOS_DO_GRUPO].proximoALUNO_DO_GRUPO=temp; 
        } 
        }
     }
}
*/

// FUNCAO PARA ESCREVER TODOS OS ALUNOS
void escreveTodosAlunos(ALUNO* alunos, GRUPO* grupos, GRUPO_DO_ALUNO* gruposDoAluno) {
	
	int i, grupoDoAlunoTemporario,Ligaquegrupo;
	
	// INICIALIZA O I COM O PRIMEIRO ALUNO REAL
	i = alunos[0].proximoALUNO;
	
	// ENQUANTO A LISTA NAO ACABAR
	while (i!=0)
	{
	    // SE O PRIMEIRO GRUPO DO ALUNO FOR 0
		if (alunos[i].primeiroGRUPO_DO_ALUNO == 0)
			printf("\nnum: %d nome %s semgrupo", alunos[i].numeroDoAluno, alunos[i].nomeDoAluno);
		else
		{
		    // 
			grupoDoAlunoTemporario=alunos[i].primeiroGRUPO_DO_ALUNO;
				printf("\nnum: %d nome %s Grupos:",alunos[i].numeroDoAluno, alunos[i].nomeDoAluno);
			// ENQUANTO A LISTA DE GRUPO_DE_ALUNO NAO ACABAR
			while (grupoDoAlunoTemporario!=0)
			{
			    // GUARDA O GRUPO DE GRUPO_DE_ALUNO
				Ligaquegrupo=gruposDoAluno[grupoDoAlunoTemporario].grupo;
				// ESCREVE O NOME DO GRUPO
				printf("\n %s",grupos[Ligaquegrupo].nomeDoGrupo);
				// ATUALIZA O GRUPO_DO_ALUNO TEMPORARIO
				grupoDoAlunoTemporario = gruposDoAluno[grupoDoAlunoTemporario].proximoGRUPO_DO_ALUNO;
			}
		}
		
		// ATUALIZA O ALUNO
		i = alunos[i].proximoALUNO; 
	} 

}

// FUNCAO QUE ESCREVE TODOS OS GRUPOS
void escreveTodosGrupos(ALUNO* alunos, GRUPO* grupos, ALUNO_DO_GRUPO* alunosDoGrupo) {
	
	// CONTADORES
	int i;
	int temp;
	int ligatemp;
	
	// INICIALIZAMOS I COM O INDICE DO PRIMEIRO GRUPO REAL
	i = grupos[0].proximoGRUPO ;
	
	// ENQUANTO A LISTA DE GRUPOS NAO ACABAR
	while (i!=0)
	{
	    // INICIALIZAMOS TEMP COM A LIGACAO PARA O PRIMEIRO ALUNO_DO_GRUPO DE CADA GRUPO
		temp=grupos[i].primeiroALUNO_DO_GRUPO;
		
		// SE O PRIMEIRO ALUNO_DO_GRUPO FOR 0 QUER DIZER QUE O GRUPO NAO TEM ALUNOS
		if (temp==0)
			printf("\ngrupo%s sem alunos",grupos[i].nomeDoGrupo);
		else
		{
		    // IMPRIME O NOME DO GRUPO
			printf("\ngrupo%s Alunos:",grupos[i].nomeDoGrupo);
			// ENQUANTO A LISTA DE ALUNO_DE_GRUPO NAO ACABAR
			while (temp!=0)
			{
			    // INICIALIZA O INDICE DO ALUNO
				ligatemp=alunosDoGrupo[temp].aluno;
				// IMPRIME O NUMERO E NOME DO ALUNO
				printf("\nnum: %d nome %s ", alunos[ligatemp].numeroDoAluno, alunos[ligatemp].nomeDoAluno);
				// ATUALIZA O INDICE DO ALUNO_DO_GRUPO
				temp=alunosDoGrupo[temp].proximoALUNO_DO_GRUPO;
			}
		}
		
		// ATUALIZA O GRUPO
		i = grupos[i].proximoGRUPO; 
	} 
}





int main ()
{
    ALUNO alunos[10];
    
    ALUNO alunoTemporario;
    
    GRUPO grupos[10];
    
    GRUPO grupoTemporario;
    
    GRUPO_DO_ALUNO gruposDoAluno[30];
    
    ALUNO_DO_GRUPO alunosDoGrupo[30];
    
    
    // INICIALIZACAO DOS CONTADORES
    int numeroDeALUNOs          = 0;
    int numeroDeGRUPOs          = 0;
    int numeroDeGRUPOS_DO_ALUNO = 0;
    int numeroDeALUNOS_DO_GRUPO = 0;
    
    

    int nj=0;

    int temp= 0;
     int ligatemp= 0;
     
    
    // DECLARACAO DA VARIAVEL PARA GUARDAR A OPCAO ESCOLHIDA
    int op;
    
    inicializa( alunos,  grupos, gruposDoAluno, alunosDoGrupo);
    
    op = menu();
    
    while ( op != 6 )
    {
        switch (op) {
        
            case 1:
                if (numeroDeALUNOs == 30 )
                    printf("\nLimite de 30 alunos excedido!");
                else{
                    
                    alunoTemporario = lerAluno(); 
                    
            
                    colocaAlunoNoArrayDeAlunos( alunos, alunoTemporario );
                    
                }
                
                break;
                
            case 2:
            
                grupoTemporario = lerGrupo();
                
                colocaGrupoNoArrayDeGrupos(grupos,grupoTemporario);
                break;
            
                    
                
            case 3: 
            
                //alunoemGrupo( alunos, grupos, gruposDoAluno,  alunosDoGrupo ); 
                
                printf("\nInsere Aluno em Grupo Placeholder.");
                
                break;
                
            case 4: 
            
                escreveTodosAlunos(alunos, grupos, gruposDoAluno); 
                
                break;
                
            case 5: 
            
                escreveTodosGrupos(alunos, grupos, alunosDoGrupo); 
                
                break;
        }
        
        op=menu();
    }
    
    
    system("pause");
}

