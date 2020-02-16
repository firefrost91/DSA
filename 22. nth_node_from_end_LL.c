#include<stdio.h>
#include<stdlib.h>
struct node{
    int data ; 
    struct node* next ; 
}; 
struct node* add_to_empty (int x){
   struct node* temp ;
   temp=(struct node*)malloc(sizeof(struct node)); 
   temp->data=x ;
   temp->next=NULL ;
   return temp ; 
}
struct node* add_at_first (struct node* first , int x){
    struct node * temp ; 
    temp=(struct node* )malloc(sizeof(struct node)); 
    if(first==NULL){
        temp=add_to_empty(x);
        return temp ; 
    }
    temp->data=x ; 
    temp->next=first ; 
    first = temp ; 
    return first ; 
} 
struct node* add_at_last ( struct node* first , int x){
    struct node* temp , *p ; 
    temp=(struct node*)malloc(sizeof(struct node)); 
    if(first==NULL){
        temp=add_to_empty(x);
        return temp ; 
    }
    temp->data= x ;
    p=first ; 
    while(p->next!=NULL){
        p=p->next ; 
    }
    p->next=temp ; 
    temp->next=NULL ; 
    return first ; 
}
struct node* add_at_index(struct node* first , int index , int x  ){
 struct node* temp, *p , *q  ;
 p=first ; 
 int i=0  ; 
 temp=(struct node*)malloc(sizeof(struct node));
 if(first==NULL){
        temp=add_to_empty(x);
        return temp ; 
    }
 temp->data=x ; 
 while(p!=NULL){
    i++;
     q=p->next ; 
     if(i==index){
         temp->next = q; 
         p->next=temp ; 
         return first ; 
     }
     p=p->next ; 
 }
 return first ; 
}
int Iterative_size ( struct node* first ){
    struct node* p =first ;
    int i =0 ;
    while(p!=NULL){
        i++;
        p=p->next ;
    }
    return i ; 
}
void Node_from_end ( struct node* first , int n  ){
    int size = Iterative_size(first) ; 
    int i = 0 ;
    int index = size- n ;
    struct node* p = first ;
    while(p!=NULL){
        if(i==index){
            printf("Value %d" , p->data); 
        }
        p=p->next ; 
        i++ ;
    }
}
void display(struct node* first){
    struct node* p = first ; 
    while(p!=NULL){
        printf("%d " , p->data); 
        p=p->next ; 
    }
 printf("\n"); 
    
}

int main(){
    struct node* first = NULL ; 
    first=add_at_last(first , 5);
    first=add_at_last(first , 7);
    first=add_at_last(first , 9);
    display(first); 
     struct node* first2 = NULL ; 
    first2=add_at_last(first2 , 2);
    first2=add_at_last(first2 , 6);
    first2=add_at_last(first2 , 8);
    first2=add_at_last(first2 , 11);
    display(first2); 
    Node_from_end(first , 3 ); 
   
 
    // struct node* first2 ; 
    // first2 = add_to_empty(3);
    // display(first2); 
}
