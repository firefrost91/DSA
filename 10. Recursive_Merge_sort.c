#include<stdio.h>
#include<stdlib.h>

void merge ( int A[] , int l , int h){
    int C[100]={0};
    int mid=(l+h)/2 ;
    //printf("%d     ", h+1);
    int i=l , j=mid+1 , k=l , p; 
    while(i<=mid && j<=h){
        if(A[i]<A[j]){
            C[k++]=A[i++];
            //k++;
            //i++;
            }
        else {
            C[k++]=A[j++]; 
            //k++ ;
            //j++;
            }}
    for( ; i<=mid ; i++){
         C[k++]=A[i];
         //k++; 
    }    
      for( ; j<=h ; j++){
         C[k++]=A[j];
         //k++; 
    } 
for(p=l ; p<=h ; p++)    {
    A[p]=C[p];
} 
    
}
void display(int n , int C[]){
    int i ;
    for(i=0 ; i<n ; i++){
        printf("%d  " , C[i]); 
        }
}
void Recursive_Merge_sort(int A[] , int l , int h ){
    int mid ;
    if(l<h){
        mid=(l+h)/2; 
       Recursive_Merge_sort(A , l , mid);
       Recursive_Merge_sort(A , mid+1 , h);
        merge(A , l , h);
    }
}
 int main(){
    int A[9]={3,4,1,2,7,9,0,6,7};
    //int B[3]={3,6,9};
    //merge(A , 0 ,2 , 5 );
    Recursive_Merge_sort(A , 0 ,8);
  //  printf("%d" , C[0]);
    display( 9 , A);
}


