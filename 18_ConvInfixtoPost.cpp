/*Write a program to convert Infix to postfix expression / notation.*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Stack
{
    int s[20];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (top < 19)
        {
            s[++top] = value;
        }
    }

    int pop()
    {
        if (top >= 0)
        {
            return s[top--];
        }
        else
        {
            return -1;
        }
    }
};
