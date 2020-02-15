#include<stdio.h>
#include<stdlib.h>
struct node{
  int data ; 
  struct node* next ; 
};
struct node* add_to_empty (int x){
    struct node* last ; 
    last=(struct node*)malloc(sizeof(struct node));
    last->data =x ; 
    last->next=last ;
    return last ; 
}
void display(struct node* last ){
     struct node *p , *q ;
     p=last->next ;
     q=last->next ;
     do{
         printf("%d " , p->data); 
         p=p->next ; 
     }while(p!=last->next);
    printf("\n"); 
    
}
struct node* add_to_first (struct node* last , int x){
    struct node *temp ; 
    if(last==NULL){
    temp=add_to_empty(x);
    return temp ;
    }
    temp=(struct node*)malloc(sizeof(struct node)); 
    temp->data = x ;
    temp->next=last->next;
    last->next=temp;
    return last ;
}
struct node* add_to_end(struct node* last , int x ){
    struct node *temp ; 
    if(last==NULL){
    temp=add_to_empty(x);
    return temp ;
    }
    temp=(struct node*)malloc(sizeof(struct node)); 
    temp->data=x ;
    temp->next=last->next ;
    last->next=temp ; 
    last=temp ;
    return last ; 
    }
struct node* add_at_index (struct node* last  , int index , int x){
 struct node* temp ; 
    if(last==NULL){
        temp = add_to_empty(x); 
        return temp ; 
    }
temp=(struct node*)malloc(sizeof(struct node)); 
temp->data=x ;
struct node*p , *q ; 
int n=1 ; 
p=last->next ;
q=p->next ; 
do{if(n==index-1){
     p->next=temp; 
 temp->next=q ;
 return last ; 
}   n++ ; 
    p=p->next ;
    q=p->next ; 
}while(p!=last->next);
 
    return last ; 
}

int main(){
    struct node* last=NULL;
    last =add_to_first(last , 3);
    last =add_to_first(last , 5);
    last =add_to_end(last , 2);
    last =add_to_end(last , 1);
    last=add_at_index(last , 3 , 4); 
    display(last);
}
