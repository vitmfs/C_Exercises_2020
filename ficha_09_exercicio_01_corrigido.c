// Um clube de viagens necessita gerir os seus socios.
// Faca um programa em C que deve permitir:
// - Inserir sócios: número e nome
// - Inserir destino de viagens
// - Inscrever sócios em viagens
// - Listar socios por numero: nome, numero e destino de viagens
// - Listar viagens por nome de destino: nome, numero e nome de socios inscritos nesse destino

#include <stdio.h>
#include <string.h>


typedef struct {
	
	int 	num;
	char 	nome[20];
	
	int 	PrimPV;
	
	int 	elo;
} P;

typedef struct {
	
     char 	nome[20];
      int 	PrimVP;
      
     int 	elo;
} V;  

typedef struct {
	
     int eloP;
     int ProxVP; 
     
}  RVP;
     
     
typedef struct {
	
     int eloP;
     int ProxPV;  
	  
} RPV;
        
int n;
int nc;
int npv;
int nvp;

void inicializa( P* x, V* y, RVP* VP, RPV* PV ) {
	
	x[0].elo = 0;
	y[0].elo = 0;
	strcpy( y[0].nome,"ZZZ" );
	VP[0].eloP = 0;
	PV[0].eloP = 0;
	
}


void EscreveTodosPessoas( P* x, V* y,  RVP* VP ) {  
          
	int i;
	int queviagens;
	int LiVPqueviagens;
	
	i = x[0].elo;
	
	while ( i != 0 )
	{
		if ( x[i].PrimPV == 0 ) {
			
			printf( "\nnum: %d nome %s sem viagens", x[i].num, x[i].nome );
			
		} else {
		
			queviagens = x[i].PrimPV;
			printf( "\nnum: %d nome %s viagens:", x[i].num, x[i].nome );
			
			while ( queviagens != 0 )
			{
				LiVPqueviagens = VP[queviagens].eloP;   
				printf( "\n %s", y[LiVPqueviagens].nome );
				queviagens = VP[queviagens].ProxVP;
			}
		}
		
		
		i = x[i].elo; 
	}  

}


void EscreveTodosviagens( P* x, V* y, RPV* PV ) {  
         
	int i;
	int temp;
	int liVPtemp;
	
	i = y[0].elo;
	
	while ( i != 0 )
	{
		temp = y[i].PrimVP;
		
		if ( temp == 0 ) {
			
			printf( "\nviagens %s sem Pessoas", y[i].nome );
			
		} else {
			
			printf( "\nviagens %s Pessoas:", y[i].nome );
			while ( temp != 0 )
			{
				liVPtemp=PV[temp].eloP;
				printf( "\nnum: %d nome %s ", x[liVPtemp].num, x[liVPtemp].nome );
				temp = PV[temp].ProxPV;
			}
		
		}
		
		
		i = y[i].elo; 
	}  

}


P LeUm() {
	
	P um;
	
	do {
		
		printf( "\nQual o número do pessoa a inserir?" );
		scanf( " %d", &um.num );
		
	} while ( um.num <= 0 );
	
	
	printf( "\nQual o nome do pessoa %d?", um.num) ;
	scanf(" %s", &um.nome);
	
	um.PrimPV = 0;
	return um;
}


void ColocaUm( P* x, P um ) {
	
	int i; 
	int ant; 
	    
	n++; 
	
	x[n] = um;
	
	i = x[0].elo;
	ant = 0;
	
	while ( ( i != 0) && ( x[i].num < x[n].num) ) {
		
		ant = i;
		i = x[i].elo;
	
	}
	
	x[ant].elo = n;
	x[n].elo = i;  
	x[n].PrimPV = 0;

}

V LeDois() {
	
	V dois;
	
	printf( "\nQual o nome do viagens?" );
	scanf( " %s", &dois.nome );
	
	return dois;

}


void ColocaDois( V* y, V dois ) {
	
	int i;
	int ant;
	    
	nc++;
	
	y[nc] = dois;
	i = y[0].elo;
	ant = 0;
	while ( i != 0 && strcmp(y[i].nome,y[nc].nome) < 0 ) {
		
		ant=i;
		i=y[i].elo;
	}
	
	y[ant].elo = nc;
	y[nc].elo = i;  
	y[nc].PrimVP = 0;

}


