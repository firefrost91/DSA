#include<stdio.h>
#include<stdlib.h>
void merge ( int A[] , int B[] , int n , int m, int C[]){
    // int *C;
    // C=(int*)malloc(sizeof(int)*(m+n)); 
    int i=0 , j=0 , k=0 ; 
    while(i<n && j<m){
        if(A[i]<B[j]){C[k]=A[i];
            k++;
            i++;}
        else {
            C[k]=B[j]; 
            k++ ;
            j++;}}
    for( ; i<n ; i++){
         C[k]=A[i];
         k++; 
    }    
      for( ; j<m ; j++){
         C[k]=B[j];
         k++; 
    } 
}
void display(int n , int C[]){
    int i ;
    for(i=0 ; i<n ; i++){
        printf("%d  " , C[i]); 
        }
}

int main(){
    int A[5]={2,5,7,11,13};
    int n = sizeof(A)/sizeof(int);
    int B[3]={3,6,9};
    int m = sizeof(B)/sizeof(int); 
    int *C ; 
    C=(int *)malloc(sizeof(int)*(m+n)); 
    
    merge( A, B , n , m , C ); 
    //printf("%d" , C[0]);
    display( 8 , C);
}
