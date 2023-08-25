/*Write a program to delete an element from anywhere using array,
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

void Delete(int a[],int& size){

    int pos;
    while(true){
        cout<<endl<<"Enter the position of the element to be deleted : ";
        cin>>pos;
        if(pos < 0 || pos >= size){
            cout<<endl<<"Invalid position!";
        }else{break;}
    }
        
    int x = a[pos];
    for(int i=pos;i<size;i++){
        a[i] = a[i+1];
    }
    size--;
    cout<<endl<<"Element ("<<x<<") at position ("<<pos<<") has been succefully deleted !";
    

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
        if(size == 0){
            cout<<endl<<endl<<"Array is empty....Exiting..!";
            exit(0);
        }

        cout<<endl<<endl;
        cout<<"1. Delete Element"<<endl
            <<"2. Display Array"<<endl
            <<"0. Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice){

            case 0 : cout<<endl<<endl<<"Exiting.........."<<endl; exit(0); break;

            case 1 : Delete(a,size); break;

            case 2 : Display(a,size); break;

            default : cout<<"Invalid choice....Re-Try!"<<endl;

        }

    }while(choice != 0);

    return 0;
}