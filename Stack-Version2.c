//MANIPULAÇÃO DE PILHA
#include <stdio.h>
#include <stdlib.h>

//==============================================================================

typedef struct node{
    
    int data;
    struct node *link;
    
}Node;

//==============================================================================

Node *alocaNo(int y);

//------- empilha com FUNÇÃO RETURN e VOID
Node *empilha1(Node **x, int y);
void empilha2(Node **x, int y);

void imprimePilha(Node *x);

//------- desempilha com FUNÇÃO RETURN e VOID
Node *desempilha1(Node **x);
void desempilha2(Node **x);

void imprimeContrario(Node *x);

int contabilizaNos(Node *x);

Node *concatenaPilhas(Node *x, Node *y);

Node *dividePilha(Node *x);

//==============================================================================

int main()
{
    Node *head = NULL;
    
    //cabeça para uma segunda lista caso o usuário deseje criar uma
    Node *head2 = NULL;
    
    Node *concatenadas = NULL;
    
    int op;
    
    while(op != 5){
        
        printf("\n(1) - Empilha (INSERE)");
		printf("\n(2) - Desempilha (REMOVE)");
		printf("\n(3) - Imprime");
		printf("\n(4) - Imprime ao CONTRÁRIO");
		printf("\n(5) - Concatenar DUAS PILHAS");
		printf("\n(6) - Dividir pilha AO MEIO");
		printf("\n(7) - Contabiliza nós");
		printf("\n(8) - Criar segunda lista randomicamente com 10 elementos");
		printf("\n(9) - Libera a PILHA TODA");
		scanf("%d", &op);
		
		switch(op){
		    case 1:{
		        
		        /*int num1, num2;
		        
		        printf("\nDigite o número e selecione (1) - VOID ou  (2) - RETURN");
		        scanf("%d %d", &num1, &num2);
		        
		        if(num2 == 1){
		            empilha2(&head, num1);
		        }else{
		            head = empilha1(&head, num1);
		        }*/
		        
		        head = empilha1(&head, 10);
		        head = empilha1(&head, 35);
		        head = empilha1(&head, 22);
		        head = empilha1(&head, 98);
		        head = empilha1(&head, 17);
		        
		    }break;
		    case 2:{
		        
		        int r;
		        
		        printf("\nDesempilhar com:\n(1) - RETURN ou (2) - VOID");
		        scanf("%d", &r);
		        
		        if(r == 1){
		            head = desempilha1(&head);
		        }else{
		            desempilha2(&head);
		        }
		        
		        
		    }break;
		    case 3:{
		        int j;
		        
		        printf("\nImprimir PILHA 1 ou 2?");
		        scanf("%d", &j);
		        
		        if(j == 1){
		            imprimePilha(head);
		        }else{
		            imprimePilha(head2);
		        }
		        
		    }break;
		    case 4:{
		        
		        if(!head){
		            printf("\nPILHA VAZIA!");
		        }else{
		            imprimeContrario(head);
		        }
		        
		    }break;
		    case 5:{
		        
		        printf("\n->> PILHAS UNIFICADAS:\n");
		        concatenadas = concatenaPilhas(head, head2);
		        imprimePilha(concatenadas);
		        
		    }break;
		    case 6:{
		        
		        int h;
		        
		        //ponteiro que vai armazenar endereço da primeira posição da outra metade da pilha
		        Node *metade = NULL;
		        
		        //ou
		        Node *metade2 = NULL;
		        
		        printf("\nDividir pilha 1 ou 2?");
		        scanf("%d", &h);
		        
		        if(h == 1){
		            head = dividePilha(metade);
		            
		            printf("\n->> PARTE 1:\n");
		            imprimePilha(head);
		            
		            printf("\n->> PARTE 2:\n");
		            imprimePilha(metade);
		            
		        }else{
		            head2 = dividePilha(metade2);
		            
		            printf("\n->> PARTE 1:\n");
		            imprimePilha(head2);
		            
		            printf("\n->> PARTE 2:\n");
		            imprimePilha(metade2);
		        }
		        
		    }break;
		    case 7:{
		        
		        printf("\nQUANTIDADE DE NÓS PILHA 1 = %d", contabilizaNos(head));
		        printf("\nQUANTIDADE DE NÓS PILHA 2 = %d", contabilizaNos(head2));
		        
		    }break;
		    case 8:{
		        
		        int i;
		        for(i=0;i<10;i++){
		            head2 = empilha1(&head2, rand() % 100);
		        }
		        
		    }break;
		    case 9:{
		        
		        int l;
		        
		        printf("\nLIBERAR PILHA 1 OU 2?");
		        scanf("%d", &l);
		        
		        if(l == 1){
		            Node *temp = head;
		        
    		        while(temp != NULL){
    		            temp = temp->link;
    		            free(head);
    		            head = temp;
    		        }
		        }else{
		            Node *temp = head2;
		        
    		        while(temp != NULL){
    		            temp = temp->link;
    		            free(head2);
    		            head2 = temp;
    		        }
		        }
		        
		    }break;
		}
    }

    return 0;
}

//==============================================================================

Node *alocaNo(int y){
    
    Node *novoNo = (Node*)malloc(sizeof(Node));
    
    if(!novoNo) return NULL;
    
    novoNo->data = y;
    novoNo->link = NULL;
    
    return novoNo;
}

//==============================================================================

Node *empilha1(Node **x, int y){
    
    Node *novoNo = alocaNo(y);
    
    if(!novoNo) return NULL;
    
    novoNo->link = *x;
    *x = novoNo;
    
    return novoNo;
}

//==============================================================================

void empilha2(Node **x, int y){
    
    Node *novoNo = alocaNo(y);
    
    if(!novoNo) return;
    
    novoNo->link = *x;
    *x = novoNo;
}

//==============================================================================

void imprimePilha(Node *x){
    
    if(!x){
        printf("\nPILHA VAZIA!");
        return;
    }
    
    while(x != NULL){
        printf("%d\n", x->data);
        x = x->link;
    }
}

//==============================================================================

Node *desempilha1(Node **x){
    
    Node *aux = *x;
    
    if(!*x){
        printf("\nPILHA VAZIA, NÃO HÁ O QUE DESEMPILHAR!");
        return (*x);
    } 
    
    //passando o pointeiro para o próximo nó para que possa remover o primeiro,
    // não perdendo o endereço do restante da pilha
    *x = (*x)->link;
    free(aux);
    aux = NULL;
    
    return (*x);
}

//==============================================================================

void desempilha2(Node **x){
    
    Node *aux = *x;
    
    if(!*x){
        printf("\nPILHA VAZIA, NÃO HÁ O QUE DESEMPILHAR!");
        return;
    } 
    
    //passando o pointeiro para o próximo nó para que possa remover o primeiro,
    // não perdendo o endereço do restante da pilha
    *x = (*x)->link;
    free(aux);
    aux = NULL;
}

//==============================================================================

void imprimeContrario(Node *x){
    
    if(!x){
        return;
    }
    
    imprimeContrario(x->link);
    
    printf("%d\n", x->data);
}

//==============================================================================

int contabilizaNos(Node *x){
    
    if(!x){
        return 0;
    }
    
    int counter = 1;
    
    while(x->link != NULL){
        counter++;
        x = x->link;
    }
    
    return counter;
}

//==============================================================================

Node *concatenaPilhas(Node *x, Node *y){
    
    Node *temp = x;
    
    while(x->link != NULL){
        x = x->link;
    }
    
    x->link = y;
    
    x = temp;
    
    return x;
}

//==============================================================================

Node *dividePilha(Node *x){
    
    
}
