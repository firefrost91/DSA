#include <iostream>
using namespace std ;
void connect(int p , int q , int points[] , int size){
    int pid = points[p];
    int qid = points[q]; 
    for(int i = 0 ; i < size ; i++){
        if(points[i]==pid){
            points[i]=qid ; 
        }
    }
}
int isconnected( int p , int q ,int points[] , int size ){
    return points[p]==points[q]; 
}
int main (){
 int size  ; 
 cout << "Enter no of points" << endl ; 
 cin >> size ; 
 int points[size]; 
 
//  cout << "Enter pair of connected inputs" << endl ; 
 for(int i=0  ; i < size ; i ++) {
     points[i]=i ; 
 }
   connect(0 ,1 , points , size);
   connect(1 ,2 , points , size) ;
   cout<< isconnected(0 ,1 , points , size) << endl; 
   cout<<isconnected(1,2 , points , size) << endl;
   cout<< isconnected(3,0 , points , size) << endl;
}
