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
