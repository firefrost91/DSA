#include<stdio.h>
#include"Creditc.h"
#include<stdlib.h>

Creditc* readcards(Creditc* Creditc_array,char* filename, int* finalsize){
	int size=10;
	Creditc_array = (Creditc*)malloc(sizeof(Creditc)*size);
	FILE* f = fopen(filename,"r");

	if(f==NULL){
		printf("Error : File cannot be opened");
		exit(0);
	}

	Creditc newcard;
	int i=0;
	while(!feof(f)){
		fscanf(f,"\"%llu,%[^,],%[^,],%[^,],%[^\"]\"\n",&(newcard.card_no),newcard.bank_code,newcard.expiry_date,newcard.first_name,newcard.last_name);
		Creditc_array[i++]=newcard;
		if(i==size){
			size*=2;
			Creditc_array = realloc(Creditc_array,sizeof(Creditc)*size);
		}
	}
	fclose(f);
	*finalsize = i;
	return Creditc_array;
}
