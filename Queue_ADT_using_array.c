#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
    int size ;
    int front ; 
    int rear ; 
    int *Qarr;
}Queue;
Queue * createI(){
    Queue* q1 ; 
    q1=(Queue *)malloc(sizeof(Queue));
    q1->Qarr=(int *)malloc(sizeof(int)*0);
    q1->size=0 ;
    q1->front=-1 ;
    q1->rear=-1; 
    return q1 ;
    
}
Queue* enqueue(int x ,  Queue* q1 ){
    q1->Qarr=(int *)realloc(q1->Qarr , sizeof(int)*q1->size+1);
    q1->size++ ; 
    q1->rear++ ;
    q1->Qarr[q1->rear]=x;
    q1->front=0 ;
    return q1 ; 
}
 Queue* dequeue(Queue* q1 ){
     if(q1->front==-1){
    printf("Queue is already empty \n"); 
    return q1 ; }
    if(q1->size==1){
       int x= q1->Qarr[0];
    printf("Dequeued element is %d \n" , x ) ;
        q1->front=-1 ;
        q1->size=0;
        q1->rear=-1;
        return q1;
    }
    int i ;
    int x= q1->Qarr[0];
    printf("Dequeued element is %d \n" , x ) ;
    for(i=0 ; i <q1->size ; i ++){
    q1->Qarr[i]=q1->Qarr[i+1];
    }
    q1->Qarr=(int *)realloc(q1->Qarr , sizeof(int)*q1->size-1);
    q1->size-- ;
    q1->rear-- ; 
    return q1 ; 
 }
void display(Queue* q1){
    int i ;
    if(q1->size==0){
    printf("Queue is empty");
    }
    for(i=0;i<q1->size;i++){
        printf("%d  " , q1->Qarr[i]);
        }
        printf("\n");
}
int front(Queue* q1){
    return q1->Qarr[0];
}
int last(Queue* q1){
    return q1->Qarr[q1->rear];
}
int main(){
    Queue *q1 = createI(); 
  //  printf("%d \n", q1->size);
    q1=enqueue(4, q1);
    q1=enqueue(3, q1);
   q1=enqueue(2, q1);
  printf("%d \n" , front(q1));
   printf("%d \n" , last(q1));
 //printf("%d \n", q1->front);
 //printf("%d \n", q1->rear);
 //printf("%d \n", q1->size);

}
