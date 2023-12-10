/*47. Write a C++ program to delete an element 
in the circular Doubly linked list. Menu driven
program.*/


#include <iostream>
using namespace std;

struct Node
{

    int data;
    Node *prev;
    Node *next;
};

class CDLL
{

    Node *start;
    Node *end;

public:
    CDLL()
    {
        start = end = nullptr;
    }

    void Create()
    {

        int x;
        char ch;

        while (true)
        {

            cout << "\nEnter the element to insert: ";
            cin >> x;

            Insert(x);

            cout << "\nEnter 'y' to insert next: ";
            cin >> ch;

            if (ch != 'y')
            {
                break;
            }
        }
    }

    void Insert(int x)
    {

        Node *newNode = new Node;
        newNode->data = x;

        if (start == nullptr)
        {
            newNode->next = newNode->prev = newNode;
            start = end = newNode;
        }
        else
        {
            newNode->next = start;
            newNode->prev = end;
            end->next = newNode;
            end = newNode;

            start->prev = end;
        }
    }

    void Disp()
    {

        if (start == nullptr)
        {

            cout << endl
                 << endl
                 << "List is empty.." << endl;
            cout<<"\n\nExiting....";
            exit(0);
        }
        else
        {

            Node *temp = start;
            cout << endl
                 << endl
                 << "Circular List : ";
            do
            {
                cout << temp->data;
                if (temp != end)
                {
                    cout << " <--> ";
                }
                temp = temp->next;

            } while (temp != start);
        }
    }

    Node *SearchNode(int x)
    {
        Node *temp = start;

        do
        {
            if (temp->data == x)
            {
                return temp;
            }
            temp = temp->next;

        } while (temp != start);

        return nullptr;
    }

    void DeleteAny()
    {

        int x;

        cout << "Enter the element to delete : ";
        cin >> x;

        Node *delNode = SearchNode(x);

        if (delNode == nullptr)
        {
            cout << "\n\nElement not found!..Re-Try!";
            DeleteAny();
            return;
        }
        else if (delNode == start && delNode == end)
        {
            start = end = nullptr;
        }
        else
        {

            delNode->next->prev = delNode->prev;
            delNode->prev->next = delNode->next;

            if (delNode == start)
            {
                start = start->next;
            }
            else if (delNode == end)
            {
                end = end->prev;
            }

            delete delNode;
        }

        cout << "\n\nNode deleted with element " << x << "!";
    }

    void DeleteBeg(){

        if(start == end){
            start = end = nullptr;
            return;
        }

        Node *delNode = start;
        start = start->next;
        end->next = start;
        start->prev = end;

        cout << "\n\nNode deleted with element " << delNode->data << "!";
        delete delNode;
    }

    void DeleteEnd(){

        if(start == end){
            start = end = nullptr;
            return;
        }

        Node *delNode = end;
        end = end->prev;
        end->next = start;
        start->prev = end;

        cout << "\n\nNode deleted with element " << delNode->data << "!";
        delete delNode;
    }
};

int main()
{

    CDLL list;

    list.Create();
    list.Disp();

    int ch;

    while (true)
    {

        cout << "\n\n1.Delete from begining" << endl
             << "2.Delete from end" << endl
             << "3.Delete an element" << endl
             << "Enter your choice : ";
        cin >> ch;

        switch (ch)
        {

        case 1:
            list.DeleteBeg();
            list.Disp();
            break;
        case 2:
            list.DeleteEnd();
            list.Disp();
            break;
        case 3 :
            list.DeleteAny();
            list.Disp();
            break;
        case 0:
            cout << "\n\nExiting....\n\n";
            exit(0);
            break;
        default:
            cout << "\n\nInvalid choice...Re-Try..\n";
        }
    }

    return 0;
}