#include <stdio.h>
static int SIZE = 10 ; 
int hash (int key ){
    return key%10 ; 
}
int probe(int B[] , int key){
    int index=hash(key);
    int i = 0 ; 
    while(B[(index+i)%SIZE]!=0){
        i++ ; 
    }
    return (index+i)%SIZE ; 
}
void insert (int B[] , int key){
    int index=hash(key); 
    if(B[index]!=0){
        index= probe(B , key );
    }
    B[index]=key ; 
}
void display (int B[]){
    int i = 0 ; 
    for(i=0 ; i < SIZE ; i ++){
        printf("%d  " , B[i]);
    }
    printf("\n"); 
}
int main()
{
    int B[10]={0}; 
    insert(B , 12 );
    insert (B , 22);
 display(B);
    return 0;
}
