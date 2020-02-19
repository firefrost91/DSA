
#include <stdio.h>
void insertionsort ( int A[] , int n ){
    int i , j , x ; 
    for(i=1 ; i <n ; i ++){
        j = i-1 ; 
        x=A[i];
        while(j>-1 && A[j]>x){
            A[j+1]=A[j]; 
          j-- ; }
A[j+1]= x ; 
}}

int main()
{
    int arr[]={5,4,3 , 1 }; 
    int n=4 ;
    int i ; 
    insertionsort(arr , 4 ); 
     for(i=0 ; i <n ; i ++){
    printf("%d" , arr[i]); 
}
    return 0;
}
