//LISTA SIMPLES
#include <stdio.h>
#include <stdlib.h>

//====================================================================================

typedef struct node{

	int data;
	struct node *link;

}Node;

//====================================================================================

Node *alocaNo(Node *x, int y);

void imprimeLista(Node *x);

Node *insereFinalReturn(Node *x, int y);

void insereFinalVoid(Node **x, int y);

Node *insereInicioReturn(Node *x, int y);

void insereInicioVoid(Node **x, int y);

int contaNos(Node *x);

Node *deletaPrimeiroReturn(Node* x);

void deletaPrimeiroVoid(Node **x);

Node *deletaUltimoReturn(Node *x);

void deletaUltimoVoid(Node **x);

Node *addNaPosicaoReturn(Node *x, int pos, int dado);

void addNaPosicaoVoid(Node *x, int pos, int dado); //único void que não precisa de pointer of pointer

Node *deletaNaPosicaoReturn(Node *x, int pos);

void deletaNaPosicaoVoid(Node **x, int pos);

Node *deletaListaReturn(Node *x);

void deletaListaVoid(Node **x);

//====================================================================================

int main(){

	Node *head = NULL;

    printf("\n-> ALOCACAO PRIMIERO NO:\n");
	//alocando primeiro nó da lista
	head = alocaNo(head, 8);
	
	imprimeLista(head);
	
	//====================================================================================
	
	printf("\n-> INSERINDO NO FINAL DA LISTA:\n");

	//inserindo nó na lista com uma função que RETORNA Node
	head = insereFinalReturn(head, 7);
	head = insereFinalReturn(head, 9);
	head = insereFinalReturn(head, 3);

	//inserindo nó na lista com uma função que é VOID e NÃO RETORNA, apenas modifica pelo endereço do ponteiro
	insereFinalVoid(&head, 1);
	insereFinalVoid(&head, 4);
	insereFinalVoid(&head, 6);

	//imprimindo lista para verificar modificações feitas nela
	imprimeLista(head);
	
	//====================================================================================

    printf("\n-> INSERINDO NO INICIO DA LISTA\n");

    //inserindo no INICIO com função que RETORNA
    head = insereInicioReturn(head, 99);
    head = insereInicioReturn(head, 22);
    head = insereInicioReturn(head, 88);

    //inserindo no INICIO com função VOID
    insereInicioVoid(&head, 11);
    insereInicioVoid(&head, 62);
    insereInicioVoid(&head, 90);

    //imprimindo para verificar modificações
    imprimeLista(head);

    printf("\n-> CONTAGEM ATUAL DE NOHS = %d\n", contaNos(head));

	//====================================================================================

    printf("\n-> DELETANDO PRIMEIRO NOH DA LISTA:\n");

    head = deletaPrimeiroReturn(head);
    deletaPrimeiroVoid(&head);

    //impressão para verificação
    imprimeLista(head);

    printf("\n-> CONTAGEM ATUAL DE NOHS = %d\n", contaNos(head));
    
	//====================================================================================

    printf("\n-> DELETANDO ULTIMO NOH DA LISTA:\n");

    head = deletaUltimoReturn(head);
    deletaUltimoVoid(&head);

    imprimeLista(head);

    printf("\n-> CONTAGEM ATUAL DE NOHS = %d\n", contaNos(head));
    
	//====================================================================================
	
	printf("\n->ADICIONANDO NÓ EM DETERMINADA POSIÇÃO:\n");
	
	int posicao;
	
	//->>>>>>>>> utilizando função que retorna o ponteiro
	
	printf("\nInsira a posição em que deseja add o elemento:");
	scanf("%d", &posicao);
	
	head = addNaPosicaoReturn(head, posicao, 186);
	imprimeLista(head);
	
	//->>>>>>>>> utilizando função que NÃO retorna o ponteiro (VOID)
	
	printf("\nInsira a posição em que deseja add o elemento:");
	scanf("%d", &posicao);
	
	addNaPosicaoReturn(head, posicao, 777);
	imprimeLista(head);
	
	//====================================================================================
	
	printf("\n-> DELETANDO ELEMENTO DE POSIÇÃO ESPECÍFICA:\n");
	
	//->>>>>>>>> utilizando função que retorna o ponteiro
	printf("\n->>> COM RETURN <<<-\n");
	head = deletaNaPosicaoReturn(head, 8);
	imprimeLista(head);
	
	//->>>>>>>>> utilizando função que NÃO retorna o ponteiro (VOID)
	printf("\n->>> SEM RETURN <<<-\n");
	deletaNaPosicaoVoid(&head, 6);
	imprimeLista(head);
	
	//====================================================================================
	
	printf("\n-> DELETANDO A LISTA TODA:\n");
	
	int op;
	
	printf("(1) - COM RETURN\n(2) - SEM RETURN");
	scanf("%d", &op);
	
	switch(op){
	    
	    case 1:{
	        head = deletaListaReturn(head);
	    }break;
	    case 2:{
	        deletaListaVoid(&head);
	    }break;
	}
	
	//o resultado deve ser lista vazia, pois foi deletado todos os elementos
	imprimeLista(head);

	return 0;
}

