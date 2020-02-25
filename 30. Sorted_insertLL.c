#include<stdio.h>
#include<stdlib.h>
static int i = 0 ;
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
struct node* sorted_insert(struct node* first , int x  ){
 struct node* temp, *p , *q  ;
 p=first ; 
 int i=0  ; 
 temp=(struct node*)malloc(sizeof(struct node));
 if(first==NULL){
        temp=add_to_empty(x);
        return temp ; 
    }
 temp->data=x ; 
 if(x<p->data){
     first=add_at_first(first , x); 
     return first ; 
 }
 while(p!=NULL){
    i++;
     q=p->next ; 
     if(q!=NULL && x<q->data){
         temp->next = q; 
         p->next=temp ; 
         return first ; 
     }
     p=p->next ; 
 }
 first = add_at_last(first ,  x);
 return first ; 
}
void display(struct node* first){
    struct node* p = first ; 
    while(p!=NULL){
        printf("%d " , p->data); 
        p=p->next ; 
    }
 printf("\n"); 
    
}
void Iterative_search(struct node* first , int key){
    int i = 0 ;
    struct node* p = first ; 
    while(p!=NULL){
        if(p->data==key){
            printf("Element is at index %d \n" , i ); 
            return ;     }
        i++;
        p=p->next;
    }
   printf("Element not found "); 
   return ; 
}
int main(){
    struct node* first = NULL ; 
    first=sorted_insert(first , 3); 
     first=sorted_insert(first , 1); 
      first=sorted_insert(first , 5); 
    display(first); 
 
}
