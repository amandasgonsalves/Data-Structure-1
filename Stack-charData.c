//MANIPULAÇÃO PILHA
#include<stdio.h>
#include<stdlib.h>

//==============================================================================

typedef struct node{
    
	char data;
	struct node *link;
	
}Node;

//==============================================================================

Node *alocaNo(char y){
    
	Node *novoNo = (Node*)malloc(sizeof(Node));
	
	if (novoNo == NULL) return NULL;
	
	novoNo->data = y;
	novoNo->link = NULL;
	
	return novoNo; 
}

//==============================================================================

void insereInicio(Node **x, char y){ //push

	Node *novoNo = alocaNo(y);
	
	novoNo->link = *x;
	*x = novoNo;
	
}

//==============================================================================

void imprimeLista(Node *x){ //imprime pilha

    if(!x){
        printf("\nLista vazia!");
        return;
    }

	while(x != NULL)
	{
		printf("%c\n", x->data);
		x = x->link;
	}
	
}

//==============================================================================

void removeInicio(Node **x){ //pop

    Node *temp = *x;
 
    if(*x == NULL){
       	printf("\nLista vazia");
       	return ;
    }
    
    if((*x)->link != NULL){
       
        *x = (*x)->link;
        free(temp);
	}
    else
    {
    	free(temp);
    	*x=NULL;
		return;
	}   
}

//==============================================================================

int main()
{
	Node *head = NULL;
	
	int op;
	char dado;
	
	while(op!=4)
	{
		printf("\n1 - Insere");
		printf("\n2 - Retira");
		printf("\n3 - Imprime");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:{
			    
				printf("\nInforme valor:");
				scanf("%s",&dado);
				    
				insereInicio(&head, dado);
					
			}break;
			case 2:{
			  
				if(head==NULL){
				    printf("\nLista vazia!");
				}else{
					removeInicio(&head);
				}
				
			}break;
			case 3:{
				  
				imprimeLista(head);
				
			}break;
		}
   }
}

