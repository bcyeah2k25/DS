/*Write a program to merge 2 arrays in sorted order,
do not sort after merge*/

#include<iostream>
using namespace std;
#define MAX 5

class Array{

    int *a;
    int size;

public:

    void Create(){

        while(true){
        cout<<endl<<"Enter the size of the array : ";
        cin>>size;
        if(size > MAX || size < 1){
            cout<<endl<<"Size should be from 1 to "<<MAX<<"!..Re-Try!";
        }else{break;}
        }
        a = new int[size];
        cout<<"Enter the elements of the array :-"<<endl;
        for(int i=0;i<size;i++){
            cin>>a[i];
        }
        
    }

    void Display(){
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

    void Sort(){
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

Array MergeSort(Array& b) {

    Sort();
    b.Sort();

    Array temp;
    temp.size = size + b.size;
    temp.a = new int[temp.size];

    int i = 0, j = 0, k = 0;

     while (i < size && j < b.size) {
            if (a[i] <= b.a[j]) {
                temp.a[k] = a[i];
                i++;
            } else {
                temp.a[k] = b.a[j];
                j++;
            }
            k++;
        }

        while (i < size) {
            temp.a[k] = a[i];
            i++;
            k++;
        }

        while (j < b.size) {
            temp.a[k] = b.a[j];
            j++;
            k++;
        }

    return temp;
}

};

int main(){

    Array A,B,MS;

    cout<<endl<<endl<<"Enter array 1 details :-"<<endl;
    A.Create();
    A.Display();

    cout<<endl<<endl<<"Enter array 2 details :-"<<endl;
    B.Create();
    B.Display();

    cout<<endl<<endl<<"Array after merging and sorting of both arrays :-"<<endl;
    MS = A.MergeSort(B);
    MS.Display();

    return 0;
}