#include<stdlib.h>
#include <stdio.h>
struct node{
    int data ;
    struct node* prev ;
    struct node* next ; 
}; 
struct node * add_to_empty(int x ){
    struct node* first ;
    first=(struct node*)malloc(sizeof(struct node)); 
    first->data=x ;
    first->next=NULL ;
    first->prev=NULL ; 
    return first ;
}
void display(struct node *first  ){
    struct node* p ; 
    p=first ; 
    while(p!=NULL){
        printf("%d " , p->data);
        p=p->next ; 
    }
    printf("\n"); 
}
struct node* add_at_first(struct node* first , int x  ){
    struct node* temp ; 
    temp=(struct node*)malloc(sizeof(struct node )); 
   if(first==NULL){
       temp =add_to_empty(x); 
       return temp ; 
   }
    temp->data= x ;
    temp->next=first ;
    first->prev=temp ; 
    temp->prev=NULL ; 
    first=temp ; 
    return first ; 
}
struct node* add_at_last(struct node* first , int x ){
    struct node*temp , *p; 
    temp=(struct node*)malloc(sizeof(struct node)); 
    if(first==NULL){
       temp =add_to_empty(x); 
       return temp ; 
   }
    temp->data =x ;
    p=first ; 
    while(p->next!=NULL){
        p=p->next ; 
    }
    p->next = temp ; 
    temp->next=NULL ; 
    temp->prev=p ; 
    return first ; 
}
struct node* add_at_index(struct node* first , int index , int x ){
    struct node* temp , *p , *q  ; 
    temp=(struct node*)malloc(sizeof(struct node)); 
     if(first==NULL){
       temp =add_to_empty(x); 
       return temp ; 
   }
    temp->data=x ;
    int i=0  ;
    p=first ;
    while(q!=NULL){
        q=p->next ; 
        i++;
        if(i==index){
            q->prev=temp ;
            temp->next=q ;
            temp->prev=p ; 
            p->next=temp ; 
            return first ; 
        }
        p=p->next ; 
    }
    return first ; 
}

int main()
{ struct node* first=NULL ; 
   first= add_to_empty(4);
   first= add_at_first(first , 3);
 display(first);   
 first = add_at_last(first , 8 ); 
 add_at_index(first , 2 , 6);
 
  display(first); 
    return 0;
}
