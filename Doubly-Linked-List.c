//LISTA DUPLAMENTE ENCADEADA
#include <stdio.h>
#include <stdlib.h>

//====================================================================================

typedef struct node{
    
    int data;
    struct node *prev;
    struct node *next;
    
}Node;

//====================================================================================

Node *alocaNo(Node *x, int y);

void imprimeLista(Node *x);

void imprimeListaContrario(Node *x);

Node *insereFinal(Node *x, int y);

Node *insereInicio(Node *x, int y);

int contaNos(Node *x);

Node *removePrimeiroNo(Node *x);

Node *removeUltimoNo(Node *x);

Node *insereNaPosicao(Node *x, int pos, int data);

Node *removeNoPosicao(Node *x, int pos);

Node* deletaLista(Node *x);

//====================================================================================

int main()
{
    int op;
    
    Node *head = NULL;
    
    while(op != 12){
        printf("\n(1) - ALOCAR PRIMEIRO NO\n(2) - INSERIR NÓ NO FINAL\n(3) - INSERIR NÓ NO INÍCIO");
        printf("\n(4) - IMPRIMIR LISTA\n(5) - IMPRIMIR LISTA AO CONTRÁRIO");
        printf("\n(6) - INVERTER LISTA\n(6) - CONTA NÓS\n(7) - REMOVE PRIMEIRO NÓ\n(8) - REMOVE ÚLTIMO NÓ");
        printf("\n(9) - DELETAR NÓ ESPECÍFICO\n(10) - DELETAR LISTA TODA\n(11) - INSERE NA POSIÇÃO");
        scanf("%d", &op);
        
        switch(op){
            
            case 1:{
                
                //inicializando a lista 
                head = alocaNo(head, 26);
                
            }break;
            case 2:{
                
                int num;
                
                printf("\nNúmero a ser add:");
                scanf("%d", &num);
                
                head = insereFinal(head, num);
                
            }break;
            case 3:{
                
                int num;
                
                printf("\nNúmero a ser add:");
                scanf("%d", &num);
                
                head = insereInicio(head, num);
                
            }break;
            case 4:{
                
                imprimeLista(head);
                
            }break;
            case 5:{
                
                printf("\nLista ao contrário:\n");
                imprimeListaContrario(head);
                
            }break;
            case 6:{
                
                printf("\nQUANTIDADE DE NÓS = %d", contaNos(head));
                
            }break;
            case 7:{
                
                head = removePrimeiroNo(head);
                
            }break;
            case 8:{
                
                head = removeUltimoNo(head);
                
            }break;
            case 9:{
                int p;
                
                printf("\nPosição:");
                scanf("%d", &p);
                
                head = removeNoPosicao(head, p);
                
            }break;
            case 10:{
                
                head = deletaLista(head);
                
            }break;
            case 11:{
                int p, n;
                
                printf("\nPosição e número:");
                scanf("%d %d", &p, &n);
                
                head = insereNaPosicao(head, p, n);
                
            }break;
        }
    }

    return 0;
}

//====================================================================================

Node *alocaNo(Node *x, int y){
    
    if(x){
        printf("\nA lista ja foi alocada!\n");
        return x;
    }
    
    x = (Node*)malloc(sizeof(Node));
    
    if(!x){
        printf("\nNao foi possivel alocar o nó!");
    }
    
    x->prev = NULL;
    x->data = y;
    x->next = NULL;
    
    return x;
}

//====================================================================================

