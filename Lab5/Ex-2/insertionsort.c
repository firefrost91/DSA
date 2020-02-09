#include "insertionsort.h"

void insertInOrder(Creditc* Creditc_array, int n, Creditc newcard){
	Creditc card = newcard;
	Creditc tempcard;
	for(int i=0;i<n;i++){
		if(card.card_no < Creditc_array[i].card_no || i==n-1){
			tempcard = card;
			card = Creditc_array[i];
			Creditc_array[i] = tempcard;
		}
	}
}

void insertionSort(Creditc* Creditc_array,int n){
	if(n==0){
		topofstack = &n;
		return;
	}
	insertionSort(Creditc_array,n-1);
	insertInOrder(Creditc_array,n,Creditc_array[n-1]);
}
