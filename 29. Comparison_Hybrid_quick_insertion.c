#include <stdio.h> 
#include<time.h>
#include <stdlib.h> 
#include<limits.h>
void findMin(double timeused[] , int n ){
    int i= 0 , j  ;
    double min = INT_MAX ; 
    for(i=0 ; i < n ; i ++){
        if(timeused[i]<min){
            min=timeused[i];
            j=i ; 
        }
    }
    printf("MINIMUM TIME --- Hybrid Quicksort with %d partitions takes : %f ms \n" , j  , min); 
}
void findMax(double timeused[] , int n ){
    int i= 0 , j  ;
    double max = INT_MIN ; 
    for(i=0 ; i < n ; i ++){
        if(timeused[i]>max){
            max=timeused[i]; 
            j=i ; 
        }
    }
    printf("MAXIMUM TIME --- Hybrid Quicksort with %d partitions takes : %f ms \n" , j  , max); 
}
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
void Iterative_quicksort ( int A[] , int l , int h , int S){
    int stack[h-l+1] ; 
    int top = -1  ;
     stack[++top]= l ; 
     stack[++top]=h ; 
     if(S<0){
         S=0 ; 
     }
    while(top>=S){
        
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
    while(top>=0){
        int h= stack[top--] ; 
        int l =stack[top--]; 
        insertionSort(A , l , h ); 
        
    }
}
void insertionSort(int arr[], int low, int n){
	// Start from second element (element at index 0 
	// is already sorted)
	for (int i = low + 1; i <= n; i++) 
	{
		int value = arr[i];
		int j = i;
		
		// Find the index j within the sorted subset arr[0..i-1]
		// where element arr[i] belongs
		while (j > low && arr[j - 1] > value) 
		{
			arr[j] = arr[j - 1];
			j--;
		}
		// Note that subarray arr[j..i-1] is shifted to
		// the right by one position i.e. arr[j+1..i]
		
		arr[j] = value;
	}
}
void display(int A[] , int n ){
    int i ; 
    for(i=0 ; i <n ; i++){
        printf("%d" , A[i]); 
    }
}
int main(){ int i ; 
     int A[3000] ; 
    int n = sizeof(A)/sizeof(int); 
     srand(time(0));
      for (i = 0; i < n; i++) { 
        int num = rand()%1000 ;  
       A[i]=num ; 
    } 
    clock_t start , end  ; 
    double timeused ; 
    int S = 0 ; 
    double timetaken[n]; 
    for(S=0 ; S < n ; S ++){
    start=clock() ; 
     Iterative_quicksort(A , 0 , n-1 , S  );
     end= clock(); 
     timetaken[S]=timeused = (double)(end - start)/ CLOCKS_PER_SEC ; 
    //  printf("Time taken for partition with %d : %f ms  \n" , S , timeused*1000);
    } start=clock() ; 
     insertionSort(A , 0 , n-1  );
     end= clock(); 
     timetaken[n]=timeused = (double)(end - start)/ CLOCKS_PER_SEC ; 
    printf("Time taken by Quicksort with no partitions : %f ms \n" , timetaken[0]); 
    printf("Time taken by Insertion Sort  : %f ms \n" , timetaken[n-1]); 
    findMin(timetaken , n)   ; 
     findMax(timetaken , n)   ; 
    // display(A , n); 
}
