#include<stdio.h>
void insertionsort ( int A[] , int n){
    int i ,j ,x  ;
    for(i=0 ; i < n ; i ++){
        x=A[i];
        j=i-1 ;
        while(j>-1 && x<A[j]){
            A[j+1]=A[j]; 
            j-- ;
        }
        A[j+1]=x ; 
    }
}

void display (int A[] , int n){
    int i ;
    for(i=0 ;i < n ; i++){
        printf("%d  \n" , A[i]);
    }
}

int main(){
    int arr[]={3,2,1,0} ;
    insertionsort(arr , 4);
    display(arr, 4 );
}
