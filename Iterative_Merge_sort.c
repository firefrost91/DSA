#include<stdio.h>
#include<stdlib.h>

void merge ( int A[] , int l , int mid , int h){
    int C[100]={0};
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
void Iterative_Mergesort(int A[] , int n )
{
int p , i , l , mid , h ;

for(p=2;p<=n;p=p*2){
    for(i=0 ; i+p-1<n ; i=i+p){
        l=i ;
        h=i+p-1 ;
        mid=(l+h)/2 ;
      merge(A , l , mid , h);
    }
}
 if(p/2<n){
 merge(A,0,p/2-1,n);}
}
 int main(){
    int A[9]={3,4,1,2,7,9,0,6,7};
    //int B[3]={3,6,9};
    //merge(A , 0 ,2 , 5 );
    Iterative_Mergesort( A, 9); 
  //  printf("%d" , C[0]);
    display( 9 , A);
}