//====================================================================================

Node *alocaNo(Node *x, int y){

	if(x){
		printf("\nPRIMEIRO no ja foi alocado!");
		return x;
	}

	Node *temp = x;

	temp = (Node*)malloc(sizeof(Node));

	if(!temp){
        printf("\nErro na alocação do no!");
        temp = alocaNo(temp, y);
	}else{
        temp->data = y;
        temp->link = NULL;
	}

	x = temp;

	return x;

}

//====================================================================================

void imprimeLista(Node *x){

    if(x == NULL){
        printf("\nLista vazia!");
        return;
    }

    Node *temp = x;

    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->link;
    }

    x = temp;
}

//====================================================================================

Node *insereFinalReturn(Node *x, int y){

    if(!x){
        printf("\nNao existe lista para add no!");
        return x;
    }

    Node *temp = x;

    while(temp->link != NULL){
        temp = temp->link;
    }

    //novo nó
    Node *novoNo = (Node*)malloc(sizeof(Node));

    if(!novoNo){
        printf("Nao foi possivel alocar o noh!");
    }

    novoNo->data = y;
    novoNo->link = NULL;

    //apontando o penúltimo nó para o último
    temp->link = novoNo;

    //não é necessário fazer a atribuição x = temp

    return x;
}

//====================================================================================

void insereFinalVoid(Node **x, int y){

    if(!*x){
        printf("\nNao existe lista para add no!");
        return;
    }

    Node *temp = *x;

    while(temp->link != NULL){
        temp = temp->link;
    }

    //criando novo nó
    Node *novoNo = (Node*)malloc(sizeof(Node));

    if(!novoNo){
        printf("\nNao foi possivel alocar novo no!");
    }

    novoNo->data = y;
    novoNo->link = NULL;

    temp->link = novoNo;
}

//====================================================================================

Node *insereInicioReturn(Node *x, int y){

    if(!x){
        printf("\nNao existe lista para add no!");
        return x;
    }

    //nó temporario para x
    Node *temp = x;

    Node *novoNo = (Node*)malloc(sizeof(Node));

    if(!novoNo){
        printf("\nNao foi possivel alocar o novo no!");
    }

    novoNo->data = y;
    novoNo->link = NULL;
    novoNo->link = temp;

    x = novoNo;

    return x;
}

//====================================================================================

void insereInicioVoid(Node **x, int y){

    if(!*x){
        printf("\nNao existe lista para add no!");
    }

    Node *temp = *x;

    //alocando novo No
    Node *novoNo =(Node*)malloc(sizeof(Node));

    if(!novoNo){
        printf("\nNao foi possivel alocar o novo no!");
    }

    novoNo->data = y;
    novoNo->link = NULL;
    novoNo->link = temp;

    *x = novoNo;
}

//====================================================================================

int contaNos(Node *x){

    if(!x){
        return 0;
    }

    Node *temp = x;
    int counter = 0;

    while(temp != NULL){
        counter++;
        temp = temp->link;
    }

    return counter;
}

//====================================================================================

Node *deletaPrimeiroReturn(Node* x){

    if(!x){
        printf("\nNao existe lista para deletar no!");
        return x;
    }

    //nó temporário recebe o endereço do segundo nó da lista
    Node *temp = x->link;

    //liberando/deletando primeiro nó da lista
    free(x);
    x = NULL;

    //devolvendo a nova lista para x
    x = temp;

    return x;
}

