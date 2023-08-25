/*Write a program to insert an element anywhere using array,
menu driven program*/

#include<iostream>
using namespace std;
#define MAX 5

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

void Insert(int a[],int& size){

    if(size == MAX){
        cout<<endl<<"Insufficient space for insertion!";
    }else{

        int x,pos;

        cout<<"Enter the element to insert : ";
        cin>>x;

        while(true){    
            cout<<endl<<"Enter the position : ";
            cin>>pos;
            if(pos < 0 || pos > size ){
                cout<<endl<<"Invalid position....Position should be from 0 to "<<size<<"!"<<endl;
            }else{break;}
        }


        for(int i=size;i>pos;i--){
            a[i] = a[i-1];
        }
        a[pos] = x;
        size++;
        cout<<endl<<"Element ("<<x<<") succesfully inserted at position ("<<pos<<")!";
    }
}


int main(){

    int size;
    while(true){
        cout<<endl<<"Enter the size of the array : ";
        cin>>size;
        if(size > MAX || size < 1){
            cout<<endl<<"Size should be between 1 and "<<MAX<<"!..Re-Try!";
        }else{break;}
    }

    int a[MAX];
    cout<<"Enter the elements of the array :-"<<endl;
    for(int i=0;i<size;i++){
        cin>>a[i];
    }

    int choice;

    do{

        cout<<endl<<endl;
        cout<<"1. Insert Element"<<endl
            <<"2. Display Array"<<endl
            <<"0. Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice){

            case 0 : cout<<endl<<endl<<"Exiting.........."<<endl; exit(0); break;

            case 1 : Insert(a,size); break;

            case 2 : Display(a,size); break;

            default : cout<<"Invalid choice....Re-Try!"<<endl;

        }

    }while(choice != 0);

    return 0;
}