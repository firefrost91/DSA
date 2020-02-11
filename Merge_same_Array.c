#include<stdio.h>
#include<stdlib.h>
int * merge ( int A[] , int l , int mid , int h){
    int *C;
    C=(int*)malloc(sizeof(int)*(h+1));
    //printf("%d     ", h+1);
    int i=l , j=mid+1 , k=l ; 
    while(i<=mid && j<=h){
        if(A[i]<A[j]){
            C[k]=A[i];
            k++;
            i++;}
        else {
            C[k]=A[j]; 
            k++ ;
            j++;}}
    for( ; i<=mid ; i++){
         C[k]=A[i];
         k++; 
    }    
      for( ; j<=h ; j++){
         C[k]=A[j];
         k++; 
    } 
    return C; 
    
}
void display(int n , int C[]){
    int i ;
    for(i=0 ; i<n ; i++){
        printf("%d  " , C[i]); 
        }
}

int main(){
    int A[6]={2,5,7,1,9,11};
    //int B[3]={3,6,9};
    
    int* C=merge( A, 0 , 2 , 5); 
    //printf("%d" , C[0]);
    display( 6 , C);
}


