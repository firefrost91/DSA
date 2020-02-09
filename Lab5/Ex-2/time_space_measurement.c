#include<time.h>
#include<stdio.h>
#include<stdlib.h>
// #include"Creditc.h"
#include"insertionsort.h"
static int count1=0 ; 

void timeForSortingTest(char* filename,char* targetfile){
	Creditc* Creditc_array;
	int size,count;
	FILE* timing = fopen(targetfile,"a");

	struct timeval t1, t2;
	double elapsedTime;
		
	gettimeofday(&t1, NULL);
for(int i=0 ; i<100 ; i++){
    Creditc_array = readcards(Creditc_array,filename,&size);
	insertionSort(Creditc_array,size);
count=size ;
count1=count1 + count ;    
}	
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	fprintf(timing, "Sorted %d structures in %lf milliseconds.\n",count1,elapsedTime);
	fclose(timing);
}
void spaceForSortingTest(char* filename,char* targetfile){
	Creditc* Creditc_array;
	int size;
	FILE* timing = fopen(targetfile,"a");
	int x;		
	Creditc_array = readcards(Creditc_array,filename,&size);
	insertionSort(Creditc_array,size);
	fprintf(timing, "Number Of elements sorted:%d, Top Of Stack:%llu, Bottom Of Stack:%llu, Difference: %llu.\n",size,topofstack,&x,(unsigned long long)&x-(unsigned long long)topofstack);
	fclose(timing);
}
