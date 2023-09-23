#include<iostream>
using namespace std;
#define MAX 5

class Queue {
    int q[MAX];
    int front = 0;
    int rear = -1;
    int size;

public:
    Queue(int n) {
        size = n;
    }

    void ReadQueue() {
        if (rear < size - 1) { 
            for (; rear < size - 1; rear++) {
                cout << "Enter the element: ";
                cin >> q[rear + 1]; 
            }
        } else {
            cout << "Queue is full." << endl;
        }
    }
    void DisplayQueue() {
        if (front < rear) { 
            cout << "The Queue is: [";
            for (; front <= rear; front++) { 
                 cout << q[front];
                 if (front < rear) {
                    cout << ", ";
                }
            }
           cout << "]" << endl;
       } else {
           cout << "Queue is empty." << endl;
       }
   }
};

int main() {
    int n;
top:
    cout << "Enter the Queue size: ";
    cin >> n;
    if (n < 1 || n > MAX) {
        cout << "The Queue size must be from 1 to " << MAX << "...Re-Enter!" << endl;
        goto top;
    }
    Queue Q(n);
    Q.ReadQueue();
    Q.DisplayQueue();
    return 0;
}