/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
static int count = 1 ; 
int* insert(int A[] , int n ){
    int i=n  , j , temp ; 
    temp=A[n]; 
    while(i>1 && temp>A[i/2]){
        A[i]=A[i/2]; 
      i = i/2 ;
    }
    A[i]=temp ; 
    count++ ; 
 return A ; 
    
}
int main()
 {   int k ; 
    int arr[]={0 , 1, 2 , 3,4,1} ; 
    int*p =arr ; 
    p=insert(arr , 1); 
     p=insert(arr , 2); 
      p=insert(arr , 3); 
       p=insert(arr , 4);
           p=insert(arr , 4);
    
    
    for(k=0 ; k <count ; k ++ )
{  printf("%d " , p[k]); }
return 0 ; 
  
    
}
