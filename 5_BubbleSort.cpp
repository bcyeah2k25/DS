/*Write a program to sort list of numbers using bubble sort*/

#include<iostream>
using namespace std;
#define MAX 5

class Array{

public:

    void Display(int a[],int& size){

    cout<<endl;
    cout<<"Array : [ ";
    for(int i=0;i<size;i++){
        cout<<a[i];
        if(i < size-1){
            cout<<", ";
        }
    }
    cout<<" ]";
    }

    void BubbleSort(int a[],int& size){

        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                
                if(a[j] < a[i]){

                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
};

int main(){

    Array A;

    int size;
    while(true){
        cout<<endl<<"Enter the size of the array : ";
        cin>>size;
        if(size > MAX || size < 2){
            cout<<endl<<"Size should be between 2 and "<<MAX<<"!..Re-Try!";
        }else{break;}
    }

    int a[MAX];
    cout<<"Enter the elements of the array :-"<<endl;
    for(int i=0;i<size;i++){
        cin>>a[i];
    }

    cout<<endl<<endl<<".....Array before Sort.......";
    A.Display(a,size);

    A.BubbleSort(a,size);
    cout<<endl<<endl<<".....Array after Sort.......";
    A.Display(a,size);

    return 0;
}