/*Write a C++ program to interchange n and n+1th nodes in a list.*/

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

class LinkedList
{
private:
  Node *start;
  int n;

public:
  LinkedList()
  {
    start = nullptr;
  }

  void DispLL()
  {
    Node *node = start;
    cout << "\nList: ";
    while (node != nullptr)
    {
      cout << node->data << " --> ";
      node = node->next;
    }
    cout << "NULL" << endl
         << endl;
  }

  void CreateLL()
  {
    int x;
    n++;
    cout << endl
         << "Enter element " << n << " : ";
    cin >> x;
    Insert(x);

    char ch;
    cout << "Enter 'y' to continue : ";
    cin >> ch;

    if (ch == 'y')
    {
      CreateLL();
    }
  }

  void Insert(int x)
  {
    Node *temp = new Node;
    temp->data = x;
    temp->next = nullptr;

    if (start == nullptr)
    {
      start = temp;
    }
    else
    {
      Node *curr = start;
      while (curr->next != nullptr)
      {
        curr = curr->next;
      }
      curr->next = temp;
    }
  }

  Node *SearchNode(int pos)
  {
    if (pos < 1 || pos > n)
    {
      return nullptr;
    }

    Node *curr = start;
    for (int i = 1; i < pos; i++)
    {
      curr = curr->next;
    }
    return curr;
  }

  void Interchange()
  {
    int x, y;

    cout << "Enter position to interchange: ";
    cin >> x;
    y = x + 1;

    if (x >= n || x < 1)
    {
      cout << "\n\nInvalid positions\n\n";
      Interchange();
      return;
    }

    Node *prevX = NULL, *currX = start;
    if (x != 1)
    {
      prevX = SearchNode(x - 1);
      currX = prevX->next;
    }

    Node *prevY = currX, *currY;
    currY = prevY->next;

    if (prevX != NULL)
      prevX->next = currY;
    else
      start = currY;

    prevY->next = currX;

    Node *temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    cout << "\n\nNodes swapped\n\n";
    DispLL();
  }
};

int main()
{
  LinkedList list;
  list.CreateLL();
  list.DispLL();
  list.Interchange();
  return 0;
}
