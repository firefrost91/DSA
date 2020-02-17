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

