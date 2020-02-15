#include <stdio.h>
int Rec_binary_search (int arr[] , int h , int l ,int x){
    while(h>=l){
        int mid = (l+h-1)/2 ; 
    
        if(arr[mid]==x){
            return mid ;
        }
        if(arr[mid]>x){
              h=mid ; 
        }
         if(arr[mid]<x){
            l=mid+1 ; 
        }}
 return -1 ;    
    
}
int main()
{
     int arr[] = { 2,5,7,8,9, 3, 4, 10, 40 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 10; 
    int result = Rec_binary_search(arr, n-1, 0 , x); 
    (result == -1) ? printf("Element is not present in array") 
                   : printf("Element is present at index %d", 
                            result); 

    return 0;
}
