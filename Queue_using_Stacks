#include<stdio.h>
#include<stdlib.h>
struct Stack {
  int size;
  int top ; 
  int *Starr ; 
};
struct Queue{
    struct Stack s1 ;
    struct Stack s2 ; };
struct Stack* create (int size){
    // struct Stack* st ;
    struct Stack* st=(struct Stack*)malloc(sizeof(struct Stack)); 
    st->top=-1 ;
    st->size=size ;
    st->Starr=(int*)malloc(sizeof(int)*size); 
    return st ;
}
int isEmpty(struct Stack* st){
    if(st->top==-1){
        return 1 ;
    }
    return 0 ;
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
void Display(struct Stack* st){
    int i= 0 ;
    for(i=0;i<st->size ; i++){
        printf(" %d " , st->Starr[i]);
    }
}
int Pop(struct Stack* st){
    int x =st->Starr[st->top]; 
    st->Starr[st->top]=0 ;
    st->top-- ;
//printf("\n Popped number is %d \n " , x); 
return x ;
    
}
void Peek(struct Stack* st){
    printf("\n Peek: %d" , st->Starr[st->top]);
}
void enqueue(struct Stack* st1 ,struct Stack* st2 , int x){
 //  printf("%d" , x); 
    push(x,st1); 
}
void dequeue(struct Stack* st1 ,struct Stack* st2 ){
    int x; 
    while(!isEmpty(st1)){
    x=Pop(st1);
    push(x,st2);
    }
printf("Dequeued element : %d" , Pop(st2));
}
int main(){
    struct Stack* st2 ;
    st2=create(5); 
     struct Stack* st1 ;
    st1=create(5); 
enqueue(st1 , st2 , 5);
enqueue(st1 , st2 , 4);
enqueue(st1 , st2 , 3);
dequeue(st1 , st2);

    
}
