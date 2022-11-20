//MANIPULAÇÃO DE LISTA SIMPLES - LINKED LIST 
#include <stdio.h>
#include <stdlib.h>

//=============== STRUCT ===================
typedef struct No{
	int dado;
	No *link;
}No;

//================== PROTÓTIPOS FUNÇÕES E PROCEDIMENTOS ====================
No* criaNo(No*x, int y);

No* addNoFim(No* x, int y);

No* addNoInicio(No*x, int y);

int contaNos(No* x); 

void addNoPosicao(No* x, int y, int z);

No* deletaPrimeiroNo(No* x);

No* deletaUltimoNo(No* x); //arrumar, pois está contando errado

void deletaNoPosicao(No** x, int z);

No* deletaLista(No* x);

void imprimeLista(No* x);

//===================== INT MAIN ======================
int main(){
	
	//cabeça da lista, sem inicialização de conteúdo dentro do campo dado
	No* cabeca = NULL;	
	
	int op, x;
	
	do{
		printf("\n(1) - Inicializar lista\n(2) - Add no inicio\n(3) - Add no final\n(4) - Add na posicao");
		printf("\n(5) - Deletar primeiro noh\n(6) - Deletar ultimo noh\n(7) - Deletar noh especifico");
		printf("\n(8) - Quantidade de nohs\n(9) - Deletar lista/SAIR\n(10) - Visualizar lista");
		scanf("%d", &op);
		
		switch(op){
			case 1:{
				int p;
				
				printf("\nINFORME O CONTEUDO PARA INICIALIZAR O NOH:");
				scanf("%d", &p);
				
				cabeca = criaNo(cabeca, p);
				break;
			}
			case 2:{
				printf("\nINFORME O CONTEUDO DO NOH:");
				scanf("%d", &x);
				
				cabeca = addNoInicio(cabeca, x);
				break;
			}
			case 3:{
				int y;
				
				printf("\nINFORME O CONTEUDO DO NOH:");
				scanf("%d", &y);
				
				cabeca = addNoFim(cabeca, y);
				break;
			}
			case 4:{
				int k, j;
				
				printf("\nINFORME O CONTEUDO E POSICAO:");
				scanf("%d %d", &k, &j);
				
				addNoPosicao(cabeca, k, j);
				break;
			}
			case 5:{
				cabeca = deletaPrimeiroNo(cabeca);
				break;
			}
			case 6:{
				cabeca = deletaUltimoNo(cabeca);
				break;
			}
			case 7:{
				int m;
				
				printf("\nINFORME A POSICAO A SER DELETADA:");
				scanf("%d", &m);
				
				deletaNoPosicao(&cabeca, m);
				break;
			}
			case 8:{
				int qtd;
				
				qtd = contaNos(cabeca);
				
				printf("\nTOTAL DE NOHS = %d", qtd);
				break;
			}
			case 9:{
				cabeca = deletaLista(cabeca);
				break;
			}
			case 10:{
				imprimeLista(cabeca);
				break;
			}
		}
	}while(op!=9);
	
	return 0;
}

//====================== FUNÇÕES E PROCEDIMENTOS ======================

No* criaNo(No*x, int y){
	
	//se a cabeça NÃO for NULL, quer dizer que ela já contém pelo menos UM nó, então imprime a mensagem abaixo
	if(x){
		printf("\nA lista ja foi incializada!");
	}else{
		No* temp = (No*)malloc(sizeof(No));
		temp->dado = y;
		temp->link = NULL;
		x = temp;
	}
	return x;
}

No* addNoFim(No* x, int y){
	
	//se a cabeça for IGUAL a NULL, entãa é preciso criar um nó antes, com a função criaNo, por esse motivo é apresentada a msg abaixo
	if(!x){
		printf("\nEh necessario criar um nó antes de add novos nós!");
	}else{
		No* temp = x;
		
		//é necessário percorrer por toda a lista, até chegar no último nó para add um novo ao fim
		//IMPORTANTE: quando vai percorrer a lista, PRECISA SIM colocar -> link, se não não funciona

		while(temp->link != NULL){
			temp = temp->link;
		}
		
		//criação dinâmica do novo nó que será add ao fim da lista
		No* novoNo = (No*)malloc(sizeof(No));
		//atribuindo valores aos campos do nó
		novoNo->dado = y;
		novoNo->link = NULL;
		
		//declarando que o campo link do PENÚLTIMO (que na verdade ainda é o último, que parou no while) nó vai receber o endereço do novo nó
		temp->link = novoNo;
		
	}
	return x;
	
}

No* addNoInicio(No*x, int y){
	
	if(!x){
		printf("\nA lista esta VAZIA!");
	}else{
		
		//criando novo nó e fazendo as atribuições de valores necessárias
		No* temp = (No*)malloc(sizeof(No));
		temp->dado = y;
		temp->link = NULL;
		
		temp->link = x;
		
		//por fim, x (que é a cabeça) deixa de apontar para o nó de antes e começa a ter como cabeça o nó criado agora, que foi add no início
		x = temp;
	}
	return x;
	
}

void addNoPosicao(No* x, int y, int z){

	//verificação se a lista está vazia
	if(!x){
		printf("\nLista VAZIA!");
	}else{
		No* temp = x;
		No* novoNo = (No*)malloc(sizeof(No));
		novoNo->dado = y;
		novoNo->link = NULL;
		
		while(z != 2){ //descontado 2 unidades para que o nó fique exatamente na posição z
			temp = temp->link;
			z--;
		}
		
		novoNo->link = temp->link;
		temp->link = novoNo;
	}
}

int contaNos(No* x){
	
	int counter = 0; 
	
	if(!x){
		printf("\nNao eh possivel fazer a contagem, a lista esta VAZIA!");
	}else{
		No* temp = x;
		
		while(temp != NULL){
			counter++;
			temp = temp->link;
		}
		x = temp;	
	}
	
	return counter;
}

No* deletaPrimeiroNo(No* x){
	
	if(!x){
		printf("\nLista Vazia, nao ha no para deletar!");
	}else{
		No* temp = x->link;
		
		free(x);
		x = NULL;
		
		x = temp;
	}
	return x;
}

No* deletaUltimoNo(No* x){
	
	if(!x){
		printf("\nLista Vazia, nao eh possivel deletar no");
	}else{
		No* temp = x;
		
		while(temp->link != NULL){
			temp = temp->link;

		}
			
	}
}

No* deletaLista(No* x){
	
	if(!x){
		printf("\nLista Vazia, nao eh possivel deletar a mesma");
	}else{
		No* temp = x;
		No* aux = NULL;
		
		while(temp != NULL){
			temp = temp->link;
			free(x);
			x = temp;
		}	
	}
	return x;
}

void deletaNoPosicao(No** x, int z){
	
	if(!*x){
		printf("\nLista vazia, nao eh possivel deletar esse no");
	}else{
		No* temp = *x;
		No* temp2 = *x;
		
		while(z != 1){
			temp = temp2;
			temp2 = temp2->link;
			z--;
		}
			
		temp->link = temp2->link;
		free(temp2);
		temp2 = NULL;	
	}
}

void imprimeLista(No* x){
	
	if(!x){
		printf("\nLista Vazia!");
	}else{
		No* temp = x;
		
		printf("\n");
		while(temp != NULL){
			printf("%d\t", temp->dado);
			temp = temp->link;
		}
	}
}
