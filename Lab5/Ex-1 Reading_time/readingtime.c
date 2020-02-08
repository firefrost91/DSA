#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Creditc.h"
static int count1=0 ; 
void timeForReadingTest(char* filename,char* targetfile){
	Creditc* Creditc_array;
	int size,count;
	FILE* timing = fopen(targetfile,"a");

	struct timeval t1, t2;
	double elapsedTime;
		
	gettimeofday(&t1, NULL);
for(int i=0 ; i<10000 ; i++){	Creditc_array = readcards(Creditc_array,filename,&size);
count=size ;
count1=count1 + count ;    
}	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	fprintf(timing, "Read %d structs in %lf milliseconds.\n",count1,elapsedTime);
	fclose(timing);
}