int menu() {
	
    int ch;
    
    do {
    	
		printf( "\n1. Insere pessoa " );
	    printf( "\n2. Insere viagens ");
	    printf( "\n3. Increve pessoa em viagens " );
	    printf( "\n4. Listar Pessoas" );
	    printf( "\n5. Listar viagens" );
	    printf( "\n6. Sair " );
	    
	    scanf("%d",&ch);
	    
	} while ( ( ch < 0) || ( ch > 6 ) );
	
    return ch;
	
}
 
  
void pessoaemviagens( P* x, V* y, RVP* VP, RPV* PV ) {

	int num; 
	int i; 
	int j; 
	V dois;
	
	do {
		
		printf( "\nQual o número do pessoa?" );
		scanf( " %d", &num );
	
	} while ( num <= 0 );
	
	
	i = x[0].elo;
	while ( ( i != 0 ) && ( x[i].num < num ) )
	i =x [i].elo;
	
	if ( x[i].num!=num ) {
		
		printf( "\nEsse pessoa nao existe" );
		
	} else {
	
		dois = LeDois();
		
		j = y[0].elo;
		while ( j != 0 && strcmp( y[j].nome,dois.nome) < 0 )
		j = y[j].elo;
		
		if ( strcmp( y[j].nome,dois.nome ) != 0 ) {
			
			printf("\nEssa viagem %s nao existe",dois.nome);
		} else { 
		
			printf( "\nInscrito!" );
			
			nvp++;
			
			VP[nvp].eloP = j;
			
			int aponta = x[i].PrimPV;
			int Ondeaponta = VP[aponta].eloP;
			
			if ( ( x[i].PrimPV == 0 )||( strcmp( y[Ondeaponta].nome, dois.nome ) > 0) ) {
				
				VP[nvp].ProxVP=aponta;
				x[i].PrimPV=nvp;
				
			} else {
			
				int seVPponta = VP[aponta].ProxVP;
				while ( ( seVPponta != 0) && ( strcmp( y[Ondeaponta].nome,dois.nome )  <0 ) ) {
				
					aponta = seVPponta;
					seVPponta = VP[seVPponta].ProxVP;
					Ondeaponta = VP[seVPponta].eloP;
				}
				
				VP[aponta].ProxVP = nvp;
				VP[nvp].ProxVP = seVPponta;
			}
			
			npv++;
			
			PV[npv].eloP = i;
			
			int ant = y[j].PrimVP; 
			Ondeaponta = PV[ant].eloP;
			
			if ( ( ant == 0) || x[Ondeaponta].num > num ) {
			
				PV[npv].ProxPV=ant;
				y[j].PrimVP=npv;
			
			} else {
			
				int temp = PV[ant].ProxPV;
				while ( ( temp != 0 ) && ( x[Ondeaponta].num < num ) ) {
					
					ant = temp;
					temp = PV[temp].ProxPV;
					Ondeaponta = PV[temp].eloP;
				}
				
				PV[ant].ProxPV = npv;
				PV[npv].ProxPV = temp;
			}
		}
	}
}   
           
int main () {

	P x[10];  
	P um;
	V y[10];
	V dois;
	RPV PV[30];
	
	RVP VP[30];
	
	int op;
	
	n = 0; 
	nc = 0; 
	npv = 0; 
	nvp = 0;
	
	inicializa( x, y, VP, PV );
	
	op = menu();
	
	
	while ( op != 6 ) {
		
		switch (op) {
			
			case 1:
				
				if (n==10) {
					
					printf("\nLimite de 10 Pessoas excedido!");
					
				} else { 
				
					um = LeUm();	
					ColocaUm( x, um );
				}
				
				break;
				
			case 2:
				
				if ( nc == 10 ) {
					
					printf("\nLimite de 10 viagens excedido!");
					
				} else {
				
					dois = LeDois();	
					ColocaDois( y, dois );
				}
				
				break;
				
			case 3:
			
				pessoaemviagens( x, y, VP, PV ); 
				
				break;
					
			case 4: 
			
				EscreveTodosPessoas( x, y, VP );
				
				break;
				
			case 5: 
			
				EscreveTodosviagens(x,y,PV);
				
				break;
		}	
			
		op=menu();
	
	}
	
	
	system ("pause");

}

