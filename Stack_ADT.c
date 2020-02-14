#include<stdio.h>
#include<stdlib.h>
struct Stack {
    int size ; 
    int top ; 
    int *Starr ; 
};
struct Stack* create (int size){
    // struct Stack* st ;
    struct Stack* st=(struct Stack*)malloc(sizeof(struct Stack)); 
    st->top=-1 ;
    st->size=size ;
    st->Starr=(int*)malloc(sizeof(int)*size); 
    return st ;
}

struct Stack* push(int x , struct Stack* st){
   if(st->top==st->size-1){
       printf("Stack Overflow \n");
       return  ; 
   }
    st->top++ ; 
    st->Starr[st->top]=x ;
  //  printf("Pushed : %d " , st->Starr[st->top]);
    return st ;
}
int Pop(struct Stack* st){
    int x =st->Starr[st->top]; 
    st->Starr[st->top]=0 ;
    st->top-- ;
//printf("\n Popped number is %d \n " , x); 
return x ;
    
}
void Display(struct Stack* st){
    int i= 0 ;
    for(i=0;i<st->size ; i++){
        printf(" %d " , st->Starr[i]);
    }
    printf("\n");
}
int main(){
    struct Stack* st1 ;
    st1=create(5);
    st1 =push(4 , st1);
    st1 =push(7 , st1);
    Display(st1); 
    Pop(st1);
    Display(st1); 
}
