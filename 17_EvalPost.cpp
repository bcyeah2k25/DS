#include <iostream>
#include <string>
#include <cctype>
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

class Postfix
{
    string p;
    Stack stack;

public:
    void ReadP()
    {
        cout << endl
             << "Enter the postfix expression : ";
        getline(cin, p);
    }

    void Disp()
    {
        cout << endl
             << "The postfix expression is : " << p << endl;
    }

    int eval()
    {
        for (int j = 0; j < p.length(); j++)
        {
            if (isdigit(p[j]))
            {
                int num = 0;
                while (isdigit(p[j]))
                {
                    num = num * 10 + (p[j] - 48);
                    j++;
                }
                j--;
                stack.push(num);
            }
            else if (p[j] == '+' || p[j] == '-' || p[j] == '*' || p[j] == '/')
            {
                int operand2 = stack.pop();
                int operand1 = stack.pop();

                switch (p[j])
                {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                }
            }
        }

        return stack.pop();
    }
};

int main()
{
    Postfix postfix;
    postfix.ReadP();
    postfix.Disp();
    int result = postfix.eval();
    cout << endl
         << "The result of the postfix expression is : " << result << endl;
    return 0;
}