//====================================================================================

void deletaPrimeiroVoid(Node **x){

    if(!*x){
        printf("\nNao existe lista para deletar no!");
        return;
    }

    Node *temp = (*x)->link;

    free(*x);
    *x = NULL;

    *x = temp;
}

//====================================================================================

Node *deletaUltimoReturn(Node *x){

    if(!x){
        printf("\nNao existe lista para deletar no!");
        return x;
    }

    Node *temp = x;

    while(temp->link->link != NULL){
        temp = temp->link;
    }

    free(temp->link);
    temp->link = NULL;

    return x;
}

//====================================================================================

void deletaUltimoVoid(Node **x){

    if(!*x){
        printf("\nNao existe lista para deletar no!");
        return;
    }

    Node *temp = *x;

    while(temp->link->link != NULL){
        temp = temp->link;
    }

    free(temp->link);
    temp->link = NULL;
}

//====================================================================================

Node *addNaPosicaoReturn(Node *x, int pos, int dado){
    
    if(!x){
        printf("\nNao existe lista para add no!");
        return x;
    }
    
    if(pos > contaNos(x)){
        printf("\nA posicao excede a quantidade de nós da lista!\n");
        return x;
    }
    
    Node *temp = x;
    
    //alocando o nó antes de adicionar ele na determinada posição da lista
    Node *novoNo = (Node*)malloc(sizeof(Node));
    novoNo->data = dado;
    novoNo->link = NULL;
   
    pos--;
    
    do{
        pos--;
        temp = temp->link;
        
    }while(pos != 1);
    
    //o link do novoNo vai receber o restante da lista que o do..while nem chegou a passar
    novoNo->link = temp->link;
    
    temp->link = novoNo;
    
    return x;
}

//====================================================================================

void addNaPosicaoVoid(Node *x, int pos, int dado){
    
    if(!x){
        printf("\nNao existe lista para adicionar elemento!\n");
        return;
    }
    
    if(pos > contaNos(x)){
        printf("\nA posicao excede a quantidade de nós da lista!\n");
        return;
    }
    
    Node *temp = x;
    
    //alocando novo nó antes de adicioná-lo na lista
    Node *novoNo = (Node*)malloc(sizeof(Node));
    novoNo->data = dado;
    novoNo->link = NULL;
    
    pos--;
    
    do{
        pos--;
        temp = temp->link;
    }while(pos != 2);
    
    novoNo->link = temp->link;
    temp->link = novoNo;
    
}

//====================================================================================

Node *deletaNaPosicaoReturn(Node *x, int pos){
    
    if(!x){
        printf("\nNao existe lista para remover elemento!\n");
        return x;
    }
    
    if(pos > contaNos(x)){
        printf("\nA posicao excede a quantidade de nós da lista!\n");
        return x;
    }
    
    Node *atual = x;
    Node *posterior = x;
    
    do{
        
        posterior = atual;
        atual = atual->link;
        pos--;
        
    }while(pos != 1);
    
    posterior->link = atual->link;
    free(atual);
    atual = NULL;
    
    return x;
}

//====================================================================================

void deletaNaPosicaoVoid(Node **x, int pos){
    
    if(!*x){
        printf("\nNao existe lista para remover elemento!\n");
        return;
    }
    
    if(pos > contaNos(*x)){
        printf("\nA posicao excede a quantidade de nós da lista!\n");
        return;
    }
    
    Node *atual = *x;
    Node *posterior = *x;
    
    do{
        posterior = atual;
        atual = atual->link;
        pos--;
        
    }while(pos != 1);
    
    posterior->link = atual->link;
    free(atual);
    atual = NULL;
}

//====================================================================================

Node *deletaListaReturn(Node *x){
    
    if(!x){
        printf("\nA lista ja esta vazia!");
        return x;
    }
    
    Node *temp = x;
    
    while(temp!= NULL){
        temp = temp->link;
        free(x);
        x = temp;
    }
    
    return x;
}

//====================================================================================

void deletaListaVoid(Node **x){
    
    if(!*x){
        printf("\nA lista ja esta vazia!");
        return;
    }
    
    Node *temp = *x;
    
    while(temp != NULL){
        temp = temp->link;
        free(*x);
        *x = temp;
    }
}
