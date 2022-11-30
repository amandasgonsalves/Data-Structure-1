//MANIPULAÇÃO DE FILA
#include <stdio.h>
#include <stdlib.h>

//==============================================================================

typedef struct node{
    
    int data;
    struct node *link;
    
}Node;

//==============================================================================

Node *alocaNo(int y);

Node *enfileirar(Node **x, int y); //insere no fim da fila

void imprimeFila(Node *x);

Node *desenfileirar(Node *x); //remove do fim

//==============================================================================

int main(){
    
    //pointers de início e fim da FILA
    Node *inicio = NULL, *fim = NULL;
    
    int op;
    
    while(op != 4){
        
        printf("\n(1) - ENFILEIRAR\n(2) - DESENFILEIRAR\n(3) - IMPRIMIR FILA");
        scanf("%d", &op);
        
        switch(op){
            
            case 1:{
                
                fim = enfileirar(&fim, 8);
                fim = enfileirar(&fim, 7);
                fim = enfileirar(&fim, 22);
                fim = enfileirar(&fim, 45);
                fim = enfileirar(&fim, 93);
                
                if(inicio == NULL){
                    inicio = fim;
                }
                
            }break;
            case 2:{
                
                inicio = desenfileirar(inicio);
                
                if(!inicio){
                    fim = NULL;
                }
                
            }break;
            case 3:{
                
                imprimeFila(inicio);
                
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

Node *enfileirar(Node **x, int y){
    
    Node *novoNo = alocaNo(y);
    
    if(!novoNo) return NULL;
    
    novoNo->link = *x;
    *x = novoNo;
    
    return novoNo;
}

//==============================================================================

void imprimeFila(Node *x){
    
    if(!x){
        printf("\nFILA VAZIA!");
        return;
    }
    
    while(x != NULL){
        printf("%d\n", x->data);
        x = x->link;
    }
}

//==============================================================================

Node *desenfileirar(Node *x){
    
    Node *temp = x;
    
    while(temp->link->link != NULL){
        temp = temp->link;
    }
    
    free(temp->link);
    temp->link = NULL;
    
    return x;
}
