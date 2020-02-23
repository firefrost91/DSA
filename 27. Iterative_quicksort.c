#include <stdio.h> 
void swap(int* a, int* b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int partition ( int A[] , int l , int h  ){
    int pivot = A[h]; 
    int i = l-1 ; 
    int j ;
    for(j=l ; j <= h-1 ; j ++){
        if(A[j]<=pivot ){
            i++; 
            swap(&A[i] , &A[j]); 
        }
    }
    swap(&A[i+1] , &A[h]); 
     return i+1 ; 
}
void Iterative_quicksort ( int A[] , int l , int h ){
    int stack[h-l+1] ; 
    int top = -1  ;
     stack[++top]= l ; 
     stack[++top]=h ; 
    
    while(top>=0){
        int h= stack[top--] ; 
        int l =stack[top--]; 
        int p = partition(A , l , h ); 
        if(p-1>l){
        stack[++top]=l ; 
        stack[++top]=p-1; 
        }
        
        if(p+1<h){
            stack[++top]=p+1 ; 
            stack[++top]=h ; 
        }
        
    }
}
void display(int A[] , int n ){
    int i ; 
    for(i=0 ; i <n ; i++){
        printf("%d" , A[i]); 
    }
}
int main(){
    int A[]={2,3,1 , 6 ,8 ,0 }; 
    int n = sizeof(A)/sizeof(int); 
    Iterative_quicksort(A , 0 , n-1); 
    display(A , n); 
}
