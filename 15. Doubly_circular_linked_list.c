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
    first->next=first ;
    first->prev=first ; 
    return first ;
}
void display(struct node *first  ){
    struct node* p ; 
    p=first ; 
    do{ printf("%d " , p->data);
        p=p->next ; 
    }while(p!=first);
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
     temp->prev=first->prev ; 
     temp->next=first ;
    first->prev->next=temp ; 
    first->prev=temp ; 
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
    do{
       p=p->next ;  
    }
    while(p->next!=first);
    p->next = temp ; 
    temp->next=first ;
    first->prev=temp ; 
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
    do{ q=p->next ; 
        i++;
        if(i==index){
            q->prev=temp ;
            temp->next=q ;
            temp->prev=p ; 
            p->next=temp ; 
            return first ; 
        }
        p=p->next ; 
    }while(q!=first);
    return first ; 
}

int main()
{ struct node* first=NULL ; 
   first= add_to_empty(4);
 first = add_at_first(first , 3);
  first=add_at_last(first , 2);
  first =add_at_index(first , 2 , 5); 
//   printf("%d " , first->next->data); 
//  printf("%d " , first->data);
  display(first);   
    return 0;
}
