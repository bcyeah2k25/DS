/*Write a program to insert more than one element into a queue*/

#include <iostream>
#include <cctype>
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
    void Insert() {
        int item;
        if (rear >= MAX - 1)
            cout << "Queue is full...New elements cannot be inserted" << endl;
        else {
            cout << "Enter the item to insert: ";
            cin >> item;
            rear++;
            q[rear] = item;
            cout << "Element " << item << " inserted successfully!" << endl;
            DisplayQueue();
        }
    }
    void DisplayQueue() {
        if (front <= rear) {
            cout << "The Queue is: [";
            for (int i=front; i <= rear; i++) {
                cout << q[i];
                if (i< rear) {
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
    char choice;
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
    do {
        cout << "Do you want to insert an element? (y/n): ";
        cin >> choice;
        choice = toupper(choice);
        switch (choice) {
            case 'Y':
                Q.Insert();
                break;
            case 'N':
                cout << "Exiting...." << endl;
                break;
            default:
                cout << "Invalid choice..Try again" << endl;
        }
    } while (choice != 'N');
    return 0;
}
