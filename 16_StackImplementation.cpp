#include<iostream>
using namespace std;
#define MAX 10

class Stack {
    int tos = -1; 
    int a[MAX];
    int n;

public:
    void ReadStack() {
    top:
        cout << "Enter the size of the stack (1 to " << MAX << "): ";
        cin >> n;
        if (n > MAX || n <= 0) {
            cout << "Invalid stack size. Please try again." << endl;
            goto top;
        }
        else {
            cout << "Enter the elements of the stack: ";
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            tos = n - 1; 
        }
    }

    void DisplayStack() {
        if (tos == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack is:" << endl;
        for (int i = tos; i >= 0; i--) {
            cout << "| " << a[i] << " |\n";
        }
    }

    void Push() {
        if (tos + 1 >= MAX) {
            cout << "Element can't be inserted. Stack is full! (Stack Overflow)" << endl;
            return;
        }

        int x;
        cout << "Enter the element to push to stack: ";
        cin >> x;

        tos++;
        a[tos] = x;

        cout << "Element " << x << " pushed to stack." << endl;
    }

    int Pop() {
        if (tos == -1) {
            cout << "Stack is empty. (Stack Underflow)" << endl;
            return -1; 
        }

        int x = a[tos];
        tos--;
        return x;
    }
};

int main() {
    Stack st;
    int choice;
    st.ReadStack();
    do {
        cout << ".....Stack Operations....." << endl
            << "1. Push element to stack" << endl
            << "2. Pop element from stack" << endl
            << "3. Display Stack" << endl
            << "0. Exit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
        case 1:
            st.Push();
            break;
        case 2: {
            int x = st.Pop();
            if (x != -1) {
                cout << "Element (" << x << ") has been successfully popped from stack." << endl;
            }
            break;
        }
        case 3:
            st.DisplayStack();
            break;
        case 0:
            cout << "Exiting...." << endl;
            break;
        default:
            cout << "Invalid Choice. Try again!" << endl;
        }
    } while (choice != 0);

    return 0;
}