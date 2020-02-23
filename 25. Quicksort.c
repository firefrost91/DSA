#include<stdio.h>
void swap(int * a , int * b){
    int temp =*a ; 
    *a = *b ; 
    *b=temp ; 
}
int partition (int A[] , int l , int h ){
    int pivot = A[h]; 
    int i = l-1 ;
    int j ; 
    for(j=l ; j < h ; j ++){
        if(A[j]<=pivot){
            i++; 
            swap(&A[i] , &A[j]); 
        }
    }
    swap(&A[i+1] , &A[h]); 
    return i+1 ; 
}

void Quicksort(int A[] , int l , int h ){
    if(l<h){
    int p = partition(A , l , h ); 
    Quicksort(A , l , p-1); 
    Quicksort(A , p+1 , h );
    }
}
void display (int A[] , int n ){
    int i ;
    for(i=0 ; i<n ; i++){
        printf("%d " , A[i]); 
    }
}

int main (){
    int A[]={6,5,4,1,0} ; 
    Quicksort(A , 0 , 4); 
    display(A , 5); 
}