void imprimeLista(Node *x){
    
    if(!x){
        printf("\nLista vazia!");
        return;
    }
    
    Node *temp = x;
    
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

//====================================================================================

Node *insereFinal(Node *x, int y){
    
    if(!x){
        printf("\nLista nao existe");
        return x;
    }
    
    Node *temp = x;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    //alocando novo nó que será adicionado ao fim da lista
    Node *novoNo = (Node*)malloc(sizeof(Node));
    novoNo->prev = NULL;
    novoNo->data = y;
    novoNo->next = NULL;
    
    temp->next = novoNo;
    novoNo->prev = temp;
    
    return x;
}

//====================================================================================

Node *insereInicio(Node *x, int y){
    
    if(!x){
        printf("\nLista nao existe");
        return x;
    }
    
    //alocando novo nó para ser add no INÍCIO
    Node *novoNo = (Node*)malloc(sizeof(Node));
    novoNo->prev = NULL;
    novoNo->data = y;
    novoNo->next = NULL;
    
    novoNo->next = x;
    
    x->prev = novoNo;
    
    x = novoNo;
   
    return x;
}

//====================================================================================

int contaNos(Node *x){
    
    if(!x){
        return 0;
    }
    
    int counter = 1;
    
    Node *temp = x;
    
    while(temp->next != NULL){
        counter++;
        temp = temp->next;
    }
    
    return counter;
}

//====================================================================================

Node *removePrimeiroNo(Node *x){
    
    if(!x){
        printf("\nLista nao existe");
        return x;
    }
    
    Node *temp = x;
    
    x = x->next;
    free(temp);
    temp = NULL;
    
    x->prev = NULL;
    
    return x;
}

//====================================================================================

Node *removeUltimoNo(Node *x){
    
    if(!x){
        printf("\nLista nao existe");
        return x;
    }
    
    Node *temp = x;
    Node *temp2 = NULL; //vai guardar o penúltimo nó, que posteriormente se torna o último
    
    while(temp->next != NULL){
        temp = temp->next;
    }
  
    temp2 = temp->prev;
    temp2->next = NULL;
    
    free(temp);
    temp = NULL;
    
    return x;
}

//====================================================================================

Node *insereNaPosicao(Node *x, int pos, int data){
    
    if(!x){
        printf("\nLista nao existe");
        return x;
    }
    
    if(pos > contaNos(x)){
        printf("\nA posição excede a quantidade de elementos na lista!");
        return x;
    }
    
    //criando novo nó
    Node *novoNo = (Node*)malloc(sizeof(Node));
    novoNo->prev = NULL;
    novoNo->data = data;
    novoNo->next = NULL;
    
    //caso a inserção seja na primeira posição
    if(pos == 1){
        x = insereInicio(x, data);
        return x;
    }

    //ponteiro que vai ser o nó anterior da posição
    Node *tempAnterior = x;
    
    //ponteiro que vai ser o nó posterior da posição
    Node *tempPosterior = NULL;
    
    //passar pela lista toda até o último elemento
    while(pos != 2){
        tempAnterior = tempAnterior->next;
        pos--;
    }
    
    tempPosterior = tempAnterior->next;
    
    tempAnterior->next = novoNo;
    novoNo->prev = tempAnterior;
    novoNo->next = tempPosterior;
    tempPosterior->prev = novoNo;
    
    return x;
}

//====================================================================================

Node *removeNoPosicao(Node *x, int pos){
    
    if(!x){
        printf("\nLista nao existe");
        return x;
    }
    
    if(pos == 1){
        x = removePrimeiroNo(x);
        return x;
    }
    
    Node *tempAnterior = x;
    Node *tempPosterior = NULL;
    
    while(pos != 1){
        tempAnterior = tempAnterior->next;
        pos--;
    }
    
    //tempPosterior armazena endereço do nó anterior ao que vai ser deletado
    tempPosterior = tempAnterior->prev;
    
    //o campo next do tempPosterior vai receber o que tinha no campo next do nó que vai ser deletado
    tempPosterior->next = tempAnterior->next;
    
    //"conectando" campo prev com o endereço do tempPosterior para não perder o restante da lista e para que possa ser removido o nó desejado
    tempAnterior->prev = tempPosterior;
    
    //deletando o nó
    free(tempAnterior);
    tempAnterior = NULL;
    
    return x;
}

//====================================================================================

void imprimeListaContrario(Node *x){
    
    if(!x){
        return;
    }
    
    imprimeListaContrario(x->next);
    
    printf("%d\n", x->data);
    
}

//====================================================================================

Node* deletaLista(Node *x){
	
	if(!x){
		printf("\nLista Vazia, nao eh possivel deletar a mesma");
	}else{
		Node* temp = x;
		Node* aux = NULL;
		
		while(temp != NULL){
			temp = temp->next;
			free(x);
			x = temp;
		}	
	}
	return x;
}
