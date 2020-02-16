void Recursive_Merge_sort(int A[] , int l , int h ){
    int mid ;
    if(l<h){
        mid=(l+h)/2; 
       Recursive_Merge_sort(A , l , mid);
       Recursive_Merge_sort(A , mid+1 , h);
        merge(A , l , h);
    }
}
