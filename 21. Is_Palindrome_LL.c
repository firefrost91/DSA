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
struct node* reverse_LL ( struct node* first ){
    struct node* prev= NULL ; 
    struct node* prev2 ; 
   // prev2=first; 
    struct node* current= first  ; 
    struct node* next = first->next ; 
    while(next!=NULL){
        current->next=prev ;
        prev=current ; 
        current=next ; 
        next=next->next ; 
    }
    current->next=prev ;
    first->next=NULL ; 
    return current; 
    
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
void check_Palindrome(struct node* first){
    int size = Iterative_size(first); 
    int mid=size/2 ; 
    int index=1 ; 
    struct node* p1 , *p2 ,*p3 ,*p4;
    p1=first ; 
    while(p1!=NULL){
        p2=p1->next ; 
        if(index==mid){
            break ;}  
        index++ ; 
        p1=p1->next ;    
    }
    p2=p1->next ;
    p1->next=NULL ; 
   // display(first);
    p2=reverse_LL(p2);
    //display(p2);
    p3=first ; 
    p4=p2 ; 
    while(p3!=NULL&& p4!=NULL){
        if(p3->data!=p4->data){
            printf("Not a Palindrome \n");
            p2=reverse_LL(p2);
            p1->next=p2 ;
            return ; 
        }
        p3=p3->next ; 
        p4=p4->next ; 
    }
    printf("It is a Palindrome \n");
     p2=reverse_LL(p2);
     p1->next=p2 ;
    return ; 
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
  first=reverse_LL(first);
   display(first); 
     struct node* first2 = NULL ; 
    first2=add_at_last(first2 , 2);
    first2=add_at_last(first2 , 3);
    first2=add_at_last(first2 , 5);
    first2=add_at_last(first2 , 3);
    first2=add_at_last(first2 , 2);
    display(first2);
   check_Palindrome(first2); 
   display(first2); 
 
}
