#include <merge.h>
int min(int x, int y) { return (x<y)? x :y; } 
void mergeSortIter(Element arr[],int n){ //Same function as above, but with a different name, so that I can use both recursive and iteratvie in comparer.c. It's messy, I know, but I'm lazy.
	int mid,right;
	iterspace = 2*sizeof(int);
	for(int curr_size=1;curr_size<n;curr_size*=2){
		for(int start=0;start<n;start+=2*curr_size){
			mid = min(start+curr_size-1,n-1);
			right = min(start+2*curr_size-1,n-1);

			Element newarr[right-start+1];
			iterspace += 2*sizeof(int)+(right-start+1)*sizeof(Element);

			merge(arr+start,mid-start+1,arr+mid+1,right-mid,newarr);
			for(int i=0;i<right-start+1;i++){
				arr[start+i]=newarr[i];
			}
		}
	}
}
