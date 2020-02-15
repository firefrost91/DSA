#include<stdio.h>
#include<stdlib.h>
static int size = 0 ;
struct Node {
    int data ;
    struct Node * next
};
struct Node* insert(int x , struct Node* first ){
    int i ; 
    struct Node* temp ; 
    temp=(struct Node*)malloc(sizeof(struct Node)); 
    temp->data = x ;
    temp->next=NULL ; 
    temp->next=first ;
    first=temp ;
    size++ ;
    return first ;
}

struct Node* insert_index(int x , struct Node* first , int index ){
 int i ; 
    if(index>size+1){
        printf("Invalid Index  \n"); 
        return first ;
    }
    struct Node* temp , *t2 , *t1 ; 
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x ;
    temp->next=NULL ; 
    t2=first ;
    t1=t2->next ; 
    for(i=1 ; i < index-1 ; i ++){
    t2=t1 ;
    t1=t1->next ; 
    }
    temp->next = t1 ;
    t2->next=temp ;
    size++ ;
    return first ;
}


void display(struct Node* first){
 struct Node* p ;
 p=first ; 
 while(p!=NULL){
     printf("%d " , p->data); 
     p=p->next ; 
 }
    
}
int main(){
struct Node* first ;
// first=create(3); 
first = insert(3 , first );
first = insert(2 , first );
first = insert(1 , first );
first =insert_index(0 , first ,3 );
first =insert_index(9 , first ,5 );
display(first);     
}
